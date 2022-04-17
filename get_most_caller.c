#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int sys_num = atoi(argv[1]);
    int most_pid_caller = get_most_caller(sys_num);
    printf(1, "The process who has called the syscall number %d has pid %d\n", sys_num, most_pid_caller);
    exit();
} 