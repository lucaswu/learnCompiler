//
//  unicodeUtf8.h
//  compiler
//
//  Created by 吴长江 on 2020/5/11.
//  Copyright © 2020 lucas. All rights reserved.
//

#ifndef unicodeUtf8_h
#define unicodeUtf8_h

#include <stdio.h>
#include <stdint.h>

uint32_t getByteNumOfEncodeUtf8(int value);
uint32_t getByteNumOfDecoderUtf8(uint8_t byte);
uint8_t encodeUtf8(uint8_t *buf,int value);
int decodeUtf8(const uint8_t*bytePtr,uint32_t length);

#endif /* unicodeUtf8_h */
