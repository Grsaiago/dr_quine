#include <stdio.h>

#define STR "#include <stdio.h>%c%c#define STR %s%cint main(void) { printf(STR, 10, 10, STR, 10); }"
int main(void) { printf(STR, 10, 10, STR, 10); }
