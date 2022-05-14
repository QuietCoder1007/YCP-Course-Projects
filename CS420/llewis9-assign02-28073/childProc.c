#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ipcEx.h"

#define C_done "CHILD: Done copying data, exiting...\n\n"

int main(int argc, char** argv)
{
    /* Print out usage statement when no value is specified */
    if ( argc != 2 ) {
        perror("CHILD argc ERROR: ");
        exit(1);
    }

    printf("CHILD: Received %d arguments\n", argc);

    char data_string[] = "Hello Shared Memory!\n";

    // TODO:
    // Insert your code here

    int *shmat_id = shmat( atoi(argv[1] ), NULL, 0 );

    if ( shmat_id == (void *) -1 ) {
        perror("CHILD shmat ERROR: ");
        exit(1);
    }

    int data_size = sizeof(data_string) - 1;

    struct ipc_struct *shared_memory = (struct ipc_struct *) shmat_id;
    int repeat = shared_memory->repeat_val;

    printf("CHILD: Parent requested that I store my data %d times\n", repeat);

    for (int i = 0; i < repeat; ++i) {
        if( data_size*i >= BUFFER_SIZE ){
            printf("ERROR: Can only fit 128 characters!");
            exit(1);
        }
        snprintf(shared_memory->data+(data_size*i), data_size+1, "%s", data_string);
    }
    printf(C_done);
    if ( (shmdt( shared_memory )) < 0 ){
            perror("CHILD shmdt ERROR: ");
            exit(1);
    }
    return 0;
}




