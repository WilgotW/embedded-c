#include <stdio.h>
#include <stdint.h>

#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUPUT 1

typedef struct
{
    uint32_t ODR; //Output data register. Write bits to control pins (LEDs, motors, etc)
    uint32_t IDR; //Input data register. Reads external signals (buttons, sensors, etc.)
    uint32_t MODER; //Mode register. every pin is multi purpose (digital I/O, analog input, etc). This register tells what pin is output and input. 
} GPIO_t;


void gpio_mode(GPIO_t *gpio, int pos, int mode){
    if(mode == GPIO_MODE_INPUT){
        gpio->MODER |= (1u << pos);
    }else if (mode == GPIO_MODE_OUPUT){
        gpio->MODER &= ~(1u << pos);
    }
}

//simulate input
void inject_input(GPIO_t *gpio, int pos, int value){
    if (value){
        gpio->IDR |= (1u << pos);
    }else {
        gpio->IDR &= (1u << pos);
    }
}

void set_bit(GPIO_t *gpio, int pos){
    if(gpio->MODER & (1u << pos)){
        gpio->ODR |= (1u << pos);
    }
}

void toggle_bit(GPIO_t *gpio, int pos){
    if (gpio->MODER & (1u << pos)){
        gpio->ODR ^= (1u << pos); //^ = XOR
    }
}

void clear_bit(GPIO_t *gpio, int pos){
    if (gpio->MODER & (1u << pos)){
        gpio->ODR &= ~(1u << pos); //sets all bits to one except the bit at pos. 
    }
}

int read_bit(uint32_t reg, int pos){
    if(reg & (1u << pos)){
        return 1;
    }else{
        return 0;
    }
}

int main(void) {
    GPIO_t gpio = {0, 0, 0, 0};    

    return 0;
}