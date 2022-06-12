#include <sys/types.h> // opendir closedir
#include <dirent.h> // opendir readdir closedir
#include <stdio.h> // puts perror
#include <errno.h> // errno perror

/*
See `man readdir`. As `d_type` is not POSIX, this may not work on
systems other than Linux and BSD and on certain file systems.
*/

int
main(const int argc, const char**argv) {
  DIR *dirp = opendir(argc >= 2 ? argv[1] : ".");
  if (!dirp) {
    perror("opendir");
    return 1;
  }

  errno = 0;
  const struct dirent *entry;
  while ((entry = readdir(dirp))) {
    if (DT_REG == entry->d_type) {
      puts(entry->d_name);
    }
    errno = 0;
  }

  if (errno) {
    perror("readdir");
    closedir(dirp);
    return 1;
  } else {
    closedir(dirp);
    return 0;
  }
}
