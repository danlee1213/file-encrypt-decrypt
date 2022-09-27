CC = gcc
TARGET = AES_TEST
OBJECTS = aes.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

clean :
	rm *.o AES_TEST