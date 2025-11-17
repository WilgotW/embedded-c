#include <stdio.h>
#include <stdint.h>

#define BUFFER_CAP 16

typedef struct
{
    uint16_t data[16];
    uint16_t head;
    uint16_t tail;
    
} BUFFER;

int is_full(BUFFER *buffer){
    if((buffer->head + 1) % BUFFER_CAP == buffer->tail){
        return 1;
    }
    return 0;
}

int is_empty(BUFFER *buffer){
    if(buffer->head == buffer->tail){
        return 1;
    }
    return 0;
}

void enqueue(BUFFER *buffer, uint16_t data){
    if(is_full(buffer)){
        buffer->tail = (buffer->tail + 1) % BUFFER_CAP;
    }
    buffer->data[buffer->head] = data;
    buffer->head = (buffer->head + 1) % BUFFER_CAP;
}

uint16_t dequeue(BUFFER *buffer){
    if(!is_empty(buffer)){
        uint16_t data = buffer->data[buffer->tail];
        buffer->tail = (buffer->tail + 1) % BUFFER_CAP;
        return data;
    }
    return 0;
}

void debug_buffer(const BUFFER *buffer) {
    printf("Buffer state:\n");
    printf("  head = %u, tail = %u\n", buffer->head, buffer->tail);
    printf("  data = [");

    for (int i = 0; i < BUFFER_CAP; i++) {
        if (i == buffer->head && i == buffer->tail) {
            printf("(%u:H/T)", buffer->data[i]); 
        } else if (i == buffer->head) {
            printf("(%u:H)", buffer->data[i]);
        } else if (i == buffer->tail) {
            printf("(%u:T)", buffer->data[i]);
        } else {
            printf("%u", buffer->data[i]);
        }

        if (i < BUFFER_CAP - 1) {
            printf(", ");
        }
    }

    printf("]\n\n");
}

int main(void) {
    BUFFER buffer = {0};

    for (int i = 0; i < 20; i++) {
        enqueue(&buffer, i);
        debug_buffer(&buffer);
    }

    while (!is_empty(&buffer)) {
        uint16_t val = dequeue(&buffer);
        printf("Dequeued: %u\n", val);
        debug_buffer(&buffer); 
    }

    return 0;
}
