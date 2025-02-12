#include <stdio.h>
/*
 * um comentário
*/
int main() {
	/*e outro*/
	char	*f="#include <stdio.h>%c/*%c * um comentário%c*/%cint main() {%c%c/*e outro*/%c%cchar%c*f=%c%s%c;%c%cprintf(f, 10, 10, 10, 10, 10, 9, 10, 9, 9, 34, f, 34, 10, 9, 10, 10);%c}%c";
	printf(f, 10, 10, 10, 10, 10, 9, 10, 9, 9, 34, f, 34, 10, 9, 10, 10);
}
