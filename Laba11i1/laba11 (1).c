#include <stdio.h>
#include <math.h>
double arctg(double x, int n)
{
    double f = pow(-1, n-1) * (pow(x, 2*n - 1)/(2 * n - 1));

    if(f < 0.5 * pow(10, -3))
        return f;
    return f + arctg(x, n+1);

}



int main()
{
    printf("Enter x for arctg: ");
    double x;
    scanf("%lf", &x);
    while(!(x >= -1 && x <= 1))
    {
        printf("-1 <= x <= 1. Try aganin: ");
        scanf("%lf", &x);
    }
    printf("%lf\n", arctg(x, 1));
    printf("%lf\n", atan(x));
}