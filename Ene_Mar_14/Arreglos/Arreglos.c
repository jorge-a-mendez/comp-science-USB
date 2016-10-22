#include <stdio.h>
#include <stdlib.h>

void leerArreglo(int n, int a[]){
	int i;
	printf("\n");
	for(i = 0; i < n; i++){
		printf("Elemento %d: ", i);
		scanf("%d", &(a[i]));
	}
	printf("\n");
}

void imprimirArreglo(int n, int a[]){
	int i;
	printf("\n[");
	for(i = 0; i < n-1; i++){
		printf("%d, ", a[i]);
	}
	printf("%d]\n", a[i]);
}

void maxYmin (int n, int a[], int *maxi, int *mini){
	int i;
	*maxi = a[0];		//Inicializo maximo y minimo en el primer elemento
	*mini = a[0];
	for(i = 1; i < n; i++){
		if(a[i] > *maxi){	//Si el iesimo elemento es mayor que el maximo de todos los anteriores
			*maxi = a[i];	//Es el nuevo maximo
		}
		else if(a[i] < *mini){	//Si el iesimo elemento es menor que el minimo de todos los anteriores
			*mini = a[i];		//Es el nuevo minimo
		}
	}
}

void swap(int *a, int *b){
	int aux;
	aux = *b;
	*b = *a;
	*a = aux;
}


//Esta funcion coloce progresivamente en la posicion 0 el menor elemento del arreglo, en la posicion 1
//el menor elemento del subarreglo de a[1] a a[n-1], en la posicion 2 el menor elemento del subarreglo
//de a[2] a a[n-1]...y asi sucesivamente...hasta quedar ordenado de forma ascendente.
void ordenarArreglo(int n, int a[]){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(a[j] < a[i]){
				swap(&a[j], &a[i]);
			}
		}
	}
}

int tamString(char a[]){
	int i = 0;
	
	while(a[i] != '\0'){	//Utilizo un while porque NO se hasta donde tengo que recorrer
		i++;				//Aumento 'i' hasta conseguir el elemento de fin (\0)
	}
	return i;				//Retorno la posicion de fin, que corresponde al tamano del arreglo
}

//Retorno 1 si es palindromo y 0 si no.
int esPalindromo(char a[]){
	int i, n;
	n = tamString(a);			//Guardo el tamano del string en una variable
	for(i = 0; i < n/2; i++){		//Intento recorrer toda la palabra
		if(a[i] != a[n-1-i]){	//Si alguna letra no es igual a su simetrica...
			return 0;			//Salgo y retorno cero (NO es palindromo)
		}
	}
	return 1;	//Si llego al final del ciclo, es porque son iguales todas las letras con sus
				//simetricas, entonces retorno 1 (SI es palindromo)
}

//Retorno 1 si el elemento pertenece y 0 si no. Si pertenece, en el entero *pos quedara la posicion
//del primero elemento de valor 'x' en el arreglo.
int pertenece(int x, int n, int a[], int *pos){
	for(*pos = 0; *pos < n; (*pos)++){		//Inicializo la posicion en cero y la voy incrementando
		if(a[*pos] == x){					//Si el elemento en la posicion *pos es igual a x
			return 1;		//Encontre el elemento y retorno 1, quedando en *pos la posicion del elemento.
		}
	}
	return 0;	//Si recorri todo el arreglo quiere decir que nunca encontre el elemento x, asi que retorno 0.
}


//inicializa todos los elementos del arreglo a, de tamano n, en el valor val
void inicializar_arreglo(int a[], int n, int val){
	int i;
	for(i = 0; i < n; i++)
		a[i] = val;
}

//El valor de a[i] a la salida de esta funcion sera:
//  1 si i es primo
//  0 si i no es primo
//Para hacerlo, utiliza el algoritmo conocido como "Criba de Eratostenes"
//Obtiene todos los numeros primos menores que n 
//Pre: n >= 2
void primosMenores(int n, int a[]){
	int i,j;

	inicializar_arreglo(a,n,1);
	a[0] = 0;
	a[1] = 0;
	for(i = 2; i*i <= n; i++){
		if(a[i]){		//si a[i] es primo
			for(j = i*i; j < n; j += i)
				a[j] = 0;
		}
	}
}

//imprime las posiciones de los valores distintos de cero en el arreglo a
void imprimirArregloBooleano(int a[], int n){
	int i;
	printf("\n");
	for(i = 0; i < n; i++)
		if(a[i])
			printf("%d\t",i);

	printf("\n");
}

void main(){
	int n, maxi, mini, x, pos;
	char c[20];
	printf("\t\t\tPRUEBA MAXIMO Y MINIMO\n\nIntroduzca el tamano del arreglo: ");
	scanf("%d", &n);
	int a[n];
	leerArreglo(n, a);
	maxYmin(n, a, &maxi, &mini);
	printf("\n\tmaximo: %d\n\tminimo: %d", maxi, mini);
	printf("\n\n\t\t\tPRUEBA ORDENAMIENTO\n\nIntroduzca el tamano del arreglo: ");
	scanf("%d", &n);
	int b[n];
	leerArreglo(n, b);
	printf("\n\tArreglo desordenado:\n");
	imprimirArreglo(n, b);
	ordenarArreglo(n, b);
	printf("\n\tArreglo ordenado: \n");
	imprimirArreglo(n, b);
	printf("\n\n\t\t\tPRUEBA PALINDROMO\n\nIntroduzca la palabra: ");
	scanf("%s", c);	//Como les habia adelantado en clase, para leer STRINGS, no se pasa &c sino directamente c.
	
	/*	OJO: Aqui utilizo una propiedad del if que no les he mencionado, pero es interesante 
		utilizar. Si lo que esta dentro de un if es cero (if(0)) la condicion NO se cumple, por
		lo que no se ejecutan las instrucciones de adentro del if. Si lo que esta adentro es distinto
		de cero, por ejemplo 1 (if(1)) SI se cumple y se ejecutan las instrucciones. Lo mismo sucede, 
		por ejemplo, con las condiciones en el while. Por eso, en el if a continuacion tomo directamente
		el valor que retorna la funcion esPalindromo como condicion del if. Noten que el codigo
		se hace bastante mas legible: if es palindromo imprimo que es palindromo else imprimo que no.
		Esto se conoce como retornar un BOOLEANO en las funciones. esPalindromo retorna un booleano
		(true or false) que los interpreto a partir de 0 y 1.*/
		
	if(esPalindromo(c)){
		printf("\nLa palabra '%s' ES un palindromo\n", c);
	}
	else{
		printf("\nLa palabra '%s' NO es un palindromo\n", c);
	}
	printf("\n\n\t\t\tPRUEBA BUSQUEDA\n\nIntroduzca el tamano del arreglo: ");
	scanf("%d", &n);
	int d[n];
	leerArreglo(n, d);
	printf("\nIntroduzca el elemento que quiere buscar: ");
	scanf("%d", &x);
	printf("\nEn el arreglo");
	imprimirArreglo(n, d);
	
	//En este caso, utilizo lo mismo que anteriormente para la condicion del if. pertenece tambien
	//retorna un booleano. Asi: if pertenece imprimo donde esta else imprimo que no se encuentra.
	if(pertenece(x, n, d, &pos)){
		printf("\nEl numero %d se encuentra en la posicion %d", x, pos);
	}
	else{
		printf("\nNo se encuentra el numero %d\n\n", x);
	}

	printf("\t\t\tPRUEBA PRIMOS MENORES\n\nIntroduzca un entero: ");
	scanf("%d",&n);
	int e[n];
	primosMenores(n, e);
	printf("\nLos primos menores que %d son:\n",n);
	imprimirArregloBooleano(e, n);
}
