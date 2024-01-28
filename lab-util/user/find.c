#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
isDir(char *path) {
  struct stat st;

  if (stat(path, &st) < 0) {
    return 0;
  }

  return st.type == T_DIR;
}

void
find(char *path, char *name) {
  char buf[512], *p;
  int fd;
  struct dirent de;

  if ((fd = open(path, O_RDONLY)) < 0) {
    fprintf(2, "find: cannot open %s\n", path);
    return ;
  }

  if (strlen(path) + 1 + DIRSIZ + 1 > sizeof(buf)) {
    fprintf(2, "find: path too long\n");
    return ;
  }
  strcpy(buf, path);
  p = buf + strlen(buf);
  *p++ = '/';

  while (read(fd, &de, sizeof(de)) == sizeof(de)) {
    if (de.inum == 0) {
      continue;
    }

    if (strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) {
      continue;
    }

    memmove(p, de.name, DIRSIZ);
    p[DIRSIZ] = 0;

    if (isDir(buf)) {
      find(buf, name);
      continue;
    }

    if (strcmp(de.name, name) == 0) {
      printf("%s\n", buf);
    }
  }
}

int
main(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(2, "usage: find directory file\n");
    exit(1);
  }

  if (isDir(argv[1]) == 0) {
    fprintf(2, "find: wrong path %s\n", argv[1]);
    exit(1);
  }

  find(argv[1], argv[2]);

  exit(0);
}
