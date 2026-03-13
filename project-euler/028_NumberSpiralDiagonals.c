#include <stdio.h>

int solve(int spiral_side)
{
    int tour = 1;
    int iter = 1;
    int sum = iter;

    while (iter < spiral_side * spiral_side)
    {
        int step = tour * 2;
        for (int i = 0; i < 4; i++)
        {
            iter += step;
            sum += iter;
        }
        tour++;
    }
    return sum;
}

int main()
{
    int sum = solve(1001);
    printf("sum: %d\n", sum);
    return 0;
}
