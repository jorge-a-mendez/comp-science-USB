#include <stdio.h>
#include <stdlib.h>

//Se definen variables (registro) de tipo "pais". Ellas tendran informacion sobre el nombre, la poblacion y el idioma del pais.
typedef struct {
	char nombre[20];		//Arreglo de caracteres = string. Asi se manejan "frases" en C. Para leerlas con scanf (o fscanf) no pueden tener espacios.
	int poblacion;		
	char idioma[20];
}pais;

int leerPaises(FILE *fp, pais paises[100]){
	int i = 0;
	if(fp!=NULL){	//Verificamos que el apuntador no apunte a NULL (nada), lo que implica que abrio correctamente.
		while(!feof(fp) && i<100){		//!feof(fp): not end of file fp
			fscanf(fp,"%s %d %s",&((paises[i]).nombre),&((paises[i]).poblacion),&((paises[i++]).idioma));	//%s para strings. paises[i] es el iesimo pais del arreglo de paises.
																											//Ej.: (pais[i]).nombre se refiere al nombre del iesimo pais. 
		}
	}
	else printf("Error al abrir archivo\n\n");
	return i;
}

void escribirPaises(FILE *fp, pais paises[100], int tamano){
	int i = 0;
	if(fp!=NULL){	//verificamos que haya abierto
		while(i<tamano){	//mientras no llegue al final del arreglo de paises...
			fprintf(fp,"%s %d %s\n", (paises[i]).nombre, (paises[i]).poblacion, (paises[i++]).idioma);	//Imprimo en el archivo todos los datos de cada pais
																										//Me ahorro la linea i++ haciendolo en la ultima instruccion que use i.
		}
	}
	else printf("Error al abrir archivo\n\n");
}

void main(){
	pais paises[100];		//Arreglo de paises. Contiene mil elementos del tipo pais (cada uno con nombre, poblacion e idioma).
	FILE *fp1 = fopen("paises.txt","r");	//fp1 es un apuntador a archivos, forma en la cual se manejan los mismos. Abrimos paises.txt en modo solo lectura.
	int tamano = leerPaises(fp1, paises);
	printf("Lei %d paises", tamano);
	fclose(fp1);
	FILE *fp2 = fopen("paisesNuevo.txt","w");	//Abrimos paisesNuevo.txt en modo solo escritura. De esta manera, si no existe se crea.
	escribirPaises(fp2,paises, tamano);
	fclose(fp2);
}

//IMPORTANTE: los archivos a abrir deben estar en la misma carpeta del archivo ".c". De lo contrario, sera imposible abrirlos.
