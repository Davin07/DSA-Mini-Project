//LATIN ALPHABET CIPHER
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int removeSpaces(char* plain, int ps) 
{ 
    int i, count = 0; 
    for (i = 0; i < ps; i++) 
        if (plain[i] != ' ') 
            plain[count++] = plain[i]; 
    plain[count] = '\0'; 
    return count; 
} 

char dec[500];
int c = 0;
int strint[100];

void la_enc(char plt[])
{
    
	int i;
    for(i = 0; i < plt[i] != '\0'; i++)
    {
        strint[i] = (int)plt[i];
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
		
    for(i = 0; i < c; i++)
	{
		printf("%d ", strint[i]);
	}

} 

void la_dec(int strint[])
{
	int i;
	for(i = 0; i < c; i++)
	{
		if(strint[i] != -1)
		{
			dec[i] = strint[i] + 'A' - 1;
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
    char plt[100];
    printf("Enter \n");
    gets(plt);
	removeSpaces(plt, strlen(plt));
    la_enc(plt);
	la_dec(strint);
}
     
