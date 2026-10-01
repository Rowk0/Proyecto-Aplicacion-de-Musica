    #include "commons.h"


//Compilar: gcc main.c -o ./main.out && ./main.out

int main ()
{
    srand(time(NULL));

    discos_ discos[MAX_DISCOS];
    discos_ fila_re[MAX_FILA];
    discos_ fila_hi[MAX_FILA];

    
    int n_fila = 0;
    int n_historial = 0;

    init_discos(discos);

    int n_discos = Inportacion(discos);
    if(n_discos == 0)
    {
        n_discos = rand() % MAX_DISCOS + 1;
        generador_id(discos, n_discos);
        generador_titulo(discos, n_discos);
        generador_artista(discos, n_discos);
        generador_album(discos, n_discos);
        generador_genero(discos, n_discos);
        generador_duracion_seg(discos, n_discos);
        generador_anho(discos, n_discos);
        generador_n_reproducciones(discos, n_discos);
        fisher_yates(discos, n_discos);
    }

    listar_artistas_disponibles(discos);
    menu(discos, fila_re, &n_fila, n_discos, fila_hi, &n_historial);
    
    Exportacion(discos,n_discos);
    liberar_memoria(discos);

    return 0;
}
