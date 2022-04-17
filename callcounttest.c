#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char *argv[]) 
{
    int pid1 = fork();
    if(pid1 < 0) {
        printf(1, "fork failed\n");
        exit();
    }
    if(pid1 == 0) {
        int write_count = get_call_count(SYS_write);
        int fork_count = get_call_count(SYS_fork);
        printf(1, "for child1 fork has been called %d and write has been called %d\n", fork_count, write_count);
    } else {
        int pid2 = fork();
        if(pid2 == 0) {
            int write_count = get_call_count(SYS_write);
            int fork_count = get_call_count(SYS_fork);
            printf(1, "for child1 fork has been called %d and write has been called %d\n", fork_count, write_count);
        } else {
            int write_count = get_call_count(SYS_write);
            int fork_count = get_call_count(SYS_fork);
            printf(1, "for parent fork has been called %d and write has been called %d\n", fork_count, write_count);
        }
    }
}