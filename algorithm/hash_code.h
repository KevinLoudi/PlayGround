#ifndef HASH_CODE_H_INCLUDED
#define HASH_CODE_H_INCLUDED

#include <string.h>

#define HASHCODE_MULT 31

//Ĭ�ϵ�hashCode
int myHashCodeDefault(void * a);

//int����hashCode
int myHashCodeInt(void * a);

//char���͵�hashCode
int myHashCodeChar(void * a);

//string���͵�hashCode
int myHashCodeString(void * a);

#endif // HASH_CODE_H_INCLUDED
