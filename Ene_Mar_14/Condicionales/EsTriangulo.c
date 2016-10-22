#include <stdio.h>
#include <stdlib.h>

/*	Para que tres lados puedan formar un triangulo debe cumplirse la
desigualdad triangular. La desigualdad triangular consiste en que, tomando
cualquieras dos lados, su suma debe ser mayor que el lado restante.*/

void main(){
	int lado1,lado2,lado3;
	printf("Introduzca los tres lados:\n");
	scanf("%d %d %d", &lado1, &lado2, &lado3);
	//Se verifica que se cumplan las TRES condiciones en simultaneo. Para esto debe
	//usarse un AND (&&).
	if((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2)){
		printf("Con los lados dados puede construirse un triangulo\n\n");
	}
	else{
		printf("Con los lados dados NO puede construirse un triangulo\n\n");
	}
}
