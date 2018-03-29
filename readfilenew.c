#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <map.h>
bool ReadFile(char* filePath)
{
	// lines with labels must have them in the first column.
    // lines without labels must have a blank in the first column.
    typedef map<string,int> mymap;
    mymap Map;
    char data[1000];
    char str1[2];
    //有一个函数叫strstr，原型是 char *strstr(char *str1, char *str2)，功能是找出str2字符串在str1字符串中第一次出现的位置
    FILE *fp=fopen(filePath,"r");
    if(!fp)
    {
        printf("can't open file\n");
        return false;
    }
     char * ptr;
    while ((fgets(data,1000,fp))!=NULL)
	{

		if(strlen(data)!=1) //don't read empty line,empty line also read "\n".
			printf("%s",data);
        //ptr =strtok(data," ");
        //strncpy(str1,data,1);
        //if (strlen(data[0]))
        if (data[0]!=' ')
        printf("str2=%c",data[0]);
	}
    fclose(fp);
    return true;
}

int main()
{
    ReadFile("1.txt");
    return 0;
}
