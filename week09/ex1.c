#include <stdio.h>
#include <stdint.h>

#define MAX_PAGE 1000

uint8_t R[MAX_PAGE + 1];

struct page
{
    int id;
    uint8_t cnt;
};

int main(int argc, char** argv)
{
    int n = 100;
    if(argc > 2)
    {
        printf("Number of arguments is wrong\n");
        return 1;
    }
    sscanf(argv[1], "%d", &n);

    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL)
    {
        printf("Error while opening file\n");
        return 1;
    }

    struct page pt[n];
    for(int i=0;i<n;i++) pt[i].id=0;

    int h=0, m=0, id;

    while(fscanf(fp, "%d", &id) != EOF)
    {
        R[id] = 1; 

        struct page* found = NULL;
        for(int i=0; i<n; i++)
        {
            if(pt[i].id == id)
            {
                found = &pt[i];
                break;
            }
        }

        if(found != NULL)  
        {
            h++;
        }
        else 
        {
            m++;

            uint8_t mn = 255;
            int I;
            for(int i=0; i<n; i++)
            {
                if(pt[i].id == 0)
                {
                    I = i;
                    break;
                }
                if(pt[i].cnt < mn)
                {
                    mn = pt[i].cnt;
                    I = i;
                }
            }

            R[I] = 0;
            pt[I].id = id;
            pt[I].cnt = 0;
        }


        for(int i=0; i<n; i++)
        {
            pt[i].cnt = pt[i].cnt >> 1;
            pt[i].cnt = pt[i].cnt | (R[i] << 8);
        }

    }

    printf("Hit: %d, Miss: %d\n", h, m);
    printf("Hits/Misses = %f\n", h/(double)m);
}
