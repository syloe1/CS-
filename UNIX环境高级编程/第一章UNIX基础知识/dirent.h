#ifndef _DIRENT_H
#define _DIRENT_H

#include <sys/types.h>

struct dirent {
    ino_t d_ino;           /* inode number */
    off_t d_off;           /* offset to the next dirent */
    unsigned short d_reclen; /* length of this record */
    unsigned char d_type;  /* type of file; not supported by all file system types */
    char d_name[256];      /* filename */
};

typedef struct {
    int fd;
    int curpos;
    int count;
    struct dirent direntry;
} DIR;

DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

#endif /* _DIRENT_H */

