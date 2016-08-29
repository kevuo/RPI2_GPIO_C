#include <gpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#define RPI_GPIO_EXPORT "/sys/class/gpio/export"
#define RPI_GPIO_UNEXPORT "/sys/class/gpio/unexport"
#define MAXBUFFER 64	

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

//printf("echo %d > /sys/class/gpio/export\n", pin);
fprintf(exp, "%d", pin);

//printf("Pin exportado\n");
fclose(exp);

//Assign port direction
if(mode==0){
	strcpy(modeValue, "in");
}else{
	strcpy(modeValue, "out");
}

sprintf(path, "/sys/class/gpio/gpio%d/direction", pin);
//Write port direction to file
//printf("Abriendo pin en la direccion: %s\n", path);
direction = fopen(path, "w");
if (direction == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fprintf(direction, "%s", modeValue);
printf("Pin %d se asigna como: %s\n", pin, modeValue);
fclose(direction);

return(0);
}


int digitalWrite(int pin, int value){
	int fileDescriptor;
	char* v;
	char buffer[MAXBUFFER];

	sprintf(buffer, "/sys/class/gpio/gpio%d/value", pin);
	fileDescriptor= open(buffer, O_WRONLY);

	*v=value+'0';

	if(fileDescriptor==-1){
		fprintf(stderr, "Failed to open gpio pin\n");
		return(-1);
	}
	if(write(fileDescriptor, v,1)!=1){
		fprintf(stderr, "Failed to write value\n");
		return(-1);
	}


	close(fileDescriptor);
	return(0);
}

int digitalRead(int pin){

	int fileDescriptor;
	char buffer[MAXBUFFER];
	char value[3];

	sprintf(buffer, "/sys/class/gpio/gpio%d/value", pin);
	fileDescriptor= open(buffer, O_RDONLY);

	if(fileDescriptor==-1){
		fprintf(stderr, "Failed to open gpio pin\n");
		return(-1);
	}
	if(read(fileDescriptor,&value,1)==-1){
		fprintf(stderr, "Failed to read value\n");
		return(-1);
	}

	close(fileDescriptor);
	return(atoi(value));
}

int blink(int pin, int freq, int duration){

	time_t start,end;
	double elapsed;
	int condition=1;
	time(&start);
	while(condition){
		time(&end);
		elapsed=difftime(end,start);
		if(elapsed>= duration){
			condition=0;
		}
		digitalWrite(pin,1);
		delay(freq);
		digitalWrite(pin,0);
		return(0);
	}
}

void delay(int dly){
 time_t start = time(NULL);
 time_t current;

 while(difftime(current, start) < dly){
  time(&current);
 }
}

int unexportPin(int pin){
//Variables declaration.
FILE *unexp; 
//Unexport given pin.
unexp = fopen(RPI_GPIO_UNEXPORT, "w");
if (unexp == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

//printf("echo %d > /sys/class/gpio/unexport\n", pin);
fprintf(unexp, "%d", pin);

//printf("Pin desexportado\n");
fclose(unexp);
return(0);
}