#include <stdio.h>

int main(){
    int num;
    printf("SE EJECUTA EL CODIGO");
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    // El bucle externo controla el tamaño del intervalo o "gap".
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        // Este bucle recorre el arreglo desde la posición "gap" hasta el final.
        for (i = gap; i < n; i++)
        {
            // Compara los elementos en la posición actual (i) y la posición "i - gap".
            // Si el elemento en la posición "i - gap" es mayor, intercambia los elementos.
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}
