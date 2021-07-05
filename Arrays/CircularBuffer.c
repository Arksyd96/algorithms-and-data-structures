/*
    Cricular buffer is a data structure that uses a fixed-size buffer, they are mostly used to manage data 
    streams and generally implement a FIFO behavior. Structure of a Circular buffer :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0
        
typedef int bool; 

typedef struct {
    int     *buffer;    // pointer to the buffer
    size_t  head;       
    size_t  tail;
    size_t  max;        // max size of the buffer
    bool    full;       // check whether buffer is full or not
} CircularBuffer;

// Here are the necessary functions to manipulate a circular buffer:
CircularBuffer* cbuf_init(uint8_t* buffer, size_t size);    // init our buffer
void cbuf_insert(CircularBuffer* cbuf, int data);           // insert a new element
bool cbuf_full(CircularBuffer* cbuf);                       // returns true if full
bool cbuf_empty(CircularBuffer* cbuf);                      // returns true if empty
int cbuf_pull(CircularBuffer* cbuf);                        // pull an element
size_t cbuf_size(CircularBuffer* cbuf);                     // get size
void cbuf_print(CircularBuffer* cbuf);                      // contents of the buffer

// Initialize
// Returns a pointer of type CircularBuffer. We initialize all the fields of the structure :
CircularBuffer* cbuf_init(uint8_t* buffer, size_t size){
    CircularBuffer* cbuf = malloc(sizeof(CircularBuffer));
    cbuf->max = size;
    cbuf->buffer = buffer;
    cbuf->head = cbuf->tail = 0;
    cbuf->full = FALSE;
    return cbuf;
}

// State checks
// Simply returns the flag full :
bool cbuf_full(CircularBuffer* cbuf){
    return cbuf->full;
}

// If flag full is false and head == tail then the buffer is empty :
bool cbuf_empty(CircularBuffer* cbuf){
    return (!cbuf->full && cbuf->head == cbuf->tail);
}

// This function returns the currect size of the buffer :
size_t cbuf_size(CircularBuffer* cbuf){
    if (cbuf_empty(cbuf)) return 0;
    else {
        if (cbuf_full(cbuf)) return cbuf->max;
        else {
            return (cbuf->head - cbuf->tail);
        }
    }
}

// Inserting is always made at the head pointer, then we increment it and update the flag full 
// (Module is importent to always keep the index <= capacity) :
void cbuf_insert(CircularBuffer* cbuf, int data){
    if (cbuf_full(cbuf)){
        printf("Buffer full \n");
        return;
    }
    cbuf->buffer[cbuf->head] = data;
    cbuf->head = (cbuf->head + 1) % cbuf->max;
    if (cbuf->head == cbuf->tail){
        cbuf->full = TRUE;
    }
}

// In the same way, to remove data from the buffer, we access the value at the tail and then increment the tail pointer :
int cbuf_pull(CircularBuffer* cbuf){
    if(cbuf_empty(cbuf)){
        printf("Buffer empty \n");
        return;
    }
    int data = cbuf->buffer[cbuf->tail];
    cbuf->tail = (cbuf->tail + 1) % cbuf->max;
    return data;
}

// This function displays the content of the buffer :
void cbuf_print(CircularBuffer* cbuf){
    int i, size;
    if (!cbuf_empty(cbuf)){
        size = cbuf_full(cbuf) ? cbuf->max : cbuf->head;
        for (i = cbuf->tail; i < size; i++){
            printf("%d ", cbuf->buffer[i]);
        }
        printf("\n");
    }
}

// How to use :
int main(int argc, char** argv){
    size_t SIZE = 10;
    uint8_t* buffer = malloc(SIZE * sizeof(int));    // Creates a buffer of size 10
    CircularBuffer* cbuf = cbuf_init(buffer, SIZE);

    cbuf_insert(cbuf, 10);
    cbuf_insert(cbuf, 7);
    cbuf_insert(cbuf, 6);
    cbuf_insert(cbuf, 41);
    printf("Content : ");
    cbuf_print(cbuf);

    printf("Removed value : %d \n", cbuf_pull(cbuf));
    printf("Content : ");
    cbuf_print(cbuf);

    return EXIT_SUCCESS;
}


