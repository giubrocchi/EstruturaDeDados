#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void func();

int main(void) {
  int ppid;

  signal(SIGINT, func);

  if(fork()==0)
  {
    printf("Processo filho %d esta executando\n", getpid());
    ppid = getppid(); //PID do processo pai
    if(kill(ppid, SIGINT)==-1)
      exit(1);
  }
  else
  {
    sleep(10);
    printf("Processo pai %d esta executando\n", getpid());
  }
  return 0;
}

void func()
{
  printf("Processo %d captou sinal SIGINT\n", getpid());
  signal(SIGINT, func); //caso tenha um outro sinal, ele continua captando
}
