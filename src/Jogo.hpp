#include <iostream>
#include <filesystem>
#include "Matriz.hpp"
#include "Personagem.hpp"
#ifndef JOGO_HPP
#define JOGO_HPP
using namespace std;
class Jogo{
    private:
        Matriz fase;
        bool notfim = true;
        Personagem p;
        int numeroDaFase=1;
        int ordem=0,numMatriz=0,numl=1,numc=1,pontos=0,pontosDaPrimeiraMatriz=0;
    public:
        Jogo();
        void setFase(int ordem,vector<string>v);
        void jogar();
        void mudaFase();
        void salvaJogo();
    
};

#endif
