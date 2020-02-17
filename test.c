#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "./include/libasm.h"


void		test_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
		printf("_____________________________________________\n");
	printf("\n");
	printf("'bonjour' --- [%zu]\n", ft_strlen("bonjour"));
	printf("'bonjour' --- [%zu]\n", strlen("bonjour"));
	printf("\n");
	printf("'salutsalutsalut' --- [%zu]\n", ft_strlen("salutsalutsalut"));
	printf("'salutsalutsalut' --- [%zu]\n", strlen("salutsalutsalut"));
	printf("\n");
	printf("'' --- [%zu]\n", ft_strlen(""));
	printf("'' --- [%zu]\n", strlen(""));
	printf("\n");
	printf("'A' --- [%zu]\n", ft_strlen("A"));
	printf("'A' --- [%zu]\n", strlen("A"));
}

void		test_strcpy()
{
	char dst[100];
	char *str = "qwerty";
	char *d = "0123456";

	printf("FT_STRCPY\n"); /// probleme sur les types de strcpy,
						   /// je ressors un int au lien dun char *
	printf("\n");
	printf("%d : ",ft_strcpy(dst, "bonjour")); // segfault si je demande un %s
	printf("dest: [%s]\n", dst);
	printf("%s : ",strcpy(dst, "bonjour"));
	printf("dest: [%s]\n", dst);
	printf("%d : ",ft_strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
    printf("%s : ",strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
	printf("%d : ",ft_strcpy(dst, str));    
	printf("dest: [%s]\n", dst);
    printf("%s : ",strcpy(dst, str));
    printf("dest: [%s]\n", dst);
}

int         main()
{
  //  test_strlen();
    test_strcpy();
    return (0);
}
