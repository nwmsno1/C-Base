#include <stdio.h>
FILE *stream, *stream2;
void main( void )
{
    int numclosed;
    /* Open for read (will fail if file "data" does not exist) */
    if( (stream  = fopen( "data", "r" )) == NULL )
        printf( "The file 'data' was not opened\n" );
    else
        printf( "The file 'data' was opened\n" );
    /* Open for write */
    if( (stream2 = fopen( "data2", "w+" )) == NULL )
       printf( "The file 'data2' was not opened\n" );
    else
       printf( "The file 'data2' was opened\n" );
    /* Close stream */
    if(fclose( stream2 ))
	  printf( "The file 'data2' was not closed\n" );
    /* All other files are closed: */
    numclosed = _fcloseall( );
    printf( "Number of files closed by _fcloseall: %u\n", numclosed );
    }
