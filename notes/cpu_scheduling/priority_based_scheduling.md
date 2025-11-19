# 🌈 **Priority-Based Scheduling — Magical Study Grimoire** ✨

_(a soft breeze turns the page… glowing runes float around the margins)_

---

## 💫 **1. What Is Real-Time Scheduling?**

Real-time systems must respond **fast**, **predictably**, and **correctly**. Some tasks _must_ finish before specific time limits.

### 🌟 Key Ideas

- ✔️ **Preemptive, priority-based scheduling** is required.
- ✔️ Only ensures **soft real-time** (good but not guaranteed).
- ✔️ **Hard real-time** needs strict deadline handling.
- ✔️ Tasks can be **periodic**:
  - 🔸 **Processing time**: `t`
  - 🔸 **Deadline**: `d`
  - 🔸 **Period**: `p`
  - Condition: `0 ≤ t ≤ d ≤ p`

- 🌱 **Rate of task** = `1 / p`

### ✨ TL;DR

Real-time tasks repeat, must meet deadlines, and have strict timing rules.

---

# 🌸 **2. Rate Monotonic Scheduling (RMS)**

_Someone draws two tiny chibi processes fighting for priority—one bouncing faster than the other_ 🎀

### 💖 Concept

**Shorter period = higher priority.**
Tasks that run more frequently get to jump ahead.

### 🌼 Example

- P1: period = 50 → **higher priority**
- P2: period = 100 → lower priority
- Process times: t₁ = 20, t₂ = 35

### 😵 When Deadlines Are Missed

Even RMS can fail when tasks are too heavy:

- P1: p = 50, t = 25
- P2: p = 80, t = 35
  → ❗ CPU can’t keep up → missed deadlines.

### ✨ TL;DR

RMS is simple and effective but not perfect. High load = possible failures.

---

# 🕊️ **3. Earliest Deadline First (EDF)**

_Someone taps the page and glowing deadline timers appear like magical clocks_ ⏳✨

### 🌟 Concept

**Soonest deadline → highest priority**
Priority changes dynamically as deadlines approach.

### 🌱 Example

- P1: p = 50, t = 25
- P2: p = 80, t = 35
  EDF often schedules these better than RMS.

### ✨ TL;DR

EDF adapts and usually performs better, especially with high loads.

---

# 🧪 **4. Virtualization & Scheduling**

_Two chibi OSes bickering over CPU crumbs… Someone giggles softly_ 😄

### 🔍 What Happens?

- Virtual machines **believe** they have full CPUs.
- But the hypervisor is secretly scheduling all guests.
- Result:
  - ❌ Bad response times
  - ❌ Wrong time-of-day clocks
  - ❌ Guests’ own scheduling is disrupted

### ✨ TL;DR

Virtualization makes scheduling trickier because VMs don’t know they’re sharing.

---

# 🧩 **5. Proportional Share Scheduling**

_Someone draws little pie-chart slices glowing pastel colors_ 🥧✨

### 💡 Idea

CPU time is divided into **shares**.

- Total shares = T
- A process gets N shares
- Guaranteed CPU share = `N / T`

Simple, fair, and predictable.

### ✨ TL;DR

Each process gets a fixed slice of CPU time like magical cake.

---

# 🛠️ **6. POSIX Real-Time Scheduling**

### 🎀 Real-Time Scheduling Classes

1. **SCHED_FIFO**
   - First-come-first-served
   - No time slicing
   - High-priority threads run until they block
   - 💥 _Very intense; like a knight who refuses to step aside_

2. **SCHED_RR**
   - Round-robin behavior
   - Time-slicing among equal-priority threads
   - ⚔️ _More polite knights taking turns_

### 🔧 Useful Functions

- `pthread_attr_getsched_policy(attr, policy)`
- `pthread_attr_setsched_policy(attr, policy)`

### ✨ TL;DR

FIFO is strict, RR is fairer. POSIX gives developers direct control.

---

# 🏰 **7. OS Scheduling Examples**

- 🐧 **Linux** → CFS + Real-time classes
- 🪟 **Windows** → Priority levels, quantum-based
- 🌞 **Solaris** → Multiple scheduling classes

---

# 💖 **Final Sparkles — Recap** ✨

- 🌼 RMS → static priority, shorter period = higher priority
- ⏳ EDF → dynamic priority, earliest deadline wins
- 🖥️ Virtualization → complicates timing
- 🥧 Proportional Share → fair CPU slices
- ⚔️ POSIX Real-Time → FIFO & RR modes
- 🧠 Real-time tasks must meet deadlines → crucial for safety-critical systems
