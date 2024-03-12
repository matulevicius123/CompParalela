# Lab 2

## Sobre o repositório
Esta implementação de multiplicação de matrizes e vetores foi criada na linguagem de programação C para realização do Lab 2 da disciplina de Computação Paralela. 

A implementação das threads foi feita utilizando a biblioteca pthreads, e a execução do programa e o commit foram realizados através da plataforma AWS.

Dividindo a matriz pelo número de threads disponibilizadas pelas variáveis do programa, a paralelização é maximizada para o número de threads disponíveis.

![alt](/Lab02-MultiplicacaoMatrizVetor/img/1.png)

### Instalação
Instale o git com o comando `sudo yum install git`. Com o git instalado, execute o comando `git clone https://github.com/matulevicius123/CompParalela/`.


Em seguida, instale o gcc utilizando `sudo yum install gcc`, e utilize o comando `cd CompParalela/Lab02-MultiplicacaoMatrizVetor` para acessar a pasta contendo o código, e `gcc MMV.c` para compilá-lo, gerando 
um arquivo `a.out` com o programa.

### Execução
Com o arquivo compilado, apenas execute-o com `./a.out`.

### Resultado da execução:
Vetor: [1, 2, 3]
Matriz: [1, 2, 3]
        [4, 5, 6]
        [7, 8, 9]
        
![alt](/Lab02-MultiplicacaoMatrizVetor/img/2.png)

### Integrantes do grupo.
- Igor Benites Moura - 10403462
- João Pedro Maia Matulevicius Garcia - 10402158
