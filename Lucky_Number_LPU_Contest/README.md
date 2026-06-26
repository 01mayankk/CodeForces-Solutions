# A. Lucky Numbers

## 🔗 Problem Summary

Given a range **[l, r]**, find a number whose **luckiness** is maximum.

The **luckiness** of a number is defined as:

> **Luckiness = Largest Digit − Smallest Digit**

If multiple numbers have the same maximum luckiness, any one of them can be printed.

---

## 💡 Approach

The maximum possible luckiness of any number is **9**, which occurs when a number contains both digits **0** and **9**.

Instead of checking every number in the entire range, we use an important observation:

* A number with maximum luckiness (9) appears very quickly if it exists.
* Therefore, it is sufficient to examine only the **first 101 numbers** of the range.
* For every candidate number:

  * Find its largest and smallest digit.
  * Compute its luckiness.
  * Keep track of the number with the highest luckiness.
* If a number with luckiness **9** is found, terminate immediately since no better answer is possible.

This optimization drastically reduces the number of iterations while always producing the correct answer.

---

## 🚀 Algorithm

1. Read the values of **l** and **r**.
2. Initialize:

   * `bestNumber = l`
   * `maximumLuckiness = -1`
3. Iterate from **l** to **min(r, l + 100)**.
4. For each number:

   * Find the maximum digit.
   * Find the minimum digit.
   * Compute luckiness.
5. If the current luckiness is greater than the previous best:

   * Update the answer.
6. If luckiness becomes **9**, stop searching.
7. Print the stored answer.

---

## 📌 Dry Run

### Input

```text
l = 59
r = 63
```

### Iteration

| Number | Largest Digit | Smallest Digit | Luckiness | Best So Far |
| -----: | :-----------: | :------------: | :-------: | :---------: |
|     59 |       9       |        5       |     4     |      59     |
|     60 |       6       |        0       |     6     |      60     |
|     61 |       6       |        1       |     5     |      60     |
|     62 |       6       |        2       |     4     |      60     |
|     63 |       6       |        3       |     3     |      60     |

### Output

```text
60
```

---

## 🎯 Key Observation

The highest possible luckiness is:

```text
9 - 0 = 9
```

Once we encounter a number with luckiness **9**, there is no need to continue searching because no number can have a higher luckiness.

This allows an early exit and keeps the solution extremely efficient.

---

## ⏱️ Complexity Analysis

Let **D** be the number of digits in a number.

* Each luckiness calculation takes **O(D)**.
* We check at most **101 numbers**.

### Time Complexity

```text
O(101 × D)
```

Since a number has at most **7 digits** (within the given constraints), this is effectively:

```text
O(1)
```

per test case.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## ✅ Correctness

* Every examined number has its luckiness computed correctly.
* The algorithm always keeps track of the maximum luckiness found so far.
* Since the search stops only after finding the maximum possible luckiness (9), no better answer can exist.
* If no such number exists, the best among the checked candidates is returned.

Hence, the algorithm always produces a valid answer.

---

## 📚 Concepts Used

* Number Manipulation
* Digit Extraction
* Greedy Observation
* Brute Force with Optimization
* Simulation
