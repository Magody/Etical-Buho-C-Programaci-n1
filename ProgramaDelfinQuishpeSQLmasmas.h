#ifndef PROGRAMADELFINQUISHPESQLMASMAS_H_INCLUDED
#define PROGRAMADELFINQUISHPESQLMASMAS_H_INCLUDED


void mostrarArchivo()
{
    char carac;
    char urlArchivo[60];
    FILE *archivo;
    fflush(stdin);
    printf("Ingrese directorio completo del archivo: ");
    gets(urlArchivo);
    archivo = fopen(urlArchivo,"r");
    int i;
    printf("\n\n");
    for(i=0;(carac=fgetc(archivo))!=EOF;  )
    {
        if(i==0)
            printf("%d ",i++);

        putchar(carac);

        if(carac == '\n')
            printf("%d ",i++);
    }
    /*for(i=0; fgets(linea,90,archivo) != NULL; i++ )
    {
        printf("%d ",i);
        printf("%s\n",linea);
    }*/
    printf("\n\n");
    fclose(archivo);
}

void busquedaPersona(char urlArchivo[])
{
    char nombre[10];
    char linea[300];
    FILE *archivo;
    archivo = fopen(urlArchivo,"r");

    fflush(stdin);
    printf("\nNombre: ");
    gets(nombre);

    while(fgets(linea,90,archivo) != NULL)
    {
        if(strstr(linea,nombre) != NULL)
        {
            printf("%20s%8s%15s%15s%15s","Nombre","Edad","Ciudad","Telefono","Password");
            printf("\n%s",linea);
            break;
        }
    }

    fclose(archivo);
    system("pause");
}


void ingresarPersona(char urlArchivo[])
{
    FILE *archivo;
    archivo = fopen(urlArchivo,"at");

    fflush(stdin);
    printf("\nNombre: ");
    gets(Victimas[numVictima].nombre);

    printf("Edad: ");
    scanf("%d",&Victimas[numVictima].edad);
    fflush(stdin);

    printf("Ciudad: ");
    gets(Victimas[numVictima].ciudad);
    fflush(stdin);

    printf("Telefono: ");
    gets(Victimas[numVictima].telefono);
    fflush(stdin);

    printf("Password: ");
    gets(Victimas[numVictima].password);

    fprintf(archivo,"%20s%8d%15s%15s%15s",Victimas[numVictima].nombre,Victimas[numVictima].edad,Victimas[numVictima].ciudad,Victimas[numVictima].telefono,Victimas[numVictima].password);

    Victimas[numVictima].id = numVictima;
    fclose(archivo);
    numVictima++;
    personasActualizadas++;
}

void informacionEspecifica()
{
    int opcion,cont,id;

    char nombre[50];
    char linea[300];
    FILE *archivo;
    archivo = fopen(urlVictimas,"r");

    fflush(stdin);
    printf("\nNombre COMPLETO de la persona que se cambiara informacion: ");
    gets(nombre);


    for(cont=0; cont<numVictima; cont++)
    {

        if(strcmp(nombre,Victimas[cont].nombre)==0)
        {
            id = Victimas[cont].id;
        }
    }

    while(fgets(linea,90,archivo) != NULL)
    {
        if(strstr(linea,nombre) != NULL)
        {
            printf("%20s%8s%15s%15s%15s","Nombre","Edad","Ciudad","Telefono","Password");
            printf("\n%s",linea);
            break;
        }
    }

    fclose(archivo);


    printf("\nIngrese el numero del dato que desee cambiar");
    printf("\n1. Nombre");
    printf("\n2. Edad");
    printf("\n3. Ciudad");
    printf("\n4. Telefono");
    printf("\n5. Password");
    printf("\nOpcion: ");
    scanf("%d", &opcion);

    fflush(stdin);

    archivo = fopen(urlVictimas,"w");
    switch(opcion)
    {
    case 1:
        printf("Nombre: "); gets(Victimas[id].nombre);
        break;
    case 2:
        printf("Edad: "); scanf("%d",&Victimas[id].edad);
        break;
    case 3:
        printf("Ciudad: "); gets(Victimas[id].ciudad);
        break;
    case 4:
        printf("Telefono: "); gets(Victimas[id].telefono);
        break;
    case 5:
        printf("Password: ");gets(Victimas[id].password);
        break;
    }
    system("pause");
    fprintf(archivo,"%20s%8s%15s%15s%15s","Nombre","Edad","Ciudad","Telefono","Password");
    for(cont=0; cont<numVictima; cont++)
    {
        if(Victimas[cont].eliminado != 'v')
        {
            fprintf(archivo,"\n%20s%8d%15s%15s%15s",Victimas[cont].nombre,
                Victimas[cont].edad,Victimas[cont].ciudad,Victimas[cont].telefono,
                Victimas[cont].password);
        }

    }

    fclose(archivo);
}

void eliminarPersona(char urlArchivo[])
{
    char nombre[10];
    char linea[300];
    FILE *archivo,*copia;

    copia = fopen("temp.txt","w");
    archivo = fopen(urlArchivo,"r");
    while(fgets(linea,100,archivo) != NULL)
    {
        fputs(linea,copia);
    }
    fclose(archivo);
    fclose(copia);

    copia = fopen("temp.txt","r");
    archivo = fopen(urlArchivo,"w");
    fflush(stdin);
    printf("\nNombre: ");
    gets(nombre);
    int contador=-1;
    while(fgets(linea,90,copia) != NULL)
    {
        if(strstr(linea,nombre) == NULL)
        {
            fputs(linea,archivo);

        }
        else
        {
            Victimas[contador].eliminado = 'v';
            printf("%s eliminado %c \n\n",Victimas[contador].nombre,
                   Victimas[contador].eliminado);
        }

        contador++;
    }

    fclose(archivo);
    fclose(copia);

    personasActualizadas--;
    system("pause");
}

void menuOpcionesSQL()
{
    clear_keybuf();
    system("mode 100");
    int opcion;
    do
    {
        printf("\n\t\t\t\t __     ___     _    ");
        printf("\n\t\t\t\t| _|   | _ |   | |   ");
        printf("\n\t\t\t\t||__   || ||   | |   ");
        printf("\n\t\t\t\t|__ |  ||_||_  | |__ ");
        printf("\n\t\t\t\t _| |  |___|_| |____|");
        printf("\n\t\t\t0. Salir.");
        printf("\n\t\t\t1. Eliminar contenido persona.");
        printf("\n\t\t\t2. Ingresar persona.");
        printf("\n\t\t\t3. Mostrar contenido del archivo.");
        printf("\n\t\t\t4. Mostrar especifico.");
        printf("\n\t\t\t5. Cambiar informacion especifica.\n\tOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            eliminarPersona(urlVictimas);
            break;
        case 2:
            ingresarPersona(urlVictimas);
            break;
        case 3:
            mostrarArchivo();
            break;
        case 4:
            busquedaPersona(urlVictimas);
            break;
        case 5:
            informacionEspecifica();
            break;
        }
        if(opcion!=3)
            system("cls");
    }
    while(opcion!=0);
    Sleep(3000);
    //NO APLASTAR TECLAS
}


void SQL()
{
    menuOpcionesSQL();
}

#endif // PROGRAMADELFINQUISHPESQLMASMAS_H_INCLUDED
