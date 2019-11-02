//Vigenere Cipher Encrypt
void Cipher(char key[],char str[])
{
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
    
    Block to convert letters to Upper Case
    My compiler did not accept "strupr(str)" function*/
    
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
        str[i]=((str[i]+key[i])%26)+'A';
    }
    str[i]='\0';
    printf("%s\n",str);
}
