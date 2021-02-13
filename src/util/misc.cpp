//
// Created by mart on 2/12/21.
//

#include "misc.h"

uint FUN_00063c3c(byte *param_1,int param_2) {
    byte *pbVar1;
    int iVar3;
    uint uVar4;
    uint uVar5;
    uint *puVar6;
    uint uStack1036;
    uint local_408 [256];
    byte *pbVar2;

    puVar6 = &uStack1036;
    uVar5 = 0;
    do {
        iVar3 = 8;
        uVar4 = uVar5;
        do {
            if ((uVar4 & 1) == 0) {
                uVar4 = uVar4 >> 1;
            }
            else {
                uVar4 = uVar4 >> 1 ^ 0xedb88320;
            }
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 1;
        *puVar6 = uVar4;
    } while (uVar5 != 0x100);
    if (param_2 == 0) {
        return 0;
    }
    uVar5 = 0xffffffff;
    pbVar2 = param_1;
    do {
        pbVar1 = pbVar2 + 1;
        uVar5 = local_408[(*pbVar2 ^ uVar5) & 0xff] ^ uVar5 >> 8;
        pbVar2 = pbVar1;
    } while (pbVar1 != param_1 + param_2);
    return ~uVar5;
}

float FUN_00067ef8(float param_1,float param_2) {
    undefined4 in_cr0;

    coprocessor_function(10,6,4,in_cr0,in_cr0,in_cr0);
    param_2 = -1.0 / param_2;
    expf(param_1);
    return 1.0 - param_2;
}
