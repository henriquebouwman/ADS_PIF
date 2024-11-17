**Grupo**:  
- [Henrique Bouwman](https://github.com/henriquebouwman)  
- [Manuel Galvão](https://github.com/manuelfgalvao)  
- [Lucas Ferreira](https://github.com/lukitas20-beep)
- [João Rietra](https://github.com/jhlr)

**Disciplina**: Programação Imperativa e Funcional  
**Instituição**: CESAR School  

# i-C-mines

## Como Jogar
1. Iniciar o Jogo: O jogo começa com um campo de 10x10 células, onde 10 minas estão escondidas aleatoriamente. Cada célula pode conter uma mina ou um número indicando quantas minas estão ao seu redor.

2. Explorar Células:
- Abrir uma célula: Escolha uma posição para abrir. Se uma mina estiver presente, o jogo termina, e você perde.
- Número de minas vizinhas: Se a célula não contém uma mina, ela mostrará um número indicando quantas minas existem nas células adjacentes.
- Propagar células vazias: Se a célula for “0” (sem minas ao redor), ela abrirá automaticamente as células próximas até encontrar células com números.

3. Marcar uma célula:
- Caso desconfie de uma mina, marque a célula. Você pode marcar quantas quiser, mas cuidado com marcações desnecessárias!
- Para vencer, é preciso abrir todas as células livres de minas sem explodir nenhuma mina!

4. Terminar o Jogo:
- O jogo termina se todas as células sem mina forem abertas, ou se você acidentalmente abrir uma mina.
- Dica: Use os números como pistas para identificar áreas seguras.

## Descrição
Bem-vindo ao i-C-mines, onde enxergar ou não enxergar uma mina faz toda a diferença! Neste desafio explosivo, você terá que abrir caminho por um campo repleto de minas ocultas, confiando em sua lógica e instintos para sair vitorioso. Afinal, i-C-mines, do you see?

O campo de jogo é um tabuleiro 10x10, e, espalhadas por ele, estão várias minas à espera do próximo movimento. Seu objetivo? Desvendar todas as células seguras e marcar as minas suspeitas sem cair em uma armadilha. Cada célula aberta revelará pistas, números que mostram quantas minas estão por perto – use esses números para traçar seu caminho e evitar o perigo.

Marque as células que suspeita serem minas e continue explorando com cuidado. Se abrir uma célula com uma mina, o jogo termina, e a vitória escapa de suas mãos! Mas se conseguir limpar o campo, poderá dizer com orgulho: “i-C-mines, and I conquered!”

Então, está preparado? Abra o olho, tome cada decisão com cuidado e tente ver as minas antes que elas vejam você. Boa sorte!

## Implementação da mecânica do jogo
A implementação da mecânica do jogo i-C-mines pode ser feita em C para combinar simplicidade e controle direto sobre os dados.

1. Estrutura do Projeto
   
1.1 Arquivos principais:
-main.c: Contém o loop principal e chama as funções do jogo.
-game_logic.c e game_logic.h: Implementam e declaram funções para a lógica do jogo.
-board.c e board.h: Implementam e declaram funções para criar e manipular o tabuleiro.

1.2 Estruturas de Dados:
-Uma matriz de tamanho fixo (10x10, por exemplo) para o tabuleiro.
-Cada célula será representada por uma estrutura
-O tabuleiro será uma matriz de Cell

2. Etapas da Implementação
2.1 Inicializar o Tabuleiro
-Uma função para inicializar o tabuleiro:
-Colocar minas aleatoriamente.
-Calcular o número de minas ao redor para cada célula.

2.2 Exibir o Tabuleiro
-Criar uma função para exibir o tabuleiro
-Mostrar o estado atual (aberto, marcado, ou oculto)

2.3 Abrir uma Célula
-Uma função para abrir uma célula. Se a célula for "0", propague a abertura para as células adjacentes.

2.4 Marcar uma Célula
-Permite que o jogador marque células suspeitas.

2.5 Loop Principal
-Implementa o loop principal para:
2.5.1 Exibir o tabuleiro.
2.5.2 Aceitar entradas do jogador.
2.5.3 Checar condições de vitória/derrota.

## Pontuação do Jogo

No i-C-mines, a pontuação foi projetada para incentivar boas estratégias e minimizar penalidades. Abaixo, seguem as regras para o cálculo da pontuação:

Ações Positivas:

Abrir uma célula segura: +10 pontos por célula.
Marcar uma mina corretamente: +20 pontos por mina marcada.

Ações Negativas:

Abrir uma célula com mina: -50 pontos (+eliminação).
Marcar uma célula incorretamente: -10 pontos.

Pontuação Final:

-Ao final do jogo, a pontuação será exibida. Vencer o jogo sem abrir nenhuma mina garante uma pontuação mais alta.
-Caso o jogador perca, a pontuação ainda será exibida como forma de feedback.
-Esses valores foram definidos para promover um equilíbrio entre risco e recompensa durante o jogo.

## Implementação da Pontuação (Código)
Adicionar um sistema de pontuação ao jogo utilizando uma variável global ou parte de uma estrutura para rastrear o progresso do jogador.

Passo 1: Adicionar a variável de pontuação
Uma variável declarada para rastrear os pontos do jogador:

Passo 2: Atualizar a pontuação com base nas ações
2.1 Abrir uma célula segura: Setão adicionados +10 pontos na função reveal_cell quando o jogador abrir uma célula segura.
2.2 Marcar uma mina corretamente: Adicione +20 pontos na função mark_cell quando o jogador marcar uma mina corretamente.
2.3 Marcar uma célula incorretamente: Subtraia 10 pontos se o jogador marcar uma célula errada.
2.4 Abrir uma célula com mina: Subtraia 50 pontos na função reveal_cell se o jogador abrir uma mina.

Passo 3: Exibir a pontuação final
No final do jogo (vitória ou derrota), a pontuação acumulada será exibida:

Passo 4: Exibir a pontuação durante o jogo (opcional)
Permitir que o jogador veja sua pontuação atual durante o jogo:
