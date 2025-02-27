#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/*
 * um comentário top
*/
#define STR "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c%c*%c * um comentário top%c*/%c#define STR %c%s%c%c#define FT() int main(void) {int fd = open(%cGrace_kid.c%c, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG); dprintf(fd, STR, 10, 10, 10, 47, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10);}%cFT()"
#define FT() int main(void) {int fd = open("Grace_kid.c", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG); dprintf(fd, STR, 10, 10, 10, 47, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10);}
FT()