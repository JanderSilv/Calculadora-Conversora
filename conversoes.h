#ifndef CONVERSOES_H
#define CONVERSOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha_estatica.h"
#include "operacoes.h"

int Decimal_Octal() {
	
	int valor, valorInicial, resto;
	int count = 1, resp = 4;
	tp_pilha pilha;
	tp_item e;
			
		system("cls");
		inicializa_pilha(&pilha);
		
			printf("* Decimal -> Octal *\n\n");
			printf("Valor a ser convertido: ");
			scanf("%d", &valor);
			valorInicial = valor;
			printf("\n=============================================\n");
		
		while (valor >= 1) {
		
			resto = valor % 8;
			e = resto;
			valor = valor / 8;
		
			printf("Divisão %d: %d\n", count, valor);
			printf("Resto %d: %d\n\n", count, resto);
			
			push(&pilha, e);
			count++;
		}
		
		printf("=====================================================\n");
		printf("O valor (%d)10 em Octal eh: ", valorInicial);
		imprime_pilha_no_space(pilha);
		
		while (resp >= 4) {
		
			printf("\n\n==========================================================\n");
			printf("\nContinuar? \n\n(1) Sim \n(2) Voltar para o Menu \n(3) Sair \n\nOpção: ");
			scanf("%d", &resp);
			
			switch (resp) {
				case 1:
					return Decimal_Octal();
				case 2:
					system("cls");
					return main();
				case 3:
					exit(0);
				default:
					system("cls");
					printf("\n Opção Inválida");
			}
		}
}

int Decimal_Binario() {
	
	int valor, valorInicial, resto;
	int count = 1, resp = 4;
	tp_pilha pilha;
	tp_item e;
	
		system("cls");	
		inicializa_pilha(&pilha);
		
			printf("* Decimal -> Binário *\n\n");
			printf("Valor a ser convertido: ");
			scanf("%d", &valor);
			valorInicial = valor;
			printf("\n=============================================\n");
		
		while (valor >= 1) {
		
			resto = valor % 2;
			e = resto;
			valor = valor / 2;
		
			printf("Divisão %d: %d\n", count, valor);
			printf("Resto %d: %d\n\n", count, resto);
			
			push(&pilha, e);
			count++;
		}
		printf("=====================================================\n");
		printf("O valor (%d)10 em Binário eh: ", valorInicial);
		imprime_pilha(pilha);
		
		while (resp >= 4) {
		
			printf("\n\n=====================================================\n");
			printf("\nContinuar? \n\n(1) Sim \n(2) Voltar para o Menu \n(3) Sair \n\nOpção: ");
			scanf("%d", &resp);
			
			switch (resp) {
				case 1:
					return Decimal_Binario();
				case 2:
					system("cls");
					return main();
				case 3:
					exit(0);
				default:
					system("cls");
					printf("\n Opção Inválida");
			}
		}
}

int Octal_Decimal() {
	
	system("cls");
	
	int valor, numero[10], resultado = 0;
	char str[10];
	int i, count = 1, resp = 4;
		
		printf("* Octal -> Decimal *\n\n");
		printf("Valor a ser convertido: ");
		scanf("%d", &valor);
		
		printf("\n=====================================================\n");

		sprintf(str,"%d",valor);
		
		for(i=0;i<strlen(str);i++) {
//		 	printf("%c ",str[i]);
		 	numero[i] = str[i] - '0';
		}
		
		int a = 0;
		int size = contaDigitos(valor);
		for(i=0;i<size;i++) {
			a++;
			int parcial = (numero[i] * pow(8,size-a));		
			resultado += parcial;
			printf("\nOperação %d: %d\n", count, parcial);
			count++;
		}
		
		printf("\n=====================================================\n\n");
		printf("O valor (%d)8 em Decimal eh: %d", valor, resultado);
		
		while (resp >= 4) {
		
			printf("\n\n=====================================================\n");
			printf("\nContinuar? \n\n(1) Sim \n(2) Voltar para o Menu \n(3) Sair \n\nOpção: ");
			scanf("%d", &resp);
			
			switch (resp) {
				case 1:
					return Decimal_Binario();
				case 2:
					system("cls");
					return main();
				case 3:
					exit(0);
				default:
					system("cls");
					printf("\n Opção Inválida");
				}
		}
}

#endif
