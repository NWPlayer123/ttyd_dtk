#pragma once

#include "dolphin/types.h"

#include "battle/battle_database_common.h"

typedef enum ItemUseLocations {
    ITEM_USE_NONE = 0,
    ITEM_USE_SHOP = 1 << 0,
    ITEM_USE_BATTLE = 1 << 1,
    ITEM_USE_FIELD = 1 << 2
} ItemUseLocations;

typedef struct ItemData {
    const char* id; //JP description of the item
    const char* name; // msgdata lookup for the name
    const char* description; //msgdata loopup for the description
    const char* menu_description; //msgdata lookup for the menu description
    s16 usable_locations; //0x10
    s16 type_sort_order; //0x12
    s16 buy_price; //0x14
    s16 discount_price; //0x16
    s16 star_piece_price; //0x18
    s16 sell_price; //0x1A
    s8 bp_cost; //0x1C
    s8 hp_restored; //0x1D
    s8 fp_restored; //0x1E
    s8 sp_restored; //0x1F
    s16 icon_id; //0x20
    s16 padding; //0x22, ???
    BattleWeapon* weapon_params; //0x24
} ItemData;
STATIC_ASSERT_SIZEOF(ItemData, 0x28);
