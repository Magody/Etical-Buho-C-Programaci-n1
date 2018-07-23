#ifndef POKIMAN_H_INCLUDED
#define POKIMAN_H_INCLUDED


struct Pokemon
{
    char nombre[10];
    int vida;
    int experiencia;
}pikachu,meow;

void pokiman()
{
    FILE *archivo; archivo = fopen("archivos/historialCombate.txt","w");
    int placaje,pocion;

    char eleccion[10];
    srand(time(NULL));

    int turno = 1+rand()%2;

    strcpy(pikachu.nombre,"Pokacho"); pikachu.vida=100;
    strcpy(meow.nombre,"Misifus"); meow.vida=100;

    while(pikachu.vida>0 && meow.vida>0)
    {

        printf("      %10s Vida: %d",pikachu.nombre,pikachu.vida);
        printf("\n      %10s Vida: %d",meow.nombre,meow.vida);
        printf("\n\t\t\t  ___              \t     ___   ");
        printf("\n\t\t\t /   \\            \t    /   \\");
        printf("\n\t\t\t|==0==| ------------------ |==0==| ");
        printf("\n\t\t\t \\___/            \t    \\___/\n\n");
        if(turno==1)
        {
            printf("\n\nEscriba accion %s\n\n",pikachu.nombre);
            printf("\n\na -> para placaje.");
            printf("\n\nb -> para pocion(de la suerte).\n\n");
            printf("\n\nOpcion: "); gets(eleccion);

            if(strcmp(eleccion,"a")==0)
            {
                placaje = rand()%20+20;
                printf("\n\n\n%s ha herido a %s con %d\n\n\n",pikachu.nombre,meow.nombre,placaje);
                fprintf(archivo,"\n%s ha herido a %s con %d\n",pikachu.nombre,meow.nombre,placaje);
                meow.vida -= placaje;
            }
            if(strcmp(eleccion,"b")==0)
            {
                pocion = 25+rand()%15;
                printf("\n\n\n%s se curo %d\n\n\n",pikachu.nombre,pocion);
                fprintf(archivo,"\n%s se curo %d\n",pikachu.nombre,pocion);
                pikachu.vida += pocion;
            }

            system("pause");
            system("cls");
            turno=2;
            continue;
        }


        if(turno==2)
        {
            printf("\n\nEscriba accion %s\n\n",meow.nombre);
            printf("\n\na -> para placaje.");
            printf("\n\nb -> para pocion.\n\n");
            printf("\n\nOpcion: "); gets(eleccion);

            if(strcmp(eleccion,"a")==0)
            {
                placaje = rand()%20+20;
                printf("\n\n\n%s ha herido a %s con %d\n\n\n",meow.nombre,pikachu.nombre,placaje);
                fprintf(archivo,"\n%s ha herido a %s con %d\n",meow.nombre,pikachu.nombre,placaje);
                pikachu.vida -= placaje;
            }
            if(strcmp(eleccion,"b")==0)
            {
                pocion = 25+rand()%15;
                printf("\n\n\n%s se curo %d\n\n\n",pikachu.nombre,pocion);
                fprintf(archivo,"\n%s se curo %d\n",pikachu.nombre,pocion);
                meow.vida += pocion;
            }
            system("pause");
            system("cls");
            turno=1;
            continue;
        }

    }

    if(pikachu.vida>0)
    {
        printf("\n\n%s ha ganado 100 y ha obtenido experiencia\n\n",pikachu.nombre);
        fprintf(archivo,"\n\n%s ha ganado 100 y ha obtenido experiencia\n\n",pikachu.nombre);
        pikachu.experiencia+=100;
    }
    else
    {
        printf("\n\n%s ha ganado 100 y ha obtenido experiencia\n\n",meow.nombre);
        fprintf(archivo,"\n\n%s ha ganado 100 y ha obtenido experiencia\n\n",meow.nombre);
        meow.experiencia+=100;
    }
    fclose(archivo);

}

#endif // POKIMAN_H_INCLUDED
