// Desafio Batalha Naval - Nível Mestre
// Habilidades Especiais com Matrizes

// Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h> // Para função abs()

// Função principal
int main() {
    
    // Declaração da matriz bidimensional para representar o tabuleiro 10x10
    int tabuleiro[10][10];
    
    // Tamanho fixo dos navios
    int tamanho_navio = 3;
    
    // Coordenadas iniciais dos quatro navios (mantendo do nível aventureiro)
    int navio1_linha = 1, navio1_coluna = 4; // Navio horizontal
    int navio2_linha = 4, navio2_coluna = 8; // Navio vertical
    int navio3_linha = 0, navio3_coluna = 0; // Navio diagonal principal (↘)
    int navio4_linha = 6, navio4_coluna = 9; // Navio diagonal secundária (↙)
    
    // Inicialização do tabuleiro com água (valor 0)
    printf("=== BATALHA NAVAL - NÍVEL MESTRE ===\n");
    printf("Inicializando tabuleiro...\n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
    
    // Posicionamento dos navios (código do nível aventureiro)
    printf("Posicionando navios...\n");
    
    // Navio horizontal
    if(navio1_coluna + tamanho_navio - 1 < 10) {
        for(int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    }
    
    // Navio vertical
    if(navio2_linha + tamanho_navio - 1 < 10) {
        for(int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
        }
    }
    
    // Navio diagonal principal
    if(navio3_linha + tamanho_navio - 1 < 10 && navio3_coluna + tamanho_navio - 1 < 10) {
        for(int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    }
    
    // Navio diagonal secundária
    if(navio4_linha + tamanho_navio - 1 < 10 && navio4_coluna - tamanho_navio + 1 >= 0) {
        for(int i = 0; i < tamanho_navio; i++) {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    }
    
    // === IMPLEMENTAÇÃO DO NÍVEL MESTRE - HABILIDADES ESPECIAIS ===
    
    // Definição do tamanho das matrizes de habilidade (5x5)
    int tamanho_habilidade = 5;
    
    // Matrizes para as habilidades especiais
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];
    
    // Pontos de origem das habilidades no tabuleiro
    int cone_origem_linha = 2, cone_origem_coluna = 2;
    int cruz_origem_linha = 5, cruz_origem_coluna = 2;
    int octaedro_origem_linha = 7, octaedro_origem_coluna = 5;
    
    printf("Criando habilidades especiais...\n");
    
    // === CRIAÇÃO DA HABILIDADE CONE ===
    printf("- Gerando habilidade CONE...\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            // Cone: ponto no topo (i=0, j=centro) expandindo para baixo
            int centro = tamanho_habilidade / 2; // Centro = 2 (para matriz 5x5)
            
            // Lógica do cone: a largura aumenta conforme desce
            if(i == 0 && j == centro) {
                cone[i][j] = 1; // Ponto do topo
            } else if(i == 1 && (j >= centro-1 && j <= centro+1)) {
                cone[i][j] = 1; // Segunda linha: 3 posições
            } else if(i == 2 && (j >= centro-2 && j <= centro+2)) {
                cone[i][j] = 1; // Terceira linha: 5 posições (base)
            } else {
                cone[i][j] = 0; // Outras posições
            }
        }
    }
    
    // === CRIAÇÃO DA HABILIDADE CRUZ ===
    printf("- Gerando habilidade CRUZ...\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            int centro = tamanho_habilidade / 2; // Centro = 2
            
            // Lógica da cruz: linha central e coluna central
            if(i == centro || j == centro) {
                cruz[i][j] = 1; // Linha ou coluna central
            } else {
                cruz[i][j] = 0; // Outras posições
            }
        }
    }
    
    // === CRIAÇÃO DA HABILIDADE OCTAEDRO ===
    printf("- Gerando habilidade OCTAEDRO (losango)...\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            int centro = tamanho_habilidade / 2; // Centro = 2
            
            // Lógica do losango: distância Manhattan do centro <= raio
            int distancia = abs(i - centro) + abs(j - centro);
            
            if(distancia <= centro) {
                octaedro[i][j] = 1; // Dentro do losango
            } else {
                octaedro[i][j] = 0; // Fora do losango
            }
        }
    }
    
    // === APLICAÇÃO DAS HABILIDADES NO TABULEIRO ===
    printf("Aplicando habilidades no tabuleiro...\n");
    
    // Aplicar CONE
    int deslocamento = tamanho_habilidade / 2; // Para centralizar a habilidade
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            if(cone[i][j] == 1) {
                int tabuleiro_linha = cone_origem_linha + i - deslocamento;
                int tabuleiro_coluna = cone_origem_coluna + j - deslocamento;
                
                // Verificar limites do tabuleiro
                if(tabuleiro_linha >= 0 && tabuleiro_linha < 10 && 
                   tabuleiro_coluna >= 0 && tabuleiro_coluna < 10) {
                    // Só aplicar se não for um navio (preservar navios)
                    if(tabuleiro[tabuleiro_linha][tabuleiro_coluna] != 3) {
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5; // 5 = área afetada
                    }
                }
            }
        }
    }
    
    // Aplicar CRUZ
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            if(cruz[i][j] == 1) {
                int tabuleiro_linha = cruz_origem_linha + i - deslocamento;
                int tabuleiro_coluna = cruz_origem_coluna + j - deslocamento;
                
                // Verificar limites do tabuleiro
                if(tabuleiro_linha >= 0 && tabuleiro_linha < 10 && 
                   tabuleiro_coluna >= 0 && tabuleiro_coluna < 10) {
                    // Só aplicar se não for um navio ou área já afetada
                    if(tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0) {
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 7; // 7 = cruz
                    }
                }
            }
        }
    }
    
    // Aplicar OCTAEDRO
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            if(octaedro[i][j] == 1) {
                int tabuleiro_linha = octaedro_origem_linha + i - deslocamento;
                int tabuleiro_coluna = octaedro_origem_coluna + j - deslocamento;
                
                // Verificar limites do tabuleiro
                if(tabuleiro_linha >= 0 && tabuleiro_linha < 10 && 
                   tabuleiro_coluna >= 0 && tabuleiro_coluna < 10) {
                    // Só aplicar se não for um navio ou área já afetada
                    if(tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0) {
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 9; // 9 = octaedro
                    }
                }
            }
        }
    }
    
    // === EXIBIÇÃO DO TABULEIRO FINAL ===
    printf("\n=== TABULEIRO COM HABILIDADES ESPECIAIS ===\n");
    printf("Legenda:\n");
    printf("0 = Água  |  3 = Navio  |  5 = Cone  |  7 = Cruz  |  9 = Octaedro\n\n");
    
    // Cabeçalho com números das colunas
    printf("   ");
    for(int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Exibir tabuleiro com números das linhas
    for(int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // === EXIBIÇÃO DAS MATRIZES DE HABILIDADE ===
    printf("\n=== MATRIZES DAS HABILIDADES ===\n");
    
    printf("\nHabilidade CONE (5x5):\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    
    printf("\nHabilidade CRUZ (5x5):\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nHabilidade OCTAEDRO (5x5):\n");
    for(int i = 0; i < tamanho_habilidade; i++) {
        for(int j = 0; j < tamanho_habilidade; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    
    // === INFORMAÇÕES DAS HABILIDADES ===
    printf("\n=== INFORMAÇÕES DAS HABILIDADES ===\n");
    printf("Cone aplicado no ponto (%d, %d)\n", cone_origem_linha, cone_origem_coluna);
    printf("Cruz aplicada no ponto (%d, %d)\n", cruz_origem_linha, cruz_origem_coluna);
    printf("Octaedro aplicado no ponto (%d, %d)\n", octaedro_origem_linha, octaedro_origem_coluna);
    
    return 0;
}