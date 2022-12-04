#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int info;
	struct no *esq, *dir;
};noArv;

Arvore *criar-arv(int x, Arvore *sal, Arvore *sad);
Arvore *r;
r=(Arvore *)malloc(sizeoff(Arvore));
r->info=x;
r->esq=sad;
r->dir=sal;

return r;

//INSERIR
 /*
    Inserir versão 2
*/
void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void imprimir_versao_2(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

 /*
    Função recursiva para buscar um elemento em uma árvore binária de busca
*/
NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}
 //em ordem
  void emOrdem(struct No *pNo) {
     if(pNo != NULL) {
         emOrdem(pNo?pEsquerda);
         visita(pNo);
         emOrdem(pNo?pDireita);
     }
 }
 
 //PRE ORDEM
  void preOrdem(Struct No *pNo){
     if(pNo != NULL){
         visita(pNo);
         preOrdem(pNo?pEsquerda);
         preOrdem(pNo?pDireita);
     }
 }
 
 //POS ORDEM 
  void posOrdem(Struct No *pNo){
     if(pNo != NULL){
         posOrdem(pNo?pEsquerda);
         posOrdem(pNo?pDireita);
         visita(pNo);
     }
 }
 
 //CONTRUCAO DE CIMA PRA BAIXO
 

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar_versao_1(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}