#include <gpio.h>
#include <stdio.h>
#define IN 0
#define OUT 1

int main(){
	int valRead;
	pinMode(2, OUT);
	pinMode(3, OUT);
	pinMode(4, IN);	
	digitalWrite(2, 1);
	blink(3, 0.05, 5.00);
	valRead=digitalRead(4);
	printf("Pin %d reads value:%d\n", 4, valRead);
	return(0);
}