#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;
typedef int tipochave;

struct elemento
{
    tipochave chave;
    //outros campos
};

struct No   // cada no possui um elemneto e o endereço de outro nó
{
    elemento valor;
    No *prox;   // ponteiro para outro No   
};              //poderiamos usar class tambem 

class FilaD
{
    private:
     No *inicio;
     No *fim;
    public:
        FilaD();
        bool vazia();
        void inserir(elemento e);
        tipochave remover();
        void mostrar();
        int gettamanho();
        bool busca(tipochave ch);
    
};

int main()
{
    
FilaD f1;
elemento e1
tipochave ch1;
int menu;
cout << "[FAÇA UMA ESCOLHA]\n";

do{
    cout << "0. para sair do gerenciador.\n";
         << "1. para inserir produto.\n"
         << "2. para remover um elemento na fila.\n"
         << "3. para mostrar elementos da fila.\n"
         << "4. para ver tamanho da fila.\n"
         << "5. para buscar por um elemento.\n"
         << "6. para destruir a fila.\n"
    cin >> menu;
    
    switch (menu)
    {
        case 0:
        cout << "[FIM]  \n";
        break;
        
        case 1:
        cout << "insira a chave do elemento a ser inserido\n";
        cin >> e1.chave; f1.inserir(e1);
        break;
        
        case 2:
        
        f1.remover();
        cout << "O elemento foi removido!\n";
        break;
        
        case 3:
        cout << "[Nossa fila] :\n";
        f1.mostrar();
        break;
        
        case 4:
        cout << "O tamanho da fila e: [" << f1.gettamanho() << "]\n";
        break;
        
        case 5: 
        cout << "Digite a chave do elemento a ser procurado\n";
        cin >> ch1;
        if (f1.busca(ch1)==1)
        {   cout << "o elemento jaj esta na fila\n";}
        else
        {
            cout << "O elemento nao esta na fila :/\n";
        }
        break;
        
        case 6:
        reiniciarFila(&f1);
        cout << "A fila foi destruida\n";
        break;
        
        default:
        cout << "Opção invalida :(\n";
        break;
        
        
    }
}
    return 0;
}


////////////////////-METODOS-//////////////////////////

FilaD::FilaD;
{
    inicio= NULL;
    fim = NULL;
};

int FilaD::gettamanho()
{
    int tam = 0;
    No *Notemp;
    NoTemp = inicio;
    while(NoTemp!=NULL)
    {
        tam = tam + 1;
        NoTemp = NoTemp->prox;
    }
    return tam;
}

void FilaD::mostrar()
{
    int tam = 0;
    No *Notemp;
    NoTemp = inicio;
    cout << "Os elementos da fila sao:\n";
    while(NoTemp!=NULL)
    {   cout << "------------------------\n"
        cout << NoTemp->valor.chave << "\n";
        NoTemp = NoTemp->prox;
    }
}

void FilaD::inserir(elemento e)
{
    if(busca (e.chave)==1)
    {
        cout << " O elemento com chave " << e.chave << " ja esta na fila\n";
    }
    else
    {
        No *NoNovo;
        NoNovo=(No*) malloc(sizeof(elmento));
        NoNovo->valor = e;
        NoNovo->prox=NULL;
        
        if (fim == NULL)
        {
            inicio = NoNovo;
            fim = NoNovo;
        }
        else
        {
            fim->prox=NoNovo;
            fim=fim->prox;
        }
        cout << "o  Elemento com chave " << e.chave << " foi inserido! :)\n";
    }
}

tipochave FilaD::remover()
{
    int a;
    a=vazia();
    if(a == 1)
    {
        cout << "Nao foi possivel remover: a fila ja esta vazia\n";
        cout << "tente outra opção\n";
        return 0;
    }
    else
    {
    No *Notemp;
    NoTemp = inicio;
    tipochave ch;
    ch=inicio->valor.chave;
    delete NoTemp;
    if(iniico==NULL)
    {
        fim=NULL;
    }
    return ch;
    }
}

bool FilaD::vazia()
{
    if(inicio==NULL){return true;}
    else {return false;}
}

bool FilaD::busca (tipochave ch)
{
    No *Notemp;
    NoTemp = inicio;
    while(NpTemp!=NULL)
    {
        if(NoTemp->valor.chave==ch)
        {
            return true;
        }
        NoTemp=NoTemp->prox;
    }
    cout << "Elemento nao encontrado\n";
    return false;
}


