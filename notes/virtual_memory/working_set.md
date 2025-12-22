# 🌙📘 Working-Set Model

### _— Understanding a Process’s Living Memory —_

---

## 🌱 The Core Idea (Big Picture)

A process doesn’t use all its pages at once.
It focuses on a **small, meaningful set** of pages at any moment.

✨ This set is called the **Working Set**.

---

## 🪟 Working-Set Window (Δ)

### 🔹 What Is Δ (Delta)?

🟢 Δ = a **fixed window of recent page references**

📌 Example:

- Δ = **10,000 instructions**
- Look at which pages were referenced in the **most recent 10,000 instructions**

> _Think of Δ as a “memory spotlight” shining on recent thoughts_ ✨

---

## 📦 Working Set of a Process (WSS)

### 🌸 Definition

🟣 **WSSᵢ** = number of **distinct pages** referenced by process **Pᵢ** within the last Δ references

🔹 It changes over time
🔹 It represents the process’s **current locality**

---

### ⚠️ Choosing Δ Carefully

❗ Δ too small
➡️ Misses parts of the locality

❗ Δ too large
➡️ Includes **multiple localities**

💀 Δ = ∞
➡️ Includes **entire program** (useless!)

> _Balance is elegance~_ 🌸

---

## 🌊 Total Memory Demand

### 🌟 Total Demand Frames (D)

🟢 **D = sum of all working sets**

📌 Meaning:

- Approximation of **overall memory demand**

---

### 🚨 The Thrashing Condition

❌ If **D > m** (total physical frames)

➡️ **Thrashing occurs**

💡 **Policy Decision**
When D > m:

- Suspend or swap out one or more processes
- Reduce memory pressure immediately

---

## 🧠 Visual Intuition (Localities)

```
Page References →
...2615777751623412344434344413234443444...

WS at time t₁ → {1,2,5,6,7}
WS at time t₂ → {3,4}
```

✨ Working sets **shift smoothly** as execution changes

---

## ⏱️ Keeping Track of the Working Set

_(Approximation Technique)_

Perfect tracking is expensive, so we approximate gently 💫

---

### 🌸 Basic Approximation Method

🟢 Use:

- Interval timer
- Reference bit per page

📌 Example Setup:

- Δ = 10,000 references
- Timer interrupt every **5000 time units**
- **2 bits per page** stored in memory

---

### 🔁 How It Works

1️⃣ Timer interrupts
2️⃣ Copy reference bits
3️⃣ Clear reference bits
4️⃣ If any bit = 1 → page is in working set

✔️ Simple
❗ Not perfectly accurate

---

### 🌟 Improved Version

✨ Use:

- **10 reference bits**
- Interrupt every **1000 time units**

➡️ Finer history, better accuracy 🌸

---

## 📉 Page-Fault Frequency (PFF)

_A More Direct Approach_

---

### 🌼 The Idea

Instead of tracking pages, track **page-fault rate**.

🟢 Define an **acceptable PFF range**

---

### ⚖️ Dynamic Adjustment

📈 Fault rate too high
➡️ Give process **more frames**

📉 Fault rate too low
➡️ Take away a frame

✔️ Simple
✔️ Adaptive
✔️ Uses **local replacement**

> _Listening to memory’s heartbeat~_ 💗

---

## 🌸 Working Sets & Page Faults

🟢 Working set size ↑ → Page faults ↓
🟢 Working set size ↓ → Page faults ↑

📈 Both change over time:

- Peaks when locality shifts
- Valleys when stable

✨ The OS must **adapt continuously**

---

## 🧁 TL;DR — Working-Set Wisdom ✨

🟣 Working set = pages used recently
🟣 Δ defines how far back we look
🟣 Sum of working sets estimates memory demand
🟣 If demand > memory → thrashing
🟣 PFF dynamically balances frame allocation

> _Memory is not about quantity… but relevance._ 🌙
