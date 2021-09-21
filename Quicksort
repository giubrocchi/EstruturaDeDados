#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

#define N 100000

using namespace std;

void quick(int v[], int esq, int dir);

long ccomp = 0;
int ctroca = 0;

int main() {
  int i, j, v[N];
  struct tms t1, t2;
  clock_t inicio, atual, tempo;

  for(i=0; i<N; i++)
    v[i]=rand()%200000;

  inicio = times(&t1);
  quick(v, 0, N-1);
  atual = times(&t2);

  cout<<"\nTotal de comparacoes: "<<ccomp;
  cout<<"\nTotal de trocas: "<<ctroca;
  cout<<"\nTempo total de execucao: "<<(float)(atual-inicio)/100;
  cout<<"\nExecucao em user: "<<t2.tms_utime-t1.tms_utime<<"\t\tExecucao em kernel: "<<t2.tms_stime-t1.tms_stime<<"\n";
  return 0;
}

void quick(int v[], int esq, int dir)
{
  int pivo=v[(dir+esq)/2], aux, i, j, auxp[3];
  if(v[esq]<pivo && v[esq]>v[dir]) pivo = v[esq];
  else if(v[esq]>pivo && v[esq]<v[dir]) pivo = v[esq];
  else if(v[dir]>pivo && v[esq]>v[dir]) pivo = v[dir];
  else if(v[dir]<pivo && v[dir]>esq) pivo = v[dir];
  i = esq;
  j = dir;
  do
  {
    while(v[i]<pivo)
    {
      i++;
      ccomp++;
    }
    while(v[j]>pivo)
    {
      j--;
      ccomp++;
    }
    if(i<=j)
    {
      aux=v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
      ctroca++;
    }
  }while(i<j);
  if(esq<j)
    quick(v, esq, j);
  if(i<dir)
    quick(v, i, dir);
}
