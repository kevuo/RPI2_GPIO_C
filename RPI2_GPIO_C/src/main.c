#include <gpio.h>
#define IN 0
#define OUT 1

int main(){
	pinMode(2, OUT);
	pinMode(4, IN);
	pinMode(7, OUT);
	pinMode(8, IN);
	pinMode(9, OUT);
	pinMode(11, IN);
	return(0);
}