#include <stdio.h>
#include <stdlib.h>

/*	Un triangulo es equilatero si sus tres lados son iguales, isoceles
si dos de sus lados son iguales y escaleno si sus tres lados son diferentes
entre si. */

void main(){
	int lado1,lado2,lado3;
	printf("Introduzca los tres lados:\n");
	scanf("%d %d %d", &lado1, &lado2, &lado3);
	//Primero, debe verificarse que los lados puedan formar un triangulo.
	if((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2)){
		//Si 'a' es igual a 'b' y 'b' es igual a 'c'..entonces ya 'a' es igual a 'c'
		//Esto quiere decir que la igualdad es una propiedad transitiva, y es lo que
		//se usa en este primer condicional.
		if(lado1 == lado2 && lado2 == lado3){
			printf("Los lados dados forman un triangulo EQUILATERO\n\n");
		}
		//SOLO si no es equilatero (por eso el else) puede ser isoceles. Debe
		//Cumplirse que algun par de lados sean iguales entre si. Por tanto
		//debe usarse un OR (||). Pendientes: para poder hacerlo con esta simplicidad
		//es necesario primero verificar que el triangulo NO sea equilatero. De
		//lo contrario, habria que verificar que SOLO dos lados sean iguales (mas complicado).
		else if(lado1 == lado2 || lado2 == lado3 || lado3 == lado1){
			printf("Los lados dados forman un triangulo ISOCELES\n\n");
		}
		//Si no es equilatero ni isoceles, ajuro es escaleno.
		else{
			printf("Los lados dados forman un triangulo ESCALENO\n\n");
		}
	}
	//Si no cumple la precondicion: error.
	else{
		printf("Con los lados dados NO puede construirse un triangulo\n\n");
	}
}
