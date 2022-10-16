/*Mateus Ticianeli Sartorio
 *Yuri Aikau de Castro Reis Sanchez
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include "musica.h"


//Tipo Celula (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct celulaMusica_st Celula;


//Tipo Playlist (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct playlist_st Playlist;


/*Inicializa playlist de musicas
 * inputs: o nome da playlist
 * output: ponteiro para a playlist inicializada
 * pre-condicao: haver espaço de memoria sufuciente para a alocaçao da lista
 * pos-condicao: a playlist eh incializada e um ponteiro para ela eh retornado
*/
Playlist* inicPlaylist(char* nome);


/*Insere musica na ultima posicao da playlist
 * inputs: a musica a ser adicionada e a playlist na qual sera adicionada
 * output: nenhum
 * pre-condicao: as estruturas playlist e musica terem sido inicializadas corretamente
 * pos-condicao: a musica tera sido adicionada na ultima posicao da playlist
*/
void insereMusicaPlaylist(Playlist* playlist, Musica* musica);


/*Retorna o nome da plalist passada
 * inputs: a playlist que se deseja saber o nome
 * output: o nome da playlist
 * pre-condicao: a playlist passada deve existir e ter sido alocada apropriadamente
 * pos-condicao: o nome da playlist eh retornado e a playlist eh inalterada
*/
char* retornaNomePlaylist(Playlist* playlist);


/*Retorna um ponteiro para a estrutura Musica de acordo com um indice passado
 * inputs: ponteiro para playlist e um indice n
 * output: Ponteiro para a Musica na posiçao n
 * pre-condicao: a lista de playlist deve nao ser nula e o indice deve ser valido
 * pos-condicao: o ponteiro pra musica original nao foi alterado
*/
Musica* retornaMusica(Playlist* playlist, int n);


/*Le o arquivo de entrada como o nome da playlist e cria a playlist
 * inputs: o nome da playlist a ser criada
 * output: um ponteiro para a playlist criada eh retornada
 * pre-condicao: o nome do arquivo deve ser valido
 * pos-condicao: a playlist eh criada e seu endereco retornado
*/
Playlist* lePlaylist(char* nome);


/*Imprime todas as musicas de uma playlist
 * inputs: ponteiro para playlist
 * output: nenhum
 * pre-condicao: a playlist ter sido previamente alocada
 * pos-condicao: nenhuma
*/
void imprimePlaylist(Playlist* playlist);


/*Desaloca todas os campos de uma playlist
 * inputs: ponteiro para playlist
 * output: nenhum
 * pre-condicao: a playlist ter sido previamente alocada
 * pos-condicao: a memoria esta devidamente liberada
*/
void destroiPlaylist(Playlist* playlist);

#endif