
// overlapped - Reads a target circle, then any number of candidate
// circles. Prints "overlapped\n" for each candidate circle that
// intersects the target and "not overlapped\n" for each candidate
// circle that does not. Exits after reading an invalid circle.

#include "circle.h"
#include <stdio.h>

#define OVERLAPPED_MSG      "overlapped\n"
#define NOT_OVERLAPPED_MSG  "not overlapped\n"

int main(void)
{
    struct circle c1 = read_circle();
    if (valid_circle(c1)) {
        while (true){
            struct circle c2 = read_circle();
            if (valid_circle(c2)) {
                if (overlapped_circles(c1, c2)) {
                    printf("overlapped\n");
                }else{
                    printf("not overlapped\n");
                }
            }else{
                return 0;
            }
    }  
    }else{
        return 1;
    }
}
