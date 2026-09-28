/**
 * @file commons.h
 * @author Benjamin Hernndez 
 * @brief Archivo encabezado para la estructura 
 * @date 2026-09-27
 * 
 * 
 */

#ifndef COMMONS
#define COMMONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_DISCOS 20
#define MAX_FILA 20


/**
 * @brief Estructura que define disco
 * 
 */
typedef struct 
{
    int id; /** ID de la musica */
    char *titulo; /** titulo de la musica */
    char *artista; /** artisata de la musica  */
    char *album; /** Nombre del abul */
    char *genero; /** Nombre del genero */
    int duracion_seg; /** Duracion de la musica */
    int anho; /** Ano de lanzamiento de la musica */
    int n_reproducciones;  /** Numero de producciones de la musica */
}discos_;


void print_discos(discos_ discos[MAX_DISCOS], int n_discos);
void generador_titulo(discos_ discos[MAX_DISCOS], int n_discos);
void init_discos(discos_ discos[MAX_DISCOS]);
void generador_id(discos_ disco[MAX_DISCOS], int n_discos);
void generador_artista(discos_ discos[MAX_DISCOS], int n_discos);
void generador_album(discos_ discos[MAX_DISCOS], int n_discos);
void generador_genero(discos_ discos[MAX_DISCOS], int n_discos);
void generador_duracion_seg(discos_ discos[MAX_DISCOS], int n_discos);
void generador_anho(discos_ discos[MAX_DISCOS], int n_discos);
void generador_n_reproducciones(discos_ discos[MAX_DISCOS], int n_discos);
void Exportacion(discos_ discos[MAX_DISCOS], int n_discos);
int busqueda_binaria_recursiva(discos_ discos[], int busqueda, int izquierda, int derecha);
void buscar_artista(discos_ disco[], int n_discos);
void ordenar_discos_por_id(discos_ discos[MAX_DISCOS], int n_discos);
void menu(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos);
void buscar_nombre(discos_ discos[], int n_discos);
void fisher_yates(discos_ discos[MAX_DISCOS], int n_discos);
void listar_artistas_disponibles(discos_ discos[MAX_DISCOS]);
void buscar_por_genero(discos_ discos[MAX_DISCOS], int n_disco);
void liberar_memoria(discos_ discos[MAX_DISCOS]);
void consultar_fila_re(discos_ fila_re[MAX_FILA], int n_fila);
void anhadir_fila_re(discos_ fila_re[MAX_FILA], discos_ discos[MAX_DISCOS], int *n_fila, int n_discos);
void quitar_fila_re(discos_ fila_re[MAX_FILA], int *n_fila);
void vaciar_fila_re(int *n_fila);
void menu_fila_re(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos);
void buscar_id(discos_ discos[MAX_DISCOS], int n_discos);
void reproducir_musica(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos);
void historial_musica(discos_ discos[MAX_DISCOS], int n_discos);


#endif