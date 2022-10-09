///
/// Tests for functions in ../src/ballot_box.c.
///

#include "ballot_box.h"
#include "helpers.h"

#include <211.h>

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


///
/// FORWARD DECLARATIONS
///

// Takes the expected winner, followed by all the votes. Each ballot is
// given as successive string arguments, terminated by "%". The final
// argument, after the final ballot's "%", must be NULL.
static void check_election(const char* expected_winner, ...);

// Test case functions (you need more!):
static void three_candidates_tied(void),
            win_on_third_round(void),
            example_from_wikipedia(void);


///
/// MAIN FUNCTION
///
    static void three_candidates_tied();
    static void win_on_third_round();
    static void example_from_wikipedia();
  //  static void state_elec();
int main(void)
{
    three_candidates_tied();
    win_on_third_round();
    example_from_wikipedia();
  //  state_elec();
}


///
/// TEST CASE FUNCTIONS
///

static void three_candidates_tied(void)
{
    if (MAX_CANDIDATES < 3) {
        return;
    }

    check_election("A",
            "a", "b", "c", "%",
            "a", "b", "c", "%",
            NULL);
}



static void win_on_third_round(void)
{
    if (MAX_CANDIDATES < 6) {
        return;
    }

    check_election("BIDEN",
            "Bloomberg", "Biden", "%",
            "Yang", "Biden", "%",
            "Warren", "Biden", "%",
            "Sanders", "Biden", "%",
            "Biden", "Sanders", "%",
            "Biden", "Gabbard", "%",
            NULL);
}

static void example_from_wikipedia(void)
{
    if (MAX_CANDIDATES < 3) {
        return;
    }

    check_election("SUE",
            "bob", "bill", "s u e", "%",
            "Sue", "Bob", "Bill", "%",
            "Bill!", "Sue!", "BoB!", "%",
            "bob", "bill", "sue", "%",
            "sue", "bob", "bill", "%",
            NULL);
}
//static void state_elec(void)
//{
 //   if (MAX_CANDIDATES < 3) {
   //     return;
    //}
    //int i =0;
 //   ballot_box_t bb = empty_ballot_box;
 //   ballot_t a = ballot_create(); 
//    ballot_insert(a, strdupb("MEMPHIS", "check_election"));
//    ballot_insert(a, strdupb("NASHVILLE", "check_election"));
//    ballot_insert(a, strdupb("CHATTANOOGA", "check_election"));
//    ballot_insert(a, strdupb("KNOXVILLE", "check_election"));
//    
 //   ballot_t b = ballot_create();
//    ballot_insert(b, strdupb("NASHVILLE", "check_election"));
//    ballot_insert(b, strdupb("CHATTANOOGA", "check_election"));
 //   ballot_insert(b, strdupb("KNOXVILLE", "check_election"));
//    ballot_insert(b, strdupb("MEMPHIS", "check_election"));
 //   
 //   ballot_t c = ballot_create();
//    ballot_insert(c, strdupb("CHATTANOOGA", "check_election"));
//    ballot_insert(c, strdupb("KNOXVILLE", "check_election"));
//    ballot_insert(c, strdupb("NASHVILLE", "check_election"));
 //   ballot_insert(c, strdupb("MEMPHIS", "check_election"));
    
//    ballot_t d = ballot_create();
 //   ballot_insert(d, strdupb("KNOXVILLE", "check_election"));
    //ballot_insert(d, strdupb("CHATTANOOGA", "check_election"));
    //ballot_insert(d, strdupb("NASHVILLE", "check_election"));
  //  ballot_insert(d, strdupb("MEMPHIS", "check_election"));
//    
    //while(i<42){
  //      bb_insert(&bb, a);
//        i++;
    //}
    //i =0;
    //while(i<26){
        //bb_insert(&bb, b);
      //  i++;
    //}
    //i =0;
    //while(i<15){
       // bb_insert(&bb, c);
     //   i++;
    //}
    //i =0;
    //while(i<17){
        //bb_insert(&bb, d);
      //  i++;
    //}
    //vote_count_t vc = bb_count(bb);
    //CHECK_SIZE(vc_lookup(vc, "MEMPHIS"), 42);
    //CHECK_SIZE(vc_lookup(vc, "NASHVILLE"), 26);
    //CHECK_SIZE(vc_lookup(vc, "CHATTANOOGA"), 15);
  //  CHECK_SIZE(vc_lookup(vc, "KNOXVILLE"), 17);
//    
    //bb_eliminate(bb, "CHATTANOOGA");
    //vc_destroy(vc);
    //
    //vc = bb_count(bb);
    //CHECK_SIZE(vc_lookup(vc, "MEMPHIS"), 42);
    //CHECK_SIZE(vc_lookup(vc, "NASHVILLE"), 26);
    //CHECK_SIZE(vc_lookup(vc, "KNOXVILLE"), 32);
    //
    //bb_eliminate(bb, "NASHVILLE");
    //vc_destroy(vc);
    //
    //vc = bb_count(bb);
    //
    //CHECK_SIZE(vc_lookup(vc, "MEMPHIS"), 42);
    //CHECK_SIZE(vc_lookup(vc, "KNOXVILLE"), 58);
    //vc_destroy(vc); bb_destroy(bb);
    //
    //
  //  
//}
///


///
/// HELPER FUNCTIONS YOU SHOULD USE
///

// These are helpers for `check_election()` that you are unlikely to
// call directly.
static ballot_box_t build_ballot_box(va_list);
static void check_irv_winner(const char*, ballot_box_t);


// Simulates an election and checks the winner. The first argument
// is the name of the expected winner, and the remaining arguments
// are the names on the ballots, with "%" in between and a NULL
// marking the end. (See uses of this function above for examples.)
static void
check_election(const char* expected, ...)
{
    va_list ap;
    va_start(ap, expected);
    ballot_box_t bb = build_ballot_box(ap);
    va_end(ap);

    check_irv_winner(expected, bb);

    bb_destroy(bb);
}


/// HELPERS FOR THE HELPERS

// Builds a ballot box from multiple string arguments. Returns
// ownership of the ballot box to the caller.
static ballot_box_t
build_ballot_box(va_list ap)
{
    ballot_box_t bb = empty_ballot_box;
    ballot_t ballot = NULL;

    char* name;
    while ((name = va_arg(ap, char*))) {
        if (!ballot) {
            ballot = ballot_create();
        }

        if (strcmp(name, "%") == 0) {
            bb_insert(&bb, ballot);
            ballot = NULL;
        } else {
            ballot_insert(ballot, strdupb(name, "check_election"));
        }
    }

    if (ballot) {
        bb_insert(&bb, ballot);
    }

    return bb;
}

// Checks that `expected` is the winner of `bb`. Borrows both arguments.
static void
check_irv_winner(const char* expected, ballot_box_t bb)
{
    char* actual = get_irv_winner(bb);

    if (expected) {
        CHECK_STRING(actual, expected);
    } else {
        CHECK_POINTER(actual, expected);
    }

    free(actual);
}
