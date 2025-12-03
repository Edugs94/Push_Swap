# ⚙️ Push Swap Project Summary

Here is a summary of the workflow for my **Push Swap** project, designed for the **42 school** curriculum. This project focuses on sorting an unsorted list of random integers using highly restricted operations between two stacks.

---

## 📚 Objective & Constraints

The main goal is to sort a list of random numbers from **minimum to maximum values** using only two data structures, **Stack A** and **Stack B**, and a limited set of allowed movements.

The **allowed movements** are:

* **Swap:** `sa`, `sb`, `ss`
* **Push:** `pa`, `pb`
* **Rotate:** `ra`, `rb`, `rr`
* **Reverse Rotate:** `rra`, `rrb`, `rrr`
![Workflow](assets/push_swap_visualizer.gif)

><i> Note: If you are performing this project and I suggest you to use this [Push_Swap visualizer Tool](https://codepen.io/ahkoh/full/bGWxmVz) created by another student and this [Random Number Generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php) </i>
---

## 🧠 Algorithm & Efficiency

#### Chosen Algorithm: **Turk Sort**

The sorting strategy implemented is the **Turk Algorithm**. 
The detailed steps followed for this implementation are based on the guidance provided in the article below:

> [Article Reference: Push Swap: Turk Algorithm Explained in 6 Steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

#### Performance 📈

Most of the time, this **Turk algorithm** completes the task for **500 random numbers** using **under 5500 moves**, demonstrating strong performance relative to the project requirements.

To verify the efficiency of the algorithm, you can run the following line in your terminal. It generates random sets of **500 numbers** (between -1000 and 1000), runs `push_swap` **50 times**, and calculates the **average** number of moves.

<pre><code>N=50; S=0; for i in $(seq 1 $N); do ARG=$(seq -1000 1000 | shuf -n 500 | tr '\n' ' '); L=$(./push_swap $ARG | wc -l); echo "Test $i: $L"; S=$((S+L)); done; echo "Average: $((S/N))"</code></pre>

---

## 🎨 Workflow Chart

Find below the visual workflow chart I made for my project's logic. Hope it helps!

![Workflow](assets/workflow_push_swap_1.png)
