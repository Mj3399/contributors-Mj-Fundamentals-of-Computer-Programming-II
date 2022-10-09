#include "libvc.h"

#include <211.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// This definition is private to this file; code in all other files
// can only handle pointers to it: values of type `struct vote_count*`
// (a/k/a `vote_count_t`), not values of type `struct vote_count`. Only
// code in this file sees this definition, so only code in this file can
// work with `struct vote_count`s directly.
struct vote_count
{
    char*  candidate;
    size_t count;
};

// A vote_count_t will be a pointer to a `malloc`ed array of
// MAX_CANDIDATES `struct vote_count`s, with the following invariant:
//
//  - Some prefix of `candidate` fields are distinct, OWNED, `malloc`ed
//  strings, and the remaining `candidate` fields are NULL.
//
//  - When a `candidate` field is NULL the value of the corresponding
//  `count` does not mean anything, but when the `candidate` is non-NULL
//  then the `count` must be a properly initialized count.

/*
 * Q: Where are header comments for the following functions?
 * A: libvc.h
 */

vote_count_t vc_create(void)
{
    vote_count_t vc = malloc(sizeof(struct vote_count)*(MAX_CANDIDATES));
    if (!vc){
        return NULL;
    }
    int i = 0;
    while (i < (MAX_CANDIDATES)){
        vc[i].candidate = NULL;
        vc[i].count = 0;
        i++;
    }
    return vc;
}

void vc_destroy(vote_count_t vc)
{
    int i = 0;
    while (i < (MAX_CANDIDATES)){
        free(vc[i].candidate);
        i++;
    } 
    free(vc);
}

static struct vote_count*
vc_find_name(vote_count_t vc, const char* name)
{
    int i = 0;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate != NULL){
            if (strcmp(vc[i].candidate, name) == 0){
                return &vc[i];
            }
        }
        i++;
        }
    return NULL;
}

static struct vote_count*
vc_find_empty(vote_count_t vc)
{
    int i = 0;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate == NULL){
            return &vc[i];
        }
        i++;
    }
    return NULL;
}

static char*
strdup_or_else(const char* src)
{
    char* dst = malloc(strlen(src) + 1);
    if (!dst){
        fprintf(stderr, "%s: error: out of memory", src);
        exit(1);
    }
    strcpy(dst, src);
    return dst;
}

size_t* vc_update(vote_count_t vc, const char* name)
{ 
    struct vote_count* vfn = vc_find_name(vc, name);
    if (vfn != NULL){
        return &vfn->count;
    }else{
        struct vote_count* vcv = vc_find_empty(vc);
        if (vcv == NULL){
            return NULL;
        }
        char* name1 = strdup_or_else(name);
        vcv->candidate = name1;
        vcv->count = 0;
        return &(vcv->count);
        
    }
}

size_t vc_lookup(vote_count_t vc, const char* name)
{
    struct vote_count* vcv = vc_find_name(vc, name);
    if (vcv != NULL){
        return vcv->count;
    }else{
        return 0;
    }
}

size_t vc_total(vote_count_t vc)
{
    int i = 0;
    size_t total = 0;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate != NULL){
            total += vc[i].count;
        }else{
            return total;
        }
        i++;
    }
    return total;
}

const char* vc_max(vote_count_t vc)
{
    int i = 0;
    const char* max = NULL;
    size_t maxv = 0;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate != NULL){
            if (vc[i].count > maxv){
                max = vc[i].candidate;
                maxv = vc[i].count;
            }
        }else{
            return max;
        }
        i++;
    }
    return max;
}

const char* vc_min(vote_count_t vc)
{
    int i = 0;
    const char* min = NULL;
    size_t minv = SIZE_MAX;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate != NULL){
            if (vc[i].count <= minv){
                min = vc[i].candidate;
                minv = vc[i].count;
            }
        }else{
            if (minv == 0){
                return NULL;
            }else{
                return min;
            }
        }
        i++;
    }
    if (minv == 0){
        return NULL;
    }else{
        return min;
    }
}

void vc_print(vote_count_t vc)
{
    int i =0;
    while (i < MAX_CANDIDATES){
        if (vc[i].candidate != NULL){
            printf("%-20s %9zu\n", vc[i].candidate, vc[i].count);
        }
        i++;
    }
}

