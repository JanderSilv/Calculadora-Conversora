#ifndef OPERACOES_H
#define OPERACOES_H

int contaDigitos(int valor) {
	int contaDigitos = 0;
	
     	if (valor == 0) contaDigitos = 1;
     	else
     		while (valor != 0) {
     			contaDigitos = contaDigitos + 1;
     			valor = valor / 10;
     		}
//    printf("\n%d", contaDigitos);
    return contaDigitos;
}

#endif
