#ifndef INICIALIZACION_H_INCLUDED
#define INICIALIZACION_H_INCLUDED


int inicia_audio(int izquierda, int derecha)
{
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }

    set_volume(izquierda, derecha);
    return 0;
}


void inicia_allegro(int ANCHO_, int ALTO_)
{
    allegro_init(); ///componentes varios por defecto
    install_keyboard(); ///inicia el teclado

    set_color_depth(32); ///tipo de color 32 bits es calidad alta
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0); ///establece el tamaño de la pantalla y si va en modo ventana o fullscreen
    inicia_audio(volumen,volumen); ///instala componentes del sonido
    install_mouse(); ///componentes del mouse
}

void inicioVictimas()
{
    FILE *archivoVictimas;

    archivoVictimas = fopen(urlVictimas,"w");


    strcpy(Victimas[0].nombre,"Pedro Guaman");
    Victimas[0].edad = 20;
    strcpy(Victimas[0].telefono,"098734562");
    strcpy(Victimas[0].password,"Dro123");
    strcpy(Victimas[0].ciudad,"Quito");
    Victimas[0].id = 0;
    personasActualizadas++;

    strcpy(Victimas[1].nombre,"Juan Hurtin");
    Victimas[1].edad = 56;
    strcpy(Victimas[1].telefono,"2129751342");
    strcpy(Victimas[1].password,"Jua123");
    strcpy(Victimas[1].ciudad,"Quito");
    Victimas[1].id = 1;
    personasActualizadas++;

    strcpy(Victimas[2].nombre,"Danny Diaz");
    Victimas[2].edad = 27;
    strcpy(Victimas[2].telefono,"0988656777");
    strcpy(Victimas[2].password,"Dan123");
    strcpy(Victimas[2].ciudad,"Quito");
    Victimas[2].id = 2;
    personasActualizadas++;

    strcpy(Victimas[3].nombre,"Fernando Fernandez");
    Victimas[3].edad = 47;
    strcpy(Victimas[3].telefono,"0934562674");
    strcpy(Victimas[3].password,"Fer123");
    strcpy(Victimas[3].ciudad,"Quito");
    Victimas[3].id = 3;
    personasActualizadas++;

    strcpy(Victimas[4].nombre,"Manaka Hoton");
    Victimas[4].edad = 17;
    strcpy(Victimas[4].telefono,"09886634536");
    strcpy(Victimas[4].password,"Man123");
    strcpy(Victimas[4].ciudad,"Quito");
    Victimas[4].id = 4;
    personasActualizadas++;


    fprintf(archivoVictimas,"%20s%8s%15s%15s%15s","Nombre","Edad","Ciudad","Telefono","Password");

    for(; numVictima<5; numVictima++)
    {
        fprintf(archivoVictimas,"\n%20s%8d%15s%15s%15s",Victimas[numVictima].nombre,
                Victimas[numVictima].edad,Victimas[numVictima].ciudad,Victimas[numVictima].telefono,
                Victimas[numVictima].password);
    }


    fclose(archivoVictimas);
}
void establecerEstadisticasIniciales()
{
    prota.posX = (ANCHO/2)-130; prota.posY = (ALTO/2); ///lugar donde aparece

    strcpy(prota.nombre,"Elliot");
    prota.vida=100;
    prota.dinero=100;
    prota.karma=0;
    prota.edad=19;
    inicioVictimas();
}

#endif // INICIALIZACION_H_INCLUDED
