#include <stdio.h>
#include <stdlib.h>

/* Antes de que lean este programa, debo explicarles dos sentencias que
olvide mencionarles en el laboratorio del viernes. La primera de ellas
es el "break". Esta sentencia se utiliza dentro de una estructura de
control iterativa (ciclo: while, do while o for) para finalizar las 
iteraciones; es decir, para salir del ciclo. Se utiliza en caso de que,
de cumplirse una cierta condicion, se desee salir del ciclo antes de 
finalizar las corridas. La otra sentencia es el "continue". Esta se usa
para saltar el resto de las instrucciones de una corrida del ciclo y 
volver al inicio. En este ejercicio utilizo, a manera de ejemplo, la 
sentencia break para determinar si un numero es primo o no, a pesar de
que no es la unica manera de resolver el ejercicio.*/


void main(){
	int n, i;
	printf("Introduzca un entero positivo: ");
	scanf("%d", &n);
	if(n >= 0){						//precondicion
		for(i = 2; i < n; i++){		//debo verificar si hay algun numero
									//mayor que 1 y menor que n que divida
									//al entero: por eso voy desde 2 hasta el
									//ultimo menor que n
			if(n % i == 0){
				break;				//si alguno de estos numeros divide a n, n 
									//ya no es primo, asi que salgo del ciclo
			}
		}
		//A este punto del programa puedo llegar de dos formas: la primera, es que
		//haya salido del ciclo por el break, en cuyo caso el entero no es primo.
		//La segunda, es que haya salido del ciclo porque finalizaron las corridas.
		//En este segundo caso, no habria conseguido ningun numero distinto de 1 y
		//n que divida a n, en cuyo caso n es primo. Entonces, la condicion que me 
		//queda por verificar es ver por que razon sali del ciclo. La manera de hacerlo
		//es verificar si aun se cumple la condicion de corrida del ciclo. Si la 
		//condicion aun se cumple, quiere decir que NO sali por haber finalizado las
		//corridas, sino por haberme encontrado con el break.
		
		if(i < n){
			printf("\nEl numero %d NO es primo.\n\n", n);
		}
		else{
			printf("\nEl numero %d ES primo.\n\n", n);
		}
	}
	else{							//si no se cumple la precondicion...
		printf("ERROR! Valor invalido: no intrudujo un entero positivo\n\n");
	}
}

//Este programa tiene una forma mas eficiente de resolverse. Noten que si ningun
//numero menor o igual que la raiz de n divide a n, ningun otro lo hara. Por que?
//Porque por cada numero que divide a otro, hay otro numero que tambien lo divide (a
//menos que sea la raiz cuadrada exacta del numero). Uno de los numeros sera menor
//que la raiz y el otro, por supuesto, sera mayor. Entonces, una vez que llego a la
//raiz de n, debo haber conseguido algun numero que divida a n, porque de lo contrario,
//ningun otro numero lo hara (ya que no tendra un par menor que la raiz para multiplicarse
//y resultar n). Para escribir este programa con esta nueva condicion de parada, ya que
//no contamos con la libreria matematica, debemos cambiar la condicion i < n (tanto en 
//el for como en el if) por i*i <= n.