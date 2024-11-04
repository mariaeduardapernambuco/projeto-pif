# 🎮 **Projeto PIF** 🎮


## 👥 **Equipe**

| Nome                      | GitHub                                                   |
|----------------------------|----------------------------------------------------------|
| Dayanne Cristina Moraes      | [@dayanne](https://github.com/dayannemoraes)                      |
| Ewerton Monteiro de Lima    | [@ewerton](https://github.ewertonmonteiroo)                      |
| Maria Eduarda Pernambuco    | [@eduarda](https://github.com/mariaeduardapernambuco)      |
| Gabriel Farias   | [@gabriel](https://github.com/gabrielfariaxs)      |

## 📚 **Disciplina**
**Programação Imperativa e Funcional - 2024.2**

## 🏫 **Instituição**
**CESAR School**

---

## 📝 **Descrição do Projeto**

Este projeto traz uma versão do clássico jogo da cobrinha (Snake) para o terminal, usando
uma interface básica com a biblioteca "ncurses". O objetivo é fazer com que a cobra coma a
"comida" que aparece na tela. Cada vez que a cobra come, ela cresce, tornando o jogo mais
desafiador, sua velocidade também é aumentada, ou seja, ela fica mais veloz, assim o nível
de dificuldade fica maior, já que o jogador precisa evitar colisões com as bordas e com o
próprio corpo da cobra.
O jogador usa as teclas W para mover a cobra para cima, A para esquerda, S para baixo e
D para a direita. O jogo termina se a cobra bater nas bordas ou no próprio corpo. Cada
comida consumida aumenta o tamanho da cobra, exigindo mais habilidade e controle.

## 🎯 **Implementação da Mecânica do Jogo**

Inicialização: A função "init_game" define o ambiente inicial, posicionando a cobra no
centro e colocando a comida em um ponto aleatório da tela.
Controle de Direção: A função "handle_input" detecta as teclas pressionadas e muda a
direção da cobra, evitando viradas de 180o (como de direita para esquerda de forma direta).
Movimentação e Crescimento: A função "update_snake" move a cobra na direção atual. Se
a cobra come a comida, ela cresce, e a comida reaparece em outra posição aleatória.
Verificação de Colisões: A mesma função "update_snake" verifica se a cobra colidiu com
as bordas ou consigo mesma; se isso acontecer, o jogo termina.
Renderização: A função "draw_screen" desenha a cobra, a comida e as bordas na tela.
A estrutura do código divide bem as tarefas de cada função, tornando a lógica do jogo fácil
de entender e manter.

### **Objetivos do Projeto**
- Desenvolver um jogo interativo em C.
- Aplicar conceitos de programação funcional e imperativa.
- Organizar o código em uma estrutura modular utilizando a CLI-lib.

---

📬 Contatos

Dayane Cristina Moraes: <a href="mailto:dcmi@cesar.school">dcmi@cesar.school</a>
Ewerton Monteiro de Lima: <a href="mailto:emlb@cesar.school">emlb@cesar.school</a>
Maria Eduarda Pernambuco: <a href="mailto:mepsl@cesar.school">mepsl@cesar.school</a>
Gabriel Farias <a href="mailto:gfm@cesar.school">gfm@cesar.school</a>

---
<p align="center"> Desenvolvido com ❤️ por Dayanne, Ewerton,Gabriel e Maria Eduarda </p>
---

## 📂 **Estrutura do Repositório**

Aqui está a organização do repositório de acordo com as especificações do projeto:

```plaintext
/projeto
├── src/         # Código-fonte (.c)
├── include/     # Arquivos de cabeçalho (.h)
├── build/       # Saídas de compilação
├── README.md    # Documentação do projeto
├── Makefile     # Arquivo de automação da compilação (opcional)
└── LICENSE      # Licença do projeto (opcional)
