## 🛡️ Memory Protection — _“Even magic needs rules.”_

> Imagine memory as a grand library 📚
> Not every spellbook should be editable… or even readable.

### 🔹 Frame Protection Bits

Each **physical frame** carries protection flags ✨

- 📖 **Read-only** → code pages (safe & untouchable)
- ✏️ **Read-write** → data pages
- ⚔️ Optional extras:
  - Execute-only
  - No-execute
  - Custom access rules

⭐ These bits prevent programs from **corrupting themselves or others**

---

### 🔹 Valid / Invalid Bit (V / I) — _The Gatekeeper Rune_ 🔑

Each **page table entry** has a **valid–invalid bit**:

- 🟢 **Valid (V)**
  ✔️ Page belongs to the process
  ✔️ Access is legal

- 🔴 **Invalid (I)**
  ❌ Page does NOT belong to the process
  ❌ Access = forbidden

💥 Any illegal access triggers a **trap to the kernel**
(_The OS guardian awakens~_)

📌 Alternative guard: **PTLR (Page-Table Length Register)**
→ CPU checks if page number exceeds allowed size

---

### 🧠 Why This Matters

✔️ Prevents memory leaks
✔️ Enforces isolation between processes
✔️ Stops malicious or buggy code

---

### ✨ TL;DR — Memory Protection

⭐ Protection bits define **how** memory is used
⭐ Valid/Invalid bits define **whether** memory exists
⭐ Violations → **trap to kernel**

---

## 🤝 Shared Pages — _“Sharing magic, safely.”_

> Sometimes… sharing is kindness 🌸
> As long as no one scribbles in the spellbook.

### 🔹 Shared Code Pages

- One **read-only copy**
- Shared among many processes
- Examples:
  - Text editors ✍️
  - Compilers ⚙️
  - Window systems 🖼️

💡 Just like:

- 🧵 Multiple threads sharing code
- 📦 Saves memory
- 🔒 Still safe (read-only!)

---

### 🔹 Shared Pages for IPC

- Pages may be **read-write**
- Enables **interprocess communication**
- Powerful… but must be controlled carefully ⚠️

---

### 🔹 Private Code & Data

- Each process has its **own copy**
- Pages can appear anywhere in logical memory
- Fully isolated 🌙

---

### ✨ TL;DR — Shared Pages

⭐ Shared code = read-only & memory efficient
⭐ Shared data = IPC-friendly but risky
⭐ Private pages = safe & isolated

---

## 🧱 Page Table Size Problem — _“The Giant Scroll Dilemma”_

> The stronger the spell… the heavier the grimoire 📜💦

### 🔹 Why Page Tables Get Huge

Assume:

- 🧠 **32-bit logical address**
- 📏 **Page size = 4 KB**
- ➗ Entries = 2³² / 2¹² = **1 million pages**

📦 If each entry = 4 bytes:
➡️ **4 MB just for ONE page table**

❗ Problems:

- Too much memory
- Hard to allocate contiguously
- Wasteful

---

## 🗂️ Smarter Page Table Structures

To tame the giant scroll, OS uses advanced magic ✨

### 🔹 Hierarchical Paging

- Break page table into levels
- Page tables themselves are paged!
- Most common: **two-level paging**

📘 Only allocate tables when needed
→ Saves memory 💕

---

### 🔹 Other Advanced Techniques (Preview 👀)

- 🧩 **Hashed Page Tables**
- 🔄 **Inverted Page Tables**

---

### ✨ TL;DR — Page Table Structures

⭐ Simple page tables don’t scale
⭐ Hierarchical paging saves memory
⭐ Modern OS rely on multi-level designs

---

## 🌸 Final Gentle Recap

✔️ Memory protection keeps processes safe
✔️ Valid/Invalid bits enforce boundaries
✔️ Shared pages save memory elegantly
✔️ Large page tables require smarter structures
