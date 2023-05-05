/* Write a C Program that transform numbers 1, 2, 3, ..., 12 into the corresponding month names January, February, March, ..., December. */

#include <stdio.h>

char *getMonth(int i);

int main() {
  int month;
  printf("Please input month #: ");
  scanf("%d" , &month);
  // '&' creates a pointer (reference to)
  printf("%s\n" , getMonth(month));
  return 0;
}

char *getMonth(int i) {
  // '*' dereferences a pointer 
  char *monthString[12] = {
    "January",
    "February", 
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };
  return monthString[i-1]; 
}