// implementar algoritmo 2
#include <iostream>
using namespace std;
#define n 20
typedef int tipochave;


struct Registro
{
    tipochave ch;
    float preco;
    struct validade{
    int dia;
    int mes;
    int ano;
}vencimento;
};
struct Lista {
    Registro A[n+1];
    int nroElem;
};
void inicializarLista (Lista *l)
{
    l->nroElem =0;
}
int TamanhoLista (Lista *l)
{
return l->nroElem ;
}

bool lista_cheia(Lista* l){
if(l->nroElem==n)return true;
return false;
}

bool InserirElem (Lista *l, Registro reg)
{
    if(lista_cheia(l)){return false;
}
    l->A[l->nroElem]=reg;
    l->nroElem++;
}
int buscaSentinela(Lista *l, tipochave ch1)
{
    int i=0;
    l->A[l->nroElem].ch = ch1;
    while(l->A[i].ch != ch1) {i++;}
    if (i == l->nroElem) {return -1; }
    else {return i; }
}

void algoritmo1(Lista* l) {
    for (int i = 0; i < l->nroElem - 1; ++i) {
        for (int j = l->nroElem - 1; j > i; --j) {
            if (l->A[j].ch < l->A[j - 1].ch) {
                Registro temporario = l->A[j];
                l->A[j] = l->A[j - 1];
                l->A[j - 1] = temporario;
            }
        }
    }
}


void exibirLista (Lista *l)
{
int i;
cout<< "A Lista contem os seguintes elementos: \n ";
 for (i=0; i< l->nroElem; i++)
{
cout<<"o produto " << l->A[i].ch <<"\tcusta " << l->A[i].preco <<"\ncom validade de "<<l->A[i].vencimento.dia<<"/"<<l->A[i].vencimento.mes<<"/"<<l->A[i].vencimento.ano<<'\n';
}
}
bool  excluirElemLista (tipochave ch1, Lista *l)
{
    int posElem, j;
    posElem  =buscaSentinela (l, ch1);
    if (posElem==-1) {return false;}
    else
    {
        for (j= posElem; j< l->nroElem; j++)
        { l->A[j]= l->A[j+1];}
        l->nroElem--;
    }
 return true;
}





int main(){

Registro prod;
Lista l1;
int a=1;
int ch, v;
inicializarLista(&l1);
while(a=!0){
cout << "Bem-vindo ao gerenciador da lista \n 0-Sair.\n 1-Inserir elemento.";
cout << "\n 2-Contar os elementos. \n 3-Buscar um elemento pela chave. \n 4-Exibir lista. \n ";
cout<<"5-utilizar o algoritmo 1 para ordenacao.\n 6- utilizar o algoritmo 2 para ordenacao.\n 7- remover um produto.\n 8- contar os produtos com chave maior que a ingressada.\n";

cin >> a;
switch(a){
case 0:
return 0;
break;
case 1:

cout << "ingresse a chave: ";
cin >> prod.ch;
cout << "ingresse o preço do produto: ";
cin >> prod.preco;
cout<<"ingresse a validade do produto: \n por exemplo: 12 03 20018\n\ninsira: ";
cin>>prod.vencimento.dia>>prod.vencimento.mes>>prod.vencimento.ano;
v = buscaSentinela(&l1, prod.ch);
if (v>0)
{
cout << "O código deste produto já está em uso\n";
}
else
{
   InserirElem(&l1, prod);
}
break;
case 2:
cout << "Quantia de produtos: " <<TamanhoLista(&l1)<<endl;
break;
case 3:
cout << "Código do produto: ";
int cod;
cin >> cod;
if (buscaSentinela(&l1, cod)==-1)
cout << "Produto não está na lista.\n";
else
cout << "o produto está na lista " ;
break;
case 4:
cout << "Lista: \nCódigo   |     Preço\n" ;
exibirLista(&l1);
break;
case 5:
   algoritmo1(&l1);
   cout<<"lista ordenada!\n\n";
   break;
case 6:
//algoritmo 2
break;
case 7:
cout << "Código do produto a ser excluído: ";

cin >> cod;
excluirElemLista(cod, &l1);
break;
case 8:
cout<<"insira a chave: "; //chave maior que p

default:
break;

}
cout << endl;
}
return 0;
}
