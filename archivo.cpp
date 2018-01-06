#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>

typedef struct n *pnodo;
typedef struct n
{
	int LU;
	pnodo sig;
}nodo;

void CargarListaEnteros(pnodo *lista)
{
	pnodo aux;

	aux=(pnodo) malloc (sizeof(nodo));

	printf("Ingrese un numero para la lista:\n");
	scanf("%i",&(aux->LU));
	getc(stdin);

	(*lista)=aux;

	while(aux->LU!=(-1))
	{
		aux->sig=(pnodo) malloc (sizeof(nodo));
		aux=aux->sig;
		printf("Ingrese un numero para la lista:\n");
		scanf("%i",&(aux->LU));
		getc(stdin);
	}
	aux->sig=NULL;
}

void MostrarLista(pnodo lista)
{
	int nro=1;
	pnodo aux;
	aux=lista;

	while(aux!=NULL)
	{
		printf("|Lista: %i|LU: %i|\n",nro,aux->LU);
		aux=aux->sig;
		nro++;
	}
}

void CopiarLISTAdeEnterosEnArch(pnodo copialista)
{
	FILE  *archivobin, *archivotxt;
	int nro;
	char caracter;

	printf("Escribir la lista de los legajos de los alumnos en un archivo:\n");
	printf("(B)inario o de texto (cualquier letra): ");
	scanf("%c",&caracter);
	getc(stdin);

	archivobin=fopen("Listalumnos.alu","wb");
	archivotxt=fopen("Listalumnos.txt","w");

	if((archivotxt==NULL)&&(archivotxt==NULL))
		printf("Error al acceder a los archivos...\n");
	else
	{
		while(copialista!=NULL)
		{
			if(caracter=='B')
			{
				nro=copialista->LU;
				fwrite(&nro,sizeof(int),1,archivobin);
			}
			else
				fprintf(archivotxt,"%i\n",copialista->LU);
			copialista=copialista->sig;
		}
	}
	fclose(archivobin);
	fclose(archivotxt);
}

int main (void)
{
	pnodo lista=NULL;

	printf("Se Cargara la lista de legajos de Alumnos|con -1 termina y se lo incluye ademas:\n\n");
	CargarListaEnteros(&lista);
	printf("\n");
	printf("La lista resultante es:\n");
	MostrarLista(lista);
	printf("\n");
	printf("Se copia la lista resultante en un archivo:\n");
	CopiarLISTAdeEnterosEnArch(lista);

	return 0;
}
