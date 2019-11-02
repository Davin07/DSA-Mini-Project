#include<stdio.h>
#include<string.h>
int i;
//Same function can be used to encrypt and decrypt
void EncryptDecrypt(char str[],int len)
{
    for(i=0;i<len;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]='Z'+'A'-str[i];
        }
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]='z'+'a'-str[i];
        } 
    }
    printf("%s",str);
    printf("\n");
}
int main()
{
 char str[50];
 printf("Enter text:\n");
 gets(str); 
 int len=strlen(str);
 printf("Ecrypted text:");
 EncryptDecrypt(str,len);
 printf("\nDecrypted text:");
 EncryptDecrypt(str,len);
 return 0;
}
