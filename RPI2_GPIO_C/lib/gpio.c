#include <gpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RPI_GPIO_DIR "/sys/class/gpio/gpio"
#define RPI_GPIO_EXPORT "/sys/class/gpio/export"
#define MAXBUFFER 64	
#define MAX_PATH_BUFFER = 30;

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
printf("%s %d %s %s", "echo ", pin, " > ", RPI_GPIO_EXPORT);
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

// int digitalWrite(int pin, int value){
// 	int fileDescriptor;
// 	char buffer[MAX_PATH_BUFFER];

// 	sprintf(buffer, ""/sys/class/gpio/"gpio%d/value", pin);
// 	fileDescriptor= open(buffer, O_WRONLY);

// 	if(fileDescriptor==-1){
// 		fprintf(stderr, "Failed to open gpio pin\n");
// 		return(-1);
// 	}
// 	if(write(fileDescriptor, value+'0',1)!=1){
// 		fprintf(stderr, "Failed to write value\n");
// 		return(-1);
// 	}


// 	close(fileDescriptor);
// 	return(0);
// }

// int digitalRead(int pin, int value){

// 	int fileDescriptor;
// 	char buffer[MAX_PATH_BUFFER];
// 	char value[3];

// 	sprintf(buffer, ""/sys/class/gpio/"gpio%d/value", pin);
// 	fileDescriptor= open(buffer, O_RDONLY);

// 	if(fileDescriptor==-1){
// 		fprintf(stderr, "Failed to open gpio pin\n");
// 		return(-1);
// 	}
// 	if(read(fileDescriptor,&value,1)==-1){
// 		fprintf(stderr, "Failed to read value\n");
// 		return(-1);
// 	}

// 	close(fileDescriptor);
// 	return(atoi(value));
// }

// int blink(int pin, int freq, int duration){

// 	time_t start,end;
// 	double elapsed;
// 	int condition=1;
// 	time(&start);
// 	while(condition){
// 		time(&end);
// 		elapsed=difftime(end,start);
// 		if(elapsed>= duration){
// 			condition=0;
// 		}
// 		digitalWrite(pin,1);
// 		delay(freq);
// 		digitalWrite(pin,0);
// 		return(0);
// 	}
	
// int unexportPin(int pin){

// return(0);
// }