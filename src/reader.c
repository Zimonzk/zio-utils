#include "zio-reader.h"


/* filestuff */
void readlin(FILE* file, kostring* dest)
{
    char c;

    kostring_free(dest);

    c = getc(file);
    while((c != '\n') && (c != EOF)) {
        kostring_append(dest, c);
        c = getc(file);
    }
}
