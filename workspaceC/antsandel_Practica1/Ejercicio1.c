/*
 * Ejercicio1.c
 *
 *  Created on: 31 de oct. de 2015
 *      Author: holdsnake
 */
#include <stdio.h>


int funcionRecursivaNoFinal(int n);
int funcionRecursivaFinalGeneralizado(int n);
int funcionRecursivaFinal(int n,int a,int b, int c, int d);
int funcionIterativa(int n);

int main()
{
	int n = 8;
	//Resultado esperado para n=8
	int res = 44;

	printf("Resultado del Algoritmo Recursivo No final de %d : %d\n",n,funcionRecursivaNoFinal(n));
	printf("Resultado del Algoritmo Recursivo Final de %d : %d\n",n,funcionRecursivaFinalGeneralizado(n));
	printf("Resultado del Algoritmo Iterativo de %d : %d\n",n,funcionIterativa(n));
	printf("Resultado esperado: %d",res);
	return 0;
}
int funcionRecursivaNoFinal(int n){
	//Casos bases
	if(n==0){
		return 4;
	}else if(n==1){
		return 3;
	}else if(n==2){
		return 2;
	}else if(n==3){
		return 1;
	//He a�adido un nuevo caso base por si me pasan por par�metro un numero negativo
	}else if(n<0){
		return 0;
	}

	return 2*funcionRecursivaNoFinal(n-2)+funcionRecursivaNoFinal(n-4);
}

int funcionRecursivaFinalGeneralizado(int n){
	return funcionRecursivaFinal(n,4,3,2,1);
}

int funcionRecursivaFinal(int n,int a,int b, int c, int d){
	if(n==0){
		return a;
	}else{
		return funcionRecursivaFinal(n-1,b,c,d,(2*c)+a);
	}

}

int funcionIterativa(int n){
	int i=0;
	int a=4;
	int b=3;
	int c=2;
	int d=1;
	int d0;
	//He a�adido un nuevo caso base por si me pasan por par�metro un numero negativo
	if(n<0){
		return 0;
	}
	while(i<n){
		i=i+1;
		d0=(2*c)+a;
		a=b;
		b=c;
		c=d;
		d=d0;
	}
	return a;
}
