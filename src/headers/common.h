#ifndef CSAPP_COMMON_H
#define CSAPP_COMMON_H

#include <stdint.h>

#define DEBUG_PRINTCACHESET     (0x8)
#define DEBUG_CACHEDETAILS      (0x10)
#define DEBUG_MMU               (0x20)
#define DEBUG_LOADER            (0x80)
#define DEBUG_PARSEINST         (0x100)
#define DEBUG_VERBOSE_SET       (0x241)

// do page walk
#define DEBUG_ENABLE_PAGE_WALK  (0)

// type converter
// uint32 to its equivalent float with rounding
uint32_t uint2float(uint32_t u);

// convert string dec or hex to the integer bitmap
typedef enum {
    STRING2UINT_LEADING_SPACE,
    STRING2UINT_FIRST_ZERO,
    STRING2UINT_POSITIVE_DEC,
    STRING2UINT_POSITIVE_HEX,
    STRING2UINT_NEGATIVE,
    STRING2UINT_NEGATIVE_FIRST_ZERO,
    STRING2UINT_NEGATIVE_DEC,
    STRING2UINT_NEGATIVE_HEX,
    STRING2UINT_ENDING_SPACE,
    STRING2UINT_FAILED
} string2uint_state_t;
string2uint_state_t string2uint_next(string2uint_state_t state, char c, uint64_t *bmap);
uint64_t string2uint(const char *str);
uint64_t string2uint_range(const char *str, int start, int end);

// commonly shared variables
#define MAX_INSTRUCTION_CHAR    (64)

/*=======================================*/
/*         wrap of the memory            */
/*=======================================*/

void *tag_malloc(uint64_t size, char *tagstr);
int tag_free(void *ptr);
void tag_sweep(char *tagstr);

#endif //CSAPP_COMMON_H
