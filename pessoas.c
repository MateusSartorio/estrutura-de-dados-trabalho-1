#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "pessoas.h"

struct celulaPlaylist_st{
    Playlist* playlist;
    CelulaPlay* prox;
};

struct listaPlaylists_st {
    CelulaPlay* prim;
    CelulaPlay* ult;
};

struct celulaAmigo_st {
    char* amigo;
    CelulaAmigo* prox;
};

struct listaAmigos_st {
    CelulaAmigo* prim;
    CelulaAmigo* ult;
};

struct pessoa_st{
    char* nome;
    ListaAmigos* listaAmigos;
    ListaPlaylists* listaPlaylists;
};

Pessoa* inicPessoa(char* nome){
    Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));

    pessoa->nome = strdup(nome);
    pessoa->listaAmigos = inicListaAmigos();
    pessoa->listaPlaylists = inicListaPlaylists();

    return pessoa;
}

ListaAmigos* inicListaAmigos(){
    ListaAmigos* listaAmigos = (ListaAmigos*)malloc(sizeof(ListaAmigos));
    listaAmigos->prim = NULL;
    listaAmigos->ult = NULL;

    return listaAmigos;
}

ListaPlaylists* inicListaPlaylists() {
    ListaPlaylists* listaPlaylists = (ListaPlaylists*) malloc(sizeof(ListaPlaylists));
    listaPlaylists->prim = NULL;
    listaPlaylists->ult = NULL;

    return listaPlaylists;
}

void insereAmigoPessoa(Pessoa* pessoa, Pessoa* amigo) {
    CelulaAmigo* amigoCel1 = (CelulaAmigo*)malloc(sizeof(CelulaAmigo));

    amigoCel1->amigo = retornaNomePessoa(amigo);

    if(pessoa->listaAmigos->prim == NULL){
        pessoa->listaAmigos->prim = amigoCel1;
        pessoa->listaAmigos->ult = amigoCel1;
    } else{
        pessoa->listaAmigos->ult->prox = amigoCel1;
        pessoa->listaAmigos->ult = amigoCel1;
    }
    pessoa->listaAmigos->ult->prox = NULL;


    CelulaAmigo* amigoCel2 = (CelulaAmigo*) malloc(sizeof(CelulaAmigo));

    amigoCel2->amigo = retornaNomePessoa(pessoa);

    if(amigo->listaAmigos->prim == NULL){
        amigo->listaAmigos->prim = amigoCel2;
        amigo->listaAmigos->ult = amigoCel2;
    } else{
        amigo->listaAmigos->ult->prox = amigoCel2;
        amigo->listaAmigos->ult = amigoCel2;
    }
    amigo->listaAmigos->ult->prox = NULL;

}

void inserePlaylistPessoa(Pessoa* pessoa, Playlist* playlist) {
    CelulaPlay* playlistCel = (CelulaPlay*) malloc(sizeof(CelulaPlay));

    playlistCel->playlist = playlist;

    if(pessoa->listaPlaylists->prim == NULL){
        pessoa->listaPlaylists->prim = playlistCel;
        pessoa->listaPlaylists->ult = playlistCel;
    } else{
        pessoa->listaPlaylists->ult->prox = playlistCel;
        pessoa->listaPlaylists->ult = playlistCel;
    }
    pessoa->listaPlaylists->ult->prox = NULL;
}

void inserePlaylistLista(ListaPlaylists* listaPlaylists, Playlist* playlist) {
    CelulaPlay* playlistCel = (CelulaPlay*) malloc(sizeof(CelulaPlay));

    playlistCel->playlist = playlist;

    if(listaPlaylists->prim == NULL){
        listaPlaylists->prim = playlistCel;
        listaPlaylists->ult = playlistCel;
    } else{
        listaPlaylists->ult->prox = playlistCel;
        listaPlaylists->ult = playlistCel;
    }
    listaPlaylists->ult->prox = NULL;
}

void insereMusicaPorNome(ListaPlaylists* listaPlaylist, char* nomePlaylist, Musica* musica) {
    CelulaPlay* celulaPlaylist = listaPlaylist->prim;
    char txt[] = ".txt";
    char* nomeTmp;
    char nomePlaylistCopia[60];
    int count = 0;
    strcpy(nomePlaylistCopia, nomePlaylist);
    Musica* musicaCopia;

    strcat(nomePlaylistCopia,txt);

    while(celulaPlaylist != NULL && count == 0) {
        nomeTmp = retornaNomePlaylist(celulaPlaylist->playlist);

        if(!strcmp(nomeTmp, nomePlaylistCopia)) {
            musicaCopia = copiaMusica(musica);

            insereMusicaPlaylist(celulaPlaylist->playlist, musicaCopia);

            count++;
        }
        celulaPlaylist = celulaPlaylist->prox;
    }
}

char* retornaNomePessoa(Pessoa* pessoa){
    return pessoa->nome;
}

void refatorada(Pessoa* pessoa){
    FILE* playedRefatorada;
    playedRefatorada = fopen("./Saida/played-refatorada.txt","a");
    if (playedRefatorada == NULL){
        printf("Erro na abertura do arquivo - refatorada()\n");
        exit(1);
    }

    CelulaPlay* celula = pessoa->listaPlaylists->prim;
    ListaPlaylists* listaPlay = inicListaPlaylists();
    Playlist* playlistTmp;
    Musica* musica;
    char autorMusica[50];
    char txt[] = ".txt";
    int i = 0;
    int j = 0;
    int n = 0;
    int igual = 0;
    
    char vetor[50][60];
    
    while(celula != NULL) {
        i = 0;
        musica = retornaMusica(celula->playlist, i);
        
        while(musica != NULL) {
            strcpy(autorMusica, retornaAutorMusica(musica));
            if(n == 0) {
                strcpy(vetor[0], autorMusica);
                n++;
            }else{
                igual = 0;
                for(int j = 0; j < n && igual == 0; j++){
                    if(!strcmp(autorMusica, vetor[j]))
                        igual = 1;
                }

                if(igual == 0) {
                    strcpy(vetor[n], autorMusica);
                    n++;
                }
            }
            i++;
            musica = retornaMusica(celula->playlist, i);
        }
        celula = celula->prox;
    }

    for(int k = 0; k < n; k++) {
        strcat(vetor[k],txt);
        playlistTmp = inicPlaylist(vetor[k]);
        inserePlaylistLista(listaPlay, playlistTmp);
    }

    
    celula = pessoa->listaPlaylists->prim;
    while(celula != NULL) {
        i = 0;
        musica = retornaMusica(celula->playlist, i);
                
        while(musica != NULL) {
            insereMusicaPorNome(listaPlay, retornaAutorMusica(musica), musica);

            i++;
            musica = retornaMusica(celula->playlist, i);
        }
    
        celula = celula->prox;
    }

    destroiListaPlaylists(pessoa->listaPlaylists);
    pessoa->listaPlaylists = listaPlay;
    

    fprintf(playedRefatorada, "%s;%d;", pessoa->nome, n);
    for(int k = 0; k < n; k++){
        fprintf(playedRefatorada,"%s", vetor[k]);
        if(k == n - 1){
            fprintf(playedRefatorada, "\n");
        }else{
            fprintf(playedRefatorada, ";");
        }
    }

    fclose(playedRefatorada);
}

int similaridades(Pessoa* pessoa1, Pessoa* pessoa2) {
    int count = 0, i = 0, j = 0;

    CelulaPlay* celula1 = pessoa1->listaPlaylists->prim;
    CelulaPlay* celula2 = pessoa2->listaPlaylists->prim;

    Musica* musica1;
    Musica* musica2;

    char nome1[20];
    char nome2[20];
    char nomeMusica1[50]; 
    char nomeMusica2[50];

    while(celula1 != NULL) {

        celula2 = pessoa2->listaPlaylists->prim;

        while(celula2 != NULL) {
            strcpy(nome1,retornaNomePlaylist(celula1->playlist));
            strcpy(nome2,retornaNomePlaylist(celula2->playlist));
            if(!strcmp(nome1, nome2)) {
                i = 0;
                musica1 = retornaMusica(celula1->playlist, i);
                musica2 = retornaMusica(celula2->playlist, i);

                while(musica1 != NULL) {
                    j = 0;
                    while(musica2 != NULL) {
                        strcpy(nomeMusica1, retornaNomeMusica(musica1));
                        strcpy(nomeMusica2, retornaNomeMusica(musica2));

                        if(!strcmp(nomeMusica1, nomeMusica2)){
                            count++;
                        }

                        j++;
                        musica2 = retornaMusica(celula2->playlist, j);
                    }
                    
                    i++;
                    musica1 = retornaMusica(celula1->playlist, i);                    
                }

            }
            celula2 = celula2->prox;
        }
        
        celula1 = celula1->prox;
    }
    return count;
}

void imprimePlaylistsArquivo(Pessoa* pessoa) {
    CelulaPlay* cel = pessoa->listaPlaylists->prim;
    char pastaPessoa[50] = "";
    char nomePlaylist[60] = "";

    sprintf(pastaPessoa, "./Saida/%s", retornaNomePessoa(pessoa));
    mkdir(pastaPessoa, 0777);    

    while(cel != NULL){
        char diretorio[100] = "";
        sprintf(diretorio,"%s/%s", pastaPessoa,retornaNomePlaylist(cel->playlist));

        FILE* saida = fopen(diretorio, "a");

        int i = 0;
        Musica* musica = retornaMusica(cel->playlist, i);

        while(musica != NULL) {
            fprintf(saida, "%s - %s\n", retornaAutorMusica(musica), retornaNomeMusica(musica));

            i++;
            musica = retornaMusica(cel->playlist, i);
        }

        cel = cel->prox;
        fclose(saida);
    }
    
}

void imprimeNomePessoa(Pessoa* pessoa){
    printf("%s\n", pessoa->nome);
}

void imprimeAmigosPessoa(Pessoa* pessoa){
    CelulaAmigo* p = pessoa->listaAmigos->prim;

    while(p != NULL){
        printf("%s\t", p->amigo);
        p = p->prox;
    }
    
    printf("\n");
}

void imprimePlaylistsPessoa(Pessoa* pessoa) {
    CelulaPlay* p = pessoa->listaPlaylists->prim;
    if(p == NULL){
        printf("Pessoa nao possui playlists.\n");
        return;
    }  

    while(p != NULL){
        printf("%s:\n", retornaNomePlaylist(p->playlist));
        imprimePlaylist(p->playlist);
        putchar('\n');
        p = p->prox;
    }

    printf("\n");
}

void imprimePessoa(Pessoa* pessoa) {
    printf("Nome: ");
    imprimeNomePessoa(pessoa);

    printf("Amigos: ");
    imprimeAmigosPessoa(pessoa);

    printf("Playlists:\n");
    imprimePlaylistsPessoa(pessoa);

}

void destroiListaPlaylists(ListaPlaylists* listaPlaylists) {
    CelulaPlay* q = listaPlaylists->prim;
    CelulaPlay* temp;
    
    while(q != NULL){
        temp = q->prox;
        destroiPlaylist(q->playlist);
        free(q);
        q = temp;
    }

    free(listaPlaylists);
}

void destroiListaAmigos(ListaAmigos* listaAmigos) {
    CelulaAmigo* p = listaAmigos->prim;
    CelulaAmigo* temp;
    
    while(p != NULL){
        temp = p->prox;
        free(p);
        p = temp;
    }

    free(listaAmigos);
}

void destroiPessoa(Pessoa* pessoa) {
    
    destroiListaAmigos(pessoa->listaAmigos);
    destroiListaPlaylists(pessoa->listaPlaylists);

    free(pessoa->nome);
    free(pessoa);
}