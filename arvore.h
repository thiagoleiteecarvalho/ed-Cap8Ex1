/*
 * arvore.h
 * Header de definição da ED Árvore Clássica com vetor.
 * Author: Thiago Leite
 */

#pragma once

#define TAMANHO 3
typedef struct no {
	char valor;
	struct no *pai;
	struct no *filhos[TAMANHO];
} No;

void setRaiz(No *no);
No* getRaiz();
No* criar_no(No *pai, char elemento);
void criar_raiz(char elemento);
void insert(No *no, char pai, char elemento);
No* search(No *no, char elemento);
void update(No *no, char elemento, char novo_valor);
void delete(No *no);
void delete_subtree(No *no);
void free_no(No *no);
void exibir_pre_ordem(No *raiz);
