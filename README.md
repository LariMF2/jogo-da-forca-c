# 🎵 Jogo da Forca em C - Música & Cantores

Jogo da Forca desenvolvido na Linguagem C como projeto prático para a unidade curricular **UC 00606 - Desenvolver Programas em Linguagem Estruturada**.

---

## 📌 Sobre o Projeto

O projeto consiste num jogo interativo de consola com a temática **Música & Cantores**. O sistema sorteia aleatoriamente um artista do banco de dados, apresenta uma dica contextualizada e permite ao jogador adivinhar a palavra letra por letra dentro de um limite de 6 tentativas.

### 🌟 Diferenciais e Funcionalidades
- **Interface Colorida (ANSI Escape Codes):** Destaque visual com menu em Ciano/Amarelo, dica em Rosa/Magenta, título em fundo rosa com texto preto, vitória em Amarelo/Verde e *Game Over* em Vermelho.

- **Arte ASCII da Forca:** Animação gráfica progressiva do boneco à medida que o jogador comete erros.

- **Integração com Playlists:** Ao vencer, o jogador recebe uma mensagem personalizada e o link direto para a playlist dos maiores sucessos do artista sorteado no YouTube.

- **Suporte a Acentos e Caracteres UTF-8:** Configurado via `SetConsoleOutputCP(65001)` no ambiente Windows (UCRT64/GCC).

- **Tratamento de Espaços:** Suporte para nomes compostos (ex: *GAL COSTA*, *ZECA PAGODINHO*).

---

## 🎤 Banco de Dados de Artistas

O jogo conta com a seguinte lista de artistas cadastrados:
1. **ANITTA** — *Dica: Cantora Pop Brasileira*
2. **GAL COSTA** — *Dica: Ícone da MPB e Tropicália*
3. **DJAVAN** — *Dica: Mestre da MPB e Samba-Jazz*
4. **ZECA PAGODINHO** — *Dica: Lenda do Samba e Pagode*

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** GCC (MSYS2 UCRT64 / MinGW)
- **Editor de Código:** VS Code
- **Controlo de Versão:** Git & GitHub

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
- Compilador `gcc` instalado e configurado no ambiente.

### Passos para compilar e rodar
1. Clona este repositório:
   ```bash
   git clone [https://github.com/LariMF2/jogo-da-forca-c.git](https://github.com/LariMF2/jogo-da-forca-c.git)