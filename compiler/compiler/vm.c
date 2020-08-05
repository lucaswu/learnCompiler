//
//  vm.c
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//

#include "vm.h"
#include "utils.h"

void initVM(VM*vm)
{
    vm->allocateBytes = 0;
    vm->curParser = NULL;
}

VM* newVM(void)
{
    VM*vm = (VM*)malloc(sizeof(VM));
    if(vm == NULL){
        MEM_ERROR("allocate VM failed");
    }
    initVM(vm);
    return vm;
}
