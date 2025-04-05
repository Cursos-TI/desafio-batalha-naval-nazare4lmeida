#include <stdio.h>

#define TAM 10 //aqui eu defini o tamanho do tabuleiro 10x10
#define TAM_NAVIO 3 //aqui eu defini o tamanho dos navios 3 posições
#define NAVIO 3 //esse é o valor que vai representar o navio no tabuleiro
#define AGUA 0 //e esse é o valor que representa a água no tabuleiro

//aqui a estrutura para armazenar coordenadas (linha = x, coluna = y)
typedef struct {
    int x, y;
} Coordenada;

//e essa é a função que criei para exibir o tabuleiro completo no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {              
        for (int j = 0; j < TAM; j++) {          
            printf("%d ", tabuleiro[i][j]);      
        }
        printf("\n");                            
    }
}

// Função para exibir as coordenadas de um navio específico
void exibirCoordenadas(Coordenada navio[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {        //aqui faz a iteração sobre as partes do navio
        printf("(%d, %d) ", navio[i].x, navio[i].y); //aqui imprime coordenadas
    }
    printf("\n");                               
}

// Verificando se é possível posicionar o navio sem sair dos limites ou sobrepor outro
int podeColocar(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + i * dx;   //aqui vai calcular a nova linha a cada passo
        int y = coluna + i * dy;  //e aqui vai calcular a nova coluna a cada passo
        if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] != AGUA)
            return 0; //isso significa que não pode colocar (fora dos limites ou já ocupado)
    }
    return 1; //essa linha significa que pode colocar
}

//essa parte posiciona o navio no tabuleiro e armazena suas coordenadas
void colocarNavio(int tabuleiro[TAM][TAM], Coordenada navio[], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + i * dx;   //aqui é a linha da parte atual do navio
        int y = coluna + i * dy;  //e aqui é a coluna da parte atual do navio
        tabuleiro[x][y] = NAVIO;  //aqui está marcando a posição no tabuleiro com 3 (NAVIO)
        navio[i].x = x;           //aqui armazena linha na struct
        navio[i].y = y;           //e aqui armazena coluna na struct
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};               //Inicializando toda a matriz com 0 (água)
    Coordenada navios[4][TAM_NAVIO];             //Vetor de 4 navios, cada um com 3 coordenadas

    //Posiciona o primeiro navio horizontal (da esquerda para direita)
    if (podeColocar(tabuleiro, 1, 1, 0, 1))      // dx = 0 (mesma linha), dy = 1 (colunas crescem)
        colocarNavio(tabuleiro, navios[0], 1, 1, 0, 1);

    //Posiciona o segundo navio vertical (de cima para baixo)
    if (podeColocar(tabuleiro, 5, 2, 1, 0))      // dx = 1 (linhas crescem), dy = 0 (mesma coluna)
        colocarNavio(tabuleiro, navios[1], 5, 2, 1, 0);

    //Posiciona o terceiro navio na diagonal principal 
    if (podeColocar(tabuleiro, 2, 2, 1, 1))      // dx = 1, dy = 1 (linha e coluna crescem)
        colocarNavio(tabuleiro, navios[2], 2, 2, 1, 1);

    //Posiciona o quarto navio na diagonal secundária 
    if (podeColocar(tabuleiro, 0, 8, 1, -1))     // dx = 1 (linha cresce), dy = -1 (coluna decresce)
        colocarNavio(tabuleiro, navios[3], 0, 8, 1, -1);

    //essa parte exibe as coordenadas de cada navio
    printf("Coordenadas dos Navios:\n");
    for (int i = 0; i < 4; i++) {
        printf("Navio %d: ", i + 1);
        exibirCoordenadas(navios[i]);           //aqui mostra coordenadas do navio atual
    }

    //e por último, essa parte exibe o tabuleiro completo com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}


//Estou colocando tudo comentado pra não me perder e entender o que estou fazendo.