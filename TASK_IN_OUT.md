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




