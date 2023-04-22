# O Labirinto
<p align="justify">
	O algoritmo aqui apresentado tem como intuito extrair matrizes de um arquivo "input.data", percorrê-las de seuindo regras pré determinadas e salva-las em um arquivo "output.data" sem alterar as informações de "input.data". Além disso, as matrizes são tratadas como labirintos em uma espécie de video game. Nese jogo, o personagem caminha pela matriz de modo aleatório até chegar à extremidade direita, ou de baixo, da matriz, que é entendida como uma fase do jogo. Nessas extremidade direita, se o personagem for para direita, ele se transporta para a mesma linha da primeira coluna da matriz seguinte. Do mesmo modo, se ele se mover para baixo, estando na última linha da matriz, ele será transportado para a mesma coluna da primeira linha da próxima fase, como é demonstrado na imagem a seguir.
</p>
	
	
	
	COLOCAR IMAGEM AQUI
<p align="justify">	
	Há ainda, casos especiais. Quando o persongem está na última coluna, ele pode se mover,caso seja possível,  tanto para a linha superior, ou inferior a que ele se encontra, porém na próxima matriz, se ele tiver se movido para a diagonal direita superior, ou  inferior, respectivamente. Se o personagem estiver no canto inferior direito da matriz e se mover para a diagonal direita inferior, ele se moverá para a última linha da primeira coluna da próxima fase. Da mesma forma, caso se mova para diagonal direita superior, estando no canto superior direito, o transporde ocorrerá como se ele tivesse se movido para a direita. Por fim,caso ele esteja no canto inferior esquerdo, mover para diagonal esquerda inferior é equivalente a mover para baixo. Não é possível se transportar para outra fase por cima, ou pela esquerda.
</p>

<p align="justify">
	Todo o processo para percorrer matriz está implementado no método "void percorreMatriz()" da classe Matriz. Além das regras de transporte já citadas, dentro da mesma matriz, ou fase, o transporte ocorre de modo aleatório sendo que cada elemento da matriz gera efeitos no personagem, ou impede o movimento pela fase. O símbolo "#" simboliza uma parede intransponível, de modo que, se o movimento sorteado levar o personagem a uma posição que contém uma parede, o movimento é desfeito e sorteado novamente. O símbolo "*", por sua vez, representa um perigo, que retira uma vida do personagem cada vez que este passa por ele. Por fim, números representam itens. Ao passar por um número, o personagem ganha um item, e o número é reduzido em um, até no mínimo 0. Quando o número chega a zero, não é mais possível retirar itens de sua posição. A cada 4 itens que o personagem pega, ele ganha uma vida.
</p>

<p align="justify">
	Caso as vidas do personagem acabem, o jogo acaba em uma tela de "GAME OVER" que é representada na imagem a seguir. Nela, são exibidas as mensagens "GANME OVER" e "YOU LOST", bem como o total de itens consumidos pelo personagem, ou sua pontuação total, o número total de perigos pelos quais ele passou, o número total de casas que foram visitadas ao menos uma vez no jogo inteiro, e o número de casas que nunca sequer foram visitadas. A tela de vitória é basicamente idêntica, porém as mensagens "GANME OVER" e "YOU LOST" são substituídas pela mensagem "VICTORY". A condição de vitória é o personagem passar por todas as fases do jogo, sem ganhar itens e sem morrer, e retornar a posição inicial do jogo, que é a posição [0][0] da primeira fase. Faltou aida dizer que da última fase, o personagem se transporta para a primeira.
</p>
	![Menu](https://github.com/JoaoVictorFBarros/Algoritmo_de_recomendacao/blob/Imagens/Menu.png)
	![TELAdeDERROTA]()
	
	
	
	COLOCAR IMAGEM AQUI(TELA DE VITÓRIA E TELA DE DERROTA)
	
	
# Custo
<p align="justify">
	As matrizes são extraídas do arquivo "input.txt" e operadas uma a uma, ou seja, o custo do algoritmo, em questão de memória alocada, depende apenas da ordem das matrizes, não da quantidade delas. Já em questão de custo computacional, para criar os arquivos separados de cada matriz, o custo seria igual a k vezes o número n de elementos de cada matriz, porém, como as matrizes são escritas e retiradas dos arquivos uma a uma, seu custo é n. Para percorrer a matriz, no entanto, o custo pertenceria à classe Teta de n, pois seu custo é, aproximadamente, 47n, dependendo do caminho percorrido,  ou seja, menor que 100n e maior que 2n, por exemplo, o que o enquadra o método "void percorreMatriz()" nessa classe de algoritmos. Como estruturas condicionais sao caras computacionalmente, e este método é o que mais faz uso delas, ele é o mais caro do algoritmo, portanto, é correto dizer que o algoritmo pertence à classe Teta de n. 
</p>


# Conclusão
<p align="justify">
	É importante dizer que, em questão de tempo de execução, o algoritmo é imprevisível, pois o método escolhido para percorrer a matriz foi a aleatoriedade, portanto, o personagem pode andar por todas as fases muitas vezes antes de uma das condições de parada ser satisfeita. Inclusive, é muito mais provável que o personagem morra, do que ele sobreviva a todas as fases até passar por todas elas e volte a posição de início de jogo sem ter adquirido itens na última vez que passou por todas as fases. Ou seja, tendo como objetivo a vitória no jogo, convém estudar outro método de percorrer a matriz, porém, como a execução do programa termina caso o personagem morra, sua execução, no geral, é rápida. Caso houver poucos, ou nenhum perigo, porém, o programa pode demorar muito para ser executado, a depender do tamanho e do número de matrizes.
</p>	

# Compilação e Execução

<p align="justify">
O arquivo Makefile permite o uso das seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a pasta build                                        |
|  `make`                | Executa a compilação e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


