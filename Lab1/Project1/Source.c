#include <stdio.h>

int main()
{
    int a, num, N;

    printf("\n\nEnter a (1...180) : ");
    {
        scanf_s("%d", &a);
        if (a < 1 || a > 180)
        {
            printf("This number does not fit\nPlease try again: ");
        }
    }
    while (a < 1 || a > 180);
    N = a;
    int i = 10;
    for (; a; i++) 
    { 
        num = (i / 10) % 10; 
        a--; 
        if (a) 
        { 
            num = i % 10; 
            a--; 
        } 
    } 
    printf("%d in the sequence is:  %d\n\n\n\n", N, num);
    return 0; 
}