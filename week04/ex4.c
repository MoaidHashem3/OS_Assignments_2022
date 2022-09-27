#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void CommandWrtie(){
    static int firstTime =1;
    if(firstTime){
        const char* clearScreen = "\e[1;1h\e[2j";
        write(STDOUT_FILENO,clearScreen,12);
        firstTime = 0;
        printf("--------SIMPLE SHELL--------\n");
    }

    printf("$# ");
}
void CommandRead (char c[], char *para[]){
    char line[1024];
    int counter = 0;
    int i =0;
    int j =0;
    char *arr[100];
    char *pch;
    for(;;) {
        int c = fgetc(stdin);
        line[counter++] = (char) c;
        if(c =='\n')
            break;
    }
    if(counter == 1) 
        return;
    pch = strtok(line, "\n");
    while (pch !=NULL)
    {
        arr[i++] = strdup(pch);
        pch = strtok(NULL, "\n");
    }
    strcpy(c, arr[0]);

    for(int j =0; j <i; j++){
        para[j] = arr[j];
    }
    para[i] = NULL;
    

}

int main(){
    char c[100], command[100], *para[20];
    char *envp[] = {(char *)"PATH=/bin", 0};
    while (1)
    {
        CommandWrtie();
        CommandRead(command, para);
        if(fork()!= 0){
            wait(NULL);
        }else{
            strcpy(c, "/bin/");
            strcat(c, command);
            execve(c, para, envp);
        }
        if(strcmp(command, "exit") ==0)
            break;
    }
    
    return 0;
}