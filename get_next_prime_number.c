#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf(2, "Usage: get_next_prime <number>\n");
        exit();
    }
    int saved_ebx, number = atoi(argv[1]);
    asm volatile(
            "movl %%ebx, %0;"
            "movl %1, %%ebx;"
            : "=r" (saved_ebx)
            : "r"(number)
            );
    printf(1, "Next prime number is: %d\n", get_next_prime_number());
    asm("movl %0, %%ebx" : : "r"(saved_ebx));
    exit();
}