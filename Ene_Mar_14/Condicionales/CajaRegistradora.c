#include <stdio.h>
#include <stdlib.h>

void main(){
	int b=500, p, c_100, c_50, c_10, c_1, v_100, v_50, v_10, v_1;		//variables que me exige el enunciado (excepto b, que es por comodidad)
	int v;																//v es una variable auxiliar que va a almacenar siempre la cantidad de vuelto que falta por entregar
	printf("\tIntroduzca el precio del articulo a comprar: ");
	scanf("%d",&p);
	printf("\n\n\tIntroduzca la cantidad de billetes de 100, 50, 10 y 1 que hay actualmente en la caja: ");
	scanf("%d %d %d %d",&c_100, &c_50, &c_10, &c_1);					//hasta aqui me relaciono con el usuario, luego calculo
	v=b-p;            //valor inicial del vuelto (vuelto total a entregar)
	if(v<0){          //Verifico que se cumpla la unica precondicion necesaria
        printf("El billete de 500 no alcanza para pagar el producto");
	}
	else{	                     //Si el billete alcanza para pagar, procedo a calcular
        if(v/100<=c_100){		//si hay suficientes billetes de 100
            v_100=v/100;		//entrego el mayor numero de billetes de 100 que caben en el vuelto													//y lo que me queda por devolver es el total menos el vuelto que entrego en billetes de 100
        }
        else{
            v_100=c_100;	    //si no hay suficientes, doy todos los que tengo en la caja
        }
        v=v-100*v_100;			//independientemente, el vuelto que me queda por entregar es el total menos lo que entregue en billetes de 100
        if(v/50<=c_50){
            v_50=v/50;
        }
        else{
            v_50=c_50;
        }
        v=v-50*v_50;			//repito para 50, y resto lo que devuelvo en billetes de 50
        if(v/10<=c_10){
            v_10=v/10;
        }
        else{
            v_10=c_10;
        }
        v=v-10*v_10;			//repito para 10, y resto lo que devuelvo en billetes de 10
        if(v<=c_1){				//si tengo suficientes billetes de 1 para completar el vuelto
            v_1=v;				//entrego lo que falta
            printf("\n\n\tEl vuelto sera entregado de la siguiente manera:\n\n%d billetes de 100\n%d billetes de 50\n%d billetes de 10\n%d billetes de 1\n\n",v_100,v_50,v_10,v_1);
        }
        else{
            printf("\n\nNo hay suficiente dinero en la caja para dar el vuelto\n\n");		//si los billetes de 1 eran insuficientes, no hay forma de completar el vuelto
        }
	}
	
}
