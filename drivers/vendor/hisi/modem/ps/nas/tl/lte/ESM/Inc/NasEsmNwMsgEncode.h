

#ifndef _NASESMNWMSGENCODE_H
#define _NASESMNWMSGENCODE_H


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include    "vos.h"
#include    "NasEsmPublic.h"
#include    "NasEsmNwMsgDecode.h"


/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/

#define NAS_ESM_PCO_CONFIG_PROTOCOL      (0x80)

#define NAS_ESM_MSG_PACKET_HEAD          0x7E

#define NAS_ESM_HIGH_BYTE                0xFF00
#define NAS_ESM_LOW_BYTE                 0x00FF
#define NAS_ESM_THIRD_BYTE               0x00FF0000
/*lint -e961*/
#define NAS_ESM_FOURTH_BYTE              0xFF000000
/*lint +e961*/

#define NAS_ESM_MSG_PCOAPL_LEN           (1)
#define APP_APN_NULL_APN_LEN              1


#define NAS_ESM_MSG_PDNCONREQ_INIT       (0x01)
#define NAS_ESM_MSG_PDNCONREQ_HANDOVER   (0x02)
#define NAS_ESM_MSG_PDNCONREQ_EMERGENCY  (0x04)

#define NAS_ESM_TFT_PARA_LIST_ID         (0x03)
#define NAS_ESM_TFT_PARA_LIST_PF_NUM     (0x01)

#define NAS_ESM_PCO_AUTH_REQ_TYPE        (0x01)
#define NAS_ESM_PCO_AUTH_RSP_TYPE        (0x02)

#define NAS_ESM_IsApnLabelLenValid(ucCharacter,enIsDigit)\
            if(ucCharacter != 0)\
            {\
                enIsDigit = PS_TRUE;\
            }\
            else\
            {\
                enIsDigit = PS_FALSE;\
            }

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

#define NAS_ESM_APN_LABEL_INTERVAL_CHARACTER                (46)    /* 字符'.' */

/*****************************************************************************
  4 Enum
*****************************************************************************/
enum NAS_ESM_SDF_OP_TYPE_ENUM
{
    NAS_ESM_SDF_OP_TYPE_ADD_SDF         = 0x01 ,
    NAS_ESM_SDF_OP_TYPE_DELETE_SDF      = 0x02,
    NAS_ESM_SDF_OP_TYPE_MOD_QOS         = 0x03,
    NAS_ESM_SDF_OP_TYPE_ADD_PF          = 0x04,
    NAS_ESM_SDF_OP_TYPE_MOD_PF          = 0x05,
    NAS_ESM_SDF_OP_TYPE_DELETE_PF       = 0x06,
    NAS_ESM_SDF_OP_TYPE_MOD_QOS_AND_PF  = 0x07,
    NAS_ESM_SDF_OP_TYPE_NO_CHANGE       = 0x08,
    NAS_ESM_SDF_OP_TYPE_BUTT
};
typedef VOS_UINT8  NAS_ESM_SDF_OP_TYPE_ENUM_UINT8;

enum NAS_ESM_APN_VERIFY_CHARACTER_TYPE_ENUM
{
    NAS_ESM_APN_VERIFY_CHARACTER_TYPE_BEGIN         = 0x01 ,
    NAS_ESM_APN_VERIFY_CHARACTER_TYPE_END           = 0x02,
    NAS_ESM_APN_VERIFY_CHARACTER_TYPE_MIDDLE        = 0x03,

    NAS_ESM_APN_VERIFY_CHARACTER_TYPE_BUTT
};
typedef VOS_UINT8  NAS_ESM_APN_VERIFY_CHARACTER_TYPE_ENUM_UINT8;

enum NAS_ESM_FUN_CTRL_ENUM
{
    NAS_ESM_FUN_CTRL_OFF              = 0x00 ,
    NAS_ESM_FUN_CTRL_ON               = 0x01,

    NAS_ESM_FUN_CTRL_BUTT
};
typedef VOS_UINT32  NAS_ESM_FUN_CTRL_ENUM_UINT32;

enum NAS_ESM_GET_IPV6_DNS_CTRL_ENUM
{
    NAS_ESM_GET_IPV6_DNS_CTRL_OFF        = 0x00 ,
    NAS_ESM_GET_IPV6_DNS_CTRL_ON         = 0x01,

    NAS_ESM_GET_IPV6_DNS_CTRL_BUTT
};
typedef VOS_UINT32  NAS_ESM_GET_IPV6_DNS_CTRL_ENUM_UINT32;


/*****************************************************************************
  5 STRUCT
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpESMCau         :1;
    VOS_UINT32                          bitOpSpare          :31;

    VOS_UINT32                          ulEpsbId;
    VOS_UINT32                          ulLinkedEpsbId;
    VOS_UINT32                          ulCid;

    VOS_UINT8                           ucPti;
    NAS_ESM_CAUSE_ENUM_UINT8            ucESMCau;
    NAS_ESM_PDN_REQ_TYPE_ENUM_UINT8     enPdnReqType;
    VOS_UINT8                           aucRsv[1];

}NAS_ESM_ENCODE_INFO_STRU;

typedef struct
{
    VOS_UINT32                          bitOpESMCau         :1;
    VOS_UINT32                          bitOpSpare          :31;

    VOS_UINT32                          ulEpsbId;
    VOS_UINT32                          ulLinkedEpsbId;
    VOS_UINT32                          ulCid;

    VOS_UINT8                           ucPti;
    NAS_ESM_SDF_OP_TYPE_ENUM_UINT8      enSdfOpType;
    NAS_ESM_CAUSE_ENUM_UINT8            ucESMCau;
    VOS_UINT8                           aucRsv[1];

}NAS_ESM_RES_MOD_ENCODE_INFO_STRU;


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
extern VOS_VOID NAS_ESM_EncodeActDedictdEpsbCntxtAccMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeActDedictdEpsbCntxtRejMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeActDefltEpsbCntxtAccMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeActDefltEpsbCntxtRejMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);

extern VOS_UINT32 NAS_ESM_EncodeAPN( const APP_ESM_APN_INFO_STRU  *pstAPNInfo,
                                             VOS_UINT8  *pSendMsg,
                                             VOS_UINT32 *pulLength,
                                             NAS_MSG_FORMAT_ENUM_UINT8   enEncodeTp);
extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsg
       (
           NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
           VOS_UINT8                          *pSendMsg,
           VOS_UINT32                         *pulLength
       );
extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsgAddSdf
       (
           NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
           VOS_UINT8                           *pSendMsg,
           VOS_UINT32                          *pulLength
       );
extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsgDeleteSdf
       (
           NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
           VOS_UINT8                           *pSendMsg,
           VOS_UINT32                          *pulLength
       );

extern VOS_UINT32  NAS_ESM_EncodeBearerResModReqMsgRelBearer
(
    NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength
);

extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsgModPf
       (
           NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
           VOS_UINT8                           *pSendMsg,
           VOS_UINT32                          *pulLength
       );
extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsgModQos
(
    NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength
);
extern VOS_UINT32 NAS_ESM_EncodeBearerResModReqMsgModQosAndPf
(
    NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
    VOS_UINT8                           *pSendMsg,
    VOS_UINT32                          *pulLength
);

extern VOS_VOID NAS_ESM_EncodeDeactEpsbCntxtAccMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID  NAS_ESM_EncodeTftDeletePf
(
    NAS_ESM_CONTEXT_TFT_STRU            *pstTFTInfo,
    VOS_UINT32                           ulPFNum,
    VOS_UINT8                           *pSendMsg,
    VOS_UINT32                          *pulLength
);

extern VOS_UINT32 NAS_ESM_IsSdfQueryNwPfIdSucc
(
    const NAS_ESM_RES_MOD_ENCODE_INFO_STRU    *pstResModEncodeInfo
);

extern VOS_UINT32 NAS_ESM_EncodeEsmInformationRspMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength );
extern VOS_VOID NAS_ESM_EncodeEsmStatus( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeModEpsbCntxtAccMsg( const NAS_ESM_ENCODE_INFO_STRU *pstEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeModEpsbCntxtRejMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_VOID NAS_ESM_EncodeOneFilterContent
       (
           NAS_ESM_CONTEXT_TFT_STRU           *pstTFTInfo,
           VOS_UINT8                          *pSendMsg,
           VOS_UINT32                         *pulLength
       );
extern VOS_VOID NAS_ESM_EncodeTftNoOperation
(
    const VOS_UINT8                    *pucNwPfId,
    VOS_UINT32                          ulPFNum,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength
);
extern VOS_UINT32 NAS_ESM_EncodePco
(
    NAS_ESM_SDF_PARA_STRU              *pstSdfPara,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength,
    NAS_MSG_FORMAT_ENUM_UINT8           enEncodeTp
);
extern VOS_UINT32 NAS_ESM_EncodePdnConReqMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_UINT32 NAS_ESM_EncodePdnDisconReqMsg( NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
                                                            VOS_UINT8  *pSendMsg,
                                                            VOS_UINT32 *pulLength);
extern VOS_UINT32 NAS_ESM_EncodeEpsQos
(
    NAS_ESM_CONTEXT_LTE_QOS_STRU       *pstEpsQosInfo,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength,
    NAS_MSG_FORMAT_ENUM_UINT8           enEncodeTp
);

extern VOS_UINT32  NAS_ESM_IsApnCharacterValid
(
    VOS_UINT8 ucCharacter,
    NAS_ESM_APN_VERIFY_CHARACTER_TYPE_ENUM_UINT8 enApnVerifyCharacterType
);

extern VOS_UINT32  NAS_ESM_VerifyApnCharacter
(
    VOS_UINT32 ulCur,
    const VOS_UINT8* pucApnName,
    const VOS_UINT8  ucApnLen
);


extern VOS_UINT32  NAS_ESM_ApnTransformaton
(
    NAS_ESM_CONTEXT_APN_STRU  *pstAPNInfoAfterTrans,
    const APP_ESM_APN_INFO_STRU  *pstAPNInfoBeforeTrans
);

extern VOS_UINT32 NAS_ESM_CheckApnReverseTransformationParaValid
(
    const APP_ESM_APN_INFO_STRU  *pstAPNInfoAfterTrans,
    const NAS_ESM_CONTEXT_APN_STRU  *pstAPNInfoBeforeTrans
);


extern VOS_UINT32  NAS_ESM_ApnReverseTransformation
(
    APP_ESM_APN_INFO_STRU  *pstAPNInfoAfterTrans,
    const NAS_ESM_CONTEXT_APN_STRU  *pstAPNInfoBeforeTrans
);

extern VOS_UINT32  NAS_ESM_EncodeBearerResAllocReqMsg
(
    NAS_ESM_ENCODE_INFO_STRU			stEncodeInfo,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength
);

extern VOS_VOID NAS_ESM_ModEpsQos
(
    const APP_ESM_EPS_QOS_INFO_STRU                *pstNwEpsQoSInfoOld,
    const APP_ESM_EPS_QOS_INFO_STRU                *pstNwEpsQoSInfoNew,
    APP_ESM_EPS_QOS_INFO_STRU                      *pstNwEpsQoSInfo
);

extern VOS_UINT32  NAS_ESM_EncodeTftCreateTftOrReplacePf
(
    VOS_UINT8                           ucTadType,
    VOS_UINT32                          ulCid,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength
);

extern VOS_VOID  NAS_ESM_EncodePapContent
(
    VOS_UINT8                          *pSendMsg,
    APP_ESM_GW_AUTH_INFO_STRU          *pstGwAuthInfo,
    VOS_UINT32                         *pulLength
);
extern VOS_UINT32  NAS_ESM_GetEpsQosAfterMod
(
    NAS_ESM_RES_MOD_ENCODE_INFO_STRU    stResModEncodeInfo,
    NAS_ESM_CONTEXT_LTE_QOS_STRU       *pstEpsQoSInfo
);
extern VOS_UINT32 NAS_ESM_EncodePdnConReqMsg_PPP
(
    const APP_ESM_PDP_SETUP_REQ_STRU *pstAppEsmSetupReqMsg,
    NAS_ESM_ENCODE_INFO_STRU stEncodeInfo,
    VOS_UINT8  *pSendMsg,
    VOS_UINT32 *pulLength
);
extern VOS_UINT32 NAS_ESM_EncodePco_PPP
(
    const NAS_ESM_SDF_PARA_STRU              *pstSdfPara,
    const APP_ESM_PPP_INFO_STRU        *pstPppInfo,
    VOS_UINT8                          *pSendMsg,
    VOS_UINT32                         *pulLength,
    NAS_MSG_FORMAT_ENUM_UINT8           enEncodeTp
);
extern VOS_VOID  NAS_ESM_EncodeChapContent_PPP
(
    VOS_UINT8                          *pSendMsg,
    const APP_ESM_AUTH_INFO_STRU       *pstAuthInfo,
    VOS_UINT32                         *pulLength
);
extern VOS_UINT32 NAS_ESM_VerifyAppAuthParam_PPP
(
    const APP_ESM_AUTH_INFO_STRU   *pstAuthInfo
);
/*****************************************************************************
  9 OTHERS
*****************************************************************************/



#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of NasEsmNwMsgProc.h*/
