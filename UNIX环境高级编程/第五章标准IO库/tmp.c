#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../apue.h"
#include "../myerr.h"

// Generate a temporary file using mkstemp
int main(void) {
    char name[] = "/tmp/tmpfileXXXXXX"; // Template for mkstemp
    char line[MAXLINE];
    int fd;
    FILE *fp;

    // Create a unique temporary file and get a file descriptor
    if ((fd = mkstemp(name)) == -1) {
        err_sys("mkstemp error");
    }

    // Print the name of the temporary file
    printf("Temporary file created: %s\n", name);

    // Open a file stream for the temporary file
    if ((fp = fdopen(fd, "w+")) == NULL) {
        close(fd);
        err_sys("fdopen error");
    }

    // Write to the temporary file
    fputs("one line of output\n", fp);

    // Rewind to the beginning of the file
    rewind(fp);

    // Read the line from the temporary file
    if (fgets(line, sizeof(line), fp) == NULL) {
        err_sys("fgets error");
    }

    // Print the read line
    fputs(line, stdout);

    // Close the file stream and delete the temporary file
    fclose(fp);
    unlink(name);

    exit(0);
}

