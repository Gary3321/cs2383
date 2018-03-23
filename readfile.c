#include <stdio.h>

#include <string.h>

int main() {   

       static const char filename[] = "test.txt";
	

       FILE *file = fopen ( filename, "r" );
       if ( file != NULL )
       {
          char line [ 128 ]; /* or other suitable maximum line size */
          while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
          {
             //fputs ( line, stdout ); /* write the line */
	     printf("%s", line);
	     char* token = strtok(line, " ");
	     while(token)
		{
		  puts(token);
		  token=strtok(NULL," ");
		}  

          }
          fclose ( file );
       }
       else
       {
          perror ( filename ); /* why didn't the file open? */
       }
       return 0;
    }
 
https://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
https://www.youtube.com/watch?v=GMzVeWpyTN0
