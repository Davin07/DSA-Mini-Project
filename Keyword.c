//KEYWORD CIPHER
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

void append(char* s, char c) 
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

char ciphertext[26], enc[100], dec[100], key[100];

void keyenc(char plt[])
{
    char ch, ch1;
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
	puts(enc);
    
}    

void keydec(char enc[], char key[])
{
	char plaintext[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pos, i;
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

void main()
{
    char plt[] = "GEEKS FOR GEEKS";
    keyenc(plt);
	keydec(enc, key);
}

