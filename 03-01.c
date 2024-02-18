#include <stdio.h>

//Write functions "quot" and "rem"
//quot(x,y)*y + rem(x,y) == x;

int quot(int x, int y);
int rem(int x, int y);

void main(){
  int x,y;
  printf("x = ?\n");
  scanf("%d",&x);
  printf("y = ?\n");
  scanf("%d",&y);

  printf("X = %d, Y = %d, quot(x,y) = %d, rem(x,y) = %d\n", x, y, quot(x,y), rem(x,y));
  printf("quot(x,y)*y + rem(x,y) == %d\n", quot(x,y)*y + rem(x,y));
}

int quot(int a, int b){
  return a/b;
}

int rem(int a, int b){
  return a%b;
}
