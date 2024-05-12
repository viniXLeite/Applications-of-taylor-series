#include <stdio.h>

int main(){
  long int serieLimit;
  long double fat = 1.0;
  long double e = 1.0;

  printf("Define a limit to the serie: ");
  scanf("%ld", &serieLimit);


  for(long int i = 1; i <= serieLimit; i++){
    for(int num = 1; num <= i; num++){
      fat = fat*num;
    }
    e += (1/fat);
    fat = 1.0;
  }
  printf("euler: %.50Lf\n\n", e);
  return 0;
}