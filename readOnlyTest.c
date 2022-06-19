#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  char * x = sbrk(0);
  sbrk(PGSIZE);
  *x = 5;
  mprotect(x, 1);
  int y = fork();
  if(y == 0){
    printf(1, "Protected the value: %d \n", *x);
    munprotect(x, 1);
    *x = 10;
    printf(1, "Unprotecting it: %d \n", *x);
    exit();
  }
  else if(y > 0){
    wait();
    *x = 10;
    exit();
  }
 exit();
}
