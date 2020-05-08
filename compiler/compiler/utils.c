//
//  utils.c
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//

#include "utils.h"
#include "vm.h"

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
