/*
    C language provides several types of integers, they differs by their size.
    We can get the maximum value of each type by using the library \"limits.h\" :
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
        
int main(int argc, char** argv){
    int myInt = INT_MAX;
    printf("Size of int : %d, Max value : %d \n", (int)sizeof(int), myInt);
        
    short myShort = SHRT_MAX;
    printf("Size of short : %d, Max value : %i \n", (int)sizeof(short), myShort);
        
    long myLong = LONG_MAX;
    printf("Size of long : %d, Max value : %ld \n", (int)sizeof(long), myLong);
    printf("Sometimes, long are also on 4 octets! Depends on your machine. This is why Long long have been created \n");

    long long myLLong = __LONG_LONG_MAX__;
    printf("Size of long long : %d, Max value : %lld \n", (int)sizeof(long long), myLLong);
        
    return EXIT_SUCCESS;
}