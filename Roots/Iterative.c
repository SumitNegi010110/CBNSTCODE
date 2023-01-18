#include <stdio.h>
#include <math.h>
int steps = 0;

float polyFunc(float x)
{
    return 2 * x - (log(x) / log(10)) - 7;
}

float diffFunc(float x)
{
    return 1 / (2 * x * log(10));
}

float xForm(float x)
{
    return ((log(x) / log(10)) + 7) / 2;
}

void Iterative(float x, float allowErr)
{
    x = xForm(x);
    steps++;
    printf("%d  iteration and the value of x is - %f\n", steps, x);
    if (fabs(polyFunc(x)) <= allowErr)
        return;
    Iterative(x, allowErr);
}

int main()
{
    float x, allowErr;
    while (1)
    {
        printf("Enter the guessed value - ");
        scanf("%f", &x);

        if (fabs(diffFunc(x)) < 1)
        {
            printf("Input is satisfying the condition\n");
            printf("Enter the allowed Error - ");
            scanf("%f", &allowErr);
            Iterative(x, allowErr);
            break;
        }
        else
            printf("Oops invalid input!!!");
    }
    return 0;
}