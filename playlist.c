#include <stdlib.h>
#include <string.h>
#include "playlist.h"

struct celulaMusica_st {
    Musica* musica;
    Celula* prox;
};

struct playlist_st{
    char* nome;
    Celula* prim;
    Celula* ult;
};

Playlist* inicPlaylist(char* nome){
    Playlist* playlist = (Playlist*) malloc(sizeof(Playlist));

    playlist->nome = strdup(nome);
    playlist->prim = NULL;
    playlist->ult = NULL;

    return playlist;
}

void insereMusicaPlaylist(Playlist* playlist, Musica* musica){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->musica = musica;
    nova->prox = NULL;

    if(playlist->prim == NULL){
        playlist->prim = nova;
        playlist->ult = nova;
        return;
    }
    
    playlist->ult->prox = nova;
    playlist->ult = nova;
}

char* retornaNomePlaylist(Playlist* playlist) {
    return playlist->nome;
}

Musica* retornaMusica(Playlist* playlist, int n) {
    Celula* nova = playlist->prim;
    for(int i = 0; i < n; i++) {
        nova = nova->prox;
        if(nova == NULL){
            return NULL;
        }
    }
    return nova->musica;
}

Playlist* lePlaylist(char* nome) {
    char diretorio[35] = "./Entrada/";
    strcat(diretorio,nome);

    FILE* playlistxt;
    playlistxt = fopen(diretorio,"r");
    if (playlistxt == NULL){
        printf("Erro na abertura do arquivo - lePlaylist()\n");
        exit(1);
    }

    Playlist* playlist = inicPlaylist(nome);

    while(!feof(playlistxt)){
        char autor[50];
        char nomeMusica[100];
        fscanf(playlistxt, "%[^-] - %[^\n]\n", autor, nomeMusica);

        autor[strlen(autor)-1] = '\0';
        Musica* musica = inicMusica(autor, nomeMusica);

        insereMusicaPlaylist(playlist, musica);
    }
  
    fclose(playlistxt);
    
    return playlist;
}

void imprimePlaylist(Playlist* playlist) {
    Celula* p = playlist->prim;

    while(p != NULL){
        imprimeMusica(p->musica);
        
        p = p->prox;
    }
}

void destroiPlaylist(Playlist* playlist){
    Celula* p = playlist->prim;
    Celula* temp;

    while(p != NULL){
        temp = p->prox;
        destroiMusica(p->musica);
        free(p);
        p = temp;
    }
    free(playlist->nome);
    free(playlist);
}