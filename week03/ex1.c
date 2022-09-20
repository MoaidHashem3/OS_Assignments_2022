#include<stdio.h>
#include<stdlib.h>
int foo (int age){

    int birthyear; 
    birthyear = 2022 - age;
    return birthyear;

}

int main(void) {
    const int x = 10;
    const int* q = &x;
    int* ptr =(int *) malloc(5* sizeof(int));
    printf("%s", "The Memoery Addresses: ");
    for (int i=0; i<5; i++){
        printf("\t%p", ptr+i);
        *(ptr+i)=x;

    }
        printf("\n");

    printf("%s", "Values of the cells before 'Foo': ");

    for (int i=0; i<5; i++){
        printf("\t%d", *(ptr+i));
    }
    printf("\n");
        printf("%s", "Values of the cells after 'Foo': ");

     for (int i=0; i<5; i++){
        *(ptr+i)=foo(*(ptr+i));
        printf("\t%d", *(ptr+i));
    }
    free(ptr);
}