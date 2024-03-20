# Laboratório 2b - Programação Paralela
## Sobre o repositório

Utilizando uma versão adaptada do código do Lab 2 da disciplina de Computação Paralela, neste repositório mediremos a performance para completar o Lab02b.

Para melhor avakuar a execução do código, ele foi programado de maneira hard-coded para gerar uma matriz de **10 mil colunas por 10 mil linhas.**

Os testes serão efetuados nos programas `MMV.c`, `MMV2.c`, e `MMVSerial.c`.


## Reprodução

Fazendo uso do Git, utilize o comando `git clone https://github.com/matulevicius123/CompParalela` para obter o repositório. Em seguida, navegue para a pasta do Lab02b, e compile os projetos desejados utilizando `gcc -lpthread [nome do arquivo do projeto]`, executando-o então com `/a.out`.
utilizando então `time taskset -c [número de processadores desejado] /a.out` para executar os programas, receber informações sobre o tempo de execução do programa, e controlar a quantidade de processadores utilizados na sua execução.


## Exercícios Propostos
### 1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução
![alt](/Lab02b-ProgramacaoParalela/assets/serial.png)

![alt](/Lab02b-ProgramacaoParalela/assets/2.png)

![alt](/Lab02b-ProgramacaoParalela/assets/4.png)

![alt](/Lab02b-ProgramacaoParalela/assets/6.png)

![alt](/Lab02b-ProgramacaoParalela/assets/8.png)

![alt](/Lab02b-ProgramacaoParalela/assets/grafico1.png)



### 2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

<table align= "center">
     <tr>
          <td>Núcleos</td>
          <td>1</td>
          <td>2</td>
          <td>4</td>
          <td>6</td>
          <td>8</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Serial</strong></td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Paralela</strong></td>
           <td>0.627</td>
           <td>0.511</td>
           <td>0.463</td>
           <td>0.455</td>
           <td>0.443</td>
     </tr>
     <tr>
           <td><strong>Speedup</strong></td>
           <td>0.979</td>
           <td>1.201</td>
           <td>1.326</td>
           <td>1.349</td>
           <td>1.386</td>
     </tr>
</table>

![alt](/Lab02b-ProgramacaoParalela/assets/grafico2.png)

### 3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

Uma das nossas únicas opções para continuar otimizando o programa é remover os prints de resultados para visar mais ainda a performance do programa. Como prints são um recurso surpreendentemente pesado e com a quantidade colossal de texto gerada como
output do programa, há de surgir alguma melhora na performance do programa.

![alt](/Lab02b-ProgramacaoParalela/assets/2.0.png)

<table align= "center">
     <tr>
          <td>Núcleos</td>
          <td>1</td>
          <td>2</td>
          <td>4</td>
          <td>6</td>
          <td>8</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Serial</strong></td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
           <td>0.614</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Aprimorada</strong></td>
           <td>0.610</td>
           <td>0.491</td>
           <td>0.439</td>
           <td>0.437</td>
           <td>0.433</td>
     </tr>
     <tr>
           <td><strong>Speedup</strong></td>
           <td>1.006</td>
           <td>1.250</td>
           <td>1.398</td>
           <td>1.405</td>
           <td>1.418</td>
     </tr>
</table>

![alt](/Lab02b-ProgramacaoParalela/assets/grafico3.png)

**Dump completo das informações pertinentes sobre a CPU utilizada para testes na pasta 'CPU'**

