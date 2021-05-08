//Trabalho Melancia - Prof(s): Thaty, Enzo, Gabriel;
//Fernanda Pereira de Sene - (ECO);
//09/07/2020;

//Bibliotecas usadas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//variaveis globais
int i, j, lin, col;
int jogadas = 0;
int semente = 0, agua = 5, adubo = 5, n = 2;
char area[25][50];

void inicializa(){
	int a, b, c, d, erv, dan;
	
	for(i = 0; i < 25; i++){ //Colocar um ' ' no resto no jogo onde nao houver caractere. - 25
		for(j = 0; j < 50; j++){ //Colocar um ' ' no resto no jogo onde nao houver caractere. - 50
			area[i][j] = ' ';
		}//end j
	}//end i
	
	for(i = 0; i < 3; i++){	//3 regioes sorteadas aleatoriamente
		a = rand()%24; //Nao vazar
		b = rand()%49; 
		if((a + 1 < 25 && b + 1 < 50) && area[a][b] == ' '){ //Apenas se o lugar sorteado estiver vazio
			area[a][b] = '^'; 
			area[a + 1][b + 1] = '^';
			area[a][b + 1] = '^';
			area[a + 1][b] = '^';
		}
		else{	//Se o lugar nao for vazio ele volta o i e faz novamente
			i--;
		}
	}//end for
	
	for(i = 0; i < 2; i++){ //2 regioes sorteadas aleatoriamente
		c = rand()%23; //Nao vazar
		d = rand()%48;
		if((c + 2 < 25 && d + 2 < 50) && area[c][d] == ' ' && area[c + 2][d + 2] == ' ' 
		   && area[c + 2][d] == ' ' && area[c][d + 2] == ' ' ){ //Fazer em cada ponta
			area[c][d] = '^';
			area[c + 1][d + 1] = '^';
			area[c][d + 1] = '^';
			area[c + 1][d] = '^';
			area[c + 2][d + 2] = '^';
			area[c + 2][d + 1] = '^';
			area[c + 1][d + 2] = '^';
			area[c + 1][d] = '^';
			area[c][d + 2] = '^';
			area[c + 2][d] = '^';
		}	
		else{ //Se o lugar nao for vazio ele volta o i e faz novamente
			i--;
		}
	}//end for
	
	for(i = 0; i < 10; i++){ //Ervas daninhas
		erv = rand()%24;
		dan = rand()%49;
		if(area[erv][dan] == ' ' && area[erv][dan] != 'i'){ //Nao nascer spawnar na pedra nem em outra erva
			area[erv][dan] = 'i';
		}
		else{ //Se o lugar nao for vazio ele volta o i e faz novamente
			i--;
		}
	}//end for
}//end inicializa

void imprime(){
	if(jogadas == 5) printf("\n--- [NOITE]\n"); //Aparecer noite quando jogadas = 5
	printf("--- [COLHEITA - MELANCIA]\n");
	printf("                                1                             2                             3                             4\n");
	
	printf("    ");
	for(i = 0; i < 5; i++){ //Imprimir a coluna de 0 ate 9
		for(j = 0; j < 10; j++){ //Fazendo isso 9 vezes
			printf("[%d]", j);
		}//end j
	}//end i
	printf("\n");
	
	for(i = 0; i < 25; i++){ //Imprimir a linha de 0 ate 24
		printf("[%.2d]", i);
		for(j = 0; j < 50; j++){ //Impressao dos objetos
			printf(" %c ", area[i][j]);
		}//end j
		printf("[%.2d]", i);
		printf("\n");
	}//end i

	printf("    ");
	for(i = 0; i < 5; i++){ //Imprimir a coluna de 0 ate 9
		for(j = 0; j < 10; j++){ //Fazendo isso 9 vezes
			printf("[%d]", j);
		}//end j
	}//end i
	printf("\n");

	printf("\n-> "); 
	printf(" [%d] Sementes | [%d] Agua | [%d] Adubo | [%d] Noite\n", semente, agua, adubo, n); //Barra quantidade
}//end imprime

void irrigar(){
	if(agua > 0){
		printf("->  [Linha|Coluna] = "); 
		scanf("%d%d", &lin, &col);
		getchar();
		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == ' '){ //se o lugar escolhido estiver vazio
				area[lin][col] = '~';
				agua--;
			}
			else{ //senao a escolha a invalida e ele joga novamente
				printf("->  [Opcao invalida]\n");
				jogadas--; //nao conta como jogada
			}
		}else{
			printf("->  [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf("->  Saldo - [0] Agua\n");
		jogadas--; //nao conta como jogada
	}
}//end irrigar

void semear(){
	if(semente > 0){
		printf("->  [Linha|Coluna] = ");
		scanf("%d%d", &lin, &col);
		getchar();
		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == '~'){ //se o lugar escolhido tiver agua
				area[lin][col] = '-';
				semente--;
			}else{
				printf("->  [Sem irrigacao no local]\n");
				jogadas--; //nao conta como jogada
			}
		}else{
			printf("->  [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf("->  Saldo - [0] Sementes\n");
		jogadas--; //nao conta como jogada
	}
}//end semear

void adubar(){
	if(adubo > 0){
		printf("->  [Linha|Coluna] = ");
		scanf("%d%d", &lin, &col);
		getchar();
		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == '-' || area[lin][col] == 'o'){ //se broto/mV/mA
				if(area[lin][col] == '-'){
					area[lin][col] = 'o';
					adubo--;
				}else if(area[lin][col] == 'o'){
					area[lin][col] = 'O';
					adubo--;
				}
			}else{
			printf("->  [Sem Broto/Melancia verde no local]\n");
			jogadas--; //nao conta como jogada
			}
		}else{
			printf("->  [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf("->  Saldo - [0] Adubo\n");
		jogadas--; //nao conta como jogada
	}
}//end adubar

void capinar(){
	int a;
	
	printf("->  [Linha|Coluna] = ");
	scanf("%d%d", &lin, &col);
	getchar();
	if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
		if(area[lin][col] == 'i' || area[lin][col] == 'I' || area[lin][col] == '+'){ //se bf/bA/cM
			if(area[lin][col] == 'i'){ //25% de chance de ter semente
				area[lin][col] = ' '; 
				a = rand()%4;
				if(a == 0){
					semente++;
				}
			}else if(area[lin][col] == 'I'){ //50% de chance de ter semente
				area[lin][col] = ' ';
				a = rand()%2;
				if(a == 1){
					semente++;		
				}
			}else if(area[lin][col] == '+'){ //100% de chance de ter semente
				area[lin][col] = ' ';
				semente++;
			}
		}else{
			printf("->  [Sem Erva daninha/Cordao de melancia no local]\n");
			jogadas--; //nao conta como jogada
		}
	}else{
		printf("->  [Fora dos limites]\n");
		jogadas--;
	}
}//end capinar

void recolher(){
	printf("->  [Linha|Coluna] = ");
	scanf("%d%d", &lin, &col);
	getchar();	
	if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
		if(area[lin][col] == 'o' ||area[lin][col] == 'O'){ //se mV/mA
			if(area[lin][col] == 'o'){ //se mV
				area[lin][col] = ' ';
				semente++; //colhe uma semente e um adubo
				adubo++;
			}else if(area[lin][col] == 'O'){ //mA
				area[lin][col] = ' ';
				semente++; //colhe semente, adubo e agua
				adubo++;
				agua++;
			}
		}else{
			printf("->  [Sem melancia Verde/Madura no local]\n");
			jogadas--; //nao conta como jogada
		}
	}else{
		printf("->  [Fora dos limites]\n");
		jogadas--;
	}
}//end recolher

void noite(){
	int b;
	if(jogadas == 5 || n > 0){ //se 5 jogadas ele execulta/jogador selecionar
		for(i = 0; i < 25; i++){
			for(j = 0; j < 50; j++){
				if(area[i][j] == 'O'){ //celula com melancia adulta
					b = rand()%20;
					if(b < 6){ //30%
						if(i - 1 >= 0 && area[i - 1][j] == ' '){ //vizinho superior
							area[i - 1][j] = '+';
						}
						else{
							if(i + 1 < 25 && area[i + 1][j] == ' '){ //vizinho inferior
								area[i + 1][j] = '+';
							}
							else{
								if(j - 1 >= 0 && area[i][j - 1] == ' '){ //vizinho a esquerda
									area[i][j - 1] = '+';
								}
								else{
									if(j + 1 < 50 && area[i][j + 1] == ' '){ //vizinho a direita
										area[i][j + 1] = '+';
									}
									else{
										if(i - 1 >= 0 && j - 1 >= 0 && area[i - 1][j - 1] == ' '){ //vizinho superior a esquerda
											area[i - 1][j - 1] = '+';
										}
										else{
											if(i - 1 >= 0 && j + 1 < 50 && area[i - 1][j + 1] == ' '){ //vizinho superior a direita
												area[i - 1][j + 1] = '+';
											}
											else{
												if(i + 1 < 25 && j - 1 >= 0 && area[i + 1][j - 1] == ' '){ //vizinho infeiror a esquerda
													area[i + 1][j - 1] = '+';
												}
												else{
													if(i + 1 < 25 && j + 1 < 50 && area[i + 1][j + 1] == ' '){ //vizinho infeiror a direita
														area[i + 1][j + 1] = '+';
													}
												}//vid
											}//vie
										}//vsd		
									}//vse
								}//vd
							}//ve
						}//vi
					}//30%
				}//end celula com melancia adulta
				else if(area[i][j] == '+'){ //celula com cordao de melancia
					b = rand()%20;
					if(b < 6){ //30%
						if(i - 1 >= 0 && area[i - 1][j] == ' '){ //vizinho superior
							area[i - 1][j] = '+';
						}else{
							if(i + 1 < 25 && area[i + 1][j] == ' '){ //vizinho inferior
								area[i + 1][j] = '+';
							}else{
								if(j - 1 >= 0 && area[i][j - 1] == ' '){ //vizinho a esquerda
									area[i][j - 1] = '+';
								}else{
									if(j + 1 < 50 && area[i][j + 1] == ' '){ //vizinho a direita
										area[i][j + 1] = '+';
									}
								}//end vd
							}//end ve
						}//end vi
					}//end 30%
					else if(b >= 6 && b < 9){ //15%
						if(i - 1 >= 0 && area[i - 1][j] == ' '){ //vizinho superior
							area[i - 1][j] = '-';
						}
						else{
							if(i + 1 < 25 && area[i + 1][j] == ' '){ //vizinho inferior
								area[i + 1][j] = '-';
							}
							else{
								if(j - 1 >= 0 && area[i][j - 1] == ' '){ //vizinho a esquerda
									area[i][j - 1] = '-';
								}
								else{
									if(j + 1 < 50 && area[i][j + 1] == ' '){ //vizinho a direita
										area[i][j + 1] = '-';
									}
								}//end vd
							}//end ve
						}//end vi
					}//end 15%
					//55% nao foi preciso ser feito, pois nao executaria nada
				}//end celula com cordao de melancia
				if(area[i][j] == 'o'){ //celula com melancia verde
					b = rand()%2;
					if(b == 1){ //50%;
						area[i][j] = 'O';
					}//end if 50%
				}//end celula com melancia verde
				if(area[i][j] == '-'){ //celula com broto de melancia
					b = rand()%2;
					if(b == 1){ //50%
						area[i][j] = 'o';
					}//end if 50%
				}//end celula com broto de melancia
				if(area[i][j] == 'i'){ //celula com broto de erva daninha
					b = rand()%2;
					if(b == 1){ //%50
						area[i][j] = 'I';
					}
				}//end celula com broto de erva daninha
				if(area[i][j] == 'I'){ //celula com erva daninha Adulta
					if(i - 1 >= 0 && area[i - 1][j] != '^' && area[i - 1][j] != 'i'){ //vizinho superior
						area[i - 1][j] = ' ';
					}
					if(i + 1 < 25 && area[i + 1][j] != '^' && area[i + 1][j] != 'i'){ //vizinho inferior
						area[i + 1][j] = ' ';
					}
					if(j - 1 >= 0 && area[i][j - 1] != '^' && area[i][j - 1] != 'i'){ //vizinho a esquerda
						area[i][j - 1] = ' ';
					}
					if(j + 1 < 50 && area[i][j + 1] != '^' && area[i][j + 1] != 'i'){ //vizinho a direita
						area[i][j + 1] = ' ';
					}
					if(i - 1 >= 0 && j - 1 >= 0 && area[i - 1][j - 1] != '^' && area[i - 1][j - 1] != 'i'){ //vizinho superior a esquerda
						area[i - 1][j - 1] = ' ';
					}
					if(i - 1 >= 0 && j + 1 < 50 && area[i - 1][j + 1] != '^' && area[i - 1][j + 1] != 'i'){ //vizinho superior a direita
						area[i - 1][j + 1] = ' ';
					}
					if(i + 1 < 25 && j - 1 >= 0 && area[i + 1][j - 1] != '^' && area[i + 1][j - 1] != 'i'){ //vizinho infeiror a esquerda
						area[i + 1][j - 1] = ' ';
					}
					if(i + 1 < 25 && j + 1 < 50 && area[i + 1][j + 1] != '^' && area[i + 1][j + 1] != 'i'){ //vizinho infeiror a direita
						area[i + 1][j + 1] = ' ';
					}
				}//end celula com erva daninha Adulta
				if(area[i][j] == ' '){ //celula vazia - broto erv
					b = rand()%1250;
					if(b == 1){
						area[i][j] = 'i';
					}//end %
				}//end celula vazia - broto erv
			}//end j
		}//end i
	}//end if jogadas
}//end noite

int main(int argc, char * argv[]){
	srand(time(NULL));
	inicializa();
	char op = ' ';
	
	system("cls");
	while(op != 'f'){
		if(jogadas < 5) printf("\n--- [DIA]\n"); //imprimir dia
		imprime();
		printf("\n->  [I]rrigar / [S]emear / [A]dubar / [C]capinar / [R]ecolher / [N]oite / [F]im \n->  [%d] Opcao = ", jogadas + 1); //Barra de itens
		scanf(" %c", &op);
		getchar();
		switch(op){
			case 'i':
				irrigar();
				jogadas++;
			break;
			case 's':
				semear();
				jogadas++;
			break;
			case 'a':
				adubar();
				jogadas++;
			break;
			case 'c':
				capinar();
				jogadas++;
			break;
			case 'r':
				recolher();
				jogadas++;
			break;
			case 'n': //Pode usar 2 vezes como ajuda no jogo
				if(n > 0){
					printf("->  [Passa por noite]\n");
               if(op = 'n') printf("\n--- [NOITE]\n");
					imprime();
					n--;
					noite();
					jogadas++; //Jogada e contada quando se usa noite
				}else{
					printf("->  [Saldo de Noite zerado]\n");
				}
			break;
			case 'f':
				printf("\n->  [FIM DE JOGO]\n");
				break;
			default:
				printf("\n->  [Opcao invalida]\n");
		}//end switch
		if(jogadas >= 5){
			imprime();
			noite();
			jogadas = 0;
		}
	}//end while

	return 0;
}//end main
