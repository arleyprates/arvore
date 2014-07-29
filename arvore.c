#include <stdlib.h>
#include <stdio.h>

typedef struct arvore {
	char nome;
	char sexo;
	struct arvore* pai;
	struct arvore* irmao;
	struct arvore* conjuge;
	struct arvore* filho;
} no;

typedef struct linha {
	no* linha;
} tabela;

struct principal {
	tabela tab;
	no* direita;
	no* esquerda;
};

int main () {
	return 0;
}