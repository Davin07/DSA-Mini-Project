#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

char enc[100], plt[100], dec[100];
int key;

void caesar_en(char plt[])
{

    char ch;
    int i;
	printf("Enter key: ");
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

void caesar_de(char enc [], int key)
{
    char ch;
	int i;
	
	for(i = 0; enc[i] != '\0'; ++i){
		ch = enc[i];
		if(isalpha(plt[i]))
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


void main()
{
    
    printf("Enter the message \n");
    gets(plt);
    caesar_en(plt);
    caesar_de(enc, key);
}

 
