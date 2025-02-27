#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#define STR "#include <fcntl.h>%c#include <string.h>%c#include <stdio.h>%c#include <unistd.h>%c#define STR %c%s%c%c#define FILENAME %c%s%c%c#define EXEC_NAME %c%s%c%cint main(void) {%c%cint i = %d;%c%cchar tmp_buff[BUFF_SIZE] = {0};%c%cchar file_format_buff[sizeof(FILENAME) + 2] = {0};%c%c%cstrcpy(buff, FILENAME);%c%cint fd = open(buff, O_RDWR | O_CREAT, S_IRWXU, S_IRWXG);%c%cdup2(1, fd);%c%cprintf(STR, 10, 10, 10, 9, i-1, 10, 10, 9, 10);%c}%c"
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
	strcpy(executable_result_buff, filename_result_buff);
	executable_result_buff[strlen(executable_result_buff) - 2] = 0;
	printf("O filename_result_buff é: %s\n", filename_result_buff);
	printf("O executable_result_buff é: %s\n", executable_result_buff);
	dprintf(fd, STR, 10, 10, 10, 10, 34, STR, 34, 10, 34, FILENAME, 34, 10, 34, EXEC_NAME, 34, 10, 10, 9, i-1, 10, 9, 10, 9, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10); // falta escrever a format string
	execl("gcc", filename_result_buff, "-o", executable_result_buff, NULL);
	if (i) {
		execl(executable_result_buff, "", NULL);
	}
}
