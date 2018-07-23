#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

char tecla;

struct Persona
{
    char nombre[100];
    int posX,posY;
    int vida;
    int edad;
    int karma;
    int dinero;
    int id;
    char telefono[20];
    char password[20];
    char ciudad[20];
    char eliminado;

}prota,Victimas[15];

int personasActualizadas = 0;
int numVictima = 0;
char urlVictimas[] = "archivos/victimas.txt";
int ANCHO = 1000,ALTO = 600; ///tamaño de la pantalla
int volumen = 230; ///volumen por defecto
int velocidad=30; ///velocidad del personaje

#endif // CONSTANTES_H_INCLUDED
