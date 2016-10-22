#include <stdio.h>
#include <stdlib.h>

int fibonacci(int x, int *fibox){
	int i, fibon_1 = 1, fibon_2 = 0;
	//La primera vez que corra el ciclo fibo(n-1) = fibo(1) = 1 y fibo(n-2) - fibo(0) = 0
	
	//Verifico que se cumpla la precondicion. El numero debe ser mayor o igual a 0
	if(x >= 0){
		if(x == 0){
			*fibox = 0;
		}
		else if(x == 1){
			*fibox = 1;
		}
			//Fuerzo los valores del fibonacci de 1 y 0. Recuerden que el entero donde 
			//quiero el resultado es *fibox.
			
			//Si el entero no es ni 1 ni 0...
		else{
			for(i = 2; i <= x; i++){
				*fibox = fibon_1 + fibon_2;		//fibo(n) = fibo(n-1) + fibo(n-2);
				fibon_2 = fibon_1;				//Para el proximo ciclo, en fibo(n-2) guardo lo que ahora era fibo(n-1)
				fibon_1 = *fibox;				//Y en fibo(n-1) lo que ahora era fibo(n).
			}
		}
		return 1;	//Si se cumplio la precondicion inicialmente, retorno 1.
	}
	return 0;		//La unica forma de llegar a esta linea es que no se cumpla la precondicion, ya que 
					//de lo contrario, se encontraria con el otro return y saldria de la funcion.
}

void main(){
	int n, fibon;
	printf("\tIntroduzca un numero no negativo: ");
	scanf("%d", &n);
	
	//Calculo el fibonacci de 'n', lo almaceno en fibon (pasando a la funcion la direccion de fibon).
	//Si lo que me retorna la funcion es igual a 1, quiere decir que se cumple la pregundicion y el calculo es correcto.
	if(fibonacci(n, &fibon) == 1){
		printf("\n\n\t\tfibo(%d) = %d\n\n\n", n, fibon);
	}
	
	//Si no es igual a 1 quiere decir que hubo un error, por lo que imprimo error.
	else printf("\n\n\t\tERROR! NUMERO INVALIDO.\n\n\n");
}
