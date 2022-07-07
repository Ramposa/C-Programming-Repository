#include<stdio.h>
#include<conio.h>

#define PI 3.14

void area(int);

main()
{
    int radius;
    printf("Enter radius of circle");
    scanf("%d",&radius);
    area(radius);
}

void area(int r)
{
    float result;
    result=PI*r*r;
    printf("Area of a circle is %f", result);
}