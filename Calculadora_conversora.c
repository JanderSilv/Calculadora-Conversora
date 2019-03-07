#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"
#include <locale.h>

void main(){
setlocale(LC_ALL, "portuguese");
	
	double valor, valorInicial;
	int resto, count;
	int resp;
	tp_pilha pilha;
	tp_item e;
	
	do {
	
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
	printf("O valor %.0lf em Binário eh: ", valorInicial);
	imprime_pilha(pilha);
	
	printf("\n\nContinuar? Sim(1) | Não(2): ");
	scanf("%d", &resp);
	
	} while (resp == 1);
}

