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


void Matriz::setMatriz(int ordem, vector<string> v){


	
	
	int x=0;
	this->ordem=ordem;
	this->v.clear();
	this->vb.clear();
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	    this->vb.push_back(0);
	    
	}
	
	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
	this->iniciob=&this->vb[0];
	this->finalb=&this->vb[(ordem*ordem)-1];
	this->pontos=0;
	this->direita =false;
	this->baixo = false;
	this->contCasas = 0;
	this->contPerigo = 0;
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
	cout << "	Perigos enfrentados: " << this->contPerigo;
	cout << "	Casas percorridas ao menos uma vez nessa matriz: " << this->contCasas;
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

int Matriz::getContPerigo(){
	return this->contPerigo;
}

void Matriz::setNuml(int l){
	this->numl = l;
}

void Matriz::setNumc(int c){
	this->numc = c;
}
















void Matriz::moverDireita(string **p,Personagem *pe, int *contc, int **b){
    *p = *p + 1;
    *b = *b + 1;
    **b=1;
    if(**p=="#"){
        **b=0;
        *p = *p - 1;
        *b = *b - 1;
        *contc = *contc - 1;
        
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
        
    }
    *contc = *contc + 1;
}

void Matriz::moverDiagonalDireitaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b){
    *p = *p + 1 + ordem;
    *b = *b + 1 + ordem;
    **b=1;
    if(**p=="#"){
       **b=0;
       *p = *p - 1 - ordem;
       *b = *b - 1 - ordem;
       *contc = *contc -1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
        
    }
    *contc = *contc + 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalDireitaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b){
    *p = *p + 1 - ordem;
    *b = *b + 1 - ordem;
    **b = 1;
    if(**p=="#"){
       **b = 0;
       *p = *p - 1 + ordem;
       *b = *b - 1 + ordem;
       *contc = *contc - 1;
       *contl = *contl + 1;
       
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
        
    }
    *contc = *contc + 1;
    *contl = *contl - 1;
    
}

void Matriz::moverBaixo(string **p, Personagem *pe, int ordem, int *contl, int **b){
    *p = *p + ordem;
    *b = *b + ordem;
    **b = 1;
    if(**p=="#"){
    	**b = 0;
        *p = *p - ordem;
        *b = *b - ordem;
        *contl = *contl - 1;
        
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
        
    }
    *contl = *contl + 1;
}

void Matriz::moverAlto(string **p, Personagem *pe, int ordem, int *contl, int **b){
	*p = *p - ordem;
	*b = *b - ordem;
	**b=1;
	if(**p=="#"){
		**b=0;
		*p = *p + ordem;
		*b = *b + ordem;
		*contl = *contl + 1;
	}
	else if(**p=="*"){
		pe->subVida();
		this->contPerigo++;
		**b = 1;
	}
	else if(**p!="0"){
		pe->addItem();
		**p = to_string(stoi(**p) - 1);
		**b = 1;
		this->pontos++;
        
    	}
    	*contl = *contl - 1;

}

void Matriz::moverEsquerda(string **p, Personagem *pe, int *contc, int **b){
    *p = *p - 1;
    *b = *b - 1;
    **b=1;
    if(**p=="#"){
    	**b=0;
        *p = *p + 1;
        *b = *b + 1;
        *contc = *contc + 1;
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b =1;
        this->pontos++;
        
    }
    *contc = *contc - 1;
}

void Matriz::moverDiagonalEsquerdaBaixo(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b){
     *p = *p - 1 + ordem;
     *b = *b - 1 + ordem;
     **b=1;
    if(**p=="#"){
       **b=0;
       *p = *p + 1 - ordem;
       *b = *b + 1 - ordem;
       *contc = *contc + 1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
    }
    
    *contc = *contc - 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalEsquerdaAlto(string **p, Personagem *pe, int ordem, int *contc, int *contl, int **b){
     *p = *p - 1 - ordem;
     *b = *b - 1 - ordem;
     **b=1;
    if(**p=="#"){
   	**b=0;
       *p = *p + 1 + ordem;
       *b = *b + 1 + ordem;
       *contc = *contc + 1;
       *contl = *contl + 1;
    }
    else if(**p=="*"){
        pe->subVida();
        this->contPerigo++;
        **b = 1;
    }
    else if(**p!="0"){
        pe->addItem();
        **p = to_string(stoi(**p) - 1);
        **b = 1;
        this->pontos++;
    }
    *contc = *contc - 1;
    *contl = *contl - 1;
}





void Matriz::percorreMatriz(){
    
    string *p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) ), *p2=this->final;
    int contl = this->numl, contc = this->numc, move=0;
    int *b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
   
    
	
    cout << "Posição Inicial: Fase[" << contl - 1 << "][" << contc - 1 << "] \n\n";
    cout << "CAMINHO:\n\n";
    *p="0";
    *b=1;
    while(p<=p2){
    	

            move = rand()%8;
            if( this->p.getVidas() <= 0){
            	break;
            }
            
            this->p.trocaItemVida();
            
            if(move == 0 && contc < this->ordem){
                moverDireita(&p, &this->p, &contc, &b);
                cout << "Direita, ";
            }
            else if(move== 1 && (p+ordem+1) < p2 && contc < this-> ordem){
                moverDiagonalDireitaBaixo(&p, &this->p, this->ordem, &contc, &contl, &b);
                cout << "Diagonal direita para baixo, ";
            }
            else if((p+ordem <= p2) && move==2){
                moverBaixo(&p, &this->p, this->ordem, &contl, &b);
                cout << "Baixo, ";
            }
            else if(move==3 && p > this->inicio && contc > 1){
                moverEsquerda(&p, &this->p, &contc, &b);
                cout << "Esquerda, " ;
            }
            
            else if(move==4 && (p+this->ordem-1)<p2 && contc > 1 ){
                moverDiagonalEsquerdaBaixo(&p, &this->p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal esquerda para baixo, ";
            }
            
            else if(move==5 && (p - ordem + 1) > this->inicio && contc < this->ordem ){
                moverDiagonalDireitaAlto(&p, &this->p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal direita para cima, ";
            }
            
            else if(move == 6 && (p - this->ordem - 1) >= this->inicio && contc>1 ){
                moverDiagonalEsquerdaAlto(&p, &this->p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal esquerda para cima, ";
            }
            
            else if(move == 7 && (p - this->ordem) >= this->inicio){
            	moverAlto(&p, &this->p, this->ordem, &contl, &b);
            	 cout << "Cima, ";
            }
            
            
            else{
            	
            	if( move == 0 && contc == this->ordem){
            		this->direita = true;
            		this->numl = contl;
            		cout << "DIREITA" ;
            		
            		break;
            	}
            	
            	else if( move == 1 && contl == this->ordem ){
            		
            		this->baixo = true;
            		if(contc < this->ordem){
            			this->numc = contc + 1;
            			cout << "DIAGONAL DIREITA PRA BAIXO";
            		}
            		else{
            			this->numc = contc;
            			cout << "BAIXO";
            		}
           	 	
           	 	break;
            		
            		
            	}
            	
            	else if( move == 1 && contc == this->ordem ){
            		this->direita = true;
            		if(contl == this->ordem){
            			this->numl = contl;
            			cout << "DIREITA" ;
            		}
            		else{
            			this->numl = contl + 1;
            			cout << "DIAGONAL DIREITA PRA BAIXO";
            		}
           	 	
           	 	break;
            	}
            	
            	else if( move == 2 && contl == this->ordem ){
            		this->baixo = true;
            		this->numc = contc;
           	 	cout << "BAIXO";
           	 	
           	 	break;
            	}
            	
            	else if(move==4 && contl == this->ordem){
          
            		this->baixo = true;
            		if(contc > 1){
            			this->numc = contc - 1;
            			cout << "DIAGONAL ESQUERDA PARA BAIXO";
            		}
            		else{
            			this->numc = contc;
            			cout << "BAIXO";
            		}
            		
           	 	break;
            		
            	}
            	
            	
            	else if(move == 5 && contc == this->ordem){
            		this->direita = true;
            		if(contl == 1 ){
            			this->numl = contl;
            			cout << "DIREITA";
            		}
            		else{
            			this->numl = contl - 1;
            			cout << "DIAGONAL DIREITA PARA CIMA";
            		}
            		
           	 	
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
	
	vector <string> vecs;
	string str,aux;
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
	

	s="dataset/MatrizB";
	ss << contMatriz;
	ss >> a;
	s.append(a).append(".txt");
	ifstream File3(s);
	
	while(getline(File3,str)){
		for(int i=0; i < str.size(); i++){
			
			if(str[i] == ' ' && aux!=""){
				vecs.push_back(aux);
				aux="";
			}
			else if(str[i] != ' '){
				aux.push_back(str[i]);
				
			}
		}
	}
	
	
	for(int i=0;i<vecs.size();i++){
		if(vecs[i]== "1"){
			this->vb[i]=1;
		}
	}
	
	
	
	
	contl=1;
	
	ofstream file2(s);
	int *pb=this->iniciob,*pb2=this->finalb;
	
	while(pb<=pb2){
	
	    file2 << to_string(*pb) << " ";
	    if(*pb == 1){
	    	this->contCasas++;
	    }
	    if(contl%this->ordem==0){
	        file2 << "\n";
	    }
	    
	    contl++;
	    pb++;
	}
	file2.close();
	

}

int Matriz::getPontos(){
	return this->pontos;
}



