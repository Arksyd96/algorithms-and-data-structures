/*
    Enumeration is a user-defined data type in C. It's mainly used to assign names to constants, it makes the code easier 
    to read and understand. We can declare an enumeration with the keyword "enum"
*/
#include <stdio.h>
#include <stdlib.h>
#define EXAMPLE 0 // turn this to 1 to see the second example

#if !EXAMPLE
// By default, first element of an enum is 0
enum Days {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
#else
// We can also assign a default starting value to the first element
enum Days {
    Monday = 10, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
#endif

int main(int argc, char** argv){
    enum Days day = Wednesday;
    printf("Wednesday is : %d \n", day); // prints 2
        
    return EXIT_SUCCESS;
}

