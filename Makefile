CC=gcc
CFLAGS=-Wall -Wextra
LIBS=-lwiringPi
TARGET1=send
TARGET2=received


all: $(TARGET1) $(TARGET2)


$(TARGET1) : $(TARGET1).o
	$(CC) $(CFLAGS) -o $(TARGET1).out $(TARGET1).o

$(TARGET1).o: $(TARGET1).c
	$(CC) $(CFLAGS) -c $(TARGET1).c

$(TARGET2) : $(TARGET2).o
	$(CC) $(CFLAGS) -o $(TARGET2).out $(TARGET2).o $(LIBS)

$(TARGET2).o: $(TARGET2).c
	$(CC) $(CFLAGS) -c $(TARGET2).c

clean:
	rm -f *.out *.o

format:
	clang-format -i -style="WebKit" $(TARGET1).c $(TARGET2).c
