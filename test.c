#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "./include/libasm.h"

/*
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
	printf("%d : ",strcpy(dst, "bonjour"));
	printf("dest: [%s]\n", dst);
	printf("%d : ",ft_strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
    printf("%d : ",strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
	printf("%d : ",ft_strcpy(dst, str));    
	printf("dest: [%s]\n", dst);
    printf("%d : ",strcpy(dst, str));
    printf("dest: [%s]\n", dst);
}
*/

void		test_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.h> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
	printf("_____________________________________________\n");
	printf("FT_WRITE\n");
	write(1, "bonjour", 7);
	printf("\n");
	ft_write(1, "bonjour", 7);
	printf("\n");
	write(1, "qwert\nqwert\n", 12);
	ft_write(1, "qwert\nqwert\n", 12);
	write(1, "", 0);
	printf("\n");
	ft_write(1, "", 0);
	printf("\n");
}

int         main()
{
  //  test_strlen();
  //  test_strcpy();
  	test_write();
    return (0);
}
