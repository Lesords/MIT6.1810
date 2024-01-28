#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void primes(int read_fd) {
  int prime;

  if (read(read_fd, &prime, sizeof(int)) == 0) {
    close(read_fd);
    return ;
  }
  printf("prime %d\n", prime);

  int fds[2];
  int pid;

  if (pipe(fds) == -1) {
    fprintf(2, "primes: pipe error\n");
    return;
  }

  pid = fork();
  if (pid < 0) {
    fprintf(2, "primes: fork error\n");
    return;
  } else if (pid == 0) {
    close(fds[1]);
    primes(fds[0]);
  } else {
    int data;

    close(fds[0]);
    while (read(read_fd, &data, sizeof(int))) {
      if (data % prime == 0) {
        continue;
      }

      if (write(fds[1], &data, sizeof(int)) == -1) {
        fprintf(2, "primes: write error\n");
        break;
      }
    }
    close(fds[1]);
    wait(0);
  }
}

int
main(int argc, char *argv[])
{
  int i;
  int pid, fds[2];

  if (pipe(fds) == -1) {
    fprintf(2, "primes: pipe error\n");
    exit(1);
  }

  pid = fork();
  if (pid < 0) {
    fprintf(2, "primes: fork error\n");
    exit(1);
  } else if (pid == 0) {
    close(fds[1]);
    primes(fds[0]);
  } else {
    close(fds[0]);

    for (i = 2; i <= 35; i++) {
      if(write(fds[1], &i, sizeof(int)) == -1) {
        fprintf(2, "pingpong: write error\n");
        exit(1);
      }
    }
    close(fds[1]);
    wait(0);
  }

  exit(0);
}
