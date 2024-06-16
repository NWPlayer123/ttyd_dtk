#pragma once

#include "manager/evtmgr.h"
#include "manager/evtmgr_cmd.h"

#include <dolphin/types.h>

//TODO: move?
enum EventOpcode {
    OPCODE_NOT_EQUALXT,          //0x00
    OPCODE_END_SCRIPT,           //0x01
    OPCODE_END_EVENT,            //0x02
    OPCODE_LABEL,                //0x03
    OPCODE_GOTO,                 //0x04
    OPCODE_DO,                   //0x05
    OPCODE_WHILE,                //0x06
    OPCODE_DO_BREAK,             //0x07
    OPCODE_DO_CONTINUE,          //0x08
    OPCODE_WAIT_FRAME,           //0x09
    OPCODE_WAIT_MSEC,            //0x0A
    OPCODE_HALT,                 //0x0B
    OPCODE_IF_STR_EQUAL,         //0x0C
    OPCODE_IF_STR_NOT_EQUAL,     //0x0D
    OPCODE_IF_STR_LESS,          //0x0E
    OPCODE_IF_STR_GREATER,       //0x0F
    OPCODE_IF_STR_LESS_EQUAL,    //0x10
    OPCODE_IF_STR_GREATER_EQUAL, //0x11
    OPCODE_IFF_EQUAL,            //0x12
    OPCODE_IFF_NOT_EQUAL,        //0x13
    OPCODE_IFF_LESS,             //0x14
    OPCODE_IFF_GREATER,          //0x15
    OPCODE_IFF_LESS_EQUAL,       //0x16
    OPCODE_IFF_GREATER_EQUAL,    //0x17
    OPCODE_IF_EQUAL,             //0x18
    OPCODE_IF_NOT_EQUAL,         //0x19
    OPCODE_IF_LESS,              //0x1A
    OPCODE_IF_GREATER,           //0x1B
    OPCODE_IF_LESS_EQUAL,        //0x1C
    OPCODE_IF_GREATER_EQUAL,     //0x1D
    OPCODE_IF_FLAG,              //0x1E
    OPCODE_IF_NOT_FLAG,          //0x1F
    OPCODE_ELSE,                 //0x20
    OPCODE_END_IF,               //0x21
    OPCODE_SWITCH,               //0x22
    OPCODE_SWITCHI,              //0x23
    OPCODE_CASE_EQUAL,           //0x24
    OPCODE_CASE_NOT_EQUAL,       //0x25
    OPCODE_CASE_LESS,            //0x26
    OPCODE_CASE_GREATER,         //0x27
    OPCODE_CASE_LESS_EQUAL,      //0x28
    OPCODE_CASE_GREATER_EQUAL,   //0x29
    OPCODE_CASE_ETC,             //0x2A
    OPCODE_CASE_OR,              //0x2B
    OPCODE_CASE_AND,             //0x2C
    OPCODE_CASE_FLAG,            //0x2D
    OPCODE_CASE_END,             //0x2E
    OPCODE_CASE_BETWEEN,         //0x2F
    OPCODE_SWITCH_BREAK,         //0x30
    OPCODE_END_SWITCH,           //0x31
    OPCODE_SET,                  //0x32
    OPCODE_SETI,                 //0x33
    OPCODE_SETF,                 //0x34
    OPCODE_ADD,                  //0x35
    OPCODE_SUB,                  //0x36
    OPCODE_MUL,                  //0x37
    OPCODE_DIV,                  //0x38
    OPCODE_MOD,                  //0x39
    OPCODE_ADDF,                 //0x3A
    OPCODE_SUBF,                 //0x3B
    OPCODE_MULF,                 //0x3C
    OPCODE_DIVF,                 //0x3D
    OPCODE_SET_READ,             //0x3E
    OPCODE_READ,                 //0x3F
    OPCODE_READ2,                //0x40
    OPCODE_READ3,                //0x41
    OPCODE_READ4,                //0x42
    OPCODE_READ_N,               //0x43
    OPCODE_SET_READF,            //0x44
    OPCODE_READF,                //0x45
    OPCODE_READF2,               //0x46
    OPCODE_READF3,               //0x47
    OPCODE_READF4,               //0x48
    OPCODE_READF_N,              //0x49
    OPCODE_CLAMP_INT,            //0x4A
    OPCODE_SET_USER_WORK,        //0x4B
    OPCODE_SET_USER_FLAG,        //0x4C
    OPCODE_ALLOC_USER_WORK,      //0x4D
    OPCODE_AND,                  //0x4E
    OPCODE_ANDI,                 //0x4F
    OPCODE_OR,                   //0x50
    OPCODE_ORI,                  //0x51
    OPCODE_SET_FRAME_FROM_MSEC,  //0x52
    OPCODE_SET_MSEC_FROM_FRAME,  //0x53
    OPCODE_SET_RAM,              //0x54
    OPCODE_SET_RAMF,             //0x55
    OPCODE_GET_RAM,              //0x56
    OPCODE_GET_RAMF,             //0x57
    OPCODE_SETR,                 //0x58
    OPCODE_SETRF,                //0x59
    OPCODE_GETR,                 //0x5A
    OPCODE_GETRF,                //0x5B
    OPCODE_USER_FUNC,            //0x5C
    OPCODE_RUN_EVENT,            //0x5D
    OPCODE_RUN_EVENT_ID,         //0x5E
    OPCODE_RUN_CHILD_EVENT,      //0x5F
    OPCODE_DELETE_EVENT,         //0x60
    OPCODE_RESTART_EVENT,        //0x61
    OPCODE_SET_PRI,              //0x62
    OPCODE_SET_SPD,              //0x63
    OPCODE_SET_TYPE,             //0x64
    OPCODE_STOP_ALL,             //0x65
    OPCODE_START_ALL,            //0x66
    OPCODE_STOP_OTHER,           //0x67
    OPCODE_START_OTHER,          //0x68
    OPCODE_STOP_ID,              //0x69
    OPCODE_START_ID,             //0x6A
    OPCODE_CHECK_EVENT,          //0x6B
    OPCODE_INLINE_EVENT,         //0x6C
    OPCODE_INLINE_EVENT_ID,      //0x6D
    OPCODE_END_INLINE,           //0x6E
    OPCODE_BROTHER_EVENT,        //0x6F
    OPCODE_BROTHER_EVENT_ID,     //0x70
    OPCODE_END_BROTHER,          //0x71
    OPCODE_DEBUG_PUT_MSG,        //0x72
    OPCODE_DEBUG_MSG_CLEAR,      //0x73
    OPCODE_DEBUG_PUT_REG,        //0x74
    OPCODE_DEBUG_NAME,           //0x75
    OPCODE_DEBUG_REM,            //0x76
    OPCODE_DEBUG_BP              //0x77
};

//Used to define native C functions that scripts can call
#define USER_FUNC(function) s32(function)(EventEntry* event, BOOL isFirstCall)

#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))

#define EVT_CMD(opcode, argv...) (((sizeof((s32[]) {argv}) / sizeof(s32)) << 16) | opcode)##argv

#define END    EVT_CMD(OPCODE_END_SCRIPT)
#define RETURN EVT_CMD(OPCODE_END_EVENT)

#define LABEL(LABEL_ID)  EVT_CMD(OPCODE_LABEL, LABEL_ID)
#define GOTO(LABEL_ID)   EVT_CMD(OPCODE_GOTO, LABEL_ID)
#define JUMP(EVT_SOURCE) EVT_CMD(OPCODE_GOTO, EVT_SOURCE)

#define LOOP(LOOP_COUNT) EVT_CMD(OPCODE_DO, LOOP_COUNT)
#define END_LOOP         EVT_CMD(OPCODE_WHILE)
#define BREAK_LOOP       EVT_CMD(OPCODE_DO_BREAK)
#define CONTINUE_LOOP    EVT_CMD(OPCODE_DO_CONTINUE)

#define WAIT_FRAMES(FRAMES)   EVT_CMD(OPCODE_WAIT_FRAME, FRAMES)
#define WAIT_MS(MILLISECONDS) EVT_CMD(OPCODE_WAIT_MSEC, MILLISECONDS)

// stall thread until expression is false
#define WAIT_UNTIL(expr) EVT_CMD(OPCODE_HALT, expr)

#define IF_STR_EQUAL(var1, var2)            EVT_CMD(OPCODE_IF_STR_EQUAL, var1, var2, )
#define IF_STR_NOT_EQUAL(var1, var2)        EVT_CMD(OPCODE_IF_STR_NOT_EQUAL, var1, var2)
#define IF_STR_LESS(var1, var2)             EVT_CMD(OPCODE_IF_STR_LESS, var1, var2)
#define IF_STR_GREATER(var1, var2)          EVT_CMD(OPCODE_IF_STR_GREATER, var1, var2)
#define IF_STR_LESS_OR_EQUAL(var1, var2)    EVT_CMD(OPCODE_IF_STR_LESS_EQUAL, var1, var2)
#define IF_STR_GREATER_OR_EQUAL(var1, var2) EVT_CMD(OPCODE_IF_STR_GREATER_EQUAL, var1, var2)

#define IF_FLOAT_EQUAL(var1, var2)            EVT_CMD(OPCODE_IFF_EQUAL, var1, var2)
#define IF_FLOAT_NOT_EQUAL(var1, var2)        EVT_CMD(OPCODE_IFF_NOT_EQUAL, var1, var2)
#define IF_FLOAT_LESS(var1, var2)             EVT_CMD(OPCODE_IFF_LESS, var1, var2)
#define IF_FLOAT_GREATER(var1, var2)          EVT_CMD(OPCODE_IFF_GREATER, var1, var2)
#define IF_FLOAT_LESS_OR_EQUAL(var1, var2)    EVT_CMD(OPCODE_IFF_LESS_EQUAL, var1, var2)
#define IF_FLOAT_GREATER_OR_EQUAL(var1, var2) EVT_CMD(OPCODE_IFF_GREATER_EQUAL, var1, var2)

#define IF_INT_EQUAL(var1, var2)            EVT_CMD(OPCODE_IF_EQUAL, var1, var2)
#define IF_INT_NOT_EQUAL(var1, var2)        EVT_CMD(OPCODE_IF_NOT_EQUAL, var1, var2)
#define IF_INT_LESS(var1, var2)             EVT_CMD(OPCODE_IF_LESS, var1, var2)
#define IF_INT_GREATER(var1, var2)          EVT_CMD(OPCODE_IF_GREATER, var1, var2)
#define IF_INT_LESS_OR_EQUAL(var1, var2)    EVT_CMD(OPCODE_IF_LESS_EQUAL, var1, var2)
#define IF_INT_GREATER_OR_EQUAL(var1, var2) EVT_CMD(OPCODE_IF_GREATER_EQUAL, var1, var2)

#define IF_BITS_SET(var1, var2)   EVT_CMD(OPCODE_IF_FLAG, var1, var2)
#define IF_BITS_CLEAR(var1, var2) EVT_CMD(OPCODE_IF_NOT_FLAG, var1, var2)

#define ELSE                        EVT_CMD(OPCODE_ELSE)
#define END_IF                      EVT_CMD(OPCODE_END_IF)
#define SWITCH(expr)                EVT_CMD(OPCODE_SWITCH, expr)
#define SWITCH_RAW(expr)            EVT_CMD(OPCODE_SWITCHI, expr)
#define CASE_EQUAL(expr)            EVT_CMD(OPCODE_CASE_EQUAL, expr)
#define CASE_NOT_EQUAL(expr)        EVT_CMD(OPCODE_CASE_NOT_EQUAL, expr)
#define CASE_LESS(expr)             EVT_CMD(OPCODE_CASE_LESS, expr)
#define CASE_GREATER(expr)          EVT_CMD(OPCODE_CASE_GREATER, expr)
#define CASE_LESS_OR_EQUAL(expr)    EVT_CMD(OPCODE_CASE_LESS_EQUAL, expr)
#define CASE_GREATER_OR_EQUAL(expr) EVT_CMD(OPCODE_CASE_GREATER_EQUAL, expr)
#define CASE_DEFAULT                EVT_CMD(OPCODE_CASE_ETC)
#define CASE_OR_EQUAL(val)          EVT_CMD(OPCODE_CASE_OR, val)
#define CASE_AND_EQUAL(val)         EVT_CMD(OPCODE_CASE_AND, val)
#define CASE_FLAG(val)              EVT_CMD(OPCODE_CASE_FLAG, val)
#define CASE_END                    EVT_CMD(OPCODE_CASE_END)
#define CASE_BETWEEN(LOWER, UPPER)  EVT_CMD(OPCODE_CASE_BETWEEN, LOWER, UPPER)
#define BREAK_SWITCH                EVT_CMD(OPCODE_SWITCH_BREAK)
#define END_SWITCH                  EVT_CMD(OPCODE_END_SWITCH)

#define SET_VALUE(expr1, expr2)       EVT_CMD(OPCODE_SET, expr1, expr2)
#define SET_RAW_VALUE(expr1, expr2)   EVT_CMD(OPCODE_SETI, expr1, expr2)
#define SET_FLOAT_VALUE(expr1, expr2) EVT_CMD(OPCODE_SETF, expr1, expr2)

// int expressions
#define ADD(expr1, expr2)      EVT_CMD(OPCODE_ADD, expr1, expr2)
#define SUBTRACT(expr1, expr2) EVT_CMD(OPCODE_SUB, expr1, expr2)
#define MULTIPLY(expr1, expr2) EVT_CMD(OPCODE_MUL, expr1, expr2)
#define DIVIDE(expr1, expr2)   EVT_CMD(OPCODE_DIV, expr1, expr2)
#define MODULO(expr1, expr2)   EVT_CMD(OPCODE_MOD, expr1, expr2)

// float expressions
#define ADD_FLOAT(expr1, expr2)      EVT_CMD(OPCODE_ADDF, expr1, expr2)
#define SUBTRACT_FLOAT(expr1, expr2) EVT_CMD(OPCODE_SUBF, expr1, expr2)
#define MULTIPLY_FLOAT(expr1, expr2) EVT_CMD(OPCODE_MULF, expr1, expr2)
#define DIVIDE_FLOAT(expr1, expr2)   EVT_CMD(OPCODE_DIVF, expr1, expr2)

#define SET_INT_READ_ADDR(ptr)         EVT_CMD(OPCODE_SET_READ, ptr)
#define READ_INT(expr)                 EVT_CMD(OPCODE_READ, expr)
#define READ_INT2(expr)                EVT_CMD(OPCODE_READ2, expr)
#define READ_INT3(expr)                EVT_CMD(OPCODE_READ3, expr)
#define READ_INT4(expr)                EVT_CMD(OPCODE_READ4, expr)
#define READ_INT_INDEXED(expr1, expr2) EVT_CMD(OPCODE_READ_N, expr, expr2)

#define SET_FLOAT_READ_ADDR(ptr)         EVT_CMD(OPCODE_SET_READF, ptr)
#define READ_FLOAT(expr)                 EVT_CMD(OPCODE_READF, expr)
#define READ_FLOAT2(expr)                EVT_CMD(OPCODE_READF2, expr)
#define READ_FLOAT3(expr)                EVT_CMD(OPCODE_READF3, expr)
#define READ_FLOAT4(expr)                EVT_CMD(OPCODE_READF4, expr)
#define READ_FLOAT_INDEXED(expr1, expr2) EVT_CMD(OPCODE_READF_N, expr, expr2)

// User Work and User Flag base
#define SET_UW_BASE(expr) EVT_CMD(OPCODE_SET_USER_WORK, expr)
#define SET_UF_BASE(expr) EVT_CMD(OPCODE_SET_USER_FLAG, expr)

#define ALLOCATE_UW(val, expr) EVT_CMD(OPCODE_ALLOC_USER_WORK, expr)

// bitwise operations
#define AND(expr, val)        EVT_CMD(OPCODE_AND, expr, val)
#define AND_RAW(expr, rawVal) EVT_CMD(OPCODE_ANDI, expr, rawVal)
#define OR(expr, val)         EVT_CMD(OPCODE_OR, expr, val)
#define OR_RAW(expr, rawVal)  EVT_CMD(OPCODE_ORI, expr, rawVal)

//time conversion opcodes
//(ms to frame count)
#define CONVERT_MS_TO_FRAME(expr, ms)         EVT_CMD(OPCODE_SET_FRAME_FROM_MSEC, expr, ms)
//(frame count to ms)
#define CONVERT_FRAME_TO_MS(expr, frameCount) EVT_CMD(OPCODE_SET_MSEC_FROM_FRAME, expr, frameCount)

// ptr stuff
#define SET_INT(val, expr)   EVT_CMD(OPCODE_SET_RAM, val, expr)
#define SET_FLOAT(val, expr) EVT_CMD(OPCODE_SET_RAMF, val, expr)
#define GET_INT(val, expr)   EVT_CMD(OPCODE_GET_RAM, val, expr)
#define GET_FLOAT(val, expr) EVT_CMD(OPCODE_GET_RAMF, val, expr)

#define SET_INT_INDEXED(expr1, expr2)   EVT_CMD(OPCODE_SETR, expr1, expr2)
#define SET_FLOAT_INDEXED(expr1, expr2) EVT_CMD(OPCODE_SETRF, expr1, expr2)

#define GET_INT_INDEXED(expr1, expr2)   EVT_CMD(OPCODE_GETR, expr1, expr2)
#define GET_FLOAT_INDEXED(expr1, expr2) EVT_CMD(OPCODE_GETRF, expr1, expr2)

#define CALL(FUNC, ARGS...)            EVT_CMD(OPCODE_USER_FUNC, (s32)FUNC, ##ARGS)
#define SCRIPT_ASYNC(script)           EVT_CMD(OPCODE_RUN_EVENT, script)
#define SCRIPT_ASYNC_TID(script, expr) EVT_CMD(OPCODE_RUN_EVENT_ID, script, expr)
#define SCRIPT_SYNC(script)            EVT_CMD(OPCODE_RUN_CHILD_EVENT, script)
#define STOP_TID(script)               EVT_CMD(OPCODE_DELETE_EVENT, script)
#define RESTART_SCRIPT(script)         EVT_CMD(OPCODE_RESTART_EVENT, script)
#define SET_THREAD_PRIORITY(priority)  EVT_CMD(OPCODE_SET_PRI, priority)
#define SET_EVENT_SPEED(timeScale)     EVT_CMD(OPCODE_SET_SPD, timeScale)
#define SET_TYPE(type)                 EVT_CMD(OPCODE_SET_TYPE, type)

#define SUSPEND_TYPES(types)            EVT_CMD(OPCODE_STOP_ALL, types)
#define RESUME_TYPES(types)             EVT_CMD(OPCODE_START_ALL, types)
#define SUSPEND_TYPES_OTHER(types)      EVT_CMD(OPCODE_STOP_OTHER, types)
#define RESUME_TYPES_OTHER(types)       EVT_CMD(OPCODE_START_OTHER, types)
#define SUSPEND_TID(expr)               EVT_CMD(OPCODE_STOP_ID, expr)
#define RESUME_TID(expr)                EVT_CMD(OPCODE_START_ID, expr)
#define CHECK_THREAD_RUNNING(expr, ret) EVT_CMD(OPCODE_CHECK_EVENT, expr, ret, )

#define BEGIN_THREAD                 EVT_CMD(OPCODE_INLINE_EVENT)
#define BEGIN_THREAD_TID(expr)       EVT_CMD(OPCODE_INLINE_EVENT_ID, expr)
#define END_THREAD                   EVT_CMD(OPCODE_END_INLINE)
#define BEGIN_CHILD_THREAD           EVT_CMD(OPCODE_BROTHER_EVENT)
#define BEGIN_CHILD_THREAD_TID(expr) EVT_CMD(OPCODE_BROTHER_EVENT_ID, expr)
#define END_CHILD_THREAD             EVT_CMD(OPCODE_END_BROTHER)

// Data types
#define EVTDAT_LW_MAX      -20 * 1000000
#define EVTDAT_GW_MAX      -40 * 1000000
#define EVTDAT_LF_MAX      -60 * 1000000
#define EVTDAT_GF_MAX      -80 * 1000000
#define EVTDAT_LSWF_MAX    -100 * 1000000
#define EVTDAT_GSWF_MAX    -120 * 1000000
#define EVTDAT_LSW_MAX     -140 * 1000000
#define EVTDAT_GSW_MAX     -160 * 1000000
#define EVTDAT_UW_MAX      -180 * 1000000
#define EVTDAT_UF_MAX      -200 * 1000000
#define EVTDAT_FLOAT_MAX   -220 * 1000000
#define EVTDAT_POINTER_MAX -250 * 1000000
#define EVTDAT_ADDR_MAX    -270 * 1000000

#define EVTDAT_LW_BASE    30 * 1000000
#define EVTDAT_GW_BASE    50 * 1000000
#define EVTDAT_LF_BASE    70 * 1000000
#define EVTDAT_GF_BASE    90 * 1000000
#define EVTDAT_LSWF_BASE  110 * 1000000
#define EVTDAT_GSWF_BASE  130 * 1000000
#define EVTDAT_LSW_BASE   150 * 1000000
#define EVTDAT_GSW_BASE   170 * 1000000
#define EVTDAT_UW_BASE    190 * 1000000
#define EVTDAT_UF_BASE    210 * 1000000
#define EVTDAT_FLOAT_BASE 230 * 1000000

#define LW(id)   ((id) - EVTDAT_LW_BASE)
#define GW(id)   ((id) - EVTDAT_GW_BASE)
#define LF(id)   ((id) - EVTDAT_LF_BASE)
#define GF(id)   ((id) - EVTDAT_GF_BASE)
#define LSWF(id) ((id) - EVTDAT_LSWF_BASE)
#define GSWF(id) ((id) - EVTDAT_GSWF_BASE)
#define LSW(id)  ((id) - EVTDAT_LSW_BASE)
#define GSW(id)  ((id) - EVTDAT_GSW_BASE)
#define UW(id)   ((id) - EVTDAT_UW_BASE)
#define UF(id)   ((id) - EVTDAT_UF_BASE)

#define EVT_RETURN_BLOCK  0
#define EVT_RETURN_YIELD  1
#define EVT_RETURN_DONE   2
#define EVT_RETURN_REPEAT 3
#define EVT_RETURN_FINISH 255
