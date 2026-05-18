#include "system.h"
extern s32 rand(void);
extern s32 gp;

u16 sysGetToken(void) {
    static u16 token;

    return token++;
}
s32 irand(s32 range) {
    s32 value;

    if (range == 0) {
        return 0;
    }

    value = rand();
    return value % range;
}
u8 padGetRumbleStatus(s32 controller) {
    controller = gp + controller;

    return *(u8*)(controller + 0x13D0);
}
u8 keyGetSubStickY(s32 controller) {
    controller = gp + controller;

    return *(u8*)(controller + 0x13C4);
}
u8 keyGetStickY(s32 controller) {
    controller = gp + controller;

    return *(u8*)(controller + 0x13BC);
}
u8 keyGetStickX(s32 controller) {
    controller = gp + controller;

    return *(u8*)(controller + 0x13B8);
}
u32 keyGetButtonTrg(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1338);
}
u32 keyGetDirTrg(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1388);
}
u32 keyGetButtonRep(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1348);
}
u32 keyGetDirRep(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1398);
}
u32 keyGetButton(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1328);
}
u32 keyGetDir(s32 controller) {
    controller = gp + controller * 4;

    return *(u32*)(controller + 0x1378);
}