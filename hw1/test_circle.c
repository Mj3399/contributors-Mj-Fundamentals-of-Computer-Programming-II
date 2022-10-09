// test_circle - Tests for the functions in ../src/circle.c.

#include "../src/circle.h"
#include <211.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

// "Factory function" for easily constructing circles.
struct circle make_circle(double x, double y, double radius)
{
    return (struct circle) {x, y, radius};
}

// Tests that tangent circles are not considered overlapped.
void test_tangent(void)
{
    // Hint: â€œ!â€ means â€œnotâ€, so this is an assertion that the
    // two circles *donâ€™t* overlap.
    CHECK(! overlapped_circles(make_circle(0, 0, 2), make_circle(4, 0, 2)));
}

// Tests that more distance circles are not considered overlapped.
void test_not_overlapped(void)
{
    CHECK(! overlapped_circles(make_circle(0, 0, 2), make_circle(5, 0, 2)));
    CHECK(! overlapped_circles(make_circle(0, 0, 2), make_circle(6, 0, 2)));
}

void test_overlap(void)
{
    CHECK(overlapped_circles(make_circle(0, 0, 2), make_circle(1, 1, 2)));
    CHECK(overlapped_circles(make_circle(0, 0, 2), make_circle(0, 0, 2)));
}

void test_fail(void)
{
    CHECK(!overlapped_circles(make_circle(0, 0, 2), make_circle(1, 1, 2)));
    CHECK(!overlapped_circles(make_circle(0, 0, 2), make_circle(0, 0, 2)));
}
int main(void)
{
    test_tangent();
    test_not_overlapped();
    test_overlap();
    
}
