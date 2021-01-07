// Trabalho Melancia - Prof(s): Thaty, Enzo, Gabriel
// Fernanda Pereira de Sene - Engenharia de Computacao (e-mail: fehsene@gmail.com) 
// 09/07/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int i, j, lin, col;
int jogadas = 0;
int semente = 0, agua = 5, adubo = 5, n = 2;
char area[25][50];

void informacoes(){
	system("cls");
	printf("\n INFORMA\200OES: \n");
	printf(" [N] Na virada da noite chove\n\n");

	printf(" [i]: Broto de Erva daninha\n");
	printf(" [I]: Erva daninha\n");
	printf(" [^]: Pedra\n\n");

	printf(" [O]: Melancia madura\n");
	printf(" [o]: Melancia verde\n");
	printf(" [-]: Broto de melancia\n");
	printf(" [+]: Cordao de melancia\n\n");
	printf(" [~]: Local Irrigado\n\n");

	printf(" [Fonte azul: DIA]\n [Fonte branca: NOITE]\n\n");
	
	printf(" - Irrigar: Em um local com buraco '.'\n - Semear: Em um local '~'\n");
	printf(" - Adubar: Em um local '-' ou 'o'\n - Recolher: Local com 'o' ou 'O'\n");
	printf(" - Ter agua: Recolher 'o' ou 'O'\n - Ter semente: Capinar 'i' ou 'I'\n");
	printf(" - Ter adubo: Recolher 'o' ou 'O'\n - Na quinta jogada anoitece\n");
}

void inicializa(){
	int a, b, c, d, erv, dan;
	
	for(i = 0; i < 25; i++){ // Colocar um '.' no resto no jogo onde nao houver caractere
		for(j = 0; j < 50; j++){ 
			area[i][j] = '.';
		}
	}
	
	for(i = 0; i < 3; i++){	// 3 regioes sorteadas aleatoriamente
		a = rand()%24; // Nao vazar
		b = rand()%49; 
		if((a + 1 < 25 && b + 1 < 50) && area[a][b] == '.'){ // Apenas se o lugar sorteado estiver vazio
			area[a][b] = '^'; 
			area[a + 1][b + 1] = '^';
			area[a][b + 1] = '^';
			area[a + 1][b] = '^';
		}
		else{	//Se o lugar nao for vazio ele volta o i e faz novamente
			i--;
		}
	}
	
	for(i = 0; i < 2; i++){ // 2 regioes sorteadas aleatoriamente
		c = rand()%23; // Nao vazar
		d = rand()%48;
		if((c + 2 < 25 && d + 2 < 50) && area[c][d] == '.' && area[c + 2][d + 2] == '.' 
		   && area[c + 2][d] == '.' && area[c][d + 2] == '.' ){ // Fazer em cada ponta
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
		else{ 
			i--;
		}
	}
	
	for(i = 0; i < 10; i++){ // Ervas daninhas
		erv = rand()%24;
		dan = rand()%49;
		if(area[erv][dan] == '.' && area[erv][dan] != 'i'){ //Nao nascer/spawnar na pedra nem em outra erva
			area[erv][dan] = 'i';
		}
		else{ 
			i--;
		}
	}
}

void imprime(){
	printf("\n+----------------------------------------- [FAZENDINHA - MELANCIA] ---------------------------------------+\n");
	printf("                        1                   2                   3                   4\n");
	printf("   ");
	
	for(i = 0; i < 5; i++){ 
		for(j = 0; j < 10; j++){
			printf(" %d", j);
		}
	}	
	printf("\n");
	
	for(i = 0; i < 25; i++){
		printf(" %.2d", i);
		for(j = 0; j < 50; j++){ // Impressao dos objetos
			printf(" %c", area[i][j]);
		}
		printf(" %.2d", i);
		printf("\n");
	}
	
	printf("   ");
	for(i = 0; i < 5; i++){ 
		for(j = 0; j < 10; j++){
			printf(" %d", j);
		}
	}	
	printf("\n\n    Bolsa com objetos: ");
	printf("[%d] Sementes / [%d] Agua / [%d] Adubo / [%d] Noite\n", semente, agua, adubo, n); 
}

void irrigar(){
	if(agua > 0){
		printf(" [Linha|Coluna] = "); 
		scanf("%d%d", &lin, &col);
		getchar();

		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == '.'){ // se o lugar escolhido estiver vazio
				area[lin][col] = '~';
				agua--;
			}
			else{ //senao a escolha eh invalida e ele joga novamente
				printf(" [Opcao invalida]\n");
				jogadas--; 
			}
		}else{
			printf(" [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf(" Saldo - [0] Agua\n");
		jogadas--; 
	}
}

void semear(){
	if(semente > 0){
		printf(" [Linha|Coluna] = ");
		scanf("%d%d", &lin, &col);
		getchar();

		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == '~'){ 
				area[lin][col] = '-';
				semente--;
			}else{
				printf(" [Sem irrigacao no local]\n");
				jogadas--; 
			}
		}else{
			printf(" [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf("Saldo - [0] Sementes\n");
		jogadas--; 
	}
}

void adubar(){
	if(adubo > 0){
		printf(" [Linha|Coluna] = ");
		scanf("%d%d", &lin, &col);
		getchar();

		if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
			if(area[lin][col] == '-' || area[lin][col] == 'o'){ 
				if(area[lin][col] == '-'){
					area[lin][col] = 'o';
					adubo--;
				}else if(area[lin][col] == 'o'){
					area[lin][col] = 'O';
					adubo--;
				}
			}else{
			printf(" [Sem Broto/Melancia verde no local]\n");
			jogadas--; 
			}
		}else{
			printf(" [Fora dos limites]\n");
			jogadas--;
		}
	}else{
		printf(" Saldo - [0] Adubo\n");
		jogadas--; 
	}
}

void capinar(){
	int a;
	
	printf(" [Linha|Coluna] = ");
	scanf("%d%d", &lin, &col);
	getchar();

	if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
		if(area[lin][col] == 'i' || area[lin][col] == 'I' || area[lin][col] == '+'){
			if(area[lin][col] == 'i'){ // 25% de chance de ter semente
				area[lin][col] = '.'; 
				a = rand()%4;
				if(a == 0){
					semente++;
				}
			}else if(area[lin][col] == 'I'){ // 50% de chance de ter semente
				area[lin][col] = '.';
				a = rand()%2;
				if(a == 1){
					semente++;		
				}
			}else if(area[lin][col] == '+'){ // 100% de chance de ter semente
				area[lin][col] = '.';
				semente++;
			}
		}else{
			printf(" [Sem Erva daninha/Cordao de melancia no local]\n");
			jogadas--; 
		}
	}else{
		printf(" [Fora dos limites]\n");
		jogadas--;
	}
}//end capinar

void recolher(){
	printf(" [Linha|Coluna] = ");
	scanf("%d%d", &lin, &col);
	getchar();	
	if((lin >= 0 && lin <= 24) && (col >= 0 && col <= 49)){ 
		if(area[lin][col] == 'o' ||area[lin][col] == 'O'){ 
			if(area[lin][col] == 'o'){ 
				area[lin][col] = '.';
				semente++; 
				adubo++;
			}else if(area[lin][col] == 'O'){
				area[lin][col] = '.';
				semente++;
				adubo++;
				agua++;
			}
		}else{
			printf(" [Sem melancia Verde/Madura no local]\n");
			jogadas--; 
		}
	}else{
		printf(" [Fora dos limites]\n");
		jogadas--;
	}
}

void noite(){
	int b;
	if(jogadas == 5 || n > 0){ 
		for(i = 0; i < 25; i++){
			for(j = 0; j < 50; j++){
				if(area[i][j] == 'O'){ // celula com melancia adulta
					b = rand()%20;
					if(b < 6){ // 30%
						if(i - 1 >= 0 && area[i - 1][j] == '.'){ // vizinho superior
							area[i - 1][j] = '+';
						}
						else{
							if(i + 1 < 25 && area[i + 1][j] == '.'){ // vizinho inferior
								area[i + 1][j] = '+';
							}
							else{
								if(j - 1 >= 0 && area[i][j - 1] == '.'){ // vizinho a esquerda
									area[i][j - 1] = '+';
								}
								else{
									if(j + 1 < 50 && area[i][j + 1] == '.'){ // vizinho a direita
										area[i][j + 1] = '+';
									}
									else{
										if(i - 1 >= 0 && j - 1 >= 0 && area[i - 1][j - 1] == '.'){ // vizinho superior a esquerda
											area[i - 1][j - 1] = '+';
										}
										else{
											if(i - 1 >= 0 && j + 1 < 50 && area[i - 1][j + 1] == '.'){ // vizinho superior a direita
												area[i - 1][j + 1] = '+';
											}
											else{
												if(i + 1 < 25 && j - 1 >= 0 && area[i + 1][j - 1] == '.'){ // vizinho infeiror a esquerda
													area[i + 1][j - 1] = '+';
												}
												else{
													if(i + 1 < 25 && j + 1 < 50 && area[i + 1][j + 1] == '.'){ // vizinho infeiror a direita
														area[i + 1][j + 1] = '+';
													}
												}// vid
											}// vie
										}// vsd		
									}// vse
								}// vd
							}// ve
						}// vi
					}// 30%
				}
				else if(area[i][j] == '+'){ // celula com cordao de melancia
					b = rand()%20;
					if(b < 6){ // 30%
						if(i - 1 >= 0 && area[i - 1][j] == '.'){ // vizinho superior
							area[i - 1][j] = '+';
						}else{
							if(i + 1 < 25 && area[i + 1][j] == '.'){ // vizinho inferior
								area[i + 1][j] = '+';
							}else{
								if(j - 1 >= 0 && area[i][j - 1] == '.'){ // vizinho a esquerda
									area[i][j - 1] = '+';
								}else{
									if(j + 1 < 50 && area[i][j + 1] == '.'){ // vizinho a direita
										area[i][j + 1] = '+';
									}
								}// end vd
							}// end ve
						}// end vi
					}// end 30%
					else if(b >= 6 && b < 9){ // 15%
						if(i - 1 >= 0 && area[i - 1][j] == '.'){ // vizinho superior
							area[i - 1][j] = '-';
						}
						else{
							if(i + 1 < 25 && area[i + 1][j] == '.'){ // vizinho inferior
								area[i + 1][j] = '-';
							}
							else{
								if(j - 1 >= 0 && area[i][j - 1] == '.'){ // vizinho a esquerda
									area[i][j - 1] = '-';
								}
								else{
									if(j + 1 < 50 && area[i][j + 1] == '.'){ // vizinho a direita
										area[i][j + 1] = '-';
									}
								}// end vd
							}// end ve
						}// end vi
					}// end 15%
				}
				if(area[i][j] == 'o'){ // celula com melancia verde
					b = rand()%2;
					if(b == 1){
						area[i][j] = 'O';
					}
				}
				if(area[i][j] == '-'){ // celula com broto de melancia
					b = rand()%2;
					if(b == 1){
						area[i][j] = 'o';
					}
				}
				if(area[i][j] == 'i'){ // celula com broto de erva daninha
					b = rand()%2;
					if(b == 1){
						area[i][j] = 'I';
					}
				}
				if(area[i][j] == 'I'){ // celula com erva daninha Adulta
					if(i - 1 >= 0 && area[i - 1][j] != '^' && area[i - 1][j] != 'i'){ // vizinho superior
						area[i - 1][j] = '.';
					}
					if(i + 1 < 25 && area[i + 1][j] != '^' && area[i + 1][j] != 'i'){ // vizinho inferior
						area[i + 1][j] = '.';
					}
					if(j - 1 >= 0 && area[i][j - 1] != '^' && area[i][j - 1] != 'i'){ // vizinho a esquerda
						area[i][j - 1] = '.';
					}
					if(j + 1 < 50 && area[i][j + 1] != '^' && area[i][j + 1] != 'i'){ // vizinho a direita
						area[i][j + 1] = '.';
					}
					if(i - 1 >= 0 && j - 1 >= 0 && area[i - 1][j - 1] != '^' && area[i - 1][j - 1] != 'i'){ // vizinho superior a esquerda
						area[i - 1][j - 1] = '.';
					}
					if(i - 1 >= 0 && j + 1 < 50 && area[i - 1][j + 1] != '^' && area[i - 1][j + 1] != 'i'){ // vizinho superior a direita
						area[i - 1][j + 1] = '.';
					}
					if(i + 1 < 25 && j - 1 >= 0 && area[i + 1][j - 1] != '^' && area[i + 1][j - 1] != 'i'){ // vizinho infeiror a esquerda
						area[i + 1][j - 1] = '.';
					}
					if(i + 1 < 25 && j + 1 < 50 && area[i + 1][j + 1] != '^' && area[i + 1][j + 1] != 'i'){ // vizinho infeiror a direita
						area[i + 1][j + 1] = '.';
					}
				}
				if(area[i][j] == '.'){ // celula vazia - broto erv
					b = rand()%1250;
					if(b == 1){
						area[i][j] = 'i';
					}
				}
			}
		}
	}
}

int main(int argc, char * argv[]){
	srand(time(NULL));
	informacoes();
	inicializa();
	char op = '.';
	
	while(op != 'f'){
		printf("\n");
		system("pause");
		system("cls");

		if(jogadas < 5) system("color 0b");
		
		imprime();
		printf("\n A\207oes: ");
		printf("[I]rrigar / [S]emear / [A]dubar / [C]apinar / [R]ecolher / [N]oite / [F]im / [M]enu\n [%d] Jogada = ", jogadas + 1);
		scanf(" %c", &op);
		getchar();
		
		if(jogadas >= 5 || op == 'n'){
			system("color 07");
		}

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
			case 'n': // Pode usar 2 vezes como ajuda no jogo
				if(n > 0){
					printf(" [Passa por noite]\n");
					imprime();
					n--;
					noite();
					jogadas++;
				}else{
					printf(" [Saldo de Noite zerado]\n");
				}
				break;
			case 'f':
				printf("\n [FIM DE JOGO]");
				break;
			case 'm':
				informacoes();
				break;
			default:
				printf("\n [Opcao invalida]\n");
		}
		
		if(jogadas >= 5){
			imprime();
			noite();
			jogadas = 0;
		}
	}

	return 0;
}
