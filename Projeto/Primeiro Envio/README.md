# Sobre o repositório

No projeto final da disciplina de Computação Paralela, calculamos o valor da constante de Euler usando uma série de Taylor com altas iterações, priorizando a paralelização e ganhos de performance para calcular o maior número de iterações possível.


A fim disso, utilizamos a biblioteca OpenMP para habilitar a paralelização do programa, e as bibliotecas GMP e MPFR para executar cálculos com números grandes o suficiente para exceder o limite oferecido pelas estruturas da linguagem C.
## Reprodução

Fazendo uso do Git, utilize o comando `git clone https://github.com/matulevicius123/CompParalela` para obter o repositório. 

Em seguida, navegue para a pasta do Lab03, e compile os programas utilizando `gcc  [nome do arquivo].c -o [nome do arquivo].bin -fopenmp -lm`, 

e a versão serial com `gcc [nome do arquivo].c -o [nome do arquivo].bin -lm`, 

executando-os então com `time taskset -c [processadores desejados] /[nome do arquivo].bin [número de iterações] [número de bits] [número de threads]`, para controlar a quantidade de processadores utilizados, e exibir o tempo de execução do programa.

Vale ressaltar que GMP e MPFR devem ser instalados antes de serem utilizados. As bibliotecas podem ser baixadas nos sites https://gmplib.org/ e https://www.mpfr.org/.

## Execução

Paralelizando a série de Taylor, a função `fatorial` para calcular a série de Taylor. Nas versões paralelas, há a divisão de workload entre as threads. Após designar a cada thread seu ponto de partida, as threads iteram o fatorial até seu ponto de partida. O tempo levado para alcancar o ponto de partida era inicialmente uma dúvida quanto à viabilidade dessa tática. Posteriormente, após alcançar seu ponto de partida correto, cada thread continua iterando o fatorial enquanto divide esta iteração por um, somando-a ao seu resultado particular. Após alcançar o final de cada thread, o resultado de cada thread é somado ao resultado total, o que se torna thread-safe com a inclusão do `critical`.

Nas implentações seriais, um processo similar é feito, porém com um único fluxo de execução fatorando, dividindo, e totalizando toda a série de Taylor.

Para os seguintes testes, foi utilizado o `número de iterações: 10000000`, `número de bits:10000`, e uma thread pra cada core. 

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/e02af168-23c7-451a-9d24-08fab2b69b67)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/be9a741f-4ede-46e7-8a01-fba80f0c00f3)


É notável a estagnação do código serial, que não se beneficia em nada com a adição de mais cores, e o fato que há um _aumento_ no tempo de execução ao aumentar as cores de 6 para 8 - o tempo computando as partes paralelas do problema se tornaram tão curtas que as seriais ocupam uma porção maior e não minimizável do tempo de execução.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/a5816478-8686-4d30-a26a-6b56f86c30f5)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/cefff0ed-d18a-42b7-b3b5-e78ca75ee816)


## CPU utilizada

Os detalhes da CPU utilizada para a execução dos testes está disponível no arquivo `CPU.txt`.

## Conclusões

É possível, com o código atual, calcular um número extremamente alto de dígitos de Euler em um espaço de tempo razoável. Podem ser feitas mais otimizações no código substituindo operações demoradas de divisão por multiplicação.
O sucesso da paralelização foi surpreendente para o grupo, já que com a estratégia atual, para o início de cada thread, é necessário iterar a fatorial até o ponto de início de cada thread, perdendo muito tempo.
