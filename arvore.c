#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arvore {
	char nome[10];
	char sexo[3];
	struct arvore* pai;
	struct arvore* irmao;
	struct arvore* conjuge;
	struct arvore* filho;
} no;

/*typedef struct linha {
	//int inicio;
	int maximo;
	no* node;
} tabela;*/

typedef struct principal {
	//tabela *tab;
	char tabela[100][8];
	no *direita;
	no *esquerda;
} primeira;

void inserirDados (no *novo) {
	char nome[10];
	char sexo[3];
	printf("Digite o nome da pessoa:\n");
	gets (nome);
	strcpy (novo->nome, nome);
	printf("Digite o sexo da pessoa:\n");
	gets (sexo);
	strcpy (novo->sexo, sexo);
	printf("RETORNO2\n");
}

no* criarNo () {
	no *novo;
	novo = (no*) malloc (sizeof (no));
	if (novo == NULL) {
		printf("ERRO DE ALOCAO\n");
		return 0;
	}
	novo->pai = NULL;
	novo->irmao = NULL;
	novo->conjuge = NULL;
	novo->filho = NULL;
	printf("RETORNO3\n");
	return novo;
}

/*void inicializaVetor (primeira *P1, int tamanho) {
	P1->tab = (tabela*) malloc (tamanho*sizeof (tabela));
	if (P1->tab == NULL)
		printf("ERRO DE ALOCAO\n");
	P1->tab->maximo = tamanho;
	P1->tab->node = NULL;
	printf("RETORNO5\n");
}*/

int registrar (primeira *P1) {
	no *novo, *linha_nova;
	//para o primeiro elemento
	if (P1->direita == NULL && P1->esquerda == NULL) {
		novo = criarNo ();
		linha_nova = criarNo ();
		inserirDados (novo);
		P1->direita = novo;
		//linha_nova = novo;
		//P1->tab->node = novo;
		printf("RETORNO1\n");
		return 1;
	} /*else {
		while () {

		}
	}*/
	printf("RETORNO4\n");
	return 0;
}

//void imprimeArvore () {
//}

int main () {
	primeira *P1;
	int tamanho;
	//P1->tab = NULL;
	P1->direita = NULL;
	P1->esquerda = NULL;
	printf("=============================\n");
	printf("Menu\n");
	printf("1 - Registrar uma pessoa\n");
	registrar (P1);
	//inicializaVetor (P1, 100);
	printf("=============================\n");
	return 0;
}