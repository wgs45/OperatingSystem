# 🖥️ **Operating System Structure**

---

## 🔹 **Multiprogramming & Multitasking**

Operating systems come in **different structures**, but they share **common features** such as:  
✅ **Multiprogramming** – Efficient CPU utilization.  
✅ **Time Sharing (Multitasking)** – Allows multiple users to interact simultaneously.

---

## 🔹 **What is Multiprogramming?**

A **single user** cannot keep the CPU or I/O devices **busy all the time**. Multiprogramming helps **increase CPU utilization** by managing multiple **jobs** efficiently.

📌 **Key Characteristics:**

- CPU **always has** a job to execute.
- Organizes **jobs (code + data)** efficiently.
- **Maximizes resource utilization** (CPU, memory, peripherals).
- **No direct user interaction** while jobs execute.

✅ **Example:**  
Imagine a **printer** queue in a school 🏫—even if one student isn’t printing, others can!

---

## 🔹 **What is Time Sharing (Multitasking)?**

A **time-sharing system** rapidly switches between tasks, giving users the illusion that multiple tasks are running **simultaneously**.

📌 **Key Features:**

- ✔️ CPU **switches between jobs** frequently.
- ✔️ Users **interact with programs in real-time**.
- ✔️ **Supports multiple users simultaneously**.
- ✔️ Uses **CPU scheduling + multiprogramming** to allocate time fairly.
- ✔️ Each user gets a separate **process in memory**.

✅ **Example:**  
While browsing the web 🌍, you can also play music 🎵 and download files 📂—all happening at the same time!

---

## 🔹 **Key Concept: Processes in Memory**

🟢 **Linux:** Background tasks are called **Daemons**.  
🔵 **Windows:** Running programs are called **Processes**.

---

### 💡 **Fun Fact:**

🔹 Early computers 🖥️ **didn't have multitasking!** You had to wait for one task to finish before starting another. 😲
