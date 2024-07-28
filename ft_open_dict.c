#include <stdio.h>
#include <string.h>
#include "main.h"
#include "ft_utils.h"

#define MAX_ENTRIES 10


int main(int argc, char **argv) {

    int index = 0;
    int recorrer = 0;
    int nbr;

    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fscanf(file, "%d: %s", &dictionary[index].key, dictionary[index].value) == 2) 
    {
        index++;
        if (index >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);

    nbr = ft_atoi(argv[1]);

    while(recorrer < index)
    {
	    if ( nbr == dictionary[recorrer].key)
	    {
		    printf("%s\n", dictionary[recorrer].value);
	    }
	    recorrer++;
    }
    return 0;
}
