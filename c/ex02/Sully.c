#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define STR "#include <fcntl.h>%c#include <string.h>%c#include <stdio.h>%c#include <strings.h>%c#include <unistd.h>%c#include <sys/types.h>%c#include <sys/wait.h>%c#define STR %c%s%c%c#define NAME %c%s%c%c#define BUFF_SIZE 10000%cint main(void) {%c%cint i = %d;%c%cchar modify_buff[BUFF_SIZE] = {0};%c%cchar filename_result_buff[sizeof(NAME) + 20] = {0};%c%cchar executable_result_buff[sizeof(NAME) + 20] = {0};%c%c%cstrcpy(modify_buff, NAME);%c%cmodify_buff[sizeof(NAME) - 5] = 37;%c%csprintf(filename_result_buff, modify_buff, i-1);%c%cint fd = open(filename_result_buff, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);%c%cstrcpy(executable_result_buff + 2, filename_result_buff);%c%cexecutable_result_buff[0] = '.';%c%cexecutable_result_buff[1] = '/';%c%cexecutable_result_buff[strlen(executable_result_buff) - 2] = 0;%c%cdprintf(fd, STR, 10, 10, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, NAME, 34, 10, 10, 10, 9, i-1, 10, 9, 10, 9, 10, 9, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 34, 34, 34, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 10);%c%cif (i) {%c%c%cint pid = fork();%c%c%cif (pid == 0) {%c%c%c%cexecl(%c/bin/gcc%c, %c/bin/gcc%c, filename_result_buff, %c-o%c, executable_result_buff, (char *)NULL);%c%c%c}%c%c%cwaitpid(pid, NULL, 0);%c%c%cexecl(executable_result_buff, executable_result_buff, (char *)NULL);%c%c}%c}"
#define NAME "Sully_pd.c"
#define BUFF_SIZE 10000
int main(void) {
	int i = 5;
	char modify_buff[BUFF_SIZE] = {0};
	char filename_result_buff[sizeof(NAME) + 20] = {0};
	char executable_result_buff[sizeof(NAME) + 20] = {0};

	strcpy(modify_buff, NAME);
	modify_buff[sizeof(NAME) - 5] = 37;
	sprintf(filename_result_buff, modify_buff, i-1);
	int fd = open(filename_result_buff, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
	strcpy(executable_result_buff + 2, filename_result_buff);
	executable_result_buff[0] = '.';
	executable_result_buff[1] = '/';
	executable_result_buff[strlen(executable_result_buff) - 2] = 0;
	dprintf(fd, STR, 10, 10, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, NAME, 34, 10, 10, 10, 9, i-1, 10, 9, 10, 9, 10, 9, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 34, 34, 34, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 10);
	if (i) {
		int pid = fork();
		if (pid == 0) {
			execl("/bin/gcc", "/bin/gcc", filename_result_buff, "-o", executable_result_buff, (char *)NULL);
		}
		waitpid(pid, NULL, 0);
		execl(executable_result_buff, executable_result_buff, (char *)NULL);
	}
}
