#ifndef PROGRAMABLOC_H_INCLUDED
#define PROGRAMABLOC_H_INCLUDED

void escrituraParaOcasion(BITMAP *buffer,BITMAP *bloc,char urlArchivo[])
{
    /**Permite escribir en un archivo y ver en tiempo real lo tecleado*/

    blit(bloc,screen,0,0,50,10,261,264);
    char texto[500];
    FILE *archivoBloc;

    char tecla = 'A';
    int p;

    int i,j;
    ///Señala margenes del bloc,limites
    int posXInicioBloc = 50;
    int posYInicioBloc = 30;
    int finMargenBloc = 295;

    ///Separacion entre letras
    int espacioXCaracter = 9;
    int espacioYCaracter = 10;

    ///para validar si fue una tecla comun o especial, ejemplo Enter es especial
    int caracterEspecial=0;

    archivoBloc = fopen(urlArchivo,"w");


    for(i=1,j=0,p=0; tecla!=27; i++)
    {
        tecla = readkey();


        ///si aplasta ESC el programa acaba
        if(tecla == 27)break;

        ///borrar letra: 8 es backspace
        if(tecla == 8)
        {

            textprintf_ex(screen,font,posXInicioBloc+((i-1)*espacioXCaracter),posYInicioBloc+(j*espacioYCaracter),makecol(0,0,0),0," ");
            texto[--p] = ' ';
            caracterEspecial = 1;
            i-=2;

        }

        ///Controla que no se desborde las letras
        if(tecla == 13)
        {
            j++;
            i=0; ///reinicia posicion en una nueva linea
            caracterEspecial=1;
        }
        else if(posXInicioBloc+(i*espacioXCaracter)>finMargenBloc)
        {
            j++;
            i=1;
        }


        if(caracterEspecial!=1)
        {
            ///imprime letras en tiempo real
            textprintf_ex(screen,font,posXInicioBloc+(i*espacioXCaracter),posYInicioBloc+(j*espacioYCaracter),makecol(0,200,200),30,"%c",tecla);
        }
        else
            caracterEspecial = 0;

        ///documenta el archivo generado en la carpeta "archivos"
        if(tecla != 8)
            texto[p++] = tecla;
    }
    texto[p] = '\0';
    fputs(texto,archivoBloc);
    fclose(archivoBloc);

}

void pedirDato(int posY,char dato[])
{
    char texto[500];

    char tecla = 'A';
    int p;

    int i;
    ///Señala margenes del bloc,limites
    int posXInicioBloc = 50;
    int posYInicioBloc = 30;


    ///Separacion entre letras
    int espacioXCaracter = 9;
    int espacioYCaracter = 10;

    ///para validar si fue una tecla comun o especial, ejemplo Enter es especial
    int caracterEspecial=0;



    for(i=1,p=0; tecla!=13; i++)
    {
        tecla = readkey();


        ///si aplasta ESC el programa acaba
        if(tecla == 13)break;

        ///borrar letra: 8 es backspace
        if(tecla == 8)
        {

            textprintf_ex(screen,font,posXInicioBloc+((i)*espacioXCaracter),posY*espacioYCaracter,makecol(0,0,0),0," ");
            texto[--p] = ' ';
            caracterEspecial = 1;
            i-=2;

        }



        if(caracterEspecial!=1)
        {
            ///imprime letras en tiempo real
            textprintf_ex(screen,font,posXInicioBloc+(i*espacioXCaracter),posYInicioBloc+(posY*espacioYCaracter),makecol(0,200,200),30,"%c",tecla);
        }
        else
            caracterEspecial = 0;

        ///documenta el archivo generado en la carpeta "archivos"
        if(tecla != 8)
            texto[p++] = tecla;
    }
    texto[p] = '\0';

    strcpy(dato,texto);
}

void escribirBloc(BITMAP *buffer,char urlArchivo[])
{
    /**Permite escribir en un archivo y ver en tiempo real lo tecleado*/

    char texto[500];
    FILE *archivoBloc;

    char tecla = 'A';
    int p;

    int i,j;
    ///Señala margenes del bloc,limites
    int posXInicioBloc = 50;
    int posYInicioBloc = 30;
    int finMargenBloc = 295;

    ///Separacion entre letras
    int espacioXCaracter = 9;
    int espacioYCaracter = 10;

    ///para validar si fue una tecla comun o especial, ejemplo Enter es especial
    int caracterEspecial=0;

    archivoBloc = fopen(urlArchivo,"wt");


    for(i=1,j=0,p=0; tecla!=27; i++)
    {
        tecla = readkey();


        ///si aplasta ESC el programa acaba
        if(tecla == 27)break;

        ///borrar letra: 8 es backspace
        if(tecla == 8)
        {

            textprintf_ex(screen,font,posXInicioBloc+((i-1)*espacioXCaracter),posYInicioBloc+(j*espacioYCaracter),makecol(0,0,0),makecol(255,255,255)," ");
            texto[--p] = ' ';
            caracterEspecial = 1;
            i-=2;

        }

        ///Controla que no se desborde las letras
        if(tecla == 13)
        {
            j++;
            i=0; ///reinicia posicion en una nueva linea
            caracterEspecial=1;
        }
        else if(posXInicioBloc+(i*espacioXCaracter)>finMargenBloc)
        {
            j++;
            i=1;
        }


        if(caracterEspecial!=1)
        {
            ///imprime letras en tiempo real
            textprintf_ex(screen,font,posXInicioBloc+(i*espacioXCaracter),posYInicioBloc+(j*espacioYCaracter),makecol(0,0,0),-1,"%c",tecla);
        }
        else
            caracterEspecial = 0;

        ///documenta el archivo generado en la carpeta "archivos"
        if(tecla != 8 && tecla != 13)
            texto[p++] = tecla;
        if(tecla == 13)
            texto[p++] = '\n';
    }
    texto[p] = '\0';
    fputs(texto,archivoBloc);
    fclose(archivoBloc);

}

void blocNote(BITMAP *buffer,BITMAP *bloc)
{
    /**Pide un titulo y genera un archivo txt*/
    char titulo[30];

    blit(bloc,screen,0,0,50,10,261,264);
    textout_ex(screen,font,"Titulo: ",55,15,makecol(0,0,0),-1);
    generarArchivoTxt(120,15,titulo);

    escribirBloc(buffer,titulo);
}


#endif // PROGRAMABLOC_H_INCLUDED
