#include <stdio.h>

typedef struct point {
    float x;
    float y;
} point;

typedef struct square {
    point corners[4];
} square;

void setPoint(square*,int,float,float);
void printSquare(square);

int main(void) {

  square my_square;

  setPoint(&my_square,0,1.0,1.0);
  setPoint(&my_square,1,4.0,1.0);
  setPoint(&my_square,2,4.0,4.0);
  setPoint(&my_square,3,1.0,4.0);

  printSquare(my_square);
  return 0;
}

void setPoint(square *a_square,int corner,float x,float y)
{
  a_square->corners[corner].x = x;
  a_square->corners[corner].y = y;
}

void printSquare(square a_square)
{
  for (int i=0; i<4; i++)
  {
    printf("Corner %d (%f,%f)\n", i, a_square.corners[i].x, a_square.corners[i].y);
  }

}
