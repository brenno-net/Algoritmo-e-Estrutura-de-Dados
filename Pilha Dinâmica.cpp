#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;
typedef int tipochave;

struct elemento
{
    tipochave chave;
    // outros campos
};

struct No   // cada no possui um elemento(como os campos) e o endereço de outro no
{
    elemento valor;
    No *anterior;
};

class PilhaD
{
    private:
    No *NoTopo; // ponteiro pra o no notopo, o endereço do no no topo sabendo onde staq o topo podemos acessar todos os nos


    public:
    PilhaD(); // criadora
    ~PilhaD(); // destrutora
    bool vazia();// 1 vazia 0 nao vazia
    void inserir elemento(elemento e); // push
    tipochave remover();// pop
    void mostrar();
    int gettamanho();
    bool busca(tipochave ch);
}

PilhaD::PilhaD()
{
    NoTopo = NULL; // criamos o no topo ou seja um endereço para receber null
}
void PIlhaD::inserir (elemento e)
{
    if(busca (e.chave) == 1)
    {
        cout << "o elemento com chave " << e.chave << " ja esta na pilha\n";
    }
    else
    {
        No *NoTopo;
    }
}

PIlhaD::inserir(elemento e)
{
      if(busca (e.chave) == 1)
    {
        cout << "o elemento com chave " << e.chave << " ja esta na pilha\n";
    }
    else
    {
        No *NoNovo=new No;
        NoNovo
    }
}

tipochave PIlhaD::remover()
{
    int a;
    a=vazia();
    if(a==1)
    
    {
        cout << "Não foi possivel remover: a pilha ja esta vazia\n";
        cout << "tente outra opção\n";
        return 0;
    }
    else
    {
        No *NoTemp;
        NoTemp=NoTopo;
        tipochave ch;
        ch=NoTopo->valor.chave;
        NoTopo=NoTopo->anterior;
        delete NoTemp;
        return ch;
    }
}

void PIlhaD::mostrar()
{
    No *NoTemp;
    NoTemp=NoTopo;
    cout << "Os elemento da pilha são:\n";
    cout << "{\n";
    while(NoTemp!=NULL)
    {
        cout << NoTemp->valor.chave << "\n";
        NoTemp=NoTemp->anterior;
        
    }
    cout << "}\n";
}

int PIlhaD::gettamanho()
{
    int tamanho=0;
    No *NoTemp;
    NoTemp=NoTopo;
     while(NoTemp!=NULL)
    {
        tamanho=tamanho+1;
        NoTemp=NoTemp->anterior;
        
    }
    return tamanho;
}

bool PIlhaD:: busca (tipochave ch)
{
     No *NoTemp;
    NoTemp=NoTopo;
    while(NoTemp!=NULL)
    {
        if(NoTemp->valor.chave==ch)
        {
            return true;
        }
        NoTemp=NoTemp->anterior;
        
    }
    cout << "elemento nao encontrado"
}

PilhaD::~PilhaD()
{
    No *NoTemp;
    while(NoTopo!=NULL)
    {
        NoTemp=NoTopo;
        NoTopo=NoTopo->anterior;
        delete NoTemp;
    }
}
int main()
{
 
 PIlhaD p1;
 elemento e1;
 tipochave ch1;
 int menu;
 
    cout << "faça ujma escolha\n";
    do{
        cout << "digite:\n";
        cout << "0 para terminar\n";
        cout << "1. para inserir elemento.\n";
        cout << "2. para remover um elemento na pilha.\n";
        cout << "3. para mostrar os elementos,\n";
        cout << "4. para ver tamanho da pilha\n";
        cout << "5. para buscar;\n";
        cout << "6. para destruir a pilha;\n";
        cin >> menu;
        switch(menu)
        {
            case 0: cout << "[FIM]\n";
            break;
            
            case 1: cout << "Digite o elemento que qweur inserir\n";
            cin >> e1.chave;
            p1.inserir (e1);
            break;
            
            case 2: cout << p1.remover() << "\n";
            break;
            
            case 3: p1.mostrar();
            break;
            
            case 4: cout << "O tamanho da pilha e: [" << p1.gettamanho(); << "]\n";
            break;
            
            case 5: cout << "digite a chave a ser procurado\n";
            cin >> ch1;
            if (p1.busca(ch1)==1)
            
        }
        
    }

    return 0;
}