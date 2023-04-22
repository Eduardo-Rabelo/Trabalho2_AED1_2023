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
		int ordem, numl=1, numc=1, pontos=0, contPerigo=0,contCasas=0;
		string *inicio,*final;
		vector<string> v;
		Personagem p;
		bool direita =false,baixo = false;
		vector<int> vb;
		int *iniciob,*finalb; 

	public:
	    
	    Matriz();
		Matriz(int ordem, vector<string> v);
		
		void setMatriz(int ordem, vector<string> v);
		
		void imprimeMatriz();
		
		void imprimeMatriz2();
		
		void percorreMatriz();
		
		vector<string> getMatriz();
		
		int getOrdem();
		
		int getNuml();
		
		int getNumc();
		
		int getContPerigo();
		
		int getPontos();
		
		void setNuml(int l);
		
		void setNumc(int c);
		
		bool getDireita();
		
		bool getBaixo();
		
		Personagem getPersonagem();
		
		void salvaMatriz(int contMatriz);
		
		void moverDireita(string **p,Personagem *pe, int *contc, int **b);
		
		void moverDiagonalDireitaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b);
		
		void moverDiagonalDireitaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b);
		
		void moverBaixo(string **p, Personagem *pe, int ordem, int *contl, int **b);
		
		void moverAlto(string **p, Personagem *pe, int ordem, int *contl, int **b);
		
		void moverEsquerda(string **p, Personagem *pe, int *contc, int **b);
		
		void moverDiagonalEsquerdaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b);
		
		void moverDiagonalEsquerdaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b);
		
};
#endif
