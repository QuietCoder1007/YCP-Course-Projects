#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "ipcEx.h"

#define P_child_left "PARENT: Child left the following in the data buffer:\n"
#define P_done "PARENT: done"

#define BUFFER_START "============= Buffer start =============\n"
#define BUFFER_END "============= Buffer end ===============\n\n"


int main(int argc, char **argv) {

    /* Print out usage statement when no value is specified */
    if ( argc != 2 ) {
        fprintf(stderr, "ERROR: You must specify an integer value as an argument\n");
        return 1;
    }
    // TODO:
    // Insert your code here

    int segment_id = shmget( IPC_PRIVATE, sizeof(struct ipc_struct), IPC_CREAT | 0666 );

    if ( segment_id < 0 ) {
        perror("PARENT shmget ERROR: \n");
        exit(1);
    }

    printf("PARENT: Created shared memory with a segment ID of %d\n", segment_id);

    int *shmat_id = shmat(segment_id, NULL, 0);

    if ( shmat_id == (void *) -1 ) {
        perror("PARENT shmat ERROR: \n");
        exit(1);
    }
    printf("PARENT: The child process should store its string in shared memory a total of %s\n\n", argv[1]);

    struct ipc_struct* shared_memory = (struct ipc_struct *) shmat_id;

    shared_memory->repeat_val = atoi(argv[1]);

    pid_t pid;

    pid = fork();

    if ( pid < 0 ) {
        perror("PARENT fork ERROR: ");
        exit(1);
    } else if ( pid == 0 ) {
        snprintf( shared_memory->data, sizeof(shared_memory->data), "%d", segment_id );

        if( (execlp( "./childProc", "childProc", shared_memory->data, NULL )) < 0 ){
            perror("PARENT execlp ERROR: ");
            exit(1);
        }
    } else {
        printf("PARENT: Child with PID=%d\n", pid);
        printf(P_child_left);

        if( wait( NULL ) < 0 ){
          perror("PARENT wait ERROR: ");
        }

        printf( BUFFER_START );
        printf( shared_memory->data );
        printf( BUFFER_END );

        if( shmdt( shared_memory ) < 0 ){
          perror("PARENT shmdt ERROR: ");
        }
        if( shmctl( segment_id, IPC_RMID, (struct shmid_ds *) NULL ) < 0 ){
          perror("PARENT shmctl ERROR: ");
        }

        printf(P_done);
    }

    return 0;
}

