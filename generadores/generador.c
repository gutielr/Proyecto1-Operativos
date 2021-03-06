#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (argc < 3)
	{
		printf("Uso: %s archivoSalida n1 n2 n3 ...\n",argv[0]);
		return 1;
	}
	int i,num[argc-2];
	FILE *fp;
	for (i = 0; i < argc - 2; ++i)
	{
		errno = 0;
		num[i] = (int) strtol(argv[i+2],NULL,10);
		if (errno)
		{
			printf("Argumento %d invalido.\n", i+1);
			return 1;
		}
	}
	if ((fp = fopen(argv[1], "w")) == NULL)
		perror("fopen:");
	if (fwrite(&num[0], sizeof(int), argc-2, fp) == 0)
		perror("fwrite");
	fclose(fp);
	return 0;
}