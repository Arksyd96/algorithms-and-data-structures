/*
    Gap buffer is a dynamic data structure that allows you to perform several operations on the data
    near the same location, it is commonly used on text editors to handle the cursor's behavior,
    permitting efficient insertion and deletion of the characters. Moving the cursor involves copying 
    text from one side of the gap to another, which can be expansive sometimes because of a complexity 
    of O(n). In counterpart, deleting and inserting characters is instantaneous and takes O(1) time.
    Note : 
    Gap buffers are inefficient for large files and handling multiple cursors.
    Here is an example :

    - initially, we can have something like this
    This is the way [                     ]out.
    - we insert some text
    This is the way the world started [   ]out.
    - we move the cursor to the left
    This is the way the world [   ]started out.
    - we insert more text, the gap is full, so we extend it's size
    This is the way the world as we know it [                   ]started out.
*/
#include <stdlib.h>

// Here is the structure of a Gap buffer :
typedef struct {
    char*   buffer;             // pointer to the buffer
    int     buffer_capacity;    // max capacity of the buffer
    int     buffer_size;        // used buffer space
    int     gap_left;           // index of the gap
    int     gap_size;           // remaining gap space
    int     growth_size;        // will be used for the function grow()
} GapBuffer;

// and those are the necessary functions to manipulate a gap buffer, each one will be described with a commented code :
typedef int bool;
#define TRUE    1
#define FALSE   0

GapBuffer*  gbuf_init(int maxbuf, int gap_size, int growth_size);
void        gbuf_insert(GapBuffer* gbuf, char* string);
bool        gbuf_insert_char(GapBuffer* gbuf, char character);
void        gbuf_print(GapBuffer* gbuf);
void        gbuf_right(GapBuffer* gbuf);
void        gbuf_left(GapBuffer* gbuf);
int         gbuf_last_index(GapBuffer* gbuf);

// Main function to create a new gap buffer, it initializes all the fields of the structure
// and fills the gap with the character '_', in practice you can change this value with NULL or
// with an empty character :
GapBuffer* gbuf_init(int maxbuf, int gap_size, int growth_size){
    // in case inputs are wrong
    if(gap_size > maxbuf || growth_size > maxbuf) {
        printf("Invalid argument! \n");
        return NULL;
    }
    GapBuffer* gbuf = malloc(sizeof(GapBuffer));
    gbuf->buffer    = malloc(sizeof(char) * (maxbuf + 1));      // extra cell for the \0
    gbuf->gap_left          = 0;                                // gap initial index is 0
    gbuf->gap_size          = gap_size;                         // gap initial size
    gbuf->buffer_capacity   = maxbuf;                           // max buffer capacity
    gbuf->buffer_size       = 0;                                // used buffer size
    gbuf->growth_size       = growth_size;                      // growth size
    // i initialize the gap to _ as i can track it
    // but in practice it has to be an empty string
    int index;
    for(index = gbuf->gap_left; index < gbuf->gap_size; index++)
        gbuf->buffer[index] = '_';
    gbuf->buffer[gbuf->gap_size] =  '\0';                       // end of string character

    return gbuf;
}

// Those two functions are almost the same, one is used to move the cursor to the right and
// the other, to the left. When one of these functions is called, a character is shifted from the left
// to the right (or the opposite) therefore complexity is O(1).
// Shifting the cursor by N cells will resutl in a complexity of O(n).
void gbuf_left(GapBuffer* gbuf){
    if(gbuf->gap_left == 0) return;             // already at start of buffer
    // we shift the character from left part to right
    gbuf->buffer[gbuf->gap_left + gbuf->gap_size - 1] = gbuf->buffer[gbuf->gap_left - 1];
    gbuf->gap_left -= 1;                        // update gap_left
    gbuf->buffer[gbuf->gap_left] = '_';
}

void gbuf_right(GapBuffer* gbuf){
    // if last cell is \\0 or buffer is full
    if(gbuf_last_index(gbuf) == gbuf->buffer_capacity - 1)  return;
    if(gbuf->buffer[gbuf_last_index(gbuf) + 1] == '\\0') return;
    // otherwise, we shift the character from right part to left
    int leftPartIndex = gbuf_last_index(gbuf) + 1;
    gbuf->buffer[gbuf->gap_left] = gbuf->buffer[leftPartIndex];
    gbuf->buffer[leftPartIndex] = '_';
    gbuf->gap_left += 1;        // update gap_left
}



