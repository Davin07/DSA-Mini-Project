//Vigenere Cipher Encrypt
void Decipher(char key[],char str[])
{
    //Perform opposite operation of Encrypt
    for(i=0;i<strlen(str);i++)
    {
        str[i] = (((str[i] - key[i]) + 26) % 26) + 'A';
    }
    printf("%s\n",str);
}
