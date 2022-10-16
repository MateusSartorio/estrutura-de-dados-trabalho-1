/*Mateus Ticianeli Sartorio
 *Yuri Aikau de Castro Reis Sanchez
*/

#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdio.h>
#include "playlist.h"

//Tipo Pessoa (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct pessoa_st Pessoa;


//Tipo CelulaPlay (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct celulaPlaylist_st CelulaPlay;


//Tipo ListaPlaylists (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct listaPlaylists_st ListaPlaylists;


//Tipo CelulaAmigo (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct celulaAmigo_st CelulaAmigo;


//Tipo ListaAmigos (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct listaAmigos_st ListaAmigos;


/*Inicializa uma estrutura de pessoa dado um nome como parametro
 * inputs: o nome da pessoa a ser criada
 * output: um ponteiro para a pessoa criada eh retornada
 * pre-condicao: o nome passado como parametro deve ser valido
 * pos-condicao: a pessoa eh criada e seu endereco retornado
*/
Pessoa* inicPessoa(char* nome);


/*Le os arquivos de entrada, inicializa a lista de amigos e atribui os valores adequadamente
 * inputs: nenhum
 * output: um ponteiro para a lista de pessoas inicializada
 * pre-condicao: os arquivos de entrada devem existir
 * pos-condicao: a lista de pessoas eh criada e seu endereco eh retornado
*/
ListaAmigos* inicListaAmigos();


/*Le o arquivo de entrada como o nome da playlist e cria a playlist
 * inputs: o nome da playlist a ser criada
 * output: um ponteiro para a playlist criada eh retornada
 * pre-condicao: o nome do arquivo deve ser valido
 * pos-condicao: a playlist eh criada e seu endereco retornado
*/
ListaPlaylists* inicListaPlaylists();


/*Insere o nome de um amigo numa lista de nomes de amigos na estrutura Pessoa de forma reciproca
 * inputs: 2 ponteiros para a estrutura de Pessoa de 2 amigos
 * output: nenhum
 * pre-condicao: os 2 ponteiros de Pessoa devem ser validos
 * pos-condicao: os 2 amigos se tem em suas listas de amigos
*/
void insereAmigoPessoa(Pessoa* pessoa, Pessoa* amigo);


/*Insere uma playlist na lista de playlists da pessoa passada
 * inputs: a pessoa e a playlist a ser adicionada
 * output: nenhum
 * pre-condicao: a pessoa e a playlist devem existir e terem sido alocadas adequadamente
 * pos-condicao: a playlist eh adicionada a lista de playlists da pessoa
*/
void inserePlaylistPessoa(Pessoa* pessoa, Playlist* playlist);


/*Insere uma playlist na lista de playlists passada
 * inputs: a lista de playlists e a playlist a ser adicionada
 * output: nenhum
 * pre-condicao: a lista de playlists e a playlist devem existir e terem sido alocadas adequadamente
 * pos-condicao: a playlist eh adicionada a lista de playlists
*/
void inserePlaylistLista(ListaPlaylists* listaPlaylists, Playlist* playlist);


/*Insere uma musica em uma playlist da lista de playlists cujo nome seja igual a string passada, 
 * inputs: uma lista de playlists, um nome de playlist e a musica a ser inserida
 * output: nenhum
 * pre-condicao: a lista de playlists e a musica devem existir e terem sido alocadas adequadamente, alem disso, deve haver uma playlist na lista de playlists com o nome passado
 * pos-condicao: a musica eh inserida na playlist correta da lista de playlists
*/
void insereMusicaPorNome(ListaPlaylists* listaPlaylist, char* nomePlaylist, Musica* musica);


/*Retorna o nome de uma pessoa contido na estrutura Pessoa
 * inputs: o ponteiro Pessoa da pessoa em questao
 * output: retorna o nome da pessoa
 * pre-condicao: o ponteiro para Pessoa existir
 * pos-condicao: nenhuma
*/
char* retornaNomePessoa(Pessoa* pessoa);


/*Refatora as playlists atuais, de modo a reorganizar as playlists por nome de autor/banda
 * inputs: um ponteiro para uma estrutura de Pessoa
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada adequadamente
 * pos-condicao: a lista de playlists dentro da estrutura de pessoa agora contem o nome das playlists por autor/banda
*/
void refatorada(Pessoa* pessoa);


/*Retorna a quantidade de musicas em comum que duas pessoas tem
 * inputs: duas pessoas
 * output: o numero de similaridades entre as duas pessoas
 * pre-condicao: as duas pessoas existirem e terem sido alocadas corretamente
 * pos-condicao: a quantidade de musicas em comum das duas pessoas eh retornada e as duas pessoas nao sao alteradas
*/
int similaridades(Pessoa* pessoa1, Pessoa* pessoa2);


/*Imprime as playlists de uma pessoa em arquivo
 * inputs: a pessoas cujas playlists devem ser impressas
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: todas as playlits da pessoa sao impressas em arquivo
*/
void imprimePlaylistsArquivo(Pessoa* pessoa);


/*Imprime o nome da pessoa contido na estrutura Pessoa
 * inputs: um ponteiro para Pessoa
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: o nome da pessoa foi impresso na saida padrao
*/
void imprimeNomePessoa(Pessoa* pessoa);


/*Imprime os amigos de uma pessoa
 * inputs: a pessoas cujos amigos devem ser impressos
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: todas os amigos da pessoa sao impressos
*/
void imprimeAmigosPessoa(Pessoa* pessoa);


/*Imprime as playlists de uma pessoa
 * inputs: a pessoas cujas playlists devem ser impressas
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: todas as playlits da pessoa sao impressas
*/
void imprimePlaylistsPessoa(Pessoa* pessoa);


/*Imprime todos os amigos de uma pessoa e todas suas playlits
 * inputs: a pessoas que se deseja imprimir
 * output: nenhum
 * pre-condicao: a pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: o nome da pessoa, todos os seus amigos e playlits sao impressos
*/
void imprimePessoa(Pessoa* pessoa);


/*Libera a memoria das playlists encadeadas numa lista de playlists
 * inputs: um ponteiro para lista de playlists
 * output: nenhum
 * pre-condicao: a lista de playlist deve existir e ter sido alocada corretamente
 * pos-condicao: todos os endereços de memoria foram liberados, tanto da lista como das playlists contidas nela
*/
void destroiListaPlaylists(ListaPlaylists* listaPlaylists);


/*Desaloca a memoria de uma lista de amigos
 * inputs: a lista de amigos a ser desalocada
 * output: nenhum
 * pre-condicao: a lista de amigos deve existir e ter sido alocada corretamente
 * pos-condicao: a lista de amigos eh desalocada
*/
void destroiListaAmigos(ListaAmigos* listaAmigos);


/*Libera todos os espaços de memoria alocados devido a estrutura de Pessoa
 * inputs: um ponteiro para a estrutura Pessoa
 * output: nenhum
 * pre-condicao: a Pessoa deve existir e ter sido alocada corretamente
 * pos-condicao: todos os endereços de memoria alocados devido a estrutura Pessoa foram liberados
*/
void destroiPessoa(Pessoa* pessoa);

#endif