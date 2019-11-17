
//Decryption
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/time.h>
//#include <termios.h>
#include <errno.h>		// for errno
#include <unistd.h>		// for EINTR
#include<ctype.h>
#include<stdbool.h>
#define S 100
int i, j, c, len, enc[S];
char encc[S], dec[S];
void append (char *s, char c)
{
  int len = strlen (s);
  s[len] = c;
  s[len + 1] = '\0';
}

//1.KEYWORD
void key_dec(char encc[])
{
    int i;
    char ch,key[S],ciphertext[26];
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
	char ch1, ence[S];

	for(i=0; i < strlen(ciphertext); i++)
    {
        ence[ciphertext[i]]=i;
    }

	for(i = 0; i < strlen(encc); i++)
	{
		ch1 = encc[i];
		if(isalpha(encc[i]))
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
void caesar_de (char encc[])
{
  char ch;
  int i,key;
    printf ("Enter an integer key\n");
    scanf ("%d", &key);

  for (i = 0; encc[i] != '\0'; ++i)
    {
      ch = encc[i];
      if (isalpha (encc[i]))
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
	  dec[i] = encc[i];
	}

    }
  printf ("\nDecrypted message: %s\n", dec);
}

//3.ATBASH CIPHER
void atb_dec (char encc[])
{
  int len = strlen (encc);
  for (i = 0; i < len; i++)
    {
      if (encc[i] >= 'A' && encc[i] <= 'Z')
	{
	  encc[i] = 'Z' + 'A' - encc[i];
	}
      if (encc[i] >= 'a' && encc[i] <= 'z')
	{
	  encc[i] = 'z' + 'a' - encc[i];
	}
    }
  printf ("\n%s\n", encc);
  printf ("\n");
}

//4.ROT13 CIPHER
void rot_de (char encc[])
{
  char ch;
  int i;

  for (i = 0; encc[i] != '\0'; ++i)
    {
      ch = encc[i];
      if (isalpha (encc[i]))
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
	  dec[i] = encc[i];
	}
    }
  dec[i] = '\0';

  puts (dec);
}

//5.VERNAM CIPHER
void ver_dec (char encc[])
{
    char keyint[S],key[S];
    int len=strlen(encc);
    printf ("Enter key of same length as enccrypted text\n");
    fflush (stdin);
    gets (key);

  //Loop to convert ascii value to range 0-25
  for (i = 0; i < len; i++)
    {
      encc[i] = (int) encc[i];
      keyint[i] = (int) key[i];
      if (encc[i] >= 65 && encc[i] <= 90)
	{
	  encc[i] -= 65;
	}
      else
	{
	  encc[i] -= 97;
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
        if(encc[i]!=' ')
            dec[i] = (encc[i] - keyint[i] + 26) % 26 + 'A';
        else
            dec[i] = encc[i];
    }
    dec[i] = '\0';
  printf ("\n%s\n", dec);
}

//6.VIGENERE CIPHER
void vig_dec (char encc[])
{
    char key[S];
    printf("Enter a string key\n");
    fflush(stdin);
    gets(key);
    len=strlen(encc);
    for(i=0,j=0;i<len;i++,j++)
    {
        if(j==strlen(key))
        {
            j=0;
        }
        key[i]=key[j];
    }
    key[i]='\0';
    puts(key);
//    printf("%d",len);
    for(i=0;encc[i]!='\0';i++)
	{
	    if (encc[i]>='a'&&encc[i]<='z')
    	{
        	encc[i]=encc[i] - 32;
    	}
    	if (key[i]>='a'&&key[i]<='z')
        {
        	key[i]=key[i] - 32;
        }
    }
  //Perform opposite operation of enccrypt
  for (i = 0; i < strlen (encc); i++)
    {
        if(encc[i]!=' ')
      dec[i] = (((encc[i] - key[i]) + 26) % 26) + 'A';
      else
        dec[i]=encc[i];
    }
    dec[i]='\0';
  printf ("\n%s\n", dec);
}

//7.XOR CIPHER
void xor_dec (char encc[])
{
  len=strlen(encc);
  char key;
    printf ("Enter a single character key\n");
    scanf ("%c", &key);

  //loop to traverse each character
  for (int i = 0; i < len; i++)
    {
      //perform XOR operation to each character and print
      dec[i] = encc[i] ^ key;
    }
    fflush(stdout);
    puts (dec);
}



//8.LATIN ALPHABET CIPHER
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
  int enc[S];
  printf ("Enter   1 to decrypt existing text or\n\t2 to enter new text\n\tAny other key to exit\n");
  //scanf ("%d", &ch);
    switch (1)
    {
        case 1:
        {
            fscanf(fp," %d ",&c);
            if(c==8)
            {
                for (i = 0; enc[i-1] != 0; i++)
                    fscanf (fp,"%d", &enc[i]);
            }
            else
            {
                fflush (stdin);
                while(fgets(encc,sizeof(encc),fp)!=NULL);
            }
        }
        break;
        case 2:
        {
            printf("Which cipher would you like to use?\nEnter\n1-Keyword Cipher\n2-Caesar Cipher\n3-Atbash Cipher\n4-Rot-13 Cipher\n5-Vernam Cipher\n6-Vigenere Cipher\n7-XOR Cipher\n8-Latin Alphabet Cipher\n");
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
                gets (encc);
            }
            break;
        }
        default:
            exit(0);
    }
     switch (c)
    {
        case 1: key_dec (encc);   break;
        case 2: caesar_de (encc);    break;
        case 3: atb_dec (encc);    break;
        case 4: rot_de (encc);    break;
        case 5: ver_dec (encc);    break;
        case 6: vig_dec (encc);    break;
        case 7: xor_dec (encc);    break;
        case 8: lat_dec (enc);  break;
        //All the functions for the above ciphers should take "enc" as an argument.
        //Requesting the key must be done within the function. The masking of the key will be done using a separate function.
        //Each function should have a return type of char to return the encrypted string which is then stored in the file.
    }
//        goto a;
        return 0;

}



/**/
