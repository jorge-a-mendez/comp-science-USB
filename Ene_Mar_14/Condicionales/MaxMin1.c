#include <stdio.h>
#include <stdlib.h>

/*	Este es uno de los muchos metodos para hallar el maximo y el minimo.
Es, quizas, el mas ineficiente de todos. Por que? Porque realiza TODAS las
comparaciones entre las variables, de manera innecesaria. Ademas, el codigo
es mas largo de escribir. Es, tambien, la forma mas directa y evidente de
escribirlo. */

void main(){
	int a,b,c, max, min;
	printf("Introduzca tres numeros para obtener el maximo y el minimo:\n");
	scanf("%d %d %d", &a, &b, &c);
	if(a >= b && a >= c){
		max = a;
	}
	else if(b >= a && b >= c){
		max = b;
	}
	else{
		max = c;
	}
	if(a <= b && a <= c){
		min = a;
	}
	else if(b <= a && b <= c){
		min = b;
	}
	else{
		min = c;
	}
	printf("max: %d\nmin: %d\n\n", max, min);
}
