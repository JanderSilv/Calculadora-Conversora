#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>

#define MAX_PILHA 100

typedef int tp_item;

typedef struct {
	int topo;
	tp_item item[MAX_PILHA];
}tp_pilha;

// função que inicializa a pilha (faz o topo apontar para -1, no caso, o primeiro "local" da pilha);
void inicializa_pilha(tp_pilha *p){
	p->topo = -1;
}

// função que verifica se a pilha esta cheia;
int pilha_cheia(tp_pilha *p){
	if(p->topo == MAX_PILHA-1){
		return 1;
	} else {
		return 0;
	}
}

// função que verifica se a pilha esta vazia;
int pilha_vazia(tp_pilha *p){
	if(p->topo == -1){
		return 1;
	} else {
		return 0;
	}
}

// função que acrescenta um elemento no topo da pilha - PUSH;
int push(tp_pilha *p, tp_item e){
	if(pilha_cheia(p) == 1){
		return 0;
	} else {
		p->topo++;
		p->item[p->topo] = e;
		return 1;
	}
}

// função que retorna o ultimo elemento da pilha (o que esta no topo) essa função retira o elemento;
// nessa implementação retorna o status da pilha e, passsa por referencia o elemento;
int pop(tp_pilha *p, tp_item *e){
	if (pilha_vazia(p)){
		return 0;				//retorna 0 se a pilha esta vazia; 
	} else {
		*e = p->item[p->topo];	//na main, terá uma variavel para ser passada por referencia para receber o valor de e;
		p->topo--;
		return 1;				//retorna 1 se a pilha possui elementos;
	}
}

// função para imprimir a pilha, eh passado por cópia para nao ser necessario esvaziar a pilha inteira para imprimir; 
void imprime_pilha(tp_pilha p){
	tp_item e;
	while(!pilha_vazia(&p)){
		pop(&p, &e);
		printf("%d ", e);
	}
}

// função para verificar o tamanho/altura da pilha;
int altura_pilha(tp_pilha *p){
	return p->topo;
}


// função que permite vizualizar o elemento que esta no topo, sem decrescer a variável topo; 
int top(tp_pilha *p, tp_item *e){
	if (pilha_vazia(p)){
		return 0;				//retorna 0 se a pilha esta vazia; 
	} else {
		*e = p->item[p->topo];	//na main, terá uma variavel para ser passada por referencia para receber o valor de e;
		return 1;				//retorna 1 se a pilha possui elementos;
	}
}

int concatena_pilhas(tp_pilha *p1, tp_pilha *p2){

	tp_pilha p3;
	inicializa_pilha(&p3);
	int i;
	tp_item x;
	
	if(altura_pilha(p1) + altura_pilha(p2) >  MAX_PILHA){
		return 0;
	} else {
		//retira todos os elementos de p2 e coloca numa pilha auxiliar p3;
		while(!pilha_vazia(p2)){
			pop(p2, &x);
			push(&p3, x);
		}
		//retira todos os elementos de p3 e coloca numa pilha auxiliar p1;
		while (!pilha_vazia(&p3)){
			pop(&p3, &x);
			push(p1, x);
		}
		
		return 1;
	}
}

int compara_pilhas (tp_pilha p1, tp_pilha p2){
	tp_item x, y;
	
	if(altura_pilha(&p1) != altura_pilha(&p2)) return 0;
	while(!pilha_vazia(&p1)){
		pop(&p1, &x);
		pop(&p2, &y);
		if(x != y) return 0;
	}
	
	return 1;

}




#endif
