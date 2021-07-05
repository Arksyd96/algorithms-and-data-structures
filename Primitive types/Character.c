/*
    A \"char\" is a data type that can store a character,
    In C language, a char is encoded as a number using ASCII encoding, and it has a size of 1 byte
*/

#include <stdio.h>
#include <stdlib.h>
        
int main(int argc, char** argv){
    char myChar = 'a';      
    printf("%c\n", myChar);   // %c to print a character
    printf("The size of a character is %d\n", (int)sizeof(char));

    myChar = 'a';
    printf("%d\n", myChar);   // prints 97
            
    myChar = 65;
    printf("%c\n", myChar);   // prints 'A'

    myChar = 'a';
    printf("%c\n", myChar);   // prints 'a'
        
    myChar += 2;
    printf("%c\n", myChar);   // prints 'c'
        
    if (myChar == 99){
        printf("it's a 'c' character.\n");
    }
            
    return EXIT_SUCCESS;
}