#include<stdio.h>
#include<stdlib.h>

void main(){
	float a, b, c;
	int r;
	printf("Introduzca tres numeros reales no negativos:\n");
	scanf("%f %f %f", &a, &b, &c);
	if(a >= 0 && b >= 0 && c >= 0){	//Si TODOS son no negativos, continuo...
		if(a + b <= c || a + c <= b || b + c <= a){	//Si la suma de ALGUN par de lados es mayor o igual al lado restante...
			r = 0;											// Entero: 0 (no forman un triangulo).
		}
		else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){	//Si la suma de ALGUN par de cuadrados es igual al cuadrado del lado restante...
			r = 1;																	//Entero: 1 (forman un triangulo rectangulo).
																			//Noten que este caso debe ser el primero, para que tenga jerarquia sobre los demas.
		}
		else if(a == b && a == c){	//Si todos los lados son iguales...
			r = 3;						//Entero: 3 (forman un triangulo equilatero).
									//Noten dos detalles. Primero, invierto las condiciones de isoceles y equilatero, ya que todos los triangulos equilateros
									//cumplen con la condicion de los isoceles (a menos que se especifique que el tercer lado sea diferente). Si estuvieran en
									//el orden inverso, todos los equilateros entrarian al caso isoceles y no al equilatero.
									//Segundo, noten que solo realizo dos comparaciones para verificar que todos los lados sean iguales. Esto, debido a la
									//transitividad de la igualdad. Si a = b y b = c, entonces a = c.
		}
		else if(a == b || b == c || a == c){	//Si ALGUN par de lados son iguales entre si...
			r = 2;									//Entero: 2 (forman un triangulo isoceles).
		}
		else{		//Si no es ni equilatero ni isoceles...
			r = 4;		//Entero: 4 (forman un triangulo escaleno)
		}

		//Noten que todas las condiciones las separo con un else. Esto es debido a que, en ocasiones, pueden cumplirse varias de las condiciones. Como solo
		//puede ser un tipo de triangulo, debo jerarquizar el orden de las condiciones como explique y asegurar entrar a una sola de ellas. Especialmente
		//en este caso, en el que se pedia que los triangulos rectangulos SOLO dijeran que son rectangulos, teniendo que todos los rectangulos son, ademas,
		//isoceles o escalenos. Tambien ocurre algo similar para los equilateros, ya que si son equilateros tambien se cumplira la condicion de isoceles,
		//y entrar a ese caso seria un error.

		printf("\n\nEl entero resultante de su clasificacion es: %d\n\n\n", r);

				/*HASTA AQUI ERA OBLIGATORIO; LO QUE SIGUE ES OPCIONAL*/

		switch(r){
			case 0:
				printf("Los numeros introducidos no forman un triangulo\n\n");
				break;
			case 1:
				printf("Los numeros introducidos forman un triangulo rectangulo\n\n");
				break;
			case 2:
				printf("Los numeros introducidos forman un triangulo isoceles\n\n");
				break;
			case 3:
				printf("Los numeros introducidos forman un triangulo equilatero\n\n");
				break;
			case 4:
				printf("Los numeros introducidos forman un triangulo escaleno\n\n");
				break;
		}
	}
	else{
		printf("\n\nERROR! Alguno de los numeros introducidos es negativo!\n\n\n");
	}
}

//Por ultimo, fijense en la identacion del codigo. Todo lo que va entre dos corchetes, una
//sengria a la derecha. Todo lo que va dentro de los cases del switch, tambien una sangria
//hacia la derecha. Los corchetes cierran en linea con la estructura que cierran.
