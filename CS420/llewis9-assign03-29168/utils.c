/*
 *
 */
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utils.h"

/*
 *
 */

void close_n_unlink_n_exit(sem_t *mutex, char mutex_name[]) {
    if (sem_close(mutex) < 0) {
        perror("sem_close: ERROR");
    }
    if (sem_unlink(mutex_name) < 0) {
        perror("sem_unlink: ERROR");
    }
}

FILE* open_file(char* filename, char* rw) {
    FILE* fp;
    
    if ((fp = fopen(filename, rw)) == NULL) {
        if(strcmp(rw, "r") == 0) {
            fprintf(stderr, "Can't open file %s for reading\n", filename);
        } else if(strcmp(rw, "w") == 0) {
            fprintf(stderr, "Can't open file %s for writing\n", filename);
        } else {
            fprintf(stderr, "Can't open file %s for operation: %s\n", filename, rw);
        }
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    return fp;
}



/*
 *
 */
void close_file(FILE* fp) {
    if (fclose(fp) != 0) {
        fprintf(stderr, "There was a problem closing a file.\n");
        perror("fclose");
    }
}



