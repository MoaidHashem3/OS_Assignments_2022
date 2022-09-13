#include <stdio.h>
#include<ctype.h>
#include <string.h>

int count(char word[], char lc){
int counter = 0;
int i = 0;
for (i = lc; i >= 0; --i) {
	if(word[i] == ','){
	continue;
	} else if(word[i] == lc){counter++;}
   	

	}
	counter = counter - 1;
	return counter;
}
 
int main(void)
{
  	char word[256];
  	char last_element;
  	int i, counter=0;
  	scanf("%[^\n]",word);
  	last_element = strlen(word) - 1;
  	for(int j=0;word[i]; i++ ){
  	word[i] = tolower(word[i]);
  	}
	for (i = last_element; i >= 0; --i) {
   	 last_element = word[i];

  	  break;
	}
	
	counter = count(word,last_element);
	printf("%c:%d", last_element, counter);
	
  	return 0;
}
