#include "reader.h"

/*Don't use this on a kostring with content, kostring_free it first!*/
void kostring_zero(kostring* kos)
{
    memset(kos, 0, sizeof(kostring));
}

void kostring_write(kostring* kos, char* cstr)
{
    size_t newsize = strlen(cstr) + 1;
    if(kos->length != newsize) {
        kostring_resize(kos, newsize);
    }
    memcpy(kos->cstring, cstr, newsize);
}

void kostring_append(kostring* kos, char c)
{
    size_t newsize;

    if(kos->length == 0) {
        newsize = kos->length + 2;
    } else {
        newsize = kos->length + 1;
    }
    kostring_resize(kos, newsize);

    kos->cstring[newsize - 2] = c;
    kos->cstring[newsize - 1] = '\0';
}

void kostring_resize(kostring* kos, size_t bytes)
{
    if((bytes > kos->allocated_length)
            || (bytes < kos->allocated_length - kos->block_bytes)) {

        if((kos->cstring != 0) && (kos->allocated_length > 0)) {
            kos->allocated_length = kos->block_bytes * ((bytes / kos->block_bytes) + 1);
            kos->cstring = (char*) realloc(kos->cstring, kos->allocated_length);
        } else {
            kos->allocated_length = kos->block_bytes * ((bytes / kos->block_bytes) + 1);
            kos->cstring = malloc(kos->allocated_length);
        }
    }


    kos->cstring[bytes - 1] = '\0';
    kos->length = bytes;
}

void kostring_free(kostring* kos)
{
    free(kos->cstring);
    kos->cstring = 0;
    kos->length = 0;
}

/* intlist */

/*Don't use this on a kostring with content, kostring_free it first!*/
void intlist_zero(intlist* intl)
{
    memset(intl, 0, sizeof(intlist));
}

void intlist_cat(intlist* intl_dest, intlist* intl_src)
{
    //TODO
    /*size_t newsize = strlen(cstr) + 1;
    if(kos->length != newsize) {
        kostring_resize(kos, newsize);
    }
    memcpy(kos->cstring, cstr, newsize);*/
}

void intlist_append(intlist* intl, int i)
{
    size_t newsize = intl->length + 1;
    mdebug("Entered \"intlist_append\"!");
    intlist_resize(intl, newsize);

    intl->integers[newsize - 1] = i;
}

void intlist_resize(intlist* intl, size_t int_ammount)
{
    mdebug("Entered \"intlist_resize\"!");
    if((int_ammount > intl->allocated_length)
            || (int_ammount < intl->allocated_length - intl->block_ints)) {

        if((intl->integers != 0) && (intl->length > 0)) {
            mdebug("Rellocating intlist");
            intl->allocated_length = intl->block_ints * ((int_ammount / intl->block_ints) + 1);
            intl->integers = (int*) realloc(intl->integers, intl->allocated_length * sizeof(int));
        } else {
            mdebug("Allocating intlist");
            intl->allocated_length = intl->block_ints * ((int_ammount / intl->block_ints) + 1);
            intl->integers = malloc(intl->allocated_length * sizeof(int));
        }
    }

    intl->length = int_ammount;
}

void intlist_free(intlist* intl)
{
    free(intl->integers);
    intl->integers = 0;
    intl->length = 0;
}

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
