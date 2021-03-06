

#ifndef __CDS_DLPROC_H__
#define __CDS_DLPROC_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "CdsDepend.h"

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*存储RABID和SDU LEN到TTF描述符中*/
/*lint -emacro({717}, CDS_DL_SAVE_LEN_MODEMID_RABID_TO_TTF)*/
/*lint -emacro({701}, CDS_DL_SAVE_LEN_MODEMID_RABID_TO_TTF)*/
#define CDS_DL_SAVE_LEN_MODEMID_RABID_TO_TTF(pstIpPkt,usLen,usModemId,ucRabId) \
                    do\
                    {\
                        (pstIpPkt)->ulForCds[0] = 0;\
                        (pstIpPkt)->ulForCds[0] = ((usModemId) << 8) | ucRabId;\
                        (pstIpPkt)->ulForCds[0] = ((usLen) << 16) | ((pstIpPkt)->ulForCds[0]);\
                    }while(0)

/*从TTF描述符中获取ModemId/RABID*/
#define CDS_DL_GET_MODEMID_RABID_FROM_TTF(pstTtfMem)\
                    (VOS_UINT16)((pstTtfMem)->ulForCds[0] & 0x0000FFFF)

/*从TTF描述符中取Sdu Len*/
#define CDS_DL_GET_PKT_LEN_FROM_TTF(pstTtfMem)      \
                    (VOS_UINT16)(((pstTtfMem)->ulForCds[0]) >> 16)

/*从TTF描述符中取ModemId*/
#define CDS_DL_GET_MODEMID_FROM_TTF(pstTtfMem)      \
                    (VOS_UINT8)(((pstTtfMem)->ulForCds[0] & 0x0000FF00) >> 8)

/*从TTF描述符中取RABID*/
#define CDS_DL_GET_RABID_FROM_TTF(pstTtfMem)        \
                    (VOS_UINT8)((pstTtfMem)->ulForCds[0] & 0x000000FF)


/*定义CDS下行接受SDU的最大长度*/
#define CDS_DL_SDU_MAX_LEN               (1536)


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
  4 枚举定义
*****************************************************************************/


/*****************************************************************************
   5 STRUCT定义
*****************************************************************************/



/*****************************************************************************
  6 UNION定义
*****************************************************************************/


/*****************************************************************************
  7 全局变量声明
*****************************************************************************/


/*****************************************************************************
  8 函数声明
*****************************************************************************/
extern VOS_VOID   CDS_LTE_RecvDbgData(TTF_MEM_ST *pstIpPkt);
extern VOS_UINT32 CDS_GUGetDefaultRabId(VOS_UINT8 ucRabId, VOS_UINT8 *pucDeftRabId, MODEM_ID_ENUM_UINT16 enModemId);


/*****************************************************************************
  9 OTHERS定义
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

#endif

