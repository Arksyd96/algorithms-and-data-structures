/*
    One of the main advantages of dynamic allocation is to allow a program to reserve the necessary space for the 
    storage of an array in memory which size unknown before compilation. Until now, the size of our tables were fixed.
    It is imperative to know how to manipulate pointers to be able to use dynamic arrays
    Allocation is made in bytes, so use the formula: sizeof(type) * size of array :
*/
#include <stdlib.h>

int main(int argc, char** argv){
    int size, *arr = NULL;
    printf("Enter size of the array :");
    scanf("%d", &size);                         // get size of the array

    arr = malloc(sizeof(int) * size);           // use malloc() function to allocate memory
    if(!arr) exit(0);                           // if allocation failed

    free(arr);                                  // never forget to free manually allocated memory

    return EXIT_SUCCESS;
}