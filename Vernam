//Does not work for spaces

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,len,strint[50],keyint[50];
void Encrypt(char key[],char str[])
{
    //Loop to convert ascii value to range 0-25
    //Needs a separate function
    for(i=0;i<len;i++)
    {
        strint[i]=(int)str[i];
        keyint[i]=(int)key[i];
        if(strint[i]>=65&&strint[i]<=90)
        {
            strint[i]-=65;
        }
        else
        {
            strint[i]-=97;
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
    
    //add the values and convert back to string
    for(i=0;i<len;i++)
    {
        str[i]=(strint[i]+keyint[i])%26+'A';
    }
    printf("%s\n",str);
}
void Decrypt(char key[],char str[])
{
    //Loop to convert ascii value to range 0-25
    //Needs a separate function
    
    for(i=0;i<len;i++)
    {
        strint[i]=(int)str[i];
        keyint[i]=(int)key[i];
        if(strint[i]>=65&&strint[i]<=90)
        {
            strint[i]-=65;
        }
        else
        {
            strint[i]-=97;
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
        str[i]=(strint[i]-keyint[i]+26)%26+'A';
    }
     printf("%s\n",str);
}
int main()
{
    char str[50],key[50];
    printf("\nEnter string:");
    gets(str);
    printf("\nEnter key:");
    gets(key);
    len=strlen(str);
    // Encrypt the string 
    printf("Encrypted String: "); 
    Encrypt(key,str); 
    // Decrypt the string 
    printf("Decrypted String: "); 
    Decrypt(key,str); 
    return 0; 
}
