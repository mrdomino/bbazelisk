#define _COSMO_SOURCE
#include "libc/calls/calls.h"
#include "libc/dce.h"
#include "libc/log/bsd.h"
#include "libc/mem/mem.h"
#include "libc/runtime/runtime.h"
#include "libc/stdio/stdio.h"
#include "libc/x/x.h"

int main(int argc, char* argv[]) {
  char pathbuf[8192];
  char *bazelisk = commandv("bazelisk", pathbuf, sizeof(pathbuf));
  if (bazelisk != NULL) {
    execv(bazelisk, argv);
    err(1, "execv");
  }
  char *sys;
  if (IsLinux()) {
    sys = "linux";
  } else if (IsWindows()) {
    sys = "windows";
  } else if (IsXnu()) {
    sys = "darwin";
  } else {
    errx(1, "unsupported os");
  }
  char *self = xdirname(GetProgramExecutableName());
  snprintf(pathbuf, sizeof(pathbuf), "%s/bazelisk-%s-%s", self, sys, _ARCH_NAME);
  free(self);
  execv(pathbuf, argv);
  err(1, "execv(%s)", pathbuf);
}
