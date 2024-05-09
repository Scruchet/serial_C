CC=gcc
CFLAGS=-Wall -Wextra -lwiringPi
TARGET=received

all: $(TARGET)

$(TARGET) : $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET).out $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	rm -f *.out *.o
