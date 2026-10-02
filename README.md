# Gestion de musíca en C
Repositorio del proyecto del curso para la gestión de un catálogo musical mediante estructuras de datos y algoritmos en C.

# Estructura 
- src: Codigo fuente (main.c, funciones.c)
- inc: encabezado (commons.h)
- csv: Persistencia de datos (Catalogo.csv)
- makefile: automatizacion de compilacion.

Autores
- Benjamin Hernández
- Daniela Soto
- Franco Rodriguez

# Funcionalidades
- Carga/Guardado CSV: Importación automática de catálogo o generación aleatoria si no existe.
- Búsquedas: Búsqueda binaria recursiva por ID, y búsquedas por nombre, artista o género.
- Ordenamiento: Implementación de QuickSort para el catálogo e Insertion Sort para rankings.
- Reproducción: Cola de reproducción e historial de escucha.

# Modo de uso
make    // compilacion del proyecto
make run   //Ejecucion del proyecto
make clean     //Limpieza de archivos 
