#include <iostream>
#include <time.h> 

#define SIZE 10
using namespace std;

struct No{
    No *prox;
    No *ant;
    int dado;
};

class Lista{
public:
    int tam;
    No *cabeca;
    
    Lista(){
        cabeca = new No;
        cabeca->prox = cabeca->ant =nullptr;
        tam = 0;
    }
    
    ~Lista(){
        Esvazia();
    }
    
    void Insere(int valor){
        No *celula = new No;
        celula->dado = valor;
        celula->ant = cabeca;
        celula->prox = cabeca->prox;
        if(tam>0)
            cabeca->prox->ant = celula;
        cabeca->prox = celula;
		tam++;
    }
    
    void Esvazia(){
        No *aux = cabeca, *atual;
        while(aux != nullptr)
        {
            atual = aux;
            aux = aux->prox;
            delete atual;
        }
    }

    //1a
    void Imprime(){
        cout << "Tamanho: " << tam << endl;
        for(No *aux = cabeca->prox; aux != nullptr; aux = aux->prox) cout << aux->dado << ' ';
        cout << endl;
    }
};

int main(){
    srand(time(0));
    Lista lista;
    for(int i=0; i<SIZE; i++)
        lista.Insere(rand()%100);
    lista.Imprime();
    return 0;
}
