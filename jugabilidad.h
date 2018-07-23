#ifndef JUGABILIDAD_H_INCLUDED
#define JUGABILIDAD_H_INCLUDED

int detectarPosicionPixeles(int xinicial,int xfinal, int yinicial,int yfinal,int posX,int posY)
{
    if(posX >= xinicial && posX <=xfinal && posY>=yinicial && posY <=yfinal)
        return 1;
    return 0;
}

BITMAP* movimientoProtagonista(char tecla,BITMAP *personajeEspalda,BITMAP *personajeLadoDerecho,
                               BITMAP *personajeLadoIzquierdo,BITMAP *personajeFrente)
{
    BITMAP *direccion;

    ///detecta limites del escenario y segun eso mueve al personaje y le da una imagen
    if(tecla == 'j' || tecla=='1')
    {

        direccion = personajeLadoIzquierdo;
        if(prota.posX>0 && (prota.posX<585 || prota.posY>167 || prota.posX>823)) ///colisiones
            prota.posX-=velocidad;  //izquierda
    }


    if(tecla == 'l' || tecla=='3')
    {
        direccion = personajeLadoDerecho;
        if(prota.posX<ANCHO-100 && (prota.posX<570 || prota.posY>167 || prota.posX>808))
            prota.posX+=velocidad;//derecha
    }

    if(tecla == 'i' || tecla=='5')
    {
        direccion = personajeEspalda;
        if(prota.posY>100 && (prota.posX<585 || prota.posY>180 || prota.posX>808))
            prota.posY-=velocidad;  //arriba
    }

    if(tecla == 'k' || tecla=='2')
    {
        direccion = personajeFrente;
        if(prota.posY<ALTO-100)
            prota.posY+=velocidad; //abajo

    }
    return direccion;
}
#endif // JUGABILIDAD_H_INCLUDED
