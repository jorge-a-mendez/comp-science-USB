#include<stdio.h>
#include<stdlib.h>

void main(){
	int n, i, r = 0;
	printf("Introduzca un entero positivo: ");
	scanf("%d", &n);
	if(n >= 0){
		for(i = 0; i <= n; i+=2){
			r += i;
		}
		printf("\nLa suma de todos los numeros pares no mayores que %d es:\n\n\n\t\t%d\n\n\n", n, r);
	}
	else{
		printf("ERROR! Valor invalido: no intrudujo un entero positivo\n\n");
	}
}
