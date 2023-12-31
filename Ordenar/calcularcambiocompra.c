#include <stdio.h>
#include <math.h>
double denominacionDolar[9] = {20, 10, 5, 1, 0.50, 0.25, 0.10, 0.05, 0.01};
double cantidadporDenominacion[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

int main()
{
    double vprod, vprodpagado, vuelto;

    printf("Ingrese el valor a pagar por el cliente:\n");
    scanf("%lf", &vprod);
    printf("Ingrese el valor pagado por el cliente:\n");
    scanf("%lf", &vprodpagado);

    if (vprodpagado == vprod)
    {
        printf("Pago realizado con exito, sin vuelto\n");
    }
    
    if (vprodpagado > vprod)
    {
        // Calcular vuelto
        vuelto = vprodpagado - vprod;
        printf("Debe entregar un cambio de: %.2f\n", vuelto);

        // Vuelto segun denominaciones
        for (int i = 0; i < 9; i++)
        {
            while (vuelto >= denominacionDolar[i])
            {
                vuelto = vuelto - denominacionDolar[i];
                cantidadporDenominacion[i]++;
            }
            printf("Denominacion: %4f\t Cantidad: %.0f\n", denominacionDolar[i], cantidadporDenominacion[i]);
        }
    }
    else
    {
        printf("Pago insuficiente\n");
    }
}