#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

// --- DEFINIÃ‡ÃƒO DE CORES ANSI ---
#define COR_RESET   "\033[0m"
#define COR_CYAN    "\033[1;36m" // Ciano brilhante
#define COR_AMARELO "\033[1;33m" // Amarelo brilhante
#define COR_VERDE    "\033[1;32m"
#define COR_DICA    "\033[1;35m" // Magenta brilhante
#define COR_SUCESSO "\033[1;32m" // Verde brilhante

// --- ESTRUTURA DO JOGO ---
typedef struct {
    char palavra[30];
    char dica[50];
    char link[150];
} ElementoJogo;

// --- BANCO DE DADOS DOS TEUS 4 CANTORES ---
ElementoJogo listaArtistas[] = {
    {"ANITTA", "Cantora Pop Brasileira", "https://www.youtube.com/watch?v=kR2A26sJm-c"},
    {"GAL COSTA", "Icone da MPB e Tropicalia", "https://www.youtube.com/watch?v=1u4vJ4UakB4"},
    {"DJAVAN", "Mestre da MPB e Samba-Jazz", "https://www.youtube.com/watch?v=9gWzM5wHkYg"},
    {"ZECA PAGODINHO", "Lenda do Samba e Pagode", "https://www.youtube.com/watch?v=Vz2yTjM3A70"}
};

int totalPalavras = sizeof(listaArtistas) / sizeof(listaArtistas[0]);

// --- PROTÃ“TIPOS DAS FUNÃ‡Ã•ES ---
void limparTela(void);
void exibirMenu(void);
void exibirSobre(void);
void iniciarJogo(void);

// --- FUNÃ‡ÃƒO PARA LIMPAR O ECRÃƒ ---
void limparTela(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// --- LÓGICA DO JOGO (ETAPA 2 & PREPARAÇÃO PARA ETAPA 3) ---
void iniciarJogo(void) {
    limparTela();

    // Sorteia um índice da lista de 4 artistas
    int indiceSorteado = rand() % totalPalavras;
    ElementoJogo jogoAtual = listaArtistas[indiceSorteado];

    int tamanho = strlen(jogoAtual.palavra);
    char mascara[30];

    // Cria a máscara: substitui letras por '_' e preserva espaços
    for (int i = 0; i < tamanho; i++) {
        if (jogoAtual.palavra[i] == ' ') {
            mascara[i] = ' ';
        } else {
            mascara[i] = '_';
        }
    }
    mascara[tamanho] = '\0'; // Finaliza a string em C

    printf(COR_CYAN "=== JOGO DA FORCA - MUSICA & CANTORES ===\n\n" COR_RESET);
    printf(COR_DICA "Dica: %s\n\n" COR_RESET, jogoAtual.dica);

    // Exibe a máscara formatada com espaços entre os caracteres
    printf("Palavra: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", mascara[i]);
    }
    printf("\n\n");

    // --- MENSAGEM DO LINK (TEXTO NORMAL, SEM COR) ---
    printf("Neste link voce consegue acessar os sucessos desse grande artista, aproveite! \n");
    printf("Playlist: %s\n\n", jogoAtual.link);

    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Consome o Enter pendente
    getchar();
}

// --- EXIBIÃ‡ÃƒO DA TELA "SOBRE" ---
void exibirSobre(void) {
    limparTela();
    printf(COR_CYAN "=============================================\n" COR_RESET);
    printf(COR_CYAN "              SOBRE O JOGO                   \n" COR_RESET);
    printf(COR_CYAN "=============================================\n\n" COR_RESET);
    printf("Jogo da Forca desenvolvido em Linguagem C.\n");
    printf("Desenvolvido no ambito da UC 00606.\n\n");
    printf("Pressione Enter para voltar ao menu...");
    getchar();
    getchar();
}

// --- MENU PRINCIPAL ---
void exibirMenu(void) {
    int opcao = 0;

    do {
        limparTela();
        printf(COR_CYAN "=============================================\n" COR_RESET);
        printf(COR_VERDE "         BEM-VINDO AO JOGO DA FORCA          \n" COR_RESET);
        printf(COR_CYAN "=============================================\n\n" COR_RESET);

        printf(COR_AMARELO "1." COR_RESET " Jogar\n");
        printf(COR_AMARELO "2." COR_RESET " Sobre\n");
        printf(COR_AMARELO "3." COR_RESET " Sair\n\n");

        printf(COR_CYAN "=============================================\n" COR_RESET);
        printf("Escolha a opcao pretendida: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
            while (getchar() != '\n');
        }

        switch (opcao) {
            case 1:
                iniciarJogo();
                break;
            case 2:
                exibirSobre();
                break;
            case 3:
                printf("\nObrigado por jogar! Ate a proxima.\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                getchar();
                getchar();
                break;
        }

    } while (opcao != 3);
}

// --- FUNÃ‡ÃƒO PRINCIPAL ---
int main(void) {
    setlocale(LC_ALL, "Portuguese");

#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    // Inicializa a semente para sorteios aleatÃ³rios reais
    srand(time(NULL));

    exibirMenu();

    return 0;
}

