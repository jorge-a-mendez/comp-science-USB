#include <stdio.h>
#include <stdlib.h>

void main(){
	int h,m,s;
	printf("Introduzca una hora en formato hh mm ss:\n");
	scanf("%d %d %d",&h,&m,&s);
	//Verificamos la precondicion: los minutos y los segundos deben ser
	//menores a 60. De lo contrario, el formato es incorrecto.
	if(m < 60 && s < 60){
		s = s + 1;		//sumo primero el segundo adicional a los segundos.
		if(s == 60){	//si con eso llego a 60..
			m = m + 1;		//sumo uno a los minutos
			s = 0;			//y reinicio los segundos.
			if(m == 60){	//Si los minutos llegan a 60..
				h = h + 1;		//sumo uno a las horas
				m = 0;			//y reinicio los minutos.
			}
		}
		//Les recomiendo hagan la corrida en frio hasta este punto. Prueben
		//con horas que tengan 59 segundos y 59 minutos...y asi.
		printf("\n\nLa hora introducida mas un segundo resulta:\n\n\t%.2d:%.2d:%.2d\n\n",h,m,s);
                //El %.2d asegura que se muestren dos cifras para cada uno de los enteros.
	}
	//Si no se cumple la precondicion, imprimo el mensaje de error.
	else{
		printf("ERROR: los numeros introducidos no corresponden a una hora\n\n");
	}
}
