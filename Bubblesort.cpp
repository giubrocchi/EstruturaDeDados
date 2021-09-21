#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

#define N 10

using namespace std;

void bubble(int v[], int *ccomp, int *ctroca);
void bubble2(int v[], int *ccomp, int *ctroca);

int main() {
  int i, j, v[N], ccomp=0, ctroca=0;
  struct tms t1, t2;
  clock_t inicio, atual;

  for(i=0; i<N; i++)
    v[i]=i;
  v[0] = 2;
  v[1] = 1;
  v[2] = 0;

  inicio = times(&t1);
  bubble2(v, &ccomp, &ctroca);
  atual = times(&t2);

  cout<<"\n";
  for(i=0; i<N; i++)
    cout<<v[i]<<" ";

  cout<<"\nTotal de comparacoes: "<<ccomp;
  cout<<"\nTotal de trocas: "<<ctroca;
  cout<<"\nTempo total de execucao: "<<(float)(atual-inicio)/100;
  cout<<"\nExecucao em user: "<<t2.tms_utime-t1.tms_utime<<"\t\tExecucao em kernel: "<<t2.tms_stime-t1.tms_stime<<"\n";
  return 0;
}

void bubble(int v[], int *ccomp, int *ctroca)
{
  int i, j, aux, trocai;
  for(i=0; i<N; i++)
  {
    trocai = *ctroca;
    for(j=N-1; j>i; j--)
    {
      (*ccomp)++;
      if(v[j]<v[j-1])
      {
        aux=v[j];
        v[j]=v[j-1];
        v[j-1]=aux;
        (*ctroca)++;
      }
    }
    if(trocai == *ctroca)
      break;
  }
}

void bubble2(int v[], int *ccomp, int *ctroca)
{
  int i, j, aux, trocai, pos;
  for(i=0; i<N; i++)
  {
    trocai = *ctroca;
    for(j=N-1; j>i; j--)
    {
      (*ccomp)++;
      if(v[j]<v[j-1])
      {
        aux=v[j];
        v[j]=v[j-1];
        v[j-1]=aux;
        (*ctroca)++;
        pos = j;
      }
    }
    if(trocai == *ctroca)
      break;
    if(trocai+1 == *ctroca && pos == i+1)
      break;
  }
}
