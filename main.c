#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_DISCOS 20

//Compilar: gcc main.c -o ./main.out && ./main.out

typedef struct 
{
    int id;
    char titulo[100];
    char *artista;
    char album[100];
    char *genero;
    int duracion_seg;
    int anho;
    int n_reproducciones;
}
discos_;

void print_discos(discos_ discos[MAX_DISCOS]);
void generador_titulo(discos_ discos[MAX_DISCOS]);
void generador_id(discos_ disco[MAX_DISCOS]);
void generador_artista(discos_ discos[MAX_DISCOS]);
void generador_album(discos_ discos[MAX_DISCOS]);
void Exportacion(discos_ discos[MAX_DISCOS]);
int busqueda_binaria_recursiva(discos_ discos[], int busqueda, int izquierda, int derecha);
void ordenamiento_y_busqueda(discos_ discos[MAX_DISCOS]);

int main ()
{
    srand(time(NULL));

    discos_ discos[MAX_DISCOS];

    generador_id(discos);
    generador_titulo(discos);
    generador_artista(discos);
    generador_album(discos);

    print_discos(discos);
    ordenamiento_y_busqueda(discos);
    Exportacion(discos);

    return 0;
}
/**
 * @brief funcion hecho por Daniela, asigna valor de id en el arreglo MAX_DISCOS
 * 
 * @param discos 
 */

void generador_id(discos_ discos[MAX_DISCOS])
{
    discos[0].id = 1000;
    for (int i=1; i<MAX_DISCOS; i++){
        discos[i].id = discos[i-1].id + 1;
        //printf("num: %d y el id es: %d \n", i, discos[i].id);
    }
}

/**
 * @brief Funcion por Franco 
 * 
 * @param discos representa los discos a editar
 */
void generador_titulo(discos_ discos[MAX_DISCOS])
{
    char *adverbio[] = {"Aqui", "Pronto", "Jamas", "Acaso", "deprisa"};
    char *sustantivo[] = {"Pan", "Canada", "Edgardo", "Bordoli", "Torre"};
    char *adjetivo [] = {"sangriento", "estancado", "montanhista", "terrorista", "desgraciado"};

    int aux = 0, aux2 = 0, aux3 = 0;

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        aux = rand() % 5;
        aux2 = rand() % 5;
        aux3 = rand() % 5;

        snprintf(discos[i].titulo, sizeof(discos[i].titulo), "%s %s %s", adverbio[aux3], sustantivo[aux], adjetivo[aux2]);
    }
}

void generador_artista(discos_ discos[MAX_DISCOS])
{
    char *artista[] = {"Jere Klein", "Bad Bunny", "Cris MJ", "Kidd Voodoo", "Feid", "Karol G", "Lucky Brown", "Anuel AA", "Katteyes", "Blessd"};
    int aux = 0;

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        aux = rand() % 10;

        discos[i].artista = artista[aux];
    }
}

void generador_album(discos_ discos[MAX_DISCOS])
{
    char *sustantivo[] = {"Pan", "Canada", "Edgardo", "Bordoli", "Torre"};
    char *adjetivo [] = {"sangriento", "estancado", "montanhista", "terrorista", "desgraciado"};

    int aux = 0, aux2 = 0;

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        aux = rand() % 5;
        aux2 = rand() % 5;

        snprintf(discos[i].album, sizeof(discos[i].album), "%s %s", sustantivo[aux], adjetivo[aux2]);
    }
}

void print_discos(discos_ discos[MAX_DISCOS])
{
    printf("==================================================================================================== \n");
    printf("| %-5s | %-33s | %-15s | %-33s | \n","ID","TITULO","ARTISTA","ALBUM");
    printf("==================================================================================================== \n");

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        printf("| %-5d | %-33s | %-15s | %-33s | \n", discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album);
    }
}

/**
 * @brief Funcion realizado por benjamin Hernandez
 * 
 * @param discos 
 */
void ordenamiento_y_busqueda(discos_ discos[MAX_DISCOS])
{
    int seleccion, busca;
    printf("1- Busqueda por id\n");
    printf("2- Busqueda por Nombre\n");
    printf("3- Busqueda por Artista\n");
    scanf("%d",&seleccion);
    if(seleccion == 1) // menu busqueda por id, Los otros numeros son de ejemplo despues de max_discos
    {
        printf("Selecciona la id del Thema\n");
        scanf("%d",&busca);
        int busqueda =busqueda_binaria_recursiva(discos, busca, 0, MAX_DISCOS - 1);
        printf("\n\n| %-5d | %-33s | %-15s | \n", discos[busqueda].id, discos[busqueda].titulo, discos[busqueda].artista);
    }
}

/**
 * @brief Busqueda binaria realizado por benjamin Hernandez
 * 
 * @param discos 
 * @param busqueda 
 * @param izquierda 
 * @param derecha 
 * @return int 
 */
int busqueda_binaria_recursiva(discos_ discos[], int busqueda, int izquierda, int derecha)
{
    if (izquierda > derecha) 
    {
        return -1;
    }

    int indice_mitad = (izquierda + derecha) / 2;
    int Mitad = discos[indice_mitad].id;
    if(busqueda == Mitad)
    {   // Retorna el indice de la busqueda para la id 
        return indice_mitad;
    }
    if(busqueda < Mitad)
    {   // Busqueda de la direccion hacia izquierda
        derecha = indice_mitad - 1;
    }
    else
    {   // Busqueda de la direccion hacia la derecha
        izquierda = indice_mitad + 1;
    }
    return busqueda_binaria_recursiva(discos, busqueda, izquierda, derecha);
}

/**
 * @brief Funcion exportacion de datos csv Realizado  por Benjamin  Hernandez
 * 
 * @param discos 
 */
void Exportacion(discos_ discos[MAX_DISCOS])
{
    FILE *archivo_csv = fopen("CSV/Catalogo.csv", "w");
    if (archivo_csv == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    for (int i = 0; i < MAX_DISCOS; i++)
    {
        fprintf(archivo_csv, "%d,%s,%s\n", discos[i].id, discos[i].titulo, discos[i].artista);
    }
    printf("Datos guardados correctamente\n");

    fclose(archivo_csv);
}