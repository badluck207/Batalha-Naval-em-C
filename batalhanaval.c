#include <stdio.h>
#define navio 3
#define bomba 2
// Função para exibir o tabuleiro
void inicializarTabuleiro(int visiveltabuleiro[10][10], int invisiveltabuleiro[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            visiveltabuleiro[i][j] = 0;   // Nenhum tiro registrado
            invisiveltabuleiro[i][j] = 0; // Sem navios visíveis
        }
    }

    // Posicionando navios no tabuleiro invisível
    invisiveltabuleiro[0][0] = navio;
    invisiveltabuleiro[0][1] = navio;
    invisiveltabuleiro[0][2] = navio;

    invisiveltabuleiro[7][6] = navio;
    invisiveltabuleiro[8][6] = navio;
    invisiveltabuleiro[9][6] = navio;

    invisiveltabuleiro[7][1] = navio;
    invisiveltabuleiro[8][2] = navio;
    invisiveltabuleiro[9][3] = navio;
};
// Exibe o tabuleiro visível (o que o jogador vê)
void exibirTabuleiro(int visiveltabuleiro[10][10])
{
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n   ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            if (visiveltabuleiro[i][j] == 0)
                printf("0 "); // Agua
            else if (visiveltabuleiro[i][j] == bomba)
                printf("X "); // Erro
            else
                printf("3 "); // Acertou
        }
        printf("\n");
    }
}
// Função do jogo principal
void jogar(int visiveltabuleiro[10][10], int invisiveltabuleiro[10][10])
{
    char menu;
    int escolhaLinha, escolhaColuna;

    // Entrada do usuario
    do
    {
        printf("\nEscolha uma linha(1-10): ");
        scanf("%d", &escolhaLinha);

        printf("\n");

        printf("Escolha uma Coluna(1-10): ");
        scanf("%d", &escolhaColuna);

        if (invisiveltabuleiro[escolhaLinha - 1][escolhaColuna - 1] == navio)
        {
            printf("Voce Acertou uma Parte do Navio");
            visiveltabuleiro[escolhaLinha - 1][escolhaColuna - 1] = navio;
        }
        else
        {
            printf("Bomba!Voce errou, Tente Novamente...");
            visiveltabuleiro[escolhaLinha - 1][escolhaColuna - 1] = bomba;
        }

        printf("\n");

        // Exibe o tabuleiro
        exibirTabuleiro(visiveltabuleiro); // mostra o tabuleiro visivel
        printf("\n");
        printf("Pressione 'S' Continuar ou 'N' para voltar ao Menu: "); // Entrada para continuar e sair do jogo
        scanf(" %c", &menu);

        if (menu == 'S' || menu == 's') // condição de continuar e sair do jogo
        {
            printf("\nContinuando o jogo ....\n");
        }
        else if (menu != 's' && menu != 'S' && menu != 'n' && menu != 'N')
        {
            printf("\nEscolha uma opcao valida!\n");
        }
        else
        {
            printf("\nVoltando ao menu principal....\n");
        }

    } while (menu == 'S' || menu == 's');
};

int main()
{
    int opcao;
    int invisiveltabuleiro[10][10];
    int visiveltabuleiro[10][10];

    inicializarTabuleiro(visiveltabuleiro, invisiveltabuleiro);

    do
    {
        // Menu principal
        printf("\n");
        printf("================================\n");
        printf(" BATALHA NAVAL - DESAFIO NO MAR  \n");
        printf("================================\n");
        printf("1) Regras \n");
        printf("2) Jogar \n");
        printf("3) Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("\nRegras do Jogo: \n"); // regras do jogo
            printf("1) Acerte onde esta o navio \n");
            printf("2) Ganha quem acerta o navio todo primeiro Representado com '3' e as bombas com 'X' \n");
            printf("3) Boa sorte! \n");
            printf("\nPressione 'ENTER' para voltar ao menu principal... ");
            getchar();
            break;
        case 2:
            jogar(visiveltabuleiro, invisiveltabuleiro);
            break;
        case 3:
            printf("Pressione 'ENTER' para sair... \n");
            getchar();
            break;
        default:
            printf("Opcao invalida, Tente Novamente... \n");
            break;
        }
    } while (opcao != 3);

    return 0;
}