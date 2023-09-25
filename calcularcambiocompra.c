
#include <stdio.h>
#include <math.h>

int main()
{
    float vprod, vprodpagado, vuelto;
    float denominacionDolar[9] = {20, 10, 5, 1, 0.50, 0.25, 0.10, 0.05, 0.01};
    float cantidadporDenominacion[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("Ingrese el valor a pagar por el cliente:\n");
    scanf("%f", &vprod);
    printf("Ingrese el valor pagado por el cliente:\n");
    scanf("%f", &vprodpagado);

    if (vprodpagado==vprod)
    {
        printf("Pago realizado con exito, sin vuelto\n");
    }

    if (vprodpagado > vprod){
        // calcular vuelto
        vuelto = vprodpagado-vprod;
        vuelto = floor(vuelto*100)/100;
        printf("Debe entregar un cambio de: $%f\n", vuelto);
        // billetes
        for (int i = 0; i<9; i++)
        {
            while (vuelto>=denominacionDolar[i])
            {
                vuelto=vuelto-denominacionDolar[i];
                printf("el vuelto es: %f\n", vuelto);
                cantidadporDenominacion[i]++;
            }
            printf("Billetes de %.2f\t Cantidad %.0f\n", denominacionDolar[i], cantidadporDenominacion[i]);
        }
    }
    else
    {
        printf("Pago Insuficiente\n");
    }
}