/*Mateus Ticianeli Sartorio
 *Yuri Aikau de Castro Reis Sanchez 
*/

#ifndef LISTAPESSOAS_H
#define LISTAPESSOAS_H

#include <stdio.h>
#include "pessoas.h"


//Tipo CelulaListaPessoa (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct celulaListaPessoa_st CelulaListaPessoa;


//Tipo ListaPessoa (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct listaPessoa_st ListaPessoa;


/*Inicializa uma lista de pessoas
 * inputs: nenhum
 * output: o endereco da lista de pessoas incializada
 * pre-condicao: nenhum
 * pos-condicao: a lista de pessoas eh inicializada e seu endereco eh retornado
*/
ListaPessoa* inicListaPessoa();


/*Insere uma pessoa numa lista de pessoas
 * inputs: um ponteiro para lista de pessoas e um ponteiro para a pessoa a ser adicionada
 * output: nenhum
 * pre-condicao: a lista de pessoas e a pessoa devem existir e ter sido alocada corretamente
 * pos-condicao: a pessoa foi devidamente encadeada na lista
*/
void inserePessoaLista(ListaPessoa* listaPessoa, Pessoa* pessoa);


/*Retorna uma pessoa de uma lista de pessoas cujo nome eh igual ao nome passado
 * inputs: uma lista de pessoas e o nome da pessoa a ser retornada
 * output: a pessoa da lista de pessoas cujo nome eh igual ao nome passado
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada corretamente e deve existir uma pessoa na lista com o nome informado
 * pos-condicao: a pessoa da lista de pessoas cujo nome eh igual ao nome passado eh retornada
*/
Pessoa* retornaPessoa(ListaPessoa* listaPessoa, char* nome);


/*Le todos os arquivos de entrada para o funcionamento do programa
 * inputs: nenhum
 * output: ponteiro para a Lista de Pessoas
 * pre-condicao: os arquivos de entrada devem estar devidamente inseridos no endereço ./Entrada/nomedoarquivo.txt
 * pos-condicao: todas as informaçoes foram usadas para a criaçao da estrutura e ela foi devidamente preenchida
*/
ListaPessoa* leArquivos();


/*Imprime o nome, as playlists e a lista de amigos de todas as pessoas da lista de pessoas passada
 * inputs: a lista de pessoas que se deseja imprimir
 * output: nenhum
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada adequadamente
 * pos-condicao: a lista de pessoas eh impressa e nao eh modificada
*/
void imprimeListaPessoa(ListaPessoa* listaPessoa);


/*Aplica a fuçao refatorada()[pessoas.h] para todas as pessoas da lista de pessoas
 * inputs: um ponteiro para lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada corretamente
 * pos-condicao: todas as pessoas da lista tiveram suas playlists alteradas para as condiçoes estabelecidas pela funçao refatorada()[pessoas.h]
*/
void refatoradaLista(ListaPessoa* listaPessoa);


/*Imprime em arquivo a quantidade de musicas iguais de cada par de amigos da lista de pessoas passada
 * inputs: a lista de pessoas que se deseja imprimir
 * output: nenhum
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada adequadamente
 * pos-condicao: a quantidade de musicas iguais de cada par de amigos eh impresso em arquivos
*/
void similaridadesLista(ListaPessoa* listaPessoa);


/*Imprime as playlists em seus diretorios de acordo com a funçao imprimePlaylistsArquivo()[pessoas.h]
 * inputs: um ponteiro para lista de pessoas
 * output: nenhum
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada corretamente
 * pos-condicao: todos as playlists foram impressa em seus respectivos arquivos
*/
void imprimePlaylistsArquivoLista(ListaPessoa* listaPessoa);


/*Destroi a lista de pessoas e cada pessoa contida na lista
 * inputs: a lista de pessoas que se deseja destruir
 * output: nenhum
 * pre-condicao: a lista de pessoas deve existir e ter sido alocada adequadamente
 * pos-condicao: a lista de pessoas eh destruida
*/
void destroiListaPessoa(ListaPessoa* listaPessoa);

#endif