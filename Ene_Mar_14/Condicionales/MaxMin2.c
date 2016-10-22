#include <stdio.h>
#include <stdlib.h>

/*	Este otro metodo consiste en un algoritmo un poco mas elaborado. En 
lugar de realizar todas las comparaciones directamente, se utiliza un 
metodo mas planficiado que arroja los resultados mas eficientemente.
Leanlo y, al final del codigo, conseguiran la explicacion del algoritmo. */

void main(){
	int a,b,c,max,min;
	printf("Introduzca tres numeros para hallar el maximo y el minimo:\n");
	scanf("%d %d %d",&a,&b,&c);
	max = a;
	min = a;
	if(b > a){
		max = b;
	}
	if(c > max){
		max = c;
	}
	if(b < a){
		min = b;
	}
	if(c < min){
		min = c;
	}
	printf("max: %d\nmin: %d\n\n",max,min);
}

/*Como pueden haber notado, el algoritmo consiste en el uso de las dos
varibles auxiliares 'max' y 'min'. Se parte del supuesto de que la va-
riable 'a' es tanto el maximo como el minimo. Si 'b' resulta ser mayor
que 'a', pasa 'b' a ser el nuevo maximo. Finalmente, si 'c' es mayor
que el maximo entre las otras dos (almacenado en la variable 'max'),
'c' pasa a ser el maximo. De manera equivalente se procede con el minimo.
Verifiquen lo que pasa si dos o tres variables son iguales. Hagan una 
corrida en frio del programa (en su mente) y luego ejecutenlo. */