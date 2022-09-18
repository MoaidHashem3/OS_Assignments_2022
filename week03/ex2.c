#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

double distance (struct point A, struct point B){
    double distance;
    distance = sqrt((pow((A.x-B.x),2.0)+pow((A.y-B.y), 2.0)));
    return distance;
}

double area (struct point A, struct point B, struct point C) {

    double area;
    area = 0.5*((A.x*B.y) - (B.x*A.y) + (B.x*C.y) - (C.x*B.y) + (C.x*A.y) - (A.x*C.y));
    return area;
}


int main(){

    struct point p1;
    p1.x = 2.5;
    p1.y = 6.0;
    struct point p2;
    p2.x = 1.0;
    p2.y = 2.2;
    struct point p3;
    p3.x = 10.0;
    p3.y = 6.0;
    double Distance = distance(p1, p2);
    double Area = area(p1,p2,p3);
    printf("The Area of the Tringle is %f unit\n", Area);
    printf("The Distance between A and B is %f unit\n", Distance);

    return 0;
    
}