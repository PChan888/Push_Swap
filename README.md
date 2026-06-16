# Push_swap

## Description

Push_swap is a 42 school algorithm project that sorts a stack of integers using a limited set of operations, aiming to minimize the total number of moves. The program receives a list of integers as arguments, determines the most efficient sequence of stack operations to sort them in ascending order (smallest on top), and outputs that sequence to stdout.

This project is an exercise in **algorithm design**, **data structure manipulation** (doubly linked lists as stacks), and **computational complexity awareness** — choosing the right approach to stay within hard operation-count benchmarks.

## Sorting Algorithm

This implementation uses the **Turk algorithm**, a greedy cost-based sorting strategy:

1. **Small inputs (≤5)** are handled by dedicated hardcoded solvers (`sort_three`, `sort_five`) that use at most 12 operations.
2. **Large inputs (6+)** use a two-phase approach:
   - **Phase A (a → b):** Push elements from stack a to b, always choosing the element with the lowest insertion cost. Cost accounts for rotations needed on both stacks, with combined operations (`rr`/`rrr`) reducing the total.
   - **Phase B (b → a):** Push elements back from b to a using the same cost-minimization logic.
   - **Finalize:** Rotate a so the minimum value is on top.

**Why the Turk algorithm?** It reliably achieves under 700 operations for 100 numbers and under 5500 for 500 numbers, meeting the project benchmarks while being straightforward to implement and debug.

## Supported Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack a |
| `sb` | Swap the first 2 elements at the top of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of stack b onto stack a |
| `pb` | Push the top element of stack a onto stack b |
| `ra` | Rotate stack a upward (top element becomes last) |
| `rb` | Rotate stack b upward (top element becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last element becomes first) |
| `rrb` | Reverse rotate stack b (last element becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

## Compilation

```bash
make        # Compiles push_swap
make clean  # Removes object files
make fclean # Removes object files and executable
make re     # Full recompile
```

## Usage

```bash
# Basic usage
./push_swap 4 67 3 87 23

# With a quoted string
./push_swap "4 67 3 87 23"

# Mixed format
./push_swap "4 67" 3 "87 23"

# Pipe into the checker to verify
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Count operations
./push_swap 4 67 3 87 23 | wc -l
```

### Example

```
$ ./push_swap 5 2 8 1 3
pb
pb
ra
sa
pa
pa
rra
```

### Error Handling

```
$ ./push_swap 5 2 abc
Error

$ ./push_swap 5 2 5
Error

$ ./push_swap 99999999999
Error

$ ./push_swap
(no output, exit 0)
```

## References

<!-- REF: Oceano's push_swap video guide — https://www.youtube.com/watch?v=OaG81sDEpVk -->
<!-- REF: Medium article(s) — https://medium.com/@ayogun/push-swap-c1f5d2d41e97 -->
<!-- REF: Medium article(s) — https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a -->
<!-- REF: Medium article(s) — https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474 -->
<!-- REF: Medium article(s) — https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 -->
<!-- REF: Medium article(s) — https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0 -->
<!-- REF: Gitbook resource — https://42-cursus.gitbook.io/guide/2-rank-02/push_swap -->
<!-- REF: Github resource — https://github.com/alx-sch/push_swap -->

## AI Assistance

This project was developed with AI tools as a learning aid:

- **Gemini** — Used early in the project for scoping and planning the overall
  structure. Helped flesh out the parsing pipeline (input validation, overflow
  detection, duplicate checking). I tested, debugged, and verified all parsing
  code myself.
- **Claude** — Used for understanding the Turk algorithm logic, walking through
  functions step by step, and building a study guide to solidify my knowledge
  of the codebase.
  
All sorting logic, operation implementations, and final debugging were done
through my own understanding and testing.