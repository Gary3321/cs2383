#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool ReadFile(char* filePath)
{
	// lines with labels must have them in the first column.
    // lines without labels must have a blank in the first column.
    char data[1000];
    FILE *fp=fopen(filePath,"r");
    if(!fp)
    {
        printf("can't open file\n");
        return false;
    }

    while ((fgets(data,1000,fp))!=NULL)
	{
		if(strlen(data)!=1) //don't read empty line,empty line also read "\n". 
			printf("%s",data);
	}
    fclose(fp);
    return true;
}

int main()
{
    ReadFile("1.txt");
    return 0;
}
