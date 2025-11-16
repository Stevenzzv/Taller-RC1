#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
  char productos[5][30] = {0};
  char recursos[3][30] = {0};
  float recursosP [5][3] = {0};
  float tiempo[5] = {0};
  float demanda[5] = {0};
  int opcion = 0;
  int contador = 0;  // ← cuántos productos hay
  int cantidadRecursos = 0; // ← cuántos recursos hay
  int continuar = 1;

  do{
    if (continuar == 0)
    {
      opcion=11;
    }
    else {
    menu();
    opcion = LeerNum();
    }
    switch (opcion)
    {
    case 1: //Establecer recursos necesarios (tipos, max 3)
    if (cantidadRecursos >= 3) {
      printf("Capacidad maxima de recursos alcanzada.\n");
      printf("No se pueden agregar mas recursos.\n");
      printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
      continuar = LeerNum();
      break;
    }
    char nuevoRecurso[30]; // Temporal para verificar repetidos
    printf("Ingrese el nombre del recurso %d: ", cantidadRecursos + 1);
    limpiar_Buffer();
    LeerChar(nuevoRecurso);
    if ((NoRepeat(recursos, cantidadRecursos, nuevoRecurso, -1))==1) {
      printf("**Error: Recurso ya existente.**\n");
      printf("No se agrego el recurso.\n");
      printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
      continuar = LeerNum();
      break;
    }
    else if (blanco(nuevoRecurso)==1) {
      printf("**Error: Nombre de recurso invalido.**\n");
      printf("No se agrego el recurso.\n");
      printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
      continuar = LeerNum();
      break;
    }
    else {
      strcpy(recursos[cantidadRecursos], nuevoRecurso);
    }
    

    cantidadRecursos++;
    printf("Recurso agregado exitosamente.\n"); 

    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;  
    case 2: // Agregar producto (max 5)
    if (contador < 5) {
      printf("Ingrese el nombre del producto: ");
      limpiar_Buffer();
      LeerChar(productos[contador]);
      contador++;
      printf("Producto agregado exitosamente.\n");
    } else {
      printf("Capacidad maxima de productos alcanzada.\n");
    }
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    
    case 3: //Establecer recursos por producto
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 4: //Establecer tiempo de fabricacion
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 5: //Establecer demanda de un producto
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 6: //Calcular tiempo requerido para cumplir la demanda
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 7:// Calcular recursos totales necesarios
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 8: // Estimar cumplimiento de demanda
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;

    case 9: // Editar producto
    printf("Seleccione el producto a editar:\n");
    for (int i = 0; i < contador; i++)
    {
      printf("%d. %s\n", i + 1, productos[i]);
    }
    printf(">> ");
    int prodIndex = LeerNum() - 1;
    while (prodIndex < 0 || prodIndex >= contador) {
      printf("**Seleccion invalida.**\n");
      printf("Intentelo nuevamente.\n");
      printf(">> ");
      prodIndex = LeerNum()-1;
    }
    printf("Has seleccionado editar: %s\n", productos[prodIndex]);
    //printf("Que especificacion desea editar?\n");
    //printf("1. Nombre del producto\n");
    //printf(">> ");
    
    
    
    if (prodIndex >= 0 && prodIndex < contador) {
      printf("Ingrese el nuevo nombre para %s: ", productos[prodIndex]);
      limpiar_Buffer();
      LeerChar(productos[prodIndex]);
      
      
      
      printf("Producto editado exitosamente a %s.\n", productos[prodIndex]);
    } else {
      printf("Seleccion invalida.\n");
    }
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;

    case 10: // Editar las especificaciones de un producto
    printf("Funcionalidad en desarrollo...\n");
    printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
    continuar = LeerNum();
    break;
    case 11: //Salir
    printf("Gracias...\n");
    break;
    
    
    default:
    printf("**Elige un numero dentro de (1-6)**\n");
    printf("Intentalo nuevamente...\n");
        break;
    }

  } while (opcion != 11);

  return 0;
}
