#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int count = atoi(argv[1]);
  
  int sum = reentrant_mutex(count);

  printf(1, "Sum is %d\n", sum);

  exit();
}