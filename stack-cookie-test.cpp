#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include <fstream>

#define BUFFERSIZE 100001

using namespace std;

void CopyInput(char* filecontent, char* buffer1)
{
	char buffer[500];
	
	try
	{
		printf("[*] filecontent size: %d\n", strlen(filecontent)); 
		//printf("[*] String read from file: %s\n", filecontent);
        strcpy(buffer,filecontent);
		strcpy(buffer1, buffer);
		//strcpy(out,buffer);
        //printf("[*] Input received : %s\n",buffer);
	}
	catch (char * strErr)
	{
		printf("[-] No valid input received ! \n");
		printf("[-] Exception : %s\n",strErr);
	}
}

int main(int argc, char* argv[])
{
    if (argc < 2) { 
		printf("%s <payload-to-read>", argv[0]);
		return 1;
	}

	char* filename = argv[1];
	printf("[*] File being opened: %s\n", filename);

	char filecontent[BUFFERSIZE];
	FILE* f = fopen(filename, "rb+");

	printf("[*] File being read: %s\n", filename);
	fseek(f, 0, SEEK_SET);
	int ncharsread = fread((char*)filecontent, sizeof(char), BUFFERSIZE-1, f);
	filecontent[ncharsread] = '\0';
	fclose(f);

	/*printf("[*] Read data being displayed\n");
	int i;
	for (i=0; i < strlen(filecontent); ++i) {
		printf("%c", filecontent[i]);
	}
	printf("\n");*/
	char buffer1[128];
    CopyInput(filecontent, buffer1);

    return 0;
}
