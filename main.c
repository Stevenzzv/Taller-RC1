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
    selector(opcion);
  } while (opcion != 10);

  return 0;
}
