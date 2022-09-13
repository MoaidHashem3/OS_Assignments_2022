#include <stdio.h>
#include <limits.h>
#include<float.h>

int main(void){

 int a = INT_MAX;
 unsigned short int b = USHRT_MAX;
 signed long int c= LONG_MAX;
 float d = FLT_MAX;
 double f= DBL_MAX;
 
  printf("Int: %d\n",a);
  printf("Short Int: %d\n",b);
  printf("Long Int: %ld\n",c);
  printf("Float: %f \n",d);
  printf("Double: %f\n",f);

 return 0 ;
}
