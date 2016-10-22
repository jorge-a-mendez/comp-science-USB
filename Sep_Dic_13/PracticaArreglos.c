/*	El siguiente programa busca apoyar al estudiante en el manejo de arreglos en lenguaje C. Los estudiantes deberan intentar
Escribir sus propios codigos antes de pasar a leer los mostrados. Para esto deben leer la firma de las funciones y las descripciones
de las mismas al inicio del archivo.
	En el curso se manejaran arreglos de una y dos dimensiones numericos, los cuales seran interpretados como vectores y matrices,
respectivamente. Un arreglo es un conjunto de elementos de un mismo tipo que se agrupan bajo un mismo nombre y se direccionan mediante
sus indices respectivos. En lenguaje C, al pasar un arreglo como parametro de entrada a una funcion, este es pasado por referencia SIEMPRE,
sin necesidad de usar explicitamente apuntadores (como veran mas adelante, no es necesario utilizar int *).
	Es importante notar que las posiciones de los arreglos comienzan desde 0, por lo que llegan hasta el tamano menos uno.
	Como siempre, los algoritmos a realizar se haran en subprogramas, con el objetivo de modular la programacion.
*/

/* Funciones y procedimientos */

/*	OJO: noten que para pasar un arreglo NO es necesario especificar su tamano (si como otro parametro de entrada, mas no como parte del
arreglo. Por otro lado, las matrices SI necesitan tener especificado al menos el numero de columnas.
*/

#include <stdio.h>
#include <stdlib.h>

//Este procedimiento recibe como entrada un arreglo de enteros a de tamano n e imprime todos sus elementos en pantalla.
void imprimirArreglo(int a[],int n);

//Esta funcion recibe un arreglo a de tamano n y debe pedir por pantalla uno a uno sus elementos.
//Como les dije, los arreglos son pasados por referencia, asi que a regresara modificado.
void leerArreglo(int a[],int n);

//Este procedimiento recibe el numero de filas (m), de columnas(n) y una matriz de tamano mxn e imprime todos sus elementos.
void imprimirMatriz(int m, int n,int a[m][n]);

//Esta funcion recibe el numero de filas (m), de columnas(n) y una matriz de tamano mxn y debe pedir por pantalla sus elementos.
void leerMatriz(int m, int n, int a[m][n]);

//Esta funcion recibe un arreglo de tamano n y calcula el promedio de todos sus elementos.
int promedio(int n, int a[]);

//Esta funcion recibe el numero de filas y columnas de tres matrices y suma las matrices a y b, guardando el resultado en c.
//Noten que la matriz c, a pesar de que hay que pasarla a la funcion, es un parametro de SALIDA, ya que no aporta una entrada
//y es lo que se toma como resultado.
void sumarMatrices(int m, int n, int a[m][n], int b[m][n], int c[m][n]);
/*							*/

//Esta funcion recibe como entrada el numero de filas (m) de a, el numero de columnas (n) de b y el numero de
//columnas de a y filas de b (p) y calcula el producto de axb, guardandolo en c.
void multMatrices(int m, int p, int n, int a[m][p], int b[p][n], int c[m][n]);



/* Ejemplos de inicializaciones */

//El procedimiento Ejemplo crea un vector y una matriz y los inicializa e imprime los valores que contiene.
void Ejemplo(){
	int ejemplo1[5] = {1, 8, 7, 3, 4};
	printf("Luego de la creacion del vector ejemplo1, se tuvieron los siguientes valores:\n");
	imprimirArreglo(ejemplo1,5);
	int ejemplo2[3][2] = {
							{1, 2},
							{8, 3},
							{6, 7},
						};
	printf("Luego de la creacion de la matriz ejemplo2, se obtuvieron los siguientes valores:\n");
	imprimirMatriz(3,2,ejemplo2);
}

/*							*/


void main(){
	int m, n, p;
	/*printf("\t\tEjemplos de matrices inicializadas por codigo\n\n");
	Ejemplo();
	printf("\n\n\t\tPrueba de lectura e impresion de vectores\n\n");
	printf("Introduzca el tamano del vector: ");
	scanf("%d",&n);
	int a[n];
	leerArreglo(a,n);
	imprimirArreglo(a,n);
	printf("\n\n\t\tPrueba de lectura e impresion de matrices\n\n");
	printf("Introduzca el numero de filas y columnas de la matriz:\n");
	scanf("%d %d", &m, &n);
	int b[m][n];
	leerMatriz(m,n,b);
	imprimirMatriz(m,n,b);*/
	printf("\n\n\t\tPrueba de promedio de elementos de un arreglo\n\n");
	printf("Introduzca el numero de elementos del arreglo: ");
	scanf("%d", &n);
	int c[n];
	leerArreglo(c, n);
	printf("El promedio de los elementos del arreglo es: %d\n", promedio(n,c));
	printf("\n\n\t\tPrueba de suma de matrices\n");
	printf("Introduzca el numero de filas y columnas de las matrices a sumar:\n");
	scanf("%d %d", &m, &n);
	int d[m][n], e[m][n], f[m][n];
	printf("Matriz 1:\n");
	leerMatriz(m,n,d);
	printf("Matriz 2:\n");
	leerMatriz(m,n,e);
	sumarMatrices(m,n,d,e,f);
	printf("La suma de las matrices resulta:\n");
	imprimirMatriz(m,n,f);
	printf("\n\n\t\tPrueba de Multiplicacion de matrices\n");
	printf("Se multiplicaran dos matrices A(mxp) y B(pxn). Introduzca m, p y n:\n");
	scanf("%d %d %d", &m, &p, &n);
	int g[m][p], h[p][n], i[m][n];
	printf("A:\n");
	leerMatriz(m,p,g);
	printf("B:\n");
	leerMatriz(p,n,h);
	multMatrices(m,p,n,g,h,i);
	printf("El resultado de la multiplicacion de las matrices es:\n");
	imprimirMatriz(m,n,i);
	printf("\n\n\n");
}

void imprimirArreglo(int a[], int n){
	int i;
	printf("\n[");
	for(i=0;i<n-1;i++){
		printf("%d, ",a[i]);
	}
	printf("%d]\n", a[i]);
}

void leerArreglo(int a[], int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++){
		printf("Elemento %d: ",i);
		scanf("%d",&(a[i]));
	}
	printf("\n");
}

void imprimirMatriz(int m, int n, int a[m][n]){
	int i, j;
	printf("\n");
	for(i=0;i<m;i++){
		printf("[");
		for(j=0;j<n-1;j++){
			printf("%d, ", a[i][j]);
		}
		printf("%d]\n", a[i][j]);
	}
}

void leerMatriz(int m, int n, int a[m][n]){
	int i, j;
	printf("\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("Elemento %d, %d: ",i,j);
			scanf("%d", &(a[i][j]));
		}
	}
	printf("\n");
}

int promedio(int n, int a[]){
	int r=0, i;
	if(n!=0){
		for(i=0;i<n;i++){
			r += a[i];
		}
		r /= n;
	}
	return r;
}

void sumarMatrices(int m, int n, int a[m][n], int b[m][n], int c[m][n]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void multMatrices(int m, int p, int n, int a[m][p], int b[p][n], int c[m][n]){
	int i,j,k,r;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			r = 0;
			for(k=0;k<p;k++){
				r += a[i][k]*b[k][j];
			}
			c[i][j] = r;
		}
	}
}
