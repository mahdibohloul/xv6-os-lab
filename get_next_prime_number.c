#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) 
{
    int number = atoi(argv[1]);
    printf(1, "Next prime number is: %d\n", get_next_prime_number(number));
    exit();
} 