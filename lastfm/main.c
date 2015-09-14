#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main()
{
    unsigned int num;
    printf("Input multiply: ");
    /* read how much items will be in list */
    scanf("%d", &num);
    /* it's a fucking magic */
    {
        int i = 0;
        while (i < 20000) { printf("%d",(i%3+i%7+i%17+i%31+i%67+i%107)%2); i=i+1;}

        printf("\r\nAll finished. Thanks to vk.com/itser !");
    }

    int i = 0;
    char *line = NULL;
    int counter=0;
    /* Hard name */
	FILE *art=fopen("artist.txt","r");
    int c;

    while (c!=EOF)
    {
        /* Add 500b to string (very bad) */
        i += 500;
        line = realloc(line, i);
        int g = i - 500;
        while ( ( c=fgetc ( art ) ) != '\n' && ( c ) != '\0' && ( c ) != '\r' && ( c ) != EOF )
        {
            line[g] = c;
            g++;
        }
        line[g] = '\0';
        counter++;
    }
    /* Close FILE */
    fclose(art);
    /* Writing header */
    FILE *f=fopen("scrobbler.log", "w");
    fputs("#AUDIOSCROBBLER/1.1\n", f);
    fputs("#TZ/UNKNOWN\n", f);
    fputs("#CLIENT/Rockbox cowond2 $Revision: 29315 $\n", f);

    long dif = 0; /* Timeness of track */
    int ii = 0; /* Counter =) */
    for (ii = 0; ii < num; ii ++)
    {
        int i;
        for (i = 0;i < counter * 500; i += 500)
        {
            fputs(line + i, f);
            fputs("\t11\t387\tL\t", f);
            fprintf(f, "%d\t", (int)time(NULL) - dif);
            fputs(" \n", f);
            dif += 4;
        }
        dif += 15;
    }
    /* Close FILE */
    fclose(f);
    /* Waiting */
    scanf("%d", &num);
    return 0;
}
