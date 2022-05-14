#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utils.h"

struct thread_sem {
    char *filename;
    char *sem_name;
};


void *runner(void *threadarg) {
    FILE *fp;
    int val;
    struct thread_sem *my_sem = (struct thread_sem *) threadarg;
    sem_t *mutex;
    if ((mutex = sem_open(my_sem[0].sem_name, O_CREAT, S_IRWXU, 1)) < 0) {
        perror("RUNNER sem_open ERROR: ");
        close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
    }

    if (sem_wait(mutex) < 0) {
        perror("RUNNER sem_wait ERROR: ");
    }

    fp = open_file(my_sem[0].filename, "r+");

    if (fseek(fp, -2L, SEEK_END) < 0) {
        perror("RUNNER first fseek ERROR: ");
        close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
    }

    if (ftell(fp) != 0L) {
        while (getc(fp) != '\n') {
            if (fseek(fp, -2L, SEEK_CUR) < 0) {
                perror("RUNNER loop fseek ERROR: ");
                close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
            }
        }
    }

    if (fscanf(fp, "%d", &val) == EOF) {
        perror("fscanf ERROR: ");
        close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
    }

    if (fseek(fp, 0L, SEEK_END) < 0) {
        perror("RUNNER fseek ERROR: ");
        close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
    }

    //    printf("Value: %d\n", val);

    if (fprintf(fp, "%d\n", ++val) < 0) {
        perror("fscanf ERROR: ");
        close_n_unlink_n_exit(mutex, my_sem[0].sem_name);
    }

    close_file(fp);

    if (sem_post(mutex) < 0) {
        perror("RUNNER sem_post ERROR: ");
    }

    if (sem_close(mutex) < 0) {
        perror("RUNNER sem_close ERROR: ");
    }
    pthread_exit(0);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Not enough parameters! Need num_threads, filename, and semaphore_name!\n");
        exit(1);
    }

    int num_threads = atoi(argv[1]);
    struct thread_sem sem;
    pthread_t threads[num_threads];
    pthread_attr_t thread_attr;

    sem.filename = argv[2];
    sem.sem_name = argv[3];

    for (int i = 0; i < num_threads; i++) {

        //        printf("Creating thread %d\n", i + 1);

        if (pthread_attr_init(&thread_attr) < 0) {
            perror("pthread_attr_init ERROR: ");
            exit(1);
        }

        if (pthread_create(&threads[i], &thread_attr, runner, (void *) &sem) < 0) {
            perror("pthread_create ERROR: ");
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) < 0) {
            perror("pthread_join ERROR: ");
            exit(1);
        }
//        printf("Thread %d has ended!\n", i);
    }

    return 0;
}
