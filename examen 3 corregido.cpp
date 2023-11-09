#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//jose miguel ruiz marquez 180200
int main() 
{
    int filas = 3200;
    int filasacontar = 50;
    int ID = 200;

    FILE *file = fopen("emails.csv", "r");

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int maximodelineas = 10240;
    char buffer[maximodelineas];
    char *nombrespalabras[filas];
    int conteopalabras[filas];

    for (int i = 0; i < filas; ++i) {
        conteopalabras[i] = 0;
    }

    if (fgets(buffer, maximodelineas, file)) 
	{
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < filas) 
		{
            nombrespalabras[columna] = strdup(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    for (int filaactual = 0; filaactual <= ID && fgets(buffer, maximodelineas, file); ++filaactual) {
    }

    for (int filaactual = 0; filaactual < filasacontar && fgets(buffer, maximodelineas, file); ++filaactual) 
	{
        char *token = strtok(buffer, ",");
        if (token != NULL) 
		{
            token = strtok(NULL, ",");
        }
        int columna = 1; 
        while (token && columna < filas) 
		{
            conteopalabras[columna] += atoi(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(file);

    FILE *output = fopen("180200.txt", "w");

    if (output == NULL) {
        perror("Eerror al abrir el archivo");
        return 1;
    }

    for (int i = 1; i < filas && nombrespalabras[i] != NULL; i++) {
        fprintf(output, "%s, %d\n", nombrespalabras[i], conteopalabras[i]);
        free(nombrespalabras[i]);
    }

    fclose(output);
    printf("ya se puede abrir el archivo");

    return 0;
}

