# 📗✨ Allocation of Frames

### _— How Memory Is Shared Fairly (and Wisely) —_

---

## 🌱 The Core Truth (Start Here!)

Every process needs a **minimum number of frames** to run correctly.
Too few frames ❌ → instructions **cannot even execute**.

---

## 🧩 Why a Minimum Is Necessary

### 📌 Classic Example — IBM 370

To execute the **SS MOVE instruction**, at least **6 frames** are required:

🟢 Instruction itself

- 6 bytes long
- May span **2 pages**

🟢 Data involved

- **2 pages** for source (“from”)
- **2 pages** for destination (“to”)

⭐ **Total minimum: 6 pages**

> _Without them… the CPU simply cannot proceed._
> _Even magic needs enough mana~_ ✨

---

## 🧮 Frame Allocation Basics

🔹 **Minimum frames** → required to execute
🔹 **Maximum frames** → total frames in the system
🔹 OS decides how to distribute frames among processes

---

## 🌸 Two Major Allocation Schemes

### 1️⃣ Fixed Allocation

### 2️⃣ Priority Allocation

Each has its own personality~ 💖

---

## 🧱 Fixed Allocation

_“You get your share, no more, no less.”_

---

### 🌼 Equal Allocation ⚖️

All processes receive the **same number of frames**.

📌 Example:

- Total frames (after OS): **100**
- Number of processes: **5**

➡️ Each process gets **20 frames**

✔️ Simple
✔️ Predictable
❗ Not always fair if processes differ in size

🟢 Usually keep some frames as a **Free Frame Buffer Pool**

---

### 🌷 Proportional Allocation 📏

Frames are assigned based on **process size**.

🧠 Idea:

- Bigger process → more frames
- Smaller process → fewer frames

✨ Allocation adjusts dynamically when:

- Process sizes change
- Degree of multiprogramming changes

> _Like tailoring clothes instead of giving everyone the same robe~_

---

### 🍃 TL;DR — Fixed Allocation

✔️ Easy to manage
✔️ Predictable behavior
❗ May waste memory or starve large processes

---

## 👑 Priority Allocation

_“Important guests get better seats.”_

---

### 🌟 How It Works

- Allocation is **proportional to priority**, not size
- Higher priority → more frames

---

### 🚨 Page Fault Handling

When process **Pi** causes a page fault:

🔹 Option 1: Replace **one of its own frames**
🔹 Option 2: Steal a frame from a **lower-priority process**

✔️ Ensures critical tasks keep running smoothly
❗ Lower-priority processes may suffer more faults

---

### 🍓 TL;DR — Priority Allocation

✔️ Protects important processes
✔️ Flexible and powerful
❗ Can be unfair to low-priority tasks

---

## 🌍 Global vs. Local Allocation

_Who is allowed to lose a frame?_ 🤔

---

### 🌐 Global Replacement️ Replacement

Any process may take a frame from **any other process**.

✔️ Higher throughput (system runs faster overall)
❗ Individual process time can vary wildly

⭐ Most common in real systems

---

### 🏡 Local Replacement

Each process replaces frames **only from its own allocation**.

✔️ Stable, predictable performance
❗ Memory may be underutilized

---

### 🧁 TL;DR — Global vs Local

| Style  | Advantage           | Disadvantage           |
| ------ | ------------------- | ---------------------- |
| Global | High throughput     | Unstable process time  |
| Local  | Consistent behavior | Possible wasted memory |

---

## 🧬 Non-Uniform Memory Access (NUMA)

_Not all memory is equally close… or fast._ ⚡

---

### 🌌 The Reality

In many modern systems:

- CPUs and memory are spread across **system boards**
- Access speed depends on **distance**

➡️ Closer memory = faster access 🏃‍♂️✨

---

### 🪄 The Smart Solution

💡 Allocate memory **near the CPU** running the process
💡 Schedule threads on the **same board when possible**

---

### 🌸 Solaris Magic: _lgroups_

Solaris solves this elegantly:

🟢 **lgroups** = low-latency CPU + memory groups
🟢 Used by both **scheduler** and **pager**

✨ Goal:

- Keep threads and memory **together**
- Reduce latency
- Maximize performance

> _Like keeping family members in the same house~_ 🏠💕

---

## 🌟 Final TL;DR (Memory Spell ✨)

🟢 Processes need a minimum number of frames
🟢 Frames can be allocated equally, proportionally, or by priority
🟢 Global allocation favors throughput
🟢 Local allocation favors predictability
🟢 NUMA systems care deeply about **where** memory lives
