#ifndef CSAPP_INSTRUCTION_H
#define CSAPP_INSTRUCTION_H

#include <stdint.h>

/*======================================*/
/*    instruction set architecture      */
/*======================================*/

typedef enum OPERAND_TYPE {
    OD_EMPTY,
    OD_IMM,
    OD_REG,
    OD_MEM
} od_type_t;

typedef struct OPERAND_STRUCT {
    od_type_t type;
    uint64_t value;
} od_t;

// handler table storing the handlers to different instruction types
typedef void (*op_t)(od_t *, od_t *);

// local variables are allocated in stack in run-time
// we don't consider local static variables
// ref: Computer System: A Programmer's Perspective 3rd
// Chapter 7 Linking: 7.5 Symbols and Symbol Tables
typedef struct INST_STRUCT {
    op_t op;        // enum of operators. e.g. mov, call, etc.
    od_t src;       // operand src of instruction
    od_t dst;       // operand dst of instruction
} inst_t;

#define MAX_NUM_INSTRUCTION_CYCLE   100
#define DEREF_VALUE(od)             (*(uint64_t *)(od->value))

#endif //CSAPP_INSTRUCTION_H
