// Copyright (c) 2021 Pathfinders
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// * All advertising materials mentioning features or use of this software must display the following acknowledgement: This product includes software developed by Pathfinders and its contributors.
// * Neither the name of Pathfinders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef BEDROCKFORMAT_NBT_H
#define BEDROCKFORMAT_NBT_H

#include "binary.h"
#include "hashmap.h"

enum NbtTagType {
    NBT_END,
    NBT_BYTE,
    NBT_SHORT,
    NBT_INT,
    NBT_LONG,
    NBT_FLOAT,
    NBT_DOUBLE,
    NBT_BYTE_ARRAY,
    NBT_STRING,
    NBT_LIST,
    NBT_COMPOUND,
    NBT_INT_ARRAY,
    NBT_LONG_ARRAY
};

const char* NbtTagTypeToString(enum NbtTagType type);

typedef struct NbtTag_T {
    enum NbtTagType type;
    void* payload;
} NbtTag;

char* DecodeRawNbtString(ByteStream* pStream);
int DecodeNbtTagWithParent(ByteStream* pStream, struct hashmap_s* parent);

void PrintNbtTagInner(enum NbtTagType type, void* payload, const char* name, int indentation);
void PrintNbtTag(NbtTag* tag);
void FreeNbtTag(NbtTag* tag);

#endif //BEDROCKFORMAT_NBT_H
