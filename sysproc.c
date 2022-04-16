#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_get_next_prime_number(void)
{
  int prime;
  if (argint(0, &prime) < 0) {
    return -1;
  }
  if(prime == 1) {
    return 2;
  }
  int found = 0;
  while(!found) {
    prime = prime + 1;
    for (int i=2 ; i<prime ; i++) {
      if (prime%i == 0) {
        break;
      }
      else if (i == prime - 1) {
        return prime;
      }
    }
  }
  return -1;
}

int
sys_get_call_count(void)
{
  int number;
  if (argint(0, &number) < 0) {
    return -1;
  }
  struct proc *curproc = myproc();
  return curproc -> syscall_count[number-1];
}

int
sys_get_most_caller(void)
{
  int most_called = 0;
  int syscall = 0;
  struct proc *curproc = myproc();
  for (int i=0 ; i < 100 ; i++) {
    if(curproc->syscall_count[i] > most_called) {
      most_called = curproc->syscall_count[i];
      syscall = i;
    }
  }
  return (syscall+1);  
}

int
sys_wait_for_process(void)
{
  int child_pid;
  if (argint(0, &child_pid) < 0) {
    return -1;
  }
  struct proc* curproc = myproc();
  curproc -> pid = child_pid;
  wait();
  return 0;
}
