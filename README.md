# 42_push_swap

## Description
This project consists of solving a "Tower of Hanoï like" puzzle with sequential access sorting algorithms. We must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

### Instruction set
| Instruction   | Description |
| ------------ | ------------ |
| `pa` | Push A: Take the first element at the top of B and put it at the top of A |
| `pb` | Push B: Take the first element at the top of A and put it at the top of B |
| `sa` | Swap A: Swap the first 2 elements at the top of stack A |
| `sb` | Swap B: Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `ra` | Rotate A: Shift all elements of stack A up by 1. The first element becomes the last one |
| `rb` | Rotate B: Shift all elements of stack B up by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate A: Shift all elements of stack A down by 1. The last element becomes the first one. |
| `rrb` | Reverse rotate B: Shift all elements of stack b down by 1. The last element becomes the first one. |
| `rrr` | `rra` and `rrb` at the same time. |

### Grade
The grade depends on how efficient the sorting algorithm is.

- Sorting 3 values: no more than 3 actions.
- Sorting 5 values: no more than 12 actions.
- Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  - 5 points for less than 700 actions
  - 4 points for less than 900
  - 3 points for less than 1100
  - 2 points for less than 1300
  - 1 point for less than 1500
- Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  - 5 points for less than 5500 actions
  - 4 points for less than 7000
  - 3 points for less than 8500
  - 2 points for less than 10000
  - 1 point for less than 11500

## Prerequisites
- Nothing needed

## Usage
- `make` for compilation
- `./push_swap <numbers>` for execution
- Example: `./push_swap 100 0 781 101 1 87 487`

## Lessons
- Sorting algorithms

## Resources
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a "Push_Swap: The least amount of moves with two stacks")
- [Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e "Push_Swap Tutorial")
- [Random Number Generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php "Random Number Generator")

