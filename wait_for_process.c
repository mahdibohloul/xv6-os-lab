#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int pid = atoi(argv[1]);
    printf(1, "We're waiting for process with pid number %d\n", pid);
    wait_for_process(pid);
    exit();
} 