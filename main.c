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
#define COR_VERDE    "\033[1;32m" //verde
#define COR_DICA    "\033[1;35m" // Magenta brilhante
#define COR_SUCESSO "\033[1;32m" // Verde brilhante
#define COR_TITULO_ROSA "\033[30;45m" // Texto preto, fundo rosa

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

// --- LÓGICA COMPLETA DO JOGO (ETAPA 3) ---
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

    // Variáveis de controlo do jogo
    int tentativasRestantes = 6;
    char letrasArriscadas[30] = ""; // Guarda as letras já digitadas
    int totalArriscadas = 0;
    int ganhou = 0;

    // --- CICLO PRINCIPAL DO JOGO ---
    while (tentativasRestantes > 0 && !ganhou) {
        limparTela();

        printf(COR_TITULO_ROSA " === JOGO DA FORCA - MUSICA & CANTORES === " COR_RESET "\n\n");
        printf(COR_DICA "Dica: %s\n" COR_RESET, jogoAtual.dica);
        printf("Tentativas restantes: %d\n", tentativasRestantes);

        // Exibe as letras já arriscadas
        printf("Letras tentadas: ");
        for (int i = 0; i < totalArriscadas; i++) {
            printf("%c ", letrasArriscadas[i]);
        }
        printf("\n\n");

        // Exibe a palavra mascarada (com espaços entre os caracteres)
        printf("Palavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", mascara[i]);
        }
        printf("\n\n");

        // Pede a letra ao jogador
        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Converte a letra digitada para maiúscula
        if (letra >= 'a' && letra <= 'z') {
            letra = letra - 32;
        }

        // Verifica se a letra já foi tentada antes
        int jaTentou = 0;
        for (int i = 0; i < totalArriscadas; i++) {
            if (letrasArriscadas[i] == letra) {
                jaTentou = 1;
                break;
            }
        }

        if (jaTentou) {
            printf("\nVoce ja tentou a letra '%c'! Tente outra.\n", letra);
            getchar();
            getchar();
            continue; // Volta ao início do ciclo sem gastar tentativa
        }

        // Adiciona a letra ao histórico de tentativas
        letrasArriscadas[totalArriscadas] = letra;
        totalArriscadas++;

        // Verifica se a letra existe na palavra do cantor
        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (jogoAtual.palavra[i] == letra) {
                mascara[i] = letra; // Revela a letra na máscara
                acertou = 1;
            }
        }

        // Se errou a letra, perde uma tentativa
        if (!acertou) {
            tentativasRestantes--;
        }

        // Verifica se o jogador completou todas as letras (se já não há '_')
        if (strchr(mascara, '_') == NULL) {
            ganhou = 1;
        }
    }

    // --- FIM DO JOGO: VITÓRIA OU DERROTA ---
    limparTela();
        printf(COR_TITULO_ROSA " === JOGO DA FORCA - MUSICA & CANTORES === " COR_RESET "\n\n");

    if (ganhou) {
        printf(COR_AMARELO "PARABENS! VOCE ACERTOU A PALAVRA: %s\n\n" COR_RESET, jogoAtual.palavra);
        // Tua mensagem sem cor e a playlist
        printf("Neste link voce consegue acessar os sucessos desse grande artista, aproveite ;) \n");
        printf("Playlist: %s\n\n", jogoAtual.link);
    } else {
        printf("GAME OVER! Voce esgotou as suas tentativas.\n");
        printf("O artista era: %s\n\n", jogoAtual.palavra);
    }

    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Consome a quebra de linha do scanf
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

