/*
Kevin Coraizaca
Programa que calcula la pendiente de una recta dados dos puntos
*/
#include <stdio.h>
#include <math.h>

int main(){
    float vprod, vprodpagado,billetes20, billetes10, billetes5;
    int vuelto;

    printf("Ingrese el valor a pagar por el cliente:\n");
    scanf("%f", &vprod);
    printf("Ingrese el valor pagado por el cliente:\n");
    scanf("%f", &vprodpagado);

if (vprodpagado==vprod){
        printf("Pago realizado con exito, sin vuelto\n");
}

if (vprodpagado>vprod)
{
   //calcular vuelto
   vuelto = vprodpagado-vprod;
   printf("Debe entregar un cambio de: $%i\n", vuelto);
   //billetes 20
   billetes20=(vuelto-(vuelto%20))/20;
   printf("Billetes de $20 a dar: %.0f\n", billetes20);
   vuelto=vuelto%20;
   //billetes 10
   billetes10=(vuelto-(vuelto%10))/10;
   printf("Billetes de $10 a dar: %.0f\n", billetes10);
   vuelto=vuelto%10;
   //billetes 5
   billetes5=(vuelto-(vuelto%5))/5;
   printf("Billetes de $5 a dar: %.0f\n", billetes5);
   vuelto=vuelto%5;
   //monedas de 1=vuelto
   printf("Monedas de $1 a dar: %i\n", vuelto);
}else{
    printf("Pago Insuficiente\n");
}
}