#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char plt[100], dec[100];
int strint[100], c = 0;

int removeSpaces(char* plain, int ps) 
{ 
    int i, count = 0; 
    for (i = 0; i < ps; i++) 
        if (plain[i] != ' ') 
            plain[count++] = plain[i]; 
    plain[count] = '\0'; 
    return count; 
} 

void poly_enc(char str[])
{
    int poly[26], i, j;
    int x=0;
    int k=11;
 //Assigning Polybius Square numbers to alphabets
 
    for(i=0;i<=25;i++)
    {
        if(i<=8)
        {
            if(i%5==0&&i!=0)
            {
                k+=5;
                poly[x]=k++;
 
            }
            else
            {
                poly[x]=k++;
            }
        }  
        if(i>=10)
        {
            if(i%5==0&&i!=0)
            {
                poly[x]=k++;
                k+=5;
            }
            else
            {
                poly[x]=k++;
            }  
        }
        if(i==9)
        {
            poly[x]=24;
        }
         x++;
    }
    i=0;
    printf("Encrypted Code using Polybius Square Cipher \n");
    while(str[i]!='\0')
    {
        if(!((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                strint[i] = poly[str[i]-'A']; 
                c++;
            }
            if(str[i]>='a'&&str[i]<='z')
            {
                strint[i] = poly[str[i]-'a'];
                c++;
            }
    } 
    if(str[i]==' ')
    {
        continue;    
    }
        i++;
    }
  
  for(i = 0; i < c; i++)
  {
      printf("%d ", strint[i]);
  }
}



void poly_dec(int strint[])
{
    int i,j,poly[26],x,k;
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
 //printf("%c",(poly[strint[i]]+65));
}
dec[i] = '\0';

puts(dec);
}

void main()
{
    printf("Message \n");
    gets(plt);
    removeSpaces(plt, strlen(plt));
    poly_enc(plt);
    poly_dec(strint);
}
