#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int pid, fds_fa[2], fds_son[2];
  char data[5];

  if (pipe(fds_fa) == -1 || pipe(fds_son) == -1) {
    fprintf(2, "pingpong: pipe error\n");
    exit(1);
  }

  pid = fork();
  if (pid < 0) {
    fprintf(2, "pingpong: fork error\n");
    exit(1);
  } else if (pid == 0) {
    close(fds_fa[1]);
    close(fds_son[0]);

    if(read(fds_fa[0], data, sizeof(data)) == -1) {
      fprintf(2, "pingpong: read error\n");
      exit(1);
    }
    printf("%d: received %s\n", getpid(), data);

    strcpy(data, "pong");
    if(write(fds_son[1], data, sizeof(data)) == -1) {
      fprintf(2, "pingpong: write error\n");
      exit(1);
    }

    close(fds_fa[0]);
    close(fds_son[1]);
  } else {
    close(fds_fa[0]);
    close(fds_son[1]);

    strcpy(data, "ping");
    if(write(fds_fa[1], data, sizeof(data)) == -1) {
      fprintf(2, "pingpong: write error\n");
      exit(1);
    }

    if(read(fds_son[0], data, sizeof(data)) == -1) {
      fprintf(2, "pingpong: read error\n");
      exit(1);
    }
    printf("%d: received %s\n", getpid(), data);
    wait(0);

    close(fds_fa[1]);
    close(fds_son[0]);
  }

  exit(0);
}
