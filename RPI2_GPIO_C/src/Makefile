APP=main
OP=libgpio
CC=gcc
SRC=$(APP).c
EXE=../bin/$(APP)
CFLAG=-I../include
LD_FLAGS=../lib/$(OP).so
EXE_MSG="Generando ejecutable..."
CLN_MSG="Borrando ejecutable..."

all: del $(EXE)

del:
		rm ../lib/gpio.o
		
$(EXE):
		@echo $(value EXE_MSG)
		$(CC) -o $(EXE) $(SRC) $(CFLAG) $(LD_FLAGS)

clean:
		@echo $(value CLN_MSG) 	
		rm $(EXE)