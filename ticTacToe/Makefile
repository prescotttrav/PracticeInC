CC=gcc
DEPS=main.h board.h display.h playerMove.h position.h utils.h validateWinner.h 
OBJ=main.o board.o display.o playerMove.o position.o utils.o validateWinner.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

tictactoe: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o test/*.o tictactoe 
