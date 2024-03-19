#include "dynamic.h"
#include <stdio.h>
#include <string.h>

int dynamic_lib_function(char* msg)
{
    printf("Hi i'm a dynamic lib that receives '%s' and return '%ld' \n", msg, strlen(msg));
    return strlen(msg);
}