#ifndef PROGRAMAPOLIPIANO_H_INCLUDED
#define PROGRAMAPOLIPIANO_H_INCLUDED

void poliPianoProgramaPc(BITMAP *buffer,BITMAP *blocBlanco,
        SAMPLE *do1,SAMPLE *re1,SAMPLE *mi1,SAMPLE *fa1,SAMPLE *sol1,SAMPLE *la1,SAMPLE *si1,
        SAMPLE *do2,SAMPLE *re2,SAMPLE *mi2,SAMPLE *fa2,SAMPLE *sol2,SAMPLE *la2,SAMPLE *si2,
        SAMPLE *do3,SAMPLE *re3,SAMPLE *mi3,SAMPLE *fa3,SAMPLE *sol3,SAMPLE *la3,SAMPLE *si3)
{
    /**Programa para generar musica de un archivo leido*/
    char titulo[30];
    blit(blocBlanco,screen,0,240,50,30,261,264);
    textprintf_ex(screen,font,55,37,makecol(0,0,0),-1,"Archivo: ");
    generarArchivoTxt(120,37,titulo);
    archivoMusical(titulo,do1,re1,mi1,fa1,sol1,la1,si1,do2,re2,mi2,fa2,sol2,la2,si2,do3,re3,mi3,fa3,sol3,la3,si3);
}

#endif // PROGRAMAPOLIPIANO_H_INCLUDED
