#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

typedef enum {
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
}TrafficState; 

typedef struct 
{
    const uint16_t RED_DUR;
    const uint16_t YELLOW_DUR;
    const uint16_t GREEN_DUR;
    TrafficState state;
    uint16_t counter;
}StateMachine;

void delay_s(unsigned s) { sleep(s); }               

void update_state(StateMachine *machine, uint16_t input){
    machine->counter++;

    if(input){
        printf("--> pedestrian pressed crosswalk button \n");
        machine->state = STATE_RED;
        machine->counter = 0;
        return;
    }

    switch (machine->state){
    case STATE_RED:
        if(machine->counter >= machine->RED_DUR){
            machine->state = STATE_YELLOW;
            machine->counter = 0;
        }
        break;
    case STATE_YELLOW:
        if(machine->counter >= machine->YELLOW_DUR){
            machine->state = STATE_GREEN;
            machine->counter = 0;
        }
        break;
    case STATE_GREEN:
        if(machine->counter >= machine->GREEN_DUR){
            machine->state = STATE_RED;
            machine->counter = 0;
        }
        break;
    }
}


int main(void){
    StateMachine machine = {
        .RED_DUR=15, 
        .YELLOW_DUR=5, 
        .GREEN_DUR=10, 
        .state=STATE_RED, 
        .counter=0
    };

    TrafficState prev = machine.state;
    printf("--> state = %d \n", machine.state);
    for(int i = 0; i < 100; i++){
        delay_s(1);
        
        int pedestrian_pressed = ((i+1) % 48 == 0);
        update_state(&machine, pedestrian_pressed);

        if(machine.state != prev){
            printf("--> state = %d \n", machine.state);
            prev = machine.state;
        }
    }

    return 0;
}