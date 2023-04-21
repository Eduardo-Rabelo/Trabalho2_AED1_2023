
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Matriz.hpp"
#include "Jogo.hpp"
#include <fstream>
#include <typeinfo>
#include <vector>
#include <sstream>
using namespace std;


int main(){
        
	srand (time(NULL));
	Jogo j;
	j.jogar();
	return 0;
}








