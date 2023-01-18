#include <stdio.h>
#include <math.h>
int step = 1;

float polyFunc(float x)
{
    return -cos(x) + 3 * x - 1;
}

float diffFunc(float x)
{
    float ans = sin(x) + 3;
    return ans;
}

void NewtonRaphson(float x, float allowErr)
{
    x = x - ((polyFunc(x) / diffFunc(x)));
    step++;
    printf("The value of x is = %f\n", x);
    if (fabs(polyFunc(x)) <= allowErr)
    {
        printf("The steps are = %d\n", step);
        return;
    }
    NewtonRaphson(x, allowErr);
}

int main()
{
    float a, b, allowErr;
    while (1)
    {
        printf("Enter guessed range  (a,b) = ");
        scanf("%f%f", &a, &b);

        if (polyFunc(a) * polyFunc(b) < 0)
        {
            float x;
            printf("Root are accepted !!!\n");
            printf("Enter the Allow error - ");
            scanf("%f", &allowErr);
            printf("Enter any mid value between range = ");
            scanf("%f", &x);
            printf("The value of x is = %f\n", x);
            NewtonRaphson(x, allowErr);
            break;
        }
        else
        {
            printf("oops invalid input !!!");
        }
    }
    return 0;
}
