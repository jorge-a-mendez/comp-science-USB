#include <stdio.h>
#include <stdlib.h>

void main(){
	int ano;
	printf("Introduzca un ano: ");
	scanf("%d", &ano);
	//Verifico la precondicion de que el ano sea positivo.
	if(ano > 0){
		if(ano%4 == 0 && (ano%100 != 0 || ano%400 == 0)){
			printf("El ano %d ES bisiesto\n",ano);
		}
		else{
			printf("El ano %d NO es bisiesto\n",ano);
		}
	}
	//Si la precondicion no se cumple, imprimo el mensaje de error.
	else{
		printf("El numero %d no corresponde a un ano\n", ano);
	}
}