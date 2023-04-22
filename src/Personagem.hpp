#include <iostream>
#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
using namespace std;

class Personagem{
    private:
        int vidas=10,itens=0;
    public:
        Personagem();
        void subVida();
        void addVida();
        void addItem();
        void trocaItemVida();
        int getVidas();
        int getItens();
        void imprimePersonagem();
};



#endif
