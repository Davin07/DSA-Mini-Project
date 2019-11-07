//Decryption
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <errno.h>   /* for errno */
#include <unistd.h>  /* for EINTR */
int i,c,len;
char enc[100],dec[100];
void append(char* s, char c) 
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

//KEYWORD
 key_dec(char enc[])
{
	char plaintext[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pos, i;
	char ch1,key[100], ence[100],ciphertext[26];
//	bool arr[26] = {0};
    int arr[26];
	for (i=0;i<26;i++)
	    arr[i]=0;
    printf("Enter key\n");
    gets(key);
    for (i=0; i<26; i++) 
    { 
        if(arr[i] == 0) 
        { 
            arr[i]=1; 
            //ciphertext[i] = (char)(i+65);
            strcat(ciphertext, (char)(i+65));
        } 
    } 
    ciphertext[i] = '\0';
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


//CAESAR CIPHER
void caesar_de(char enc [])
{
    char ch;
	int i,key;
	printf("Enter key\n");
    scanf("%d",&key);
	for(i = 0; enc[i] != '\0'; ++i){
		ch = enc[i];
		if(isalpha(enc[i]))
		{
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			dec[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
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
	
	printf(" \n Decrypted message: %s", dec);
}


//XOR CIPHER
void xor_dec(char enc[])
{
    char key;
    printf("Enter key\n");
    scanf("%d",&key);
    int len=strlen(enc);
    //loop to traverse each character
    for (int i = 0; i < len; i++) 
    {
        //perform XOR operation to each character and print
        enc[i] = enc[i] ^ key; 
        printf("%c",enc[i]); 
    } 
} 
//ROT13 CIPHER
void rot_de(char* enc)
{
    char ch;
	int i;
	
	for(i = 0; enc[i] != '\0'; ++i){
		ch = enc[i];
		if(isalpha(enc[i]))
		{
        	if(ch >= 'a' && ch <= 'z')
			{
				ch = ch - 13;
			
				if(ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
			
				dec[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z')
			{
				ch = ch - 13;
			
				if(ch < 'A')
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
	
	puts(dec);
}

//VERNAM CIPHER
void ve_dec(char enc[])
{
    char key[100],encint[100],keyint[100];
    //Loop to convert ascii value to range 0-25
    //Needs a separate function
    printf("Enter key\n");
    gets(key);
	
    for(i=0;i<len;i++)
    {
        encint[i]=(int)enc[i];
        keyint[i]=(int)key[i];
        if(encint[i]>=65&&encint[i]<=90)
        {
            encint[i]-=65;
        }
        else
        {
            encint[i]-=97;
        }
        if(keyint[i]>=65&&keyint[i]<=90)
        {
            keyint[i]-=65;
        }
        else
        {
            keyint[i]-=97;
        }
    }
    
    //substract the values and convert back to string
    for(i=0;i<len;i++)
    {
        enc[i]=(encint[i]-keyint[i]+26)%26+'A';
    }
     printf("%s\n",enc);
}
//VIGNERE CIPHER
void vi_dec(char enc[])
{
    char key[100];
    printf("Enter key\n");
    gets(key);
	//Perform opposite operation of Encrypt
    for(i=0;i<strlen(enc);i++)
    {
        enc[i] = (((enc[i] - key[i]) + 26) % 26) + 'A';
    }
    printf("%s\n",enc);
}
//PLAYFAIR CIPHER
//POLYBIUS SQUARE CIPHER
void poly_dec(int enc[])
{
    int i,j,poly[26],x,k,strint[100];
    x=0;
    k=11;
 //Assigning Polybius Square numbers to alphabets
 
    for(i=0;i<=25;i++)
    {
        if(i<=8)
        {
            if(i%5==0&&i!=0)
            {
                k+=5;
                poly[k]=x;
                k++;
            }
            else
            {
                poly[k]=x;
                k++;
            }
        }
        if(i>=10)
        {
            if(i%5==0&&i!=0)
            {
                poly[k]=x;
                k++;
                k+=5;
            }
            else
            {
                poly[k]=x;
                k++;
            }  
        }
        if(i==9)
        {
            poly[24]=8;//taking 'i' instead of 'j'
        }
        x++;
    }
printf(" \n Decrypted Code using Polybius Square Cipher \n");
for(i = 0; i < c; i++)
{
 dec[i] = poly[strint[i]]+65;
 //printf("%c",(poly[encint[i]]+65));
}
dec[i] = '\0';

puts(dec);
}

//ATBASH CIPHER
void at_dec(char enc[],int len)
{
    for(i=0;i<len;i++)
    {
        if(enc[i]>='A'&&enc[i]<='Z')
        {
            enc[i]='Z'+'A'-enc[i];
        }
        if(enc[i]>='a'&&enc[i]<='z')
        {
            enc[i]='z'+'a'-enc[i];
        } 
    }
    printf("%s",enc);
    printf("\n");
}


//LATIN ALPHABET CIPHER
void la_dec(int encint[])
{
	int i;
	for(i = 0; i < c; i++)
	{
		if(encint[i] != -1)
		{
			dec[i] = encint[i] + 'A' - 1;
		}
		else
		{
			printf(" ");
		}
		
	}
	puts(dec);
}



void main()
{
    FILE *fp;
    fp = fopen("data.txt","w");
    int i, a, s;
    char enc[500], plt[500];
    printf("Enter the text you wish to decrypt \n");
    scanf("%s",enc);
    len=strlen(enc);
    /*a = rand();
    if(a%10 >= 1 && a%10 <= 10)
    {
      s = a%10;
      fprintf(fp, "%d \n", a%10);
      //fputs("\n", fp);
    }
    // fprintf(fp, "%s \n", enc); At the end; after encryprtion.
    //fclose(fp);*/
    printf(" Option ");
    scanf("%d",&s);
    switch(s)
    {
        case 1: //KEYWORD CIPHER 
        key_dec(enc);
        break;
        case 2: //CAESAR CIPHER
        caesar_de(enc);
        break;
        case 3: //XOR CIPHER
        xor_dec(enc);
        break;
        case 4: //ROT13 CIPHER
        rot_de(enc);
        break;
        case 5: //VERNAM CIPHER
        ve_dec(enc);
        break;
        case 6: //VIGNERE CIPHER
        vi_dec(enc);
        break;
        //case 7: //PLAYFAIR CIPHER
        case 8: //POLYBIUS SQUARE CIPHER
        poly_dec(enc);
        break;
        case 9: //ATBASH CIPHER
        at_dec(enc,len);
        break;
        case 10: //LATIN ALPHABET CIPHER
        la_dec(enc);
        break;
        //All the functions for the above ciphers should take "enc" as an argument.
        //Requesting the key must be done within the function. The masking of the key will be done using a separate function.
        //Each function should have a return type of char to return the encrypted string which is then stored in the file.
    }
}
