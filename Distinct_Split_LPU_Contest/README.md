# B. Distinct Split

## 🔗 Problem Summary

Given a string **s**, split it into **two non-empty substrings**:

* **a** (prefix)
* **b** (suffix)

such that:

```text
a + b = s
```

Let **f(x)** denote the number of distinct characters in string **x**.

Your task is to find the maximum possible value of:

```text
f(a) + f(b)
```

over all valid split positions.

---

## 💡 Approach

Instead of recalculating the number of distinct characters for every possible split, we preprocess the string.

### Step 1: Prefix Distinct Count

Traverse the string from **left to right** while maintaining a set of visited characters.

For every index **i**, store:

```text
prefixDistinct[i]
```

which represents the number of distinct characters in the substring:

```text
s[0...i]
```

---

### Step 2: Suffix Distinct Count

Traverse the string from **right to left** while maintaining another set.

For every index **i**, store:

```text
suffixDistinct[i]
```

which represents the number of distinct characters in:

```text
s[i...n-1]
```

---

### Step 3: Evaluate Every Split

For every valid split position:

```text
Left  = s[0...i]
Right = s[i+1...n-1]
```

the answer becomes:

```text
prefixDistinct[i] + suffixDistinct[i + 1]
```

Take the maximum over all possible splits.

---

## 🚀 Algorithm

1. Read the string.
2. Build the prefix distinct count array.
3. Build the suffix distinct count array.
4. Iterate through every split position.
5. Compute:

```text
prefixDistinct[i] + suffixDistinct[i + 1]
```

6. Keep track of the maximum value.
7. Print the answer.

---

## 📌 Dry Run

### Input

```text
n = 7
s = "abcabcd"
```

### Prefix Distinct Array

| Index | Character | Distinct Characters | Count |
| ----: | :-------: | :-----------------: | ----: |
|     0 |     a     |         {a}         |     1 |
|     1 |     b     |        {a,b}        |     2 |
|     2 |     c     |       {a,b,c}       |     3 |
|     3 |     a     |       {a,b,c}       |     3 |
|     4 |     b     |       {a,b,c}       |     3 |
|     5 |     c     |       {a,b,c}       |     3 |
|     6 |     d     |      {a,b,c,d}      |     4 |

```text
Prefix = [1,2,3,3,3,3,4]
```

---

### Suffix Distinct Array

| Index |  Suffix | Count |
| ----: | :-----: | ----: |
|     6 |    d    |     1 |
|     5 |    cd   |     2 |
|     4 |   bcd   |     3 |
|     3 |   abcd  |     4 |
|     2 |  cabcd  |     4 |
|     1 |  bcabcd |     4 |
|     0 | abcabcd |     4 |

```text
Suffix = [4,4,4,4,3,2,1]
```

---

### Try Every Split

| Split Position | Left Distinct | Right Distinct | Total |
| -------------: | ------------: | -------------: | ----: |
|     a | bcabcd |             1 |              4 |     5 |
|     ab | cabcd |             2 |              4 |     6 |
|     abc | abcd |             3 |              4 | **7** |
|     abca | bcd |             3 |              3 |     6 |
|     abcab | cd |             3 |              2 |     5 |
|     abcabc | d |             3 |              1 |     4 |

Maximum value:

```text
7
```

---

## 🎯 Key Observation

The number of distinct characters in every prefix and suffix can be precomputed once.

This allows each split to be evaluated in **O(1)** time, avoiding repeated traversal of the string.

---

## ⏱️ Complexity Analysis

Let **n** be the length of the string.

### Time Complexity

* Building prefix array → **O(n)**
* Building suffix array → **O(n)**
* Checking all split positions → **O(n)**

Overall:

```text
O(n)
```

---

### Space Complexity

Two arrays of size **n** and two hash sets are used.

```text
O(n)
```

---

## ✅ Correctness

* `prefixDistinct[i]` correctly stores the number of distinct characters from the beginning of the string up to index `i`.
* `suffixDistinct[i]` correctly stores the number of distinct characters from index `i` to the end of the string.
* Every possible split is evaluated exactly once.
* The algorithm keeps the maximum value among all valid splits.

Therefore, the algorithm always returns the maximum possible value of:

```text
f(a) + f(b)
```

---

## 📚 Concepts Used

* Strings
* Prefix Computation
* Suffix Computation
* Hash Set (`unordered_set`)
* Simulation
* Greedy Observation
