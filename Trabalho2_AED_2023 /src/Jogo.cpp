#include <iostream>
#include "Jogo.hpp"
using namespace std;

Jogo::Jogo(){
	//int o,n;
	stringstream s;
	string str,aux;
	
	vector<string> vecs,vs;
	
	ifstream File("dataset/input.data");

	getline(File,str);
	
	//////////////////////////////////////////////////////////////
	
		for(int j=0;j<str.size();j++){
		
			if(str[j] == ' ' && aux!="" ){
				vecs.push_back(aux);
				aux="";
			}
			else if(str[j] != ' '){
				aux.push_back(str[j]);
			}
			
			
		}
		vecs.push_back(aux);
		
	aux="";
	
	
	
	

	
	
	
	cout << "\n\n\n";
	//o=stoi(str);
	this->ordem = stoi(vecs[0]);
	cout << "this->ordem: " << this->ordem;
	//s<<str[4];
	//s>>n;
	this->numMatriz = stoi(vecs[2]);
	//cout << "this->numMatriz: " << this->numMatriz << "\n\n\n\n";
	
	vecs.clear();
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////////
	/*
	cout << "\n\n\n";
	//o=stoi(str);
	this->ordem = stoi(str);
	s<<str[4];
	//s>>n;
	s >> this->numMatriz;
	//cout << "this->numMatriz: " << this->numMatriz << "\n\n\n\n";*/
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	for(int i=0; i < this->numMatriz; i++){
		
		stringstream ss;
		string a,fileName="dataset/Matriz";
		ss << (i+1);
		ss >> a;
		//cout <<"\n\na: "<< a << "\n\n" << a;
		fileName.append(a).append(".txt");
		ofstream File2(fileName);
    		for(int j=0; j < this->ordem + 1; j++){
    			getline(File,str);
    			File2 << str << "\n";
    		}
    		File2.close();
	}
	
	
	
	
	
	
	ifstream fileFase("dataset/Matriz1.txt");
	while(getline(fileFase,str)){
		vs.push_back(str);
	}
	
	for(int i=0;i<vs.size();i++){
		for(int j=0;j<vs[i].size();j++){
		
			if(vs[i][j] == ' ' && aux!="" ){
				vecs.push_back(aux);
				aux="";
			}
			else if(vs[i][j] != ' '){
				aux.push_back(vs[i][j]);
			}
			
			
		}
	
	}
	vs.clear();
	vecs.push_back(aux);
	cout << "\n\n\n";
	
	for(int i=0;i<vecs.size();i++){
		cout << vecs[i] << " "; 
	}

	setFase(this->ordem,vecs);
	vecs.clear();
}

void Jogo::setFase(int ordem,vector<string>v){
    this->fase.setMatriz(ordem,v);
}



void Jogo::mudaFase(){
	
	
		this->numeroDaFase++;
		
		if(this->numeroDaFase > this->numMatriz){
			this->numeroDaFase = 1;
		}
		
		if( this->fase.getBaixo() == true ){
			this->numl = 1;
			this->numc = this->fase.getNumc();
			cout << "\n\n\n\n\nNUMC = " << this->numc << "\n\n\n\n";
		}else{
			this->numl = this->fase.getNuml();
			this->numc = 1;
			cout << "\n\n\n\n\nNUML = " << this->numl << "\n\n\n\n";
		}
	
		string str,aux;
		vector<string> vecs,vs;
		stringstream ss;
		
		string a,fileName="dataset/Matriz";
		ss << (this->numeroDaFase);
		ss >> a;
		//cout <<"\n\na: "<< a << "\n\n" << a;
		fileName.append(a).append(".txt");
		
		
		ifstream fileFase(fileName);
		//cout << "\n\n\n";
		while(getline(fileFase,str)){
			vs.push_back(str);
		}
		
		
		cout << "\n\n\n";
		
		for(int i=0;i<vs.size();i++){
			for(int j=0;j<vs[i].size();j++){
			
				if(vs[i][j] == ' ' && aux!="" ){
					vecs.push_back(aux);
					aux="";
				}
				else if(vs[i][j] != ' '){
					aux.push_back(vs[i][j]);
				}
				
				
			}
		
		}
		vs.clear();
		vecs.push_back(aux);
		
		setFase(this->ordem, vecs);
		this->fase.setNuml(this->numl);
		this->fase.setNumc(this->numc);
		vecs.clear();
}


void Jogo::jogar(){
	
	int x=0;
	while(notfim){
		cout << "\n\nPRIMEIRA FASE: " << "( vez " << x << " )" << "\n\n";
		this->pontosDaPrimeiraMatriz = this->pontos;
		this->fase.imprimeMatriz();
		this->fase.percorreMatriz();
		this->fase.imprimeMatriz();
		this->pontos = this->pontos + this->fase.getPontos();
		cout << "      Pontos acumulados: " << this->pontos << "\n\n\n";
		this->p = this->fase.getPersonagem();
		this->p.imprimePersonagem();
		this->fase.salvaMatriz(this->numeroDaFase);
		
		if(this->p.getVidas()<=0){
				cout << "\n\n                                GAME OVER\n\n";
				cout << "                                YOU LOST\n\n";
				this->notfim = false;
				break;
		}
			
		mudaFase();
		
		for(int i=1; i < this->numMatriz; i++ ){
			
			if(this->p.getVidas()<=0){
				cout << "\n\n                                GAME OVER\n\n";
				cout << "                                YOU LOST\n\n";
				this->notfim = false;
				break;
			}
			
			cout << "\n\nFASE " << i+1 << "\n";
			this->fase.imprimeMatriz();
			this->fase.percorreMatriz();
			this->fase.imprimeMatriz();
			this->pontos = this->pontos + this->fase.getPontos();
			cout << "      Pontos acumulados: " << this->pontos << "\n";
			this->p = this->fase.getPersonagem();
			this->p.imprimePersonagem();
			this->fase.salvaMatriz(this->numeroDaFase);
			mudaFase();
	    
	    	}
	    	if( this->numl == 1 && this->numc == 1 && this->pontosDaPrimeiraMatriz == this->pontos){
	    		cout << "                                VICTORY\n\n"; 
	    		cout << "                                SCORE: " << this->pontos << "\n\n";
			this->notfim = false;
		}
		/*else if(this->p.getVidas()<=0){
			cout << "                                GAME OVER\n\n";
			cout << "                                YOU LOST\n\n";
			this->notfim = false;
		}*/
		x++;
    	}
    
    
    
	
    
    
   salvaJogo();
}





void Jogo::salvaJogo(){

	string str,aux;
	vector<string> vecs,vs;
	stringstream ss;
	
	
	/*for(int i = 1; i < this-numMatriz; i++ ){
		string a,fileName="dataset/Matriz";
		ss << i;
		ss >> a;
		//cout <<"\n\na: "<< a << "\n\n" << a;
		fileName.append(a).append(".txt");
		ifstream File2(fileName);
		ofstream File("dataset/output.data");
		for(int j=0; j < this->ordem + 1; j++){
    			getline(File,str);
    			File << str << "\n";
    		}
    		File2.close();
    		File.close();
	}*/
	ofstream File("dataset/output.data");
	File << this->ordem << " " << this->ordem << " " << this->numMatriz << endl;
	for(int i=0; i < this->numMatriz; i++){
		
		stringstream ss;
		string a,fileName="dataset/Matriz";
		ss << (i+1);
		ss >> a;
		//cout <<"\n\na: "<< a << "\n\n" << a;
		fileName.append(a).append(".txt");
		ifstream File2(fileName);
    		for(int j=0; j < this->ordem + 1; j++){
    			getline(File2,str);
    			File << str << "\n";
    		}
    		
    		std::filesystem::remove(fileName);
    	}


}