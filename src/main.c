#include "main.h"

#include "mario/mariost.h"
#include "sdk/DEMOInit.h"

#include <dolphin/os.h>


void main(void) {
    OSTick tick;

    marioStInit();
    marioStMain();
    while (1) {
        tick = OSGetTick();
        DEMOBeforeRender();
        marioStDisp();
        marioStMain();
        gp->deltaGame = OSGetTick() - tick;
        DEMODoneRender();
        gp->deltaRender = OSGetTick() - tick;
    }
}
