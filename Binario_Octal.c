#include <stdio.h>
#include <string.h>

int main() {
	
	int i;
	char numero[] = "1,1,1,0,1,0,0,1";
    int tamanho = strlen(numero); //isto funciona só para delimitador de 1 caractere
    char *token = strtok(numero, ",");
    for (i = 0; i < tamanho; i++) {
        printf(token[i] == 0 ? "\\0" : "%c", token[i]);
    }
    while(token != NULL) {
        printf("\n%s", token);
        token = strtok(NULL, ",");
    }
}
