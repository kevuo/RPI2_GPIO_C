#include <gpio.h>
#include <stdio.h>
#include <stdlib.h>

#define IN 0
#define OUT 1

int main(){
	//pinMode(2, OUT);

	int val;
	digitalWrite(2,1);
	val=digitalRead(2);
	fprintf(stdout, "Pin value is: %d\n", val);
	digitalWrite(2,0);
	val=digitalRead(2);
	fprintf(stdout, "Pin value is: %d\n", val);
	return(0);
}