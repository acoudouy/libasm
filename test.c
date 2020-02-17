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
}


int         main()
{
    test_strlen();
    return (0);
}
