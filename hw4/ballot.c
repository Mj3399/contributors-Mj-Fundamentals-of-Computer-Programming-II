#include "ballot.h"
#include "helpers.h"

#include <211.h>

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A `ballot_t` (defined in `ballot.h`) is be a pointer to a
// heap-allocated `struct ballot`, with the following invariant:
//
//  - `length <= MAX_CANDIDATES`
//
//  - the first `length` elements of `entries` are initialized
//
//  - the `name` field of each of the first `length` entries is non-NULL
//    and points to an OWNED, heap-allocated string containing only
//    letters, all of which are uppercase (a la isupper(3)).
//
// The remaining elements of `entries` (`MAX_CANDIDATES - length`)
// should be considered uninitialized.

struct entry
{
    char* name;
    bool active;
};

struct ballot
{
    size_t length;
    struct entry entries[MAX_CANDIDATES];
};


ballot_t ballot_create(void)
{
    ballot_t ballot = malloc(sizeof(struct ballot));
    // size of struct ballot = malloc(size_t length +
    // sizeof(struct entry)*MAxcandidates)
    if (!ballot){
        exit(2);
    }
    int i = 0;
    ballot->length = 0;
    while (i<(MAX_CANDIDATES)){
        ballot->entries[i].name = NULL;
        ballot->entries[i].active = false;
        i++;
    }
    return ballot;
}

void ballot_destroy(ballot_t ballot)
{
    if(ballot == NULL){
        return;
    }
    int i = 0;
    while (i<(ballot->length)){
        free(ballot->entries[i].name);
        i++;
    }
    free(ballot);
}

void ballot_insert(ballot_t ballot, char* name)
{
    if(ballot->length < (MAX_CANDIDATES + 1)){
        clean_name(name);
        ballot->entries[ballot->length].name = name;
        ballot->entries[ballot->length].active = true;
        ballot->length += 1;
    }else{
        exit(3);
    }
    
}

const char* ballot_leader(ballot_t ballot)
{
    int i=0;
    while(i < ballot->length){
        if (ballot->entries[i].active){
            return ballot->entries[i].name;
        }
        i++;
    }
    return NULL;
}

void ballot_eliminate(ballot_t ballot, const char* name)
{
    int i=0;
    while(i < ballot->length){
        if (strcmp(ballot->entries[i].name, name) == 0){
            ballot->entries[i].active = false;
        }
        i++;
    }
}

void count_ballot(vote_count_t vc, ballot_t ballot)
{
    const char* bl = ballot_leader(ballot);
    if (bl == NULL){
        return;
    }
    size_t* bc = vc_update(vc, bl);
    if (bc == NULL){
        exit(4);
    }
    *bc += 1;
    
}

ballot_t read_ballot(FILE* inf)
{
    
    char* line;
    if ((line = fread_line(inf)) == NULL){
        return NULL;
    }
    ballot_t ballot = ballot_create();
    while(line != NULL && strcmp(line, "%") != 0){
        ballot_insert(ballot, line);
        line = fread_line(inf);
    }
    free(line);
    return ballot;
    
}

void clean_name(char* name)
{
    int i =0;
    int j =0;
    char* dst = name;
    char* src = name;
    while (name[i] != '\0'){
        if(isalpha(src[i]) == 0){
            i++;
            continue;
        }
        char c;
        c = src[i];
        dst[j] = toupper(c);
        i++;
        j++;
    }
    dst[j] = '\0';
    name = dst;
}

void print_ballot(FILE* outf, ballot_t ballot)
{
    for (size_t i = 0; i < ballot->length; ++i) {
        bool active = ballot->entries[i].active;
        fprintf(outf, "%c%s%s\n",
                active? ' ' : '[',
                ballot->entries[i].name,
                active? "" : "]");
    }
}
