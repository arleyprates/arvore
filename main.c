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
	char nome[10];
	char sexo[3];
	printf("Digite o nome da pessoa:\n");
	gets (nome);
	strcpy (A1->nome, nome);
	strcpy (A1->no->nome, nome);
	printf("Digite o sexo da pessoa:\n");
	gets (sexo);
	strcpy (A1->no->sexo, sexo);
	printf("RETORNO2\n");	
}

Registro* criarRegistro () {
	Registro *novo;
	novo = (Registro*) malloc (sizeof(Registro));
	if (novo == NULL) {
		printf("RETORNO2 - ALOCACAO\n");
		return 0;
	}
	return novo;
}

Arvore* criarNo () {
	Arvore* novo;
	novo = (Arvore*) malloc (sizeof(Arvore));
	if (novo == NULL) {
		printf("RETORNO2 - ALOCACAO\n");
		return 0;
	}
	return novo;
}
int registrar (Arvore *A1) {
	Arvore *novo;
	novo = criarNo ();
	A1 = novo;
	novo->no = criarRegistro ();
	A1->no = novo->no;
	inserirDados (novo);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("RETORNO1\n");
	return 1;
}

int main () {
	Arvore *A1, *A2;
	//A1 = NULL;
	//A2 = NULL;
	printf("=============================\n");
	printf("Menu\n");
	printf("1 - Registrar uma pessoa\n");
	registrar (A1);
	printf("A1->nome %s\n", A1->nome);
	printf("A1->no->nome %s\n", A1->no->nome);
	printf("=============================\n");
	return 0;
}








