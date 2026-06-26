# D. Rudolf and the Another Competition

## 🔗 Problem Summary

Rudolf is participating in an **ICPC-style programming contest**.

Each participant:

* Earns **1 point** for every solved problem.
* Receives a penalty equal to the time elapsed when each solved problem is completed.

The final ranking is determined by:

1. **More solved problems** rank higher.
2. If solved problems are equal, **lower total penalty** ranks higher.
3. If both values are identical, Rudolf (participant **1**) gets the better rank.

Every participant can choose the order in which they solve problems.

Your task is to determine Rudolf's final rank assuming **every participant follows the optimal solving order**.

---

## 💡 Approach

To maximize the number of solved problems while minimizing the total penalty, every participant should solve the problems in **ascending order of required solving time**.

For each participant:

1. Sort the problem-solving times.
2. Solve problems one by one until the contest duration is exceeded.
3. Count the solved problems.
4. Accumulate the penalty using the elapsed contest time.

After computing Rudolf's score, compare it with every other participant.

A participant ranks ahead of Rudolf only if:

* They solve **more problems**, or
* They solve the **same number of problems** but have a **smaller penalty**.

Since Rudolf wins all complete ties, equal scores and equal penalties do not affect his rank.

---

## 🚀 Algorithm

1. Read the contest details.
2. For every participant:

   * Sort the solving times.
   * Simulate solving problems.
   * Compute:

     * Number of solved problems.
     * Total penalty.
3. Store Rudolf's result.
4. Compare every other participant with Rudolf.
5. Increase Rudolf's rank whenever another participant performs better.
6. Print Rudolf's final rank.

---

## 📌 Dry Run

### Input

```text
n = 3
m = 3
h = 120

Participant 1 : 20 15 110
Participant 2 : 90 90 100
Participant 3 : 40 40 40
```

---

### Participant 1 (Rudolf)

Sorted times:

```text
15 20 110
```

| Problem | Elapsed Time |  Penalty | Solved |
| ------: | -----------: | -------: | -----: |
|      15 |           15 |       15 |      1 |
|      20 |           35 |       50 |      2 |
|     110 |          145 | Exceeded |   Stop |

Result:

```text
Solved = 2
Penalty = 50
```

---

### Participant 2

Sorted times:

```text
90 90 100
```

| Problem | Elapsed Time |  Penalty | Solved |
| ------: | -----------: | -------: | -----: |
|      90 |           90 |       90 |      1 |
|      90 |          180 | Exceeded |   Stop |

Result:

```text
Solved = 1
Penalty = 90
```

Participant 2 does **not** rank ahead of Rudolf.

---

### Participant 3

Sorted times:

```text
40 40 40
```

| Problem | Elapsed Time | Penalty |
| ------: | -----------: | ------: |
|      40 |           40 |      40 |
|      40 |           80 |     120 |
|      40 |          120 |     240 |

Result:

```text
Solved = 3
Penalty = 240
```

Participant 3 solves more problems and ranks ahead of Rudolf.

---

### Final Ranking

| Participant | Solved | Penalty | Rank |
| ----------: | -----: | ------: | ---: |
|           3 |      3 |     240 |    1 |
|  1 (Rudolf) |      2 |      50 |    2 |
|           2 |      1 |      90 |    3 |

Output:

```text
2
```

---

## 🎯 Key Observation

To maximize the contest score:

* Solving **shorter problems first** allows more problems to be completed.
* It also minimizes the cumulative penalty because smaller completion times contribute less to the total penalty.

Therefore, sorting the solving times in ascending order always produces the optimal result.

---

## ⏱️ Complexity Analysis

Let:

* **n** = number of participants
* **m** = number of problems

For each participant:

* Sorting the solving times:

```text
O(m log m)
```

* Simulating the contest:

```text
O(m)
```

Overall complexity:

```text
O(n × m log m)
```

Since the total value of **n × m** over all test cases is at most **2 × 10⁵**, the solution easily satisfies the constraints.

---

### Space Complexity

Each participant stores only one array of problem-solving times.

```text
O(m)
```

---

## ✅ Correctness

* Sorting ensures every participant follows the optimal problem-solving order.
* The simulation accurately computes:

  * Number of solved problems.
  * Total accumulated penalty.
* Rudolf's result is compared against every other participant using the official ranking rules.
* Since Rudolf automatically wins complete ties, only participants with a strictly better performance increase his rank.

Therefore, the algorithm always computes Rudolf's correct final position.

---

## 📚 Concepts Used

* Greedy Algorithm
* Sorting
* Simulation
* ICPC Ranking Rules
* Prefix Time Accumulation
* Implementation
