#include "Interpreter.h"

#include "StringUtils.h"
#include "Data.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Char definitions:
 *  > index += 1
 *  < index -= 1
 *  + char at current index += 1
 *  - char at current index -= 1
 *  . outputting the char at current index
 *  , char at current index = input
 */

// Data
int dataSize;
char* data;
int index;

// Initializing the interpreter
void init(int size) {
	dataSize = size;
	data = (char*)malloc(dataSize * sizeof(char));
	for (int i = 0; i < dataSize; i++)
		data[i] = 'a';
	index = 0;
}

void cleanUp() { free(data); }

// Evaluating a string
void eval(char* string) {
	for (int i = 0; i < getSize(string); i++) {
		if (string[i] == INDEX_UP)
			up();
		else if (string[i] == INDEX_DOWN)
			down();
		else if (string[i] == CHAR_UP)
			upChar();
		else if (string[i] == CHAR_DOWN)
			downChar();
		// TODO: Implement looping
	}
}

// Eval operations
void up() {
	index++;
	if (index >= dataSize)
		index = 0;
}

void down() {
	index--;
	if (index < 0)
		index = dataSize - 1;
}

void upChar() { data[index]++; }
void downChar() { data[index]--; }

void out() { putchar(data[index]); }
void in() { data[index] = getchar(); }
