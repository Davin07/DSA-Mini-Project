//Vigenere
#include<stdio.h>
#include<string.h>
int i,j;

//Vigenere Cipher Encrypt
void Cipher(char key[],char str[])
{
        int len=strlen(str);
    //Block to make the length of key equal length of string
    for(i=0,j=0;i<len;i++,j++)
    {
        if(j==strlen(key))
        {
            j=0;
        }
        key[i]=key[j];
    }
    key[i]='\0';

//    Code works only for Upper Case letters

//    Block to convert letters to Upper Case
  //  My compiler did not accept strupr(str) function
    for(i=0;str[i]!='\0';i++)
	{
	    if (str[i]>='a'&&str[i]<='z')
    	{
        	str[i]=str[i] - 32;
    	}
    	if (key[i]>='a'&&key[i]<='z')
        {
        	key[i]=key[i] - 32;
        }
    }

    //Encrypt operation-add str and key
    for(i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        str[i]=((str[i]+key[i])%26)+'A';
    }
    str[i]='\0';
    printf("%s\n",str);
}

//Vigenere Cipher Encrypt
void Decipher(char key[],char str[])
{
    //Perform opposite operation of Encrypt
    for(i=0;i<strlen(str);i++)
    {
        if(isalpha(str[i]))
        str[i] = (((str[i] - key[i]) + 26) % 26) + 'A';
    }
    printf("%s\n",str);
}
int main()
{
    char str[50],key[50];
    int j;
    printf("Enter string:\n");
    gets(str);
    printf("Enter key:\n");
    gets(key);

    printf("%s\n",str);
    Cipher(key,str);
    printf("%s\n",key);

    Decipher(key,str);
    return 0;
}

