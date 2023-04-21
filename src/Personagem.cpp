#include "Personagem.hpp"

Personagem::Personagem(){
    this->vidas=10;
    this->itens=0;
}

void Personagem::subVida(){
    this->vidas=this->vidas - 1;
}

void Personagem::addVida(){
    this->vidas=this->vidas + 1;
}

void Personagem::addItem(){
    this->itens=this->itens + 1;
}

void Personagem::trocaItemVida(){
    if(this->itens >= 4){
        this->itens=this->itens - 4;
        this->vidas=this->vidas + 1;
    }    

}

int Personagem::getVidas(){
    return this->vidas;
}

int Personagem::getItens(){
    return this->itens;
}

void Personagem::imprimePersonagem(){
    cout << "Vidas: " << this->vidas;
    cout << "       Itens: " << this->itens; 
}
