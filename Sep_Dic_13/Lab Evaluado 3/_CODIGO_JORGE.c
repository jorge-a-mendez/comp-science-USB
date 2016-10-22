#include <stdio.h>
#include <stdlib.h>

//El arreglo de coeficientes del polinomio debe tener grado+1 elementos (0,1,2,...,grado)
void leerCoef(int grado, float poli[grado+1]){
	int i;
	for(i=0;i<=grado;i++){		//leo del 0 al grado, obteniendo los grado+1 coeficientes necesarios
		printf("coef%d: ",i);
		scanf("%f",&poli[i]);	//y los almaceno en el arreglo
	}
	printf("\n\n");
	//como todos los arreglos son pasados por referencia, son modificados los valores.
}

void imprimirPoli(int grado, float poli[grado+1]){
	int i;
	printf("%f",poli[0]);	//imprimo el primero aparte para evitar el x^0 y el + extra al final.
	for(i=1;i<=grado;i++){	//imprimo todos los coeficientes con su variable correspondiente
		printf(" + %.2fx^%d",poli[i],i);
	}
	printf("\n\n");
}

void multPoli(int grado1, int grado2, float poli1[grado1+1], float poli2[grado2+1], float poli3 [grado1+grado2+1]){
	int i,j;
	for(i=0;i<=grado1+grado2;i++){
		poli3[i] = 0;
	}
	//Inicializo en 0 todo el arreglo del resultado. Por que? Porque necesitare hacer una suma acumulada en cada
	//termino. Esto debido a que al multiplicar polinomios suelen quedar terminos semejantes que hay que sumar.
	//En este codigo, esto se ve en el hecho de que la posicion en la que se almacenara el resultado es la i+j,
	//lo que implica que puede accederse varias veces a la misma posicion (0+1, 1+0, por ejemplo).
	for(i=0;i<=grado1;i++){
		for(j=0;j<=grado2;j++){
			poli3[i+j] += poli1[i]*poli2[j];
			//el coeficiente de x^(i+j) es la suma de los demas coeficientes del mismo orden (obtenidos anteriormente)
			//mas el producto del coeficiente de x^i en poli1 por el de x^j en poli2.
		}
	}
}

void main(){
	int m, n;
	printf("Introduzca m: ");
	scanf("%d",&m);
	printf("Introduzca n: ");
	scanf("%d", &n);
	printf("\n\n");
	if(m>=0 && n>=0){		//si los ordenes son no negativos, procedo.
		float P[m+1], Q[n+1], R[m+n+1];		//declaro los arreglos luego de leer los ordenes
											//para poder obtener su tamano. A todos les sumo
											//uno debido al coeficiente 0 (un polinomio de 
											//grado 3 tiene 4 coeficientes).
		printf("Introduzca los coeficientes de P\n");
		leerCoef(m,P);
		printf("Introduzca los coeficientes de Q\n");
		leerCoef(n,Q);
		multPoli(m,n,P,Q,R);
		printf("\tP(x):\n");
		imprimirPoli(m,P);
		printf("\tQ(x):\n");
		imprimirPoli(n,Q);
		printf("\tR(x) = P(x)Q(x):\n");
		imprimirPoli(m+n,R);
	}
	else{
		printf("Los polinomios deben tener grado no negativo\n\n");
	}
}
