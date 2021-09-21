#include <iostream>

struct no{
  int cod;
  struct no *esq, *dir;
};

using namespace std;

void incluir(struct no **raiz, int n);
void remover(struct no **raiz, int n);
int mydel(struct no **x);
int buscar(struct no *raiz, int n);
int comparar(struct no *a, struct no *b);
void uniao(struct no **u, struct no *a, struct no *b);
void inter(struct no **i, struct no *a, struct no *b);
void emOrdem(struct no *raiz);
void unir(struct no **u, struct no *a);
void f (struct no *raiz)
{
 if (raiz != NULL){
    f (raiz->dir);
    f(raiz->esq);
    printf("%d ", raiz->cod);
    f(raiz->dir);
  }
}

int main() {
  struct no *raiz = NULL;
  int opcao;
  struct no *comp = NULL;
  incluir(&comp, 6);
  incluir(&comp, 8);
  incluir(&comp, 2);
  incluir(&comp, 12);
  system("clear");
  do
  {
    cout<<"\n-- MANIPULACAO DE ARVORES --\n";
    cout<<"\n01 - Inserir\n02 - Retirar\n03 - Buscar\n04 - Comparar\n05 - Uniao\n06 - Interseccao\n07 - emOrdem\n00 - Sair";
    cout<<"\n\nInsira sua opcao: ";
    cin>>opcao;

    switch(opcao)
    {
      case 1:
      {
        int n;
        cout<<"Numero a ser inserido: ";
        cin>>n;
        incluir(&raiz, n);
      }break;

      case 2:
      {
        int n;
        cout<<"Numero a ser retirado: ";
        cin>>n;
        remover(&raiz, n);
      }break;

      case 3:
      {
        int n;
        cout<<"Numero a ser buscado: ";
        cin>>n;
        if(buscar(raiz, n))
          cout<<"\nNumero presente";
        else
          cout<<"\nNumero NAO presente";
      }break;

      case 4:
      {
        cout<<"\nArvore = ";
        emOrdem(raiz);
        cout<<"\nArvore 2 = ";
        emOrdem(comp);
        if(comparar(raiz, comp))
          cout<<"\nArvore iguais";
        else
          cout<<"\nArvore diferentes";
      }break;

      case 5:
      {
        struct no *uni = NULL;
        uniao(&uni, raiz, comp);
        cout<<"\nArvore = ";
        emOrdem(raiz);
        cout<<"\nArvore 2 = ";
        emOrdem(comp);
        cout<<"\nUniao = ";
        emOrdem(uni);
      }break;

      case 6:
      {
        struct no *inte = NULL;
        inter(&inte, raiz, comp);
        cout<<"\nArvore = ";
        emOrdem(raiz);
        cout<<"\nArvore 2 = ";
        emOrdem(comp);
        cout<<"\nInterseccao = ";
        emOrdem(inte);
      }break;

      case 7:
      {
        cout<<"\nArvore = ";
        emOrdem(raiz);
      }break;

      case 8:
      {
        f(raiz);
      }break;

      case 0: break;

      default: cout<<"\nOpcao invalida!";
    }
    cout<<"\n\nPressione enter para continuar. . .";
    cin.ignore();
    int c = getchar();
    system("clear");
  }while(opcao!=0);
}

void incluir(struct no **raiz, int n)
{
  if(*raiz == NULL)
  {
    *raiz = (no *)malloc(sizeof(no));
    if(*raiz == NULL)
    {
      cout<<"\nHeap overflow";
      return;
    }
    (*raiz)->cod = n;
    (*raiz)->esq = (*raiz)->dir = NULL;
  }
  else if(n < (*raiz)->cod)
    incluir(&(*raiz)->esq, n);
  else if(n > (*raiz)->cod)
    incluir(&(*raiz)->dir, n);
}

void remover(struct no **raiz, int n)
{
  if(*raiz != NULL)
  {
    if((*raiz)->cod == n)
    {
      if((*raiz)->esq == NULL)
        *raiz = (*raiz)->dir;
      else if((*raiz)->dir == NULL)
        *raiz = (*raiz)->esq;
      else
        (*raiz)->cod = mydel(&(*raiz)->esq);
      return;
    }
    else if(n < (*raiz)->cod)
      remover(&(*raiz)->esq, n);
    else
      remover(&(*raiz)->dir, n);
  }
  else
    cout<<"\nElemento nao presente";
}

int mydel(struct no **x)
{
  if((*x)->dir != NULL)
    return mydel(&(*x)->dir);
  else
  {
    struct no *aux = *x;
    int n = (*x)->cod;
    (*x) = (*x)->esq;
    free(aux);
    return n;
  }
}

int buscar(struct no *raiz, int n)
{
  if(raiz == NULL)
    return 0;
  else if(raiz->cod == n)
    return 1;
  else if(n < raiz->cod)
    return buscar(raiz->esq, n);
  else
    return buscar(raiz->dir, n);
}

int comparar(struct no *a, struct no *b)
{
  if(a == NULL && b == NULL)
    return 1;
  else if(a == NULL || b == NULL)
    return 0;
  else if(a->cod == b->cod)
    return (comparar(a->esq, b->esq) && comparar(a->dir, b->dir));
  else
    return 0;
}

void uniao(struct no **u, struct no *a, struct no *b)
{
  if(a != NULL)
    unir(&(*u), a);
  if(b != NULL)
    unir(&(*u), b);
}

void unir(struct no **u, struct no *a)
{
  if(a != NULL)
  {
    incluir(&(*u), a->cod);
    unir(&(*u), a->esq);
    unir(&(*u), a->dir);
  }
}

void inter(struct no **i, struct no *a, struct no *b)
{
  if(a != NULL)
  {
    if(buscar(b, a->cod))
      incluir(&(*i), a->cod);
    inter(&(*i), a->esq, b);
    inter(&(*i), a->dir, b);
  }
}

void emOrdem(struct no *raiz)
{
  if(raiz != NULL)
  {
    emOrdem(raiz->esq);
    cout<<raiz->cod<<" ";
    emOrdem(raiz->dir);
  }
}
