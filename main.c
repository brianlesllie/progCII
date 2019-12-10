/*
 ============================================================================
 Name        : grafos.c
 Author      :
 Version     :
 Copyright   : Renan Augusto Starke, todos os direitos reservados
 Description : grafos com lista encadeadas, Ansi-style
             : estruturas disponiveis:
             : pilha e fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "fila.h"
#include "grafo.h"

int main(void) {

	grafo_t *grafo;
	vertice_t* vertice;

	fila_t *fila;
	int id;

	grafo = cria_grafo(0);
	fila = cria_fila();

	//Adiciona todos os vertices no grafo
	vertice = grafo_adicionar_vertice(grafo, 1);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 2);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 3);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 4);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 5);
	enqueue(vertice, fila);

/*	vertice = grafo_adicionar_vertice(grafo, 6);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,7);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,8);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,9);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,10);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,11);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,12);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,13);
	enqueue(vertice, fila);

*/

        // constrói grafo
	while (!fila_vazia(fila))	{
		vertice = dequeue(fila);
		id = vertice_get_id(vertice);

		switch(id){
			case 1:
				adiciona_adjacentes(grafo, vertice, 4, 2, 1, 3, 1);
				break;
			case 2:
				adiciona_adjacentes(grafo, vertice, 6, 1, 1, 3, 1, 4, 1);
				break;
			case 3:
				adiciona_adjacentes(grafo, vertice, 6, 1, 1, 2, 1, 5, 1);
				break;
			case 4:
				adiciona_adjacentes(grafo, vertice, 2, 2, 1);
				break;
			case 5:
				adiciona_adjacentes(grafo, vertice, 2, 3, 1);
				break;
/*			case 6:
				adiciona_adjacentes(grafo, vertice, 6, 1, 14, 3, 2, 5, 9);
				break;
			case 7:
				adiciona_adjacentes(grafo, vertice, 2, 8, 9);
				break;
			case 8:
				adiciona_adjacentes(grafo, vertice, 4, 7, 9, 9, 4);
				break;
			case 9:
				adiciona_adjacentes(grafo, vertice, 2, 8, 4);
				break;
			case 10:
				adiciona_adjacentes(grafo, vertice, 4, 11, 1, 12, 8);
				break;
			case 11:
				adiciona_adjacentes(grafo, vertice, 4, 10, 1, 12, 4);
				break;
			case 12:
				adiciona_adjacentes(grafo, vertice, 4, 11, 4, 10, 8);
				break;
			default:
				break;*/
		}
	}
	printf("\n\\--------\\\n");
	printf("\n\\--------\\\n");
    /*bfs(grafo,procura_vertice(grafo,4));
    dfs(grafo,procura_vertice(grafo,1));*/
    printf("TeM: %d",tem_ciclo(grafo));
    int idd;
    int idpai;
    while(1){
        scanf("%d",&idd);
        if(idd==0)
            break;
        vertice_t *v=procura_vertice(grafo, idd);
        for(;v!=NULL;v=vertice_get_pai(v)){
            if(vertice_get_pai(v)!=NULL)
                idpai=vertice_get_id(vertice_get_pai(v));
            else
                idpai=0;
            printf("\\--------\\\nId:\t%d\nDist:\t%d\nPai:\t%d\nVisit:\t%d\n\\--------\\\n", vertice_get_id(v),vertice_get_grupo(v),idpai,vertice_get_visit(v));
        }
    }
	exportar_grafo_dot("grafo.dot", grafo);
	libera_fila(fila);
	libera_grafo(grafo);

	return EXIT_SUCCESS;
}

