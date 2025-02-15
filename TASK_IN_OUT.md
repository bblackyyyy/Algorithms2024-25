 Tasks Instructions, Input, and Output

# Task 1 (general)

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
```

# Task 2 (sorting)
## Input:

The first line of input contains a natural number `t`, which represents the number of test cases. Each test case begins with a natural number `n`, indicating the number of artifacts in the given dataset. The following `n` lines contain descriptions of the artifacts. Each description consists of:

- **Artifact Identifier**: A single-word string.
- **Mass (`m`)**: A natural number in kilograms representing the weight of the artifact.

### Constraints:

- \( 1 \leq t \leq 10 \)
- \( 1 \leq n \leq 50,000 \)
- \( 1 \leq m \leq 100,000 \)

---

## Output:

For each test case, the output should include two lines:

1. Line 1: The minimum total energy required to place all artifacts into the Paradox Vault.
2. Line 2: A space-separated list of artifact identifiers in the order they should be placed into the vault to minimize energy usage.

---

## Note:

You **cannot use STL libraries** for this task. A self-written sorting algorithm must be implemented.

---

## Example:

### Input:
```
2
5
rower_elektryczny-1453 12
smartfon-1890 1
dron_z_kamera-2000pne 4
przenosna_lodowka-753 8
teleporter_do_kawy-2024 4
3
skaner_mysli-1984 7
teletransporter-3210pne 133
noktowizor-1410 1
```

### Output:
```
61
smartfon-1890 dron_z_kamera-2000pne teleporter_do_kawy-2024 przenosna_lodowka-753 rower_elektryczny-1453
150
noktowizor-1410 skaner_mysli-1984 teletransporter-3210pne
```

# Task 3 (queue)

## Input:

The input starts with four natural numbers in the first line:

- `t` — the duration of the store's operation for the simulation (in seconds),
- `l` — the number of registers (cashiers) in the store,
- `s` — efficiency of the registers, meaning the number of seconds needed to scan a product by a cashier,
- `z` — the time (in seconds) required by a customer to make a payment.

The following lines describe events, of which there are three types:

- `o` — opening a register,
- `z` — closing a register,
- `k` — a new customer entering the queue.

Each line starts with a single-character flag:

- `f` — the type of event:
  - If `f == 'k'`, it is followed by:
    - `p` — the relative time in seconds from the start of the simulation for the first customer, or the time since the previous customer for subsequent ones (guaranteed that the sum of all relative times `p` will be greater than or equal to `t`),
    - `r` — the number of products in the customer's basket.
  - If `f == 'o'` or `f == 'z'`, it is followed by:
    - `a` — the register number.

---

### Constraints:

- \( 1 \leq t \leq 30,000 \)
- \( 1 \leq l \leq 30 \)
- \( 1 \leq s \leq 60 \)
- \( 1 \leq z \leq 360 \)
- \( 0 \leq p \leq 10,000 \)
- \( f \in (\text{'o'}, \text{'z'}, \text{'k'}) \)
- \( 0 \leq a \leq l-1 \)
- \( 1 \leq r \leq 100 \)

---

## Output:

The output should show the state of each register after the time `t` has passed. The state should be in the following format:

- For an open register:
  - `K[n]: [queue_length]o, [queue_time_in_seconds]s`
- For a closed register:
  - `K[n]: z`

Registers should be listed on one line, separated by commas.

---

## Example:

### Input:
```
30 5 5 5
o 2
o 1
k 0 8
k 1 7
k 1 10
k 0 5
k 0 4
o 4
k 10 8
k 0 5
k 10 6
z 1
k 7 7
k 0 5
k 8 4
```

### Output:
```
K0: z, K1: z, K2: 4o 136s, K3: z, K4: 5o 147s
```

# Task 4 (BST)

## Input:

The input begins with a natural number `n` — the number of time-travel events. The following `n` lines are composed of three natural numbers:

- `y` — the year to which the crew arrived,
- `f` — the observed frequency in Hz,
- `l` — the measured wavelength in cm.

### Constraints:

- \( 1 \leq n \leq 300,000 \)
- \( 1 \leq y \leq 10,000 \)
- \( 1 \leq f \leq 100,000 \)
- \( 1 \leq l \leq 5,000 \)

---

## Output:

The output should contain a line for each **unique year** where valid measurements were made. These lines should be sorted in ascending order of years. For each year, output the frequencies and wavelengths in the format:

```
[year]: (f1,l1), (f2,l2), (f3,l3)...
```

- The pairs \((f_i, l_i)\) should be sorted by **increasing frequency**. If two pairs have the same frequency, sort them by **wavelength** (ascending).
- Exclude invalid measurements. Measurements are considered invalid if:
  - The observed frequency `f` could not realistically be heard by Janusz, or
  - The wavelength `l` does not correspond to a realistic frequency considering environmental factors (e.g., temperature, equipment limitations).

At the end of the output, include an additional line indicating whether the engine is fine-tuned. The result should be either `TAK` (YES) or `NIE` (NO), depending on whether at least one valid measurement was recorded.

---

## Example:

### Input:
```
16
5029 10 2789
7819 45043 23
1993 30 1080
2789 29 1090
2222 302 107
834 299 108
67 34 100
123 390 12888
728 300 108
1073 302 107
2222 302 107
834 109 300
1993 300 108
234 3000 11
2222 150 214
834 299 109
```

### Output:
```
234: (3000,11)
728: (300,108)
834: (109,300) (299,108) (299,109)
1073: (302,107)
1993: (30,1080) (300,108)
2222: (150,214) (302,107) (302,107)
2789: (29,1090)
NIE
```
# Task 5 (graph/bfs/dfs)
## Input:

The input starts with a natural number `t`, representing the number of test cases. For each test case:

1. Three natural numbers `n`, `m`, and `s`, representing the number of points, the number of connections between them, and the starting point for repairing the timeline.
2. The next `m` lines contain pairs of natural numbers `x` and `y`, which indicate that a decision at point `x` leads to point `y`.

Assume:
- No duplicate connections will appear.
- No loops will exist (i.e., connections that start and end at the same point).
- Points are numbered from 0.

### Constraints:

- \( 1 \leq t \leq 10 \)
- \( 1 \leq n \leq 100,000 \)
- \( 0 \leq m \leq 2n \)
- \( 0 \leq x, y < n \)

---

## Output:

For each test case, the program should output:

- `NIE` if stabilization is not possible.
- `PETLA` if stabilization cannot occur, but a loop exists.
- `TAK` if stabilization is possible. In this case, also output the sequence of points that need to be visited to achieve stabilization. Provide the shortest solution. If there are multiple solutions of the same length, choose the lexicographically smallest one.

---

## Example:

### Input:
```
3
6 7 3
0 1
1 5
2 0
2 1
3 2
3 4
4 0
4 3 0
0 1
1 2
2 3
2 2 0
0 1
1 0
```

### Output:
```
TAK
3 2 0 1 5
NIE
PETLA
```
# Task 6 (d&c)
---
# Task 7 (dynamic programming)
## Input:

The input begins with a natural number `n` — the size of the city (a square grid of size \(n \times n\)).

The next `n` lines each contain `n` values (0 or 1):
- `0` indicates the absence of an artifact in the sector.
- `1` indicates the presence of an artifact in the sector.

### Constraints:

- \( 1 \leq n \leq 500 \)

---

## Output:

The output should be the maximum number of artifacts that can be collected while exploring the city according to the described rules.

### Note:

The task must be solved using **dynamic programming**.

---

## Example:

### Input:
```
4
1 0 1 0
1 1 0 0
0 0 0 1
1 0 0 1
```

### Output:
```
6
```
# Task 8 (backtracking)
## Input:

The input starts with a positive integer `n` (\(1 \leq n \leq 35\)), representing the number of paths and beds in the garden.

The next `n` lines each contain `n` natural numbers, where the value at position `(i, j)` represents the cost of planting spices in bed `i` along path `j`.

### Constraints:

- Costs for each bed do not exceed 1000.

---

## Output:

The program must output `n` numbers, where each number represents the **path number** assigned to the corresponding bed, such that the total planting cost is minimized. Paths and beds are numbered starting from `0`.

### Note:

The task must be solved using **backtracking**. Standard Template Libraries (STL) cannot be used.

---

## Example:

### Input:
```
4
5 3 2 2
1 2 3 3
2 1 8 7
3 5 3 2
```

### Output:
```
1 2 0 3
```
# Task 9 (sorting in linear time)
## Input:

The input begins with a natural number `n` (\(2 \leq n \leq 2,000,000\)), representing the number of fence posts.

The next line contains `n` real numbers \(-10^9 \leq p_i \leq 10^9\), which are the positions of the fence posts in random order.

---

## Output:

The output should be a single real number — the length of the longest span between adjacent fence posts, rounded to 4 decimal places.

---

## Example:

### Input:
```
8
7.6 -2.0 12.0 0.3 9.3 2.0 4.5 5.1
```

### Output:
```
2.7000
```

---

## Note:

The solution must be based on a **linear time sorting algorithm**. Standard Template Libraries (STL) cannot be used.

# Task 10 (binary heap)

## Input:

The input begins with a natural number `n` (\(1 \leq n \leq 30,000\)), representing the number of entrepreneurs who need assistance.

For each entrepreneur:

1. An integer `o` (\(1 \leq o \leq 100,000\)), representing the number of operations to be performed for the entrepreneur.
2. The next `o` lines describe the operations in one of two formats:
   - `a p t`: Add a product priced at `p` zł with a tax rate of `t%`.
   - `p x`: Change the price of the most expensive product by `x`. If the operation is not possible, do nothing.

### Constraints:

- \( 1 \leq p \leq 100,000 \)
- \( 1 \leq t \leq 100 \)
- \(-99,999 \leq x \leq 99,999 \)

---

## Output:

The output should consist of `n` lines, where each line contains the minimum tax calculated for each entrepreneur, expressed in grosz (1 zł = 100 grosz).

---

## Example:

### Input:
```
2
10
a 1000 20
a 1200 10
a 900  5
a 1500 30
p 100
a 3000 40
p -200
p -100
a 20 20
a 30 4
8
a 970 20
a 1800 10
a 1900  5
a 150 30
a 2000 40
p -200
a 50 10
a 9000 4
```

### Output:
```
70500
107400
```

# Task 11 (selection algo)

## Input:

The input begins with an integer `t` (\(1 \leq t \leq 10\)), representing the number of datasets.

For each dataset:

1. An integer `n` (\(1 \leq n \leq 1,000,000\)), representing the number of observed numerical values.
2. `n` natural numbers `a1, a2, ..., an` (\(1 \leq a_i \leq 1,000,000\)), representing the values of these numbers.
3. An integer `k` (\(0 \leq k < n\)), indicating the position of the desired value.

---

## Output:

For each dataset, output the `k`-th value (0-indexed) after sorting the numbers in ascending order. If there are fewer than `k` values, output `BRAK DANYCH` ("NO DATA").

---

## Example:

### Input:
```
2
5
12 15 9 10 6
2
4
8 14 7 18
2
```

### Output:
```
12
BRAK DANYCH
```






