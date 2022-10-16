#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPessoas.h"

struct celulaListaPessoa_st{
    Pessoa* pessoa;
    CelulaListaPessoa* prox;
};

struct listaPessoa_st {
    CelulaListaPessoa* prim;
    CelulaListaPessoa* ult;
};


ListaPessoa* inicListaPessoa() {
    ListaPessoa* listaPessoa = (ListaPessoa*) malloc(sizeof(ListaPessoa));

    listaPessoa->prim = NULL;
    listaPessoa->ult = NULL;

    return listaPessoa;
}

void inserePessoaLista(ListaPessoa* listaPessoa, Pessoa* pessoa){
    CelulaListaPessoa* nova = (CelulaListaPessoa*) malloc(sizeof(CelulaListaPessoa));

    nova->pessoa = pessoa;

    if(listaPessoa->prim == NULL){
        listaPessoa->prim = nova;
        listaPessoa->ult = nova;
    } else{
        listaPessoa->ult->prox = nova;
        listaPessoa->ult = nova;
    }
    listaPessoa->ult->prox = NULL;
}

Pessoa* retornaPessoa(ListaPessoa* listaPessoa, char* nome) {
    CelulaListaPessoa* celula = listaPessoa->prim;

    while(celula != NULL) {
        //printf("celula->pessoa: %s\t nome: %s\n", retornaNomePessoa(celula->pessoa), nome);
        if(!strcmp(retornaNomePessoa(celula->pessoa), nome))
            return celula->pessoa;
        celula = celula->prox;
    }

    printf("Nao existe essa pessoa na lista - retornaPessoa()\n");
    return NULL;
}

ListaPessoa* leArquivos() {
    FILE* amizade;
    amizade = fopen("./Entrada/amizade.txt","r");
    if (amizade == NULL){
        printf("Erro na abertura do arquivo - leAmizades()\n");
        exit(1);
    }

    ListaPessoa* listaPessoa = inicListaPessoa();
    
    char nome1[15];
    char c = 'a';

    while(c != '\n' && !feof(amizade)) {
        fscanf(amizade,"%[^;\n]%c", nome1, &c);
        inserePessoaLista(listaPessoa,inicPessoa(nome1));
    }

    char amigo1[15];
    char amigo2[15];

    while(!feof(amizade)) {
        fscanf(amizade, "%[^;];%[^\n]\n", amigo1, amigo2);
        Pessoa* pessoa1 = retornaPessoa(listaPessoa,amigo1);
        Pessoa* pessoa2 = retornaPessoa(listaPessoa,amigo2);
        insereAmigoPessoa(pessoa1, pessoa2);
    }

    fclose(amizade);

    FILE* playlistxt;
    playlistxt = fopen("./Entrada/playlists.txt","r");
    if (playlistxt == NULL){
        printf("Erro na abertura do arquivo - leArquivos()\n");
        exit(1);
    }

    while(!feof(playlistxt)) {
        char nome2[15];
        char nomePlaylist[20];
        int n = 0;

        fscanf(playlistxt, "%[^;];%d;", nome2, &n);
        Pessoa* pessoaPremiada = retornaPessoa(listaPessoa, nome2);

        for(int i = 0; i < n; i++){
            fscanf(playlistxt, "%[^;\n]%*c", nomePlaylist);

            Playlist* playlist = lePlaylist(nomePlaylist);

            inserePlaylistPessoa(pessoaPremiada, playlist);
        }
    }

    fclose(playlistxt);

    return listaPessoa;
}

void imprimeListaPessoa(ListaPessoa* listaPessoa) {
    CelulaListaPessoa* celula = listaPessoa->prim;
    if(celula == NULL){
        printf("Lista nao possui pessoas.\n");
        return;
    }

    while(celula != NULL) {
        imprimePessoa(celula->pessoa);
        putchar('\n');
        celula = celula->prox;
    }

    putchar('\n');
}

void refatoradaLista(ListaPessoa* listaPessoa) {
    CelulaListaPessoa* celula = listaPessoa->prim;
    /*
    FILE* refatsaida;
    refatsaida = fopen("./Saida/played-refatorada.txt", "w");
    */

    while(celula != NULL) {
        refatorada(celula->pessoa);
        celula = celula->prox;
    }
}

void similaridadesLista(ListaPessoa* listaPessoa) {
    FILE* amizade;
    amizade = fopen("./Entrada/amizade.txt","r");
    if (amizade == NULL){
        printf("Erro na abertura do arquivo - similaridadesLista()\n");
        exit(1);
    }

    FILE* similaridadetxt;
    similaridadetxt = fopen("./Saida/similaridades.txt","a");
    if (similaridadetxt == NULL){
        printf("Erro na abertura do arquivo - similaridadesLista()\n");
        exit(1);
    }

    int count = 0;

    char amigo1[20];
    char amigo2[20];

    fscanf(amizade, "%*[^\n]\n");
    
    while(!feof(amizade)) {
        count = 0;
        
        fscanf(amizade, "%[^;];%[^\n]\n", amigo1, amigo2);
        
        Pessoa* pessoa1 = retornaPessoa(listaPessoa,amigo1);
        Pessoa* pessoa2 = retornaPessoa(listaPessoa,amigo2);

        count = similaridades(pessoa1, pessoa2);

        fprintf(similaridadetxt, "%s;%s;%d\n", amigo1, amigo2, count);
        
    }    

    fclose(amizade);
    fclose(similaridadetxt);
}

void imprimePlaylistsArquivoLista(ListaPessoa* listaPessoa) {
    CelulaListaPessoa* p = listaPessoa->prim;

    while(p != NULL){
        imprimePlaylistsArquivo(p->pessoa);
        p = p->prox;
    }
}

void destroiListaPessoa(ListaPessoa* listaPessoa){
    CelulaListaPessoa* p = listaPessoa->prim;
    CelulaListaPessoa* temp;

    while(p != NULL){
        temp = p->prox;
        destroiPessoa(p->pessoa);
        free(p);
        p = temp;
    }

    free(listaPessoa);
}