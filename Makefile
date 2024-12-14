CC = gcc
CFLAGS = -Wall -g

OBJ = main.o roomManip.o inventory.o fileIO.o commandParser.o stringManip.o

multi-level-dungeon: $(OBJ)
	$(CC) $(CFLAGS) -o multi-level-dungeon $(OBJ)

main.o: main.c roomManip.h inventory.h fileIO.h commandParser.h stringManip.h
	$(CC) $(CFLAGS) -c main.c

roomManip.o: roomManip.c roomManip.h
	$(CC) $(CFLAGS) -c roomManip.c

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c inventory.c

fileIO.o: fileIO.c fileIO.h
	$(CC) $(CFLAGS) -c fileIO.c

commandParser.o: commandParser.c commandParser.h
	$(CC) $(CFLAGS) -c commandParser.c

stringManip.o: stringManip.c stringManip.h
	$(CC) $(CFLAGS) -c stringManip.c

clean:
	rm -f *.o multi-level-dungeon

