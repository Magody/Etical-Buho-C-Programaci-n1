#ifndef PROGRAMAFSOCIETY_H_INCLUDED
#define PROGRAMAFSOCIETY_H_INCLUDED

int factorial(int num)
{
    int fact=1,i;
    for(i=2;i<=num;i++)
        fact *= i;
    return fact;
}

int compararPassword(char permutado[])
{
    int bandera = 0,i;
    for(i=0;i<numVictima;i++)
    {
        if(strcmp(Victimas[i].password,permutado)==0)
        {
            bandera=1;
            break;
        }
    }
    return bandera;
}

void permutaciones(char *conjunto, int longitud, int pos,int posXInicioBloc,int espacioXCaracter,int posYInicioBloc,int espacioV,
                   int espacioH,int espacioYCaracter,int *contador,int fact,char palabraClave[],int *bandera)
{

    if (longitud > 1)
    {
        int i;

        permutaciones(conjunto, longitud - 1, pos + 1,posXInicioBloc,espacioXCaracter,posYInicioBloc,espacioV,espacioH,
                      espacioYCaracter,contador,fact,palabraClave,bandera);

        for (i = 1; i < longitud; i++)
        {
            char temp;

            temp = conjunto[pos + i];
            memmove(conjunto + pos + 1, conjunto + pos, i);
            conjunto[pos] = temp;

            permutaciones(conjunto, longitud - 1, pos + 1,posXInicioBloc,espacioXCaracter,posYInicioBloc,
                          espacioV,espacioH,espacioYCaracter,contador,fact,palabraClave,bandera);

            memmove(conjunto + pos, conjunto + pos + 1, i);
            conjunto[pos + i] = temp;

        }

    }
    else
    {
        if(*bandera == 0)
        {
            printf("%s\t",conjunto);
            textprintf_ex(screen,font,posXInicioBloc+(espacioH*espacioXCaracter)+9,posYInicioBloc+((espacioV+1)*espacioYCaracter),
                              makecol(255,0,0),30," ");
            textprintf_ex(screen,font,posXInicioBloc+(espacioH*espacioXCaracter)+9,posYInicioBloc+((espacioV+1)*espacioYCaracter),
                              makecol(255,0,0),30,"%d de %d",*contador,fact);

            textprintf_ex(screen,font,posXInicioBloc+(espacioH*espacioXCaracter)+9,posYInicioBloc+((espacioV+2)*espacioYCaracter),
                              makecol(255,0,0),30,"%s",conjunto);
            *contador = *contador + 1;
            if(compararPassword(conjunto))
            {
                *bandera = 1;

                textprintf_ex(screen,font,posXInicioBloc+(espacioH*espacioXCaracter)+9,posYInicioBloc+((espacioV+3)*espacioYCaracter),
                              makecol(200,0,50),30,"ENCONTRADO");
                strcpy(palabraClave,conjunto);

            }

            Sleep(10);
        }


    }

}



void escribirComandos(BITMAP *buffer,char urlArchivo[])
{
    int i,j,pos;char tecla;char comando[160];
    char palabra1[20],palabra2[80],palabra3[20],palabra4[20],palabra5[20];
    ///Señala margenes del bloc,limites
    int posXInicioBloc = 50;
    int posYInicioBloc = 30;
    int finMargenBloc = 295;

    ///Separacion entre letras
    int espacioXCaracter = 9;
    int espacioYCaracter = 10;

    ///para validar si fue una tecla comun o especial, ejemplo Enter es especial
    int caracterEspecial=0;


    FILE *Script = fopen(urlArchivo,"w");

    while(tecla!=13)
    {
        for(pos=0,i=0,j=1; tecla!=13;i++)
        {
            tecla = readkey();

            ///borrar letra: 8 es backspace
            if(tecla == 8)
            {
                textprintf_ex(screen,font,posXInicioBloc+((i)*espacioXCaracter),posYInicioBloc+(j*espacioYCaracter),makecol(0,0,0),0," ");
                caracterEspecial = 1;
                comando[--pos] = ' ';
                i-=2;
            }

            ///enter
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
                ///imprime letras en tiempo real siempre y cuando no sea caracter especial
                textprintf_ex(screen,font,posXInicioBloc+(i*espacioXCaracter)+9,posYInicioBloc+(j*espacioYCaracter),makecol(0,250,0),30,"%c",tecla);
            }
            else
                caracterEspecial = 0;
            if(tecla != 8)
                comando[pos++] = tecla;
        }
        comando[pos] = '@';
        comando[pos+1] = '\0';
        extraerPalabrasDeTexto(palabra1,palabra2,palabra3,palabra4,palabra5,comando);
        printf("\n%s",comando);

        if(strcmp(palabra1,"/system")==0)
        {

            if(strcmp(palabra2,"copy")==0)
            {

                //copy /b 1.jpg + 2.rar 3.jpg
                strcat(palabra2," ");strcat(palabra2,palabra3);strcat(palabra2," ");
                strcat(palabra2,palabra4); strcat(palabra2," "); strcat(palabra2,palabra5);
                system(palabra2);

            }

            if(strcmp(palabra2,"fc")==0)
            {
                //fc /b a.txt b.txt
                strcat(palabra2," ");strcat(palabra2,palabra3);strcat(palabra2," ");
                strcat(palabra2,palabra4); strcat(palabra2," "); strcat(palabra2,palabra5);

                system(palabra2);
            }

            if(strcmp(palabra2,"start")==0 || strcmp(palabra2,"color")==0 || strcmp(palabra2,"ping")==0 ||
               strcmp(palabra2,"tracert")==0)
            {
                system(strcat(strcat(palabra2," "),palabra3)); ///ejecuta una operacion de system();
            }
        }
        fputs(comando,Script);
        if(strcmp(palabra1,"/permutar")==0)
        {
            int contador=1; int bandera = 0;
            char palabraClave[20];
            //pedirDato(j,palabraClave);


            strcat(palabra2,palabra3);
            permutaciones(palabra2,strlen(palabra2),0,posXInicioBloc,espacioXCaracter,posYInicioBloc,j,i,espacioYCaracter,
                          &contador,factorial(strlen(palabra2)),palabraClave,&bandera);

            fputs(palabraClave,Script);
            Sleep(5000);

        }


    }

    fclose(Script);
}

void fsocietyPrograma(BITMAP *buffer,BITMAP *fondoScript,BITMAP *fondoBlanco)
{
    /**Pise un titulo y genera ese archivo txt*/
    char titulo[30];
    clear_keybuf();
    fflush(stdin);
    blit(fondoScript,screen,0,0,50,10,261,264);
    blit(fondoBlanco,screen,0,240,50,10,261,264);
    textprintf_ex(screen,font,55,15,makecol(0,0,0),-1,"Titulo: ");
    generarArchivoTxt(140,15,titulo);

    escribirComandos(buffer,titulo);
}
#endif // PROGRAMAFSOCIETY_H_INCLUDED
