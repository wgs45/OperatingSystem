### **Step 1: Understanding the Assignment**

1. **Client-Server Login System**
   - A **server** waits for clients to connect.
   - A **client** sends `username password`.
   - The server checks it against `users.txt`.
   - The server responds with `OK` or `FAIL`.
   - After the response, the connection closes.

2. **Two Server Models**
   - **Fork version:** Each client connection is handled by a **new process**. (`login_server_fork.c`)
   - **Thread version:** Each client connection is handled by a **new thread**. (`login_server_thread.c`)

3. **Stress Testing**
   - Send many requests concurrently (10, 50, 100, 200).
   - Measure:
     - Latency (average, max, P95)
     - CPU/memory usage
     - Context switches
     - Success/Timeout rates

4. **Report Questions**
   - Compare process vs thread in **resources**, **latency**, **memory**, **context switches**.
   - Explain **bottlenecks**, troubleshooting, and possible optimizations.

---

### **Step 2: Plan of Action**

#### **A. Server Implementation**

1. **Fork-based server (`login_server_fork.c`)**
   - Use `socket()` to create a TCP socket.
   - Use `bind()` and `listen()`.
   - When a client connects:

     ```c
     pid_t pid = fork();
     if (pid == 0) {
         // child process: handle login request
         // check users.txt
         // send OK or FAIL
         exit(0);
     } else {
         // parent process: continue listening
     }
     ```

2. **Thread-based server (`login_server_thread.c`)**
   - Same socket setup.
   - When a client connects:

     ```c
     pthread_t tid;
     pthread_create(&tid, NULL, handle_client, (void*)&client_socket);
     pthread_detach(tid); // optional: auto-free resources when done
     ```

   - `handle_client` function does the login check.

---

#### **B. Client Implementation (`login_client.c`)**

- Connects to server.
- Sends `username password`.
- Receives `OK` or `FAIL`.

---

#### **C. Stress Test (`login_stress.c`)**

- Run many concurrent clients to simulate load.
- Arguments: `total_requests` + `concurrency`.
- Could use `fork()` or threads in stress test for parallel clients.

---

### **Step 3: Measurements**

1. **CPU/Memory**

   ```bash
   /usr/bin/time -v ./login_server_thread
   top / htop
   pmap -x <pid>
   ps -L -p <pid>  # show threads
   ```

2. **Latency**
   - Record response times for clients.

3. **Context switches**
   - Check `voluntary` and `involuntary` from `time -v`.

---

### **Step 4: Report Questions (Hints)**

1. **System Resource Comparison**
   - Fork → more memory per connection (processes don’t share memory).
   - Threads → lighter, shared memory.

2. **Performance & Latency**
   - Threads usually faster due to less overhead.
   - Fork can have higher context switches.

3. **Troubleshooting**
   - Check logs, resource usage.
   - Check number of connections and blocking issues.

4. **Conclusion**
   - Use **process** if isolation is important.
   - Use **thread** for efficiency.
   - Thread pools/event-driven → scalable under high load.

---

### **Step 5: How to Start Coding**

1. **Read `users.txt` into memory** once at server startup (array or hash map).
2. **Fork version:**
   - Accept client.
   - Fork.
   - In child → handle login → exit.
   - In parent → close client socket and continue.

3. **Thread version:**
   - Accept client.
   - Create pthread → handle login.
   - Detach thread.

4. **Client:**
   - Connect → send → recv → close.

5. **Stress test:**
   - Create many client threads or processes.
