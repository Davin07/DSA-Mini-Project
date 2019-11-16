
//Decryption
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <errno.h>		// for errno
#include <unistd.h>		// for EINTR
#include<ctype.h>
#include<stdbool.h>

int i, j, c, len;
char enc[100], dec[100];
void append (char *s, char c)
{
  int len = strlen (s);
  s[len] = c;
  s[len + 1] = '\0';
}

//1.KEYWORD
void key_dec(char enc[])
{
    int i;
    char ch,key[100],ciphertext[26];
    bool arr[26] = {0};
    printf("Enter a string key\n");
    fflush(stdin);
    gets(key);
    for(i = 0; i < strlen(key); i++)
    {
		ch = key[i];
        if(ch >= 'A' && ch <= 'Z')
        {
            if(arr[ch - 'A'] == 0)
            {
                //ciphertext[i] = ch;
                append(ciphertext, ch);
                arr[ch - 'A'] = 1;
            }
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            if (arr[ch - 'a'] == 0)
            {
                //ciphertext[i] = ch - 32;
                append(ciphertext, ch-32);
                arr[ch - 'a'] = 1;
            }
        }
    }


    for (i=0; i<26; i++)
    {
        if(arr[i] == 0)
        {
            arr[i]=1;
            //ciphertext[i] = (char)(i+65);
            append(ciphertext, (char)(i+65));
        }
    }
	ciphertext[i] = '\0';


    char plaintext[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pos;
	char ch1, ence[100];

	for(i=0; i < strlen(ciphertext); i++)
    {
        ence[ciphertext[i]]=i;
    }

	for(i = 0; i < strlen(enc); i++)
	{
		ch1 = enc[i];
		if(isalpha(enc[i]))
		{
			if(ch1 >= 'a' && ch1 <= 'z')
			{
				pos = ence[ch1 - 97];
				append(dec, plaintext[pos]);
			}
			else if(ch1 >= 'A' && ch1 <= 'Z')
			{
				pos = ence[ch1];
				append(dec, plaintext[pos]);
			}
		}
		else
		{
			dec[i] = ch1;
		}
	}
	puts(dec);
}








//2.CAESAR CIPHER
void caesar_de (char enc[])
{
  char ch;
  int i,key;
    printf ("Enter an integer key\n");
    scanf ("%d", &key);

  for (i = 0; enc[i] != '\0'; ++i)
    {
      ch = enc[i];
      if (isalpha (enc[i]))
	{
	  if (ch >= 'a' && ch <= 'z')
	    {
	      ch = ch - key;

	      if (ch < 'a')
		{
		  ch = ch + 'z' - 'a' + 1;
		}

	      dec[i] = ch;
	    }
	  else if (ch >= 'A' && ch <= 'Z')
	    {
	      ch = ch - key;

	      if (ch < 'A')
		{
		  ch = ch + 'Z' - 'A' + 1;
		}

	      dec[i] = ch;
	    }
	}
      else
	{
	  dec[i] = enc[i];
	}

    }
//puts(dec);
  printf ("\nDecrypted message: %s\n", dec);
}


//3.XOR CIPHER
void xor_dec (char enc[])
{
  len=strlen(enc);
  char key;
    printf ("Enter a single character key\n");
    scanf ("%c", &key);

  //loop to traverse each character
  for (int i = 0; i < len; i++)
    {
      //perform XOR operation to each character and print
      dec[i] = enc[i] ^ key;
    }
    fflush(stdout);
    puts (dec);
}

//4.ROT13 CIPHER
void rot_de (char enc[])
{
  char ch;
  int i;

  for (i = 0; enc[i] != '\0'; ++i)
    {
      ch = enc[i];
      if (isalpha (enc[i]))
	{
	  if (ch >= 'a' && ch <= 'z')
	    {
	      ch = ch - 13;

	      if (ch < 'a')
		{
		  ch = ch + 'z' - 'a' + 1;
		}

	      dec[i] = ch;
	    }
	  else if (ch >= 'A' && ch <= 'Z')
	    {
	      ch = ch - 13;

	      if (ch < 'A')
		{
		  ch = ch + 'Z' - 'A' + 1;
		}

	      dec[i] = ch;
	    }
	}
      else
	{
	  dec[i] = enc[i];
	}
    }
  dec[i] = '\0';

  puts (dec);
}

//5.VERNAM CIPHER
void ver_dec (char enc[])
{
    char keyint[100],key[100];
    int len=strlen(enc);
    printf ("Enter key of same length as encrypted text\n");
    fflush (stdin);
    gets (key);

  //Loop to convert ascii value to range 0-25
  for (i = 0; i < len; i++)
    {
      enc[i] = (int) enc[i];
      keyint[i] = (int) key[i];
      if (enc[i] >= 65 && enc[i] <= 90)
	{
	  enc[i] -= 65;
	}
      else
	{
	  enc[i] -= 97;
	}
      if (keyint[i] >= 65 && keyint[i] <= 90)
	{
	  keyint[i] -= 65;
	}
      else
	{
	  keyint[i] -= 97;
	}
    }

  //substract the values and convert back to string
  for (i = 0; i < len; i++)
    {
      dec[i] = (enc[i] - keyint[i] + 26) % 26 + 'A';
    }
  printf ("\n%s\n", dec);
}

//6.VIGENERE CIPHER
void vig_dec (char enc[])
{
    char key[100];
    printf("Enter a string key\n");
    fflush(stdin);
    gets(key);
    len=strlen(enc);
    for(i=0,j=0;i<len;i++,j++)
    {
        if(j==strlen(key))
        {
            j=0;
        }
        key[i]=key[j];
    }
    printf("%d",len);
    for(i=0;enc[i]!='\0';i++)
	{
	    if (enc[i]>='a'&&enc[i]<='z')
    	{
        	enc[i]=enc[i] - 32;
    	}
    	if (key[i]>='a'&&key[i]<='z')
        {
        	key[i]=key[i] - 32;
        }
    }
  //Perform opposite operation of Encrypt
  for (i = 0; i < strlen (enc); i++)
    {
        if(isalpha(enc[i]))
      dec[i] = (((enc[i] - key[i]) + 26) % 26) + 'A';
      else
        dec[i]=enc[i];
    }
  printf ("\n%s\n", dec);
}

/*//8.POLYBIUS SQUARE CIPHER
void poly_dec (int enc[])
{
  int i, poly[26], x, k, strint[100];
  x = 0;
  k = 11;
  //Assigning Polybius Square numbers to alphabets

  for (i = 0; i <= 25; i++)
    {
      if (i <= 8)
	{
	  if (i % 5 == 0 && i != 0)
	    {
	      k += 5;
	      poly[k] = x;
	      k++;
	    }
	  else
	    {
	      poly[k] = x;
	      k++;
	    }
	}
      if (i >= 10)
	{
	  if (i % 5 == 0 && i != 0)
	    {
	      poly[k] = x;
	      k++;
	      k += 5;
	    }
	  else
	    {
	      poly[k] = x;
	      k++;
	    }
	}
      if (i == 9)
	{
	  poly[24] = 8;		//taking 'i' instead of 'j'
	}
      x++;
    }
  printf (" \n Decrypted Code using Polybius Square Cipher \n");
  for (i = 0; i < c; i++)
    {
      dec[i] = poly[strint[i]] + 'A';
      //printf("%c",(poly[enc[i]]+65));
    }
  dec[i] = '\0';

  puts (dec);
}
*/
//9.ATBASH CIPHER
void atb_dec (char enc[])
{
  int len = strlen (enc);
  for (i = 0; i < len; i++)
    {
      if (enc[i] >= 'A' && enc[i] <= 'Z')
	{
	  enc[i] = 'Z' + 'A' - enc[i];
	}
      if (enc[i] >= 'a' && enc[i] <= 'z')
	{
	  enc[i] = 'z' + 'a' - enc[i];
	}
    }
  printf ("\n%s\n", enc);
  printf ("\n");
}


//10.LATIN ALPHABET CIPHER
void lat_dec (int enc[])
{
    int i;
    for (i = 0;enc[i] != 0; i++)
    {
        if (enc[i] != -1)
        {
            dec[i] = enc[i] + 'A' - 1;
        }
        else
        {
            dec[i]=' ';
        }
    }
    puts (dec);
}



int main ()
{
   FILE *fp;
   fp = fopen("data.txt","r");
  int ch, c;
  char encc[100];
  int enc[100];
  printf ("Enter   1 to decrypt existing text or\n\t2 to enter new text\n");
  scanf ("%d", &ch);
    switch (ch)
    {
        case 1:
        {
            fscanf(fp," %d ",&c);
            fprintf(fp," %d ",c);
            if(c==8)
            {
                for (i = 0; enc[i-1] != 0; i++)
                    fscanf (fp,"%d", &enc[i]);
                for (i = 0; enc[i-1] != 0; i++)
                    fprintf(fp,"%d", enc[i]);

            }
            else
            {
                fflush (stdin);
                while(fgets(enc,sizeof(enc),fp)!=NULL);
            }
        }
        break;
        case 2:
        {
            printf("Which cipher would you like to use?\nEnter\n1-Keyword Cipher\n2-Caesar Cipher\n3-Atbash Cipher\n4-Rot-13 Cipher\n5-Vernam Cipher\n6-Vigenere Cipher\n7-XOR Cipher\n8-Polibius Cipher\n9-Latin Alphabet Cipher\n");
            scanf ("%d",&c);
            printf ("\nEnter the text you wish to decrypt \n");
            if(c==8)
            {
                for (i = 0; enc[i-1] != 0; i++)
                    scanf ("%d", &enc[i]);
            }
            else
            {

                fflush (stdin);
                gets (enc);
            }
            break;
        }
    }
     switch (c)
    {
        case 1: key_dec (enc);   break;
        case 2: caesar_de (enc);    break;
        case 3: atb_dec (enc);    break;
        case 4: rot_de (enc);    break;
        case 5: ver_dec (enc);    break;
        case 6: vig_dec (enc);    break;
        case 7: xor_dec (enc);    break;
        case 8: lat_dec (enc);  break;
		     	     
        //All the functions for the above ciphers should take "enc" as an argument.
        //Requesting the key must be done within the function. The masking of the key will be done using a separate function.
        //Each function should have a return type of char to return the encrypted string which is then stored in the file.
    }
       // goto a;
        return 0;

}


