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
int eval(char* string) {
	if (equals(string, "quit") || equals(string, "exit"))
		return 1;

	int isGettingLoopString = 0;
	int isGettingTimesToLoop = 0;
	int timesToLoop = 1;
	char* loopString = NULL;
	int loopStringIndex = 0;

	for (int i = 0; i < getSize(string); i++) {
		if (isGettingLoopString) {
			if (string[i] == ']') {
				isGettingLoopString = 0;
				isGettingTimesToLoop = 1;
			} else {
				loopString[loopStringIndex] = string[i];
				loopStringIndex++;
			}
		} else if (isGettingTimesToLoop) {
			if (string[i] == '+')
				timesToLoop++;
			else {
				isGettingTimesToLoop = 0;
				loop(loopString, timesToLoop);
			}	
		} else {
			if (string[i] == INDEX_UP)
				up();
			else if (string[i] == INDEX_DOWN)
				down();
			else if (string[i] == CHAR_UP)
				upChar();
			else if (string[i] == CHAR_DOWN)
				downChar();
			else if (string[i] == OUTPUT)
				out();
			else if (string[i] == INPUT)
				in();
			else if (string[i] == BEGIN_LOOP) {
				isGettingLoopString = 1;
				loopString = (char*)malloc(128 * sizeof(char));
				loopStringIndex = 0;
			} else if (string[i] == END_LOOP) {
				printf("ERROR: End of loop before beginning of loop.\n");
			}
		}
	} if (isGettingTimesToLoop) {
		isGettingTimesToLoop = 0;
		loop(loopString, timesToLoop);
	}

	return 0;
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
		eval(operation);
}
