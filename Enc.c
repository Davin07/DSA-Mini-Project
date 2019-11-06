#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>
#include <sys/time.h>
#include <termios.h>
#include <errno.h>   /* for errno */
#include <unistd.h>  /* for EINTR */

char ciphertext[200], enc[200], dec[200], plt[200];
int strint[100];

//For removal of spaces 
void append(char* s, char c) 
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

//KEYWORD CIPHER ALGORITHM
void keyenc(char plt[])
{
    char ch, ch1, key[100];
    printf("Enter the key (Alphabets only)\n");
    gets(key);                                             
    int i;
    bool arr[26] = {0};
    
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

	int pos;
    
	for(i = 0; i < strlen(plt); i++)
	{
		ch1 = plt[i];
		if(isalpha(plt[i]))
		{
			if(ch1 >= 'a' && ch1 <= 'z')
			{
				pos = ch1 - 97;	
				append(enc, ciphertext[pos]);
			}
			else if(ch1 >= 'A' && ch1 <= 'Z')
			{
				pos = ch1 - 65;
				append(enc, ciphertext[pos]);	
			}
		}
		else
		{
			enc[i] = ch1;
		}
	}
	printf("Encrypted message: %s", enc);                 

    
}    


//CAESAR CIPHER ALGORITHM           //Currently does not work for lower case alphabets from s onwards
void caesarenc(char plt[])
{

    char ch;
    int i, key;
	printf("Enter key: (Number)");
	scanf("%d", &key);                          
	
	for(i = 0; plt[i] != '\0'; ++i){
		ch = plt[i];
		if(isalpha(plt[i]))
		{
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			enc[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			enc[i] = ch;
		}
		}
		else
		{
			enc[i] = plt[i];
		}
		
	}
    enc[i] = '\0';
	
	printf("Encrypted message: %s", enc);                      

}


//XOR CIPHER ALGORITHM

void XORencrypt(char str[])
{
    char key;
    printf("Enter the key (A single character) \n");
    scanf("%c", &key);
    int len = strlen(str);
    //loop to traverse each character
    printf("Encypted Message: ");
    for (int i = 0; i < len; i++) 
    {
        //perform XOR operation to each character and print
        enc[i] = str[i] ^ key; 
                         
    } 
    puts(enc);  
}

//ROT13 CIPHER ALGORITHM                //Currently does not work for lowercase alphabets from s onwards
void rotenc(char plt[])
{

    char ch;
    int i;
    int key = 13;
    
	
	for(i = 0; plt[i] != '\0'; i++)
	{
		ch = plt[i];
		if(isalpha(plt[i]))
        {
			if(ch >= 'a' && ch <= 'z')
			{
				ch = ch + key;                         
			
				if(ch > 'z')
				{
				ch = ch - 'z' + 'a' - 1;
				}
			
			enc[i] = ch;
			}	
			else if(ch >= 'A' && ch <= 'Z')
			{
				ch = ch + key;                          
			
				if(ch > 'Z')
				{
				ch = ch - 'Z' + 'A' - 1;
				}
			
			enc[i] = ch;
			}
        }
        else
        {
            enc[i] = plt[i];
        }
        
	}
    enc[i] = '\0';
	
	printf("Encrypted Message: %s", enc);               

}


//VERNAM CIPHER ALGORITHM
void vernamenc(char str[])
{
    int len, i, strint[100], keyint[100]; 
    //Loop to convert ascii value to range 0-25
    //Needs a separate function
    char key[100];
    printf("Enter the key \n");
    gets(key);
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
        enc[i]=(strint[i]+keyint[i])%26+'A';
    }
    enc[i] = '\0';
    printf("Encrypted Message: %s\n",enc);                 
}

void vigenc(char str[])
{
    int i, j;
    char key[100];
    printf("Enter the key \n");
    gets(key);
    //Block to make the length of key equal length of string
    for(i=0,j=0;i<strlen(str);i++,j++)                  
    {
        if(j==strlen(key))
        {
            j=0;
        }
        key[i]=key[j];
    }
    
    /*Code works only for Upper Case letters
    
    Block to convert letters to Upper Case*/
    
    for(i=0;str[i]!='\0';i++) 
	{
	    if (str[i]>='a'&&str[i]<='z')
    	{
        	str[i]=str[i] - 32;
        	key[i]=key[i] - 32;
        }
    }
    int len=strlen(str);
    
    //Encrypt operation-add str and key
    for(i=0;i<len;i++)
    {
        enc[i]=((str[i]+key[i])%26)+'A';
    }
    enc[i] = '\0';
    printf("%s \n",enc);                     
}

//POLYBIUS SQUARE CIPHER
void polyenc(char str[])
{
    int c = 0;
    
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
                strint[i] = poly[str[i]-'A'];                   //STRINT C
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
  printf("Encrypted Message \n");
  for(i = 0; i < c; i++)
  {
      printf("%d ", strint[i]);
  }
}


//ATBASH CIPHER ALGORITHM
void atbashenc(char str[])
{
    int i;
    int len=strlen(str);
    for(i=0;i<len;i++)                     
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            enc[i]='Z'+'A'-str[i];
        }
        if(str[i]>='a'&&str[i]<='z')
        {
            enc[i]='z'+'a'-str[i];
        } 
    }
    printf("Encrypted Message %s",enc);                     
    printf("\n");
}

//LATIN ALPHABET CIPHER
void la_enc(char plt[])
{
    
	int i, c = 0;
    for(i = 0; i < plt[i] != '\0'; i++)
    {
        strint[i] = (int)plt[i];                                    //STRINT C
        if(strint[i] >= 'A' && strint[i] <= 'Z')
        {
            //append(enc, s - 66);
			strint[i] -= 64;
			c++;
        }
        else if(strint[i] >= 'a' && strint[i] <= 'z')
        {
            //append(enc, s - 98);
			strint[i] -= 96;
			c++;
        }
        if(plt[i] == ' ')
        {
            continue;
        }
    }
	printf("Encrypted Message \n");
    for(i = 0; i < c; i++)
	{
		printf("%d ", strint[i]);
	}

}



int main()
{
    FILE *fp;
    fp = fopen("data.txt","w");
    int i, a, s;
    printf("Enter the text you wish to encrypt \n");
    gets(plt);
    srand(time(0));
    a = rand(); //Randomizing the algorithm chosen 
    if(a%10 >= 1 && a%10 <= 10)
    {
      s = a%10;
      fprintf(fp, "%d \n", s);
      //fputs("\n", fp);
    }
    
    switch(10)
    {
        case 1: keyenc(plt); break; //Works
        case 2: caesarenc(plt); break; //Works with limitations 
        case 3: XORencrypt(plt); break;  //Does not work
        case 4: rotenc(plt); break; //Works with limitations 
        case 5: vernamenc(plt); break;  //Does not work                
        case 6: vigenc(plt); break; //Works?                     
        case 7: printf("WIP \n"); break;
                //PLAYFAIR CIPHER
        case 8: //printf("WIP \n"); break;
                polyenc(plt);
                fprintf(fp, "%s \n", strint); //Doesn't input correct message in the file
                fclose(fp);
                goto c;
        case 9: atbashenc(plt); break; //Works ?                       
        case 10://printf("WIP \n"); break; 
                la_enc(plt);
                for(int i = 0; i < 20; i++)
                {
                fprintf(fp, "%d ", strint[i]); 
                }
                fclose(fp);
                goto c;
        //All the functions for the above ciphers should take "plt" as an argument.
        //Requesting the key must be done within the function. The masking of the key will be done using a separate function.
        //Masking the key is still a work in progress. 
        //Each function should have a return type of char to return the encrypted string which is then stored in the file.
    }
    fprintf(fp, "%s \n", enc); 
    fclose(fp);
    c: return 1;
}
