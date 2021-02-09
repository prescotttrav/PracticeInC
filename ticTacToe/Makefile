CC=gcc
DEPS=main.h board.h test/main.h test/board.h test/utils.h
OBJ=main.o board.o test/main.o test/board.o test/utils.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tictactoe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
