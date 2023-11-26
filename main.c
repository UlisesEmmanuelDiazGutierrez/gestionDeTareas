#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecera.h"


//---------------------------------------------------------------------------
int main() {
    char busqueda[100];
    int opc,indice=0;
    int contadorTareas=0;
    struct tarea tareas[100];
    do {
            menu(&opc);
    switch (opc) {
            case 1:
                printf("---------------------------------------\n");
                printf(" Selecciono agregar nueva tarea.\n");
                agregarTarea(tareas, &contadorTareas);
                break;
            case 2:
                printf("---------------------------------------\n");
                printf(" Selecciono marcar una tarea como completada.\n");
                marcarCompleta(tareas, contadorTareas);
                break;
            case 3:
                printf("//------------------------------------\n");
                printf(" Selecciono listar todas las tareas pendientes.\n");
                listarPentdientes(tareas, contadorTareas);
                break;
            case 4:
                printf("---------------------------------------\n");
                printf("Selecciono listar todas las tareas.\n");
                listarTodas(tareas, contadorTareas);
                break;
            case 5:
                printf("---------------------------------------\n");
                printf(" Selecciono buscar por titulo.\n");
                printf(" escribe el titulo de la tarea que deseas buscar: ");
                scanf("%s",&busqueda);
                buscar(tareas,indice, contadorTareas, busqueda);
                break;
            case 6:
                printf("---------------------------------------\n");
                printf(" Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("---------------------------------------\n");
                printf(" Error: Opcion no valida. Intentelo de nuevo.\n");
        }
          while (getchar() != '\n');
          printf("Presione Enter para continuar...\n");
          getchar();
    } while (opc != 6);
    return 0;
}

