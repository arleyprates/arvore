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

void inserirDados (Arvore *A1) {
	printf("Digite o nome da pessoa:\n");
	scanf ("%s", A1->nome);
	strcpy (A1->no->nome, A1->nome);
	printf("Digite o sexo da pessoa:\n");
	scanf ("%s", A1->no->sexo);
	printf("RETORNO2\n");	
}

Registro* criarRegistro () {
	Registro *novo;
	novo = (Registro*) malloc (sizeof(Registro));
	if (novo == NULL) {
		printf("RETORNO2.4 - ALOCACAO\n");
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
		printf("RETORNO2.1 - ALOCACAO\n");
		return 0;
	}
	novo->esquerda = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2.2 - ALOCACAO\n");
		return 0;
	}
	novo->direita = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2.3 - ALOCACAO\n");
		return 0;
	}
	return novo;
}

int criarRaiz (Arvore **A1) {
	Arvore *novo;
	novo = criarNo ();
	novo->no = criarRegistro ();
	inserirDados (novo);
	*A1 = novo;
	printf("RETORNO1\n");
	return 1;
}

int casamento (Arvore **A1) {
	Arvore *novo;
	novo = criarNo ();
	novo->no = criarRegistro ();
	inserirDados (novo);
	printf("novo->nome %s\n", novo->nome);
	printf("novo->no->sexo %s\n", novo->no->sexo);
	(*A1)->direita = *novo;
	printf("A1->nome %s\n", (*A1)->direita->nome);
	printf("A1->no->nome %s\n", (*A1)->direita->no->sexo);
	printf("RETORNO3\n");
	return 1;
}

int filho () {
	printf("RETORNO4\n");
	return 1;
}

int irmao () {
	printf("RETORNO5\n");
	return 1;
}

void imprimeEsquerda () {
	printf("RETORNO1.0\n");
}

void imprimeDireita () {
	printf("RETORNO1.1\n");
}

int main () {
	Arvore *A1, *A2;
	A1 = NULL;
	A2 = NULL;
	printf("=============================\n");
	printf("Menu\n");
	printf("1 - Registrar um casal\n");
	printf("2 - Registrar um casamento\n");
	criarRaiz (&A1);
	casamento (&A1->direita);
	//criarRaiz (&A2);
	
	

	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);
	printf("A1->nome %s\n", A1->direita->nome);
	printf("A1->no->nome %s\n", A1->direita->no->sexo);/*
	printf("A1->no->sexo %s\n", A2->no->sexo);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);*/
	printf("=============================\n");
	return 0;
}








