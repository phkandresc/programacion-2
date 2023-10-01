#include <stdio.h>

int lower(int c);

int main(){
    printf("Caracter convertido a minuscula %d", lower(90));
}

int lower(int c){
    if(c>='A' && c<='Z'){
        return c +'a'-'A';
    }else return c;
}