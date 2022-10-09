#include "translate.h"

#include <stddef.h>
#include <stdlib.h>

// Helper function for interpreting escapes. Given the character that
// follows a backslash, returns the character that the combination
// should be replaced with. Recognizes the seven standard C escapes, and
// maps every other character to itself.
char interpret_escape(char c)
{
    switch (c) {
    case 'a': return '\a';
    case 'b': return '\b';
    case 'f': return '\f';
    case 'n': return '\n';
    case 'r': return '\r';
    case 't': return '\t';
    case 'v': return '\v';
    default:  return c;
    }
}

size_t charseq_length(const char* src)
{
    size_t result = 0;
    size_t i = 0;
    while (src[i] != '\0') {
        if (src[i+1] == '-' && src[i+2] != '\0') {
            if (src[i] > src[i+2]){
                i += 3;
            }else{
                result += src[i+2] - src[i] + 1;
                i += 3;
            }
      } else if (src[i] == '\\' && src[i+1] != '\0'){
            result += 1;
            i += 2;
      } else{
        result += 1;
        i++;
      }
        
    }

    return result;
}

char* expand_charseq(const char* src)
{
    char* const dst = malloc(charseq_length(src) + 1);
    if (!dst) {
        return NULL;
    }

    size_t i = 0;
    size_t j = 0;


    while (src[i] != '\0') {
        if (src[i+1] == '-' && src[i+2] != '\0') {
            if (src[i] > src[i+2]){
                    i += 3;
            }else{
                int h = src[i];
                while (h <= src[i+2]){
                    dst[j] = h;
                    j++;
                    h++;
                }
                i += 3;
            }
                
            }
          else if(src[i] == '\\' && src[i+1] != '\0'){
               dst[j] = interpret_escape(src[i+1]);
               j++;
               i += 2;
         } else{
            dst[j] = src[i];
            i++;
            j++;
      }
      }
    dst[j] = '\0'; 
    return dst;  
    }

    

    


// The starter code for expand_charseq above is written in
// *array-indexing style*, whereas the commented-out expand_charseq
// below uses *pointer arithmetic style*. If you prefer pointer
// arithmetic to array indexing, you may comment out the expand_charseq
// above and uncomment the one right here:
/*
char* expand_charseq(const char* src)
{
    char* result = malloc(charseq_length(src) + 1);
    if (!result) {
        return NULL;
    }

    char* dst    = result;

    //
    // TODO: Your code goes here
    //

    *dst = 0;

    return result;
}
*/

char translate_char(char c, const char* from, const char* to)
{
    size_t i =0;
    while (from[i] != '\0'){
        if (from[i] == c) {
            return to[i];
        }else{
            i++;
        }
    }

    return c;
}

void translate(char* s, const char* from, const char* to)
{
    size_t i =0;
    while (s[i] != '\0'){
        s[i] = translate_char(s[i], from, to);
        i++;
    }
}

