/*
    An array is a data structure that allows variables to be stored contiguously in memory, you can access a variable 
    in the array with its index. However, a single array can only contain variables of the same type.
    The access to a variable in an array is instantaneous, so we have a complexity of O(1) for this structure.
    First index of an array in C language is 0, these are the different ways of declaring an array
*/
#include <stdio.h>
#include <stdlib.h>
        
int main(int argc, char** argv){
    int arr[10];    // declare an array of 10 integers
            
    int array_size = 10;
    int arr2[array_size];   // declare an array of user specified size 
            
    int arr3[] = {14, 75, 6, 42, 18};
    printf("at index 2 we have %d \n", arr3[2]);    // prints 6
            
    char cArr[10];  // we can create an array of any data type, even structures
    double dArr[10];

    // Moreover, character strings are represented by arrays of chars that ends with the special 
    // character "\0". This end of string character indicates to the computer when the chain stops so 
    // it's important to always put it at the end of a string :

    char string[] = "Hello";    // declare array of 6 chars
    printf("My string is : %s \n", string);   // we print string with %s format specifier
        
    printf("Second character of the string is : %c \n", string[1]); //starts at 0
        
    if (string[5] == '\0'){
        printf("Last character is '\\0' \n");  // the string ends with \0
    }
            
    return EXIT_SUCCESS;
}