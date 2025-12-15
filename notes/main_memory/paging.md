# 📘 Paging

### ✨ _The Magic That Makes Memory Flexible_ ✨

> _“A process need not live in one place… memory is kinder than that.”_ 💫

---

## 🌟 Why Paging Exists (The Big Problem)

😣 **Old problem:**

- Processes needed **contiguous physical memory**
- Memory became fragmented and messy

✨ **Paging’s promise:**

> 🪄 _A process can live in scattered places — and still feel whole._

---

## 🧠 Core Idea of Paging

🟢 **Physical address space can be noncontiguous**

✔️ Memory is allocated **whenever frames are free**
✔️ Process does _not_ care where pages are placed

🎉 Benefits:

- ❌ Avoids **external fragmentation**
- 📦 Avoids problems with **varying-sized chunks**

⚠️ Still has:

- 🟡 **Internal fragmentation** (we’ll see why soon!)

---

## 🧩 Memory Is Divided Neatly

### 🧱 Physical Memory

- Split into **frames**
- ✔️ Fixed size
- ✔️ Size is power of 2

📏 Typical sizes:

- From **512 bytes** up to **16 MB**

---

### 📄 Logical (Process) Memory

- Split into **pages**
- ✔️ Same size as frames

🧡 _Pages fit perfectly into frames — like matching puzzle pieces._

---

## 🗂️ Behind the Scenes (What the OS Tracks)

🧑‍💻 The Operating System:

- 📝 Keeps track of **free frames**
- 📥 To run a process of **N pages**:
  - Find **N free frames**
  - Load each page into a frame

---

## 📑 Page Table — The Translator 📜

✨ Paging needs a **map** to work.

✔️ Each process has a **page table**
✔️ It translates:

```
Logical address → Physical address
```

🧠 _Processes see an illusion; hardware knows the truth._

---

## 💾 Backing Store (Disk Side)

📌 Even secondary storage:

- Is split into **pages**
- Matches memory paging structure

✨ This symmetry makes swapping elegant and efficient.

---

## 🔍 Address Translation Scheme

🌸 _Let’s split an address like magic!_ 🌸

### 🧮 CPU-Generated Logical Address

It consists of **two parts**:

```
| page number (p) | page offset (d) |
```

✔️ **Page number (p)**

- Used as index into the page table

✔️ **Page offset (d)**

- Position inside the page

---

## 🧠 From Logical to Physical

✨ Translation process:

1️⃣ Use **p** to index the page table
2️⃣ Get the **frame number (f)**
3️⃣ Combine **f + d**
4️⃣ Produce the **physical address** 🏁

---

## ⚙️ Paging Hardware (Conceptual View)

```
CPU
 ↓ logical address (p, d)
Page Table → frame number (f)
 ↓
Physical address (f, d)
 ↓
Physical Memory
```

🧡 _Hardware performs this dance incredibly fast._

---

## 🗺️ Paging Model — Visual Intuition

### 📄 Logical Memory (Pages)

- Page 0
- Page 1
- Page 2
- Page 3

⬇️ via Page Table ⬇️

### 🧱 Physical Memory (Frames)

- Frame 1 ← Page 0
- Frame 4 ← Page 1
- Frame 3 ← Page 2
- Frame 7 ← Page 3

✨ Pages may land anywhere — order does not matter!

---

## 🧪 Paging Example (Numbers, Gently ✨)

📌 Given:

- Logical address space: `2^m`
- Page size: `2^n`

Example:

- `m = 4` → 16-byte logical space
- `n = 2` → 4-byte pages

✔️ Logical address split:

- Page number = `m - n` bits
- Offset = `n` bits

🧠 _Small example, same rules everywhere._

---

## ⚠️ Internal Fragmentation

😔 Even paging isn’t perfect.

### 🧮 Example Calculation

- Page size = **2,048 bytes**
- Process size = **72,766 bytes**

➡️ Uses:

- 35 full pages
- - 1 partial page (1,086 bytes)

❗ Internal fragmentation:

```
2,048 − 1,086 = 962 bytes wasted
```

---

## 📊 Fragmentation Facts to Remember

✔️ Worst case:

- 🟥 **1 frame − 1 byte** wasted

✔️ Average case:

- 🟨 **Half a frame size** wasted

🤔 Question:

> Should we use very small pages?

---

## ⚖️ Trade-Off: Page Size

🌱 **Small pages:**

- ✔️ Less internal fragmentation
- ❌ Larger page tables (more memory)

🌳 **Large pages:**

- ✔️ Smaller page tables
- ❌ More internal fragmentation

✨ Reality:

- Page sizes have **grown over time**

📌 Example:

- Solaris supports **8 KB** and **4 MB** pages

---

## 🔐 Protection & Illusion

🧠 Important magic rule:

✔️ Process sees **only its own memory**
✔️ Physical memory layout is hidden

✨ Paging provides:

- Memory protection
- Clean abstraction

---

## 🧁 TL;DR — Gentle Recap

✔️ Paging allows **noncontiguous physical memory**
✔️ Memory split into **pages** and **frames**
✔️ Page table translates addresses 📑
✔️ Eliminates **external fragmentation**
✔️ Still has **internal fragmentation** ⚠️
✔️ Page size is a trade-off ⚖️
