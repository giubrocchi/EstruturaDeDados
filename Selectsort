#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

#define N 100000

using namespace std;

void select(int v[], double *ccomp, int *ctroca);

int main() {
  int i, j, v[N], ctroca=0;
  double ccomp=0;
  struct tms t1, t2;
  clock_t inicio, atual, tempo;

  for(i=0; i<N; i++)
    v[i]=rand()%200000;

  inicio = times(&t1);
  select(v, &ccomp, &ctroca);
  atual = times(&t2);

  cout<<"\nTotal de comparacoes: "<<ccomp;
  cout<<"\nTotal de trocas: "<<ctroca;
  cout<<"\nTempo total de execucao: "<<(float)(atual-inicio)/100;
  cout<<"\nExecucao em user: "<<t2.tms_utime-t1.tms_utime<<"\t\tExecucao em kernel: "<<t2.tms_stime-t1.tms_stime<<"\n";
  return 0;
}

void select(int v[], double *ccomp, int *ctroca)
{
  int i, j, aux, menor;
  for(i=0; i<N-1; i++)
  {
    menor = v[i];
    aux = i;
    for(j=i+1; j<N; j++)
    {
      (*ccomp)++;
      if(menor>v[j])
      {
        menor = v[j];
        aux = j;
      }
    }
    if(v[i]!=menor)
    {
      v[aux] = v[i];
      v[i] = menor;
      (*ctroca)++;
    }
  }
}
