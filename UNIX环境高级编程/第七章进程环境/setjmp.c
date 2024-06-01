#include "../apue.h"
#include "../myerr.h"
#include <stdio.h>
#include <string.h>

#define TOK_ADD 5

void do_line(char *);
void cmd_add(void);
int get_token(void);

char* tok_ptr;

int main(void) {
    char line[MAXLINE];
    while (fgets(line, MAXLINE, stdin) != NULL) {
        do_line(line);
    }
    exit(0);
}

void do_line(char* ptr) {
    int cmd;
    tok_ptr = ptr;
    while ((cmd = get_token()) > 0) {
        switch (cmd) {
            /* one case for each command */
            case TOK_ADD:
                cmd_add();
                break;
        }
    }
}

void cmd_add(void) {
    int token;
    token = get_token();
    /* rest of processing for this command */
    printf("cmd_add: token = %d\n", token); // Just for demonstration
}

int get_token(void) {
    /* Simple tokenizer example */
    if (tok_ptr == NULL) {
        return 0;
    }
    while (*tok_ptr == ' ' || *tok_ptr == '\t') {
        tok_ptr++;
    }
    if (*tok_ptr == '\0') {
        return 0;
    }

    if (strncmp(tok_ptr, "add", 3) == 0 && (tok_ptr[3] == ' ' || tok_ptr[3] == '\t' || tok_ptr[3] == '\0')) {
        tok_ptr += 3;
        return TOK_ADD;
    }

    /* Skip current token */
    while (*tok_ptr != ' ' && *tok_ptr != '\t' && *tok_ptr != '\0') {
        tok_ptr++;
    }

    return -1; // Unknown token
}
