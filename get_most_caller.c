#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int most_caller = get_most_caller();
    printf(1, "The most called system call number is %d\n", most_caller);
    exit();
} 