# Embedded C

This repository contains some projects related to embedded C programming.

## Project descriptions

#### Register simulation

This project simulates a GPIO that is commonly found in all microcontrollers. GPIO (General Purpose Input/Output) let's programmers define the properties for pins on a embedded system. The GPIO contains several registers, in this simplified project it contains: IDR (input data register), ODR (output data register) and the MODER register.
- The MODER registers tells the system what register to use. Data flows throug the register that the MODER specifies.
- The ODR registers contains the output for each pin IF the MODER is set to output
- The IDR registers contains the input for each pin IF the MODER is set to output

#### Ring Buffer

A ring buffer is an array that treats memory as if its wraps around in a cicle. The buffer has a header pointer (points to were the system reads) and a tail pointer (points to were new data is added). When you write new data to this array, it gets added to the tail position which then moves one step forward.. When reading data, the header pointer is were its written (also move tail forward one step). if tail or head reaches the end of the array, it wrapes around to index 0. This structure is very useful because it saves alot of computing power and time. The time to write or read is just O(1). Compare this to a classical array where removing a data point makes the whole array shift down one level witch takes alot more resources.

#### State machine

A simple simulation of a state machine. In this project, a state machine for a traffic light is siimulated. There are 3 different states the traffic light can be in: RED, YELLOW and GREEN. Each state has its own condition for when to switch to another state. This condition is only time. State machines a useful in embedded systems were multiple states are possible and were the systems conditions creates specific changes based on current state and current inputs.

#### Scheduler simulation

Work in progress
