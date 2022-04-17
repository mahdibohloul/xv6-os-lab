#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int pid1 = fork();
    if(pid1 == 0) {
        for(int i=0; i<10000000; i++){};
        printf(1, "First run me!\n");
        exit();
    } else {
        int pid2 = fork();
        if (pid2 == 0) {
            wait_for_process(pid1);
            printf(1, "Then run me\n");
            exit();
        } else {
            wait();
            printf(1, "At last run me!\n");
            exit();
        }
    }   
} 