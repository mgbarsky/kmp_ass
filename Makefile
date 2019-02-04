CC = gcc
CFLAGS = -Wall -std=c99

all: test

string_matching_naive.o: string_matching_naive.c string_matching.h 
	$(CC) $(CFLAGS) -c string_matching_naive.c

string_matching_kmp.o: string_matching_kmp.c string_matching.h
	$(CC) $(CFLAGS) -c string_matching_kmp.c
	
test.o: test.c string_matching.h
	$(CC) $(CFLAGS) -c test.c
	
test: string_matching_naive.o string_matching_kmp.o test.o
	$(CC) $(CFLAGS) -o test string_matching_naive.o string_matching_kmp.o test.o

clean:
	rm *.o test
