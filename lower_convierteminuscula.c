#include <stdio.h>

int lower(int c);

int main(){
    printf("Caracter convertido a minuscula %d", lower(67));
}

int lower(int c){
    /*if(c>='A' && c<='Z'){
        return c +'a'-'A';
    }else return c;
    Aqui se usa if- else como cualquiera haria
    pero la expresion de abajo simplifica este proceso.
    */
    
    return((c>='A' && c<='Z')? c +'a'-'A':c);
}