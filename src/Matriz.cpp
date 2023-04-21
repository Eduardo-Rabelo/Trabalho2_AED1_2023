#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
#include "Matriz.hpp"
using namespace std;

Matriz::Matriz(){
    this->ordem=0;
    this->inicio=this->final=NULL;
}

Matriz::Matriz( int ordem, vector<string> v){
	this->ordem=ordem;
	
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	}

	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
}


void Matriz::setMatriz(int ordem, vector<string> v){
	
	this->ordem=ordem;
	this->v.clear();
	
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	}

	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
	this->pontos=0;
	this->direita =false;
	this->baixo = false;
}

void Matriz::imprimeMatriz(){
    int contl=1;
    string *p=this->inicio,*p2=this->final;
    
	while(p<=p2){
	 
	    cout << *p << " ";
	    
	    if(contl%ordem==0){
	        cout << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	cout << "\n\n\n";
}



void Matriz::imprimeMatriz2(){
    int contl=1;
    string *p=this->inicio,*p2=this->final;
    
	while(p<=p2){
	 
	    cout << *p << " ";
	    
	    if(contl%ordem==0){
	        cout << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	cout << "\n\n\nPontos da fase: " << this->pontos;
}

vector<string> Matriz::getMatriz(){
	return this->v;
}

int Matriz::getOrdem(){
	return this->ordem;
}

bool Matriz::getDireita(){
	return this->direita;
}

bool Matriz::getBaixo(){
	return this->baixo;
}

int Matriz::getNuml(){
	return this->numl;
}

int Matriz::getNumc(){
	return this->numc;
}

void Matriz::setNuml(int l){
	this->numl = l;
}

void Matriz::setNumc(int c){
	this->numc = c;
}














void Matriz::moverDireita(string **p,Personagem *pe, int *contc){
    *p = *p + 1;
    if(**p=="#"){
        *p = *p - 1;
        *contc = *contc - 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
        
    }
    *contc = *contc + 1;
}

void Matriz::moverDiagonalDireitaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl){
    *p = *p + 1 + ordem;
    if(**p=="#"){
       *p = *p - 1 - ordem;
       *contc = *contc -1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
        
    }
    *contc = *contc + 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalDireitaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl){
    *p = *p + 1 - ordem;
    if(**p=="#"){
       *p = *p - 1 + ordem;
       *contc = *contc - 1;
       *contl = *contl + 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
        
    }
    *contc = *contc + 1;
    *contl = *contl - 1;
    
}

void Matriz::moverBaixo(string **p, Personagem *pe, int ordem, int *contl){
    *p = *p + ordem;
    if(**p=="#"){
        *p = *p - ordem;
        *contl = *contl - 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
        
    }
    *contl = *contl + 1;
}

void Matriz::moverAlto(string **p, Personagem *pe, int ordem, int *contl){
	*p = *p - ordem;
	if(**p=="#"){
		*p = *p + ordem;
		*contl = *contl + 1;
	}
	else if(**p=="*"){
		pe->subVida();
	}
	else if(**p!="0"){
		pe->addItem();
		**p = to_string(stoi(**p) - 1);
		this->pontos++;
        
    	}
    	*contl = *contl - 1;

}

void Matriz::moverEsquerda(string **p, Personagem *pe, int *contc){
    *p = *p - 1;
    if(**p=="#"){
        *p = *p + 1;
        *contc = *contc + 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
        
    }
    *contc = *contc - 1;
}

void Matriz::moverDiagonalEsquerdaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl){
     *p = *p - 1 + ordem;
    if(**p=="#"){
       *p = *p + 1 - ordem;
       *contc = *contc + 1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
    }
    
    *contc = *contc - 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalEsquerdaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl){
     *p = *p - 1 - ordem;
    if(**p=="#"){
       *p = *p + 1 + ordem;
       *contc = *contc + 1;
       *contl = *contl + 1;
    }
    else if(**p=="*"){
        pe->subVida();
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        this->pontos++;
    }
    *contc = *contc - 1;
    *contl = *contl - 1;
}





void Matriz::percorreMatriz(){
    
    string *p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) ), *p2=this->final;
    int contl = this->numl, contc = this->numc, move=0;
    
    
	
    cout << "Posição Inicial: Fase[" << contl - 1 << "][" << contc - 1 << "] \n\n";
    cout << "CAMINHO:\n\n";
    *p="0";
    while(p<=p2){
    	

            move = rand()%8;
            if( this->p.getVidas() <= 0){
            	break;
            }
            
            this->p.trocaItemVida();
            
            if(move == 0 && contc < this->ordem){
                moverDireita(&p, &this->p, &contc);
                cout << "Direita, ";
            }
            else if(move== 1 && (p+ordem+1) < p2 && contc < this-> ordem){
                moverDiagonalDireitaBaixo(&p, &this->p, this->ordem, &contc, &contl);
                cout << "Diagonal direita para baixo, ";
            }
            else if((p+ordem <= p2) && move==2){
                moverBaixo(&p, &this->p, this->ordem, &contl);
                cout << "Baixo, ";
            }
            else if(move==3 && p > this->inicio && contc > 1){
                moverEsquerda(&p, &this->p, &contc);
                cout << "Esquerda, " ;
            }
            
            else if(move==4 && (p+this->ordem-1)<p2 && contc > 1 ){
                moverDiagonalEsquerdaBaixo(&p, &this->p, this->ordem, &contc, &contl );
                cout << "Diagonal esquerda para baixo, ";
            }
            
            else if(move==5 && (p - ordem + 1) > this->inicio && contc < this->ordem ){
                moverDiagonalDireitaAlto(&p, &this->p, this->ordem, &contc, &contl );
                cout << "Diagonal direita para cima, ";
            }
            
            else if(move == 6 && (p - this->ordem - 1) >= this->inicio && contc>1 ){
                moverDiagonalEsquerdaAlto(&p, &this->p, this->ordem, &contc, &contl );
                cout << "Diagonal esquerda para cima, ";
            }
            
            else if(move == 7 && (p - this->ordem) >= this->inicio){
            	moverAlto(&p, &this->p, this->ordem, &contl);
            	 cout << "Cima, ";
            }
            
            
            else{
            	
            	if( move == 0 && contc == this->ordem){
            		this->direita = true;
            		this->numl = contl;
            		cout << "numl: " << numl << "  ";
            		cout << "DIREITA(D): " << direita << "    ";
            		
            		break;
            	}
            	
            	else if( move == 1 && contl == this->ordem ){
            		
            		this->baixo = true;
            		if(contc < this->ordem){
            			this->numc = contc + 1;
            		}
            		else{
            			this->numc = contc;
            		}
            		cout << "numc: " << numc << " ";
           	 	cout << "BAIXO(dirB): " << baixo << "     ";
           	 	
           	 	break;
            		
            		
            	}
            	
            	else if( move == 1 && contc == this->ordem ){
            		this->direita = true;
            		if(contl == this->ordem){
            			this->numl = contl;
            		}
            		else{
            			this->numl = contl + 1;
            		}
            		cout << "numl: " << numl << " ";
           	 	cout << "Direita(dirB): " << direita << "     ";
           	 	
           	 	break;
            	}
            	
            	else if( move == 2 && contl == this->ordem ){
            		this->baixo = true;
            		this->numc = contc;
            		cout << "numc: " << numc << " ";
           	 	cout << "BAIXO(B): " << baixo << "   ";
           	 	
           	 	break;
            	}
            	
            	else if(move==4 && contl == this->ordem){
          
            		this->baixo = true;
            		if(contc > 1){
            			this->numc = contc - 1;
            		}
            		else{
            			this->numc = contc;
            		}
            		
            		cout << "numc: " << numc << " ";
           	 	cout << "BAIXO(esqB): " << baixo << "     ";
           	 	
           	 	break;
            		
            	}
            	
            	
            	else if(move == 5 && contc == this->ordem){
            		this->direita = true;
            		if(contl == 1 ){
            			this->numl = contl;
            		}
            		else{
            			this->numl = contl - 1;
            		}
            		
            		cout << "numl: " << numl << " ";
           	 	cout << "Direita(dirA): " << direita << "     ";
           	 	
           	 	break;
            		
            	}    	
            }
            
            
            
            
     
    }
    cout << "\n\n\n";
    
}

Personagem Matriz::getPersonagem(){
    return this->p;
}

void Matriz::salvaMatriz(int contMatriz){
	
	string s="dataset/Matriz",a;
	stringstream ss;
	
	ss << contMatriz;
	ss >> a;
	s.append(a).append(".txt");
	ofstream file(s);
	
	int contl=1;
	string *p=this->inicio,*p2=this->final;
	
	while(p<=p2){
	
	    file << *p << " ";
	    
	    if(contl%ordem==0){
	        file << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	
	file.close();
	

}

int Matriz::getPontos(){
	return this->pontos;
}



