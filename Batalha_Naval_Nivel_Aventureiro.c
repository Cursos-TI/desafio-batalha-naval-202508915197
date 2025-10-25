// Desafio Batalha Naval - Nível Aventureiro
// Tabuleiro Completo e Navios Diagonais

// Bibliotecas necessárias
#include <stdio.h>

// Função principal
int main() {
    
    // Declaração da matriz bidimensional para representar o tabuleiro 10x10
    int tabuleiro[10][10];
    
    // Tamanho fixo dos navios
    int tamanho_navio = 3;
    
    // Coordenadas iniciais dos quatro navios
    int navio1_linha = 1, navio1_coluna = 1; // Navio horizontal
    int navio2_linha = 4, navio2_coluna = 6; // Navio vertical
    int navio3_linha = 0, navio3_coluna = 0; // Navio diagonal principal (↘)
    int navio4_linha = 2, navio4_coluna = 7; // Navio diagonal secundária (↙)
    
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
    
    // Validação e posicionamento do navio diagonal principal (↘)
    printf("Posicionando navio diagonal principal a partir da posição (%d, %d)\n", 
           navio3_linha, navio3_coluna);
    
    // Verificar se o navio diagonal principal cabe no tabuleiro
    if(navio3_linha + tamanho_navio - 1 < 10 && navio3_coluna + tamanho_navio - 1 < 10) {
        // Verificar sobreposição com navios anteriores
        int sobreposicao = 0;
        for(int i = 0; i < tamanho_navio; i++) {
            if(tabuleiro[navio3_linha + i][navio3_coluna + i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        
        if(!sobreposicao) {
            for(int i = 0; i < tamanho_navio; i++) {
                tabuleiro[navio3_linha + i][navio3_coluna + i] = 3; // 3 representa navio
            }
            printf("Navio diagonal principal posicionado com sucesso!\n");
        } else {
            printf("Erro: Navio diagonal principal se sobrepõe a outro navio!\n");
        }
    } else {
        printf("Erro: Navio diagonal principal não cabe no tabuleiro!\n");
    }
    
    // Validação e posicionamento do navio diagonal secundária (↙)
    printf("Posicionando navio diagonal secundária a partir da posição (%d, %d)\n", 
           navio4_linha, navio4_coluna);
    
    // Verificar se o navio diagonal secundária cabe no tabuleiro
    if(navio4_linha + tamanho_navio - 1 < 10 && navio4_coluna - tamanho_navio + 1 >= 0) {
        // Verificar sobreposição com navios anteriores
        int sobreposicao = 0;
        for(int i = 0; i < tamanho_navio; i++) {
            if(tabuleiro[navio4_linha + i][navio4_coluna - i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        
        if(!sobreposicao) {
            for(int i = 0; i < tamanho_navio; i++) {
                tabuleiro[navio4_linha + i][navio4_coluna - i] = 3; // 3 representa navio
            }
            printf("Navio diagonal secundária posicionado com sucesso!\n");
        } else {
            printf("Erro: Navio diagonal secundária se sobrepõe a outro navio!\n");
        }
    } else {
        printf("Erro: Navio diagonal secundária não cabe no tabuleiro!\n");
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
    printf("\n=== COORDENADAS DOS QUATRO NAVIOS ===\n");
    
    printf("Navio 1 - Horizontal (linha %d):\n", navio1_linha);
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio1_linha, navio1_coluna + i);
    }
    
    printf("Navio 2 - Vertical (coluna %d):\n", navio2_coluna);
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio2_linha + i, navio2_coluna);
    }
    
    printf("Navio 3 - Diagonal Principal (↘):\n");
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio3_linha + i, navio3_coluna + i);
    }
    
    printf("Navio 4 - Diagonal Secundária (↙):\n");
    for(int i = 0; i < tamanho_navio; i++) {
        printf("  Posição: (%d, %d)\n", navio4_linha + i, navio4_coluna - i);
    }
    
    printf("\n=== ESTATÍSTICAS ===\n");
    int total_navios = 4;
    int total_posicoes = total_navios * tamanho_navio;
    printf("Total de navios: %d\n", total_navios);
    printf("Tamanho de cada navio: %d posições\n", tamanho_navio);
    printf("Total de posições ocupadas: %d\n", total_posicoes);

    return 0;
}