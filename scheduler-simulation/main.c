#include <stdio.h>
#include <stdint.h>

//function pointers 
// int add(int a, int b){
//     return a + b;
// }

// int middleFunction(int (*func)(int,int)){
//     int val = func(1, 2);
//     return val;
// }

typedef struct{
    const char *name;
    void (*fn)(void *ctx); //task will run this function
    void *ctx; //context, task data/state.
    uint32_t period_ms;
    uint64_t next_release_ms;
    int enabled;
}Task;

#define MAX_TASKS 8
typedef struct{
    Task tasks[MAX_TASKS];
    int count;
} Scheduler;

void add_task(Scheduler *sc, const char *name, void (*func)(void*), void *ctx, uint32_t period_ms){
    
}

int main(void){

    return 0;
}

