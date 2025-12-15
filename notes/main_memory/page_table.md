# 📗 Page Table & TLB

### ✨ _How Addresses Find Their True Home_ ✨

> _“Translation is an art—swift, precise, and mostly invisible.”_ 💫

---

## 🧱 Free Frames & Page Allocation

🟢 **Free-frame list** keeps track of empty frames in physical memory.

### 🧩 Before Allocation

- Free frames: `14, 13, 18, 20, 15`
- New process needs **4 pages** (page 0–3)

### ✨ After Allocation

✔️ OS selects free frames
✔️ Assigns one frame per page

**New-process page table (example):**

```
Page → Frame
0    → 14
1    → 13
2    → 18
3    → 20
```

💡 _Pages can land anywhere—order doesn’t matter!_ 🧠

---

## 🗂️ Where Is the Page Table Stored?

📌 **In main memory (RAM)**

To find it quickly, hardware uses:

- 🧭 **PTBR** — Page-Table Base Register (start address)
- 📏 **PTLR** — Page-Table Length Register (table size)

✨ Each process has its own page table.

---

## ⚠️ The Two-Memory-Access Problem

Without optimization:

1️⃣ Access **page table** (to get frame)
2️⃣ Access **actual data/instruction**

❗ Result:

> 🐢 **Every memory access costs two accesses**

---

## ⚡ The Hero Appears: TLB

🌟 **TLB — Translation Lookaside Buffer**

- Special **fast associative cache**
- Stores recent page → frame translations

🧡 Goal:

> 🚀 Reduce address translation to _one_ memory access most of the time

---

## 🧠 Associative Memory (How TLB Thinks)

✨ **Parallel search magic** ✨

Process:

1️⃣ CPU generates `(page#, offset)`
2️⃣ TLB checks **all entries at once**
3️⃣ If page# found → frame# returned instantly
4️⃣ If not → consult page table in memory

---

## 🎯 TLB Hit vs Miss

### 🌸 TLB Hit

✔️ Page found in TLB
✔️ Physical address formed immediately
✔️ Only **1 memory access**

### 🌧️ TLB Miss

❌ Page not in TLB
✔️ Access page table in memory
✔️ Load result into TLB for next time

✨ _Learning from experience~_ 💖

---

## 🧩 Paging Hardware with TLB (Flow)

```
CPU → logical address (p, d)
          ↓
        TLB
      ↙      ↘
   hit ✔️     miss ❌
    ↓           ↓
physical addr   page table → frame
    ↓               ↓
physical memory ←———
```

---

## 🛡️ ASIDs — Protecting Processes

🆔 **ASID (Address-Space Identifier)**:

- Stored in some TLB entries
- Uniquely identifies each process

✨ Benefits:

- ✔️ No TLB flush on context switch
- ✔️ Strong address-space protection

Without ASIDs?

> 🔄 Must flush TLB every switch (slower)

---

## 📏 TLB Size & Policies

📌 Typical TLB size:

- 🧠 **64 to 1,024 entries**

🔁 On TLB miss:

- Replacement policy decides which entry to evict

⭐ Some entries can be:

- **Wired down** (never replaced)

---

## ⏱️ Effective Access Time (EAT)

🌸 _Now for the timing spell—gently!_ 🌸

### 🔢 Ingredients

- `m` → memory access time
- `ε` → TLB lookup time
- `α` → TLB hit ratio

### ✨ General Idea

- Hit → fast
- Miss → slower (extra memory access)

---

## 🧮 EAT Intuition (No Math Pain 💖)

✔️ **On a hit:**

- TLB lookup + 1 memory access

✔️ **On a miss:**

- TLB lookup + page table + memory

💡 EAT is just the **weighted average** of both cases.

---

## 🧪 Example (Realistic Numbers)

📌 Given:

- TLB lookup = **20 ns**
- Memory access = **100 ns**

### Case 1: α = 80%

- Hit path ≈ 120 ns
- Miss path ≈ 220 ns

➡️ **EAT ≈ 140 ns**

### Case 2: α = 99%

- Most accesses are hits ✨

➡️ **EAT ≈ 101 ns**

🌟 _Almost as fast as pure memory!_

---

## 🧁 TL;DR — Gentle Recap

✔️ Page tables map **pages → frames** 📑
✔️ Stored in **main memory**
✔️ PTBR & PTLR locate and size them
✔️ TLB fixes the **two-access problem** ⚡
✔️ ASIDs avoid TLB flushes 🔐
✔️ High hit ratio = blazing fast memory 🚀
