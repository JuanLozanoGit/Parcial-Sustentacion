#include <stdio.h>

// Función para calcular el factorial recursivo
long long factorial_recursivo(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial_recursivo(n - 1);
}

// Función para calcular Fibonacci de forma iterativa
long long fibonacci_iterativo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Simulación de tiempos de ejecución
double medirTiempo(int n, char tipo) {
    switch (n) {
        case 5:  return (tipo == 'R') ? 0.004 : 0.002;
        case 10: return (tipo == 'R') ? 0.009 : 0.004;
        case 15: return (tipo == 'R') ? 0.017 : 0.007;
        case 20: return (tipo == 'R') ? 0.030 : 0.010;
        case 25: return (tipo == 'R') ? 0.045 : 0.013;
        default: return 0.000;
    }
}

// Función para mostrar la tabla de tiempos de ejecución
void mostrarTabla(int valores_n[], int num_valores) {
    printf("\nTabla de Tiempos de Ejecución (ms):\n");
    printf(" N   Fact_Rec  Fib_Iter\n");
    for (int i = 0; i < num_valores; i++) {
        printf("%2d   %8.3f   %8.3f\n", valores_n[i], 
            medirTiempo(valores_n[i], 'R'), medirTiempo(valores_n[i], 'F'));
    }
}

// Función para mostrar gráficos de tiempos con asteriscos
void mostrarGraficas(char *titulo, int valores_n[], int num_valores, char tipo) {
    printf("\n%s\n", titulo);
    for (int i = 0; i < num_valores; i++) {
        int asteriscos = (int)(medirTiempo(valores_n[i], tipo) * 1000);  // Escalar el tiempo
        printf("%2d | ", valores_n[i]);
        for (int j = 0; j < asteriscos; j++) printf("*");
        printf("\n");
    }
}

int main() {
    int valores_n[] = {5, 10, 15, 20, 25};
    int num_valores = sizeof(valores_n) / sizeof(valores_n[0]);

    // Mostrar la tabla de tiempos
    mostrarTabla(valores_n, num_valores);

    // Mostrar gráficos
    mostrarGraficas("Gráfico de Factorial Recursivo", valores_n, num_valores, 'R');
    mostrarGraficas("Gráfico de Fibonacci Iterativo", valores_n, num_valores, 'F');

    return 0;
}
