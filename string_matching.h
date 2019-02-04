#ifndef STRING_MATCHING_H
#define STRING_MATCHING_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int string_matching_naive(char *text, int N, char* pattern, int M);
int string_matching_kmp(char *text, int N, char* pattern, int M);

int * overlap_array(char* pattern, int M);
void print_array(int *arr, int size);

#endif