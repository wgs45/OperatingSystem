# 🖥️ **Computer System Architecture**

---

## 🔹 **1. Single Processor Systems**

A **Single Processor System** consists of **one** main **CPU** responsible for executing general-purpose instructions. It may include **special-purpose processors** for device-specific tasks.

✅ **Example:** Personal Computers (PCs), Laptops

📌 **Key Characteristics:**

- Only **one CPU** executes instructions.
- Other processors handle **device-specific tasks** (e.g., graphics card, sound card).
- **Lower performance** compared to multiprocessor systems.

---

## 🔹 **2. Multiprocessor Systems (Parallel Systems)**

Also called **Tightly Coupled Systems**, these systems have **two or more processors** working together, sharing **memory, clock, and peripheral devices**.

✅ **Example:** Supercomputers, High-performance servers

### ✨ **Advantages of Multiprocessor Systems:**

- ✔️ **Increased Throughput** – Multiple CPUs perform tasks **simultaneously**, reducing processing time.
- ✔️ **Economy of Scale** – Shared resources lead to **cost efficiency**.
- ✔️ **Higher Reliability** – If one processor fails, others continue functioning.

### 🔹 **Types of Multiprocessor Systems**

#### 🔹 **1. Symmetric Multiprocessing (SMP)**

- All CPUs have **equal access** to memory and perform tasks independently.
- **Example:** Intel Xeon Processors used in modern servers.

#### 🔹 **2. Asymmetric Multiprocessing (AMP)**

- One **main CPU** assigns tasks to other CPUs (master-slave model).
- **Example:** Older gaming consoles like **PlayStation 2**.

---

## 🔹 **3. Clustered Systems**

Clustered systems combine **multiple independent computers** to work together for **better performance and availability**.

✅ **Example:** Google Cloud, AWS, High-availability databases

📌 **Key Characteristics:**

- Composed of **two or more interconnected systems**.
- Provides **high availability** and **load balancing**.
- Used for **mission-critical applications** where downtime is not acceptable.

### 🔹 **Types of Clustered Systems**

1️⃣ **Asymmetric Clustering** – One system remains on **standby mode** and takes over in case of failure.  
2️⃣ **Symmetric Clustering** – All systems work together and **share the load**.

---

## 📊 **Comparison Table: System Architectures**

| Feature        | Single Processor | Multiprocessor          | Clustered System   |
| -------------- | ---------------- | ----------------------- | ------------------ |
| Number of CPUs | 1                | 2 or more               | Multiple Systems   |
| Performance    | Lower            | Higher                  | Very High          |
| Reliability    | Lower            | Higher                  | Highest (Failover) |
| Example        | Laptops, PCs     | Servers, Supercomputers | Google Cloud, AWS  |

---

### 💡 **Fun Fact**

🔹 The **PlayStation 5** uses a **multiprocessor system** to enhance gaming performance! 🎮
