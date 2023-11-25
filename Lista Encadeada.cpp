//aluno: Brenno Pereira dos Santos
//matricula: 222037773

#include <iostream>
#include <cstdlib>
using namespace std;

typedef int TIPOCHAVE;

struct Registro
{
    TIPOCHAVE Chave;
    float preco;
   
};

struct Elemento
{
    Registro reg;
    Elemento *prox;
};

typedef Elemento * PONT;

struct Lista
{
   PONT inicio;
};

void inicializarLista (Lista *l)
{l->inicio=NULL;}

int tamanho (Lista *l)
{
    PONT end = l->inicio;
    int tam=0;
    while (end!= NULL)
    {
        tam++;
        end=end->prox;
    }
    return tam;
}


void ExibirLista(Lista *l)
{
  PONT end = l->inicio;
  cout<<"nossa lista: \n";
  while (end!= NULL)
    {   cout << "---------------------\n";
        cout <<"chave: " << end->reg.Chave << "\n";
        cout << "preco: " << end->reg.preco << "\n";
        end=end->prox;
    }
}

PONT buscaSeq (Lista *l, TIPOCHAVE ch)
{
    PONT pos=l->inicio;
    while(pos !=NULL)
    {
        if(pos->reg.Chave==ch)
        {
            cout << "O produto esta na lista!\n";
            return pos;
        }
        pos=pos->prox;
    }
    cout << "O produto nao esta na lista! :/\n";
    return NULL;
}


PONT buscaOrd (Lista* l, TIPOCHAVE ch)
{
PONT pos = l->inicio;

    while (pos !=NULL && pos->reg.Chave < ch)
    {
        
        if ( pos->reg.Chave==ch)
        {
            cout << "O produto esta na lista!\n";
            return pos; 
        }
        pos=pos->prox;
    }
    cout << "O produto nao esta na lista!\n";
    return NULL;
}

PONT buscaSeqAux(Lista *l, TIPOCHAVE ch, PONT *ant)
{
    *ant= NULL;
    PONT atual= l->inicio;
        while((atual!= NULL) && (atual->reg.Chave<ch))
        {
            *ant = atual;
            atual = atual->prox;
        }
        if((atual!= NULL) && (atual->reg.Chave==ch))
        {
            return atual;
        }
        return NULL;
}

bool inserirOrd (Lista *l, Registro reg)
{
    TIPOCHAVE ch = reg.Chave;
    PONT ant, i;
    i=buscaSeqAux ( l, ch, &ant);
    if(i != NULL) 
    {
        cout << "\n [AVISO!]: O elemento ja esta na lista!\n";
        return false;}
    i = (PONT) malloc (sizeof(Elemento));
    i->reg= reg;
    
    if(ant == NULL)
    {
        l->inicio=i;
    }
    else
    {
        i->prox=ant->prox;
        ant->prox= i;
    }
    return true;
}

bool Excluir (Lista * l, TIPOCHAVE ch)
{
    PONT ant, i;
    i=buscaSeqAux (l, ch, &ant); 
        if (i ==NULL) { return false;} 
      else { ant->prox= i->prox; } 
        if (ant ==NULL) { l->inicio=i->prox;}
    free (i); 
    return true; 
}

void ReinicializarLista (Lista * l)
{ 
    PONT end= l->inicio;
    while( end!=NULL)
    { 
        PONT apagar=end;
        end= end->prox ;
        free( apagar);
    }

l->inicio= NULL;
}

int main(){
    int ch;
    Elemento a;
    Lista l1;
    inicializarLista(&l1);
    int t;
    
    cout << t << "\n";
    Registro R1, R2;

    ExibirLista(&l1);
    PONT anterior;
    int menu = true;
    
    cout << "[GERENCIADOR DE LISTA]\n";
    
    while(menu = true)
    {
        cout << "\n[PRESSIONE]\n"
             << "1. para inserir produto.\n"
             << "2. para contar os produtos na lista.\n"
             << "3. para procurar produto pela chave.\n"
             << "4. para mostrar os produtos.\n"
             << "5. para excluir produto da lista.\n"
             << "6. para reiniciar lista\n"
             << "0. para sair do gerenciador.\n";
             
             cin >> menu;
             switch(menu)
             {
                 case 1:
                 // inserir
                 cout << "Insira  a chave do elemento que deseja inserir\n";
                 cin >> a.reg.Chave;
                 cout << "Insira o preço\n";
                 cin >> a.reg.preco;
                 inserirOrd(&l1, a.reg);
                    
                 break;
                 
                 case 2:
                 // contar
                 t=tamanho(&l1);
                 cout << "\n-------------------------"
                      << "\nO tamanho e: [" << t <<"]\n"
                      << "--------------------------\n";   
                 break;
                 
                 case 3:
                 // procurar pela chave
                 cout << "Insira a chave do elemento que deseja procurar:\n";
                 cin >> ch;
                 buscaSeq(&l1, ch);
                 
                 break;
                 
                 case 4:
                 // mostrar
                 ExibirLista(&l1);
                 
                 break;
                 
                 case 5:
                 //excluir
                 cout << "Insira  a chave do elemento que deseja excluir\n";
                 cin >>ch;
                 Excluir(&l1, ch);
                 
                 break;
                 
                 case 6:
                 ReinicializarLista(&l1);
                 cout << "A lista foi reinicializada!\n";
                 
                 break;
                 
                 case 0:
                 cout << "Voce saiu do gerenciador :/" << endl;
                 return false;
                 
                 break;
             }
    }
    
return 0;
}
