

void effStarStoneDisp_1(enum CameraId cameraId, void* param) {
    GXTexObj sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;                                       /* compiler-managed */
    s32 spC;
    s32 sp8;                                        /* compiler-managed */
    CameraEntry* camera;
    StarStoneData* data;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 starType;
    u32 var_r27;
    u32 var_r27_2;
    u32 var_r27_3;
    u32 var_r27_4;
    u32 var_r27_5;
    u32 var_r27_6;
    u32 var_r27_7;
    u32 var_r27_8;
    u8* var_r25_2;
    u8* var_r25_3;
    u8* var_r25_4;
    u8* var_r25_5;
    u8* var_r25_6;
    u8* var_r25_7;
    u8* var_r25_8;
    u8* var_r26;
    void** var_r25;
    void** var_r26_2;
    void** var_r26_3;
    void** var_r26_4;
    void** var_r26_5;
    void** var_r26_6;
    void** var_r26_7;
    void** var_r26_8;

    Mtx sp9C;
    Mtx sp6C;
    Mtx sp3C;

    u32 i;

    data = ((EffectEntry*)param)->userdata;
    starType = data->starType;
    camera = camGetPtr(cameraId);
    mapSetMaterialFog();
    GXSetArray(GX_VA_CLR0, color_tbl[data->starType], 4);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
    GXSetChanMatColor(GX_COLOR0A0, data->edgeColor);
    GXSetNumTexGens(0);
    GXSetNumTevStages(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C0, GX_CC_CPREV, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
    GXSetTevColor(GX_TEVREG0, (GXColor){data->field_5C.r, data->field_5C.g, data->field_5C.b, data->field_5C.a});
    PSMTXTrans(sp9C, data->position.x, data->position.y, data->position.z);
    temp_f1 = 1.1f * data->scale;
    PSMTXScale(sp6C, temp_f1, temp_f1, temp_f1);
    PSMTXConcat(sp9C, sp6C, sp9C);
    PSMTXRotRad(sp3C, 'y', MTXDegToRad(data->rotation.y));
    PSMTXConcat(sp9C, sp3C, sp9C);
    PSMTXConcat(camera->view, sp9C, sp9C);
    GXLoadPosMtxImm(sp9C, 0);
    GXSetCurrentMtx(0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZCompLoc(TRUE);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetZMode(TRUE, GX_LEQUAL, FALSE);
    GXSetCullMode(GX_CULL_BACK);
    if (starType == 0) {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 11);
        GXSetArray(GX_VA_POS, &diamond_1_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_S8, 6);
        GXSetArray(GX_VA_NRM, &diamond_1_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_1_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 13);
        GXSetArray(GX_VA_TEX0, &diamond_1_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_1_dl_0_tbl[i], diamond_1_dl_0_size_tbl[i] << 5);
        }
        
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_RGBA4, 11);
        GXSetArray(GX_VA_POS, &diamond_1_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_RGB8, 6);
        GXSetArray(GX_VA_NRM, &diamond_1_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA4, 13);
        GXSetArray(GX_VA_TEX0, &diamond_1_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_1_dl_1_tbl[i], diamond_1_dl_1_size_tbl[i] << 5);
        }
    } else {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 11);
        GXSetArray(GX_VA_POS, &diamond_7_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_S8, 6);
        GXSetArray(GX_VA_NRM, &diamond_7_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_7_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 13);
        GXSetArray(GX_VA_TEX0, &diamond_7_texcoord0_tbl, 4);

        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_7_dl_0_tbl[i], diamond_7_dl_0_size_tbl[i] << 5);
        }
        
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 11);
        GXSetArray(GX_VA_POS, &diamond_7_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_S8, 6);
        GXSetArray(GX_VA_NRM, &diamond_7_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_7_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 13);
        GXSetArray(GX_VA_TEX0, &diamond_7_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_7_dl_1_tbl[i], diamond_7_dl_1_size_tbl[i] << 5);
        }
    }
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, FALSE, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_NONE, GX_AF_NONE);
    GXSetNumTexGens(1);
    GXSetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 30);
    PSMTXTrans(sp9C, data->unk24.x, data->unk24.y, 0.0f);
    GXLoadTexMtxImm(sp9C, 0x1EU, GX_MTX2x4);
    GXSetNumTevStages(2U);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C0, GX_CC_CPREV, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
    GXSetTevColor(GX_TEVREG0, (GXColor){data->field_5C.r, data->field_5C.g, data->field_5C.b, data->field_5C.a});
    PSMTXTrans(sp9C, data->position.x, data->position.y, data->position.z);
    temp_f1_2 = data->scale;
    PSMTXScale(sp6C, temp_f1_2, temp_f1_2, temp_f1_2);
    PSMTXConcat(sp9C, sp6C, sp9C);
    PSMTXRotRad(sp3C, 'y', MTXDegToRad(data->rotation.y));
    PSMTXConcat(sp9C, sp3C, sp9C);
    PSMTXConcat(camera->view, sp9C, sp9C);
    GXLoadPosMtxImm(sp9C, 0U);
    GXSetCurrentMtx(0U);
    if (starType == 0) {
        effGetTexObj(0x2E, &sp1C);
        GXLoadTexObj(&sp1C, GX_TEXMAP0);
    } else {
        effGetTexObj(0x2F, &sp1C);
        GXLoadTexObj(&sp1C, GX_TEXMAP0);
    }
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZCompLoc(TRUE);
    GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_AND, GX_ALWAYS, 0U);
    GXSetZMode(TRUE, GX_LEQUAL, FALSE);
    if (starType == 0) {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_RGBA4, 11);
        GXSetArray(GX_VA_POS, &diamond_1_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_RGB8, 6);
        GXSetArray(GX_VA_NRM, &diamond_1_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_1_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA4, 13);
        GXSetArray(GX_VA_TEX0, &diamond_1_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_1_dl_0_tbl[i], diamond_1_dl_0_size_tbl[i] << 5);
        }
    } else {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 11);
        GXSetArray(GX_VA_POS, &diamond_7_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_S8, 6);
        GXSetArray(GX_VA_NRM, &diamond_7_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_7_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 13);
        GXSetArray(GX_VA_TEX0, &diamond_7_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_7_dl_0_tbl[i], diamond_7_dl_0_size_tbl[i] << 5);
        }
    }
    effGetTexObj(0x2D, &sp1C);
    GXLoadTexObj(&sp1C, GX_TEXMAP0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZCompLoc(TRUE);
    GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_AND, GX_ALWAYS, 0U);
    GXSetZMode(TRUE, GX_LEQUAL, FALSE);
    if (starType == 0) {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_RGBA4, 11);
        GXSetArray(GX_VA_POS, &diamond_1_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_RGB8, 6);
        GXSetArray(GX_VA_NRM, &diamond_1_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA4, 13);
        GXSetArray(GX_VA_TEX0, &diamond_1_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_1_dl_1_tbl[i], diamond_1_dl_1_size_tbl[i] << 5);
        }
    }
    else {
        GXClearVtxDesc();
        
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 11);
        GXSetArray(GX_VA_POS, &diamond_7_vertex_tbl, 6);
        
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_S8, 6);
        GXSetArray(GX_VA_NRM, &diamond_7_normal_tbl, 3);
        
        GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetArray(GX_VA_CLR0, &diamond_7_color0_tbl, 4);
        
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_S16, 13);
        GXSetArray(GX_VA_TEX0, &diamond_7_texcoord0_tbl, 4);
        
        for (i = 0; i < 34; i++) {
            GXCallDisplayList(diamond_7_dl_1_tbl[i], diamond_7_dl_1_size_tbl[i] << 5);
        }
    }
}
