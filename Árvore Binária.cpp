#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <unistd.h> // biblioteca função sleep
using namespace std;

typedef int tipochave;

struct No
{  
    tipochave chave;
    float preco;
    struct No *esquerda;
    struct No *direita;
};

typedef No *PN; // ponteiro para nó

PN inicializar()
{return (NULL);}

PN CriarNovoNo (tipochave ch1, float preco)
{
PN novoNo=(PN)malloc(sizeof(No));
  novoNo->esquerda=NULL;
  novoNo->direita=NULL;
  novoNo->chave=ch1;
  novoNo->preco = preco;
return novoNo;
}

PN adicionarNoNaArv (PN r, PN no)
{

if(r==NULL) {return (no);}
if (no->chave<r->chave)
{r->esquerda = adicionarNoNaArv (r->esquerda, no); }
else
{ r->direita = adicionarNoNaArv ( r->direita, no); }
return (r);
}

PN busca(tipochave ch, PN r)
{
    if (r == NULL) {return (NULL);}
    if (r->chave == ch) {return (r);}
    if (r->chave > ch) {return busca (ch, r->esquerda);}
    return busca (ch, r->direita);
}

int ContarNos (PN r)
{
int tam = 0;
if (r==NULL) {return 0;}

else
{ tam = ContarNos(r->esquerda) +1+ ContarNos (r->direita);}
return tam;
}

void mostrar( PN r)
{
  if(r!=NULL)
  {
    cout << "[CHAVE]: " << r->chave << "\n";
    cout << "[PRECO]: " << r->preco << "\n";
    cout << "-------------------------\n";
   
    mostrar (r->esquerda);
    mostrar (r ->direita);
  }
}

int main() {
 
  tipochave ch;
  int menu, tam;
  float preco;

  PN raiz = inicializar();

     do{
         cout << "\n[GERENCIADOR ARVORE BINARIA]\n\n"
              << "[0] [Para sair]\n"
              << "[1] [Para inserir produto]\n"
              << "[2] [Para contar quantidade de produtos]\n"
              << "[3] [Para busca binaria pela chave primaria]\n"
              << "[4] [Para mostrar os produtos]\n";
         cin >> menu;
         
         switch(menu)
         {
            case 0:
             // sair
             cout << "[FINALIZANDO...]\n";
             usleep(500000);
             cout << "[FIM]";
            break;
             
            case 1:
             // inserir
             cout << "=> Insira a chave do no a ser inserido\n";
              cin >> ch;
             cout << "=> Insira o preço do elemento inserido\n";
              cin >> preco;
             PN p1;
             p1 = busca(ch, raiz);
             if(p1 != NULL){cout << "=> ja existe um no com essa chave.\n Tente outra.\n";}
             else
             {
             PN no;
                no = CriarNovoNo(ch, preco);
                raiz = adicionarNoNaArv(raiz ,no);  
                cout << "=> Elemento iserido com sucesso!\n";
             }
             usleep(500000);
            break;
             
            case 2:
             // contar
             tam = ContarNos(raiz);
             cout << "=> A arvore tem : [" << tam << "] nos\n";
             usleep(500000);
            break;
           
            case 3:
            // busca binaria por chave
            cout << "=> Ingresse a chave do no a ser procurado\n";
             cin >> ch;
             PN p;
             p = busca (ch , raiz);
             if (p == NULL) {cout << "=> o no de chave: [" << ch <<  "] nao esta na arvore\n";}
             else {cout << "=> O no  esta no endereco: [" << p << "]\n";}
             usleep(500000);
            
            break;
           
            case 4:
            // mostrar
            cout << "=> os elemetos da arvore sao: \n";
            mostrar(raiz);
            cout << "\n";
            usleep(500000);
            break;

            default:
            // opção invalida
            cout << "[OPCAO INVALIDA!] \n => insira outra opcao\n";
            usleep(500000);
             break;
             
         }
         
     }while(menu!=0);

    return 0;
}