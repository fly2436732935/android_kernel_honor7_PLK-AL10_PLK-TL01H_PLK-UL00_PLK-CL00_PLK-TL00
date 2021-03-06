


/*****************************************************************************
   1 头文件包含
*****************************************************************************/
#include "Taf_Aps.h"
#include "MnApsComm.h"
#include "TafApsMain.h"
#include "TafApsCtx.h"

#ifdef  __cplusplus
  #if  __cplusplus
  extern "C"{
  #endif
#endif

/*****************************************************************************
    协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_TAF_APSDEALSNDCPMSG_C


/*****************************************************************************
   2 全局变量定义
*****************************************************************************/


/*****************************************************************************
   3 函数实现
*****************************************************************************/


/*****************************************************************************
 Prototype      : Aps_SnMsgModSnActRspParaCheck()
 Description    : SNDCP的激活RSP和修改RSP的消息内容相同,故使用同一个函数来进行
                  参数检查.
 Input          : pSnActRsp
 Output         :
 Return Value   : #define APS_PARA_VALID                  0
                  #define APS_PARA_INVALID                1
 Data Access    :
 Data Update    :
 Calls          :
 Called By      :
 History        : ---
  1.Date        : 2005-
    Author      : ---
    Modification: Created function
*****************************************************************************/
VOS_UINT32  Aps_SnMsgModSnActRspParaCheck( APS_SNDCP_ACTIVATE_RSP_ST* pSnActRsp)
{
    if ( pSnActRsp->XidParameter.ucMask & SN_XID_PARA_P_CMPR)
    {
        if ( !(APS_SN_P_CMP_VALID(pSnActRsp->XidParameter.ucPCmprAlgrth)) )
        {
            return  APS_PARA_INVALID;
        }
    }

    if ( pSnActRsp->XidParameter.ucMask & SN_XID_PARA_D_CMPR)
    {
        if ( !(APS_SN_H_CMP_VALID(pSnActRsp->XidParameter.ucDCmprAlgrth)) )
        {
            return  APS_PARA_INVALID;
        }
    }
    return  APS_PARA_VALID;

}

/*****************************************************************************
 Prototype      : Aps_SnActRspChngEntity()
 Description    : 收到SN_ACT_RSP后修改状态机参数,包括XID参数,TRANSMODE,状态
 Input          : pSnMdfRsp
 Output         : NO
 Return Value   :
 Data Access    :
 Data Update    :
 Calls          : Rabm_SetTransMode();
                  Aps_DealEntityTrans();
 Called By      : Aps_DealAllFromSndcp()
 History        : ---
  1.Date        : 2005-
    Author      : ---
    Modification: Created function
*****************************************************************************/
VOS_VOID    Aps_SnActRspChngEntity(     APS_SNDCP_ACTIVATE_RSP_ST*  pSnActRsp,
                                        VOS_UINT8                   ucPdpId)
{
    RABM_TRANS_MODE_ENUM                TansMode;

    /*将传来的XID填入状态机*/
    if ( pSnActRsp->XidParameter.ucMask & SN_XID_PARA_P_CMPR)
    {
        g_PdpEntity[ucPdpId].PdpGprsParaFlag        = APS_USED;
        g_PdpEntity[ucPdpId].GprsPara.Op_Xid_PCmp   = APS_USED;
        g_PdpEntity[ucPdpId].GprsPara.ucPCmprAlgrth
                                        = pSnActRsp->XidParameter.ucPCmprAlgrth;
    }

    if ( pSnActRsp->XidParameter.ucMask & SN_XID_PARA_D_CMPR)
    {
        g_PdpEntity[ucPdpId].PdpGprsParaFlag        = APS_USED;
        g_PdpEntity[ucPdpId].GprsPara.Op_Xid_DCmp   = APS_USED;
        g_PdpEntity[ucPdpId].GprsPara.ucDCmprAlgrth
                                        = pSnActRsp->XidParameter.ucDCmprAlgrth;
    }

    Aps_DecideTransMode( ucPdpId, &TansMode );

    /*填写状态机中的TRANSMODE*/
    g_PdpEntity[ucPdpId].GprsPara.Op_TransMode  = APS_USED;
    g_PdpEntity[ucPdpId].GprsPara.TransMode     = TansMode;

    return;
}

/*****************************************************************************
 Prototype      : Aps_SnMsgModSnMdfRsp()
 Description    : APS修改指示SNDCP后,SNDCP应该返回APS响应信息.该函数用于处理这
                  个响应消息.并调用RABM提供的函数设置RABM的TRANSMODE,然后上报
                  APP修改是否成功的事件。
 Input          : pSnMdfRsp
 Output         : NO
 Return Value   :
 Data Access    :
 Data Update    :
 Calls          : Rabm_SetTransMode();
                  Aps_DealEntityTrans();
 Called By      : Aps_DealAllFromSndcp()
 History        : ---
  1.Date        : 2005-
    Author      : ---
    Modification: Created function
*****************************************************************************/
VOS_UINT32    Aps_SnMsgModSnMdfRsp  ( APS_SNDCP_MODIFY_RSP_ST*  pSnMdfRsp )
{
    VOS_UINT8                       ucPdpId;
    RABM_APS_SET_TRANS_MODE_ST      ApsRabmSetTRansMod;

    ucPdpId = TAF_APS_GetCurrFsmEntityPdpId();

    Aps_SnMdfRspChngEntity(pSnMdfRsp, ucPdpId);

    ApsRabmSetTRansMod.ucNsapi      = pSnMdfRsp->ucNsapi;
    ApsRabmSetTRansMod.TransMode    = g_PdpEntity[ucPdpId].GprsPara.TransMode;

    /*设置RABM的传输模式*/
    if ( APS_SUCC != Aps_SetRabmTransMode(&ApsRabmSetTRansMod))
    {
        APS_WARN_LOG("NAS_RabmSetTransMode ERR ");
        return APS_FAIL;
    }

    return APS_SUCC;
}

/*****************************************************************************
 Prototype      : Aps_SnMsgModSnMdfRspParaCheck()
 Description    :
 Input          : pSnActRsp
 Output         :
 Return Value   : #define APS_PARA_VALID                  0
                  #define APS_PARA_INVALID                1
                  APS_NSAPI_INVALID
 Data Access    :
 Data Update    :
 Calls          :
 Called By      :
 History        : ---
  1.Date        : 2005-
    Author      : ---
    Modification: Created function
*****************************************************************************/
VOS_UINT32  Aps_SnMsgModSnMdfRspParaCheck( APS_SNDCP_MODIFY_RSP_ST*   pSnActRsp)
{
    if ( !(APS_JUDGE_NSAPI_VALID(pSnActRsp->ucNsapi)))
    {
        return  APS_NSAPI_INVALID;
    }

    return  APS_PARA_VALID;
}


VOS_VOID    Aps_SnMdfRspChngEntity(
    APS_SNDCP_MODIFY_RSP_ST            *pSnMdfRsp,
    VOS_UINT8                           ucPdpId
)
{
    RABM_TRANS_MODE_ENUM                TansMode;

    Aps_DecideTransMode( ucPdpId, &TansMode );

    /*填写状态机中的TRANSMODE*/
    g_PdpEntity[ucPdpId].GprsPara.Op_TransMode  = APS_USED;
    g_PdpEntity[ucPdpId].GprsPara.TransMode     = TansMode;

    return;
}


/*****************************************************************************
 Prototype      : Aps_SnMsgModSnDeActRspParaCheck()
 Description    : 检查SAPI
 Input          : pSnActRsp
 Output         :
 Return Value   : #define APS_PARA_VALID                  0
                  #define APS_PARA_INVALID                1
 Data Access    :
 Data Update    :
 Calls          :
 Called By      :
 History        : ---
  1.Date        : 2005-
    Author      : ---
    Modification: Created function
*****************************************************************************/
VOS_UINT32  Aps_SnMsgModSnStatusReqParaCheck
                            (   APS_SNDCP_STATUS_REQ_ST    *pSnDeActRsp)
{
    if ( !(APS_JUDGE_SAPI_VALID(pSnDeActRsp->ucSapi)))
    {
        return  APS_PARA_INVALID;
    }

    return  APS_PARA_VALID;
}


VOS_UINT32  Aps_SetRabmTransMode(   RABM_APS_SET_TRANS_MODE_ST *pApsRabmSetTRansMod)
{
    VOS_UINT32                      ulRet;
    RABM_APS_SET_TRANSMODE_MSG     *pApsSetRabmTransmodeMsg;

    /*申请消息*/
    pApsSetRabmTransmodeMsg = (RABM_APS_SET_TRANSMODE_MSG *)PS_ALLOC_MSG(WUEPS_PID_TAF, (sizeof(RABM_APS_SET_TRANSMODE_MSG) - VOS_MSG_HEAD_LENGTH));
    if ( VOS_NULL_PTR == pApsSetRabmTransmodeMsg )
    {
        APS_ERR_LOG("Aps_SetRabmTransMode VOS_AllocMsg err ");
        return TAF_FAILURE;
    }

    /*构造RABM的消息头*/
    pApsSetRabmTransmodeMsg->ulSenderCpuId    = VOS_LOCAL_CPUID;
    pApsSetRabmTransmodeMsg->ulSenderPid      = WUEPS_PID_TAF;
    pApsSetRabmTransmodeMsg->ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pApsSetRabmTransmodeMsg->ulReceiverPid    = WUEPS_PID_RABM;

    pApsSetRabmTransmodeMsg->ulLength         = sizeof(RABM_APS_SET_TRANSMODE_MSG) - VOS_MSG_HEAD_LENGTH;

    /*填消息类型*/
    pApsSetRabmTransmodeMsg->usMsgType        = RABM_APS_SET_TRANSMODE_MSG_TYPE;

    /*填消息内容*/
    pApsSetRabmTransmodeMsg->RabmApsSetTransMode
                                            = *pApsRabmSetTRansMod;

    /*发送消息*/
    ulRet = PS_SEND_MSG(WUEPS_PID_TAF, pApsSetRabmTransmodeMsg );
    if ( VOS_OK != ulRet )
    {
        APS_WARN_LOG("Aps Send RABM_APS_SET_TRANSMODE_MSG ERR ");
        return  APS_FAIL;
    }

    APS_NORM_LOG("APS->RABM RABM_APS_SET_TRANSMODE_MSG ");

    return APS_SUCC;

}

VOS_VOID    Aps_RabmMsgActSndcp (   VOS_UINT8    ucPdpId )
{
    APS_INNER_SN_ACT_ST             InnerSnActInd;
    SM_TAF_QOS_STRU                 SmQos;

    if (APS_SNDCP_ACT == g_PdpEntity[ucPdpId].PdpProcTrack.ucSNDCPActOrNot)
    {
        /* SNDCP已经激活，无须再次激活 */
        return;
    }

    /*填PdpId*/
    InnerSnActInd.ucPdpId           = ucPdpId;

    /*调用函数Aps_PackSmQos ( &(g_PdpEntity[ucPdpId].PdpQos), &SmQos )把状态机
    中的QOS转换为激活SNDCP需要的QOS结构;*/
    PS_MEM_SET(&SmQos,0x00,sizeof(SmQos));
    Aps_PackSmQos ( &(g_PdpEntity[ucPdpId].PdpQos), &SmQos );
    InnerSnActInd.pQos              = &SmQos;

    Aps_SmMsgModSnActInd(&InnerSnActInd, APS_ACT_SN_SYS_CHNG);

    /*为了区别切换引起的激活SNDCP，以免收到SN的激活响应后再上报，在此设置标识*/
    g_PdpEntity[ucPdpId].PdpProcTrackFlag               = APS_USED;
    g_PdpEntity[ucPdpId].PdpProcTrack.ucHowToInitAct    = APS_SYSCHNG_ACT_SN;
    g_PdpEntity[ucPdpId].PdpProcTrack.ucSNDCPActOrNot   = APS_SNDCP_ACT;

    return;
}

/*****************************************************************************
 Prototype      : Aps_RabmMsgDeActSndcp
 Description    : 收到RABM的切换消息后，若要发起去激活SNDCP，就调用此函数.
 Input          : pRabmMsg
 Output         : ---
 Return Value   : ---
 Data Access    :
 Data Update    :
 Calls          : Aps_SmMsgModSnDeActInd    (   VOS_UINT8    ucPdpId )
 Called By      : ---
 History        : ---
  1.Date        : 2005-0
    Author      : 韩鲁峰
    Modification: Created function
*****************************************************************************/
VOS_VOID    Aps_RabmMsgDeActSndcp ( VOS_UINT8    ucPdpId )
{
    if (APS_SNDCP_INACT == g_PdpEntity[ucPdpId].PdpProcTrack.ucSNDCPActOrNot)
    {
        /*SNDCP未被激活*/
        APS_WARN_LOG("Aps_RabmMsgDeActSndcp: SNDCP has been deactived already!!");
        return;
    }

    Aps_SmMsgModSnDeActInd(ucPdpId);

    g_PdpEntity[ucPdpId].PdpProcTrack.ucSNDCPActOrNot = APS_SNDCP_INACT;

    return;
}
VOS_UINT32 TAF_APS_ValidatePdpForSnStatusReq(
    VOS_UINT8                           ucPdpId,
    APS_SNDCP_STATUS_REQ_ST            *pstSnStatusReq
)
{
    VOS_UINT32                          ulResult;
    APS_PDP_CONTEXT_ENTITY_ST          *pstPdpEntity;

    /* 获取该PDPID的PDP实体内容地址 */
    ulResult                            = VOS_FALSE;
    pstPdpEntity                        = TAF_APS_GetPdpEntInfoAddr(ucPdpId);

    switch (pstSnStatusReq->usSnCause)
    {
        case SN_CAUSE_NORMAL_REL:           /*Cause "normal release"*/
            /*SM shall then deactivate all PDP contexts for that SAPI requiring
              acknowledged peer-to-peer LLC operation*/

        case SN_CAUSE_DM_RCV:               /*Cause "DM received"*/
            /*SM shall then deactivate all PDP contexts for that SAPI requiring
              acknowledged peer-to-peer LLC operation*/

            if ( (VOS_TRUE               == pstPdpEntity->PdpGprsParaFlag)
              && (VOS_TRUE               == pstPdpEntity->GprsPara.Op_Sapi)
              && (pstSnStatusReq->ucSapi == pstPdpEntity->GprsPara.ucSapi)
              && (VOS_TRUE               == pstPdpEntity->GprsPara.Op_TransMode)
              && (RABM_ABM_ENUM          == pstPdpEntity->GprsPara.TransMode) )
            {
                ulResult = VOS_TRUE;
            }
            break;

        case    SN_CAUSE_NO_PEER_RSP:          /*Cause "no peer response"*/
            /*处理方式同下面的CASE,故不用break*/

        case    SN_CAUSE_INVALID_XID_RSP:      /*Cause "invalid XID response"*/
            /*SM shall then deactivate all PDP contexts for that SAPI*/
            /*处理方式同下面的CASE,故不用break*/

        case    SN_CAUSE_INVALID_XID_CMD:       /*Cause "invalid XID command"*/
            /*SM shall then deactivate all PDP contexts for this SAPI*/

            if ( (VOS_TRUE               == pstPdpEntity->PdpGprsParaFlag)
              && (VOS_TRUE               == pstPdpEntity->GprsPara.Op_Sapi)
              && (pstSnStatusReq->ucSapi == pstPdpEntity->GprsPara.ucSapi) )
            {
                ulResult = VOS_TRUE;
            }
            break;

        default :
            APS_WARN_LOG("SNDCP -> Aps : invalid Status Msg Cause !");
            break;
    }

    return ulResult;
}



#ifdef  __cplusplus
  #if  __cplusplus
  }
  #endif
#endif
