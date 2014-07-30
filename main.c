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
} No;

typedef struct arvore {
	char nome[10];
	No* no;
	struct arvore *esquerda;
	struct arvore *direita;
} Arvore;

int main () {
	Arvore *A1, *A2;
	A1 = NULL;
	A2 = NULL;
	return 0;
}