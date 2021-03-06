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
	novo->direita = NULL;
	novo->esquerda = NULL;
	/*
	novo->esquerda = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2.2 - ALOCACAO\n");
		return 0;
	}
	novo->direita = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2.3 - ALOCACAO\n");
		return 0;
	}*/
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
	(*A1)->no->no_conjuge = criarRegistro ();
	(*A2)->no->no_conjuge = criarRegistro ();
	(*A1)->no->no_conjuge = (*A2)->no;
	(*A2)->no->no_conjuge = (*A1)->no;
	(*A1)->direita = novo;
	(*A2)->esquerda = novo;
	printf("RETORNO3\n");
	return 1;
}

int filho (Arvore **A1, Arvore **A2) {
	Arvore *novo, *aux;
	aux = *A1;
	while ((*A1)->direita != NULL) {
		printf("!while");
		if (aux->no->no_conjuge != NULL) {
			printf("aux->direita->nome %s\n", aux->direita->nome);
			aux->direita = aux->direita->direita;
			printf("aux->direita->nome %s\n", aux->direita->nome);
			if (aux->direita == NULL) {
				printf("aux->direita->nome %s\n", aux->direita->nome);
				novo = criarNo ();
				novo->no = criarRegistro ();
				inserirDados (novo);
				novo->no->no_pai = criarRegistro ();
				novo->no->no_pai = aux->no;
				aux->no->no_filho = criarRegistro ();
				aux->no->no_filho = novo->no;
				aux->direita = novo;
				printf(" aux->direita->nome %s\n", aux->direita->nome);
				printf("A1->direita->nome %s\n", (*A1)->direita->nome);
				return 1;
				//(*A1)->direita = novo;
			}
			break;
		}
	}
	printf("ESSE CASAL JA TEM UM FILHO\n");
	//printf("RETORNO4\n");
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
	filho (&A1, &A2);
	filho (&A1, &A2);	
	//return 0;
	printf("\n\n\n\n\n\nCasal\n");
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);
	printf("A2->no->nome %s\n", A2->no->nome);
	printf("A2->no->sexo %s\n", A2->no->sexo);
	printf("A1->no->no_filho->nome %s\n", A1->no->no_filho->nome);
	printf("A2->no->no_filho->nome %s\n", A2->no->no_filho->nome);
	printf("\n\n\n Casamento\n");
	printf("A1->direita->nome %s\n", A1->direita->nome);
	printf("A1->direita->no->nome %s\n", A1->direita->no->nome);/*
	printf("A1->no->sexo %s\n", A2->no->sexo);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("A1->no->sexo %s\n", A1->no->sexo);*/
	printf("=============================\n");
	return 0;
}








