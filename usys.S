#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(get_next_prime_number)
SYSCALL(get_call_count)
SYSCALL(get_most_caller)
SYSCALL(wait_for_process)
SYSCALL(print_processes)
SYSCALL(change_queue)
SYSCALL(set_bjf_process)
SYSCALL(set_bjf)
SYSCALL(sem_init)
SYSCALL(sem_acquire)
SYSCALL(sem_release)
SYSCALL(reentrant_mutex)
SYSCALL(mprotect)
SYSCALL(munprotect)
