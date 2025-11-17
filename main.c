#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

int main()
{
  char productos[5][30] = {0};
  char recursos[3][30] = {0};
  int recursosP [5][3] = {0}; // recursos por producto
  int tiempo[5] = {0};
  int demanda[5] = {0};
  int opcion = 0;
  int contador = 0;  // ← cuántos productos hay
  int cantidadRecursos = 0; // ← cuántos recursos hay
  int RecursosDisponibles[3] = {0};
  int continuar = 1;

  do{
    if (continuar != 0)
    {
    menu();
    opcion = LeerNum();
    }
    switch (opcion)
    {
      case 1: // Agregar producto (max 5)
      if (contador < 5) {
        printf("Ingrese el nombre del producto: ");
        limpiar_Buffer();
        char nombreProducto[30];
        LeerChar(nombreProducto);
        if (blanco(nombreProducto)==1) {
          printf("**Error: Nombre del producto en blanco.**\n");
          printf("No se agrego el producto.\n");
          break;
        }
        else if ((NoRepeat(productos, contador, nombreProducto, -1))==1) {
          printf("**Error: Producto ya existente.**\n");
          printf("No se agrego el producto.\n");
          break;
        }
        else {
          strcpy(productos[contador], nombreProducto);
        }
        contador++;
        printf("Producto agregado exitosamente.\n");
      } else {
        printf("Capacidad maxima de productos alcanzada.\n");
      }
    
      break;
    case 2: //Establecer recursos necesarios (tipos, max 3)
    if (cantidadRecursos >= 3) {
      printf("**Error: Capacidad maxima de recursos alcanzada.**\n");
      printf("No se pueden agregar mas recursos.\n");
      break;
    }
    char nuevoRecurso[30]={0}; // Temporal para verificar repetidos
    printf("Ingrese el nombre del recurso %d: ", cantidadRecursos + 1);
    limpiar_Buffer();
    LeerChar(nuevoRecurso);
    if (blanco(nuevoRecurso)==1) {
      printf("**Error: Nombre de recurso en blanco.**\n");
      printf("No se agrego el recurso.\n");
      break;
    }
    else if ((NoRepeat(recursos, cantidadRecursos, nuevoRecurso, -1))==1) {
      printf("**Error: Recurso ya existente.**\n");
      printf("No se agrego el recurso.\n");
      break;
    }
    else {
      strcpy(recursos[cantidadRecursos], nuevoRecurso);
    }
    
    
    cantidadRecursos++;
    printf("Recurso agregado exitosamente.\n"); 
    
    break;  
    
    case 3: //Establecer recursos por producto
    printf("Seleccione el producto a configurar:\n");
    for (int i = 0; i < contador; i++)
    {
      printf("%d. %s\n", i + 1, productos[i]);
    }
    printf(">> ");
    int pIndex = LeerNum() - 1;
    while (pIndex < 0 || pIndex >= contador) {
      printf("**Seleccion invalida.**\n");
      printf("Intentelo nuevamente.\n");
      printf(">> ");
      pIndex = LeerNum()-1;
    }
    printf("Has seleccionado: %s\n", productos[pIndex]);
    for (int j = 0; j < cantidadRecursos; j++)
    {
      printf("Ingrese la cantidad de %s necesaria para fabricar %s: ", recursos[j], productos[pIndex]);
      recursosP[pIndex][j] = LeerNum();
    }
    
    break;
    case 4: //Establecer tiempo de fabricacion
    printf("Seleccione el producto a configurar:\n");
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
    printf("Has seleccionado: %s\n", productos[prodIndex]);
    printf("Ingrese el tiempo en horas de fabricacion para %s: ", productos[prodIndex]);
    tiempo[prodIndex] = LeerNum();
    
    break;
    case 5: //Visualizar inventario
    printf("----- INVENTARIO DE PRODUCTOS -----\n\n");
    printf("Cantidad de recursos registrados: %d\n", cantidadRecursos);
    for (int i = 0; i < cantidadRecursos; i++)
    {
      printf("Recurso %d: %s (Disponibles: %d)\n", i + 1, recursos[i], RecursosDisponibles[i]);
    }
    printf("Cantidad de productos registrados: %d\n\n", contador);
    for (int i = 0; i < contador; i++)
    {
      printf("---------------------------------\n");
      printf("Producto %d: %s\n\n", i + 1, productos[i]);
      printf("  Tiempo de fabricacion: %d horas\n", tiempo[i]);
      printf("  **Recursos necesarios para fabricacion**:\n");
      for (int j = 0; j < cantidadRecursos; j++)
      {
        printf("    %s: %d unidades\n", recursos[j], recursosP[i][j]);
      }
      printf("  **Recursos disponibles**:\n");
      for (int j = 0; j < cantidadRecursos; j++)
      {
        printf("    %s: %d unidades\n", recursos[j], RecursosDisponibles[j]);
      }
      printf("---------------------------------\n");
    }
    break;
    case 6: // Abastecer/Desabastecer recursos
    printf("Seleccione la operacion:\n");
    printf("1. Abastecer Recursos\n");
    printf("2. Desabastecer Recursos\n");
    printf("3. Salir\n");
    printf(">> ");
    int operacion = LeerNum();
    if (operacion < 1 || operacion > 3) {
      printf("**Seleccion invalida.**\n");
      printf("Operacion cancelada.\n");
      break;
    }
    if (operacion == 3) {
      break;
    }
    printf("Seleccione el recurso a modificar:\n");
    for (int i = 0; i < cantidadRecursos; i++)
    {
      printf("%d. %s (Disponibles: %d)\n", i + 1, recursos[i], RecursosDisponibles[i]);
    }
    printf(">> ");
    int rIndex = LeerNum() - 1;
    while (rIndex < 0 || rIndex >= cantidadRecursos) {
      printf("**Seleccion invalida.**\n");
      printf("Intentelo nuevamente.\n");
      printf(">> ");
      rIndex = LeerNum()-1;
    }
    int cantidad = 0;
    printf("Has seleccionado: %s\n", recursos[rIndex]);
    if (operacion == 1) {
      printf("Ingrese la cantidad a abastecer: ");
      cantidad = LeerNum();
      if (cantidad < 0) {
        printf("**Error: Cantidad negativa invalida.**\n");
        printf("Operacion no realizada.\n");
        break;
      }
      else {
        RecursosDisponibles[rIndex] += cantidad;
        printf("Recurso abastecido exitosamente. Cantidad actual de %s es de: %d\n", recursos[rIndex], RecursosDisponibles[rIndex]);
      }
    }
    if (operacion == 2) {
      printf("Ingrese la cantidad a desabastecer: ");
      cantidad = LeerNum();
      if (cantidad < 0) {
        printf("**Error: Cantidad negativa invalida.**\n");
        printf("Operacion no realizada.\n");
        break;
      }
      else if (cantidad > RecursosDisponibles[rIndex]) {
        printf("**Error: No hay suficientes recursos disponibles para desabastecer esa cantidad.**\n");
        printf("Operacion no realizada.\n");
      }
      else if (RecursosDisponibles[rIndex]>=cantidad) {
        RecursosDisponibles[rIndex] -= cantidad;
        printf("Recurso desabastecido exitosamente. Cantidad actual de %s es de: %d\n", recursos[rIndex], RecursosDisponibles[rIndex]);
      }
    }
    
    
    
    break;
    case 7: // Calcular tiempo requerido para cumplir demanda
    demanda[0] = 0; demanda[1] = 0; demanda[2] = 0; demanda[3] = 0; demanda[4] = 0; // Reiniciar demandas
    printf("Ingrese la demanda para cada producto:\n");
    for (int i = 0; i < contador; i++)
    {
      printf("%s: ", productos[i]);
      demanda[i] = LeerNum();
      while (demanda[i]<0)
      {
        printf("**Error: Demanda no puede ser negativa.**\n");
        printf("Intente nuevamente.\n");
        printf("%s: ", productos[i]);
        demanda[i] = LeerNum();
      }
    }
    int tiempoTotal = 0;
    for (int i = 0; i < contador; i++)
    {
      tiempoTotal += tiempo[i] * demanda[i];
    }
    printf("\n--- Tiempo Requerido para Cumplir la Demanda ---\n");
    printf("Tiempo total requerido: %d horas\n", tiempoTotal);
    
    
    break;
    case 8:// Calcular recursos totales necesarios
    demanda[0] = 0; demanda[1] = 0; demanda[2] = 0; demanda[3] = 0; demanda[4] = 0; // Reiniciar demandas
    printf("Ingrese la demanda para cada producto:\n");
    for (int i = 0; i < contador; i++)
    {
      printf("%s: ", productos[i]);
      demanda[i] = LeerNum();
      while (demanda[i]<0)
      {
        printf("**Error: Demanda no puede ser negativa.**\n");
        printf("Intente nuevamente.\n");
        printf("%s: ", productos[i]);
        demanda[i] = LeerNum();
      }
    }
    printf("\n--- Recursos Totales Necesarios ---\n");
    for (int j = 0; j < cantidadRecursos; j++)
    {
      int totalRecurso = 0;
      for (int i = 0; i < contador; i++)
      {
        totalRecurso += recursosP[i][j] * demanda[i];
      }
      printf("%s: %d unidades\n", recursos[j], totalRecurso);
    }
    break;
    
    case 9: // Estimar cumplimiento de demanda
    {
      if (contador == 0) {
        printf("No hay productos registrados.\n");
        break;
      }
      // Leer demanda por producto
      printf("Ingrese la demanda para cada producto:\n");
      for (int i = 0; i < contador; i++) {
        printf("%s: ", productos[i]);
        demanda[i] = LeerNum();
        while (demanda[i] < 0) {
          printf("**Error: Demanda no puede ser negativa.**\n");
          printf("Intente nuevamente.\n");
          printf("%s: ", productos[i]);
          demanda[i] = LeerNum();
        }
      }

      // Tiempo disponible
      printf("Ingrese el limite de tiempo disponible (horas): ");
      int limiteTiempo = LeerNum();
      while (limiteTiempo < 0) {
        printf("**Error: Tiempo no puede ser negativo.**\n");
        printf("Intente nuevamente.\n");
        printf("Ingrese el limite de tiempo disponible (horas): ");
        limiteTiempo = LeerNum();
      }

      // Calcular tiempo total necesario
      int tiempoNecesario = 0;
      for (int i = 0; i < contador; i++) {
        tiempoNecesario += tiempo[i] * demanda[i];
      }

      // Calcular recursos totales necesarios por tipo
      int recursosNecesarios[3] = {0, 0, 0};
      for (int j = 0; j < cantidadRecursos; j++) {
        int total = 0;
        for (int i = 0; i < contador; i++) {
          total += recursosP[i][j] * demanda[i];
        }
        recursosNecesarios[j] = total;
      }

      // Mostrar resumen y comparar con disponibles
      printf("\n--- Estimacion de Cumplimiento de Demanda ---\n");
      printf("Tiempo necesario: %d horas | Tiempo disponible: %d horas\n", tiempoNecesario, limiteTiempo);

      int tiempo_ok = (tiempoNecesario <= limiteTiempo);
      if (tiempo_ok) {
        printf("Tiempo: suficiente.\n");
      } else {
        printf("Tiempo: insuficiente. Falta: %d horas\n", tiempoNecesario - limiteTiempo);
      }

      int recursos_ok = 1;
      if (cantidadRecursos == 0) {
        printf("No hay tipos de recurso definidos.\n");
      } else {
        printf("\nRecursos necesarios vs disponibles:\n");
        for (int j = 0; j < cantidadRecursos; j++) {
          printf("  %s: necesita %d | disponible %d", recursos[j], recursosNecesarios[j], RecursosDisponibles[j]);
          if (recursosNecesarios[j] <= RecursosDisponibles[j]) {
            printf(" -> SI SE PUEDE\n");
          } else {
            printf(" -> FALTAN %d\n", recursosNecesarios[j] - RecursosDisponibles[j]);
            recursos_ok = 0;
          }
        }
      }

      if (tiempo_ok && recursos_ok) {
        printf("\n LA FABRICA PUEDE CUMPLIR CON LA DEMANDA\n");
      } else {
        printf("\n NO SE PUEDE CUMPLIR LA DEMANDA. Detalles arriba.\n");
      }
    }
    break;

    case 10: // Eliminar producto
    printf("Seleccione el producto a eliminar:\n");
    for (int i = 0; i < contador; i++)
    {
      printf("%d. %s\n", i + 1, productos[i]);
    }
    printf(">> ");
    int delIndex = LeerNum() - 1;
    while (delIndex < 0 || delIndex >= contador) {
      printf("**Seleccion invalida.**\n");
      printf("Intentelo nuevamente.\n");
      printf(">> ");
      delIndex = LeerNum()-1;
    }
    printf("Has seleccionado eliminar: %s\n", productos[delIndex]);
    if (delIndex >= 0 && delIndex < contador) {
      for (int i = delIndex; i < contador - 1; i++) {
        strcpy(productos[i], productos[i + 1]);
      }
      productos[contador - 1][0] = '\0'; // Limpiar el último
      contador--;
      printf("Producto eliminado exitosamente.\n");
    } else {
      printf("Seleccion invalida.\n");
    }
    break;
    case 11:

    break;
    case 12: //Salir
    printf("Gracias...\n");
    break;
    
    
    default:
    printf("**Elige un numero dentro de (1-11)**\n");
    printf("Intentalo nuevamente...\n");
        break;
    }
    if (opcion != 11) {
        printf("Desea volver al menú principal? (1: Si, 0: No)\n>> ");
        continuar = LeerNum();
        while (continuar != 0 && continuar != 1) {
          printf("**Error: Opcion invalida.**\n");
          printf("Ingrese 1 para volver al menu principal o 0 para salir.\n>> ");
          continuar = LeerNum();
        }
        if (continuar == 0) {
          printf("Gracias...\n");
          break;
        }
    }
  } while (opcion != 11);

  return 0;
}
