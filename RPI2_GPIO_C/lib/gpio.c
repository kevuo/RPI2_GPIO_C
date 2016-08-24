#include <gpio.h>
#define RPI_GPIO_DIR "/sys/class/gpio/gpio"
#define RPI_GPIO_EXPORT "/sys/class/gpio/export"
#define MAXBUFFER 64	
#define OUT 1

int pinMode(int pin, int mode){
//Variables declaration.
FILE *exp; 
FILE *direction;
char modeValue[MAXBUFFER]; 
char path[MAXBUFFER];

//Export given pin.
exp = fopen(RPI_GPIO_EXPORT, "w");
if (exp == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fprintf(exp, "%s %d %s %s", "echo ", pin, " > ", RPI_GPIO_EXPORT);
fclose(exp);

//Assign port direction
if(mode==0){
	strcpy(modeValue, "out");
}else{
	strcpy(modeValue, "in");
}

//Write port direction to file
direction = fopen(path, "w");
if (direction == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fprintf(direction, "%s %s %s %s %d %s", "echo ", modeValue, " > ", RPI_GPIO_DIR, pin, "/direction");
fclose(direction);

return(0);
}

int digitalWrite(int pin, int value){


return(0);
}

int digitalRead(int pin){


return(0);
}

int blink(int pin, int freq, int duration){


return(0);
}

int unexportPin(int pin){

return(0);
}