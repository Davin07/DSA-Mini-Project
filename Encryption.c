#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <errno.h>   /* for errno */
#include <unistd.h>  /* for EINTR */

void main()
{
    FILE *fp;
    fp = fopen("data.txt","w");
    int i, a, s;
    char plt[500], enc[500];
    printf("Enter the text you wish to encrypt \n");
    scanf("%s",plt);
    a = rand();
    if(a%10 >= 1 && a%10 <= 10)
    {
      s = a%10;
      fprintf(fp, "%d \n", a%10);
      //fputs("\n", fp);
    }
    // fprintf(fp, "%s \n", plt); At the end; after encryprtion.
    //fclose(fp);
    switch(s)
    {
        case 1: //KEYWORD CIPHER 
        case 2: //CAESAR CIPHER
        case 3: //XOR CIPHER
        case 4: //ROT13 CIPHER
        case 5: //VERNAM CIPHER
        case 6: //VIGNERE CIPHER
        case 7: //PLAYFAIR CIPHER
        case 8: //POLYBIUS SQUARE CIPHER
        case 9: //ATBASH CIPHER
        case 10: //LATIN ALPHABET CIPHER
        //All the functions for the above ciphers should take "plt" as an argument.
        //Requesting the key must be done within the function. The masking of the key will be done using a separate function.
        //Each function should have a return type of char to return the encrypted string which is then stored in the file.
    }
}
