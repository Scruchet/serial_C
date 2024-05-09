CC=gcc
CFLAGS=-Wall -Wextra
TARGET=test

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS).out -c $(TARGET).c

clean:
	rm -f $(TARGET).out $(TARGET).o
