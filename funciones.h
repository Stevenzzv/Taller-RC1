#ifndef FUNK_C
#define FUNK_C
#define longitudChar 30
#define PRODUCTOS_MAXIMOS 5
#define RECURSOS_MAXIMOS 3
void menu();
void LeerChar(char cadena[]);
float LeerFloat();
int LeerNum(void);
void limpiar_Buffer();
int NoRepeat(char nombre[][longitudChar], int cont, const char *nuevo, int skipIndex);
int blanco(char *cadena);

#endif