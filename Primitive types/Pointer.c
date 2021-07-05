/*
    A pointer is a type of data that is dedicated to storing memory addresses. In C, it can be used to allocate 
    memory dynamically or manipulate complex data structures 
*/

#include <stdio.h>
#include <stdlib.h>
        
int main(int argc, char** argv){
    // We can create a pointer of any data type with the character *
    int     *pInt;
    float   *pFloat;
    double  *pDouble;
    char    *pChar;

    // You can also declare pointers in these ways
    int*  p;
    int * p2;

    // Use the address operator & to get the address of a variable, and dereference operator * to get the 
    // variable pointed by a pointer
    int var = 5;
    int* pVar = &var;
        
    printf("Address of var is : %d \n", pVar);
    printf("Value of var is : %d \n", *pVar);
        
    *pVar += 5;
        
    printf("New value of var is : %d \n", var);

    // Note
    // You cannot and should not do something like :
    // *pVar = &var;
    // This will overwrite to the variable var it's address

    // We can also affect a NULL value to a pointer which means the pointer contains no address, 
    // we can also use an if statement to check if a pointer is NULL or not :

    p = NULL; // equivalent to 0
    printf("The value of pointer is : %d \n", p);
        
    if (!p){
        printf("The pointer is NULL \n");
    }
        
    return EXIT_SUCCESS;
}