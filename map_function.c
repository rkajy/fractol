#include <stdio.h>

//rescaledValue = ((new_max - new_min) * (unscaledNum - old_min)) / (old_max - old_min) + new_min
//
double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) + (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

int main()
{
    for(int i = 0; i < 800; ++i)
    {
        printf("d -> %f\n", i, scale((double)i, -2, +2, 0, 799 ));
    }

    return 0;
}