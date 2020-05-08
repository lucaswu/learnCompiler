//
//  common.h
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//

#ifndef common_h
#define common_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct vm VM;
typedef struct parser Parser;
typedef struct class Class;

#define bool char
#define true 1
#define false 0

#define UNUSED __attribute__ ((unused))


#ifdef DEBUG
    #define ASSERT(condition,errMsg) \
        do {\
            if(!(condition)) {\
                fprintf(stderr,"ASSERT failed! %s:%d in function %s():%s\n",\
                __FILE__,__LINE__,__func__,errMsg); \
                abort();\
            }\
        }while(0);
#else
    #define ASSERT(condition,errMsg) ((void)0)
#endif

#define NOT_REACHED() \
    do {\
        fprintf(stderr,"NOT_REACHED:%s:%d In function %s()\n",\
        __FILE__,__LINE__,__func__);\
        while(1);\
    }while(0);

#endif /* common_h */
