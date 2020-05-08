//
//  vm.h
//  compiler
//
//  Created by 吴长江 on 2020/5/6.
//  Copyright © 2020 lucas. All rights reserved.
//

#ifndef vm_h
#define vm_h

#include <stdio.h>
#include "common.h"

struct vm{
    uint32_t allocateBytes;
    Parser *curParser;
};

void initVM(VM*vm);

VM* newVM(void);

#endif /* vm_h */
