#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


#define MUTEX 0
#define FULL 1
#define EMPTY 2

#define BUFF_SIZE 5

int buf[BUFF_SIZE];
uint w_index = 0;
uint r_index = 0;


void
producer()
{
  int i = 0;
  while (i++ < 10) {
    sleep(8);
    sem_acquire(EMPTY);
    sem_acquire(MUTEX);
    printf(1, "producer acquired the lock.\n");

    printf(1, "PRODUCER: wrote item %d to index %d\n", w_index, w_index % BUFF_SIZE);

    sem_release(MUTEX);
    sem_release(FULL);
    printf(1, "producer released the lock.\n\n");
    w_index++;
  }
}

void
consumer()
{
  int i = 0;

  while(i++ < 10) {
    sleep(10);
    sem_acquire(FULL);
    sem_acquire(MUTEX);
    printf(1, "consumer acquired the lock.\n");

    printf(1, "CONSUMER: read item %d from index %d\n", r_index, r_index % BUFF_SIZE);

    sem_release(MUTEX);
    sem_release(EMPTY);
    printf(1, "consumer released the lock.\n\n");
    r_index++;
  }
}

int
main(int argc, char *argv[])
{
  sem_init(MUTEX, 1);
  sem_init(FULL, BUFF_SIZE);
  sem_init(EMPTY, BUFF_SIZE);

  if (fork() == 0)
    consumer();
  else
    producer();

  wait();

  exit();
}