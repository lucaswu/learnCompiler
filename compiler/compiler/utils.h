//
//  utils.h
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//

#ifndef utils_h
#define utils_h

#include <stdio.h>
#include "common.h"

void *memManager(VM* vm,void*ptr,uint32_t oldSize,uint32_t newSize);

#define ALLOCATE(vmPtr,type)\
    (type*)memManager(vmPtr,NULL,0,sizeof(type))

#define ALLOCATE_EXTRA(vmPtr,mainType,extraSize) \
    (mainType*)memManager(vmPtr,NULL,0,sizeof(mainType)+extraSize)

#define ALLOCATE_ARRAY(vmPtr,type,count) \
    (type*)memManager(vmPtr,NULL,0,sizeof(type)*count)

#define DEALLOCATE(vmPtr,memPtr) memManager(vmPtr,memPtr,0,0)

uint32_t ceilToPowerOf2(uint32_t v);

typedef struct {
    char* str;
    uint32_t length;
} String;

typedef struct{
    uint32_t length;
    char start[0];
} CharValue;


#define DECLARE_BUFFER_TYPE(type) \
    typedef struct{\
        /*数据缓冲区*/ \
        type*datas;\
        /*已使用的元素个数*/ \
        uint32_t count;\
        uint32_t capacity;\
    }type##Buffer;\
    void type##BufferInit(type##Buffer*buf);\
    void type##BufferFillWrite(VM*vm,type##Buffer *buf,type data,uint32_t fillCount)\
    void type##BufferAdd(VM*vm,type##Buffer *buf,type data);\
    void type##BufferClear(VM*vm,type##Buffer);

#define DEFINE_BUFFER_METHOD(type) \
    void type##BufferInit(type##Buffer *buf){\
        buf->datas = NULL;\
        buf->count = buf->capacity = 0;\
    }\
    \
    void type##BufferFillWrite(VM*vm,type##Buffer *buf,type data,uint32_t fillCount){\
        uint32_t newCounts = buf->count + fillCount;\
        if(newCounts > buf->capacity){\
            size_t oldSize = buf->capacity*sizeof(type);\
            buf->capacity = ceilToPowerOf2(newCounts);\
            size_t newSize = buf->capacity*sizeof(type);\
            ASSERT(newSize > oldSize, "faint...memory allocate!");\
            buf->datas = (type*)memManager(vm,buf->datas,oldSize,newSize);\
        }\
        uint32_t cnt = 0;\
        while(cnt<fillCount){\
            buf->datas[buf->count++] = data;\
            cnt++;\
        }\
    }\
    \
    void type##BufferAdd(VM*vm,type##Buffer *buf,type data){\
        type##BufferFillWrite(vm,buf,data,1);\
    }\
    \
    void type##BufferClear(VM*vm,type##Buffer){\
        size_t oldSize = buf->capacity*sizeof(buf->datas[0]);\
        memManager(vm,buf->datas,oldSize,0);\
        type##BufferInit(buf);\
    }
#endif /* utils_h */
