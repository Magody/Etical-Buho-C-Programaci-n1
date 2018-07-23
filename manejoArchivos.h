#ifndef MANEJOARCHIVOS_H_INCLUDED
#define MANEJOARCHIVOS_H_INCLUDED

void imprimirEstadisticas(BITMAP *buffer)
{
    /**Actualiza la barra de estadisticas que se muestra en la parte superior de la pantalla*/
    int cm=32;
    textprintf_ex(buffer,font,cm,8,makecol(80, 216, 166),0,"Nombre: %s",prota.nombre);
    textprintf_ex(buffer,font,cm*6,8,makecol(80, 216, 166),0,"Vida: %d",prota.vida);
    textprintf_ex(buffer,font,cm*10,8,makecol(80, 216, 166),0,"Dinero: %d",prota.dinero);
    textprintf_ex(buffer,font,cm*15,8,makecol(80, 216, 166),0,"Karma: %d",prota.karma);
    textprintf_ex(buffer,font,cm*19,8,makecol(80, 216, 166),0,"Edad: %d",prota.edad);
}

void extraerPalabrasDeTexto(char palabra1[],char palabra2[],char palabra3[],char palabra4[],char palabra5[],char texto[])
{
    /** Extrae palabras de un texto espaciado: si texto es /ipconfig 1234 Danny, extrae: /ipconfig,1234,Danny*/
    int i,contador,pos;

    ///el fin del texto es un punto que se agrego automaticamente antes
    for(pos=0,contador=1; 1; contador++)
    {
        for(i=0; texto[pos]!=' ' && texto[pos]!='@' ; pos++,i++)
        {
            if(contador==1)
                palabra1[i] = texto[pos];
            if(contador==2)
                palabra2[i] = texto[pos];
            if(contador==3)
                palabra3[i] = texto[pos];
            if(contador==4)
                palabra4[i] = texto[pos];
            if(contador==5 && texto[pos]!='@')
                palabra5[i] = texto[pos];

        }
        if(texto[pos]==' ') pos++;
        if(texto[pos]=='@') i--;
        if(contador==1)
            palabra1[i] = '\0';
        if(contador==2)
            palabra2[i] = '\0';
        if(contador==3)
            palabra3[i] = '\0';
        if(contador==4)
            palabra4[i] = '\0';
        if(contador==5)
            palabra5[i] = '\0';

        if(texto[pos]=='@') break;
    }
    printf("\n%s->%s->%s->%s->%s",palabra1,palabra2,palabra3,palabra4,palabra5);
}

void generarArchivoTxt(int x,int y,char cadena[])
{
    ///x y, definen el lugar donde se imprimira lo que escribe
    char tecla;
    int i,caracterEspecial=0,pos=0;
    int espacioXCaracter = 9,espacio=0; //controlan el desplazamiento de los caracteres mostrados en pantalla

    ///Escribe "archivos/" porque esa es la carpeta de destino. El usuario solo debe ingresar un titulo
    char carpetaDest[] = "archivos/";

    for(i=0; carpetaDest[i]!='\0'; i++)
        cadena[i] = carpetaDest[i];


    clear_keybuf();
    while(1)
    {
        tecla = readkey();

        if(tecla == 13)
            break; ///si presion enter Acaba el programa

        if(tecla == 8)
        {
            textprintf_ex(screen,font,x+((pos-1)*espacioXCaracter)+espacio,y,makecol(0,0,0),makecol(255,255,255)," ");///BACKSPACE, borra
            caracterEspecial = 1;
            cadena[--i] = ' ';
            pos--;
        }

        if(!caracterEspecial) ///si no es un caracter especial,almacena datos
        {
            textprintf_ex(screen,font,x+(pos*espacioXCaracter),y,makecol(57, 124, 249),-1,"%c",tecla); ///imprime en tiempo real
            cadena[i++] = tecla;
            pos++;
        }
        caracterEspecial =0;
    }
    cadena[i] = '.';
    cadena[i+1] = 't';
    cadena[i+2] = 'x';
    cadena[i+3] = 't';
    cadena[i+4] = '\0'; ///fin de cadena: .txt
    printf("\n%s\n",cadena);
}

void archivoMusical(char urlArchivoMusical[],
                    SAMPLE *do1,SAMPLE *re1,SAMPLE *mi1,SAMPLE *fa1,SAMPLE *sol1,SAMPLE *la1,SAMPLE *si1,
                    SAMPLE *do2,SAMPLE *re2,SAMPLE *mi2,SAMPLE *fa2,SAMPLE *sol2,SAMPLE *la2,SAMPLE *si2,
                    SAMPLE *do3,SAMPLE *re3,SAMPLE *mi3,SAMPLE *fa3,SAMPLE *sol3,SAMPLE *la3,SAMPLE *si3)
{
    FILE *archivo;
    archivo = fopen(urlArchivoMusical,"rt");


    while((tecla = fgetc(archivo))!=EOF) ///Agarra letras del archivo
    {
        switch(tecla)
        {
        ///ESCALA 1
        case 'q':
            play_sample(do1,volumen,127,1000,0);
            break;
        case 'w':
            play_sample(re1,volumen,127,1000,0);
            break;
        case 'e':
            play_sample(mi1,volumen,127,1000,0);
            break;
        case 'r':
            play_sample(fa1,volumen,127,1000,0);
            break;
        case 't':
            play_sample(sol1,volumen,127,1000,0);
            break;
        case 'y':
            play_sample(la1,volumen,127,1000,0);
            break;
        case 'u':
            play_sample(si1,volumen,127,1000,0);
            break;

        ///ESCALA 2
        case 'i':
            play_sample(do2,volumen,127,1000,0);
            break;
        case 'o':
            play_sample(re2,volumen,127,1000,0);
            break;
        case 'p':
            play_sample(mi2,volumen,127,1000,0);
            break;
        case 'a':
            play_sample(fa2,volumen,127,1000,0);
            break;
        case 's':
            play_sample(sol2,volumen,127,1000,0);
            break;
        case 'd':
            play_sample(la2,volumen,127,1000,0);
            break;
        case 'f':
            play_sample(si2,volumen,127,1000,0);
            break;

        ///ESCALA 3
        case 'g':
            play_sample(do3,volumen,127,1000,0);
            break;
        case 'h':
            play_sample(re3,volumen,127,1000,0);
            break;
        case 'j':
            play_sample(mi3,volumen,127,1000,0);
            break;
        case 'k':
            play_sample(fa3,volumen,127,1000,0);
            break;
        case 'l':
            play_sample(sol3,volumen,127,1000,0);
            break;
        case 'z':
            play_sample(la3,volumen,127,1000,0);
            break;
        case 'x':
            play_sample(si3,volumen,127,1000,0);
            break;

        ///otras teclas
        case 'c':
            play_sample(do2,volumen,127,1000,0);
            break;
        case 'v':
            play_sample(re2,volumen,127,1000,0);
            break;
        case 'b':
            play_sample(mi2,volumen,127,1000,0);
            break;
        case 'n':
            play_sample(fa2,volumen,127,1000,0);
            break;
        case 'm':
            play_sample(sol2,volumen,127,1000,0);
            break;
        case ',':
            play_sample(la2,volumen,127,1000,0);
            break;
        case '.':
            play_sample(si2,volumen,127,1000,0);
            break;


        case '1':
            play_sample(do3,volumen,127,1000,0);
            break;
        case '2':
            play_sample(re3,volumen,127,1000,0);
            break;
        case '3':
            play_sample(mi3,volumen,127,1000,0);
            break;
        case '4':
            play_sample(fa3,volumen,127,1000,0);
            break;
        case '5':
            play_sample(sol3,volumen,127,1000,0);
            break;
        case '6':
            play_sample(la3,volumen,127,1000,0);
            break;
        case '7':
            play_sample(si3,volumen,127,1000,0);
            break;

        default:
            play_sample(sol2,volumen,127,1000,0);
        }

        Sleep(300);

    }

    fclose(archivo);
}
#endif // MANEJOARCHIVOS_H_INCLUDED
