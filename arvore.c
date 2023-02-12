/*
 * arvore.c
 * Classe de implemantação da ED Árvore Clássica com vetor.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *raiz = NULL;

void setRaiz(No *no) {
	raiz = no;
}

No* getRaiz() {
	return raiz;
}

No* criar_no(No *pai, char elemento) {

	No *no = malloc(sizeof(No));
	no->valor = elemento;
	no->pai = pai;
	no->filhos[0] = NULL;
	no->filhos[1] = NULL;
	no->filhos[2] = NULL;

	return no;
}

void criar_raiz(char elemento) {

	if (raiz == NULL) {

		raiz = criar_no(NULL, elemento);
	} else {
		printf("Raiz já foi criada\n");
	}
}

void insert(No *raiz, char pai, char elemento) {

	if (raiz == NULL) {
		printf("Raiz nula. Insert de nó não permitido!\n");
		return;
	}

	No *no_pai = search(raiz, pai);

	if (no_pai != NULL) { /*I*/

		if (no_pai->filhos[0] == NULL) {
			no_pai->filhos[0] = criar_no(no_pai, elemento);
		} else if (no_pai->filhos[1] == NULL) {
			no_pai->filhos[1] = criar_no(no_pai, elemento);
		} else if (no_pai->filhos[2] == NULL) {
			no_pai->filhos[2] = criar_no(no_pai, elemento);
		} else {
			printf("O nó %c não possui mais filhos disponíveis.\n", pai);
		}
	} else {
		printf("O nó pai %c não pertence a árvore.\n", pai);
	}
}

No* search(No *no, char elemento) {

	if (no != NULL) {

		if (no->valor == elemento) {
			return no;
		} else {

			No *no_procurado;

			no_procurado = search(no->filhos[0], elemento);
			if (no_procurado != NULL)
				return no_procurado;

			no_procurado = search(no->filhos[1], elemento);
			if (no_procurado != NULL)
				return no_procurado;

			no_procurado = search(no->filhos[2], elemento);
			if (no_procurado != NULL)
				return no_procurado;

		}
	}
	return NULL;
}

void update(No *raiz, char elemento, char novo_valor) {

	No *no = search(raiz, elemento);

	if (no != NULL) {
		no->valor = novo_valor;
	} else {
		printf("Nó não encontrado. Impossível realizar update.");
	}
}

void delete(No *no) {

	No *pai = no->pai;

	delete_subtree(no);

	if (pai != NULL) {

		if (pai->filhos[0] == no) {
			pai->filhos[0] = NULL;
		}
		if (pai->filhos[1] == no) {
			pai->filhos[0] = NULL;
		}
		if (pai->filhos[2] == no) {
			pai->filhos[2] = NULL;
		}
	}
}

void delete_subtree(No *no) {

	if (no != NULL) {

		delete_subtree(no->filhos[0]);
		delete_subtree(no->filhos[1]);
		delete_subtree(no->filhos[2]);

		free(no);
		no = NULL;
	}
}

void exibir_pre_ordem(No *no) {

	if (no != NULL) {

		printf("%c ", no->valor);
		exibir_pre_ordem(no->filhos[0]);
		exibir_pre_ordem(no->filhos[1]);
		exibir_pre_ordem(no->filhos[2]);
	}

}
