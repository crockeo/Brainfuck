#include "Interpreter.h"

#include "StringUtils.h"
#include "Data.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Char definitions:
 *  > - index += 1
 *  < - index -= 1
 *  + - char at current index += 1
 *  - - char at current index -= 1
 *  . - outputting the char at current index
 *  , - char at current index = input
 */

// Declaring functions
void up();
void down();
void upChar();
void downChar();
void out();
void in();
void loop(char* operation, int timesToLoop);

// Data
int dataSize;
char* data;
int index;

int isGettingLoopString = 0;
int isGettingTimesToLoop = 0;
int timesToLoop = 1;
char* loopString = NULL;
int loopStringIndex = 0;

// Initializing the interpreter
void initInterpreter(int size) {
	dataSize = size;
	data = (char*)malloc(dataSize * sizeof(char));
	for (int i = 0; i < dataSize; i++)
		data[i] = 'a';
	index = 0;
}

void cleanUpInterpreter() { free(data); }

// Evaluating a string
int evalString(char* string) {
	if (equals(string, "quit") || equals(string, "exit"))
		return 1;
	
	for (int i = 0; i < getSize(string); i++)
		evalChar(string[i]);

	return 0;
}

// Evaluating a given character
void evalChar(char c) {
	if (isGettingLoopString) {
		if (c == ']') {
			isGettingLoopString = 0;
			isGettingTimesToLoop = 1;
		} else {
			loopString[loopStringIndex] = c;
			loopStringIndex++;
		}
	} else if (isGettingTimesToLoop) {
		if (c == '+')
			timesToLoop++;
		else {
			isGettingTimesToLoop = 0;
			loop(loopString, timesToLoop);
		}	
	} else {
		if (c == INDEX_UP)
			up();
		else if (c == INDEX_DOWN)
			down();
		else if (c == CHAR_UP)
			upChar();
		else if (c == CHAR_DOWN)
			downChar();
		else if (c == OUTPUT)
			out();
		else if (c == INPUT)
			in();
		else if (c == BEGIN_LOOP) {
			isGettingLoopString = 1;
			loopString = (char*)malloc(128 * sizeof(char));
			loopStringIndex = 0;
		}
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

void loop(char* operation, int timesToLoop) {
	for (int i = 0; i < timesToLoop; i++)
		evalString(operation);
}
