#include <sys/xattr.h>
#include<attr/xattr.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#define XATTR_SIZE 10000

int
main(int argc, char *argv[])
{
    setxattr(argv[1], argv[2], argv[3],strlen(argv[3]),0);
}
