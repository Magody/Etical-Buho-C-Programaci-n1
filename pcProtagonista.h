#ifndef PCPROTAGONISTA_H_INCLUDED
#define PCPROTAGONISTA_H_INCLUDED

#include "programaPoliPiano.h"
#include "programaBloc.h"
#include "programaFsociety.h"
#include "ProgramaDelfinQuishpeSQLmasmas.h"

void computadoraEncendida(BITMAP *buffer,BITMAP *fondo,BITMAP *cursor,BITMAP *bloc,BITMAP *blocBlanco,BITMAP *pantallaSalida,int ANCHO,int ALTO,char urlArchivo[],BITMAP *barraEstadisticas,
      SAMPLE *do1,SAMPLE *re1,SAMPLE *mi1,SAMPLE *fa1,SAMPLE *sol1,SAMPLE *la1,SAMPLE *si1,
      SAMPLE *do2,SAMPLE *re2,SAMPLE *mi2,SAMPLE *fa2,SAMPLE *sol2,SAMPLE *la2,SAMPLE *si2,
      SAMPLE *do3,SAMPLE *re3,SAMPLE *mi3,SAMPLE *fa3,SAMPLE *sol3,SAMPLE *la3,SAMPLE *si3,SAMPLE *mrRobot)
{
    int menuSalida = 0;

    while(1)
    {
        blit(fondo,buffer,0,0,0,0,ANCHO,ALTO);
        blit(barraEstadisticas,buffer,0,0,0,0,1000,26); imprimirEstadisticas(buffer);


        ///en caso de que haya clickeado la parte inferior izquierda y vaya a salir
        if(menuSalida)
            blit(pantallaSalida,buffer,0,0,0,197,293,372);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);


        ///Programa: programaBloc
        if(detectarPosicionPixeles(13,94,26,112,mouse_x,mouse_y))
        {
            if(mouse_b & 1)
            {
                clear_keybuf();
                blocNote(buffer,blocBlanco);
            }
        }

        ///Programa: programaPoliPiano
        if(detectarPosicionPixeles(25,25+67,138,138+129,mouse_x,mouse_y))
        {
            if(mouse_b & 1)
            {
                stop_sample(mrRobot);
                clear_keybuf();
                poliPianoProgramaPc(buffer,blocBlanco,do1,re1,mi1,fa1,sol1,la1,si1,do2,re2,mi2,fa2,sol2,la2,si2,do3,re3,mi3,fa3,sol3,la3,si3);
                play_sample(mrRobot,volumen,127,1000,1);
            }
        }

        ///Programa: SQL
        if(detectarPosicionPixeles(13,13+98,284,284+92,mouse_x,mouse_y))
        {
            if(mouse_b & 1)
            {
                stop_sample(mrRobot);
                clear_keybuf();
                SQL();
                play_sample(mrRobot,volumen,127,1000,1);
            }
            clear_keybuf();
        }

        ///Programa: programaFsociety
        if(detectarPosicionPixeles(33,102,396,490,mouse_x,mouse_y))
        {

            if(mouse_b & 1)
            {
                clear_keybuf();
                fsocietyPrograma(buffer,bloc,blocBlanco);
            }
        }

        ///SALIDA: click en la parte inferior izquierda y luego en apagar
        if(detectarPosicionPixeles(1,35,568,600,mouse_x,mouse_y))
        {
            if(mouse_b & 1)
            {
                printf("\nmenu generado");
                if(menuSalida)
                    menuSalida = 0;
                else
                    menuSalida = 1;

                Sleep(200);

            }
        }

        if(menuSalida) ///si la imagen del menu de salida esta abierto
        {
            ///si se da click en el boton "apagar"
            if(detectarPosicionPixeles(174,220,544,563,mouse_x,mouse_y))
            {
                if(mouse_b & 1)
                {
                    stop_sample(mrRobot);
                    break;
                }

            }
        }

        blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
    }
    clear_keybuf();
}

#endif // PCPROTAGONISTA_H_INCLUDED
