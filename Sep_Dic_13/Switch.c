#include <stdio.h>
#include <stdlib.h>

void main(){
	int op,a,b,r,i,v=1;		//operacion, numero1, numero2, resultado, contador (para potencia), volver (1=TRUE, 0=FALSE)
	printf("\t\t\tMenu de Operaciones Matematicas\n\n");

	do{						//muestro el menu al menos una vez (recuerden que el do while hace todo al menos una vez y luego evalua la condicion)
		printf("Seleccione su opcion:\n\t1) Suma\n\t2) Multiplicacion\n\t3) Potencia\n\t4) Salir\nIntroduzca su opcion: ");		//muestro las opciones 
		scanf("%d",&op);				//y permito seleccionar al usuario
		switch(op){
			case 1:
				printf("\nIntroduzca los dos numeros a sumar:\n");
				scanf("%d %d",&a,&b);
				r = a + b;
				printf("\n\t\t%d + %d = %d\n\n",a,b,r);
				break;															//sin este break el programa realiza TODOS los casos siguientes hasta conseguir un break
			case 2:
				printf("\nIntroduzca los dos numeros a multiplicar:\n");
				scanf("%d %d",&a,&b);
				r = a * b;
				printf("\n\t\t%d * %d = %d\n\n",a,b,r);
				break;															//sin este break el programa realiza TODOS los casos siguientes hasta conseguir un break
			case 3:
				printf("\nIntroduzca la base y el exponente:\n");
				scanf("%d %d",&a,&b);
				r=1;
				for(i=0;i<b;i++){												//realizo a*a*a... hasta hacerlo b veces. Vean que en caso b=0 el resultado siempre es 1.
					r *= a;
				}
				printf("\n%d ^ %d = %d\n\n",a,b,r);
				break;															//sin este break el programa realiza TODOS los casos siguientes hasta conseguir un break
			case 4:
				v = 0;								//si la opcion es salir, quiere decir que no quiero volver. No realizo ninguna operacion y salgo
				break;								//sin este break el programa realiza TODOS los casos siguientes hasta conseguir un break
			default:
				printf("\nIntroduzca una opcion valida\n\n");			//si la opcion introducida es invalida simplemente muestra el menu de nuevo
				break;
		}
	} while(v!=0);									//vuelvo a mostrar el menu mientras el usuario quiera volver
													//fijense que SI iba el ; despues del while
}
