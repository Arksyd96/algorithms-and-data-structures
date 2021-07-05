/*
    Float and double are data types used to represent floating point numbers (real numbers), 
    float is only 4 bytes (32 bits) while double is 8 bytes (64 bits for a double precision),
    Float has a precision of 6 decimal digits and double 15 decimal digits,
    We use \"%f\" to print a float and \"%lf\" to print a double in C language :
*/

#include <stdio.h>
#include <stdlib.h>
        
int main(int argc, char** argv){
    float myFloat = 3.141592;   // 6 decimal digits
    printf("float value with 6 digits : %f \n", myFloat);
        
    myFloat = 3.141592653589793;    // 15 decimal digits
    printf("float value with 15 digits : %0.15f \n", myFloat);  
        
    double myDouble = 3.141592653589793;
    printf("double value with 15 digits : %0.15f \n", myDouble);

    printf("As you can see, values after the 7th decimal of the float are wrong \n");

    printf("size of a float : %d bytes \n", (int)sizeof(float));
    printf("size of a double : %d bytes \n", (int)sizeof(double));
        
    return EXIT_SUCCESS;
}