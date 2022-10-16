/*Mateus Ticianeli Sartorio
 *Yuri Aikau de Castro Reis Sanchez
*/

#include <stdio.h>
#include "listaPessoas.h"

int main() {

    ListaPessoa* listaPessoa = leArquivos();

    refatoradaLista(listaPessoa);

    imprimeListaPessoa(listaPessoa);

    similaridadesLista(listaPessoa);

    imprimePlaylistsArquivoLista(listaPessoa);

    destroiListaPessoa(listaPessoa);
    
    return 0;
}