## **1️⃣ Fork-based Server — `login_server_fork.c`**

_(Same as the skeleton I sent, already ready for testing.)_

---

## **2️⃣ Thread-based Server — `login_server_thread.c`**

_(Same as the skeleton I sent, ready to run.)_

---

## **3️⃣ Simple Client — `login_client.c`**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("Socket failed"); exit(1); }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s %s", username, password);
    write(sock, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer)-1);
    printf("Server Response: %s\n", buffer);

    close(sock);
    return 0;
}
```

**Test it:**

```bash
./login_client 127.0.0.1 alice 1234
```

---

## **4️⃣ Stress Test — `login_stress.c`**

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 12345
#define BUFFER_SIZE 1024

typedef struct {
    char *server_ip;
    char *username;
    char *password;
} ClientInfo;

void* send_login(void *arg) {
    ClientInfo *info = (ClientInfo*)arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return NULL;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, info->server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(sock);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s %s", info->username, info->password);
    write(sock, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer)-1);
    // Uncomment to see each response:
    // printf("%s\n", buffer);

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <server_ip> <total_requests> <concurrency> <username>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int total_requests = atoi(argv[2]);
    int concurrency = atoi(argv[3]);
    char *username = argv[4];

    int i = 0;
    while (i < total_requests) {
        int batch = (total_requests - i > concurrency) ? concurrency : total_requests - i;
        pthread_t threads[batch];
        for (int j = 0; j < batch; j++) {
            ClientInfo *info = malloc(sizeof(ClientInfo));
            info->server_ip = server_ip;
            info->username = username;
            info->password = "1234"; // default password for testing
            pthread_create(&threads[j], NULL, send_login, info);
        }
        for (int j = 0; j < batch; j++) {
            pthread_join(threads[j], NULL);
        }
        i += batch;
    }

    printf("Stress test completed.\n");
    return 0;
}
```

**Run stress test:**

```bash
./login_stress 127.0.0.1 100 10 alice
```

- 100 total requests, concurrency 10, username `alice` with password `1234`.

---

## **5️⃣ Automated Test Script — `run_tests.sh`**

```bash
#!/bin/bash

echo "Starting fork server..."
./login_server_fork &
FORK_PID=$!
sleep 1

echo "Running stress test on fork server..."
./login_stress 127.0.0.1 200 50 alice

echo "Collecting fork server stats..."
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
ps -L -p $FORK_PID
pmap -x $FORK_PID

kill $FORK_PID
sleep 1

echo "Starting thread server..."
./login_server_thread &
THREAD_PID=$!
sleep 1

echo "Running stress test on thread server..."
./login_stress 127.0.0.1 200 50 alice

echo "Collecting thread server stats..."
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
ps -L -p $THREAD_PID
pmap -x $THREAD_PID

kill $THREAD_PID
```

- This script runs both servers, performs stress tests, and collects basic resource usage info.

---

## **6️⃣ Report Guide**

| Section                    | Points to Include                                                                                    |
| -------------------------- | ---------------------------------------------------------------------------------------------------- |
| System Resource Comparison | # of processes/threads, Max RSS (threads lighter), context switches                                  |
| Performance & Latency      | Threads usually lower latency, fork higher memory usage, possible timeouts at high concurrency       |
| Troubleshooting            | Use `top`, `htop`, `ps -L -p`, check logs, check for blocked clients                                 |
| Conclusion                 | Use processes for isolation, threads for efficiency; consider thread pool/event-driven for high load |
