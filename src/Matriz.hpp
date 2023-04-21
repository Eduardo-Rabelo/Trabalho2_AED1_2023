#include <iostream>
#include <fstream>
#include <sstream>
#include "Personagem.hpp"
#include <vector>
#include <time.h>
#ifndef MATRIZ_HPP
#define MATRIZ_HPP
using namespace std;

class Matriz{
	private:
		int ordem, numl=1, numc=1, pontos=0;
		string *inicio,*final;
		vector<string> v;
		Personagem p;
		bool direita =false,baixo = false;// esquerda = false, cima = false, 

	public:
	    
	    Matriz();
		Matriz(int ordem, vector<string> v);
		
		void setMatriz(int ordem, vector<string> v);
		
		void imprimeMatriz();
		
		void percorreMatriz();
		
		vector<string> getMatriz();
		
		int getOrdem();
		
		int getNuml();
		
		int getNumc();
		
		int getPontos();
		
		void setNuml(int l);
		
		void setNumc(int c);
		
		bool getDireita();
		
		//bool getEsquerda();
		
		//bool getCima();
		
		bool getBaixo();
		
		Personagem getPersonagem();
		
		void salvaMatriz(int contMatriz);
		
		void moverDireita(string **p,Personagem *pe, int *contc);
		
		void moverDiagonalDireitaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl);
		
		void moverDiagonalDireitaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl);
		
		void moverBaixo(string **p, Personagem *pe, int ordem, int *contl);
		
		void moverAlto(string **p, Personagem *pe, int ordem, int *contl);
		
		void moverEsquerda(string **p, Personagem *pe, int *contc);
		
		void moverDiagonalEsquerdaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl);
		
		void moverDiagonalEsquerdaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl);
		
};
#endif
