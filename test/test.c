#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "../include/libasm.h"

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
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT"); // OK! 
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
	printf("\n");
	printf("\n");
}

void		test_strcpy()
{
	char dst[100];
	char *str = "qwerty";
	char *d = "0123456";

	printf("\x1b[32mft_strcpy :\x1b[0m\n"); /// probleme sur les types de strcpy,
						   					/// je ressors un int au lien dun char *
	printf("\n");
	printf("%s : ",ft_strcpy(dst, "bonjour")); // segfault si je demande un %s
	printf("dest: [%s]\n", dst);
	printf("%s : ",strcpy(dst, "bonjour"));
	printf("dest: [%s]\n", dst);
	printf("%s : ",ft_strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
    printf("%s : ",strcpy(dst, ""));
    printf("dest: [%s]\n", dst);
	printf("%s : ",ft_strcpy(dst, str));    
	printf("dest: [%s]\n", dst);
    printf("%s : ",strcpy(dst, str));
    printf("dest: [%s]\n", dst);
	printf("\n");

	char *ret = NULL;
	char z[] = "11111111111";
	char s[] = "222222";
	char e[] = "";
	char n[] = "dsqdqd";
	printf("1 before copy ->\nd: %s\ns: %s\nret: %s\n", z, s, ret);
	ret = ft_strcpy(z, s);
	printf("1 after copy ->\nd: %s\ns: %s\nret: %s\n", z, s, ret);
	printf("d[7] -- %c \n", z[7]);
	ret = ft_strcpy(n, e);
	printf("srcs empty d: %s\n", ret);
	printf("\n");

	char *ret2 = NULL;
	char d2[] = "richardcoeurdelion";
	char s2[] = "henri";
	printf("2 before copy->\nd: %s\ns: %s\nret: %s\n", d2, s2, ret2);
	ret2 = ft_strcpy(d2, s2);
	printf("2 after copy->\nd: %s\ns: %s\nret: %s\n", d2, s2, ret2);
	printf("d[7] -- %c \n", d2[7]);
	printf("\n");

	char *ret3 = NULL;
	char d3[] = "richa";
	char s3[] = "henri";
	printf("3 before copy->\nd: %s\ns: %s\nret: %s\n", d3, s3, ret3);
	ret3 = ft_strcpy(d3, s3);
	printf("3 after copy->\nd: %s\ns: %s\nret: %s\n", d3, s3, ret3);
	printf("\n");

}

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
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
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
	printf("res = %zd : ", write(1, "", 10));
	printf("\n");
	printf("res = %zd : ", ft_write(1, "", 10));
	printf("\n");
}


void		test_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(NULL));
}


void		test_read()
{
	char	dest[100];
	int		fd;
	char	buf[10000];
		printf("_____________________________________________\n");
	printf("FT_READ\n");
	printf("TEST1\n");
	fd = open("inc/libasm.h", O_RDONLY);
	read(fd, buf, 100);
	printf("[%s]\n", buf);
	close(fd);
	fd = open("libasm.h", O_RDONLY);
	ft_read(fd, buf, 100);
	printf("[%s]\n", buf);
	close(fd);
	printf("TEST2\n");
	fd = open("test_read.txt", O_RDONLY);
	read(fd, buf, 500);
	printf("[%s]\n", buf);
	close(fd);
	fd = open("text_read.txt", O_RDONLY);
	ft_read(fd, buf, 500);
	printf("[%s]\n", buf);
	close(fd);
}
*/
void			test_strcmp()
{
	char *a = "qwerty";
	char *b = "qwertz";
	char *c = "1235";
	char *d = "1234";
	printf("Test 1\n");
	printf("%d | \n", strcmp(a,b));
	printf("%d | \n", ft_strcmp(a,b));
	printf("Test 2\n");
	printf("%d | \n", strcmp(c,d));
	printf("%d | \n", ft_strcmp(c,d));
	printf("Test 3\n");
	printf("%d | \n", strcmp(a,a));
	printf("%d | \n", ft_strcmp(a,a));
	printf("Test 4\n");
	printf("%d | \n", strcmp("",""));
	printf("%d | \n", ft_strcmp("",""));
}
int         main()
{
//    test_strlen();
  //  test_strcpy();
  //	test_write();
 // 	test_strdup();
//  	test_read();
	test_strcmp();
    return (0);
}
