/*
    A bit field is a data structure that consists of a number of adjacent memory units which have been allocated 
    with an explicit width, in bits. A bit field is generally used to represent integral types of known, fixed bit-width.
    For example, suppose we want to represent data in day / month / year format with a bit field structure :
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} Date;

typedef struct OptimizedDate {
    unsigned int day    : 5;    // 31 maximum values so we need 5 bits
    unsigned int month  : 4;    // 12 maximum values so we need 4 bits
    unsigned int year   : 12;   // 12 bits if we suppose max year is 4096
} OptimizedDate;

// Note : Always use unsigned int, unless you have negative values. In this case it is necessary to count one more bit.

int main(int argc, char** argv){
    printf("Size of a normal date structure : %d \n", (int)sizeof(Date));
    printf("Size of the bit field date structure : %d \n", (int)sizeof(OptimizedDate));

    OptimizedDate date;
    date.day    = 22;
    date.month  = 6;
    date.year   = 1998;
    printf("My date of birth is : %d/%d/%d \n", date.day, date.month, date.year);

    date.day = 52;
    printf("field day cannot contain values bigger than 32 \nday = %d, because first the 5 first bits of 52 gives 20\n", date.day);

    // Note
    // We cannot have pointers to bit field members as they may not start at a byte boundary :
    /*
        OptimizedDate date;
        date.month  = 6;
        printf("Address of date.month is %d \\n", &date.month); // Will return an error: cannot take address of bit-field 'month'
    */
    return EXIT_SUCCESS;
}
