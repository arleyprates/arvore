#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char nome[10];
	char sexo[3];
	struct node *no_pai;	
	struct node *no_irmao;
	struct node *no_conjuge;
	struct node *no_filho;
} Registro;

typedef struct arvore {
	char nome[10];
	Registro *no;
	struct arvore *esquerda;
	struct arvore *direita;
} Arvore;

void inserirDados (Arvore *aux) {
	printf("Digite o nome da pessoa:\n");
	scanf ("%s", aux->nome);
	strcpy (aux->no->nome, aux->nome);
	printf("Digite o sexo da pessoa:\n");
	scanf ("%s", aux->no->sexo);
	printf("RETORNO2\n");	
}

Registro* criarRegistro () {
	Registro *novo;
	novo = (Registro*) malloc (sizeof(Registro));
	if (novo == NULL) {
		printf("RETORNO2.1 - ALOCACAO\n");
		return 0;
	}
	novo->no_pai = NULL;
	novo->no_irmao = NULL;
	novo->no_conjuge = NULL;
	novo->no_filho = NULL;
	return novo;
}

Arvore* criarNo () {
	Arvore* novo;
	novo = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2.0 - ALOCACAO\n");
		return 0;
	}
	novo->esquerda = NULL;
	novo->direita = NULL;
	return novo;
}

int registrar (Arvore **A1) {
	Arvore *novo;
	novo = criarNo ();
	novo->no = criarRegistro ();
	inserirDados (novo);
	*A1 = novo;
	printf("RETORNO1\n");
	return 1;
}


int main () {
	Arvore *A1, *A2;
	A1 = NULL;
	A2 = NULL;
	printf("=============================\n");
	printf("Menu\n");
	printf("1 - Registrar uma pessoa\n");
	printf("A1 %p\n", A1);
	registrar (&A1);
	registrar (&A2);
	registrar (&A2->direita);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);
	printf("A1->nome %s\n", A2->nome);
	printf("A1->no->nome %s\n", A2->no->nome);
	printf("A1->no->sexo %s\n", A2->no->sexo);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);
	printf("=============================\n");
	return 0;
}








