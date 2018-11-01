//
// Created by Salmon on 2018/11/1.
//
#include "skf.h"
#include <stdio.h>

void SKF_GetDevinfo(){
    printf("this is called by method SKF_GetDevinfo....\n");

#ifdef KOAL_SSL_EXTENSION
    printf("this is should be printed!. when define KOAL_SSL_EXTENSION\n");
#endif

#ifdef NO_MARCO
    printf("this is shouldn`t be called.\n");
#endif
}