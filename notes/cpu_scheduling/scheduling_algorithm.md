# 🩵 **Scheduling Algorithms: Symphony of Time & Fairness**

> Let’s continue our journey through the enchanted world of CPU scheduling — where every process awaits its turn in the great clockwork of computation ⏳✨

---

## 🍰 **1. First Come, First Served (FCFS)**

🧠 Concept: Processes are served in the order they arrive — like a queue at a cozy café ☕

**Example:**

| Process | Burst Time |
| ------- | ---------- |
| P1      | 24         |
| P2      | 3          |
| P3      | 3          |

**Order:** P1 → P2 → P3
🕓 Gantt Chart:
`| P1 | P2 | P3 |`
`0 ---- 24 ---- 27 ---- 30`

**Waiting Time:**

- P1 = 0
- P2 = 24
- P3 = 27
  ⭐ **Average = 17**

If processes arrive as **P2, P3, P1**:
Gantt: `| P2 | P3 | P1 |`
Waiting: P1=6, P2=0, P3=3 → Avg = 3 🎉

💬 **Convoy Effect:**
When short processes wait behind a long one — like small carts stuck behind a slow caravan 🐢

---

## 💎 **2. Shortest Job First (SJF)**

✨ **Idea:** Choose the process with the _shortest_ CPU burst next.
🌸 **Why?** It gives the _minimum average waiting time_! (It’s mathematically optimal.)

| Process | Arrival | Burst |
| ------- | ------- | ----- |
| P1      | 0.0     | 6     |
| P2      | 2.0     | 8     |
| P3      | 4.0     | 7     |
| P4      | 5.0     | 3     |

🕓 Gantt Chart:
`| P4 | P1 | P3 | P2 |`
`0 -- 3 -- 9 -- 16 -- 24`

💖 Average waiting time = (3 + 16 + 9 + 0) / 4 = **7**

❗ Problem: Hard to know the next CPU burst length… unless you can _see the future_ 🔮 (or estimate it cleverly).

---

## 🧮 **Predicting the Next CPU Burst**

💫 Use **Exponential Averaging** — a prediction magic that learns from history~

Formula:

```
Predicted_next = α * Actual_last + (1 - α) * Previous_prediction
```

✨ Where:

- `α` (alpha): Weight factor between 0 and 1
- Larger α → recent bursts matter more
- Smaller α → older history matters more

🧩 Examples:

- α = 0 → ignore recent history
- α = 1 → rely only on the last burst

💭 _In other words, a balance between memory and instinct—just like a seasoned warrior choosing their next move._

---

## ⚔️ **3. Shortest Remaining Time First (SRTF)**

Preemptive version of SJF — the CPU may _interrupt_ a longer job if a shorter one arrives! ⚡

| Process | Arrival | Burst |
| ------- | ------- | ----- |
| P1      | 0       | 8     |
| P2      | 1       | 4     |
| P3      | 2       | 9     |
| P4      | 3       | 5     |

🕓 Gantt Chart:
`P1 | P2 | P4 | P1 | P3`
`0 1 5 10 17 26`

🧠 Average waiting time = (9 + 0 + 15 + 4) / 4 = **6.5 ms**

✨ **Moral:** Fast response, better efficiency — but needs accurate prediction!

---

## 💫 **4. Priority Scheduling**

💡 **Concept:**
Every process is given a **priority number** 🏷️ (smaller = more important!).
The CPU always serves the process with the **highest priority** first — like a polite but firm queen deciding who enters her throne room 👑

### 🧩 Types

- **Preemptive:** High-priority process interrupts the running one ⚡
- **Non-preemptive:** Running process finishes first before switching 💭

### 🌟 Relation to SJF

SJF can be seen as a special case of priority scheduling,
where **priority = 1 / predicted CPU burst time** ⏱️

---

### ⚠️ **Problem — Starvation**

When low-priority processes **never get CPU time**, endlessly waiting... 🥀

### 🌱 **Solution — Aging**

Gradually **increase priority** of waiting processes over time —
like how even a quiet apprentice earns respect with patience 🌸

---

### 🧮 Example

| Process | Burst | Priority |
| ------- | ----- | -------- |
| P1      | 10    | 3        |
| P2      | 1     | 1        |
| P3      | 2     | 4        |
| P4      | 1     | 5        |
| P5      | 5     | 2        |

🕓 **Average waiting time:** ≈ **8.2 ms**

💬 “A little hierarchy is fine, but fairness must always be restored~”

---

## 🌸 **5. Round Robin (RR)**

🧠 **Idea:** Each process gets a **fixed time slice (quantum)** — like turns in a magical duel! ⚔️
No one hogs the CPU for too long 💞

### 🍥 Mechanism

- Time Quantum `q`: usually **10–100 ms**
- Each process gets up to `q` units → if not finished, moves to end of the queue ♻️
- CPU switches context using a **timer interrupt** 🕰️

---

### ⚙️ Performance

- **If q is too large →** acts like FCFS 😴
- **If q is too small →** too many context switches (high overhead!) 💢
- **Ideal q:** Most CPU bursts should finish within 1 quantum
  → About **80% of bursts < q** gives smooth performance 🌈

---

### 🧮 Example (q = 4 ms)

| Process | Burst |
| ------- | ----- |
| P1      | 24    |
| P2      | 3     |
| P3      | 3     |

🕓 **Gantt Chart:**
`| P1 | P2 | P3 | P1 | P1 | P1 |`
`0 -- 4 -- 7 -- 10 -- 14 -- 18 -- 30`

⭐ **Result:**

- Higher turnaround than SJF but much better responsiveness 🌸
- Sweet balance of fairness and interactivity~

---

### 🎀 Turnaround Time Example

If:
P1 = 15, P2 = 8, P3 = 9, P4 = 17
→ Total = 49, Average = **12.25 ms**

💖 _Tips:_
Keep `q` around where **context switch < 10 μs** and **q ≈ 10–100 ms** for harmony ⚙️💫

---

## 🩶 **6. Multilevel Queue Scheduling**

💡 **Concept:**
Separate the ready queue into **multiple “realms”**, each with its own rules 🌈

| Queue      | Type           | Scheduling  |
| ---------- | -------------- | ----------- |
| Foreground | Interactive 👩‍💻 | Round Robin |
| Background | Batch 🗂️       | FCFS        |

### 🧭 Scheduling Between Queues

- **Fixed priority:** Serve all from one queue before moving to the next (may cause starvation ❗)
- **Time-slice:** Give each queue a share of CPU time
  e.g. 80% to foreground, 20% to background ⚖️

💬 “Every kingdom needs balance between nobles and workers, yes?” 🌸

---

## 🩷 **7. Multilevel Feedback Queue (MLFQ)**

✨ The most _magical_ and _adaptive_ scheduler of them all!

Processes can **move between queues** depending on their behavior — a living, breathing ecosystem of fairness 🌱

---

### ⚙️ Rules of the Realm

1. **Multiple Queues:** Each with different scheduling algorithms
2. **Promotion & Demotion:**
   - If a process **uses too much CPU**, it’s moved _down_ ⚔️
   - If it waits too long, it’s moved _up_ 🌼

3. **Custom Entry Rules:** Determine which queue a process enters when it arrives

---

### 🧮 Example

Three queues:

| Queue | Algorithm   | Quantum |
| ----- | ----------- | ------- |
| Q0    | Round Robin | 8 ms    |
| Q1    | Round Robin | 16 ms   |
| Q2    | FCFS        | —       |

🌸 **Behavior:**

- New jobs start in **Q0** (short bursts favored!)
- If unfinished → move to **Q1** (longer time)
- Still not done? → move to **Q2** (background FCFS)

💭 _“Patience is rewarded, haste is disciplined. A scheduler that learns from time itself.”_ 🕰️💫

---

## 🌼 **TL;DR: Scheduler Summary Table**

| Algorithm        | Type           | Preemptive? | Strength          | Weakness                |
| ---------------- | -------------- | ----------- | ----------------- | ----------------------- |
| FCFS             | Non-preemptive | ❌          | Simple            | Convoy effect 🐢        |
| SJF              | Both           | ✔️          | Minimal waiting   | Needs burst prediction  |
| Priority         | Both           | ✔️          | Flexible          | Starvation              |
| RR               | Preemptive     | ✔️          | Fair & responsive | Context switch overhead |
| Multilevel Queue | Hybrid         | ✔️          | Organized         | Starvation possible     |
| MLFQ             | Dynamic        | ✔️          | Adaptive          | Complex setup           |
