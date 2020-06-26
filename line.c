#include "line.h"
#include <stdio.h>
#include "memory.h"

void initLines(Lines *lines) {
    lines->lines = NULL;
    lines->capacity = 0;
    lines->count = 0;
}

void writeLine(Lines *lines, int line) {
    if (lines->count == 0 || lines->lines[lines->count - 2] != line) {
        if (lines->capacity < lines->count + 2) {
            int oldCapacity = lines->capacity;
            lines->capacity = GROW_CAPACITY(oldCapacity);
            lines->lines = GROW_ARRAY(lines->lines, int, oldCapacity, lines->capacity);
        }
        lines->lines[lines->count] = line;
        lines->lines[lines->count + 1] = 1;
        lines->count += 2;
    } else {
        lines->lines[lines->count - 1]++;
    }
}

int getLine(Lines *lines, int instructionIndex) {
    for (int i = 0; i < lines->count; i += 2) {
        instructionIndex -= lines->lines[i + 1];
        if (instructionIndex < 0) {
            return lines->lines[i];
        }
    }
    return -1;
}

void freeLines(Lines *lines) {
    FREE_ARRAY(int, lines->lines, lines->capacity);
    initLines(lines);
}