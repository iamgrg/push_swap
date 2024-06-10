# Push_swap

## Overview

`Push_swap` is a project designed to challenge your skills in data sorting with a limited set of operations and two stacks. The goal is to sort data using the least number of moves possible, applying various types of algorithms to find the most optimized solution.

## Objectives

The main objectives of this project are:
- To implement a sorting algorithm using stack operations.
- To understand and optimize sorting algorithms' complexities.

## Build Instructions

Compile the project using the provided Makefile:
```bash
make all
```

## Usage
Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

## Rules

You have two stacks, a and b, and the following operations available:

- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss: Perform sa and sb simultaneously.
- pa (push a): Move the first element from stack b to stack a.
- pb (push b): Move the first element from stack a to stack b.
- ra (rotate a): Shift all elements of stack a up by one.
- rb (right rotate b): Shift all elements of stack b up by one.
- rr: Perform ra and rb simultaneously.
- rra (reverse rotate a): Shift all elements of stack a down by one.
- rrb (reverse rotate b): Shift all elements of stack b down by one.
- rrr: Perform rra and rrb simultaneously.

## Game Example
Starting with stack a: 2 1 3 6 5 8 and stack b empty, the goal is to sort stack a in ascending order with the smallest number of operations.

## The "push_swap" program

push_swap outputs the series of operations that sort the numbers in stack a, displaying them line by line:

```plaintext
sa
pb
pb
pb
sa
pa
pa
pa
```

## Benchmark

The sorting operations should be optimized to handle:
- 100 numbers within 700 operations.
- 500 numbers within 5500 operations for full marks.

## Contributors

- @iamgrg

## License

![MIT License](https://img.shields.io/badge/license-MIT-green)
Distributed under the MIT License.
