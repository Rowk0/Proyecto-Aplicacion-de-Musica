/**
 * @file funciones.c
 * @author Benjamin Hernndez
 * @brief aqui no se que poner
 * @date 2026-09-27
 * 
 */
#include "commons.h"


void listar_artistas_disponibles(discos_ discos[MAX_DISCOS])
{
    char *artistas_disponible[MAX_DISCOS];
    int seEncontró = 0;
    int j = 0;

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        seEncontró = 0;

        if (discos[i].artista != NULL) 
        {   
            for (int k = 0; k < j; k++)
            {
                if (strcmp(artistas_disponible[k], discos[i].artista) == 0)
                {
                    seEncontró = 1;
                    break;
                }
            }

            if (seEncontró == 0)
            {
                artistas_disponible[j] = discos[i].artista;
                j++;
            }
        }   
    }

    ///////////////////////////////////////////////////////////

    printf("==================================\n");
    printf("| %-30s |\n", "ARTISTAS DISPONIBLES"); 
    printf("================================== \n");

    for (int i = 0; i < j; i++)
    {
        printf("| %-30s |\n", artistas_disponible[i]); 
    }
    printf("================================== \n\n");
}

void init_discos(discos_ discos[MAX_DISCOS])
{
    for (int i = 0; i < MAX_DISCOS; i++)
    {
        discos[i].id = 0;
        discos[i].titulo = NULL;
        discos[i].artista = NULL;
        discos[i].album = NULL;
        discos[i].genero = NULL;
        discos[i].duracion_seg = 0;
        discos[i].anho = 0;
        discos[i].n_reproducciones = 0;
    }
}

/**
 * @brief funcion hecho por Daniela, asigna valor de id en el arreglo MAX_DISCOS
 * 
 * @param discos 
 */

void generador_id(discos_ discos[MAX_DISCOS], int n_discos)
{
    discos[0].id = 1000;
    for (int i=1; i< n_discos; i++){
        discos[i].id = discos[i-1].id + 1;
        //printf("num: %d y el id es: %d \n", i, discos[i].id);
    }
}

/**
 * @brief Funcion por Franco 
 * 
 * @param discos representa los discos a editar
 */
void generador_titulo(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *adverbio[] = {"Aqui", "Pronto", "Jamas", "Acaso", "deprisa"};
    char *sustantivo[] = {"Pan", "Canada", "Edgardo", "Bordoli", "Torre"};
    char *adjetivo [] = {"sangriento", "estancado", "montanhista", "terrorista", "desgraciado"};

    int aux = 0, aux2 = 0, aux3 = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 5;
        aux2 = rand() % 5;
        aux3 = rand() % 5;

        //Recuerdenme que debo liberar la memoria porque aun no lo hago
        discos[i].titulo = malloc(100 * sizeof(char));

        snprintf(discos[i].titulo, 100, "%s %s %s", adverbio[aux3], sustantivo[aux], adjetivo[aux2]);
    }
}

void generador_artista(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *artista[] = {"Jere Klein", "Bad Bunny", "Cris MJ", "Kidd Voodoo", "Feid", "Karol G", "Lucky Brown", "Anuel AA", "Katteyes", "Blessd"};
    int aux = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 10;

        discos[i].artista = artista[aux];
    }
}

void generador_album(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *sustantivo[] = {"Pan", "Canada", "Edgardo", "Bordoli", "Torre"};
    char *adjetivo [] = {"sangriento", "estancado", "montanhista", "terrorista", "desgraciado"};

    int aux = 0, aux2 = 0, aux_bin = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 5;
        aux2 = rand() % 5;
        aux_bin = rand() % 2;

        discos[i].album = malloc(100 * sizeof(char));

        if (aux_bin == 1)
        {
            snprintf(discos[i].album, 100, "%s %s", sustantivo[aux], adjetivo[aux2]);
        }
        else
        {
            snprintf(discos[i].album, 100, "Sencillo");
        }
        
    }
}

void generador_genero(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *genero[] = {"Pop", "Electronica", "Jazz", "Country", "Hyper Pop", "Dubstep", "DnB", "Indie Rock", "Soundtrack", "Musica clasica"};
    int aux = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 10;

        discos[i].genero = genero[aux];
    }
}

void generador_duracion_seg(discos_ discos[MAX_DISCOS], int n_discos)
{
    int num = 0;

    for (int i = 0; i < n_discos; i++)
    {
        num = 180 + rand() % (300 - 180 + 1);

        discos[i].duracion_seg = num;
    }
}

void generador_anho(discos_ discos[MAX_DISCOS], int n_discos)
{
    int anho = 0;

    for (int i = 0; i < n_discos; i++)
    {
        anho = 1900 + rand() % (2026 - 1900 + 1);

        discos[i].anho = anho;
    }
}

void generador_n_reproducciones(discos_ discos[MAX_DISCOS], int n_discos)
{
    int n_reproducciones = 0;

    for (int i = 0; i < n_discos; i++)
    {
        n_reproducciones = 5000 + rand() % (10000 - 5000 + 1);

        discos[i].n_reproducciones = n_reproducciones;
    }
}

void fisher_yates(discos_ discos[MAX_DISCOS], int n_discos)
{
    int j = 0;
    for (int i = n_discos - 1; i > 0; i--){
        j = rand() % (i + 1);

        discos_ temp = discos[i];
        discos[i] = discos[j];
        discos[j] = temp;
    }
}

void print_discos(discos_ discos[MAX_DISCOS], int n_discos)
{
    printf("====================================================================================================================================================\n");
    printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_REPRODUCCIONES");
    printf("==================================================================================================================================================== \n");

    for (int i = 0; i < n_discos; i++)
    {
        printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d | \n", 
            discos[i].id, 
            discos[i].titulo, 
            discos[i].artista, 
            discos[i].album, 
            discos[i].genero, 
            discos[i].duracion_seg,
            discos[i].anho,
            discos[i].n_reproducciones);
    }
    printf("====================================================================================================================================================\n\n");
}





/**
 * @brief Fucion echo por benjamin hernandez 
 * 
 * @param discos 
 * @param n_discos 
 */
void ordenar_discos_por_id(discos_ discos[MAX_DISCOS], int n_discos) {
    int swapped;
    for (int i = 0; i < n_discos - 1; i++) 
    {
        swapped = 0;
        for (int j = 0; j < n_discos - i - 1; j++) 
        {
            if (discos[j].id > discos[j + 1].id) // Ordenamiento de menor a mayor por ID
            {
                discos_ temp = discos[j];
                discos[j] = discos[j + 1];
                discos[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) 
        {
            break;
        }
    }
}


/**
 * @brief Funcion realizado por benjamin Hernandez
 * 
 * @param discos 
 */
void menu(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos)
{
    int seleccion = -1; /** menu de busqueda  */

    while (seleccion != 0)
    {
        printf("\n");
        printf("==================================\n");
        printf("|Busqueda de canciones           |\n");
        printf("==================================\n");
        printf("| 0- Salir del programa          |\n");
        printf("| 1- Busqueda por id             |\n");
        printf("| 2- Busqueda por Nombre         |\n");
        printf("| 3- Busqueda por Artista        |\n");
        printf("| 4- Busqueda por Genero Musical |\n");
        printf("| 5- Fila de reproduccion        |\n");
        printf("| 6- historial de reproduccion   |\n");
        printf("| 7- Reproducir musica           |\n");
        printf("==================================\n\n");
        if(scanf("%d",&seleccion) != 1)
        {
            return;
        }

        else if(seleccion == 1) 
        {
            buscar_id(discos, n_discos);
        }
        else if(seleccion == 2)
        {
            buscar_nombre(discos, n_discos);
        } 
        else if(seleccion == 3)
        {
            buscar_artista(discos, n_discos);
        }
        else if(seleccion == 4)
        {
            buscar_por_genero(discos, n_discos);
        }
        else if(seleccion == 5)
        {
            menu_fila_re(discos, fila_re, n_fila, n_discos);
        }
        else if(seleccion == 6)
        {
            
        }
        else if(seleccion == 7)
        {
            
        }
    }
}

void buscar_id(discos_ discos[MAX_DISCOS], int n_discos)
{
    int busca;

    ordenar_discos_por_id(discos, n_discos); /** esto sirve para que los ya se ordene automaticamente por id */

    printf("Selecciona la id del Thema\n");
    if(scanf("%d",&busca) != 1)
    {
        return;
    }

    int busqueda =busqueda_binaria_recursiva(discos, busca, 0, n_discos - 1);
    if (busqueda != -1)
    {
        printf("\n\n| %-5d | %-33s | %-15s | \n", discos[busqueda].id, discos[busqueda].titulo, discos[busqueda].artista);
    }
    else
    {
        printf("\nNo se a encontrado ninguna cancion con el ID %d\n", busca);
    }
}

void buscar_nombre(discos_ discos[], int n_discos)
{
    char nombre_ingresado[50];
    printf("Ingrese el nombre de la cancion\n");
    if(scanf(" %49[^\n]", nombre_ingresado) != 1)
    {
        return;
    }
    for (int i = 0; i < n_discos; i++)
    {
        // Validación contra NULL y comparación exacta de cadenas
        if(strcmp(discos[i].titulo, nombre_ingresado) == 0)
        {
            printf("Nombre encontrado");
            printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d |\n", discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
        }
    }
}

/**
 * @brief hecho por benjamin HErnandez
 * 
 * @param disco 
 * @param n_discos 
 */
void buscar_artista(discos_ discos[], int n_discos)
{
    char artita_ingresado[30];
    printf("Ingrese el nombre exacto o parcial del artista: ");
    if(scanf(" %29[^\n]", artita_ingresado) != 1) /** [^\n] esto sirve que pueda leer el espacio */
    {
        return;
    }
    for(int i = 0; i < n_discos; i++)
    {
        if(strcmp(discos[i].artista, artita_ingresado) == 0)
        {
            printf("%-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d |\n",discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
        }
    }
}


void buscar_por_genero(discos_ discos[MAX_DISCOS], int n_discos)
{
    char seleccion[50] = {0};
    int cant_canciones_genero = 0;
    int pop = 0, electronica = 0, jazz = 0, country = 0, hyper_pop = 0, dubstep = 0, dnb = 0, indie_rock = 0, soundtrack = 0, musica_clasica = 0;
    
    for (int i = 0; i < n_discos; i++)
    {
        if (strcmp(discos[i].genero, "Pop") == 0)
        {
            pop++;
        }
        else if (strcmp(discos[i].genero, "Electronica") == 0)
        {
            electronica++;
        }
        else if (strcmp(discos[i].genero, "Jazz") == 0)
        {
            jazz++;
        }
        else if (strcmp(discos[i].genero, "Country") == 0)
        {
            country++;
        }
        else if (strcmp(discos[i].genero, "Hyper Pop") == 0)
        {
            hyper_pop++;
        }
        else if (strcmp(discos[i].genero, "Dubstep") == 0)
        {
            dubstep++;
        }
        else if (strcmp(discos[i].genero, "DnB") == 0)
        {
            dnb++;
        }
        else if (strcmp(discos[i].genero, "Indie Rock") == 0)
        {
            indie_rock++;
        }
        else if (strcmp(discos[i].genero, "Soundtrack") == 0)
        {
            soundtrack++;
        }
        else if (strcmp(discos[i].genero, "Musica clasica") == 0)
        {
            musica_clasica++;
        }
    }
    
    printf("Generos disponibles:\n");
    printf("Pop: %d\n", pop);
    printf("Electronica: %d\n", electronica);
    printf("Jazz: %d\n", jazz);
    printf("Country: %d\n", country);
    printf("Hyper Pop: %d\n", hyper_pop);
    printf("Dubstep: %d\n", dubstep);
    printf("DnB: %d\n", dnb);
    printf("Indie Rock: %d\n", indie_rock);
    printf("Soundtrack: %d\n", soundtrack);
    printf("Musica clasica: %d\n", musica_clasica);
    
    printf("\nEscriba el que desee buscar: ");
    if(scanf(" %49[^\n]", seleccion) != 1) // El espacio al inicio omite espacios/Enter previos (IA)
    {
        return;
    }
    printf("====================================================================================================================================================\n");
    printf("|                                                            %-80s      |\n", seleccion);
    printf("====================================================================================================================================================\n");
    printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_REPRODUCCIONES");
    printf("==================================================================================================================================================== \n");


    for (int j = 0; j < n_discos; j++)
    {
        if (strcmp(discos[j].genero, seleccion) == 0)
        {
            cant_canciones_genero++;

            printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d | \n", 
                discos[j].id, 
                discos[j].titulo, 
                discos[j].artista, 
                discos[j].album, 
                discos[j].genero, 
                discos[j].duracion_seg,
                discos[j].anho,
                discos[j].n_reproducciones);
        }
    }

    printf("\nHay %d cancion/es del genero que eligio \n", cant_canciones_genero);
    
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

    int indice_mitad = izquierda + (derecha - izquierda) / 2;
    int Mitad = discos[indice_mitad].id;

    if (busqueda == Mitad)
    {   
        return indice_mitad; // Retorna el indice
    }
    
    if (busqueda < Mitad)
    {   
        return busqueda_binaria_recursiva(discos, busqueda, izquierda, indice_mitad - 1);
    }
    else
    {   
        return busqueda_binaria_recursiva(discos, busqueda, indice_mitad + 1, derecha);
    }
}


/**
 * @brief Funcion exportacion de datos csv Realizado  por Benjamin  Hernandez
 * 
 * @param discos 
 */
void Exportacion(discos_ discos[MAX_DISCOS], int n_discos)
{
    FILE *archivo_csv = fopen("CSV/Catalogo.csv", "w");
    if (archivo_csv == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fprintf(archivo_csv,"ID,TITULO,ARTISTA,ALBUN,GENERO,DURACION,ANHO,NUMERO_DE_PRODUCCIONES\n");
    for (int i = 0; i < n_discos; i++)
    {
        fprintf(archivo_csv, "%d,%s,%s,%s,%s,%d,%d,%d\n", discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
    }
    printf("Datos guardados correctamente\n");

    fclose(archivo_csv);
}

/**
 * @brief Funcion liberacion de memoria de punteros por Franco
 * 
 * @param discos discos a liberar
 */
void liberar_memoria(discos_ discos[MAX_DISCOS])
{
    for (int i = 0; i < MAX_DISCOS; i++)
    {
        free(discos[i].titulo);
        free(discos[i].album);
    }
}

void consultar_fila_re(discos_ fila_re[MAX_FILA],int n_fila)
{
    if (n_fila == 0)
    {
        printf("La lista de reproducion esta vacia \n");
        return;
    }
    
    printf("====================================================================================================================================================\n");
    printf("|                                                       FILA DE REPRODUCCION                                                                       |\n");
    printf("====================================================================================================================================================\n");
    printf("| %-5s | %-5s | %-30s | %-15s | %-20s |\n","POS","ID","TITULO","ARTISTA","ALBUM");
    printf("====================================================================================================================================================\n");
    for (int i = 0; i < n_fila; i++)
    {
        printf("| %-5d | %-5d | %-30s | %-15s | %-20s|\n", i+1, fila_re[i].id, fila_re[i].titulo, fila_re[i].artista, fila_re[i].album);
    }
    printf("====================================================================================================================================================\n");
}

void anhadir_fila_re(discos_ fila_re[MAX_FILA], discos_ discos[MAX_DISCOS], int *n_fila, int n_discos)
{
    if (*n_fila >= MAX_FILA)
    {
        printf("Fila de reproduccion llena \n");
        return;
    }
    
    int id_buscar = 0;
    printf("Ingrese el ID de la cancion que desea anhadir a la fila de reproduccion \n");
    printf("ID: \n");
    if(scanf("%d", &id_buscar) != 1)
    {
        return;
    }

    int id_catalogo = -1;
    for (int i = 0; i < n_discos; i++)
    {
        if (discos[i].id == id_buscar)
        {
            id_catalogo = i;
            break;
        }
    }
    
    if (id_catalogo == -1)
    {
        printf("No se encontro ninguna cancion con este ID \n");
        return;
    }

    for (int i = 0; i < *n_fila; i++)
    {
        if (fila_re[i].id == id_buscar)
        {
            printf("Esta cancion ya se encuentra en la lista de reproduccion \n");
            break;
        }
    }
    
    
    for (int i = *n_fila; i > 0; i--) //hacer espacion enla posicion 0
    {
        fila_re[i] = fila_re[i-1];
    }
    fila_re[0] = discos[id_catalogo]; //insertar en la posicion 0
    (*n_fila)++;

    printf("SE ANHADIO A LA FILA DE REPRODUCCION");
}

void quitar_fila_re(discos_ fila_re[MAX_FILA], int *n_fila)
{
    if (*n_fila == 0)
    {
        printf("La lista de reproduccion esta vacia \n");
        return;
    }
    
    int opcion = 0;
    printf("--- Eliminar de la fila ---\n");
    printf("1. Eliminar por posicion \n");
    printf("2. Eliminar por ID \n");
    printf("Seleccione su opcion: \n");
    if(scanf("%d", &opcion) != 1)
    {
        return;
    }

    int pos_borrar = -1;

    switch (opcion)
    {
        case 1:
        {
            int pos_elegida = 0;

            consultar_fila_re(fila_re, *n_fila);

            printf("Ingrese la posicion que desea eliminar: \n");
            if(scanf("%d", &pos_elegida) != 1)
            {
                return;
            }

            if (pos_elegida < 1 || pos_elegida > *n_fila)
            {
                printf("Esta posicion no existe/fuera de rango\n");
                return;
            }

            pos_borrar = pos_elegida - 1;
        
            break;
        }
        case 2:
        {    
            int id_elegido = 0;

            consultar_fila_re(fila_re, *n_fila);

            printf("Ingrese el ID de la cancion que desea eliminar: \n");
            if(scanf("%d", &id_elegido) != 1)
            {
                return;
            }

            for (int i = 0; i < *n_fila; i++)
            {
                if (fila_re[i].id == id_elegido)
                {
                    pos_borrar = i;
                    break;
                }
            }

            if (pos_borrar == -1)
            {
                printf("No se encontro el ID de la cancion \n");
                return;
            }
            break;
        }
        default:
            printf("Opcion no valida. \n");
        return;
    }

    for (int i = pos_borrar; i < *n_fila-1 ; i++)
    {
        fila_re[i] = fila_re[i+1];
    }
    (*n_fila)--;
}

void vaciar_fila_re(int *n_fila)
{
    *n_fila = 0;
    printf("Fila vaciada completamente \n");
}

void menu_fila_re(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos)
{
    int opcion_fila_re = 0;

    printf("\n");
    printf("=======================================\n");
    printf("|Menu fila de reproduccion            |\n");
    printf("=======================================\n");
    printf("| 0- Volver al menu                   |\n");
    printf("| 1- Consultar fila de reproduccion   |\n");
    printf("| 2- Anhadir canccion                 |\n");
    printf("| 3- Quitar cancion                   |\n");
    printf("| 4- Vaciar lista de reproduccion     |\n");
    printf("=======================================\n\n");
    printf("Elija su opcion: \n");
    if(scanf("%d", &opcion_fila_re) != 1)
    {
        return;
    }

    switch (opcion_fila_re)
    {
    case 0:
        break;
    case 1:
        consultar_fila_re(fila_re, *n_fila);
        break;
    case 2:
        anhadir_fila_re(fila_re, discos, n_fila, n_discos);
        break;
    case 3:
        quitar_fila_re(fila_re, n_fila);
        break;
    case 4:
        vaciar_fila_re(n_fila);
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }
}