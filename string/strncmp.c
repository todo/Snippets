#include <stdio.h>

/* String comparison for n characters */
int strncmp( const char s1[], const char s2[], size_t n );
int strncmp( const char s1[], const char s2[], size_t n )
{
    /* When n = 0, must return 0 */
    if ( n == 0 ) return 0;
    /* No comparison is made after n characters */
    for ( ; --n && *s1 && *s1 == *s2; ++s1, ++s2 )
        ;
    return *(unsigned const char *)s1 - *(unsigned const char *)s2;
}

int main( void )
{
    printf( "%d\n", strncmp( "aa", "aab", 2 ) );
    return 0;
}
