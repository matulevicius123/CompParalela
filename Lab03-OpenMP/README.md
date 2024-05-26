# Sobre o repositório

Neste laboratório, exploramos a aceleração conferida pela paralelização via OpenMP à um algoritmo de cálculo de integrais utilizando a regra dos trapézios.

Em seguida, utilizamos o tempo de execução encontrado para medir o speedup recebido ao aumentar o número de CPUs utilizadas. 

Os argumentos utilizados no código para execução foram `1`, `5`, `1000000000`, e o número de cores utilizados para a, b, o número de trapézios, e o número de threads.

## Reprodução

Fazendo uso do Git, utilize o comando `git clone https://github.com/matulevicius123/CompParalela` para obter o repositório. 

Em seguida, navegue para a pasta do Lab03, e compile os projetos paralelos utilizando `gcc -fopenmp [nome do arquivo].c -o [nome do arquivo].bin -lm`, 

e a versão serial com `gcc [nome do arquivo].c -o [nome do arquivo].bin -lm`, 

executando-os então com `time taskset -c [processadores desejados] /[nome do arquivo].bin [valor de a] [valor de b] [número de trapezios] [número de threads]`, para controlar a quantidade de processadores utilizados, e exibir o tempo de execução do programa.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/c413f3ae-4897-46ed-946d-d657f4b5807c)

# Questões

**1- Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução.**

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/6d420d85-0bf3-4a3b-82e0-83cc53ff8276)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/50e83833-4589-4a53-9077-fe0e58aec500)

**2- Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.**

Neste item é notável a diminuição de ganho de speedup ao ir de 6 para 8 núcleos - o tempo computando as partes paralelas do problema se tornaram tão curtas que as seriais ocupam uma porção maior e não minimizável do tempo de execução.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/3caf1724-c176-4244-8b9a-62bfacd7e8cb)

**3- Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores. **

Com a diretiva critical, a condição de corrida onde múltiplas threads tentam acessar o valor global ao mesmo tempo é anulada, porém a soma do resultado calculado pela thread ao resultado global torna-se serial, tornando o código mais lento.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/e9f141cb-5931-452b-a930-3a275fe323a1)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/e1e97c06-32e6-4307-8d56-77827264656f)

Isso torna-se aparente ao notar que o problema presente na questão 2 foi exacerbado - a maior quantidade de threads executando tarefas seriais deixa o código mais lento.

## CPU utilizada

Os detalhes da CPU utilizada para a execução dos testes está disponível no arquivo `CPU.txt`.

## Execução
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/0b9e2106-d257-4195-9df1-77a7c3b0ef24)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/e5af9e24-9ada-410a-afd6-27f232c39611)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/9cb1693f-494a-4e8a-a1f1-4d9812fa0201)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/7698b146-8ef6-4fe0-a5cf-aa7bbca72ad7)


