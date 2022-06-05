#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define PRODUCER 0
#define CONSUMER 1

#define BUFF_SIZE 5

int buf[BUFF_SIZE];
uint w_index = 0;
uint r_index = 0;

void
producer()
{
  int i = 0;
  while (i++ < 10) {
    reentrant_mutex_acquire(PRODUCER);
    printf(1, "producer acquired the lock.\n");
    printf(1, "PRODUCER: wrote item %d to index %d\n", w_index, w_index % BUFF_SIZE);
    reentrant_mutex_release(PRODUCER);
    printf(1, "producer released the lock.\n");
    w_index++;
  }
}

void
consumer()
{
  int i = 0;

  while(i++ < 10) {
    sleep(1);
    reentrant_mutex_acquire(CONSUMER);
    printf(1, "consumer acquired the lock.\n");
    printf(1, "CONSUMER: read item %d from index %d\n", r_index, r_index % BUFF_SIZE);
    reentrant_mutex_release(CONSUMER);
    printf(1, "consumer released the lock.\n");
    r_index++;
  }
}

int
main(int argc, char *argv[])
{
    int parent_pid = 0;
    int child_pid = 0;

    if (fork() == 0)
    {
        child_pid = getpid();
        reentrant_mutex_init(PRODUCER, child_pid);
        producer();
    }
    else
    {
        parent_pid = getpid();
        reentrant_mutex_init(CONSUMER, parent_pid);
        consumer();
    }

    wait();
    exit();
}