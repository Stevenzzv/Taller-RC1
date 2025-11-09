#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (){
  char productos[5][30]= {0};
  float tiempo [5] = {0};
  int opcion=0;

  do{
menu();
opcion=Leer();
selector(opcion);
  }while(opcion != 6);
  
  
  return 0;
}
