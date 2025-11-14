#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu(){
    printf("-------------GESTION DE PRODUCCION---------------\n\n");

    printf("--- I. GESTION DE PRODUCTOS Y ESPECIFICACIONES ---\n\n");
    printf("1. **Agregar** Nuevo Producto\n");
    printf("2. **Editar** las Especificaciones de un producto\n");
    printf("3. **Eliminar** un Producto\n\n");

    printf("--- II. DEFINICION DE REQUERIMIENTOS ---\n\n");
    
    printf("4. Establecer **Tiempo** de Fabricacion (min)\n");
    printf("5. Establecer **Recursos** Necesarios\n");
    printf("6. Establecer **Demanda** de un Producto\n\n");
    
    printf("--- III. CALCULOS Y ANALISIS DE CAPACIDAD ---\n\n");
    
    printf("7. **Calcular** Tiempo Requerido para Cumplir la Demanda\n");
    printf("8. **Calcular** Recursos Totales Necesarios para la Produccion\n");
    printf("9. **Estimar** Cumplimiento de demanda (con Limites de Tiempo/Recursos) \n\n");
    
    printf("--- IV. FINALIZAR ---\n\n");

    printf("10. Salir\n");
    printf("-------------------------------------------------\n");
    printf(">> ");

}
void limpiar_Buffer(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

int LeerNum(void){
    int opcion;
    while (scanf("%d",&opcion) != 1) {
            while (getchar() != '\n');
            printf("**Error, Ingrese un digito valido.**\n");
            printf("**Intente nuevamente.**\n>> ");
        } 
    return opcion;
}

float LeerFloat(){
    float valor;

    while (1){
        if (scanf("%f", &valor) == 1){
            break; // Entrada válida
        }
        else{
            limpiar_Buffer();// Limpiar buffer
            printf("**Error, Ingrese un numero valido.**\n>> ");
        }
    }

    return valor;
}

void LeerChar(char cadena[]){
    fgets(cadena, 30, stdin);     // Leer 
    int lan = strlen(cadena) - 1; // Encontrar el "\n"
    cadena[lan] = '\0';           // Reemplazar el "\n" por "\0"
}

int NoRepeat(char nombre[][30], int cont, const char *nuevo, int skipIndex){
    for (int i = 0; i < cont; ++i) {
        if (i == skipIndex) continue;
        if (strcmp(nombre[i], nuevo) == 0) return 1; // ya existe
    }
    return 0; // no existe
}