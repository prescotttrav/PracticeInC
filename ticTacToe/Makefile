CC=gcc
DEPS=main.h board.h utils.h test/main.h test/board.h test/utils.h
OBJ=main.o board.o utils.o test/main.o test/board.o test/utils.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

tictactoe: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o test/*.o tictactoe 
