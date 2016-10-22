#include <stdio.h>
#include <stdlib.h>

void main(){
	int op,a,b;
	printf("\t\t\tMENU DE OPERACIONES\n\n");
	printf("(1) Suma\n(2) Multiplicacion \n(3) Salir\nIntroduzca su opcion: ");
	scanf("%d", &op);
	//Verifico posibles valores de la variable op (operacion)
	switch(op){
		//Si es 1, calculo una suma.
		case 1:
			printf("Introduzca los sumandos:\n");
			scanf("%d %d",&a,&b);
			printf("%d + %d = %d\n\n",a,b,a+b);
			break;
		//Si es 2, calculo un producto.
		case 2:
			printf("Introduzca los factores:\n");
			scanf("%d %d", &a,&b);
			printf("%d * %d = %d\n\n",a,b,a*b);
			break;
		//Si es 3, no ejecuto ninguna operacion.
		case 3:
			break;
		//Si no es ninguna de las anteriores, imprimo mensaje de error.
		default:
			printf("ERROR: La opcion introducida no corresponde a ninguna operacion.\n\n");
			break;		//No olviden el break al final de ninguno de los casos.
						//Hasta en el default deben incluirlo.
	}
}
