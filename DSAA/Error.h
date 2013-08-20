#ifndef _ERROR_H
#define _ERROR_H
#include<stdio.h>
#include<stdlib.h>
static void FateErrors(char * message)
{
	printf("%s\n",message);
	exit(-1);
}
#endif