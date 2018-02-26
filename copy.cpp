#include<stdio.h>
#include<stdlib.h>
const int MAXSIZE=1030;
int main(int argc,char **argv )
{
    if(argc<3)
    {
        printf("two few arguments\n");
        return 0;
    }
	FILE *fpr,*fpw;
	fpr=fopen(argv[1],"rb");
    if(fpr==NULL)
    {
        printf("open source file  failed!\n");
        return;
    }
	fpw=fopen(argv[2],"wb");
    if(fpw==NULL)
    {
        printf("open target file failed!\n");
        return ;
    }
	int readnum=0;
    int index=0;
	char buf[MAXSIZE];
    fflush(stdout);
    while(1)
    {
        readnum=fread(buf, sizeof(char),1024,fpr);
        if(readnum<1024)
        {
			fwrite(buf,sizeof(char),readnum,fpw);
        }
		fwrite(buf,sizeof(char),1024,fpw);
    }
    fclose(fpr);
	fclose(fpw);
    return ;
}

	