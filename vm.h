#ifndef GAMACLOX_VM_H
#define GAMACLOX_VM_H

#include "chunk.h"
#include "common.h"

#define STACK_MAX 256

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

typedef struct {
    Chunk *chunk;
    uint8_t *ip;
    Value stack[STACK_MAX];
    Value *stackTop;
} VM;

void initVM();

void freeVM();

InterpretResult interpret(const char* source);

void push(Value value);

Value pop();

#endif //GAMACLOX_VM_H