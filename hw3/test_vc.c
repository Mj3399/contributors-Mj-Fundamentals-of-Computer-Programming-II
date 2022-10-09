#include "../src/libvc.h"

#include <211.h>

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_create_destroy(void)
{
    vc_destroy(vc_create());
}

static void test_2_candidates(void)
{
    // Skip this test if MAX_CANDIDATES isn't large enough.
    if (MAX_CANDIDATES < 2) {
        return;
    }

    size_t* cp;
    vote_count_t vc = vc_create();
    CHECK( vc != NULL );
    if (vc == NULL) {
        // Can't keep testing if vc is NULL
        return;
    }

    CHECK_POINTER( vc_max(vc), NULL );
    CHECK_POINTER( vc_min(vc), NULL );
    CHECK_SIZE( vc_lookup(vc, "alice"), 0 );
    CHECK_SIZE( vc_lookup(vc, "bob"), 0 );
    CHECK_SIZE( vc_total(vc), 0 );

    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_STRING( vc_max(vc), "alice" );
    CHECK_STRING( vc_min(vc), "alice" );
    CHECK_SIZE( vc_lookup(vc, "alice"), 1 );
    CHECK_SIZE( vc_lookup(vc, "bob"), 0 );
    CHECK_SIZE( vc_total(vc), 1 );

    cp = vc_update(vc, "bob");
    CHECK( cp );
    *cp += 1;
    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_STRING( vc_max(vc), "alice" );
    CHECK_STRING( vc_min(vc), "bob" );
    CHECK_SIZE( vc_lookup(vc, "alice"), 2 );
    CHECK_SIZE( vc_lookup(vc, "bob"), 1 );
    CHECK_SIZE( vc_total(vc), 3 );

    vc_destroy(vc);
}

static void test__candidates(void)
{

    size_t* cp;
    vote_count_t vc = vc_create();
    CHECK( vc != NULL );
    if (vc == NULL) {
        // Can't keep testing if vc is NULL
        return;
    }

    CHECK_POINTER( vc_max(vc), NULL );
    CHECK_POINTER( vc_min(vc), NULL );
    CHECK_SIZE( vc_total(vc), 0 );

    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_STRING( vc_max(vc), "alice" );
    CHECK_STRING( vc_min(vc), "alice" );
    CHECK_SIZE( vc_lookup(vc, "alice"), 1 );
    CHECK_SIZE( vc_total(vc), 1 );

    vc_destroy(vc);
}

static void test_candidates(void)
{

    size_t* cp;
    vote_count_t vc = vc_create();
    CHECK( vc != NULL );
    if (vc == NULL) {
        // Can't keep testing if vc is NULL
        return;
    }

    CHECK_POINTER( vc_max(vc), NULL );
    CHECK_POINTER( vc_min(vc), NULL );
    CHECK_SIZE( vc_total(vc), 0 );

    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_STRING( vc_max(vc), "alice" );
    CHECK_STRING( vc_min(vc), "alice" );
    CHECK_SIZE( vc_lookup(vc, "alice"), 1 );
    CHECK_SIZE( vc_total(vc), 1 );
    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_SIZE( vc_lookup(vc, "alice"), 2 );
    CHECK_SIZE( vc_total(vc), 2 );
    

    vc_destroy(vc);

    vc = vc_create();
    CHECK( vc != NULL );
    if (vc == NULL) {
        // Can't keep testing if vc is NULL
        return;
    }

    CHECK_POINTER( vc_max(vc), NULL );
    CHECK_POINTER( vc_min(vc), NULL );
    CHECK_SIZE( vc_total(vc), 0 );

    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_STRING( vc_max(vc), "alice" );
    CHECK_STRING( vc_min(vc), "alice" );
    CHECK_SIZE( vc_lookup(vc, "bob"), 0 );
    CHECK_SIZE( vc_total(vc), 1 );
    cp = vc_update(vc, "alice");
    CHECK( cp );
    *cp += 1;
    CHECK_SIZE( vc_lookup(vc, "alice"), 2 );
    CHECK_SIZE( vc_total(vc), 2 );
    

    vc_destroy(vc);
}
static void testcandidates(void)
{
    size_t* p;
    vote_count_t vc = vc_create();
    CHECK( vc != NULL );
    if (vc == NULL) {
        // Can't keep testing if vc is NULL
        return;
    }

    p = vc_update(vc, "Madison"); *p += 1;
    p = vc_update(vc, "Monroe"); *p += 1;
    p = vc_update(vc, "Madison"); *p += 1;
    p = vc_update(vc, "Madison"); *p += -2;
    vc_lookup(vc, "Madison");
    CHECK_SIZE( vc_lookup(vc, "Madison"), 0 );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "Quincy Adams"); *p += 1;
    vc_update(vc, "Jackson"); ++*p;
    vc_update(vc, "Van Buren"); ++*p;
    CHECK_SIZE( vc_lookup(vc, "Jackson"), 0 );
    CHECK_SIZE( vc_lookup(vc, "Quincy Adams"), 3 );
    CHECK_SIZE( vc_lookup(vc, "Van Buren"), 0 );
    vc_destroy(vc);
    vc = vc_create();
    vc_max(vc);
    vc_min(vc);
    CHECK_STRING( vc_max(vc), NULL );
    CHECK_STRING( vc_min(vc), NULL );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "W. H. Harrison"); *p += 1;
    p = vc_update(vc, "Tyler"); *p += 1;
    p = vc_update(vc, "W. H. Harrison"); *p += 1;
    p = vc_update(vc, "Tyler"); *p += 1;
    vc_min(vc);
    CHECK_STRING( vc_min(vc), "Tyler" );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "W. H. Harrison"); *p += 1;
    p = vc_update(vc, "Tyler"); *p += 1;
    p = vc_update(vc, "W. H. Harrison"); *p += 1;
    p = vc_update(vc, "Tyler"); *p += 1;
    vc_min(vc);
    CHECK_STRING( vc_min(vc), "Tyler" );
    CHECK_STRING( vc_max(vc), "W. H. Harrison" );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "W. H. Harrison"); *p += 1;
    p = vc_update(vc, "W. H. Harrison"); *p += -1;
    vc_max(vc);
    CHECK_STRING( vc_max(vc), NULL );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "Tyler"); *p += 1;
    p = vc_update(vc, "Tyler"); *p += -1;
    vc_min(vc);
    CHECK_STRING( vc_min(vc), NULL );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "Polk"); *p += 1;
    p = vc_update(vc, "Polk"); *p += 1;
    p = vc_update(vc, "Tayler"); *p += 1;
    p = vc_update(vc, "Polk"); *p += 1;
    p = vc_update(vc, "Tayler"); *p += 1;
    p = vc_update(vc, "Fillmore"); *p += 1;
    vc_total(vc);
    CHECK_SIZE( vc_total(vc), 6 );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "Taft"); *p += 1;
    p = vc_update(vc, "Wilson"); *p += 1;
    p = vc_update(vc, "Harding"); *p += 1;
    p = vc_update(vc, "a"); *p += 1;
    p = vc_update(vc, "b"); *p += 1;
    p = vc_update(vc, "c"); *p += 1;
    p = vc_update(vc, "d"); *p += 1;
    p = vc_update(vc, "e"); *p += 1;
    p = vc_update(vc, "f"); *p += 1;
    p = vc_update(vc, "g"); *p += 1;
    p = vc_update(vc, "h"); *p += 1;
    p = vc_update(vc, "i"); *p += 1;
    p = vc_update(vc, "Coolidge"); *p += 1;
    p = vc_update(vc, "Hoover"); *p += 1;
    p = vc_update(vc, "FDR"); *p += 1;
    p = vc_update(vc, "Truman"); *p += 1;
    p = vc_update(vc, "Eisenhower");
    p = vc_update(vc, "Coolidge"); *p += 1;
    p = vc_update(vc, "Wilson"); *p += 1;
    p = vc_update(vc, "Harding"); *p += 1;
    vc_lookup(vc, "Taft");
    CHECK_SIZE( vc_lookup(vc, "Taft"), 1 );
    vc_max(vc);
    CHECK_STRING( vc_max(vc), "Wilson" );
    vc_min(vc);
    CHECK_STRING( vc_min(vc), "Truman" );
    p = vc_update(vc, "Truman"); *p += 1;
    p = vc_update(vc, "Truman"); *p += 1;
    vc_max(vc);
    CHECK_STRING( vc_max(vc), "Truman" );
    vc_destroy(vc);
    vc = vc_create();
    p = vc_update(vc, "Taft"); *p += 1;
    p = vc_update(vc, "Wilson"); *p += 2;
    p = vc_update(vc, "Harding"); *p += 2;
    p = vc_update(vc, "a"); *p += 2;
    p = vc_update(vc, "b"); *p += 3;
    p = vc_update(vc, "c"); *p += 4;
    p = vc_update(vc, "d"); *p += 5;
    p = vc_update(vc, "e"); *p += 6;
    p = vc_update(vc, "f"); *p += 7;
    p = vc_update(vc, "g"); *p += 7;
    p = vc_update(vc, "h"); *p += 8;
    p = vc_update(vc, "i"); *p += 9;
    p = vc_update(vc, "Coolidge"); *p += 2;
    p = vc_update(vc, "Hoover"); *p += 3;
    p = vc_update(vc, "FDR"); *p += 2;
    p = vc_update(vc, "Truman"); *p += 2;
    vc_lookup(vc, "six-hundred bees");
    CHECK_SIZE( vc_lookup(vc, "six-hundred bees"), 0 );
    CHECK_STRING( vc_min(vc), "Taft" );
    CHECK_STRING( vc_max(vc), "i" );
    CHECK_SIZE( vc_total(vc), 65 );
    vc_destroy(vc);
}

int main(void)
{
    test_create_destroy();
    test_2_candidates();
    test__candidates();
    test_candidates();
    testcandidates();
    return 0;
}
