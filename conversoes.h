#ifndef CONVERSOES_H
#define CONVERSOES_H

#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

int Decimal_Octal() {
	
	double valor, valorInicial;
	int resto, count = 1;
	int resp;
	tp_pilha pilha;
	tp_item e;
			
		system("cls");
		inicializa_pilha(&pilha);
		
			printf("Valor a ser convertido: ");
			scanf("%lf", &valor);
			valorInicial = valor;
			printf("\n=============================================\n");
		
		while (valor >= 1) {
		
			resto = (int) valor % 8;
			e = resto;
			valor = valor / 8;
		
			printf("Divisão %d: %.2lf\n", count, valor);
			printf("Resto %d: %d\n\n", count, resto);
			
			push(&pilha, e);
			count++;
		}
		
		printf("==========================================================\n");
		printf("O valor (%.0lf)10 em Octal eh: ", valorInicial);
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
	
	double valor, valorInicial;
	int resto, count = 1;
	int resp;
	tp_pilha pilha;
	tp_item e;
	
		system("cls");	
		inicializa_pilha(&pilha);
		
			printf("Valor a ser dividido: ");
			scanf("%lf", &valor);
			valorInicial = valor;
			printf("\n=============================================\n");
		
		while (valor >= 1) {
		
			resto = (int) valor % 2;
			e = resto;
			valor = valor / 2;
		
			printf("Divisão %d: %.2lf\n", count, valor);
			printf("Resto %d: %d\n\n", count, resto);
			
			push(&pilha, e);
			count++;
		}
		printf("==========================================================\n");
		printf("O valor (%.0lf)10 em Binário eh: ", valorInicial);
		imprime_pilha(pilha);
		
		while (resp >= 4) {
		
			printf("\n\n==========================================================\n");
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
