#Brainfuck

###About
An implementation of the brainfuck language, with a little bit of a twist.

Programmed in C exclusively.

###Twist
The main difference between this implementation of Brainfuck and many others is the manner in which it loops. It makes it
more explicit and more easily controllable, but also has its drawbacks.

In this version of Brainfuck there are only finite loops. You start a loop with '[' and end it with ']'. Like that it
will only run once (which isn't much of a loop). To designate a loop to run more than once you add '+'s to show that it
will run more than once.

For instance, running "[.]" will print out the current character once, while "[.]+++" will print out the current
character four times.

###Syntax
The syntax is Brainfuck is rather simple, just incredibly useless.
In total there are 8 operators, '>', '<', '+', '-', '.', ',', '[', and ']'

* > Used to increment the index
* < Used to decrement the index
* + Used to increment the current character
* - Used to decrement the current character
* . Used to output the current character
* , Used to set the current character to the input
* [ Used to designate the beginning of a loop
* ] Used to designate the end of a loop
* ]+(or more) Used to designate how many times you want to do a loop.

###Credits
Completely developed by Crockeo