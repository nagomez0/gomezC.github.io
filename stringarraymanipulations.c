/* Write a C Program that initializes an array with ten random strings and then prints four lines of output, containing 1)Every element at an even index; 2)Every element with an even size; 3)All elements in reverse order; 4)Only the first and last elements. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * newRandomStr() {
  int n = rand() % 11 + 1; // str size randomly assigned between 1 and 10
  char* str = malloc(n); // allocates storage for str so it can be reassigned
  char* alphabet = "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < n; i++) {
    str[i] = alphabet[rand() % 26];
  }

  return str;

}

int main(void) {
  
  srand(time(NULL)); //init 
  
  char* strList[10];
  
  for(int i = 0; i < 10; i++){ 
    strList[i] = newRandomStr();
    printf("%d. %s\n", i+1, strList[i]);
  }

  //Output 1
  printf("Every element at even index:\n");
  for(int i = 0; i < 5; i ++){
    printf("%s\n", strList[i*2]);
  }

  //Output 2
  printf("\n\nEven size:\n");
  for(int i = 0; i < 10; i++){
    if(strlen(strList[i])%2==0){
      printf("%s\n", strList[i]);
    }
  }

  //Output 3
  printf("\n\nReverse order:\n");
  for(int i = 0; i < 10; i++){
    printf("%s\n", strList[9-i]);
  }

  //Output 4
  printf("\n\nFirst and Last:\n%s, %s", strList[0], strList[9]);

  return 0;
}