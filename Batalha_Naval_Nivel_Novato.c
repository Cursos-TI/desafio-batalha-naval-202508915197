// Desafio Batalha Naval nivel Novato

// Bibliotecas necessárias
#include <stdio.h>

// Função principal
int main() {
    
    // Declaração da matriz bidimensional para representar o tabuleiro 10x10
    int tabuleiro[10][10];
    
    // Tamanho fixo dos navios
    int tamanho_navio = 3;
    
    // Coordenadas iniciais dos navios
    int navio1_linha = 2, navio1_coluna = 1; // Navio horizontal
    int navio2_linha = 5, navio2_coluna = 6; // Navio vertical
    
    // Inicialização do tabuleiro com água (valor 0)
    printf("Inicializando tabuleiro...\n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
    
    // Validação e posicionamento do navio horizontal
    printf("Posicionando navio horizontal na linha %d, a partir da coluna %d\n", 
           navio1_linha, navio1_coluna);
    
    // Verificar se o navio horizontal cabe no tabuleiro
    if(navio1_coluna + tamanho_navio - 1 < 10) {
        for(int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3; // 3 representa navio
        }
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
    }
    
    // Validação e posicionamento do navio vertical
    printf("Posicionando navio vertical na coluna %d, a partir da linha %d\n", 
           navio2_coluna, navio2_linha);
    
    // Verificar se o navio vertical cabe no tabuleiro
    if(navio2_linha + tamanho_navio - 1 < 10) {
        // Verificar sobreposição com o navio horizontal
        int sobreposicao = 0;
        for(int i = 0; i < tamanho_navio; i++) {
            if(tabuleiro[navio2_linha + i][navio2_coluna] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        
        if(!sobreposicao) {
            for(int i = 0; i < tamanho_navio; i++) {
                tabuleiro[navio2_linha + i][navio2_coluna] = 3; // 3 representa navio
            }
            printf("Navio vertical posicionado com sucesso!\n");
        } else {
            printf("Erro: Navios se sobrepõem!\n");
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
    }
    
    // Exibição do tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    printf("Legenda: 0 = Água, 3 = Navio\n\n");
    
    // Cabeçalho com números das colunas
    printf("   ");
    for(int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Exibir tabuleiro com números das linhas
    for(int i = 0; i < 10; i++) {
        printf("%d  ", i); // Número da linha
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // Exibir coordenadas dos navios posicionados
    printf("\n=== COORDENADAS DOS NAVIOS ===\n");
    printf("Navio Horizontal (linha %d):\n", navio1_linha);
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio1_linha, navio1_coluna + i);
    }
    
    printf("Navio Vertical (coluna %d):\n", navio2_coluna);
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio2_linha + i, navio2_coluna);
    }

    return 0;
}