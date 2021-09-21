#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <signal.h>

struct tms t1, t2;
clock_t inicio, atual;

void f2();
void f5();

int main(void)
{
  inicio = times(&t1);

  if(fork()==0)
  {
    signal(SIGALRM, f2);
    alarm(2);
    for(;;);
  }
  else
  {
    signal(SIGALRM, f5);
    alarm(5);
    for(;;);
  }

  return 0;
}

void f2()
{
  printf("\nFilho captou um sinal de alarme: %d\n", getpid());
  atual = times(&t2);
  printf("Tempo de execução: %.2f\n", (float)(atual-inicio)/100);
  printf("Total: %u\t\tExecução user: %u\t\tExecução kernel: %u\n", (int)(atual-inicio), (int)(t2.tms_utime - t1.tms_utime), (int)(t2.tms_stime - t1.tms_stime));
  signal(SIGALRM, f2);
  alarm(2);
}

void f5()
{
  printf("\nPai captou um sinal de alarme: %d\n", getpid());
  time_t mytime;
  mytime= time(NULL);
  struct tm tm=*localtime(&mytime);
  printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
  printf("Hora: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("%s", ctime(&mytime));
  signal(SIGALRM, f5);
  alarm(5);
}
