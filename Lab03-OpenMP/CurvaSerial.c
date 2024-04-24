#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double alturaCurva(double x) {
    return 5.0 + sin(x);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Utilize os seguintes argumentos de entrada: Inicio, Fim, Numero de Trapezios.\n");
        return 1;
    }

    double a = atof(argv[1]);  // a = inicio da curva
    double b = atof(argv[2]);  // b = final da curva
    int n = atoi(argv[3]);     // n = numero de trapezios a serem criados
    double largura = (b-a) / n;
    double resultado = (alturaCurva(a) + alturaCurva(b)) / 2.0;
    double x;

    for (int i = 1; i <= n-1; i++) {
         x = a + i * largura;
	 resultado += alturaCurva(x);
    }

    resultado = largura * resultado;

    printf("Estimativa da Integral: %lf\n", resultado);
    return 0;
}
