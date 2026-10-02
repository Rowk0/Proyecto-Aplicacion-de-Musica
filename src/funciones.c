/**
 * @file funciones.c
 * @author Benjamin Hernndez
 * @brief Listado de funciones del proyecto
 * @date 2026-09-27
 * 
 */
#include "commons.h"

/**
 * @brief Funcion por Franco
 * La funcion lo que hace es recorrer todos los discos guardados y mostrar una lista de los artistas disponibles en el catalogo
 * @param discos Arreglo con el catálogo de canciones/discos.
 */
void listar_artistas_disponibles(discos_ discos[MAX_DISCOS])
{
    char *artistas_disponible[MAX_DISCOS];
    int seEncontró = 0;
    int j = 0;

    for(int i = 0; i < MAX_DISCOS; i++) /**<recorre todos los discos  */
    {
        seEncontró = 0;

        if(discos[i].artista != NULL)  /**<verifica que el disco tenga un artista */
        {   
            for (int k = 0; k < j; k++) /** < recorre los artista que fueron encontrados */
            {
                if(strcmp(artistas_disponible[k], discos[i].artista) == 0) /**<compara cada artista que a sido encontrado */
                {
                    seEncontró = 1;
                    break;
                }
            }

            if(seEncontró == 0) /**si el artista no fue encontrado anteriormente */
            {
                artistas_disponible[j] = discos[i].artista;/**guarda el puntero del nombre del artissta*/
                j++; /**aumenta la cantidad de artista encontrados */
            }
        }   
    }

    ///////////////////////////////////////////////////////////
    /** muestra los artista disponibles*/
    printf("==================================\n");
    printf("| %-30s |\n", "ARTISTAS DISPONIBLES"); 
    printf("================================== \n");

    for (int l = 0; l < j; l++)
    {
        printf("| %-30s |\n", artistas_disponible[l]); 
    }
    printf("================================== \n\n");
}

/**
 * @brief Funcion por Franco
 * En esta funcion lo que hace es inicializa todos los campos de la estructura discos en valores por defecto
 * @param discos Arreglo con el catálogo de canciones/discos.
 */
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
 * @brief Funcio hecha por Daniela 
 * La funcion lo que hace es dar un valor de id en el Max_discos
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
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
 * En esta funcion lo que hace es basicamente combinar advervio, sustantivo y adjetiv, para crear un titulo 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void generador_titulo(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *adverbio[] = {"Aqui", "Pronto", "Jamas", "Acaso", "Deprisa"};
    char *sustantivo[] = {"Pan", "Canada", "Edgardo", "Bordoli", "Torre"};
    char *adjetivo [] = {"Sangriento", "Estancado", "Montanhista", "terrorista", "Desgraciado"};

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

/**
 * @brief Funcion por Daniela
 * En est afuncion lo que hace es generar un artista aleatoriamente de una lista ya predefinida
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados 
 */
void generador_artista(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *artista[] = {"Jere Klein", "Bad Bunny", "Cris MJ", "Kidd Voodoo", "Feid", "Karol G", "Lucky Brown", "Anuel AA", "Katteyes", "Blessd"};
    int aux = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 10;
        discos[i].artista = strdup(artista[aux]);
    }
}

/**
 * @brief Funcion por Franco
 * En esta funcion lo que hace es generar el nombre de un albun aleatoriamente con un sustantivo o adjetivo
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
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

/**
 * @brief Funcion por Franco
 * En esta funcion lo que hace es basicamente elegir una lista ya predefinidad aleatoraimente
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void generador_genero(discos_ discos[MAX_DISCOS], int n_discos)
{
    char *genero[] = {"Pop", "Electronica", "Jazz", "Country", "Hyper Pop", "Dubstep", "DnB", "Indie Rock", "Soundtrack", "Musica clasica"};
    int aux = 0;

    for (int i = 0; i < n_discos; i++)
    {
        aux = rand() % 10;

        discos[i].genero = strdup(genero[aux]);
    }
}
/**
 * @brief Funcion por Franco
 * Basicamente lo que hace esta funcion es generar aleatoriamente cuanto puede durar la cancion dentro de un rango de 180 hasta 300 seg
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados 
 */
void generador_duracion_seg(discos_ discos[MAX_DISCOS], int n_discos)
{
    int num = 0;

    for (int i = 0; i < n_discos; i++)
    {
        num = 180 + rand() % (300 - 180 + 1);

        discos[i].duracion_seg = num;
    }
}
/**
 * @brief Funcion por Franco
 * Basicamente lo que hace esta funciones es generar un numero aleatorio entre 1900 a 2026 para el año que se origino el disco
 * @param discos 
 * @param n_discos 
 */
void generador_anho(discos_ discos[MAX_DISCOS], int n_discos)
{
    int anho = 0;

    for (int i = 0; i < n_discos; i++)
    {
        anho = 1900 + rand() % (2026 - 1900 + 1);

        discos[i].anho = anho;
    }
}

/**
 * @brief Funcion por Franco
 * En esta funcion lo que hace es generar aleatoraimente los numeros de la cantidad de reproducciones que hay entre 5000 a 10000
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void generador_n_reproducciones(discos_ discos[MAX_DISCOS], int n_discos)
{
    int n_reproducciones = 0;

    for (int i = 0; i < n_discos; i++)
    {
        n_reproducciones = 5000 + rand() % (10000 - 5000 + 1);

        discos[i].n_reproducciones = n_reproducciones;
    }
}

/**
 * @brief Funcion por Daniela
 * Esta funcion lo que hace es Permuta los elemntos del arrglo de manera aleatoria 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
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

/**
 * @brief Funcion por Franco
 * Basicamente esta funcion lo que hace es imprimir cada catalogo de disco en formato tabla
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void print_discos(discos_ discos[MAX_DISCOS], int n_discos)
{
    printf("====================================================================================================================================================\n");
    printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_n_reproducciones");
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
 * @brief Funcion por Hernandez
 * Genera diferentes reportes de ranking del catálogo.
 *
 * La función genera tres tipos de rankings:
 *
 * 1. Top 5 de canciones con mayor cantidad de reproducciones.
 * 2. Canción más escuchada de cada género.
 * 3. Canción más escuchada de cada artista.
 *
 * Para obtener el Top 5 global, se utiliza el algoritmo
 * de ordenamiento Burbuja (Bubble Sort), ordenando las canciones
 * de mayor a menor cantidad de reproducciones.
 *
 * Para los rankings por género y artista, se utilizan las funciones
 * cancion_mas_escuchada() y cancion_mas_escuchada_art().
 * @param discos Arreglo que contiene el catálogo de canciones/discos.
 * @param n_discos Cantidad actual de discos registrados.
 */
void ranking(discos_ discos[], int n_discos)
{
    for (int i = 0; i < n_discos - 1; i++)
    {
        for (int j = 0; j < n_discos - i - 1; j++)
        {
            if (discos[j].n_reproducciones < discos[j + 1].n_reproducciones)
            {
                discos_ temp = discos[j];
                discos[j] = discos[j + 1];
                discos[j + 1] = temp;
            }
        }
    }
    printf("==========================================\n");
    printf("|     Top 5 canciones mas escuchada      |\n");
    printf("==========================================\n");
    int limite = (n_discos < 5) ? n_discos : 5;
    for(int i = 0; i < limite; i++)
    {
        printf("|%d- %27s %7d |\n", i + 1, discos[i].titulo, discos[i].n_reproducciones);
    }
    printf("==========================================\n\n");
    
    char *genero[] = {"Pop", "Electronica", "Jazz", "Country", "Hyper Pop", "Dubstep", "DnB", "Indie Rock", "Soundtrack", "Musica clasica"};
    
    printf("======================================\n");
    printf("|  Cancion mas escuchada por genero  |\n");

    for(int i = 0; i < 10; i++)
    {
        cancion_mas_escuchada(discos, n_discos, genero[i]);
    }
    printf("======================================\n\n");

    char *artista[] = {"Jere Klein", "Bad Bunny", "Cris MJ", "Kidd Voodoo", "Feid", "Karol G", "Lucky Brown", "Anuel AA", "Katteyes", "Blessd"};

    printf("============================================\n");
    printf("|   CANCION MAS ESCUCHADA DE LOS ARTISTA   |\n");
    printf("============================================\n");
    for(int i = 0; i < 10; i++)
    {
        cancion_mas_ecuchada_art(discos, n_discos, artista[i]);
    }
}

/**
 * @brief Funcion por hernandez
 * Basicamente lo que hace es busca e imprime la cacion mas escuchada de un artista en especifico.
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados 
 * @param artista 
 */
void cancion_mas_ecuchada_art(discos_ discos[], int n_discos, char artista[])
{
    int max_reprod = -1;
    int pos_max = -1;

    for (int i = 0; i < n_discos; i++)
    {
        if (strcmp(discos[i].artista, artista) == 0)
        {
            if (discos[i].n_reproducciones > max_reprod)
            {
                max_reprod = discos[i].n_reproducciones;
                pos_max = i;
            }
        }
    }

    if (pos_max != -1)
    {
        printf("=============================================\n");
        printf("| Artista:        %28s |\n", discos[pos_max].artista);
        printf("| Cancion:        %28s |\n", discos[pos_max].titulo);
        printf("| Reproducciones: %28d |\n", discos[pos_max].n_reproducciones);
        printf("=============================================\n");
    }
    else
    {
        printf("No se encontraron canciones para el artista %s\n", artista);
    }
}



/**
 * @brief Funcion realizada por Benjamin Hernandez
 * Busca e imprime la canción más escuchada de un género específico.
 * La función primero recorre el catálogo y selecciona solamente las canciones que pertenecen al género indicado.
 *
 * Posteriormente, utiliza el algoritmo Insertion Sort para ordenar las canciones seleccionadas de mayor a menor cantidad de 
 * reproducciones finalmente, muestra la primera canción del arreglo ordenado, ya quecorresponde a la canción con mayor cantidad de reproducciones.
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados 
 * @param genero Es el genero musical que desea buscar
 */
void cancion_mas_escuchada(discos_ discos[], int n_discos, char genero[]) /**<se ha utilizado Insertion Sort>*/
{
    discos_ seleccionados[MAX_DISCOS];
    int cantidad = 0;

    for (int i = 0; i < n_discos; i++)
    {
        if (strcmp(discos[i].genero, genero) == 0)
        {
            seleccionados[cantidad] = discos[i];
            cantidad++;
        }
    }

    for (int i = 1; i < cantidad; i++) // Insertion Sort
    {
        discos_ clave = seleccionados[i];
        int j = i - 1;

        for (; j >= 0 &&
               seleccionados[j].n_reproducciones < clave.n_reproducciones;
             j--)
        {
            seleccionados[j + 1] = seleccionados[j];
        }

        seleccionados[j + 1] = clave;
    }

    if (cantidad > 0)
    {
        printf("======================================\n");
        printf("|Genero:    %25s|\n", seleccionados[0].genero);
        printf("|Cancion: %27s|\n", seleccionados[0].titulo);
        printf("|Reproducciones: %20d|\n",seleccionados[0].n_reproducciones);
    }
}

/**
 * @brief Fucion echo por benjamin hernandez 
 * Basicamente esta funcion lo que hace es ordenar los discos de mmeno a mayor segun la id (burble sort)
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void ordenar_discos_por_id(discos_ discos[MAX_DISCOS], int n_discos) {
    int swapped;
    for (int i = 0; i < n_discos - 1; i++) 
    {
        swapped = 0;
        for (int j = 0; j < n_discos - i - 1; j++) 
        {
            if (discos[j].id > discos[j + 1].id) // Ordenamiento de menor discos_1 mayor por ID
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
 * @brief  Hecho por benjamin  Hernandez
 * La función ordena los discos según el criterio seleccionado. Para realizar el ordenamiento, se selecciona un elemento central 
 * del arreglo como pivote y se separan los elementos menores y mayores respecto a este.
 * 
 * @param discos Arreglo que contiene los discos que serán ordenados.
 * @param izquierda Posición inicial del segmento del arreglo que se ordenará.
 * @param derecha Posición final del segmento del arreglo que se ordenará.
 * @param criterio Indica el criterio utilizado para comparar los discos.
 */
void quick_sort(discos_ discos[], int izquierda, int derecha, int criterio)
{
    int i = izquierda;
    int j = derecha;
    discos_ pivote = discos[(izquierda + derecha) / 2];
    discos_ aux;
    while (i <= j)
    {
        while (comparar_discos(discos[i], pivote, criterio) < 0)
        {    
            i++;
        }
        while (comparar_discos(discos[j], pivote, criterio) > 0)
        {
            j--;
        }
        if (i <= j)
        {
            aux = discos[i];
            discos[i] = discos[j];
            discos[j] = aux;
            i++;
            j--;
        }
    }
    if (izquierda < j)
    { 
        quick_sort(discos, izquierda, j, criterio);
    }
    if (i < derecha)
    {
        quick_sort(discos, i, derecha, criterio);
    }
}

/**
 * @brief Funcion Hecha por Benjamin Hernandez
 * Esta funcion lo que hace es comparar dos estructuras de discos segun el criterio
 * @param discos_1 Primer disco 
 * @param discos_2 segundo disco
 * @param criterio id, discos, titulo,artista, albun, anho, reproducciones
 * @return Valor menor, igual, o mayor a 0 segun la comparacion
 */
int comparar_discos(discos_ discos_1, discos_ discos_2, int criterio)
{
    switch (criterio)
    {
        case 1: // ID
            return discos_1.id - discos_2.id;

        case 2: // Título
            return strcmp(discos_1.titulo, discos_2.titulo);

        case 3: // Artista
            return strcmp(discos_1.artista, discos_2.artista);

        case 4: // Álbum
            return strcmp(discos_1.album, discos_2.album);

        case 5: // Género
            return strcmp(discos_1.genero, discos_2.genero);

        case 6: // Año
            return discos_1.anho - discos_2.anho;

        case 7: // Numero de n_reproducciones
            return discos_1.n_reproducciones - discos_2.n_reproducciones;

        default:
            return 0;
    }
}



/**
 * @brief 
 * 
 * @param discos 
 * @param fila_re 
 * @param n_fila 
 * @param n_discos 
 * @param fila_hi 
 * @param n_historial 
 */
void menu(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos, discos_ fila_hi[MAX_FILA], int *n_historial)
{
    int seleccion = -1; /** menu de busqueda  */

    while(seleccion != 0)
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
        printf("| 6- Historial de reproduccion   |\n");
        printf("| 7- Reproducir musica           |\n");
        printf("| 8- Ver musica disponible       |\n");
        printf("| 9- Ranking                     |\n");
        printf("| 10- Ordenar musica disponible  |\n");
        printf("==================================\n\n");
        if(scanf("%d", &seleccion) != 1)
        {
            int c;
            while((c = getchar()) != '\n' && c != EOF); // Se asigna a c y se limpia el buffer
            seleccion = -1;
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
            print_fila_historial(fila_hi, n_historial);
        }
        else if(seleccion == 7)
        {
            //Hacer que al reproducir musica se añada en historial de musica
            reproducir_musica(discos, fila_re, n_fila, fila_hi, n_historial);
        }
        else if (seleccion == 8)
        {
            print_discos(discos, n_discos);
        }
        else if (seleccion == 9)
        {
            ranking(discos,n_discos);
        }
        else if (seleccion == 10)
        {
            int criterio = -1;
            printf("======================\n");
            printf("|¿Cómo desea ordenar?|\n");
            printf("======================\n");
            printf("|1- ID               |\n");
            printf("|2- Título           |\n"); 
            printf("|3- Artista          |\n");
            printf("|4- Álbum            |\n");
            printf("|5- Género           |\n");
            printf("|6- Año              |\n");
            printf("|7- n_reproducciones |\n");
            printf("======================\n");
            if(scanf("%d", &criterio) != 1)
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF); 
                criterio = -1;    
            }
            else
            {
                quick_sort(discos, 0, n_discos - 1, criterio);
                printf("\nCatálogo ordenado correctamente.\n");
                print_discos(discos, n_discos);   
            }
        }
    }
}

/**
 * @brief Funcion por Franco
 * Reproduce la primera canción de la fila de reproducción.
 * La función toma la primera canción de la fila de reproducción,aumenta su cantidad de reproducciones en el catálogo principal,la agrega al historial 
 * y finalmente la elimina de la fila dereproducción.
 *
 * @param discos Arreglo que contiene el catálogo principal de canciones.
 * @param fila_re Arreglo que contiene las canciones de la fila de reproducción.
 * @param n_fila Puntero que contiene la cantidad de canciones actualmentealmacenadas en la fila de reproducción.
 * @param fila_hi Arreglo que contiene el historial de canciones reproducidas.
 * @param n_historial Puntero que contiene la cantidad de canciones almacenadas actualmente en el historial.
 */
void reproducir_musica(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, discos_ fila_hi[MAX_FILA], int *n_historial)
{
    int pos_borrar = -1;

    /* Primero confirmar que la lista de reproduccion tiene alguna cancion */

    if(*n_fila == 0)
    {
        printf("La lista de reproduccion esta vacia \n");
        return;
    }

    /*Se aumenta en uno la cantidad de n_reproducciones en discos[MAX_DISCOS]*/
    
    for (int i = 0; i < MAX_DISCOS; i++)
    {
        if (discos[i].id == fila_re[0].id)
        {
            discos[i].n_reproducciones++;
            break;
        }
    }

    /* Añadir cancion al historial */

    historial_musica(fila_hi, fila_re, n_historial);

    /*Se borra la musica de la posicion 1 de la lista de reproduccion, codigo por cortesia de la Dani*/

    int pos_elegida = 1;

    if (pos_elegida < 1 || pos_elegida > *n_fila)
    {
        printf("Esta posicion no existe/fuera de rango\n");
        return;
    }

    pos_borrar = pos_elegida - 1;

    for (int i = pos_borrar; i < *n_fila-1 ; i++)
    {
        fila_re[i] = fila_re[i+1];
    }
    (*n_fila)--;


}

/**
 * @brief Funcio por Franco y Daniela
 * Agrega una canción reproducida al inicio del historial.
 *La función recibe una canción desde la fila de reproducción y laagrega en la primera posición del historial.
 *
 * Para mantener el orden del historial, primero desplaza todos los elementos existentes una posición hacia la derecha.
 * Si el historial alcanza MAX_FILA, se elimina el elemento más antiguo antes de agregar la nueva canción.
 *
 * @param fila_hi Arreglo que contiene el historial de canciones reproducidas.
 * @param fila_re Arreglo que contiene la fila de reproducción actual.
 * @param n_historial Puntero que almacena la cantidad actual de canciones
 */
void historial_musica(discos_ fila_hi[MAX_FILA], discos_ fila_re[MAX_FILA], int *n_historial)
{
    if (*n_historial == MAX_FILA)
    {
        (*n_historial)--;
    }

    for (int i = *n_historial; i > 0; i--)
    {
        fila_hi[i] = fila_hi[i-1];
    }

    fila_hi[0] = fila_re[0];

    if (*n_historial < MAX_FILA) 
    {
        (*n_historial)++;
    }
    
    printf("===========================================================================================\n");
    printf("|                             REPRODUCCIENDO CANCION                                      |\n");
    printf("===========================================================================================\n");
    printf("| %-5d | %-30s | %-15s | %-20s |\n", fila_hi[0].id, fila_hi[0].titulo, fila_hi[0].artista, fila_hi[0].album);
    printf("===========================================================================================\n");
}

/**
 * @brief Funcion por Franco
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void print_fila_historial(discos_ fila_hi[MAX_FILA], int *n_historial)
{
    //NO SE COMO HACER ESTO

    printf("===========================================================================================\n");
    printf("|                             HISTORIAL                                                   |\n");
    printf("===========================================================================================\n");
    printf("| %-5s | %-30s | %-15s | %-20s |\n","ID","TITULO","ARTISTA","ALBUM");
    printf("===========================================================================================\n");
    for (int i = 0; i < *n_historial; i++)
    {
        printf("| %-5d | %-30s | %-15s | %-20s|\n", fila_hi[i].id, fila_hi[i].titulo, fila_hi[i].artista, fila_hi[i].album);
    }
    printf("===========================================================================================\n");
}

/**
 * @brief Funcion por Hernandez
 *  Basicacamente la funcion lo que hace es buscar una cancion por ID mediante la busqueda binaria
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
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
        printf("====================================================================================================================================================\n");
        printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_n_reproducciones");
        printf("==================================================================================================================================================== \n");
        printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d |\n",discos[busqueda].id, discos[busqueda].titulo, discos[busqueda].artista, discos[busqueda].album, discos[busqueda].genero, discos[busqueda].duracion_seg, discos[busqueda].anho, discos[busqueda].n_reproducciones);
        printf("==================================================================================================================================================== \n");
    }
    else
    {
        printf("\nNo se discos_1 encontrado ninguna cancion con el ID %d\n", busca);
    }
}
/**
 * @brief Funcion por Hernandez
 * Busca canciones dentro del catalogo mediante su titulo exacto, recorriendo todos los discos y comparando cada titulo con el nombre
 * ingresado por el usuario.
 * 
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void buscar_nombre(discos_ discos[], int n_discos)
{
    char nombre_ingresado[50];
    int encontrado = 0;

    printf("Ingrese el nombre de la cancion\n");
    if(scanf(" %49[^\n]", nombre_ingresado) != 1)
    {
        return;
    }

    for (int i = 0; i < n_discos; i++)
    {
        if(strcmp(discos[i].titulo, nombre_ingresado) == 0)
        {
            if (!encontrado)
            {
                printf("Nombre encontrado\n\n");
                printf("====================================================================================================================================================\n");
                printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_n_reproducciones");
                printf("==================================================================================================================================================== \n");
                encontrado = 1;
            }
            printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d |\n", discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
        }
    }

    if (encontrado)
    {
        printf("==================================================================================================================================================== \n");
    }
    else
    {
        printf("\nNo se encontro ninguna cancion con el nombre '%s'\n", nombre_ingresado);
    }
}

/**
 * @brief hecho por benjamin HErnandez
 * Basicamente lo que hace es buscar todas las canciones de un artisata en particular
 * @param discos Arreglo con el catalogo de caciones/discos
 * @param n_discos Cantidad actul de discos registrados
 */
void buscar_artista(discos_ discos[], int n_discos)
{
    char artita_ingresado[30];
    printf("Ingrese el nombre exacto del artista: ");
    if(scanf(" %29[^\n]", artita_ingresado) != 1) /** [^\n] esto sirve que pueda leer el espacio */
    {
        return;
    }

    printf("====================================================================================================================================================\n");
    printf("|                                                            %-80s      |\n", artita_ingresado);
    printf("====================================================================================================================================================\n");
    printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_n_reproducciones");
    printf("==================================================================================================================================================== \n");

    for(int i = 0; i < n_discos; i++)
    {
        if(strcmp(discos[i].artista, artita_ingresado) == 0)
        {
            printf("| %-5d | %-30s | %-15s | %-20s | %-15s | %-15d | %-5d | %-18d |\n",discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
        }
    }

    printf("====================================================================================================================================================\n");
}

/**
 * @brief Funcion por Franco
 * Basicamente lo que hace la funcion es que busca y muestra las canciones pertenecientes a un genero especifico.
 * La funcion recorre el catalogo para contar cuantas canciones existen de cada genero disponible. Luego solicita al usuario seleccionar un genero
 * y vuelve a recorrer el catalogo para mostrar todas las canciones que coincidan con el genero seleccionado, indicando finalmente la cantidad
 * de canciones encontradas.
 *
 * @param discos Arreglo que contiene el catalogo de canciones y sus respectivos datos.
 * @param n_discos Cantidad actual de canciones o discos registrados en el catalogo.
 */
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
    printf("| %-5s | %-30s | %-15s | %-20s | %-15s | %-15s | %-5s | %-18s | \n","ID","TITULO","ARTISTA","ALBUM","GENERO","DURACION_SEG","ANHO","N_n_reproducciones");
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

    printf("==================================================================================================================================================== \n");

    printf("\nHay %d cancion/es del genero que eligio \n", cant_canciones_genero);
    
}

/**
 * @brief Busqueda binaria realizado por benjamin Hernandez
 * Realiza una busqueda binaria recursiva por ID en el catalogo de discos.
 * 
 * @note El arreglo 'discos' debe estar previamente ordenado de menor a mayor por ID.
 * 
 * @param discos Arreglo con el catálogo de canciones/discos.
 * @param busqueda ID del disco que se desea encontrar.
 * @param izquierda Índice inicial de la sublista.
 * @param derecha Índice final de la sublista.
 * @return int Índice del disco encontrado, o -1 si no existe.
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
 * Basicamente la funcion lo que hace es laexporta el catalogo de discos actual hacia el archivo CSV.
 * 
 * @param discos Arreglo con el catálogo de canciones/discos.
 * @param n_discos Cantidad actual de discos registrados.
 */
void Exportacion(discos_ discos[MAX_DISCOS], int n_discos)
{
    FILE *archivo_csv = fopen("CSV/Catalogo.csv", "w");
    if (archivo_csv == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fprintf(archivo_csv,"ID,TITULO,ARTISTA,ALBUM,GENERO,DURACION,ANHO,NUMERO_DE_PRODUCCIONES\n");
    for (int i = 0; i < n_discos; i++)
    {
        fprintf(archivo_csv, "%d,%s,%s,%s,%s,%d,%d,%d\n", discos[i].id, discos[i].titulo, discos[i].artista, discos[i].album, discos[i].genero, discos[i].duracion_seg, discos[i].anho, discos[i].n_reproducciones);
    }
    printf("Datos guardados correctamente\n");

    fclose(archivo_csv);
}

/**  
 * @brief Creado por Benjamin Hernandez: Lo que hace es que ingresa la  
 * Basicamente la funcion lo que hace es carga el catalogo de discos desde un archivo CSV.
 * 
 * @param discos Arreglo donde se almacenaran los discos importados.
 * @return int Cantidad de discos leidos exitosamente.
 */
int Inportacion(discos_ discos[MAX_DISCOS])
{
    FILE *archivo_csv = fopen("CSV/Catalogo.csv", "r");
    if(archivo_csv == NULL)
    {
        return 0; // El archivo no existe aún
    }
    char linea[256];
    int count = 0;

    if(fgets(linea, sizeof(linea), archivo_csv) == NULL)
    {
        fclose(archivo_csv);
        return 0;
    }

    while(fgets(linea, sizeof(linea), archivo_csv) != NULL && count < MAX_DISCOS)
    {
        discos[count].titulo = malloc(100 * sizeof(char));
        discos[count].album = malloc(100 * sizeof(char));
        discos[count].artista = malloc(100 * sizeof(char));
        discos[count].genero = malloc(100 * sizeof(char));
        sscanf(linea, "%d,%99[^,],%99[^,],%99[^,],%99[^,],%d,%d,%d", &discos[count].id, discos[count].titulo, discos[count].artista, discos[count].album, discos[count].genero, &discos[count].duracion_seg, &discos[count].anho, &discos[count].n_reproducciones);
        count++;
    }

    fclose(archivo_csv);
    return count; // Retorna la cantidad de discos cargados
}

/**
 * @brief Funcion liberacion de memoria de punteros por Franco
 * Basicamente lo que hace es libera la memoria dinamica asignada a las cadenas de texto del catalogo.
 * @param discos discos discos_1 liberar
 */
void liberar_memoria(discos_ discos[MAX_DISCOS])
{
    for (int i = 0; i < MAX_DISCOS; i++)
    {

        if (discos[i].titulo != NULL)  
        {  
            free(discos[i].titulo);  
            discos[i].titulo = NULL; }
        if (discos[i].album != NULL)   
        {
            free(discos[i].album); 
            discos[i].album = NULL; 
        }
        if (discos[i].artista != NULL) 
        { 
            free(discos[i].artista); 
            discos[i].artista = NULL; 
        }
        if (discos[i].genero != NULL)  
        {
            free(discos[i].genero);  
            discos[i].genero = NULL; 
        }
    }
}
    
/**
 * @brief Funcion por Dani
 * Basicamente lo que hace es mostrar por pantalla el contenido actual de la fila de reproduccion.
 * 
 * @param fila_re Arreglo de la fila de reproduccion.
 * @param n_fila Cantidad actual de canciones en la fila.
 */
void consultar_fila_re(discos_ fila_re[MAX_FILA],int n_fila)
{
    if (n_fila == 0)
    {
        printf("La lista de reproducion esta vacia \n");
        return;
    }
    
    printf("===========================================================================================\n");
    printf("|                             FILA DE REPRODUCCION                                        |\n");
    printf("===========================================================================================\n");
    printf("| %-5s | %-5s | %-30s | %-15s | %-20s |\n","POS","ID","TITULO","ARTISTA","ALBUM");
    printf("===========================================================================================\n");
    for (int i = 0; i < n_fila; i++)
    {
        printf("| %-5d | %-5d | %-30s | %-15s | %-20s|\n", i+1, fila_re[i].id, fila_re[i].titulo, fila_re[i].artista, fila_re[i].album);
    }
    printf("===========================================================================================\n");
}

/**
 * @brief Funcion por Dani
 * Basicamente la funcion lo que hace es busca una cancion por ID y la añade a la fila de reproduccion.
 * 
 * @param fila_re Arreglo de la fila de reproduccion.
 * @param discos Arreglo con el catálogo completo de discos.
 * @param n_fila Puntero a la cantidad de canciones actualmente en la fila.
 * @param n_discos Cantidad total de discos en el catálogo.
 */
void anhadir_fila_re(discos_ fila_re[MAX_FILA], discos_ discos[MAX_DISCOS], int *n_fila, int n_discos)
{
    if (*n_fila >= MAX_FILA)
    {
        printf("Fila de reproduccion llena \n");
        return;
    }
    
    int id_buscar = 0;
    printf("Ingrese el ID de la cancion que desea anhadir discos_1 la fila de reproduccion \n");
    printf("ID: ");
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
            return;
        }
    }
    
    
    for (int i = *n_fila; i > 0; i--) //hacer espacion enla posicion 0
    {
        fila_re[i] = fila_re[i-1];
    }
    fila_re[0] = discos[id_catalogo]; //insertar en la posicion 0
    (*n_fila)++;

    printf("SE ANHADIO A LA FILA DE REPRODUCCION\n");
}

/**
 * @brief Funcion por Dani
 * Basicamente la funncion lo que hace es elimina una cancion de la fila de reproduccion, ya sea por posicion o por ID.
 * 
 * @param fila_re Arreglo que representa la fila de reproduccion.
 * @param n_fila Puntero a la cantidad de canciones en la fila.
 */
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
    printf("Seleccione su opcion: ");
    if (scanf("%d", &opcion) != 1) 
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
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

            if(pos_elegida < 1 || pos_elegida > *n_fila)
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

/**
 * @brief Funcion por Dani
 * Basicamnete lo que hace es vaciar completamente la fila de reproduccion restableciendo su contador.
 * 
 * @param n_fila Puntero al numero de elementos en la fila de reproduccion.
 */
void vaciar_fila_re(int *n_fila)
{
    *n_fila = 0;
    printf("Fila vaciada completamente \n");
}

/**
 * @brief Funcion por Dani
 * menu principal de la operacion
 * 
 * @param discos Arreglo principal que contiene todas las canciones del catalogo.
 * @param fila_re Arreglo que representa la fila de reproduccion de canciones.
 * @param n_fila Puntero que almacena la cantidad actual de canciones en la fila de reproduccion.
 * @param fila_hi Arreglo que contiene el historial de canciones reproducidas.
 * @param n_historial Puntero que almacena la cantidad actual de canciones en el historial.
 */
void menu_fila_re(discos_ discos[MAX_DISCOS], discos_ fila_re[MAX_FILA], int *n_fila, int n_discos)
{
    int opcion_fila_re = -1;

    while (opcion_fila_re != 0)
    {
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
        printf("Elija su opcion: ");
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
}