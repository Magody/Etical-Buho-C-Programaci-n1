#ifndef OBJETOPIANO_H_INCLUDED
#define OBJETOPIANO_H_INCLUDED

void tecladoPiano(BITMAP *buffer,BITMAP *blocBlanco,
        SAMPLE *do1,SAMPLE *re1,SAMPLE *mi1,SAMPLE *fa1,SAMPLE *sol1,SAMPLE *la1,SAMPLE *si1,
        SAMPLE *do2,SAMPLE *re2,SAMPLE *mi2,SAMPLE *fa2,SAMPLE *sol2,SAMPLE *la2,SAMPLE *si2,
        SAMPLE *do3,SAMPLE *re3,SAMPLE *mi3,SAMPLE *fa3,SAMPLE *sol3,SAMPLE *la3,SAMPLE *si3)
{
    char archivoSinfonia[30];
    blit(blocBlanco,screen,0,240,50,30,261,264); ///para escribirle un titulo
    textprintf_ex(screen,font,55,37,makecol(0,0,0),-1,"Titulo: ");
    generarArchivoTxt(120,37,archivoSinfonia); ///los numeros indican en que lugar se imprimira lo que escriba el usuario

    FILE *sinfonia; sinfonia = fopen(archivoSinfonia,"w");

    while(1)
    {
        tecla = readkey();
        if(tecla == 13) ///mientras la tecla no sea ENTER
            break;

        switch(tecla)
        {
        ///ESCALA 1
        case 'q':play_sample(do1,volumen,127,1000,0); break;
        case 'w':play_sample(re1,volumen,127,1000,0); break;
        case 'e':play_sample(mi1,volumen,127,1000,0); break;
        case 'r':play_sample(fa1,volumen,127,1000,0); break;
        case 't':play_sample(sol1,volumen,127,1000,0); break;
        case 'y':play_sample(la1,volumen,127,1000,0); break;
        case 'u':play_sample(si1,volumen,127,1000,0); break;

        ///ESCALA 2
        case 'i':play_sample(do2,volumen,127,1000,0); break;
        case 'o':play_sample(re2,volumen,127,1000,0); break;
        case 'p':play_sample(mi2,volumen,127,1000,0); break;
        case 'a':play_sample(fa2,volumen,127,1000,0); break;
        case 's':play_sample(sol2,volumen,127,1000,0); break;
        case 'd':play_sample(la2,volumen,127,1000,0); break;
        case 'f':play_sample(si2,volumen,127,1000,0); break;

        ///ESCALA 3
        case 'g':play_sample(do3,volumen,127,1000,0); break;
        case 'h':play_sample(re3,volumen,127,1000,0); break;
        case 'j':play_sample(mi3,volumen,127,1000,0); break;
        case 'k':play_sample(fa3,volumen,127,1000,0); break;
        case 'l':play_sample(sol3,volumen,127,1000,0); break;
        case 'z':play_sample(la3,volumen,127,1000,0); break;
        case 'x':play_sample(si3,volumen,127,1000,0); break;

        ///otras teclas
        case 'c':play_sample(do2,volumen,127,1000,0); break;
        case 'v':play_sample(re2,volumen,127,1000,0); break;
        case 'b':play_sample(mi2,volumen,127,1000,0); break;
        case 'n':play_sample(fa2,volumen,127,1000,0); break;
        case 'm':play_sample(sol2,volumen,127,1000,0); break;
        case ',':play_sample(la2,volumen,127,1000,0); break;
        case '.':play_sample(si2,volumen,127,1000,0); break;


        case '1':play_sample(do3,volumen,127,1000,0); break;
        case '2':play_sample(re3,volumen,127,1000,0); break;
        case '3':play_sample(mi3,volumen,127,1000,0); break;
        case '4':play_sample(fa3,volumen,127,1000,0); break;
        case '5':play_sample(sol3,volumen,127,1000,0); break;
        case '6':play_sample(la3,volumen,127,1000,0); break;
        case '7':play_sample(si3,volumen,127,1000,0); break;

        default: play_sample(sol2,volumen,127,1000,0);
        }
        fputc(tecla,sinfonia);
    }
    fclose(sinfonia);
}

#endif // OBJETOPIANO_H_INCLUDED
