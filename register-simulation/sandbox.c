#include <stdio.h>

void half_adder(int a, int b, int *sum, int *carry){
    *sum = a ^ b; //XOR
    *carry = a & b; //AND
}

void full_adder(int a, int b, int c, int *sum, int *carry){
    int s1, c1, c2;
    half_adder(a, b, &s1, &c1);
    half_adder(s1, c, sum, &c2);
    *carry = c1 | c2; //OR
}


int main(void) {
    int sum, carry;

    int a = 6;  //0000 0110
    int b = 24; //0001 1000
    int c = 3;  //0000 0011

    full_adder(a, b, c, &sum, &carry);


    printf("sum = %d\n", sum);
    printf("carry = %d\n", carry);

    return 0;
}