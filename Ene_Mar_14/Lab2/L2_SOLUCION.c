#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leer_frase(char cadena[]){
	gets(cadena);		//Leo la frase(todos los arreglos se pasan por referencia asi que se modifica la original)
	return strlen(cadena);	//Retorno su longitud
}

int sustituye_caracteres(char cadena[], char a, char b, int length, int sust){
	int cant_a = 0, cant_sust = 0, i;
	for(i = 0; i < length; i++){
		if(cadena[i] == a){
			cant_a++;		//cuento la cantidad de veces que aparece 'a'.
		}
	}
	i = 0;
	if(cant_a >= sust){		//Si aparece suficientes veces para hacer las sustituciones
		while(cant_sust < sust){	//Recorro el arreglo hasta que la cantidad de sustituciones
									//hechas sea igual a las sustituciones solicitadas
			if(cadena[i] == a){	//Si el caracter es igual al que se quiere cambiar
				cadena[i] = b;	//Se cambia
				cant_sust++;	//Se aumenta la cantidad de sustituciones hechas.
			}
			i++;	//En cualquier caso (haya hecho la sustitucion o no) aumento el contador de recorrida del arreglo.
		}
		return 1;	//retorno 1
	}
	return 0;	//si llegue a este punto, es porque no era posible hacer las sustituciones, entonces retorno cero.
}

void main(){
	int length, sust;
	char a, b, c[100];
	printf("Introduzca la frase:\n\n\t");
	length = leer_frase(c);
	printf("\nIntroduzca el caracter a sustituir: ");
	scanf("%c", &a);
	while(getchar() != '\n');
	printf("Introduzca el caractar por el que desea sustituirlo: ");
	scanf("%c", &b);
	while(getchar() != '\n');
	printf("Introduzca la cantidad de veces que desea sustituirlo: ");
	scanf("%d", &sust);
	if(sustituye_caracteres(c, a, b, length, sust)){	//Utilizo directamente el resultado de la funcion como condicion.
														//Si retorna 1 entro y si retorna 0 no. Esto es lo que me interesa.
		printf("La frase modificada es:\n\t%s\n\n\n", c);
	}
	else{
		printf("No es posible sustituir '%c' %d veces en la frase '%s'\n\n\n", a, sust, c);
	}
}
