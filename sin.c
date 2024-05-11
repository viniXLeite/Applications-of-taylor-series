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
    long double sin;
    double angle, formatedAngle;

    printf("(Enter the angle in degrees)\nsin ");
    scanf("%lf", &angle);
    formatedAngle = formatAngle(angle);

    for(int n = 0; n <= serieLimit; n++){
        long double taylorSerie = (pow(-1,n)*pow(formatedAngle, 2*n+1))/factorial(2*n+1);
        sin += taylorSerie;
    }

    if(angle < 360 && angle > 180)
        sin = -1*sin;

    printf("\nsin(%.2f) = %.15Lf\n", angle, sin);
}