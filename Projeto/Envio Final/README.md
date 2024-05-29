# Sobre o repositório

No projeto final da disciplina de Computação Paralela, calculamos o valor da constante de Euler usando uma série de Taylor com altas iterações, priorizando a paralelização e ganhos de performance para calcular o maior número de iterações possível.


A fim disso, utilizamos a biblioteca OpenMP para habilitar a paralelização do programa, e as bibliotecas GMP e MPFR para executar cálculos com números grandes o suficiente para exceder o limite oferecido pelas estruturas da linguagem C.

### Participantes
- Igor Benites Moura - 10403462
- João Pedro Maia Matulevicius Garcia - 10402158

## Reprodução

Fazendo uso do Git, utilize o comando `git clone https://github.com/matulevicius123/CompParalela` para obter o repositório. 

Em seguida, navegue para a pasta do Envio Final, e compile os programas utilizando `gcc  [nome do arquivo].c -o [nome do arquivo].bin -fopenmp -lm`, 

e a versão serial com `gcc [nome do arquivo].c -o [nome do arquivo].bin -lm`, 

executando-os então com `time taskset -c [processadores desejados] /[nome do arquivo].bin [número de iterações] [número de bits] [número de threads]`, para controlar a quantidade de processadores utilizados, e exibir o tempo de execução do programa.

Vale ressaltar que GMP e MPFR devem ser instalados antes de serem utilizados. As bibliotecas podem ser baixadas nos sites https://gmplib.org/ e https://www.mpfr.org/.

## Execução

Após diversas tentativas de aumentar a performance do programa, apenas um progresso modesto progresso foi feito. Tentativas foram feitas para serializar o fatorial e paralelizar a divisão de 1 e soma do resultado de iterações, mas sem muitos frutos.

Tentamos substituir também o ineficiente `mpfr_div` por multiplicações ou potências ou até mesmo um `mpfr_div_si`, mas sem resultados. 

No fim, as melhorias foram modestas: descobrimos que não há necessidade de fornecer uma precisão de bits tão grande para `div`, optamos por apenas 53, a quantidade utilizada por um double. Isso foi o bastante para ver ligeiros ganhos de performance.

Além disso. a lógica da divisão de trabalho entre as threads foi corrigida: ao definir o resultado como 2 inicialmente para pular as duas primeiras iterações da série de Taylor, errôneamente duas iterações eram puladas em todas as threads, o que foi corrigido.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/be8291bb-ff8c-4c40-a009-33384e994427)

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/ff5020b6-e985-457e-8b47-2274ce3e06af)

Apesar das melhorias não serem enormes, o grupo foi capaz de calcular um valor de Euler extenso e preciso, que foi anexado no repositório.

![image](https://github.com/matulevicius123/CompParalela/assets/142500460/04f319bb-904d-42ca-9037-bee3b7037137)




![image](https://github.com/matulevicius123/CompParalela/assets/142500460/10944d3f-faa2-4956-8fdb-728f8c06c887)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/216ee041-e4f4-4227-8b03-b919028822ca)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/22f568cf-b1ba-4a81-a980-1e3b1467ac99)
![image](https://github.com/matulevicius123/CompParalela/assets/142500460/9b37540b-6a54-48d0-ba94-813cea21f314)


## CPU utilizada

Os detalhes da CPU utilizada para a execução dos testes está disponível no arquivo `CPU.txt`.

## Conclusões

É possível, com o código atual, calcular um número extremamente alto de dígitos de Euler em um espaço de tempo razoável.
