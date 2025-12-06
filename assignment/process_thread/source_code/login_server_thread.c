#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024
#define MAX_USERS 100

typedef struct {
  char username[50];
  char password[50];
} User;

User users[MAX_USERS];
int user_count = 0;

// Load users from users.txt
void load_users(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("Failed to open users.txt");
    exit(1);
  }
  while (fscanf(fp, "%s %s", users[user_count].username,
                users[user_count].password) == 2) {
    user_count++;
  }
  fclose(fp);
}

// Check login
int check_login(char *username, char *password) {
  for (int i = 0; i < user_count; i++) {
    if (strcmp(users[i].username, username) == 0 &&
        strcmp(users[i].password, password) == 0) {
      return 1;
    }
  }
  return 0;
}

// Thread handler
void *handle_client(void *arg) {
  int client_sock = *(int *)arg;
  free(arg);

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, sizeof(buffer));
  int n = read(client_sock, buffer, sizeof(buffer) - 1);
  if (n <= 0) {
    close(client_sock);
    return NULL;
  }

  char username[50], password[50];
  sscanf(buffer, "%s %s", username, password);

  if (check_login(username, password)) {
    write(client_sock, "OK", 2);
  } else {
    write(client_sock, "FAIL", 4);
  }

  close(client_sock);
  return NULL;
}

int main() {
  load_users("users.txt");

  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("Socket failed");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("Bind failed");
    exit(1);
  }

  listen(server_sock, 10);
  printf("Thread-based server listening on port %d...\n", PORT);

  while (1) {
    int *client_sock = malloc(sizeof(int));
    *client_sock = accept(server_sock, NULL, NULL);
    if (*client_sock < 0) {
      free(client_sock);
      continue;
    }

    pthread_t tid;
    pthread_create(&tid, NULL, handle_client, client_sock);
    pthread_detach(tid); // auto-free when done
  }

  close(server_sock);
  return 0;
}
