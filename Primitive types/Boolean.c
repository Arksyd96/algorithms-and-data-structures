/*
    A Boolean is a data type which can only store two values, represented by true and false on most languages,
    C language can be used to manipulate boolean data,  In addition, the language provides operators comparable 
    to the operators of Boolean algebra, However, the C language works in this case with integers using the following 
    convention: 0 and the null value represents the boolean constant false, any other value will be assimilated to 
    the constant true. We can very well try to reproduce the boolean type in this way :
*/

#include <stdio.h>
#include <stdlib.h>
        
#define TRUE 1
#define FALSE 0
        
typedef int bool;   // We can also creat a boolean from a uint8 in order to save some space (int 32bits vs uint8 8bits)
        
int main(int argc, char** argv) {
    bool myBoolean = TRUE;
    if(myBoolean) {
        printf("True");
    }
    return EXIT_SUCCESS;
}