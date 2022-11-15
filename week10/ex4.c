#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#define MAX_SIZE 100


int main()
{
    DIR *dir = opendir("./tmp");
    if(dir == NULL)
    {
        printf("Error While opening folder\n");
        return 1;
    }
    
    int c = 0;
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL)
    {
        if(entry->d_name[0] == '.') continue;

        struct stat s = {};
        char d[MAX_SIZE] = "tmp/";
        stat(strcat(d, entry->d_name), &s);
	
        if(s.st_nlink >= 2){
            c++;
        }
    }

    printf("Found %d i-node(s) with hardlink count of two or more\n", c);
}
