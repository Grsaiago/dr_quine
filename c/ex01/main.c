#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define STR "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#define STR %c%s%c%cint main(void) {%c%cint fd = open(%cGrace_kid.c%c, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);%c%cwrite(fd, STR, sizeof(STR));%c%cdprintf(fd, STR, 10, 10, 10, 34, STR, 34, 10, 10, 9, 34, 34, 10, 9, 10, 9);}"
int main(void) {
	int fd = open("Grace_kid.c", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
	dprintf(fd, STR, 10, 10, 10, 34, STR, 34, 10, 10, 9, 34, 34, 10, 9, 10, 9);}

