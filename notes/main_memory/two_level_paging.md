## 🗺️ Two-Level Paging — _“A map within a map.”_

> When memory grows vast,
> we don’t carry one giant book —
> we carry **indexes to smaller books** 📚✨

### 🔹 Why Two-Level Paging Exists

A single page table can be **huge** ❗
So instead, we **page the page table itself**.

🧠 Idea:

- Page table → split into **chunks**
- Use:
  - 🧭 **Outer page table**
  - 📖 **Inner page tables**

Only the needed inner tables are loaded 💕
→ Memory efficient & elegant

---

## 🧩 Two-Level Page Table Structure

### 🪄 Conceptual View

```
Logical Address
   ↓
[ Outer Page # | Inner Page # | Offset ]
   ↓
Outer Page Table
   ↓
Inner Page Table
   ↓
Physical Frame + Offset
```

⭐ This is also called a **forward-mapped page table**

---

## 🧠 Address Breakdown (32-bit Example)

✨ Given:

- 🧮 **32-bit logical address**
- 📏 **Page size = 1 KB (1024 bytes)**

### 🔹 Step 1: Offset Size

- 1 KB = 2¹⁰ bytes
  ➡️ **Offset = 10 bits**

### 🔹 Step 2: Page Number Size

- 32 − 10 = **22 bits** (page number)

---

## 🪜 Splitting the Page Number (Two Levels)

Since the page table is paged too ✨
we split the **22-bit page number**:

| Part  | Size    | Meaning                          |
| ----- | ------- | -------------------------------- |
| 🧭 p₁ | 12 bits | Index into **outer page table**  |
| 📖 p₂ | 10 bits | Offset into **inner page table** |
| 📍 d  | 10 bits | Page offset                      |

### 🔹 Final Logical Address Layout

```
| p₁ (12) | p₂ (10) | d (10) |
```

🌸 _Nested pages, perfectly balanced._

---

## 🔄 Address Translation Flow (Step-by-Step)

💻 CPU generates logical address →
1️⃣ Use **p₁** to index outer page table
2️⃣ Find address of inner page table
3️⃣ Use **p₂** to index inner page table
4️⃣ Get **frame number**
5️⃣ Combine with **offset (d)**
✨ → Physical address ✨

🧠 Yes, this may require **multiple memory accesses**
(Unless TLB saves the day~ 🪽)

---

## 🧪 Visual Intuition (Gentle)

- Outer page table = table of contents 📘
- Inner page tables = chapters 📖
- Pages = paragraphs
- Offset = character position ✨

---

## 🌌 What About 64-bit Address Space?

_Euphie sighs softly…_ 💭
Even **two levels aren’t enough anymore**.

### 🔹 Example: 64-bit System

Assume:

- Page size = **4 KB (2¹²)**
- Offset = **12 bits**
- Remaining = **52-bit page number**

📦 Page table entries explode in size ❗

---

## 🧠 Why Inner Page Tables Are 2¹⁰ Entries (Not 2¹²)

✨ Important exam hint ✨

- Page size = 4 KB
- Page table entry = 4 bytes

➡️ 4 KB / 4 bytes = **1024 entries = 2¹⁰**

⭐ That’s why:

```
2¹⁰ entries + 4-byte entries = 2¹² bytes (1 page)
```

---

## 🧱 Scaling Further — More Levels

When even two levels fail:

- ➕ Add **another outer page table**
- Leads to:
  - 3-level
  - 4-level paging (used in modern OS)

⚠️ Downside:

- Up to **4 memory accesses** per translation
- TLB becomes absolutely critical 🪽

---

## ✨ TL;DR — Two-Level Paging

⭐ One giant page table = bad ❌
⭐ Two-level paging = page the page table ✔️
⭐ Logical address = p₁ | p₂ | offset
⭐ Saves memory by loading only needed tables
⭐ Large address spaces → multi-level paging
