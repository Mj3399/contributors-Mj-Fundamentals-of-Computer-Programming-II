#include "ballot_box.h"
#include "helpers.h"

#include <211.h>

#include <stdlib.h>
#include <string.h>

// A `ballot_box_t` (defined in `ballot_box.h`) is a linked list made
// of `struct bb_node`s. Each node owns the next node, so the whole list
// is owned by the pointer to the first node.
struct bb_node
{
    ballot_t ballot;
    struct bb_node* next;
};


// The empty ballot box is the null pointer.
const ballot_box_t empty_ballot_box = NULL;


void bb_destroy(ballot_box_t bb)
{
    while (bb != NULL){
        ballot_box_t temp = bb;
        bb = bb->next;
        ballot_destroy(temp->ballot);  
        free(temp);
        
        }
    
}

void bb_insert(ballot_box_t* bbp, ballot_t ballot)
{
    ballot_box_t head = mallocb(sizeof *head, "bb_insert");
    head->ballot = ballot;
    head->next   = *bbp;
    *bbp = head;
}

ballot_box_t read_ballot_box(FILE* inf)
{
    ballot_box_t bb = empty_ballot_box;
    ballot_t ballot;
    while((ballot = read_ballot(inf)) != NULL){
        bb_insert(&bb, ballot);
    }
    return bb;
}

vote_count_t bb_count(ballot_box_t bb)
{
    vote_count_t result = vc_create();
    struct bb_node* current = bb;
    while (current != NULL){
        const char* leader = ballot_leader(current->ballot);  
        size_t* lc = vc_update(result, leader);
        *lc += 1;
        current = current->next;
    }
    
    return result;
}

void bb_eliminate(ballot_box_t bb, const char* candidate)
{
    struct bb_node* current = bb;
    while (current != NULL){
        ballot_eliminate(current->ballot, candidate);
        current = current->next;
    }
}

char* get_irv_winner(ballot_box_t bb)
{
    ///vote_count_t vc = NULL;
    while(true){
        ///vc_destroy(vc);
        vote_count_t vc = bb_count(bb);
        const char* max = vc_max(vc);
        size_t total = vc_total(vc);
        if(total == 0){
            vc_destroy(vc);
            return NULL;
        }
        size_t maxv = vc_lookup(vc, max);
        if (maxv > ((.5)*total)){
            char* result = strdupb(max, "get_irv_winner");
            vc_destroy(vc);
            return result;
        }else{
            const char* min = vc_min(vc);
            bb_eliminate(bb, min);
            vc_destroy(vc);
        }
    }
}
