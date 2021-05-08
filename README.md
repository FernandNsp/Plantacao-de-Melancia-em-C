<h1 align="center">🍉 Plantação de Melancia 🍉</h1>

<p align="center">
   <a href="#-Sobre">Sobre</a>&nbsp;&nbsp; | &nbsp;&nbsp;
   <a href="#-Modo-de-Jogar">Modo de Jogar</a>&nbsp;&nbsp; | &nbsp;&nbsp;
   <a href="#-Observações">Observações</a> &nbsp;&nbsp; | &nbsp;&nbsp;
   <a href="#-License">License</a>
</p>

<p align="center">
  <img alt="Imagem Melancia" src="github/plantacaoMelancia.png">
</p>

## 🔖 Sobre
  Projeto final do Laboratório de Técnicas de Programação, com linguagem C. Foi desenvolvido utilizando as técnicas aprendidas durante o curso.
 
## 📑 Modo de jogar
  Inicialmente o jogador possui alguns itens para começar a jogar:
  - [0] Sementes = Para ter semente deve capinar;
  - [5] Agua = Para regar o local onde será semeado, primeiro passo para começar a plantação;
  - [5] Adubo = Adubar após semear;
  - [2] Noite = Duas chances de utilizar noite mesmo quando não for 5 jogadas.

  As ações do jogo acontecem pela escolha do usuário ao clicar nas teclas [i, s, a, r, c, n], respectivamente são:

  - Irrigar: primeira ação do jogo;

  - Semear: após irrigação, semeie para poder adubar;

  - Adubar: adubar para que a melancia vire uma muda;

  - Recolher: poderá recolher a melancia em dois estágios, broto (1 semente, 1 água) e madura (2 sementes, 2 águas, 2 adubo);

  - Capinar: tem chances de pegar sementes, capina as ervas daninhas (i / I) e os cordões de melancia (+); 

  - Noite: Toda noite chove, sendo assim, as ervas daninhas e plantas possuem uma porcentagem de crescimento, caso uma erva daninha creça a um bloco de distância da melancia a fruta morre. Anoite também há chances das melancias amadurecerem.

  O jogador deverá escolher a linha e a coluna onde as ações do jogo irão acontecer. A **linha** [0 à 24] e a **coluna** [0 à 50], sabendo disso, para que o jogador plante em uma determinada área, deverá ser preenchido como:
  - [Linha | Coluna] = 5 10 -> Linha sendo 5 e Coluna sendo 10;

## 🔍 Observações
  - A cada 5 jogadas anoitece automaticamente, sendo assim, na quarta jogada não precisa utilizar das noites que tem disponível;
  - Jogando você irá perceber o nascimentos de '+' (cordão de melancia), ele tem uma porcentagem de chances de crescer ao lado de uma melancia madura, dá ao jogador 2 sementes e 2 quantidades de água.

## 📄 License
Esse projeto está sob a licença MIT. Para mais detalhes acesse o arquivo [LICENSE](https://github.com/FernandNsp/Plantacao-de-Melancia-em-C/blob/main/LICENSE).
