#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
  if (sock < 0) {
    perror("Socket failed");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connect failed");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  snprintf(buffer, sizeof(buffer), "%s %s", username, password);
  write(sock, buffer, strlen(buffer));

  memset(buffer, 0, sizeof(buffer));
  read(sock, buffer, sizeof(buffer) - 1);
  printf("Server Response: %s\n", buffer);

  close(sock);

  return 0;
}
