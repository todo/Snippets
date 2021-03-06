#include <stdio.h>

char *strncat( char * restrict dest, const char * restrict src, size_t n );
char *strncat( char * restrict dest, const char * restrict src, size_t n )
{
    char    *destP = dest;

    while ( *destP )
        ++destP;
    for ( ; n-- && (*destP = *src++); ++destP )
        ;
    *destP = '\0';
    return dest;
}

int main( void )
{
    char    a[ 100 ] = "Test ", b[] = "Hello World";

    printf( "%s\n", strncat( a, b, 6 ) );
    return 0;
}
