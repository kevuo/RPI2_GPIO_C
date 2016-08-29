APP=main
OP=libgpio
SRC=$(APP).c
EXE=../src/$(APP)
CFLAG+=-I../include
LD_FLAGS+=-L../lib/ -lgpio
EXE_MSG="Generando ejecutable..."
CLN_MSG="Borrando ejecutable..."

all: $(EXE)

del:
		rm ../lib/gpio.o
		
$(EXE):
		@echo $(value EXE_MSG)
		$(CC) -o $(EXE) $(SRC) $(CFLAG) $(LD_FLAGS)

clean:
		@echo $(value CLN_MSG) 	
		rm $(EXE)
