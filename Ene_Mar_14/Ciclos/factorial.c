#include <stdio.h>
#include <stdlib.h>

void main(){
	int n, i, r = 1;
	printf("Introduzca un entero positivo: ");
	scanf("%d", &n);
	if(n >= 0){
		for(i = 1; i <= n; i++){
			r *= i;
		}
		printf("\n\n\t\t%d! = %d\n\n", n, r);
	}
	else{
		printf("ERROR! Valor invalido: no intrudujo un entero positivo\n\n");
	}
}