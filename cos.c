#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

long int factorial(int n){
    long int parcialFat = 1;
    for(int num = 1; num <= n; num++){
        parcialFat = parcialFat*num;
    }
    return parcialFat;
}

double formatAngle(double angle){
    double formatedAngle;

    for(int i = 1; angle > 90; i++){
        if(angle >= 360)
            angle = angle-360;
        else if(angle < 360 && angle > 270)
            angle = 360-angle;
        else if(angle <= 270 && angle >= 180)
            angle = angle-180;
        else if(angle < 180 && angle > 90)
            angle = 180-angle;
    }
    formatedAngle = angle*(PI/180);    
    return formatedAngle;
}

int main(){
    int serieLimit = 32;
    long double cos;
    double angle, formatedAngle;

    printf("(Enter the angle in degrees)\ncos ");
    scanf("%lf", &angle);
    formatedAngle = formatAngle(angle);

    for(int n = 0; n <= serieLimit; n++){
        long double taylorSerie = (pow(-1,n)*pow(formatedAngle, 2*n))/factorial(2*n);
        cos += taylorSerie;
    }

    if(angle < 270 && angle > 90)
        cos = -1*cos;

    printf("\ncos(%.2f) = %.15Lf\n", angle, cos);
    return 0;
}