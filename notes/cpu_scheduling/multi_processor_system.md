# 🌟🌸 **Multiprocessor Systems — Enchanted OS Grimoire** 🌸🌟

_Soft glow… magical diagrams… warm explanations…_

---

## 💠 **1. What Are Multiprocessor Systems?**

When your computer has _more than one CPU_, scheduling becomes a little more… spicy 😌🔥
The OS must decide **which CPU runs what**, while keeping performance smooth and harmonious.

### ⭐ Key Ideas

- Multiple CPUs = more scheduling complexity
- CPUs may be:
  - **Homogeneous** → all CPU cores are the same
  - **Heterogeneous** → different kinds of cores (e.g., big.LITTLE designs)

---

# 🧭 **2. Multiprocessing Models**

## 🟥 **Asymmetric Multiprocessing (AMP)**

_One CPU is the “boss,” others are helpers._

- Only **one processor** handles system data structures
- Removes the need for complicated sharing
- Simpler, but less flexible
- Used in older or specialized systems

## 🟩 **Symmetric Multiprocessing (SMP)**

_smiles softly: “Everyone gets equal rights~”_ 😌💚

- **Every processor is self-scheduling**
- Processes may be placed in:
  - A **single global ready queue**, or
  - Separate **private ready queues**

- This is the **current dominant model** in OS design
- Works beautifully when combined with affinity & load balancing

---

# 💚💫 **3. Processor Affinity (CPU Affinity)**

_Like a process saying: “I’m comfy on this CPU, let me stay here please…”_ 😳💞

Why?
Because moving a process between CPUs often loses the benefit of cached data—staying in place keeps things fast.

### Types of Affinity

### 🟢 **Soft Affinity**

- OS _tries_ to keep the process on the same CPU
- But it **may migrate** if necessary

### 🔵 **Hard Affinity**

- The process is **strictly bound** to a specific CPU
- No migration unless explicitly changed

### 📝 Real-World Example

Tools like `taskset` (Linux) let you bind a process to specific cores.

---

# 🔮 **4. NUMA (Non-Uniform Memory Access)**

_Memory distance magic ✨_

- In NUMA systems, memory access time **depends on which CPU** requests it
- CPUs have “local” memory (fast) and “remote” memory (slower)
- OS schedulers consider:
  ✔ CPU affinity
  ✔ Memory placement
  ✔ Minimizing cross-node movement

Think of NUMA like different “neighborhoods”:
Staying in your own neighborhood = fast
Crossing town = slower 💨

---

# 🌗 **5. Load Balancing in Multiprocessor Scheduling**

### Why?

To prevent:

- One CPU being overworked 😭💦
- Another CPU being idle and bored 😴

### Techniques

### 🔼 **Push Migration**

“Hey CPU 4, you look overloaded—let me take something for you!”

- Periodic checks
- Tasks pushed from busy CPUs → less busy ones

### 🔽 **Pull Migration**

“Ugh… I’m idle. Anyone got something for me?”

- Idle CPUs pull tasks from busy ones

### ⚠️ Side Effect

Load balancing can **weaken processor affinity**, causing more migrations.

---

# 🔥🧵 **6. Multicore Processors**

The modern standard: multiple cores placed on one physical chip ✨
Benefits:

- Faster overall performance
- Lower power consumption
- Supports _multiple threads per core_

### Magical Trick

When one thread is waiting on memory, the core switches to another thread instantly → better CPU utilization 💫

---

# 🌀✨ **7. Multithreaded Multicore System**

A combination of:

- Multiple CPUs
- Multiple cores
- Multiple threads
  All working at different layers, creating a beautifully complex performance symphony ✨🎶

---

# ⏱️ **8. Real-Time CPU Scheduling**

When deadlines matter… like spellcasting under pressure ❗⏳

## 🌿 **Soft Real-Time Systems**

- Try their best
- No guarantee a critical task meets its deadline
- Examples: multimedia, streaming

## 🔥 **Hard Real-Time Systems**

- Deadlines are sacred
- Missing a deadline = failure
- Used in autopilots, medical devices, robotics

---

# ⏰ **9. Latencies (The Hidden Delays)**

Two types of delays affect real-time performance:

### 1️⃣ **Interrupt Latency**

Time from interrupt arrival → start of its handlr

### 2️⃣ **Dispatch Latency**

Time for the scheduler to:

- Pause the current process
- Switch to another

### ⚡ Dispatch Latency Conflict Phase

Issues include:

1. Preempting processes running in kernel mode
2. Releasing resources blocked by low-priority tasks
   required by a high-priority one

---

# 🌸💖 **TL;DR — Sparkle Summary**

- SMP = common modern scheduling model
- Affinity keeps a process on its preferred CPU
- Load balancing spreads work across CPUs
- NUMA introduces memory distance concerns
- Multicore processors allow parallelism + efficiency
- Real-time scheduling focuses on deadlines
- Latencies = interrupt & dispatch delays
