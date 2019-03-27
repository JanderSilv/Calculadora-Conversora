#include <locale.h>
#include "Conversoes.h"

void CarregarLogo();

int main() {
setlocale(LC_ALL,"portuguese");	
	
	CarregarLogo();
	int resp;
	//bacon mandou funcinar
	
	printf("\n\nEscolha a convers�o: \n\n(1) Decimal->Bin�rio \n(2) Decimal->Octal \n(3) Octal->Decimal \n(4) Octal->Bin�rio \n(5) Bin�rio->Decimal \n\nOp��o: ");
	scanf("%d", &resp);
	
	switch (resp) {
		case 1:
			Decimal_Binario();
		break;
		case 2:
			Decimal_Octal();
		break;
		case 3:
			Octal_Decimal();
		break;
		case 4:
			Octal_Binario();
		break;
		case 5:
			Binario_Decimal();
		break;	
		default:
			system("cls");
			printf("\nOp��o inv�lida.\n");
			return main();
	}
}

/* Fun��o para carregar a logo do Programa */
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
		// L� uma linha (inclusive com o '\n')
	      result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n'
	      if (result)  // Se foi poss�vel ler
		  printf("%s",Linha);
	  }
	  
	  fclose(arq);
}
