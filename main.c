#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
  char productos[5][30] = {0};
  float tiempo[5] = {0};
  int opcion = 0;

  do{
    menu();
    opcion = LeerNum();
    switch (opcion)
    {
    case 1: //Agregar nuevo producto

        break;
    case 2: // Editar las especificaciones de un producto

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
