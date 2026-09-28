    #include "commons.h"


//Compilar: gcc main.c -o ./main.out && ./main.out

int main ()
{
    srand(time(NULL));

    discos_ discos[MAX_DISCOS];
    discos_ fila_re[MAX_FILA];

    int n_discos = rand() % MAX_DISCOS + 1;
    int n_fila = 0;

    printf("Ingrese la cantidad de discos que desea generar: ");
    scanf("%d", &n_discos);

    init_discos(discos);
    generador_id(discos, n_discos);
    generador_titulo(discos, n_discos);
    generador_artista(discos, n_discos);
    generador_album(discos, n_discos);
    generador_genero(discos, n_discos);
    generador_duracion_seg(discos, n_discos);
    generador_anho(discos, n_discos);
    generador_n_reproducciones(discos, n_discos);
    fisher_yates(discos, n_discos);


    listar_artistas_disponibles(discos);
    print_discos(discos, n_discos);
    busqueda(discos,n_discos);
    menu_fila_re(discos, fila_re, &n_fila, n_discos);
    Exportacion(discos,n_discos);

    liberar_memoria(discos);

    return 0;
}
