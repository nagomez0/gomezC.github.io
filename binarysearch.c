/* Write a C Program that executes binary search in an array of Strings. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Binary Search to find x within sorted arr
// 1. Find middle element of arr
// 2. Compare middle element to x 
// if equal -> return middle index
// if less (before) -> binary search right half of arr[0:mid]
// if more (after) -> binary search left half of arr[mid:end]


// Sort array alphabetically
int cmpstr(void const *a, void const *b) { 
    char const *a2 = (char const *)a;
    char const *b2 = (char const *)b;
    // Utilize strcomp to compare str's
    return strcmp(a2, b2);
}

int binarySearch(char* arr[], char *x, size_t size) {
	// Sort arr elements alphabetically
	qsort(arr, size, sizeof(char*), cmpstr);

	// Init points in array
	int beg = 0;
	int mid;
	int end = size - 1;

	while (beg <= end) {
    	mid = (beg + end)/2;
		// If y == x value, return mid
		if (strcmp(arr[mid], x) == 0) {
			return mid;
		} else if (strcmp(arr[mid], x) > 0) { // If y > x, continue checking left half of array (split at mid)
      		end = mid - 1; 
		} else if (strcmp(arr[mid], x) < 0) { // If y < x, continue checking right half of array (split at mid)
      		beg = mid + 1; 
		}
	}
  	// Case: x not found in arr
	return -1;
}

int main(void) {
	// Generate array of [10] strings
	// char* char pointer - arr of char
  	char *arrList[10] = {
    	"Apollo",
		"Blathers",
		"Isabelle",
		"Mabel",
		"Nook",
		"Rover",
		"Slider",
		"Timmy",
		"Tommy",
    	"Zipper"
	};

	// target word
	char *x = "Rover";

	// Find and print index of target word (-1 -> not found)
  	int result = binarySearch(arrList, x, 10);
	if (result == -1) 
	  printf ("\n%s could not be found", x);
	else
	  printf("\n%s located at index %d", x, result);

	return 0;
}