
#include "circle.h"

#include <stdio.h>
#include <math.h>

bool valid_circle(struct circle c)
{
    return c.radius > 0;
}

struct circle read_circle(void)
{
    struct circle c1;
    int g = scanf("%lf%lf%lf", &c1.x, &c1.y, &c1.radius);
    if (g == 3){
        return c1;
    }else{
        return (struct circle) {0, 0, -1};
    }
}

bool overlapped_circles(struct circle c1, struct circle c2)
{
    return ((c1.radius+c2.radius)*(c1.radius+c2.radius)) > 
    ((c1.x - c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
}

