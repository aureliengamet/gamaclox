#ifndef GAMACLOX_LINE_H
#define GAMACLOX_LINE_H

typedef struct {
    int capacity;
    int count;
    int *lines;
} Lines;

void initLines(Lines *lines);

void writeLine(Lines *lines, int line);

int getLine(Lines *lines, int instructionIndex);

void freeLines(Lines *lines);

#endif //GAMACLOX_LINE_H