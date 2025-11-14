#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
  char productos[5][30] = {0};
  char recursos[5][30] = {0};
  float tiempo[5] = {0};
  int opcion = 0;
  int contador = 0;  // ← cuántos productos hay
  do{
    menu();
    opcion = LeerNum();
    switch (opcion)
    {
    case 1: //Agregar nuevo producto
        if (contador < 5) {
            printf("Ingrese el nombre del producto: ");
            limpiar_Buffer();
            LeerChar(productos[contador]);
            contador++;
            printf("Producto agregado exitosamente.\n");
        } else {
            printf("Capacidad maxima de productos alcanzada.\n");
        }
        break;
    case 2: // Editar las especificaciones de un producto
          printf("Seleccione el producto a editar:\n");
          for (int i = 0; i < contador; i++)
          {
              printf("%d. %s\n", i + 1, productos[i]);
          }
          printf(">> ");
          int prodIndex = LeerNum() - 1;
          printf("Has seleccionado editar: %s\n", productos[prodIndex]);
          //printf("Que especificacion desea editar?\n");
          //printf("1. Nombre del producto\n");
          //printf(">> ");



          if (prodIndex >= 0 && prodIndex < contador) {
              printf("Ingrese el nuevo nombre para %s: ", productos[prodIndex]);
              limpiar_Buffer();
              LeerChar(productos[prodIndex]);
              if(strcmp(productos[prodIndex],"") == 0){
                  printf("Edicion cancelada, no se puede dejar en blanco el nombre.\n");
                  break;
              }
              
              
              printf("Producto editado exitosamente a %s.\n", productos[prodIndex]);
          } else {
              printf("Seleccion invalida.\n");
          }

        break;
    case 3: //Eliminar un producto

        break;
    case 4: //Establecer tiempo de fabricacion

        break;
    case 5: //Establecer recursos necesarios

        break;
    case 6: //Establecer demanda de un producto

        break;
    case 7:// Calcular tiempo requerido para cumplir la demanda

        break;
    case 8: //Calcular recursos totales necesarios para la produccion

        break;
    case 9: // Estimar cumplimiento de demanda (con limites de tiempo/recursos)

        break;
    case 10: //Salir
        printf("Gracias...\n");
        break;
    
    
    default:
        printf("**Elige un numero dentro de (1-6)**\n");
        printf("Intentalo nuevamente...\n");
        break;
    }

  } while (opcion != 10);

  return 0;
}
