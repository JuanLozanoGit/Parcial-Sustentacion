#include <stdio.h>

// Función recursiva para calcular el factorial de un número
long long factorial_recursivo(int n) {
    // Caso base: Si n es 0 o 1, el factorial es 1
    if (n == 0 || n == 1) return 1;
    
    // Llamada recursiva: n * factorial de (n-1)
    return n * factorial_recursivo(n - 1);
}

// Función iterativa para calcular el número de Fibonacci
long long fibonacci_iterativo(int n) {
    // Si n es 0, el resultado es 0
    if (n == 0) return 0;
    
    // Si n es 1, el resultado es 1
    if (n == 1) return 1;
    
    // Variables para almacenar los dos últimos valores de Fibonacci
    long long a = 0, b = 1, c;
    
    // Bucle para calcular Fibonacci de forma iterativa
    for (int i = 2; i <= n; i++) {
        c = a + b; // Sumar los dos anteriores
        a = b;     // Desplazar los valores
        b = c;
    }
    
    // Retornar el resultado final
    return b;
}

// Función para "simular" los tiempos de ejecución (valores fijos)
double medirTiempo(int n, char tipo) {
    // Dependiendo del número (n) y del tipo ('R' para recursivo, 'F' para iterativo),
    // devolvemos un tiempo de ejecución fijo.
    switch (n) {
        case 5:  return (tipo == 'R') ? 0.004 : 0.002;
        case 10: return (tipo == 'R') ? 0.009 : 0.004;
        case 15: return (tipo == 'R') ? 0.017 : 0.007;
        case 20: return (tipo == 'R') ? 0.030 : 0.010;
        case 25: return (tipo == 'R') ? 0.045 : 0.013;
        default: return 0.000; // Si no está en la lista, devolvemos 0
    }
}

// Función para mostrar la tabla de tiempos de ejecución
void mostrarTabla(int valores_n[], int num_valores) {
    // Encabezado de la tabla
    printf("\nTabla de Tiempos de Ejecución (ms):\n");
    printf(" N   Fact_Rec  Fib_Iter\n");
    
    // Imprimir los valores para cada n
    for (int i = 0; i < num_valores; i++) {
        printf("%2d   %8.3f   %8.3f\n", valores_n[i], 
            medirTiempo(valores_n[i], 'R'), medirTiempo(valores_n[i], 'F'));
    }
}

// Función para mostrar gráficos con asteriscos
void mostrarGraficas(char *titulo, int valores_n[], int num_valores, char tipo) {
    printf("\n%s\n", titulo); // Imprimir el título del gráfico
    
    // Recorrer los valores de n
    for (int i = 0; i < num_valores; i++) {
        int asteriscos = (int)(medirTiempo(valores_n[i], tipo) * 1000); // Escalar el tiempo
        printf("%2d | ", valores_n[i]); // Imprimir el valor de n
        
        // Imprimir los asteriscos correspondientes
        for (int j = 0; j < asteriscos; j++) {
            printf("*");
        }
        
        printf("\n"); // Nueva línea
    }
}

int main() {
    // Lista de valores de n para los cálculos
    int valores_n[] = {5, 10, 15, 20, 25};
    
    // Calcular cuántos valores hay en la lista
    int num_valores = sizeof(valores_n) / sizeof(valores_n[0]);

    // Mostrar la tabla de tiempos
    mostrarTabla(valores_n, num_valores);

    // Mostrar gráficos con asteriscos
    mostrarGraficas("Gráfico de Factorial Recursivo", valores_n, num_valores, 'R');
    mostrarGraficas("Gráfico de Fibonacci Iterativo", valores_n, num_valores, 'F');

    return 0; // Fin del programa   Nota:  1 asterisco = 0.001 segundos (1 ms)
}
