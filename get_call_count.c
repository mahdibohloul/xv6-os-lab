#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int number = atoi(argv[1]);
    printf(1, "system call number %d has been called %d times.\n", number, get_call_count(number));
    exit();
} 