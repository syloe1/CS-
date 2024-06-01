#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>
#include <string.h>
#include <errno.h>

int main(void) {
    struct spwd *spwd_entry;

    // Open the shadow password file
    if ((spwd_entry = getspnam("username")) == NULL) {
        perror("getspnam error");
        exit(EXIT_FAILURE);
    }

    // Print the encrypted password
    printf("Encrypted password for user %s: %s\n", spwd_entry->sp_namp, spwd_entry->sp_pwdp);

    return 0;
}

