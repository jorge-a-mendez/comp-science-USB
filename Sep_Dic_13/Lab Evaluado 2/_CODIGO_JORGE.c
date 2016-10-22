#include <stdio.h>
#include <stdlib.h>

int DiasDelMes(int m){
	int r;
	switch(m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			r = 31;
			break;
		case 2:
			r = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			r = 30;
			break;
		default: 		//El default no era necesario, pero se lo agrego para que vean...
			r = 0;		//r = 0 funcionara como caracter de control, para verificar en funciones
						// que llamen a esta si el resultado es valido.
			printf("El numero introducido no corresponde a ningun mes\n");
			break;
	}
	return r;
}

void main(){
	int d1,m1,d2,m2,i,r=0;
	printf("Introduzca dos fechas (d1 m1 d2 m2):\n\n");
	scanf("%d %d %d %d",&d1,&m1,&d2,&m2);

	//A continuacion se verifica el cumplimiento de todas las condiciones necesarias (cosa que ustedes no tenian que hacer)
	//1.- Que el mes uno sea menor al dos o, si son iguales, que el dia 1 sea menor o igual al dos.
	//2.- Que los dias sean positivos.
	//3.- Que los dias no sean mas que la cantidad de dias del mes (aqui se verifica tambien que el mes sea valido ya que,
	//    de lo contrario, DiasDelMes(m1) retornaria 0 y no se cumpliria que el dia sea menor o igual).
	//TODAS deben cumplirse, por lo que se usa AND.

	if((m1<m2 || m1==m2 && d1<=d2) && d1>0 && d2>0 && d1<=DiasDelMes(m1) && d2<=DiasDelMes(m2)){
		for(i=m1;i<m2;i++){
			r += DiasDelMes(i);		//sumo todos los dias desde el mes 1 (inclusive) hasta el mes 2 (sin incluir)
		}
		r += d2-d1;					//resto los dias que ya transcurrieron del mes 1 y sumo los que transcurriran del mes 2.
		printf("La cantidad de dias entre el %.2d/%.2d y el %.2d/%.2d es: %d\n\n\n",d1,m1,d2,m2,r);
	}
	else printf("Introduzca valores validos\n\n\n");
}
