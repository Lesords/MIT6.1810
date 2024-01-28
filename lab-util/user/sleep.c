#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  if (argc <= 1) {
    fprintf(2, "usage: sleep ticks\n");
    exit(1);
  }

  for(i = 1; i < argc; i++){
    sleep(atoi(argv[i]));
    printf("(nothing happens for a little while)\n");
  }
  exit(0);
}
