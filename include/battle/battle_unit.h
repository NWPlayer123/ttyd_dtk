#pragma once

#include <dolphin/mtx.h>

typedef enum BattleUnitType {
    UNIT_MARIO = 222,  //0xDE
    UNIT_SHELL_SHIELD, //0xDF
    UNIT_GOOMBELLA,    //0xE0
    UNIT_KOOPS,        //0xE1
    UNIT_YOSHI,        //0xE2
    UNIT_FLURRIE,      //0xE3
    UNIT_VIVIAN,       //0xE4
    UNIT_BOBBERY,      //0xE5
    UNIT_MS_MOWZ,      //0xE6
    UNIT_MAX,          //0xE7
} BattleUnitType;
#define UNIT_PARTNER_MIN UNIT_GOOMBELLA
#define UNIT_PARTNER_MAX UNIT_MS_MOWZ + 1

typedef enum BattleUnitAttribute {
    ATTRIBUTE_VEILED = (1 << 4)
} BattleUnitAttribute;

#pragma enumalwaysint off
typedef enum StatusEffectType {
    STATUS_ALLERGIC,     //0x0
    STATUS_SLEEP,        //0x1
    STATUS_STOPPED,      //0x2
    STATUS_DIZZY,        //0x3
    STATUS_POISON,       //0x4
    STATUS_CONFUSED,     //0x5
    STATUS_ELECTRIC,     //0x6
    STATUS_DODGY,        //0x7
    STATUS_BURN,         //0x8
    STATUS_FROZEN,       //0x9
    STATUS_HUGE,         //0xA
    STATUS_TINY,         //0xB
    STATUS_ATTACK_UP,    //0xC
    STATUS_ATTACK_DOWN,  //0xD
    STATUS_DEFENSE_UP,   //0xE
    STATUS_DEFENSE_DOWN, //0xF
    STATUS_CHARGED,      //0x10
    STATUS_FLIPPED,      //0x11, TODO: double check
    STATUS_INVISIBLE,    //0x12
    STATUS_FAST,         //0x13
    STATUS_SLOW,         //0x14
    STATUS_PAYBACK,      //0x15
    STATUS_HOLD_FAST,    //0x16
    STATUS_HP_REGEN,     //0x17
    STATUS_FP_REGEN,     //0x18
    STATUS_FRIGHT,       //0x19
    STATUS_GALE_FORCE,   //0x1A
    STATUS_INSTAKILL,    //0x1B
} StatusEffectType;
#pragma enumalwaysint on

typedef enum BattleDataType {
    DATA_MAKE_TECH_MENU = 1,
    DATA_APPEAL_EVENT = 5,
    DATA_AUDIENCE_EVENT = 6,
} BattleDataType;

typedef enum BattlePoseType {
    POSE_UNK1 = 1,
} BattlePoseType;

typedef struct BattleDataEntry {
    BattleDataType type; //0x0
    void* event;         //0x4
} BattleDataEntry;
STATIC_ASSERT_SIZEOF(BattleDataEntry, 0x8);

typedef struct BattlePoseEntry {
    BattlePoseType type; //0x0
    const char* name;    //0x4
} BattlePoseEntry;
STATIC_ASSERT_SIZEOF(BattlePoseEntry, 0x8);

typedef struct BattleUnitData {
    BattleUnitType type;        //0x0
    u8 unk4[0xE - 0x4];         //0x4
    s8 level;                   //0xE
    u8 unkF[0x30 - 0xF];        //0xF
    Vec togeBaseOffset;         //0x30
    u8 unk3C[0xC0 - 0x3C];      //0x3C
    BattleDataEntry* dataTable; //0xC0
} BattleUnitData;
STATIC_ASSERT_SIZEOF(BattleUnitData, 0xC4);

typedef struct BattleUnitPartData {
    s32 partId;           //0x0
    const char* partName; //0x4
    u8 unk8[0x4C - 0x8];  //0x8
} BattleUnitPartData;
STATIC_ASSERT_SIZEOF(BattleUnitPartData, 0x4C);

typedef struct BattleWorkUnitPart {
    struct BattleWorkUnitPart* nextPart; //0x0
    BattleUnitPartData* data;            //0x4
    const char* partName;                //0x8
    Vec homePosition;                    //0xC
    Vec position;                        //0x18
    Vec positionOffset;                  //0x24
    Vec displayOffset;                   //0x30
    Vec baseRotation;                    //0x3C
    Vec rotation;                        //0x48
    Vec rotationOffset;                  //0x54
    Vec scale;                           //0x60
    Vec baseScale;                       //0x6C
    u8 unk78[0x7C - 0x78];               //0x78
    Vec moveStartPosition;               //0x7C
    Vec moveCurrentPosition;             //0x88
    Vec moveTargetPosition;              //0x94
    u8 unkA0[0xA4 - 0xA0];               //0xA0
    f32 moveSpeedXZ;                     //0xA4
    f32 fallAcceleration;                //0xA8
    u8 unkAC[0x170 - 0xAC];              //0xAC
    Vec hitBaseOffset;                   //0x170
    Vec hitOffset;                       //0x17C
    Vec hitCursorBaseOffset;             //0x188
    Vec hitCursorOffset;                 //0x194
    u8 unk1A0[0x1AC - 0x1A0];            //0x1A0
    s32 attributes;                      //0x1AC, TODO: enum
    u8 unk1B0[0x1BC - 0x1B0];            //0x1B0
    BattlePoseEntry* poseTable;          //0x1BC
    u8 unk1C0[0x204 - 0x1C0];            //0x1C0
    s32 animFlags;                       //0x204
    u8 unk208[0x4EC - 0x208];            //0x208
    struct BattleWorkUnit* owner;        //0x4EC
    u8 unk4F0[0x500 - 0x4F0];            //0x4F0
} BattleWorkUnitPart;
STATIC_ASSERT_SIZEOF(BattleWorkUnitPart, 0x500);

typedef struct BattleWorkUnitHP {
    u16 unk0;  //0x0
    u16 unk2;  //0x2
    s16 unk4;  //0x4
    s16 unk6;  //0x6
    s16 unk8;  //0x8
    s16 unkA;  //0xA
    s32 unkC;  //0xC
    s32 unk10; //0x10
    f32 unk14; //0x14
    f32 unk18; //0x18
} BattleWorkUnitHP;
STATIC_ASSERT_SIZEOF(BattleWorkUnitHP, 0x1C);

typedef struct BattleWorkAlliance {
    s16 index;             //0x0
    s8 attackDirection;    //0x2
    s8 unk3;               //0x3
    s32 clearConditionMet; //0x4
} BattleWorkAlliance;

typedef struct BattleWorkStatus {
    s8 sleepTurns;            //0x0
    s8 sleepStrength;         //0x1
    s8 stoppedTurns;          //0x2
    s8 dizzyTurns;            //0x3
    s8 poisonTurns;           //0x4
    s8 poisonStrength;        //0x5
    s8 confusedTurns;         //0x6
    s8 electricTurns;         //0x7
    s8 dodgyTurns;            //0x8
    s8 burnTurns;             //0x9
    s8 frozenTurns;           //0xA
    s8 sizeChangeTurns;       //0xB
    s8 sizeChangeStrength;    //0xC
    s8 attackChangeTurns;     //0xD
    s8 attackChangeStrength;  //0xE
    s8 defenseChangeTurns;    //0xF
    s8 defenseChangeStrength; //0x10
    s8 chargedStrength;       //0x11
    s8 allergicTurns;         //0x12
    s8 flippedTurns;          //0x13
    s8 invisibleTurns;        //0x14
    s8 paybackTurns;          //0x15
    s8 holdFastTurns;         //0x16
    s8 fastTurns;             //0x17
    s8 slowTurns;             //0x18
    s8 hpRegenTurns;          //0x19
    s8 hpRegenStrength;       //0x1A
    s8 fpRegenTurns;          //0x1B
    s8 fpRegenStrength;       //0x1C
    s8 instakillStrength;     //0x1D
} BattleWorkStatus;

typedef struct BattleWorkBadges {
    u8 unk0[0x17 - 0x0];   //0x0
    u8 zapTap;             //0x17
    u8 unk18[0x28 - 0x18]; //0x18
} BattleWorkBadges;

typedef struct BattleWorkUnit {
    s32 unitId;                      //0x0
    BattleUnitType initialType;      //0x4
    BattleUnitType currentType;      //0x8
    s8 alliance;                     //0xC
    s8 level;                        //0xD
    s8 groupId;                      //0xE, used for Ms Mowz's Kiss Thief
    u8 alignF;                       //0xF
    BattleUnitData* data;            //0x10
    BattleWorkUnitPart* parts;       //0x14
    BattleDataEntry* dataTable;      //0x18
    s32 flags;                       //0x1C
    s8 moveState;                    //0x20
    s8 maxMoveCount;                 //0x21
    s8 movesRemaining;               //0x22
    s8 maxMovesThisTurn;             //0x23
    u8 unk24[0x2C - 0x24];           //0x24
    s32 attackPhase;                 //0x2C
    Vec homePosition;                //0x30
    Vec position;                    //0x3C
    Vec positionOffset;              //0x48
    Vec displayOffset;               //0x54
    Vec baseRotation;                //0x60
    Vec rotation;                    //0x6C
    Vec rotationOffset;              //0x78
    u8 unk84[0x90 - 0x84];           //0x84
    Vec scale;                       //0x90
    Vec baseScale;                   //0x9C
    Vec togeOffset;                  //0xA8
    u8 unkB4[0xCC - 0xB4];           //0xB4
    s16 width;                       //0xCC
    s16 height;                      //0xCE
    u8 unkD0[0x104 - 0xD0];          //0xD0
    BattleUnitAttribute attributes;  //0x104
    s16 currentMaxHP;                //0x108
    s16 baseMaxHP;                   //0x10A
    s16 currentHP;                   //0x10C
    s16 currentMaxFP;                //0x10E
    s16 baseMaxFP;                   //0x110
    s16 currentFP;                   //0x112
    f32 sizeMultiplier;              //0x114
    BattleWorkStatus statusEffects;  //0x118
    u8 unk136[0x138 - 0x136];        //0x136
    s32 statusFlags;                 //0x138
    s16 unk13C; //0x13C
    s16 unk13E; //0x13E
    u8 unk140[0x148 - 0x140];        //0x140
    Vec moveStartPosition;           //0x148
    Vec moveCurrentPosition;         //0x154
    Vec moveTargetPosition;          //0x160
    u8 unk16C[0x170 - 0x16C];        //0x16C
    f32 moveSpeedXZ;                 //0x170
    f32 fallAcceleration;            //0x174
    f32 moveSpeedY;                  //0x178
    u8 unk17C[0x189 - 0x17C];        //0x17C
    s8 faceDirection;                //0x189
    u8 unk18A[0x1FC - 0x18A];        //0x18A
    BattleWorkUnitHP healthGauge;    //0x1FC
    s32 work[16];                    //0x218
    u8 unk258[0x264 - 0x258];        //0x258
    s32 totalHpDamageTaken;          //0x264
    s32 totalFpDamageTaken;          //0x268
    s32 totalFpLost;                 //0x26C
    s8 hpDamageTaken;                //0x270
    s8 fpDamageTaken;                //0x271
    u8 unk272[0x27C - 0x272];        //0x272
    s32 tokenFlags;                  //0x27C
    u8 unk280[0x2B4 - 0x280];        //0x280
    s32 damageEventId;               //0x2B4
    u8 unk2B8[0x2D4 - 0x2B8];        //0x2B8
    s32 talkPartId;                  //0x2D4
    const char* talkPoseName;        //0x2D8
    const char* stayPoseName;        //0x2DC
    BattleWorkBadges badgesEquipped; //0x2E0
    u8 unk308[0xB34 - 0x308];        //0x308
} BattleWorkUnit;
STATIC_ASSERT_SIZEOF(BattleWorkUnit, 0xB34);

BOOL BtlUnit_Init(void);

BOOL BtlUnit_Delete(BattleWorkUnit* unit);

void BtlUnit_GetPos(BattleWorkUnit* unit, f32* x, f32* y, f32* z);
void BtlUnit_SetPos(BattleWorkUnit* unit, f32 x, f32 y, f32 z);

void BtlUnit_GetPartsOffsetPos(BattleWorkUnitPart* part, f32* x, f32* y, f32* z);

void BtlUnit_ResetMoveStatus(BattleWorkUnit* unit);

void BtlUnit_GetStatus(BattleWorkUnit* unit, StatusEffectType type, s8* turns, s8* strength);
void BtlUnit_ClearStatus(BattleWorkUnit* unit);
BOOL BtlUnit_CheckStatus(BattleWorkUnit* unit, StatusEffectType type);

BOOL BtlUnit_CanActStatus(BattleWorkUnit *unit);

void BtlUnit_ReviseHpFp(BattleWorkUnit *unit);
s32 BattleTransPartyId(BattleUnitType type);

u32 BtlUnit_snd_se(BattleWorkUnit* unit, s32 lookup, s32 volume, s16 add_pitch);
s32 BtlUnit_snd_se_pos(BattleWorkUnit* unit, s32 lookup, s32 volume, s16 add_pitch, Vec* position);
