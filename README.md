Hangman
# Jogo da Cobrinha

## O que é?

O jogo da cobrinha é um jogo que apresenta um labirinto com uma cobra e uma saida. O objetivo é encontrar o caminho até a saida do labirinto

## Como jogar?

O jogo não permite jogadores, o sistema simula o comportamento da cobra e, através do backtracking, busca a solução do labirinto

## Como compilar e executar?

Para compilar e poder jogar, é preciso seguir os seguintes passos:

1.  Na raís do projeto, executar o Cmake passando como source a pasta core e como build a pasta build

```sh
Snaze/  $ cmake -S core -B build
```

2. Em seguida, compilando a pasta build

```
Snaze/  $ cmake --build build
```

3. Executar o arquivo executável passando como parâmetro na linha de argumento o arquivo .dat que possui o labirinto, como por exemplo

```sh
./build/solver ./files/maze.dat
```

## Exemplos

O arquivo maze.dat é um exemplo de labirinto que possui solução, o arquivo dead_end.dat é um exemplo de labirinto que não possui solução.