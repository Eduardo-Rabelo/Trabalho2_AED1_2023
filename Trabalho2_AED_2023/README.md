#O caminho guloso

	O algoritmo aqui apresentado tem como intuito calcular o total do caminho guloso para percorrer cada matriz do arquivo "input.data" de modo a calcular a soma dos caminhos gulosos de todas as matrizes. Com esse objetivo, foram criados 3 arquivos em linguagem c++, sendo eles "main.cpp""Matriz.hpp""Matriz.cpp".

	Para se percorrer a matriz, deve-se sempre sseguir a matriz escolhendo-se o maior valor a cada passo, porém não sendo possível ir para uma linha acima da atual.


	Nos arquivos "Matriz.cpp" e "Matriz.hpp", a classe Matriz é criada. No header "Matriz.hpp", são definidos os atributos e os métodos da classe, bem como os tipos dos argumentos requisitados pelos atributos.

	Os atributos da classe Matriz são dois inteiros, "ordem" e "total", sendo que na declaração já é atribuido o valor 0 a "total",dois ponteiros de inteiros "inicio" e "final",para marcar o inicio e o fim da matriz, bem como um vector de inteiros para se criar um objeto da classe Matriz.

	Com relação aos métodos da classe,esses são o construtor "Matriz(int ordem, vector<int> v);", e os métodos "void setMatriz(int ordem, vector<int> v);", "void conta();", "void setOrdem(int ordem);", "int getTotal();" e "void imprimeMatriz();".


#Métodos:
#Matriz(int ordem, vector<int> v;

	Esse é o construtor da matriz, ele recebe um inteiro "ordem" e um vector de inteiros "v" e cria um objeto Matriz a partir desses parâmetros.

	No construtor, dados aleatórios são armazenados no vector v de modo que este tenha um tamanho igual ao quadrado da ordem , o ponteiro início é apontado para o início desse vetor e o ponteiro final é apontado para o final dele.

#void setMatriz(int ordem, vector<int> v);

 Esse método, do mesmo modo que o construtor,recebe um inteiro "ordem" e um vector de inteiros "v". Esse método é escito do mesmo modo que o construtor, mas, ao contrário do construtor, não cria um novo objeto Matriz, porém altera um objeto completamente.

#void conta();

	Esse método é responsável por calcular o caminho guloso da matriz, substituir todos os elementos percorridos por -1 e salvar a soma desses elementos no atributo "total".

	No método, são criados os ponteiros "*p" e "*p2", que apontam respectivamente para as mesmas posições que os ponteiros "*início" e "*final". Dessa forma, um while(p < p2) é usado para percorrer a matriz seguindo as regras do projeto. Reras essas que,no programa, são determinadas por condicionais.

#void setOrdem(int ordem);

	Esse método recebe um inteiro "ordem" e atribui o valor desse inteiro ao atributo "ordem" da classe "Matriz".

#int getTotal();
	Esse método retorna o atributo do tipo inteiro "total".

#void imprimeMatriz();
	Esse método simplesmente imprime o objeto Matriz.


