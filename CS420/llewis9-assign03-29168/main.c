#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "utils.h"


int main(int argc, char **argv) {
    char *filename = NULL;  // DO NOT MODIFY THIS VARIABLE NAME
    int num_procs = 0;      // DO NOT MODIFY THIS VARIABLE NAME
    int num_threads = 0;    // DO NOT MODIFY THIS VARIABLE NAME

    // TODO: parse arguments
    int opt;
    char SEM_NAME[] = "/llewis9";

    while ((opt = getopt(argc, argv, "p:t:f:")) > 0) {
        if (opt == '?') {
            perror("No options given!\n");
            exit(1);
        }
        switch (opt) {
            case 'p':
                num_procs = atoi(optarg);
                break;
            case 't':
                num_threads = atoi(optarg);
                break;
            case 'f':
                filename = optarg;
                break;
        }
    }

    // TODO: write initial '0' to file
    FILE *file_pt = open_file(filename, "w");
    fprintf(file_pt, "0\n");
    close_file(file_pt);

    // TODO: create a named semaphore
    sem_t *mutex;

    if ((mutex = sem_open(SEM_NAME, O_CREAT, S_IRWXU, 1)) < 0) {
        perror("sem_open ERROR: ");
        close_n_unlink_n_exit(mutex, SEM_NAME);
    }

    // TODO: fork off child processes and wait for them to finish
    pid_t pid;

    for (int i = 0; i < num_procs; i++) {
        pid = fork();
        if (pid < 0) {
            perror("PARENT failed to fork CHILD ERROR: ");
            close_n_unlink_n_exit(mutex, SEM_NAME);
        } else if (pid == 0) {

            //            printf("CHILD: %d\n", getpid());

            char str_threads[21] = "";
            snprintf(str_threads, sizeof(str_threads), "%d", num_threads);

            if ((execlp("./fileWriter", "fileWriter", str_threads, filename, SEM_NAME, NULL)) < 0) {
                perror("PARENT execlp ERROR: ");
                close_n_unlink_n_exit(mutex, SEM_NAME);
            }
        }
    }

    for (int i = 0; i < num_procs; i++) {
        wait(NULL);
    }
//    printf("All child processes complete!\n");

    // TODO: clean up and close named semaphore
    close_n_unlink_n_exit(mutex, SEM_NAME);

    /////////////////////////////////////////////////////////////////////////////////////
    //
    // ** IMPORTANT: DO NOT REMOVE/CHANGE/MODIFY/EDIT OR DO ANYTHING TO THE CODE BETWEEN
    //               HERE AND THE END OF THIS FILE.  YOU CANNOT CHANGE THIS CODE TO MAKE
    //               IT WORK WITH YOUR PROGRAM.  IF YOUR PROGRAM DOESN'T WORK WITH THIS
    //               CODE, THEN YOUR PROGRAM -DOES NOT WORK-.  CHANGE YOUR PROGRAM AS
    //               NECESSARY TO WORK WITH THIS CODE.  ANY CHANGES TO THE CODE BELOW WILL
    //               RESULT IN 0 CREDIT FOR THIS LAB.  BE SURE ALL OF YOU CHILD PROCESSES
    //               HAVE TERMINATED BEFORE THIS POINT.
    //
    /////////////////////////////////////////////////////////////////////////////////////
    // This section checks the output file to see if everthing went as planned.  A message
    // is printed to the terminal indicated if everything works correctly.
    /////////////////////////////////////////////////////////////////////////////////////
    FILE *fpt = open_file(filename, "r");   // open the file for reading
    int max_value = num_procs * num_threads;
    int value;
    int success = 1;

    // The following loop will read the file after it has been written by all of the
    // child processes and threads.  It will read each line and compare it to the
    // expected value.  If an error is encoutered, the 'success' flag will be set
    // to false.
    for (int expected_value = 0; expected_value <= max_value; expected_value++) {
        fscanf(fpt, "%i", &value);
        if (expected_value != value) {
            success = 0;
            break;
        }
    }
    close_file(fpt);                        // close the file


    if (success) {
        printf("\n\n-SUCCESS-\n\n");
    } else {
        printf("\n\n-EPIC FAIL-\n\n");
    }
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////

    return 0;
}

