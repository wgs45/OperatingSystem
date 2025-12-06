#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

typedef struct {
  char *server_ip;
  char *username;
  char *password;
} ClientInfo;

void *send_login(void *arg) {
  ClientInfo *info = (ClientInfo *)arg;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    return NULL;

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, info->server_ip, &server_addr.sin_addr);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    close(sock);
    return NULL;
  }

  char buffer[BUFFER_SIZE];
  snprintf(buffer, sizeof(buffer), "%s %s", info->username, info->password);
  write(sock, buffer, strlen(buffer));

  memset(buffer, 0, sizeof(buffer));
  read(sock, buffer, sizeof(buffer) - 1);
  printf("%s\n", buffer);

  close(sock);
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <server_ip> <total_requests> <concurrency> <username>\n",
           argv[0]);
    return 1;
  }

  char *server_ip = argv[1];
  int total_requests = atoi(argv[2]);
  int concurrency = atoi(argv[3]);
  char *username = argv[4];

  int i = 0;
  while (i < total_requests) {
    int batch =
        (total_requests - i > concurrency) ? concurrency : total_requests - i;
    pthread_t threads[batch];
    for (int j = 0; j < batch; j++) {
      ClientInfo *info = malloc(sizeof(ClientInfo));
      info->server_ip = server_ip;
      info->username = username;
      info->password = "1234";
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
