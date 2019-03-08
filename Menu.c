#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Conversoes.h"

void CarregarLogo();

int main() {
setlocale(LC_ALL,"portuguese");	
	
	CarregarLogo();
	int resp;
	
	printf("\n\nEscolha a conversão: \n\n(1) Decimal->Binario \n(2) Decimal->Octal \n\nOpção: ");
	scanf("%d", &resp);
	
	switch (resp) {
		case 1:
			Decimal_Binario();
		break;
		case 2:
			Decimal_Octal();
		break;
		default:
			system("cls");
			printf("\nOpção inválida.\n");
			return main();
	}
}

/* Função para carregar a logo do Programa */
void CarregarLogo() {
	
  FILE *arq;
  char Linha[100];
  char *result;

	  // Abre um arquivo TEXTO para LEITURA
	  arq = fopen("Menu_Logo.txt", "rt");
	
	  if (arq == NULL) { // Se houve erro na abertura
	     printf("Problemas na abertura do arquivo\n");
	     return;
	  }
	  
	  while (!feof(arq)) {
		// Lê uma linha (inclusive com o '\n')
	      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
	      if (result)  // Se foi possível ler
		  printf("%s",Linha);
	  }
	  
	  fclose(arq);
}
