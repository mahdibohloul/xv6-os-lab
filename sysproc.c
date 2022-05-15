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
    int number = myproc()->tf->ebx;
    return get_next_prime_number(number);
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
  int sys_num;
  if (argint(0, &sys_num) < 0) {
    return -1;
  }

  return get_most_caller(sys_num);
}

int
sys_wait_for_process(void)
{
  int pid;
  if (argint(0, &pid) < 0) {
    return -1;
  }
  return wait_for_process(pid);
}

int
sys_print_processes(void){
  printp();
  return 0;
}

int
sys_change_queue(void){
  int pid;
  int queue;
  argint(0, &pid);
  argint(1, &queue);
  changeq(pid, queue);
  return 0;
}

int
sys_set_bjf_process(void){
  return 0;
}

int
sys_set_bjf(void){
  return 0;
}


