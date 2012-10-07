#ifndef INTERPRETER_H
#define INTERPRETER_H

void initInterpreter(int size);
void cleanUpInterpreter();

int evalString(char*);
void evalChar(char);

#endif
