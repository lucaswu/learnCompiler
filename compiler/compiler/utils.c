//
//  utils.c
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//
#include <stdarg.h>
#include "utils.h"
#include "vm.h"
#include "parser.h"

void *memManager(VM* vm,void*ptr,uint32_t oldSize,uint32_t newSize)
{
    vm->allocateBytes += newSize - oldSize;
    if(newSize == 0){
        free(ptr);
        return NULL;
    }
    
    return realloc(ptr,newSize);
}


uint32_t ceilToPowerOf2(uint32_t v)
{
    v += (v ==0);
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

DEFINE_BUFFER_METHOD(String)
DEFINE_BUFFER_METHOD(Int)
DEFINE_BUFFER_METHOD(Char)
DEFINE_BUFFER_METHOD(Byte)

//通用报错函数
void errorReport(void* parser,ErrorType errorType, const char* fmt, ...) {
    char buffer[DEFAULT_BUfFER_SIZE] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buffer, DEFAULT_BUfFER_SIZE, fmt, ap);
    va_end(ap);

    switch (errorType) {
        case ERROR_IO:
        case ERROR_MEM:
            fprintf(stderr, "%s:%d In function %s():%s\n",__FILE__, __LINE__, __FUNCTION__, buffer);
            break;
        case ERROR_LEX:
        case ERROR_COMPILE:
            ASSERT(parser != NULL, "parser is null!");
            fprintf(stderr, "%s:%d \"%s\"\n", ((Parser*)parser)->file,((Parser*)parser)->preToken.lineNo, buffer);
            break;
        case ERROR_RUNTIME:
            fprintf(stderr, "%s\n", buffer);
            break;
        default:
            NOT_REACHED();
    }
    exit(1);
}
