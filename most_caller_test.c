#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char *argv[]) 
{
    //SYS_fork
    printf(1, "The process who has called the FORK syscall the most has pid %d\n", get_most_caller(SYS_fork));
    //SYS_write
    printf(1, "The process who has called the WRITE syscall the most has pid %d\n", get_most_caller(SYS_write));
    //SYS_wait
    printf(1, "The process who has called the WAIT syscall the most has pid %d\n", get_most_caller(SYS_wait));

    exit();
} 