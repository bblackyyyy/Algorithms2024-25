 Tasks Instructions, Input, and Output

## Task 1: Maximum Length of Fence Span

# Problem Statement

## Input:

The input consists of an integer `t`, indicating the number of test cases. Each test case consists of the following:

- Three natural numbers `n`, `d`, and `m`, representing the number of workers, the number of queries for days, and the required number of tons of ore.
- `n` lines follow, each containing two integers `C` (efficiency of a worker) and `K` (efficiency reduction rate over consecutive days).
- The last line of the test case contains `d` positive integers, representing the number of days for which queries are made.

### Constraints:

- \( 1 \leq t \leq 10 \)
- \( 1 \leq n \leq 1,000 \)
- \( 1 \leq d \leq 1,000,000 \)
- \( 1 \leq m \leq 10,000,000 \)
- \( 1 \leq K \leq C \leq 10,000 \)

---

## Output:

For each test case:

- Print `d` numbers representing the total tons of ore moved for each queried day `di`.
- On a new line, print the number of queries for which the required `m` tons of ore were successfully moved.

---

## Example:

### Input:
```
2
2 3 100
20 10
30 5
5 1 100
1 2 15
5 2
1 3
```

### Output:
```
130 50 135 
2
5 9 
0
