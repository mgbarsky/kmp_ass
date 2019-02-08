#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void short_test (char *text, int N, char * pattern, int M){
	printf("text='%s', pattern='%s'\n", text, pattern);
	int result1 = string_matching_naive(text, N, pattern, M);
	int result2 = string_matching_kmp(text, N, pattern, M);
	printf("Number of occurrences: result1=%d, result2=%d\n", result1, result2);
}

void stress_test(int N, int M){
  int i;
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  srand(time(NULL));   // Initialization, should only be called once.
  
  while (1) {
    int n = rand() % (N-3) + 3;      // Returns a pseudo-random integer between 3 and N.
    int m = rand() % M + 1; 
    
    char *text = malloc(n+1);
    for (i=0; i<n; i++){
	  int pos = rand() % (int)(sizeof(charset) -1);
          text[i] = charset[pos];      
    }
    text[i] = '\0';
	  
    char *pattern = malloc(m +1);
    for (i=0; i<m; i++){
	  int pos = rand() % (int)(sizeof(charset) - 1);
          pattern[i] = charset[pos];      
    }
    pattern[i] = '\0';
	  
    printf("text='%s', pattern='%s'\n", text, pattern);
	
    int result1 = string_matching_naive(text, n, pattern, m);
    int result2 = string_matching_kmp(text, n, pattern, m);
    
    if (result1==result2)
      	printf("OK\n");
    else {
      	printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
	exit(0);
    }
    free(text);
    free(pattern);
  }  
}

int main(int argc, char **argv ){
  if (argc < 4){
    printf("To run: test <1> <text> <N> <pattern> <M>\n or test <2> <N> <M>\n");
    return 0;
   }
   
   int mode = atoi(argv[1]);
   
   if (mode == 1){
	   if (argc < 6){
			printf("To run: test <1> <text> <N> <pattern> <M>\n");
			return 0;
	   }
	   char *text = argv[2];
	   int N = atoi(argv[3]);
	   char *pattern = argv[4];
	   int M = atoi(argv[5]);
	   printf("M=%d\n",M);
	   short_test(text, N, pattern, M);
	   return 0;
   }
   
   int N = atoi(argv[2]);
   int M = atoi(argv[3]);
   
   stress_test(N, M);
   
   return 0;
  
}
