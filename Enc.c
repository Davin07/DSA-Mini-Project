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
