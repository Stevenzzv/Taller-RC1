#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu(){
    printf("-------------MENU---------------\n");
    printf("1. Agregar Productos\n");
    printf("2. Agregar Tiempo de Fabricación y Recursos por Producto\n");
    printf("3. Agregar Recursos Necesarios por Producto\n");
    printf("4. Editar Producto\n");
    printf("5. Eliminar Producto\n");
    printf("6. Salir\n");
    printf("--------------------------------\n");
    printf(">> ");

}
int Leer(void){
    int opcion;
    while (scanf("%d",&opcion) != 1) {
            while (getchar() != '\n');
            printf("**Error, Ingrese un digito valido.**\n");
            printf("**Intente nuevamente.**\n");
            printf(">> ");
        } 
    return opcion;
}
void selector(int opcion){
    switch (opcion)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        printf("Gracias...\n");
        break;
    
    
    default:
        printf("**Elige un numero dentro de (1-6)**\n");
        printf("Intentalo nuevamente...\n");
        break;
    }
}