default:
	gcc -std=c99 -o Brainfuck *.c *.h

windows:
	gcc -std=c99 -o Brainfuck.exe *.c *.h
