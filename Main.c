// A simple brainfuck
// implementation, because
// why the hell not?

#include "Interactive.h"
#include "Static.h"
#include "Data.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc == 2) {
		staticRead(argv[1]);
	} else if (argc > 2) {
		printf("Usage: brainfuck [file location]");
	} else {
		printf("Brainfuck -- Written by Cerek Hillen\n");
		printf("Version: %s", VERSION);

		interactive();
	}
}
