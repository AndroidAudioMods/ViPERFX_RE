//
// Created by mart on 2/12/21.
//

#include "CRevModel.h"

// CRevModel::~CRevModel()

CRevModel::~CRevModel() {
    if (this->field_0x270 != nullptr) {
        operator_delete__(this->field_0x270);
    }
    if (this->field_0x274 != nullptr) {
        operator_delete__(this->field_0x274);
    }
    if (this->field_0x278 != nullptr) {
        operator_delete__(this->field_0x278);
    }
    if (this->field_0x27c != nullptr) {
        operator_delete__(this->field_0x27c);
    }
    if (this->field_0x280 != nullptr) {
        operator_delete__(this->field_0x280);
    }
    if (this->field_0x284 != nullptr) {
        operator_delete__(this->field_0x284);
    }
    if (this->field_0x288 != nullptr) {
        operator_delete__(this->field_0x288);
    }
    if (this->field_0x28c != nullptr) {
        operator_delete__(this->field_0x28c);
    }
    if (this->field_0x290 != nullptr) {
        operator_delete__(this->field_0x290);
    }
    if (this->field_0x294 != nullptr) {
        operator_delete__(this->field_0x294);
    }
    if (this->field_0x298 != nullptr) {
        operator_delete__(this->field_0x298);
    }
    if (this->field_0x29c != nullptr) {
        operator_delete__(this->field_0x29c);
    }
    if (this->field_0x2a0 != nullptr) {
        operator_delete__(this->field_0x2a0);
    }
    if (this->field_0x2a4 != nullptr) {
        operator_delete__(this->field_0x2a4);
    }
    if (this->field_0x2a8 != nullptr) {
        operator_delete__(this->field_0x2a8);
    }
    if (this->field_0x2ac != nullptr) {
        operator_delete__(this->field_0x2ac);
    }
    if (this->field_0x2b0 != nullptr) {
        operator_delete__(this->field_0x2b0);
    }
    if (this->field_0x2b4 != nullptr) {
        operator_delete__(this->field_0x2b4);
    }
    if (this->field_0x2b8 != nullptr) {
        operator_delete__(this->field_0x2b8);
    }
    if (this->field_0x2bc != nullptr) {
        operator_delete__(this->field_0x2bc);
    }
    if (this->field_0x2c0 != nullptr) {
        operator_delete__(this->field_0x2c0);
    }
    if (this->field_0x2c4 != nullptr) {
        operator_delete__(this->field_0x2c4);
    }
    if (this->field_0x2c8 != nullptr) {
        operator_delete__(this->field_0x2c8);
    }
    if (this->field_0x2cc != nullptr) {
        operator_delete__(this->field_0x2cc);
    }
    return this;
}



// CRevModel::ProcessReplace(int*, int*, int)

void CRevModel::ProcessReplace(int *param_1,int *param_2,int param_3) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    longlong lVar5;
    longlong lVar6;
    int iVar7;
    CCombFilter *this_00;
    CAllpassFilter *this_01;
    uint uVar8;
    int iVar9;
    int iVar10;
    CAllpassFilter *this_02;
    int iVar11;
    int iVar12;
    int iVar13;
    int *piVar14;
    int *local_40;
    int local_3c;

    if ((this->field_0x0 != 0) && (local_3c = param_3 + -1, 0 < param_3)) {
        piVar14 = param_2 + 2;
        local_40 = param_1 + 2;
        do {
            iVar10 = piVar14[-2];
            iVar11 = 0;
            iVar9 = local_40[-2];
            iVar13 = 0;
            iVar12 = 0;
            lVar1 = (longlong)(iVar9 + iVar10) * (longlong)*(int *)&this->field_0x4 + 0x1000000;
            uVar8 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
            do {
                iVar7 = CCombFilter::Process
                        ((CCombFilter *)((int)&this->field_0x30[0].feedback + iVar11),uVar8);
                iVar12 = iVar12 + iVar7;
                this_00 = (CCombFilter *)((int)&this->field_0x110[0].feedback + iVar11);
                iVar11 = iVar11 + 0x1c;
                iVar7 = CCombFilter::Process(this_00,uVar8);
                iVar13 = iVar13 + iVar7;
            } while (iVar11 != 0xe0);
            iVar11 = 4;
            this_02 = this->field_0x1f0;
            do {
                iVar12 = CAllpassFilter::Process(this_02,iVar12);
                this_01 = this_02 + 4;
                this_02 = this_02 + 1;
                iVar13 = CAllpassFilter::Process(this_01,iVar13);
                iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            local_3c = local_3c + -1;
            lVar1 = (longlong)iVar13 * (longlong)*(int *)&this->field_0x20 + 0x1000000;
            lVar2 = (longlong)*(int *)&this->field_0x1c * (longlong)iVar13 + 0x1000000;
            lVar3 = (longlong)iVar12 * (longlong)*(int *)&this->field_0x1c + 0x1000000;
            lVar4 = (longlong)iVar12 * (longlong)*(int *)&this->field_0x20 + 0x1000000;
            lVar5 = (longlong)iVar9 * (longlong)this->field_0x24 + 0x1000000;
            lVar6 = (longlong)this->field_0x24 * (longlong)iVar10 + 0x1000000;
            local_40[-2] = ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7) +
                           ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                           ((uint)lVar5 >> 0x19 | (int)((ulonglong)lVar5 >> 0x20) << 7);
            piVar14[-2] = ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
                          ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7) +
                          ((uint)lVar6 >> 0x19 | (int)((ulonglong)lVar6 >> 0x20) << 7);
            piVar14 = piVar14 + 2;
            local_40 = local_40 + 2;
        } while (local_3c != -1);
    }
    return;
}



// CRevModel::UpdateCoeffs()

void CRevModel::UpdateCoeffs() {
    int iVar1;
    longlong lVar2;
    longlong lVar3;
    uint uVar4;
    CCombFilter *this_00;
    uint uVar5;
    int iVar6;
    CCombFilter *this_01;
    CCombFilter *pCVar7;
    undefined8 uVar8;
    undefined8 uVar9;
    ulonglong uVar10;
    ulonglong uVar11;

    if (this->field_0x0 == 0) {
        return;
    }
    iVar6 = this->field_0x28;
    uVar4 = this->field_0x18;
    uVar8 = VectorShiftRight(CONCAT44(iVar6,iVar6),0x20);
    uVar8 = VectorShiftLeft(uVar8,0x19,0x40,0);
    uVar9 = VectorShiftRight(CONCAT44(0x2000000 - iVar6,0x2000000 - iVar6),0x20);
    uVar9 = VectorShiftLeft(uVar9,0x19,0x40,0);
    iVar6 = (int)((longlong)uVar8 >> 0x3f);
    iVar1 = (int)((longlong)uVar9 >> 0x3f);
    uVar10 = VectorShiftRight(CONCAT44(iVar6,iVar6),0x20);
    uVar11 = VectorShiftRight(CONCAT44(iVar1,iVar1),0x20);
    uVar8 = VectorAdd(uVar10 & 0x3ffffff,uVar8,8);
    uVar9 = VectorAdd(uVar11 & 0x3ffffff,uVar9,8);
    uVar8 = VectorShiftRight(uVar8,0x1a);
    uVar10 = VectorShiftRight(uVar9,0x1a);
    lVar2 = (longlong)(int)uVar4 * (longlong)((int)uVar8 + 0x1000000) + 0x1000000;
    lVar3 = (uVar10 & 0xffffffff) * (ulonglong)uVar4;
    uVar5 = (uint)lVar3;
    *(uint *)&this->field_0x1c = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
    *(uint *)&this->field_0x20 =
            uVar5 + 0x1000000 >> 0x19 |
            ((int)uVar10 * ((int)uVar4 >> 0x1f) + uVar4 * (int)(uVar10 >> 0x20) +
             (int)((ulonglong)lVar3 >> 0x20) + (uint)(0xfeffffff < uVar5)) * 0x80;
    if (this->field_0x2c < 0x1000000) {
        uVar4 = this->field_0x8;
        *(undefined **)&this->field_0x4 = &DAT_0007ae14;
        *(uint *)&this->field_0xc = uVar4;
        *(uint *)&this->field_0x14 = this->field_0x10;
    }
    else {
        uVar4 = 0x2000000;
        *(undefined4 *)&this->field_0xc = 0x2000000;
        *(undefined4 *)&this->field_0x14 = 0;
        *(undefined4 *)&this->field_0x4 = 0;
    }
    this_01 = this->field_0x30;
    pCVar7 = this_01;
    while( true ) {
        CCombFilter::SetFeedback(pCVar7,uVar4);
        this_00 = pCVar7 + 8;
        pCVar7 = pCVar7 + 1;
        CCombFilter::SetFeedback(this_00,*(int *)&this->field_0xc);
        if (pCVar7 == this->field_0x110) break;
        uVar4 = *(uint *)&this->field_0xc;
    }
    do {
        CCombFilter::SetDamp(this_01,*(int *)&this->field_0x14);
        pCVar7 = this_01 + 8;
        this_01 = this_01 + 1;
        CCombFilter::SetDamp(pCVar7,*(int *)&this->field_0x14);
    } while (this_01 != this->field_0x110);
    return;
}



// CRevModel::SetRoomSize(int)

void CRevModel::SetRoomSize(int param_1) {
    longlong lVar1;

    if (this->field_0x0 == 0) {
        return;
    }
    lVar1 = (longlong)param_1 * 0x8f5c2a + 0x1000000;
    this->field_0x8 = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) + 0x1666666;
    UpdateCoeffs(this);
    return;
}



// CRevModel::GetRoomSize()

void CRevModel::GetRoomSize(void) {
    int in_r0;
    uint uVar1;

    uVar1 = *(int *)(in_r0 + 8) + 0xfe99999a;
    __aeabi_ldivmod(uVar1 * 0x2000000,((int)uVar1 >> 0x1f) << 0x19 | uVar1 >> 7,0x8f5c2a,0);
    return;
}



// CRevModel::SetDamp(int)

void CRevModel::SetDamp(int param_1) {
    longlong lVar1;

    if (this->field_0x0 == 0) {
        return;
    }
    lVar1 = (longlong)param_1 * 0xccccce + 0x1000000;
    this->field_0x10 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
    UpdateCoeffs(this);
    return;
}



// CRevModel::GetDamp()

void CRevModel::GetDamp(void) {
    int in_r0;
    uint uVar1;

    uVar1 = *(uint *)(in_r0 + 0x10);
    __aeabi_ldivmod(uVar1 << 0x19,((int)uVar1 >> 0x1f) << 0x19 | uVar1 >> 7,0xccccce,0);
    return;
}



// CRevModel::SetWet(int)

void CRevModel::SetWet(int param_1) {
    longlong lVar1;

    if (this->field_0x0 == 0) {
        return;
    }
    lVar1 = (longlong)param_1 * 0x6000000 + 0x1000000;
    this->field_0x18 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
    UpdateCoeffs(this);
    return;
}



// CRevModel::GetWet()

void CRevModel::GetWet(void) {
    int in_r0;
    uint uVar1;

    uVar1 = *(uint *)(in_r0 + 0x18);
    __aeabi_ldivmod(uVar1 << 0x19,((int)uVar1 >> 0x1f) << 0x19 | uVar1 >> 7,0x6000000,0);
    return;
}



// CRevModel::SetDry(int)

void CRevModel::SetDry(int param_1) {
    if (this->field_0x0 == 0) {
        return;
    }
    this->field_0x24 = param_1 << 1;
    return;
}



// CRevModel::GetDry()

undefined8 CRevModel::GetDry() {
    int iVar1;
    undefined8 uVar2;
    ulonglong uVar3;

    uVar2 = VectorShiftRight(CONCAT44(this->field_0x24,this->field_0x24),0x20);
    uVar2 = VectorShiftLeft(uVar2,0x19,0x40,0);
    iVar1 = (int)((longlong)uVar2 >> 0x3f);
    uVar3 = VectorShiftRight(CONCAT44(iVar1,iVar1),0x20);
    uVar2 = VectorAdd(uVar3 & 0x3ffffff,uVar2,8);
    uVar2 = VectorShiftRight(uVar2,0x1a);
    return uVar2;
}



// CRevModel::SetWidth(int)

void CRevModel::SetWidth(int param_1) {
    if (this->field_0x0 == 0) {
        return;
    }
    this->field_0x28 = param_1;
    UpdateCoeffs(this);
    return;
}



// CRevModel::GetWidth()

int CRevModel::GetWidth() {
    return this->field_0x28;
}



// CRevModel::SetMode(int)

void CRevModel::SetMode(int param_1) {
    if (this->field_0x0 == 0) {
        return;
    }
    this->field_0x2c = param_1;
    UpdateCoeffs(this);
    return;
}



// CRevModel::GetMode()

undefined4 CRevModel::GetMode() {
    undefined4 uVar1;

    if (this->field_0x2c < 0x1000000) {
        uVar1 = 0;
    }
    else {
        uVar1 = 0x2000000;
    }
    return uVar1;
}



// CRevModel::Mute()

void CRevModel::Mute() {
    int iVar1;
    CCombFilter *this_00;
    CAllpassFilter *this_01;
    CAllpassFilter *this_02;

    if (this->field_0x0 == 0) {
        return;
    }
    iVar1 = GetMode(this);
    if (0xffffff < iVar1) {
        return;
    }
    iVar1 = 0;
    do {
        CCombFilter::Mute((CCombFilter *)((int)&this->field_0x30[0].feedback + iVar1));
        this_00 = (CCombFilter *)((int)&this->field_0x110[0].feedback + iVar1);
        iVar1 = iVar1 + 0x1c;
        CCombFilter::Mute(this_00);
    } while (iVar1 != 0xe0);
    this_02 = this->field_0x1f0;
    iVar1 = 4;
    do {
        CAllpassFilter::Mute(this_02);
        this_01 = this_02 + 4;
        this_02 = this_02 + 1;
        CAllpassFilter::Mute(this_01);
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    return;
}



void CRevModel::~ZN9CRevModel5ResetEv() {
    int iVar1;
    CCombFilter *this_00;
    CAllpassFilter *this_01;
    CAllpassFilter *this_02;

    if (this->field_0x0 == 0) {
        return;
    }
    iVar1 = GetMode(this);
    if (0xffffff < iVar1) {
        return;
    }
    iVar1 = 0;
    do {
        CCombFilter::Mute((CCombFilter *)((int)&this->field_0x30[0].feedback + iVar1));
        this_00 = (CCombFilter *)((int)&this->field_0x110[0].feedback + iVar1);
        iVar1 = iVar1 + 0x1c;
        CCombFilter::Mute(this_00);
    } while (iVar1 != 0xe0);
    this_02 = this->field_0x1f0;
    iVar1 = 4;
    do {
        CAllpassFilter::Mute(this_02);
        this_01 = this_02 + 4;
        this_02 = this_02 + 1;
        CAllpassFilter::Mute(this_01);
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    return;
}



// CRevModel::CRevModel()

CRevModel::CRevModel() {
    void *pvVar1;
    CCombFilter *pCVar2;
    CCombFilter *pCVar3;
    CAllpassFilter *pCVar4;
    CAllpassFilter *pCVar5;
    CAllpassFilter *pCVar6;
    CCombFilter *this_00;
    CAllpassFilter *this_01;

    this_00 = this->field_0x110;
    pCVar3 = this->field_0x30;
    do {
        pCVar2 = pCVar3 + 1;
        CCombFilter::CCombFilter(pCVar3);
        pCVar3 = pCVar2;
    } while (pCVar2 != this_00);
    pCVar6 = this->field_0x1f0;
    pCVar3 = this_00;
    do {
        pCVar2 = pCVar3 + 1;
        CCombFilter::CCombFilter(pCVar3);
        pCVar3 = pCVar2;
    } while (pCVar2 != (CCombFilter *)pCVar6);
    this_01 = this->field_0x1f0 + 4;
    pCVar5 = pCVar6;
    do {
        pCVar4 = pCVar5 + 1;
        CAllpassFilter::CAllpassFilter(pCVar5);
        pCVar5 = pCVar4;
    } while (pCVar4 != this_01);
    pCVar5 = this_01;
    do {
        pCVar4 = pCVar5 + 1;
        CAllpassFilter::CAllpassFilter(pCVar5);
        pCVar5 = pCVar4;
    } while (pCVar4 != (CAllpassFilter *)&this->field_0x270);
    this->field_0x0 = 0;
    pvVar1 = operator_new__(0x1170);
    this->field_0x270 = pvVar1;
    pvVar1 = operator_new__(0x11cc);
    this->field_0x274 = pvVar1;
    pvVar1 = operator_new__(0x1290);
    this->field_0x278 = pvVar1;
    pvVar1 = operator_new__(0x12ec);
    this->field_0x27c = pvVar1;
    pvVar1 = operator_new__(0x13f4);
    this->field_0x280 = pvVar1;
    pvVar1 = operator_new__(0x1450);
    this->field_0x284 = pvVar1;
    pvVar1 = operator_new__(0x1530);
    this->field_0x288 = pvVar1;
    pvVar1 = operator_new__(0x158c);
    this->field_0x28c = pvVar1;
    pvVar1 = operator_new__(0x1638);
    this->field_0x290 = pvVar1;
    pvVar1 = operator_new__(0x1694);
    this->field_0x294 = pvVar1;
    pvVar1 = operator_new__(0x174c);
    this->field_0x298 = pvVar1;
    pvVar1 = operator_new__(0x17a8);
    this->field_0x29c = pvVar1;
    pvVar1 = operator_new__(0x1854);
    this->field_0x2a0 = pvVar1;
    pvVar1 = operator_new__(0x18b0);
    this->field_0x2a4 = pvVar1;
    pvVar1 = operator_new__(0x1944);
    this->field_0x2a8 = pvVar1;
    pvVar1 = operator_new__(0x19a0);
    this->field_0x2ac = pvVar1;
    pvVar1 = operator_new__(0x8b0);
    this->field_0x2b0 = pvVar1;
    pvVar1 = operator_new__(0x90c);
    this->field_0x2b4 = pvVar1;
    pvVar1 = operator_new__(0x6e4);
    this->field_0x2b8 = pvVar1;
    pvVar1 = operator_new__(0x740);
    this->field_0x2bc = pvVar1;
    pvVar1 = operator_new__(0x554);
    this->field_0x2c0 = pvVar1;
    pvVar1 = operator_new__(0x5b0);
    this->field_0x2c4 = pvVar1;
    pvVar1 = operator_new__(900);
    this->field_0x2c8 = pvVar1;
    pvVar1 = operator_new__(0x3e0);
    this->field_0x2cc = pvVar1;
    if (((((((int *)this->field_0x270 != nullptr) && (this->field_0x274 != nullptr)) &&
           (this->field_0x278 != nullptr)) &&
          (((this->field_0x27c != nullptr && (this->field_0x280 != nullptr)) &&
            ((this->field_0x284 != nullptr && ((this->field_0x288 != nullptr && (this->field_0x28c != nullptr))))
            )))) && (((this->field_0x290 != nullptr &&
                       ((((((this->field_0x294 != nullptr && (this->field_0x298 != nullptr)) &&
                            (this->field_0x29c != nullptr)) &&
                           ((this->field_0x2a0 != nullptr && (this->field_0x2a4 != nullptr)))) &&
                          ((this->field_0x2a8 != nullptr &&
                            ((this->field_0x2ac != nullptr && (this->field_0x2b0 != nullptr)))))) &&
                         (this->field_0x2b4 != nullptr)))) &&
                      (((this->field_0x2b8 != nullptr && (this->field_0x2bc != nullptr)) &&
                        (this->field_0x2c0 != nullptr)))))) &&
        (((this->field_0x2c4 != nullptr && (this->field_0x2c8 != nullptr)) && (pvVar1 != nullptr)))) {
        this->field_0x0 = 1;
        CCombFilter::SetBuffer(this->field_0x30,(int *)this->field_0x270,0x45c);
        CCombFilter::SetBuffer(this_00,(int *)this->field_0x274,0x473);
        CCombFilter::SetBuffer(this->field_0x30 + 1,(int *)this->field_0x278,0x4a4);
        CCombFilter::SetBuffer(this->field_0x110 + 1,(int *)this->field_0x27c,0x4bb);
        CCombFilter::SetBuffer(this->field_0x30 + 2,(int *)this->field_0x280,0x4fd);
        CCombFilter::SetBuffer(this->field_0x110 + 2,(int *)this->field_0x284,0x514);
        CCombFilter::SetBuffer(this->field_0x30 + 3,(int *)this->field_0x288,0x54c);
        CCombFilter::SetBuffer(this->field_0x110 + 3,(int *)this->field_0x28c,0x563);
        CCombFilter::SetBuffer(this->field_0x30 + 4,(int *)this->field_0x290,0x58e);
        CCombFilter::SetBuffer(this->field_0x110 + 4,(int *)this->field_0x294,0x5a5);
        CCombFilter::SetBuffer(this->field_0x30 + 5,(int *)this->field_0x298,0x5d3);
        CCombFilter::SetBuffer(this->field_0x110 + 5,(int *)this->field_0x29c,0x5ea);
        CCombFilter::SetBuffer(this->field_0x30 + 6,(int *)this->field_0x2a0,0x615);
        CCombFilter::SetBuffer(this->field_0x110 + 6,(int *)this->field_0x2a4,0x62c);
        CCombFilter::SetBuffer(this->field_0x30 + 7,(int *)this->field_0x2a8,0x651);
        CCombFilter::SetBuffer(this->field_0x110 + 7,(int *)this->field_0x2ac,0x668);
        CAllpassFilter::SetBuffer(pCVar6,(int *)this->field_0x2b0,0x22c);
        CAllpassFilter::SetBuffer(this_01,(int *)this->field_0x2b4,0x243);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 1,(int *)this->field_0x2b8,0x1b9);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 5,(int *)this->field_0x2bc,0x1d0);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 2,(int *)this->field_0x2c0,0x155);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 6,(int *)this->field_0x2c4,0x16c);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 3,(int *)this->field_0x2c8,0xe1);
        CAllpassFilter::SetBuffer(this->field_0x1f0 + 7,(int *)this->field_0x2cc,0xf8);
        CAllpassFilter::SetFeedback(pCVar6,0x1000000);
        CAllpassFilter::SetFeedback(this_01,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 1,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 5,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 2,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 6,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 3,0x1000000);
        CAllpassFilter::SetFeedback(this->field_0x1f0 + 7,0x1000000);
        SetWet(this,0x558106);
        SetRoomSize(this,0x1000000);
        SetDry(this,0x800000);
        SetDamp(this,0x1000000);
        SetWidth(this,0x2000000);
        SetMode(this,0);
        _ZN9CRevModel5ResetEv(this);
    }
    return this;
}
