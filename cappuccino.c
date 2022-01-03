#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(){
    // No menu é apresentado as opções e temos uma validação do número escolhido
    int opc;
    int repetir;
    printf("\n\t\t\33[1;37m+\33[1;34m=======================\33[1;37m+\n");
    printf("\t\t\33[1;34m|\33[1;37m\t   MENU\t\t\33[1;34m|\n");
    printf("\t\t\33[1;37m+\33[1;34m=======================\33[1;37m+\33[1;34m\n");
    printf("\t\t|\33[1;37m   [1] - NOVO JOGO \t\33[1;34m|\n");
    printf("\t\t|\33[1;37m   [2] - REGRAS  \33[1;34m\t|\n");
    printf("\t\t|\33[1;37m   [3] - EU \t\33[1;34m\t|\n");
    printf("\t\t\33[1;37m+\33[1;34m-----------------------\33[1;37m+\n\n");

    do {
        repetir = 1;
        printf("\33[1;34m>>> Opção Escolhida:\33[1;37m ");
        scanf("%d", &opc);
        
        if (opc > 3) printf("\33[1;31m ERRO! %d não é uma opção válida!\33[1;37m\n", opc);
        else repetir = 0;
    } while (repetir == 1);

    return opc;
}

void enterContinua(int mostrar){
    if (mostrar > 0){
        printf("\nPRESSIONE ENTER PARA CONTINUAR...");
        getchar();
    }
    system("clear");
    if (mostrar < 2)
    printf("-=-=-=-=-=-=-=-=-=-=-=- CAPPUCCINO -=-=-=-=-=-=-=-=-=-=-=-\n\n");
}

void mostrarTutorial(){
    enterContinua(0);
    getchar();
    printf("Cappuccino é um jogo abstrato para até quatro jogadores\n");
    printf("cujo objetivo é ter a maior quantidade de pilhas sobre seu \n");
    printf("domínio ao final da partida. Esse objetivo é alcançado\n");
    printf("empilhando peças durante a partida.\n");
    enterContinua(1);

    printf("O Jogo acontece em um Tabuleiro 5x5 onde cada um dos 4\n");
    printf("Jogadores tem a mesma quantidade de peças, mas essas peças\n");
    printf("são posicionadas aleatoriamente e os espaços dos cantos e \n");
    printf("central não possuem nenhuma peça.\n");
    enterContinua(1);

    printf("Os jogadores alternam seus turnos durante a partida,\n");
    printf("durante seu turno o jogador deverá escolher uma peça e\n");
    printf("movê-la para um espaço adjacente.\n");
    printf("Desde modo, o jogador indica o espaço que ela se encontra\n");
    printf("(exemplo: a4)\n"); 
    enterContinua(1);

    printf("Depois disso o Jogador deve escolher uma direção de movimento\n");
    printf("usando o teclado numérico (com o 8 indicando cima, 3 diagonal\n");
    printf("para direita e baixo, etc.).\n");
    enterContinua(1);

    printf("Todas as peças movem-se similar ao Rei do Xadrez. O jogador\n");
    printf("deverá escolher uma das oito posições ao seu redor para mover\n");
    printf("sua peça. Caso o espaço esteja vazio,não é possível realizar o\n");
    printf("movimento. Caso o espaço tenha uma peça, ele só poderá se mover\n");
    printf("se a peça tiver altura igual ou inferior à sua. Ao mover uma peça\n");
    printf("para um espaço válido, você deve empilhar sobre a pilha existente\n");
    printf("isto é, se sua peça tinha altura 3 e se move para um espaõ com peça\n");
    printf("de altura 2 no final você terá uma peça de sua cor de altura 5.\n");
    printf("\n");
    enterContinua(1);

    printf("A partida dura enquanto for possível alguém se movimentar. Isto é,\n");
    printf("se você passar a vez de todos os jogadores, pois nenhum é capaz\n");
    printf("de se mover mais, a partida encerra. Em caso de empates, usar\n");
    printf("ordem do turno inversa para desempatar.\n");
    enterContinua(2);
    main();
}

void mostrarCreditos(){
    enterContinua(0);
    getchar();
    printf("-=- Projeto de Introdução à Programação -=- \n\n");
    printf("Implementação de Versão alterada do jogo Cappuccino na linguagem de programação C\n");
    printf("Aluno: Vinicius Guedes dos Santos - UFCA\n");
    printf("Professor: Roberto Hugo Wanderley Pinheiro - CC0001\n\n");
    printf("-=- Resumo do trabalho -=- \n\n");
    printf("- Código elaborado utilizando Linux Ubuntu e o Visual Studio Code;\n");
    printf("- Para minimizar os problemas no windows, as cores foram feitas com os códigos de cor \\033;\n");
    printf("- Utilizei 2 matrizes para fazer o tabuleiro;\n");
    printf("- Todas as exigências da Seção 1 foram feitas;\n");
    printf("- Da seção 2 somente o item 2.1 está feito, todas as funções foram feitas.\n\n");
    printf("PRESSIONE ENTER PARA VOLTAR AO MENU...");
    getchar();
    system("clear");
    main();
}

void exibeTabuleiro(int casasInt[5][5], int jogsInt[5][5]){
    // essa função irá imprimir todo o tabuleiro na tela de acordo com a matriz do jogo.
    int l, c, li, co;
    char letras[5] = {'a', 'b', 'c', 'd', 'e'};
    char casasChar[5][5];

    // Nessa parte eu estou preenchendo uma matriz com os mesmos valores da original, só que em char, para quando a altura for 0 deixar a casa valendo ' ':
    for (l = 0 ; l < 5 ; l++){
        for (c = 0 ; c < 5 ; c++){
            casasChar[l][c] = casasInt[l][c]+'0';
            if (casasChar[l][c] == '0')
                casasChar[l][c] = ' ';
        }
    }

    system("clear");
    printf("\t\t  -=- C A P P U C C I N O -=-\n");
    printf("\n\t\t+-----+-----+-----+-----+-----+\n\t\t");
    for (li = 0 ; li < 5 ; li++){
        for (co = 0; co < 5 ; co++){
            printf("|");
            switch (jogsInt[li][co]){
                case 1: printf("\33[1;31m"); break; // Vermelho
                case 2: printf("\33[1;32m"); break; // Verde
                case 3: printf("\33[1;33m"); break; // Amarelo
                case 4: printf("\33[1;36m"); break; // Azul
            }
            if (casasChar[li][co] <= 57)
                printf("  %c  ", casasChar[li][co]);
            else if (casasChar[li][co] <= 67)
                printf(" 1 %c ", casasChar[li][co]-10);
            else if (casasChar[li][co] <= 77)
                printf(" 2 %c ", casasChar[li][co]-10);
            printf("\33[1;37m");
        }
        printf("| %c\n\t\t+-----+-----+-----+-----+-----+\n\t\t", letras[li]);
    }
    printf("   1     2     3     4     5 \n");
}

int trocaTurno(rodada, vez){
    // Analisando de quem é a vez conforme a rodada
    vez++;
    if (vez == 5)
        vez = 1;
    return vez;
}

int validaPeca(char peca[2], int vez, int matrizJog[5][5]){
    // Validando espaço em relação ao tabuleiro para saber se ela existe:
    if ((peca[0] == 'a' || peca[0] == 'b' || peca[0] == 'c' || peca[0] == 'd'
      || peca[0] == 'e' || peca[0] == 'A' || peca[0] == 'B' || peca[0] == 'C' 
      || peca[0] == 'D' || peca[0] == 'E') && (peca[1] == '1' || peca[1] == '2' 
      || peca[1] == '3' || peca[1] == '4' || peca[1] == '5'))
        return 1;
    return 0;
}

int posicaoMatriz(int vez, int matrizJog[5][5], char peca[2]){
    // essa função altera a posição de texto (a5) para números acessíveis na matriz (0 e 4).
    int p1, p2;
    switch (peca[0]){
        case 'a': p1 = 10; break;
        case 'b': p1 = 20; break;
        case 'c': p1 = 30; break;
        case 'd': p1 = 40; break;
        case 'e': p1 = 50; break;
        case 'A': p1 = 10; break;
        case 'B': p1 = 20; break;
        case 'C': p1 = 30; break;
        case 'D': p1 = 40; break;
        case 'E': p1 = 50; break;
        default: break;
    }

    switch (peca[1]){
        case '1': p2 = 1; break;
        case '2': p2 = 2; break;
        case '3': p2 = 3; break;
        case '4': p2 = 4; break;
        case '5': p2 = 5; break;
        default: break;
    }

    return p1+p2;
}

int validaMovimento(int vez, int posl, int posl2, int posc, int posc2, int destino, int matrizJog[5][5], int matrizTam[5][5], int rodada){
    int errado = 0;
    // Calculando a posição que a peça irá receber (posl2, posc2). Não usei switch pq ficaria maior
    printf("\n");
    // Se o jogador escolher uma peça que não pertence a ele:
    if (matrizJog[posl][posc] != vez && matrizTam[posl][posc] != 0){
        printf("ERRO! Essa peça não pertence à você!\n");
        errado = 1;
    } 
    else if (matrizTam[posl][posc] == 0){
        printf("ERRO! Você escolheu uma casa vazia!\n");
        errado = 2;
    } 
    // Se o jogador escolher um destino inválido
    if (destino > 9 || destino < 1 || destino == 5){
        printf("ERRO! O Destino é Inválido!\n");
        errado = 3;
    }
    // Se o destino que ele escolheu é fora da matriz:
    if (posl2 > 4 || posl2 < 0 || posc2 > 4 || posc2 < 0){
        printf("ERRO! O Destino está fora do tabuleiro!\n");
        errado = 4;
    }
    // Se o destino que ele escolheu é uma casa vazia
    else if (matrizTam[posl2][posc2] == 0){
        printf("ERRO! O Destino não pode ser uma casa vazia!\n");
        errado = 5;
    }
    // Se o espaço destino for maior que o da origem
    if (matrizTam[posl2][posc2] > matrizTam[posl][posc] && errado != 2){
        printf("ERRO! O Destino tem que ser uma peça de altura igual ou inferior à origem!\n");
        errado = 6;
    }
    if (errado == 0) return 0;
    return 1;
}

int validaMov(int posl, int posl2, int posc, int posc2, int matrizJog[5][5], int matrizTam[5][5]){
    int errado = 0;
    // Calculos basicos da função jogadasPossiveis()
    if (matrizTam[posl][posc] == 0) // Casa inicial vazia
        return 2;

    if (posl2 > 4 || posl2 < 0 || posc2 > 4 || posc2 < 0) // Destino fora do tabuleiro
        return 3;

    if (matrizTam[posl2][posc2] == 0) // Destino é uma casa vazia
        return 4;

    if (matrizTam[posl2][posc2] > matrizTam[posl][posc] && errado != 2) // Peça destino maior
        return 5;
    return 0;
}

int jogadasPossiveis(int matrizJog[5][5], int matrizTam[5][5], int tam, int linha, int coluna){
    // Função que calcula as jogadas possiveis de uma peça usando a função valida movimento
    int quant = 0;

    // testando com destino 7, 8 e 9:
    if (validaMov(linha, linha-1, coluna, coluna-1, matrizJog, matrizTam) == 0) quant++;
    if (validaMov(linha, linha-1, coluna, coluna, matrizJog, matrizTam) == 0) quant++;
    if (validaMov(linha, linha-1, coluna, coluna+1, matrizJog, matrizTam) == 0) quant++;

    // testando com destino 4 e 6:
    if (validaMov(linha, linha, coluna, coluna-1, matrizJog, matrizTam) == 0) quant++;
    if (validaMov(linha, linha, coluna, coluna+1, matrizJog, matrizTam) == 0) quant++;

    // testando com destino 1, 2 e 3:
    if (validaMov(linha, linha+1, coluna, coluna-1, matrizJog, matrizTam) == 0) quant++;
    if (validaMov(linha, linha+1, coluna, coluna, matrizJog, matrizTam) == 0) quant++;
    if (validaMov(linha, linha+1, coluna, coluna+1, matrizJog, matrizTam) == 0) quant++;

    return quant;
}

int fimPartida(int matrizTam[5][5], int matrizJog[5][5], int vez){
    int contvermelho = 0, contverde = 0, contamarelo = 0, contazul = 0; // Quantas peças tem
    int movvermelho = 0, movverde = 0, movamarelo = 0, movazul = 0; // Quantos movimentos tem
    int linha, coluna;
    int matrizPossiveis[5][5];

    for (linha = 0 ; linha < 5 ; linha++){
        for (coluna = 0 ; coluna < 5 ; coluna++){
            // Contando quantas peças tem
            switch (matrizJog[linha][coluna]){
                case 1: contvermelho++; break;
                case 2: contverde++; break;
                case 3: contamarelo++; break;
                case 4: contazul++; break;
            }
        matrizPossiveis[linha][coluna] =
        jogadasPossiveis(matrizJog, matrizTam, matrizJog[linha][coluna], linha, coluna);
        }
    }
    
    for (linha = 0 ; linha < 5 ; linha++){
        for (coluna = 0 ; coluna < 5 ; coluna++){
            // Contando quantas peças movimentaveis tem de cada cor
            
            if (matrizPossiveis[linha][coluna] > 0){
                switch (matrizJog[linha][coluna]){
                    case 1: movvermelho++; break;
                    case 2: movverde++; break;
                    case 3: movamarelo++; break;
                    case 4: movazul++; break;
                }
            }
        }
    }
    int retorno = 0;
    if (movvermelho == 0 || contvermelho == 0) retorno += 1000;
    if (movverde == 0 || contverde == 0) retorno += 100;
    if (movamarelo == 0 || contamarelo == 0) retorno += 10;
    if (movazul == 0 || contazul == 0) retorno += 1;
    return retorno;
}

int contarVitoria(int matrizTam[5][5], int matrizJog[5][5]){
    int ptvermelho = 0, ptverde = 0, ptamarelo = 0, ptazul = 0;
    int vitoria = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(matrizTam > 0){
                switch (matrizJog[i][j]){
                    case 1: ptvermelho += matrizTam[i][j]; break;
                    case 2: ptverde += matrizTam[i][j]; break;
                    case 3: ptamarelo += matrizTam[i][j]; break;
                    case 4: ptazul += matrizTam[i][j]; break;
                }
            }
        }
    }

    printf("\33[1;31mPontos do vermelho: \33[1;37m%d\n", ptvermelho);
    printf("\33[1;32mPontos do verde: \33[1;37m%d\n", ptverde);
    printf("\33[1;33mPontos do amarelo: \33[1;37m%d\n", ptamarelo);
    printf("\33[1;36mPontos do azul: \33[1;37m%d\n", ptazul);

    // Definindo vitória (o ultimo da rodada tem privilégios em caso de empate)
    // Ordem das rodadas: Vermelho -> Verde -> Amarelo -> Azul
    if (ptazul >= ptamarelo && ptazul >= ptverde && ptazul >= ptvermelho){
        vitoria = 4;
        printf("VITÓRIA DO AZUL!!!\n");
    }
    if (ptamarelo > ptazul && ptamarelo >= ptverde && ptamarelo >= ptvermelho){
        vitoria = 3;
        printf("VITÓRIA DO AMARELO!!!\n");
        }
    if (ptverde > ptamarelo && ptverde > ptazul && ptverde >= ptvermelho){
        vitoria = 2;
        printf("VITÓRIA DO VERDE!!!\n");
        }
    if (ptvermelho > ptverde && ptvermelho > ptamarelo && ptvermelho > ptazul){
        vitoria = 1;
        printf("VITÓRIA DO VERMELHO!!!\n");
        }

    return vitoria;
}

int main(){
    time_t t;	
	srand((unsigned) time(&t));

    int vencedor = 0;

    int matrizTam[5][5] = {0, 1, 1, 1, 0,
                           1, 1, 1, 1, 1,
                           1, 1, 0, 1, 1,
                           1, 1, 1, 1, 1,
                           0, 1, 1, 1, 0};

    int matrizJog[5][5];
    int jog[4] = {5, 5, 5, 5};
    for (int linha = 0 ; linha < 5 ; linha++){
        for (int coluna = 0 ; coluna < 5 ; coluna++){
            if (matrizTam[linha][coluna] == 0)
                matrizJog[linha][coluna] = 0;
            else {
                int sort = 0;
                do sort = ((rand()%4)+1); while (jog[sort-1] == 0);
                matrizJog[linha][coluna] = sort;
                jog[sort-1]--;
            }
        }
    }

    int continuar = 0, rodada = 1, vez = 0;

    int opc = mostrarMenu();
    switch (opc){
        case 1: continuar = 1; break;
        case 2: mostrarTutorial(); break;
        case 3: mostrarCreditos(); break;
    }

    // Iniciando o Jogo
    if (continuar == 1){
        char nome[30];
        printf("\33[1;34m>>> Digite o nome do Jogo: \33[1;37m");
        getchar();
        gets(nome);

        int vez = 0;

        while (continuar == 1){
            exibeTabuleiro(matrizTam, matrizJog);
            int fim = fimPartida(matrizTam, matrizJog, vez);
            if (fim == 1111){
                continuar = 0;
                vencedor = contarVitoria(matrizTam, matrizJog);
            }

            else {
                int pularvermelho = 0, pularverde = 0, pularamarelo = 0, pularazul = 0;
                int pular = 0;

                if (fim % 10 == 1)
                    pularazul = 1;

                if ((fim%100)/10 == 1)
                    pularamarelo = 1;

                if ((fim % 1000)/100 == 1)
                    pularverde = 1;

                if (fim/1000 == 1)
                    pularvermelho = 1;
                

                // Exibindo a rodada
                vez = trocaTurno(rodada, vez);

                // Se a vez for de um jogador, mas ele não tiver peças, pula ele:
                if ((vez == 1 && pularvermelho == 1 ) || (vez == 2 && pularverde == 1) ||
                    (vez == 3 && pularamarelo == 1) || (vez == 4 && pularazul == 1))
                        rodada++;

                else {
                    int validacao, destino;
                    char peca[2];

                    printf("\nVez do Jogador ");
                    switch (vez){
                        case 1: printf("\33[1;31mVermelho"); break;
                        case 2: printf("\33[1;32mVerde"); break;
                        case 3: printf("\33[1;33mAmarelo"); break;
                        case 4: printf("\33[1;36mAzul"); break;
                    }

                    printf("\n>>> Digite uma peça: \33[1;37m");
                    scanf("%s", peca);
                    validacao = validaPeca(peca, vez, matrizJog);
                    printf("\33[1;35m>>> Para qual posição você quer ir? [NumPad]\33[1;37m ");
                    scanf("%d", &destino);

                    // Recebendo a posição da peça
                    if (validacao == 1){
                        int pos = posicaoMatriz(vez, matrizJog, peca);
                        int posl = ((pos - (pos % 10)) / 10) - 1;
                        int posc = (pos % 10) - 1;
                        int posl2 = posl, posc2 = posc, errado = 0;

                        if (destino == 7 || destino == 8 || destino == 9) // Subindo
                            posl2--;
                        if (destino == 1 || destino == 2 || destino == 3) // Descendo
                            posl2++;
                        if (destino == 7 || destino == 4 || destino == 1) // Esquerda
                            posc2--;
                        if (destino == 9 || destino == 6 || destino == 3) // Direita
                            posc2++;

                        int mov = validaMovimento(vez, posl, posl2, posc, posc2, destino, matrizJog, matrizTam, rodada);

                        if (mov == 0){
                            matrizTam[posl2][posc2] += matrizTam[posl][posc];
                            matrizTam[posl][posc] = 0;
                            matrizJog[posl2][posc2] = matrizJog[posl][posc];
                            matrizJog[posl][posc] = 0;
                            rodada++;
                        } else {
                            printf("Pressione ENTER para tentar novamente.");
                            vez--;
                            getchar();
                        }
                    } else {
                        vez--;
                    }

                    if (validacao == 0){
                        printf("ERRO! Você escolheu uma casa inválida!\n");
                        printf("Pressione ENTER para tentar novamente.");
                        getchar();
                    }
                getchar();       
                }
            }
        }
    }
    return 0;
}