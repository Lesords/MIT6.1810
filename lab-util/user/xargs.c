#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char buf[512], *xargv[MAXARG], data;
  int i, pos = 0, xargc = 0;

  if (argc < 2) {
    fprintf(2, "xargs: xargs cmd ...\n");
    exit(1);
  }

  for (i = 1; i < argc; ++i) {
    xargv[xargc++] = argv[i];
  }

  while (read(0, &data, sizeof(char)) == 1) {
    if (data != '\n') {
      buf[pos++] = data;
      continue;
    }

    xargv[xargc] = (char *) malloc(pos + 1);
    memmove(xargv[xargc], buf, pos);
    pos = 0;

    int pid = fork();
    if (pid < 0) {
      fprintf(2, "xargs: fork error\n");
      exit(1);
    } else if (pid == 0) {
      argv[xargc + 1] = 0;
      if (exec(xargv[0], xargv) < 0) {
        fprintf(2, "xargs: exec error\n");
        exit(1);
      }
    } else {
      wait(0);
    }
  }

  exit(0);
}
