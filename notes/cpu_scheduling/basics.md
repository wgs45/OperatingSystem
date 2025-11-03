# 🌐 **CPU Scheduling: The Dance of Time & Tasks**

> _“In a kingdom of processors, every process awaits its turn at the throne of the CPU…”_ 👑

---

## 💞 **Definition: The Essence of CPU Scheduling**

🔹 **Goal:** Achieve _maximum CPU utilization_ through multitasking (multiprogramming).
🔹 **Concept:** Each process alternates between:

- ⚙️ **CPU Burst** — when it performs computation
- 💾 **I/O Burst** — when it waits for input/output

🔮 **Key Focus:** The _distribution_ of CPU burst#s decides scheduling efficiency!

📖 _Think of it like a dance: when one process twirls off to wait for I/O, another gracefully takes its place on the CPU stage._

---

## 🧭 **The CPU Scheduler — The Short-Term Strategist**

🪄 **What it does:**
Selects a process from the **ready queue** and gives it the CPU.

🧩 **When does it act?**

1. ⏩ Running → Waiting
2. 🔁 Running → Ready
3. 💤 Waiting → Ready
4. 🏁 Process Termination

✨ **Types of Scheduling:**

- 🕊️ **Non-preemptive** → happens in case (1) and (4); once CPU is given, it’s not taken back.
- ⚔️ **Preemptive** → happens in (2) and (3); CPU can be snatched away for a higher-priority process.

⚠️ **Considerations:**

- Shared data safety 🧠
- Preemption inside kernel mode 🛡️
- Interrupts during crucial operations ⚡

---

## ⚙️ **Dispatcher — The Quick Switcher**

_Imagine a butler gracefully changing the guests at the CPU’s royal table 🍵._

The **Dispatcher**:

- Performs **context switch** 🌀
- Switches CPU to **user mode** 👤
- Jumps to the right spot in the program to resume execution

⏱️ **Dispatch Latency:**
Time taken to pause one process and start another — like the breath between musical notes 🎶

---

## 🌟 **Scheduling Criteria — The Performance Spellbook**

Every scheduler aims for the perfect balance among these powers:

| 💠 Criterion        | 🌸 Meaning                                     | 🎯 Goal  |
| ------------------- | ---------------------------------------------- | -------- |
| **CPU Utilization** | Keep CPU busy as much as possible              | Maximize |
| **Throughput**      | # of processes finished per time unit          | Maximize |
| **Turnaround Time** | Total time to execute a process                | Minimize |
| **Waiting Time**    | Time spent waiting in the ready queue          | Minimize |
| **Response Time**   | Time from request submission to first response | Minimize |

🪶 _A good scheduler is like a wise conductor — keeping every note in rhythm without missing a beat._

---

## 🧙‍♀️ **Optimization Goals — The Ideal Harmony**

✨ Seek the balance of:

- ✅ Max CPU utilization
- ✅ Max throughput
- ⏳ Min turnaround time
- 🕰️ Min waiting time
- 💬 Min response time

📜 _These are the five guiding stars of CPU performance._
