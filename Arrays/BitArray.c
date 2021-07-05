/*
    A bit array (or bitmap) is an array where each variable can only contain the binary values 0 and 1.
    C language does not provide support for bit arrays, since the smallest addressable unit in C is the byte (8 bits) 
    and using an array of int instead means losing a lot of memory (wasting 31/32 bits for an int).
    However, The C programming language provides all the necessary operations to allow the programmer 
    to implement a bit array data structure. 
    An Efficient implementation of bit arrays is to create an array of integers and use all the 32bits of an int :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// this function will return the size of int array
int bitToInt(int bitArraySize){
    return bitArraySize / 32 + (bitArraySize % 32 ? 1 : 0);
}

// sets a bit to 1
void setBit(int bitArray[], int pos){
    // getting position of the bit
    int i = pos / 32;
    int k = pos % 32;
        
    unsigned int flag = 1 << k;
    bitArray[i] = bitArray[i] | flag;
}

// sets a bit to 0
void clearBit(int bitArray[], int pos){
    int i = pos / 32;
    int k = pos % 32;
        
    unsigned int flag = ~(1 << k);
    bitArray[i] = bitArray[i] & flag;
}

// Main
int main(int argc, char** argv){
    int size = bitToInt(145);    // getting the required size for 145 bits array
    int bitArray[size];             // create bit array
    for (int i = 0; i < size; i++){
        bitArray[i] = 0;            // initialize array
    }
        
    setBit(bitArray, 0);
    setBit(bitArray, 1);
    setBit(bitArray, 2);            // 000...000111
    printf("%d \n", bitArray[0]);   // prints 7 which is equal to 111
        
    clearBit(bitArray, 1);          // 000...000101
    printf("%d \n", bitArray[0]);   // prints 5 which is equal to 101

    setBit(bitArray, 33);           // 000...000010
    printf("%d \n", bitArray[1]);   // prints 2 on the second int of the array

    // Note, it's also possible to make a cleaner get bit instead of using Printf
        
    return EXIT_SUCCESS;
}

