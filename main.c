#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char nome[10];
	char sexo[3];
	struct *no_pai;	
	struct *no_irmao;
	struct *no_conjuge;
	struct *no_filho;
} No;

typedef struct arvore {
	char nome[10];
	No* no;
	struct arvore *esquerda
	struct arvore *direita;
} Arvore;

int main () {
	return 0;
}