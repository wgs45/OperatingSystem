🌙✨ **Least Recently Used (LRU)** — _The Gentle Art of Remembering_ ✨🌙

---

## 🔹 What Is LRU? 🕰️

🪄 **Least Recently Used (LRU)**:

> Replace the page that **has not been used for the longest time in the past**

✨ Key idea:

- Uses **past behavior**, not future 🔮❌
- Assumes: _recently used pages are likely to be used again_

📌 Think of it as:

> “Who has been forgotten the longest?” 🌙

---

## 🔸 LRU vs FIFO vs Optimal 🌸

🧺 FIFO:

- Evicts oldest arrival
- Ignores usage 😢

🧠 LRU:

- Evicts least recently used
- Smarter & adaptive ✨

🔮 Optimal:

- Evicts farthest future use
- Perfect but impossible

💡 LRU stands gracefully **between FIFO and Optimal** 💖

---

## 🌟 LRU Walkthrough (3 Frames) 📜

✨ Reference string:
7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1

🧱 Frames available: **3**

📊 Final result:

- ⭐ Page faults = **12**
- ⭐ Page fault ratio = **12 / 20 = 60%**

🎯 Interpretation:

- ✔️ Better than FIFO (15 faults)
- ❌ Worse than Optimal (9 faults)

---

## 🔹 Why LRU Is Popular 💕

✔️ Adapts to real usage patterns
✔️ Performs well in practice
✔️ No Belady’s Anomaly ✨

📌 LRU is a **stack algorithm**:

> More frames → never more faults ❗

---

## 🌙 How Do We Implement LRU? 🛠️

🌸 This is where reality gently hurts 💔

---

## 🔸 Counter Implementation ⏱️

🧠 Idea:

- Each page has a **counter**
- On every reference → copy current clock value

🪄 Replacement:

- Choose page with **smallest counter** (oldest use)

⚠️ Drawbacks:

- Requires searching page table
- Hardware support needed

---

## 🔸 Stack Implementation 📚

🧠 Idea:

- Maintain a **stack (most recent on top)**

✨ On page reference:

- Move page to the top
- Requires updating multiple pointers

🎯 Pros:

- No search during replacement

⚠️ Cons:

- Each access is expensive

---

## 🌸 Stack Intuition Example 🧩

✨ Page references:
4, 7, 0, 7, 1, 0, 1, 2, 1, 2, 7, 1, 2

🧠 Stack behavior:

- Most recently used → top
- Least recently used → bottom

🌙 Bottom page is the one to replace

---

## 🔹 Why LRU Has No Belady’s Anomaly ✨

📌 LRU (like Optimal) is a **stack algorithm**:

✔️ Pages in memory with N frames ⊆ pages with N+1 frames

💖 Therefore:

> Adding more frames never increases page faults

---

## 🌟 LRU Approximation Algorithms 🧪

🌸 True LRU is costly… so we cheat gently 💫

---

## 🔸 Reference Bit Algorithm 🔘

🧠 Each page has a **reference bit**:

- Initially = 0
- Set to 1 when referenced

✨ Replacement:

- Pick any page with bit = 0

⚠️ Limitation:

- No ordering information

---

## 🔸 Second-Chance Algorithm 💞

🧺 FIFO + kindness

✨ On replacement:

- Reference bit = 0 → replace
- Reference bit = 1 →
  - Set bit to 0
  - Give page a second chance 🌸

---

## 🔸 Clock Algorithm 🕰️

🕒 Pages arranged in a circle

✨ Replacement rule:

- Bit = 0 → replace
- Bit = 1 → clear bit & move on

💡 Efficient and widely used!

---

## 🌟 TL;DR — Memory Bracelet 📿

🟢 LRU evicts least recently used page
🟢 Better than FIFO, close to Optimal
🟢 No Belady’s Anomaly
🟢 True LRU is expensive to implement
🟢 Clock algorithm ≈ practical LRU
