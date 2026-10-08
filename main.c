#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

// --- Definição de CORES ANSI ---
#define COR_RESET    "\033[0m"
#define COR_VERMELHO "\033[1;31m"
#define COR_VERDE    "\033[1;32m"
#define COR_AMARELO  "\033[1;33m"
#define COR_AZUL     "\033[1;34m"
#define COR_CYAN     "\033[1;36m"

// --- PROTOTIPOS DAS FUNÇÕES ---
void limparTela(void);
void exibirMenu(void);
void exibirSobre(void);

// --- FUNÇÃO PARA LIMPAR O ECRÃ ---
void limparTela(void) {
#ifdef _WIN32
	system("CLS");
#else
	system("clear");
#endif
}

// --- FUNÇÃO PARA EXIBIR O SOBRE (CRÉDITOS) ---
void exibirSobre(void) {
	limparTela();
	printf(COR_CYAN "=========================================\n" COR_RESET);
	printf(COR_AMARELO "             SOBRE O JOGO               \n" COR_RESET);
	printf(COR_CYAN "=========================================\n" COR_RESET);
	printf("Jogo da Forca desenvolvido em Linguagem C.\n");
	printf("Desenvolvido no âmbito da UFCD 00606.\n");
	printf(COR_CYAN "=========================================\n\n" COR_RESET);

	printf("Pressione ENTER para voltar ao menu...");
	getchar();
	getchar();
}

// --- FUNÇÃO DO MENU INICIAL ---
void exibirMenu(void) {
	int opcao = 0;

	do {
		limparTela();
		printf(COR_CYAN "=========================================\n" COR_RESET);
		printf(COR_VERDE "        BEM-VINDO AO JOGO DA FORCA      \n" COR_RESET);
		printf(COR_CYAN "=========================================\n" COR_RESET);
		printf(COR_AMARELO "1." COR_RESET " Jogar\n");
		printf(COR_AMARELO "2." COR_RESET " Sobre\n");
		printf(COR_AMARELO "3." COR_RESET " Sair\n");
		printf(COR_CYAN "=========================================\n" COR_RESET);
		printf("Escolha a opção pretendida: ");

		if (scanf("%d", &opcao) != 1) {
			opcao = 0;
			while (getchar() != '\n') {
			}
		}

		switch (opcao) {
			case 1:
				limparTela();
				printf(COR_VERDE "\nIniciando o jogo...\n" COR_RESET);
				printf("(O jogo será implementado na próxima etapa!)\n\n");
				printf("Pressione ENTER para voltar...");
				getchar();
				getchar();
				break;
			case 2:
				exibirSobre();
				break;
			case 3:
				limparTela();
				printf(COR_AMARELO "Obrigado por jogar! Até a prxima.\n" COR_RESET);
				break;
			default:
				printf(COR_VERMELHO "\nOpção inválida! Tente novamente.\n" COR_RESET);
				printf("Pressione ENTER para continuar...");
				getchar();
				getchar();
				break;
		}
	} while (opcao != 3);
}

// --- FUNÇÃO PRINCIPAL ---
int main(void) {
    // Define a localização do sistema para português
    setlocale(LC_ALL, "Portuguese");

#ifdef _WIN32
    // Configura a consola do Windows para UTF-8
    SetConsoleOutputCP(65001);
#endif

    // Inicializa a semente para sorteios aleatórios reais
    srand(time(NULL));

    exibirMenu();

    return 0;
}

