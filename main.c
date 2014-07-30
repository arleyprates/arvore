#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char nome[20];
	char sexo[3];
	struct node *no_pai;	
	struct node *no_irmao;
	struct node *no_conjuge;
	struct node *no_filho;
} Registro;

typedef struct arvore {
	char nome[20];
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

int casamento (Arvore **A1, Arvore **A2) {
	Arvore *novo;
	novo = criarNo ();
	novo->no = criarRegistro ();
	strcpy (novo->nome, "cas ");
	strcpy (novo->no->nome,  "cas ");
	strcat (novo->nome, (*A1)->nome);
	strcat (novo->no->nome,  (*A1)->nome);
	strcat (novo->nome, " e ");
	strcat (novo->no->nome,  " e ");
	strcat (novo->nome, (*A2)->nome);
	strcat (novo->no->nome,  (*A2)->nome);
	(*A1)->direita = novo;
	(*A2)->esquerda = novo;	
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
	criarRaiz (&A2);
	casamento (&A1, &A2);
	
	printf("\n\n\n Casal\n");
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);
	printf("A2->no->nome %s\n", A2->no->nome);
	printf("A2->no->sexo %s\n", A2->no->sexo);
	printf("\n\n\n Casamento\n");
	printf("A1->->direita->nome %s\n", A1->direita->nome);
	printf("A1->direita->no->nome %s\n", A1->direita->no->nome);/*
	printf("A1->no->sexo %s\n", A2->no->sexo);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);*/
	printf("=============================\n");
	return 0;
}








