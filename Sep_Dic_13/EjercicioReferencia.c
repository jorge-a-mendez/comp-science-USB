#include <stdio.h>
#include <stdlib.h>

//Recibe dos apuntadores a entero e intercambia los valores de los mismos
void swap(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
//Recibe dos apuntadores a entero y devuelve un booleano: 1 si alguno divide al otro y 0 si no.
//Al final del programa, si alguno divide a otro, se tendra SIEMPRE que b divide a a y por eso se
//reciben los parametros por referencia.
int divide(int *b, int *a){
	int r = 0;						//inicialmente digo que ninguno divide a ninguno
	if(*a!=0 && *b!=0){				//si ambos son cero dire que ninguno divide a ninguno
		if(*b>*a) swap(a,b);		//si b es mayor que a los volteo para hacer la cuenta una sola vez
		if((*a)%(*b) == 0) r = 1;	//si b divide a a retorno 1
	}
	else if(*a == 0) r = 1;			//si a es cero b siempre divide a a.
	else if(*b == 0){				//si b es cero a siempre divide a b.
		swap(a,b);
		r = 1;
	}
	return r;
}

void main(){
	int a,b;
	printf("Introduzca dos numeros:\n");
	scanf("%d %d",&a,&b);
	if(divide(&b,&a)) printf("%d divide a %d\n\n\n", b,a);			//para pasar los valores por referencia utilizo &
	else printf("Ninguno de los dos divide al otro\n\n\n");
}
