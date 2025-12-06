# **0️⃣ Before You Start — Requirements**

✔ A Linux environment (Ubuntu recommended)
✔ GCC installed
✔ Terminal
✔ All `.c` files and `run_tests.sh`

---

# **1️⃣ Create Project Folder**

```bash
mkdir login_assignment
cd login_assignment
```

---

# **2️⃣ Create All Source Files**

Copy each file EXACTLY into your folder:

### ✔ `login_server_fork.c`

### ✔ `login_server_thread.c`

### ✔ `login_client.c`

### ✔ `login_stress.c`

### ✔ `run_tests.sh`

---

# **3️⃣ Create users.txt**

```bash
nano users.txt
```

Paste:

```
alice 1234
bob 5678
test 0000
```

Save: **Ctrl+O → Enter → Ctrl+X**

---

# **4️⃣ Compile Everything**

Run these commands **in the folder**:

```bash
gcc login_server_fork.c -o login_server_fork
gcc login_server_thread.c -o login_server_thread -lpthread
gcc login_client.c -o login_client
gcc login_stress.c -o login_stress -lpthread
chmod +x run_tests.sh
```

---

# **5️⃣ Test the Fork Server Manually**

### 1. Start the fork server

```bash
./login_server_fork
```

Terminal will look like it's “doing nothing” — that’s correct.

### 2. Open a SECOND terminal window

Run:

```bash
./login_client 127.0.0.1 alice 1234
```

You should see:

```
Server Response: OK
```

### 3. Stop server

Go back to server terminal → press:

```
Ctrl + C
```

---

# **6️⃣ Test the Thread Server Manually**

### 1. Start thread server

```bash
./login_server_thread
```

### 2. Open another terminal

```bash
./login_client 127.0.0.1 alice 1234
```

See:

```
Server Response: OK
```

Stop server:

```
Ctrl + C
```

---

# **7️⃣ Run the Stress Test**

## **Test Fork Version with different concurrency:**

### Start fork server

```bash
./login_server_fork
```

### In another terminal

Run concurrency = **10, 50, 100, 200**

```bash
./login_stress 127.0.0.1 200 10 alice
./login_stress 127.0.0.1 200 50 alice
./login_stress 127.0.0.1 200 100 alice
./login_stress 127.0.0.1 200 200 alice
```

Stop server:

```
Ctrl + C
```

---

## **Test Thread Version with different concurrency:**

Start thread server:

```bash
./login_server_thread
```

Run same tests:

```bash
./login_stress 127.0.0.1 200 10 alice
./login_stress 127.0.0.1 200 50 alice
./login_stress 127.0.0.1 200 100 alice
./login_stress 127.0.0.1 200 200 alice
```

Stop:

```
Ctrl + C
```

---

# **8️⃣ Capture Required Measurements**

## Your assignment demands screenshots + logs

## ✔ 1) **/usr/bin/time -v**

Fork:

```bash
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
```

Thread:

```bash
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
```

---

## ✔ 2) **htop screenshot**

Open:

```bash
htop
```

Look at:

- Processes count (for fork server)
- Threads count (for thread server)

Take a screenshot.

---

## ✔ 3) **ps -L -p <pid>**

Get PID:

```bash
ps aux | grep login_server
```

Then:

```bash
ps -L -p <PID>
```

Screenshot it.

---

## ✔ 4) **pmap -x <pid>**

```bash
pmap -x <PID>
```

Screenshot memory map.

---

# **9️⃣ Run Automatic Script (Optional)**

This script does most tests for you:

```bash
./run_tests.sh
```

Screenshots still needed manually.

---

# 🔟 Final Step — **Write Report**

✔ Tables
✔ Graphs (optional)
✔ Fork vs Thread comparison
✔ Latency
✔ Max RSS
✔ Context Switch
✔ Diagnostic checklist
✔ Final conclusion
