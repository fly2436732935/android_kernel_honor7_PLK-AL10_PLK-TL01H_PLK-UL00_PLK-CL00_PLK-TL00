
#ifndef  VC_CALL_INTERFACE_H
#define  VC_CALL_INTERFACE_H

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  2 常量定义
*****************************************************************************/


/*****************************************************************************
  3类型定义
*****************************************************************************/
enum CALL_VC_MSG_ID_ENUM
{
    /*CALL->VC*/
    CALL_VC_CHANNEL_OPEN                = 0,
    CALL_VC_CHANNEL_CLOSE,
    CALL_VC_CHANNEL_PARA_CHANGE,

    /*VC->CALL*/
    VC_CALL_END_CALL,

    CALL_VC_MSG_BUTT
};
typedef VOS_UINT16 CALL_VC_MSG_ID_ENUM_U16;



enum CALL_VC_CODEC_TYPE_ENUM
{
    CALL_VC_CODEC_TYPE_AMR,                                                     /* amr */
    CALL_VC_CODEC_TYPE_EFR,                                                     /* enhanced full rate */
    CALL_VC_CODEC_TYPE_FR,                                                      /* full rate */
    CALL_VC_CODEC_TYPE_HR,                                                      /* half rate */
    CALL_VC_CODEC_TYPE_AMR2,                                                    /* amr2 */
    CALL_VC_CODEC_TYPE_AMRWB,                                                    /* amr2 */
    CALL_VC_CODEC_TYPE_G711,                                                    /* G711 */
    CALL_VC_CODEC_TYPE_BUTT                                                     /* invalid value */
};
typedef VOS_UINT8  CALL_VC_CODEC_TYPE_ENUM_U8;

enum CALL_VC_RADIO_MODE_ENUM
{
    CALL_VC_MODE_GSM,
    CALL_VC_MODE_WCDMA,
    CALL_VC_MODE_IMS_EUTRAN,
    CALL_VC_MODE_BUTT
};
typedef VOS_UINT8  CALL_VC_RADIO_MODE_ENUM_U8;

enum CALL_VC_CHANNEL_RATE_ENUM
{
    CALL_VC_CHANNEL_RATE_475,                                                   /* rate 4.75kbps/s */
    CALL_VC_CHANNEL_RATE_515,                                                   /* rate 5.15kbps/s */
    CALL_VC_CHANNEL_RATE_59,                                                    /* rate 5.9kbps/s */
    CALL_VC_CHANNEL_RATE_67,                                                    /* rate 6.7kbps/s */
    CALL_VC_CHANNEL_RATE_74,                                                    /* rate 7.4kbps/s */
    CALL_VC_CHANNEL_RATE_795,                                                   /* rate 7.95kbps/s */
    CALL_VC_CHANNEL_RATE_102,                                                   /* rate 10.2kbps/s */
    CALL_VC_CHANNEL_RATE_122,                                                   /* rate 12.2kbps/s */
    CALL_VC_CHANNEL_RATE_BUFF                                                   /* invalid value */
};
typedef VOS_UINT8  CALL_VC_CHANNEL_RATE_ENUM_U8;
enum APP_VC_OPEN_CHANNEL_FAIL_CAUSE_ENUM
{
    APP_VC_OPEN_CHANNEL_CAUSE_SUCC                = 0,                          /* 成功 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_STARTED,                                     /* HIFI已经启动 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_PORT_CFG_FAIL,                               /* 端口配置失败 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_SET_DEVICE_FAIL,                             /* 设置Device失败 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_SET_START_FAIL,                              /* start失败 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_SET_VOLUME_FAIL,                             /* 设置音量失败 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_SAMPLE_RATE_FAIL,                            /* 速率采样失败 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_TI_START_EXPIRED,                            /* start保护定时器超时 */

    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_BUTT
};
typedef VOS_UINT32  APP_VC_OPEN_CHANNEL_FAIL_CAUSE_ENUM_UINT32;
typedef struct
{
    CALL_VC_RADIO_MODE_ENUM_U8          enMode;                                 /*GSM|WCDMA*/
    CALL_VC_CODEC_TYPE_ENUM_U8          enCodecType;                            /* codec type */
    VOS_UINT8                           aucReserved[2];
 } CALL_VC_CHANNEL_PARAM_STRU;

typedef struct
{
    VOS_BOOL                            bChannelEnable;
    CALL_VC_CHANNEL_PARAM_STRU          stChannelParam;                         /* channel rate */
} CALL_VC_CHANNEL_INFO_STRU;


/*****************************************************************************
 结构名    : CALL_VC_CHANNEL_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 信道信息的结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CALL_VC_MSG_ID_ENUM_U16             enMsgName;                              /* 原语类型 */
    VOS_UINT16                          usReserve;                              /* 保留 */
    CALL_VC_CHANNEL_INFO_STRU           stChannelInfo;
}CALL_VC_CHANNEL_INFO_MSG_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CALL_VC_MSG_ID_ENUM_U16                     enMsgName;                              /* _H2ASN_Skip *//* 原语类型 */
    VOS_UINT8                                   aucReserve[2];                              /* 保留 */
    APP_VC_OPEN_CHANNEL_FAIL_CAUSE_ENUM_UINT32  enCause;
}VC_CALL_MSG_STRU;


/*****************************************************************************
  4 宏定义
*****************************************************************************/


/*****************************************************************************
  5 全局变量声明
*****************************************************************************/


/*****************************************************************************
  6 接口函数声明
*****************************************************************************/



#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* VC_CALL_INTERFACE_H */

