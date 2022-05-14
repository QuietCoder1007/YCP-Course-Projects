#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>

#define STDIN  0
#define STDOUT 1
#define STDERR 2

#define BUFFER_SIZE 256


int main(int argc, char** argv)
{
    char *src_file, *dst_file;
    char data_buf[BUFFER_SIZE];

    // TODO 1
    // Declare any other variables
    // you may need here
    //

    struct stat src_file_stats;

    int src, dst;
    char* err;
    int bytes_in;

    // verify the user has supplied the correct number of arguments
    // and assign source and destination file names
    if (argc != 3) {
        err = "Error: Incorrect number of arguments\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    } else {
        // TODO 2
        // Make appropriate assignments if correct
        // number of arguments were supplied
        //
        src_file = argv[1];
        dst_file = argv[2];
    }



    // TODO 3
    // Open the source file, be sure to apply appropriate permissions
    // BE SURE TO CHECK FOR ERRORS WHEN OPENING FILES
    // If an error occurs, report the error and terminate the program
    if ( (src = open(src_file, O_RDONLY)) < 0 )
    {
        err = "Error: Could not open src file\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }

    // TODO 4
    // Determine the file system permissions (i.e. mode) of the source file
    // Again, be sure to check for errors!
    if ( stat(src_file, &src_file_stats) < 0 ){
        err = "Error: Could not retrieve src file permissions\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }

    // TODO 5
    // Open the destination file, be sure to apply appropriate permissions
    // BE SURE TO CHECK FOR ERRORS WHEN OPENING FILES
    // If an error occurs, report the error and terminate the program

     if ( ((dst = open( dst_file, O_WRONLY | O_CREAT | O_TRUNC, src_file_stats.st_mode))) < 0 ){
        err = "Error: Could not assign dst file permissions\n";
        write(STDERR, err, strlen(err));
        exit(-1);
     }


    // TODO 6
    // Output a status message here, something like
    // "Copying AAA to BBB"
    if( (write(STDOUT, "Copying ", 8)) < 0 ){
        err = "Error: Could not write to terminal error\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }
    if( (write(STDOUT, src_file, strlen(src_file))) < 0 ){
        err = "Error: Could not write to terminal error\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }
    if( (write(STDOUT, " to ", 4)) < 0 ){
        err = "Error: Could not write to terminal error\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }
    if( (write(STDOUT, dst_file, strlen(dst_file))) < 0 ){
        err = "Error: Could not write to terminal error\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }

    // TODO 7
    // Do the work to actually copy the file here
    // Be efficient and copy CHUNKS of data
    // DO NOT COPY ONE BYTE AT AT TIME
    // DO NOT READ THE ENTIRE FILE INTO MEMORY
    // Again, be sure to check for errors!
    while( (bytes_in = read( src, data_buf, BUFFER_SIZE )) != 0 ){

        if ( bytes_in < 0 ) {
            err = "Error: There was an error reading from src file\n";
            write(STDOUT, err, strlen(err));
            exit(-1);
        }

        if( (write( dst, data_buf, bytes_in )) < 0 ){
            err = "Error: There was an error writing to dst file\n";
            write(STDERR, err, strlen(err));
            exit(-1);
        }
    }


    // TODO 8
    // Close the source and destination files here
    // As always, check for any errors that may be generated
    if ( close(src) < 0 ){
        err = "Error: There was an error closing src file\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }

    if ( close(dst) < 0 ){
        err = "There was an error closing dst file\n";
        write(STDERR, err, strlen(err));
        exit(-1);
    }

    return 0;
}
