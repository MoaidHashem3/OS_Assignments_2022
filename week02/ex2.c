#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void){

char output[256];
char last_element;
char i;

scanf("%[^\'.' || \n]",output);
last_element = strlen(output) - 1;
for (i = last_element; i >= 0; --i) {
    printf("%c", output[i]);
}

	return 0;
}
