#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
    #define sistem printf("windows")
#endif // _WIN32
#ifdef __linux__
    #define CLEAR_SCREEN "clear"
    #define sistem printf("linux")
#endif // __linux__
#ifdef __APPLE__
    #define CLEAR_SCREEN "clear"
#endif // __APPLE__

//---------------------------------------------------------------------------
struct tarea{
    char titulo [100];
    int completo;
};
//---------------------------------------------------------------------------
//declaracion de funciones.
void menu(int *opc);
void agregarTarea(struct tarea tareas[],int *contadorTareas);
void marcarCompleta(struct tarea tareas[], int contadorTareas);
void listarPentdientes(struct tarea tareas[], int contadorTareas);
void listarTodas(struct tarea tareas[], int contadorTareas);
void buscar(struct tarea tareas[], int indice, int contadorTareas, char busqueda[]);
//---------------------------------------------------------------------------
//menu principal de opciones
void menu(int *opc){
system(CLEAR_SCREEN);
sistem;
        printf(" Bienvenido al sistema de gestion de tareas!\n");
        printf(" 1. Agregar nueva tarea\n");
        printf(" 2. Marcar una tarea como completada\n");
        printf(" 3. Lista todas las tareas pendientes\n");
        printf(" 4. Lista todas las tareas\n");
        printf(" 5. Buscar por titulo\n");
        printf(" 6. Salir\n");

        printf(" Ingreso de datos:");
        scanf("%d", opc);
}
//---------------------------------------------------------------------------
//funcion para agregar nuevas tareas
void agregarTarea(struct tarea tareas[], int *contadorTareas){
    printf("Escribe el titulo de la nueva tarea: ");
    scanf(" %[^\n]", tareas[*contadorTareas].titulo);
    tareas[*contadorTareas].completo = 0;
    (*contadorTareas)++;
    //printf("\ntareas actuales %d\n", *contadorTareas);
    printf("Tarea agregada exitosamente.\n");

}
//---------------------------------------------------------------------------
//esta funcion permite al usuario marcar una de las tareas almacenadas completa
void marcarCompleta(struct tarea tareas[], int contadorTareas){
int noTarea,opc;
do{
    printf("Escribe el numero de la tarea que deseas marcar como completada: ");
    scanf("%d",&noTarea);
    noTarea=noTarea-1;
    printf("%d. %s\n", noTarea+1, tareas[noTarea].titulo);
    printf("Presiona 1 si quieres marcar esta tarea como completa.\nPresiona 2 si quieres elegir otra tarea.\nPresiona 3 si deseas volver al menu principal.\n");
    printf("Ingreso de datos:");
    scanf("%d",&opc);
    if(opc==1){tareas[noTarea].completo=1;
    printf("Tarea completada con exito.\n");
    printf("%d. %s - %s\n", noTarea + 1, tareas[noTarea].titulo, (tareas[noTarea].completo == 0) ? "Pendiente" : "Completada");
    }
            else if(opc==2){ system(CLEAR_SCREEN);}
            else if(opc==3){printf("Volviendo al menu.");}
            else{printf("Error en la entrada de datos.\n");}
            }while (opc!=3 && opc!=1);
}
//---------------------------------------------------------------------------
//esta funcion sirve para mostrar todas las tareas pendientes
void listarPentdientes(struct tarea tareas[], int contadorTareas){
for (int i=0; i<contadorTareas;i++){
    if(tareas[i].completo == 0){printf("%d. %s - %s\n", i + 1, tareas[i].titulo, (tareas[i].completo == 0) ? "Pendiente" : "Completada");}
}
}
//---------------------------------------------------------------------------
//esta funcion muestra todas la tareas y su estado actual
void listarTodas(struct tarea tareas[], int contadorTareas){
    for (int i=0; i<contadorTareas;i++){
            printf("%d. %s - %s\n", i + 1, tareas[i].titulo, (tareas[i].completo == 0) ? "Pendiente" : "Completada");
    }
}
//---------------------------------------------------------------------------
// esta función recursiva permite buscar una tarea por su nombre
void buscar(struct tarea tareas[], int indice, int contadorTareas, char busqueda[]) {
    if(indice<=contadorTareas){
            if(strcmp(tareas[indice].titulo,busqueda)!=0){buscar(tareas,indice+1, contadorTareas, busqueda);}
            else{printf("%d. %s - %s\n", indice + 1, tareas[indice].titulo, (tareas[indice].completo == 0) ? "Pendiente" : "Completada");}}
    else{printf("Tarea no encontrada.");}
}
//---------------------------------------------------------------------------
#endif // CABECERA_H_INCLUDED
