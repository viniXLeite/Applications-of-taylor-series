#include <stdio.h>

int main(){
  long int LimiteSerie;
  long double fat = 1.0;
  long double e = 1.0;

  printf("Digite um limite para a serie: ");
  scanf("%ld", &LimiteSerie);


  for(long int i = 1; i <= LimiteSerie; i++){
    for(int num = 1; num <= i; num++){
      fat = fat*num;
    }
    e += (1/fat);
    printf("fat (%ld): %.0Lf\n", i, fat);
    printf("euler parcial: %.50Lf\n\n", e);
    fat = 1.0;
  }
}