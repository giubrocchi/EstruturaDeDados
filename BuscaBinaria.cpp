#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define N 1023

using namespace std;

void busca(int x, int v[], int esq, int dir, int cont);

int main()
{
  int i, x, v[N], esq=0, dir=N-1, cont=0;

  cout<<"v = [";
  for(i=0; i<N; i++)
  {
    v[i]=2*i;
    cout<<v[i]<<" ";
  }

  cout<<"]\n\nQual valor deseja encontrar? ";
  cin>>x;

  busca(x, v, 0, N-1, cont);
}

void busca(int x, int v[], int esq, int dir, int cont)
{
  if(esq>dir)
  {
    cout<<"\nElemento NAO encontrado\nNumero de comparacoes: "<<cont<<"\n";
    return;
  }
  int pivo = (dir+esq)/2;
  if(x==v[pivo])
  {
    cout<<"\nElemento encontrado!\nNumero de comparacoes: "<<cont+1<<"\n";
    return;
  }
  if(x<v[pivo])
    busca(x, v, esq, pivo-1, cont+1);
  else
    busca(x, v, pivo+1, dir, cont+1);
}
