#include <stdlib.h>
#include <string.h>

#include "musica.h"

struct musica_st{
    char* autor;
    char* nome;
};

Musica* inicMusica(char* autor, char* nome){
    Musica* musica = (Musica*)malloc(sizeof(Musica));

    musica->autor = strdup(autor);
    musica->nome = strdup(nome);

    return musica;
}

Musica* copiaMusica(Musica* sample) {
    Musica* copia = inicMusica(sample->autor, sample->nome);

    return copia;
}

char* retornaAutorMusica(Musica* musica){
    if(musica == NULL)
        return NULL;

    return musica->autor;
}

char* retornaNomeMusica(Musica* musica) {
    if(musica == NULL)
        return NULL;

    return musica->nome;
}

void imprimeMusica(Musica* musica){
    printf("%s - %s\n", retornaAutorMusica(musica), retornaNomeMusica(musica));
}

void destroiMusica(Musica* musica) {
    free(musica->autor);
    free(musica->nome);
    free(musica);
}