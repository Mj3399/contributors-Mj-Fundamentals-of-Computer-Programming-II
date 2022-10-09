#include "libvc.h"

#include <211.h>

#include <stdio.h>

#define OOM_MESSAGE     "%s: out of memory\n"
#define DROP_MESSAGE    "%s: vote dropped: %s\n"
#define FINAL_MESSAGE   "%s: %zu vote(s) dropped\n"

int main(int argc, char* argv[])
{
    vote_count_t vc = vc_create();
    if (vc == NULL){
        fprintf(stderr, OOM_MESSAGE, argv[0]);
        return 1;
    }
    char* line;
    size_t dropped = 0;
    size_t* x = 0;
    while((line = read_line()) != NULL){
        x = vc_update(vc, line);
        if(x == NULL){
            fprintf(stderr, DROP_MESSAGE, "./count", line);
            dropped += 1;
        }else{
            *x += 1;
        }
        free(line);
    }
    vc_print(vc);
    vc_destroy(vc);
    if(dropped > 0){
        fprintf(stderr, FINAL_MESSAGE, "./count", dropped);
        return 2;
    }

    return 0;
}

