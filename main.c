#include <stdio.h>
#include <stdlib.h>

#include <allegro.h>
#include <winalleg.h>
#include <string.h>

#include "constantes.h"     ///constantes y struct: persona
#include "inicializacion.h" ///inicia componentes alegro y agrega estadisticas al pers. SE EJECUTA SOLO UNA VEZ
#include "jugabilidad.h"    ///funcion detectar posiciones en la pantalla ///movimiento del personaje con el teclado
#include "manejoArchivos.h" ///Para leer y escribir archivos
///tambien imprime estadisticas
#include "objetoPiano.h"    ///Funcion para piano del cuarto
#include "pcProtagonista.h" ///Las funciones del pc del protagonista
#include "pokiman.h"

char urlArchivo[] = "archivos/archivoDefecto.txt";

int main(){
    inicia_allegro(ANCHO,ALTO); ///Inicia Componentes necesarios
                            ///IMAGENES///
    BITMAP *buffer = create_bitmap(ANCHO,ALTO); ///lo que almacenara las demas imagenes
    BITMAP *cursor = load_bitmap("bitmaps/cursor.bmp",NULL); ///mouse
    ///protagonista
    BITMAP *personajeFrente = load_bitmap("bitmaps/protaFrente.bmp",NULL);
    BITMAP *personajeLadoDerecho = load_bitmap("bitmaps/protaLadoDerecho.bmp",NULL);
    BITMAP *personajeLadoIzquierdo = load_bitmap("bitmaps/protaLadoIzquierdo.bmp",NULL);
    BITMAP *personajeEspalda = load_bitmap("bitmaps/protaEspalda.bmp",NULL);
    BITMAP *barraEstadisticas = load_bitmap("bitmaps/barraEstadisticas.bmp",NULL);
    BITMAP *posicionPersonaje = personajeEspalda;
    ///Cuarto Protagonista
    BITMAP *menuPiano = load_bitmap("bitmaps/menu piano.bmp",NULL);
    BITMAP *cuartoProtagonista = load_bitmap("bitmaps/cuartoProtagonista1.bmp",NULL);
    ///Computadora
    BITMAP *fondoPc = load_bitmap("bitmaps/fondoPc.bmp",NULL);
    BITMAP *blocNegro = load_bitmap("bitmaps/blocNegro.bmp",NULL);
    BITMAP *blocBlanco = load_bitmap("bitmaps/blocBlanco.bmp",NULL);
    BITMAP *pantallaSalida = load_bitmap("bitmaps/pantallaSalida.bmp",NULL);


                                                        ///MUSICA///
    ///Tema fondo principal
    SAMPLE *ilusionistas = load_wav("musica/Now You See Me.wav");
    SAMPLE *mrRobot = load_wav("musica/MrRobotTheme.wav");
    SAMPLE *pokemon = load_wav("musica/Musica Pokemon.wav");
    play_sample(ilusionistas,volumen,127,1000,1); //atributos de play_sample(archivo,volumen<250,distribucion sonido derecha izquierda,rapidez milisegundos,repeticion)

                                                    ///Notas musicales para el piano
    ///ESCALA 1                                                         ESCALA 2                                                            ESCALA 3
    SAMPLE *do1 = load_wav("musica/notas musicales/escala1/do1.wav");   SAMPLE *do2 = load_wav("musica/notas musicales/escala2/do2.wav");   SAMPLE *do3 = load_wav("musica/notas musicales/escala3/do3.wav");
    SAMPLE *re1 = load_wav("musica/notas musicales/escala1/re1.wav");   SAMPLE *re2 = load_wav("musica/notas musicales/escala2/re2.wav");   SAMPLE *re3 = load_wav("musica/notas musicales/escala3/re3.wav");
    SAMPLE *mi1 = load_wav("musica/notas musicales/escala1/mi1.wav");   SAMPLE *mi2 = load_wav("musica/notas musicales/escala2/mi2.wav");   SAMPLE *mi3 = load_wav("musica/notas musicales/escala3/mi3.wav");
    SAMPLE *fa1 = load_wav("musica/notas musicales/escala1/fa1.wav");   SAMPLE *fa2 = load_wav("musica/notas musicales/escala2/fa2.wav");   SAMPLE *fa3 = load_wav("musica/notas musicales/escala3/fa3.wav");
    SAMPLE *sol1 = load_wav("musica/notas musicales/escala1/sol1.wav"); SAMPLE *sol2 = load_wav("musica/notas musicales/escala2/sol2.wav"); SAMPLE *sol3 = load_wav("musica/notas musicales/escala3/sol3.wav");
    SAMPLE *la1 = load_wav("musica/notas musicales/escala1/la1.wav");   SAMPLE *la2 = load_wav("musica/notas musicales/escala2/la2.wav");   SAMPLE *la3 = load_wav("musica/notas musicales/escala3/la3.wav");
    SAMPLE *si1 = load_wav("musica/notas musicales/escala1/si1.wav");   SAMPLE *si2 = load_wav("musica/notas musicales/escala2/si2.wav");   SAMPLE *si3 = load_wav("musica/notas musicales/escala3/si3.wav");


    establecerEstadisticasIniciales(); ///inicializa estadisticas del personaje

    system("mode con cols=40 lines=50");

    char dato[50];

    while(tecla!=27) ///mientras no sea ESC
    {
        blit(cuartoProtagonista,buffer,0,0,0,0,ANCHO,ALTO);
        masked_blit(posicionPersonaje,buffer,0,0,prota.posX,prota.posY,81,109);
        blit(barraEstadisticas,buffer,0,0,0,0,1000,26); imprimirEstadisticas(buffer);

        blit(buffer,screen,0,0,0,0,ANCHO,ALTO); ///imprime todo lo que se almacene en buffer

        tecla = readkey();

        ///actualiza la imagen del personaje y lo mueve
        if(tecla=='j' || tecla=='i' ||tecla=='k' ||tecla=='l'
           || tecla=='1'|| tecla=='2'|| tecla=='3'|| tecla=='5')
            posicionPersonaje = movimientoProtagonista(tecla,personajeEspalda,personajeLadoDerecho,personajeLadoIzquierdo,personajeFrente);



        ///Si llega a la posicion del piano
        if(detectarPosicionPixeles(467,517,67,137,prota.posX,prota.posY))
        {
            if(tecla=='a')
            {
                stop_sample(ilusionistas);
                clear_keybuf();
                masked_blit(menuPiano,screen,0,0,160,245,716,187);
                tecladoPiano(buffer,blocBlanco,do1,re1,mi1,fa1,sol1,la1,si1,do2,re2,mi2,fa2,sol2,la2,si2,do3,re3,mi3,fa3,sol3,la3,si3);
                play_sample(ilusionistas,volumen,127,1000,1);
            }

        }

        ///Si esta en la posicion de la computadora
        if(detectarPosicionPixeles(3,86,23,100,prota.posX,prota.posY))
        {
            if(tecla == 'a')
            {
                stop_sample(ilusionistas);
                play_sample(mrRobot,volumen,127,1000,1);
                printf("pc encendida!"); ///enviara todos los archivos necesarios
                computadoraEncendida(buffer,fondoPc,cursor,blocNegro,blocBlanco,pantallaSalida,ANCHO,ALTO,urlArchivo,barraEstadisticas,do1,
                                     re1,mi1,fa1,sol1,la1,si1,do2,re2,mi2,fa2,sol2,la2,si2,do3,re3,mi3,fa3,sol3,la3,si3,mrRobot);
                printf("\npc apagada");
                play_sample(ilusionistas,volumen,127,1000,1);
            }
        }

        ///Si esta en la gameboy
        if(detectarPosicionPixeles(452,452+86,350,350+74,prota.posX,prota.posY))
        {
            if(tecla == 'a')
            {
                stop_sample(ilusionistas);
                system("cls");
                play_sample(pokemon,volumen-50,127,1000,0);
                Sleep(3000);
                stop_sample(pokemon);
                pokiman();

                play_sample(ilusionistas,volumen,127,1000,1);
            }
        }


    }
    return 0;
}
END_OF_MAIN();
