#include <gpio.h>
#define IN 0
#define OUT 1

int main(){
	pinMode(2, OUT);
	blink(2, 0.05, 10.00);
	return(0);
}