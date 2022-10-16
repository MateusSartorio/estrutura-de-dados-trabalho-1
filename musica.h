/*Mateus Ticianeli Sartorio
 *Yuri Aikau de Castro Reis Sanchez
*/

#ifndef MUSICA_H
#define MUSICA_H

#include <stdio.h>

//Tipo Musica (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct musica_st Musica;


/*Aloca memoria para a musica e inicializa  seus campos
 * inputs: o nome do autor e o nome da musica
 * output: um ponteiro para a estrutura Musica inicializada
 * pre-condicao: as strings autor e nome existirem
 * pos-condicao: a estrutura musica foi criada, seus campos foram inicializados, e seu endereco eh retornado
*/
Musica* inicMusica(char* autor, char* nome);


/*Aloca e retorna o endereco de uma copia da musica passada
 * inputs: o nome do autor e o nome da musica
 * output: um ponteiro para a estrutura Musica inicializada
 * pre-condicao: a musica nao ser NULA
 * pos-condicao: bloco de memoria da copia da musica alocado e atribuido os mesmos valores que o original
*/
Musica* copiaMusica(Musica* sample);


/*Retorna o nome do autor ou da banda que compos a musica
 * inputs: o endereco da estrutura do tipo Musica que se deseja saber o nome do autor ou da banda
 * output: o nome do autor ou da banda da musica
 * pre-condicao: a lista deve existir e ter sido inicializada corretamente
 * pos-condicao: o nome do autor da musica eh retornado e a musica nao eh alterada
*/
char* retornaAutorMusica(Musica* musica);


/*Retorna o nome da musica
 * inputs: o endereco da estrutura do tipo Musica que se deseja saber o nome
 * output: o nome da musica
 * pre-condicao: a lista deve existir e ter sido inicializada corretamente
 * pos-condicao: o nome da musica eh retornado e a musica nao eh alterada
*/
char* retornaNomeMusica(Musica* musica);


/*Imprime o banda/autor da musica
 * inputs: o endereco da musica a ser impressa
 * output: nenhum
 * pre-condicao: a musica deve existir e ter sido inicializada corretamente
 * pos-condicao: a musica eh impressa
*/
void imprimeMusica(Musica* musica);


/*Desaloca a estrutura Musica passada como paramentro
 * inputs: o endereco da lista a ser desalocada
 * output: nenhum
 * pre-condicao: a musica deve existir e ter sido inicializada corretamente
 * pos-condicao: a estrutura Musica passada eh desalocada
*/
void destroiMusica(Musica* musica);


#endif