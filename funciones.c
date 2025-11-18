#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define longitudChar 30
void menu(){
    printf("-------------GESTION DE PRODUCCION---------------\n\n");

    printf("--- I. GESTION DE PRODUCTOS Y REQUERIMIENTOS ---\n\n");
    printf("1. **Agregar** Nuevo Producto (max 5)\n");
    printf("2. Agregar **Recursos** (max 3)\n");
    printf("3. Establecer **Recursos Fijos** por Producto\n");
    printf("4. Establecer **Tiempo** de Fabricacion (horas)\n");
    printf("5. Visualizar Inventario\n");
    printf("6. Abastecer/Desabastecer **Recursos**\n");

    printf("--- II. CALCULOS Y ANALISIS DE CAPACIDAD ---\n\n");
    
    printf("7. **Calcular** Tiempo Requerido para Cumplir una Demanda\n");
    printf("8. **Calcular** Recursos Totales Necesarios para la Produccion\n");
    printf("9. **Estimar** Cumplimiento de demanda (con Limites de Tiempo/Recursos) \n\n");
    
    printf("--- III. EDICION ---\n\n");
    printf("10. **Editar** Editar un producto\n");
    printf("11. **Eliminar** Un producto\n\n");
    
    printf("--- IV. FINALIZAR ---\n\n");

    printf("12. Salir\n");
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
    fgets(cadena, longitudChar, stdin);     // Leer 
    int lan = strlen(cadena) - 1; // Encontrar el "\n"
    cadena[lan] = '\0';           // Reemplazar el "\n" por "\0"
}

int NoRepeat(char nombre[][longitudChar], int cont, const char *nuevo, int skipIndex){
    for (int i = 0; i < cont; ++i) {
        if (i == skipIndex) continue;
        if (strcmp(nombre[i], nuevo) == 0) return 1; // ya existe
    }
    return 0; // no existe
}
int blanco(char *cadena){
    if (cadena[0] == '\0') return 1;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ' && cadena[i] != '\t') {
            return 0; // No está en blanco
        }
    }
    return 1; // Está en blanco
}