
#include "vxWorks.h"
#include <stdio.h>
#include "product_config.h"
#include "drv_sci.h"
#include "bsp_om.h"
#include "bsp_sci.h"

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_RST
*
* ��������  : ���ӿ����ڸ�λSCI��Smart Card Interface��������USIM��Universal 
*           Subscriber Identity Module����
*
* �������  :  ��
* �������  : ��
*
* �� �� ֵ  : OK  ��λ�ɹ�
*
* �޸ļ�¼  :  Yangzhi create
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_RST(RESET_MODE rstMode)
{
#if defined(INSTANCE_1)
	return ((BSP_S32)I1_bsp_sci_reset(rstMode));
#else
    return ((BSP_S32)bsp_sci_reset(rstMode));
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_GET_CARD_STAU
*
* ��������  : ���ӿ����ڻ�ÿ���ǰ��״̬
*
* �������  : ��  
* �������  : ��
                 
* �� �� ֵ  :    ��״̬
*           
*
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_U32 DRV_USIMMSCI_GET_CARD_STAU(BSP_VOID)
{
#if defined(INSTANCE_1)
    return ((BSP_U32)I1_bsp_sci_card_status_get());
#else
    return ((BSP_U32)bsp_sci_card_status_get());
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_SND_DATA
*
* ��������  : ���ӿ����ڷ���һ�����ݵ�USIM��
*
* �������  : u32 u32DataLength �������ݵ���Ч���ȡ�ȡֵ��Χ1��256����λΪ�ֽ�  
*             u8 *pu8DataBuffer �������������ڴ���׵�ַ�����Ƕ�̬���䣬���ýӿ�
*                                   ���������ͷţ�������Ӳ����������
* �������  : ��
*
* �� �� ֵ  : OK
*           BSP_ERR_SCI_NOTINIT
*           BSP_ERR_SCI_INVALIDPARA
*           BSP_ERR_SCI_DISABLED
*           BSP_ERR_SCI_NOCARD
*           BSP_ERR_SCI_NODATA
*
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_SND_DATA(BSP_U32 u32DataLength,BSP_U8 * pu8DataBuffer)
{
#if defined(INSTANCE_1)
    return ((BSP_S32)I1_bsp_sci_data_send(u32DataLength, pu8DataBuffer));
#else
    return ((BSP_S32)bsp_sci_data_send(u32DataLength, pu8DataBuffer));
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_RCV
*
* ��������  : ���ӿ�����USIM Manager��ȡ����SCI Driver�Ŀ���������
*             �ýӿ�Ϊ�����ӿڣ�ֻ��SCI���յ��㹻����������Ż᷵�أ�
*             �ýӿڵĳ�ʱ����Ϊ1s
*
* �������  : u32  u32DataLength USIM Manager����SCI Driver��ȡ�����ݳ��ȡ�
* �������  : u8 *pu8DataBuffer USIM Managerָ����Buffer��SCI Driver�����ݿ�������Buffer��
* �� �� ֵ  : OK
*             BSP_ERR_SCI_NOTINIT
*             BSP_ERR_SCI_INVALIDPARA
*
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_RCV(BSP_U32 u32DataLength,BSP_U8 * pu8DataBuffer)
{
#if defined(INSTANCE_1)
        return ((BSP_S32)I1_bsp_sci_data_read_sync(u32DataLength, pu8DataBuffer));
#else
        return ((BSP_S32)bsp_sci_data_read_sync(u32DataLength, pu8DataBuffer));
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_RCV_ALL
*
* ��������  : ���ӿ�����USIM Manager�ڶ�����ʱ��ʱ�򣬵��ñ���������ȡ�������ݻ����е���������
*
* �������  : ��  
* �������  : u32 *u32DataLength Driver��ȡ�����ݳ��ȣ����ظ�USIM Manager��ȡֵ��Χ1��256����λ���ֽ�
*           u8 * pu8DataBuffer USIM Managerָ����Buffer��SCI Driver�����ݿ�������Buffer
*
* �� �� ֵ  : OK
*          BSP_ERR_SCI_NOTINIT
*          BSP_ERR_SCI_INVALIDPARA
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32 DRV_USIMMSCI_RCV_ALL(u32 *u32DataLength,u8 * pu8DataBuffer)
{
#if defined(INSTANCE_1)
    return ((u32)I1_bsp_sci_all_data_read(u32DataLength, pu8DataBuffer));
#else
    return ((u32)bsp_sci_all_data_read(u32DataLength, pu8DataBuffer));
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_GET_ATR
*
* ��������  : ���ӿ����ڽ�Driver�㻺���ATR���ݺ����ݸ������ظ�USIM Manager��
*
* �������  : void  
* �������  : u8 *u8DataLength  Driver��ȡ��ATR���ݳ��ȣ����ظ�USIM Manager��
*                                   ȡֵ��Χ0��32����λ���ֽ�
*           u8 *pu8ATR          USIM Managerָ����Buffer��SCI Driver��ATR
*                                   ���ݿ�������Buffer��һ��Ϊ����ϵͳ������̬����
*                                   ���߾�̬����ĵ�ַ
* 
*
* �� �� ֵ  : OK
*          BSP_ERR_SCI_NOTINIT
*          BSP_ERR_SCI_INVALIDPARA
*
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_GET_ATR(unsigned long * u32DataLength, BSP_U8 * pu8ATR,SCI_ATRInfo* stSCIATRInfo)
{
#if defined(INSTANCE_1)
    return ((BSP_S32)I1_bsp_sci_atr_get(u32DataLength, pu8ATR,stSCIATRInfo));
#else
    return ((BSP_S32)bsp_sci_atr_get(u32DataLength, pu8ATR,stSCIATRInfo));
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_CLASS_SWITCH
*
* ��������  : ���ӿ�����֧��PS�Կ��ĵ�ѹ���ͽ����л�����1.8V�л���3V
*
* �������  : BSP_VOID  
* �������  : ��
*
* �� �� ֵ  :  OK    ��ǰ��ѹ������ߵģ����е�ѹ�л�����
*           BSP_ERR_SCI_CURRENT_STATE_ERR �л�ʧ�� current SCI driver state is ready/rx/tx 
*           BSP_ERR_SCI_VLTG_HIGHEST   ��ǰ��ѹ�Ѿ�����ߵ�ѹ��û�н��е�ѹ�л�
*           BSP_ERR_SCI_NOTINIT
*           BSP_ERR_SCI_CURRENT_VLTG_ERR ��ǰ��ѹֵ�쳣����class B����C��
*
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_S32  DRV_USIMMSCI_CLASS_SWITCH(BSP_VOID)
{
#if defined(INSTANCE_1)
        return ((BSP_S32)I1_bsp_sci_vltg_class_switch());
#else
        return ((BSP_S32)bsp_sci_vltg_class_switch());
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_SHOW_VLT
*
* ��������  : ���ӿ�������ʾ��ǰSIM���ӿڵ�ѹ
*
* �������  : ��  
* �������  :u32 * pu32Vltgval ��ǰ��ѹ
*
* �� �� ֵ  : OK
*          BSP_ERR_SCI_NOTINIT
*          BSP_ERR_SCI_INVALIDPARA
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32  DRV_USIMMSCI_SHOW_VLT(BSP_U32* pu32Vltgval)
{
#if defined(INSTANCE_1)
    return ((BSP_U32)I1_bsp_sci_show_vltg_val(pu32Vltgval));
#else
    return ((BSP_U32)bsp_sci_show_vltg_val(pu32Vltgval));
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_TM_STOP
*
* ��������  : ���ӿ�����֧��PS�ر�SIM��ʱ��
*
* �������  : 
*           SCI_CLK_STOP_TYPE_E enTimeStopCfg ʱ��ֹͣģʽ
*   
* �������  : ��
*
* �� �� ֵ  : OK - successful completion
*               ERROR - failed
*               BSP_ERR_SCI_NOTINIT
*               BSP_ERR_SCI_INVALIDPARA - invalid mode specified
*               BSP_ERR_SCI_UNSUPPORTED - not support such a operation
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_TM_STOP(SCI_CLK_STOP_TYPE_E enTimeStopCfg)
{
#if defined(INSTANCE_1)
    return I1_bsp_sci_clk_status_cfg((u32)enTimeStopCfg);
#else
    return bsp_sci_clk_status_cfg((u32)enTimeStopCfg);
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_DEACT
*
* ��������  : ���ӿ����ڶ�SIM����ȥ�������
*
* �������  : ��
*   
* �������  : ��
*
* �� �� ֵ  : OK
*             BSP_ERR_SCI_NOTINIT
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32 DRV_USIMMSCI_DEACT(BSP_VOID)
{
#if defined(INSTANCE_1)
    return I1_bsp_sci_deactive();
#else
    return bsp_sci_deactive();
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_GET_CLK_STAU
*
* ��������  : ���ӿ����ڻ�ȡ��ǰSIM��ʱ��״̬
*
* �������  : u32 *pu32SciClkStatus   ����ָ�룬���ڷ���SIM��ʱ��״̬��
*                                       0��ʱ���Ѵ򿪣�
*                                       1��ʱ��ֹͣ 
* �������  : ��
*
* �� �� ֵ  : OK    �����ɹ�
*          BSP_ERR_SCI_INVALIDPARA
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32 DRV_USIMMSCI_GET_CLK_STAU(BSP_U32 * pu32SciClkStatus)
{
#if defined(INSTANCE_1)
    return (BSP_U32)I1_bsp_sci_get_clk_status(pu32SciClkStatus);
#else
    return (BSP_U32)bsp_sci_get_clk_status(pu32SciClkStatus);
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_PCSC_GET_CLK_FREQ
*
* ��������  : ���ӿ����ڻ�ȡ��ǰSIM��ʱ��Ƶ��
*
* �������  : ��
*
* �������  : BSP_U32 *pLen   ʱ��Ƶ�����ݵĳ���
*             BSP_U8 *pBuf    ʱ��Ƶ������
* �� �� ֵ  : OK    �����ɹ�
*             BSP_ERR_SCI_INVALIDPARA
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_U32 DRV_PCSC_GET_CLK_FREQ(unsigned long * pLen,BSP_U8 * pBuf)
{
#if defined(INSTANCE_1)
    return (BSP_U32)I1_appl131_get_clk_freq((u32*)pLen, pBuf);
#else
    return (BSP_U32)appl131_get_clk_freq((u32*)pLen, pBuf);
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_PCSC_GET_BAUD_RATE
*
* ��������  : ���ӿ����ڻ�ȡ��ǰSIM��������
*
* �������  : ��
*
* �������  : BSP_U32 *pLen   ���������ݵĳ���
*             BSP_U8 *pBuf    ����������
*
* �� �� ֵ  : OK    �����ɹ�
*             BSP_ERR_SCI_INVALIDPARA
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32 DRV_PCSC_GET_BAUD_RATE(unsigned long * pLen, BSP_U8 * pBuf)
{
#if defined(INSTANCE_1)
    return (BSP_U32)I1_appl131_get_baud_rate((u32*)pLen, pBuf);
#else
    return (BSP_U32)appl131_get_baud_rate((u32*)pLen, pBuf);
#endif
}


/*****************************************************************************
* �� �� ��  : DRV_PCSC_GET_SCI_PARA
*
* ��������  : ���ӿ����ڻ�ȡ��ǰSIM����PCSC��ز���
*
* �������  : ��
*
* �������  : u8 *pBuf    PCSC��ز���
*
* �� �� ֵ  : OK    �����ɹ�
*             BSP_ERR_SCI_INVALIDPARA
* �޸ļ�¼  : Yangzhi create
*
*****************************************************************************/
BSP_U32 DRV_PCSC_GET_SCI_PARA(BSP_U8 * pBuf)
{

#if defined(INSTANCE_1)
    return (BSP_U32)I1_appl131_get_pcsc_paremeter(pBuf);
#else
    return (BSP_U32)appl131_get_pcsc_paremeter(pBuf);
#endif
}


/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_FUNC_REGISTER
*
* ��������  : ���ӿ�����ע��OAM  �ص�����
* �������  : void  
* �������  : ��
*
* �� �� ֵ  : OK  ��λ�ɹ�
*
* �޸ļ�¼  : 
*
*****************************************************************************/
void DRV_USIMMSCI_FUNC_REGISTER(OMSCIFUNCPTR omSciFuncPtr)
{
#if defined(INSTANCE_1)
    I1_bsp_sci_func_register(omSciFuncPtr);
#else
    bsp_sci_func_register(omSciFuncPtr);
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_RECORD_DATA_SAVE
*
* ��������  : ���ӿڿ�ά�ɲ���Ϣ��¼
* �������  : void  
* �������  : ��
*
* �� �� ֵ  : OK  �ɹ�
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_U32 DRV_USIMMSCI_RECORD_DATA_SAVE(SCI_LOG_MODE log_mode) 
{
#if defined(INSTANCE_1)
    return (BSP_U32)I1_bsp_sci_record_data_save(log_mode);
#else
    return (BSP_U32)bsp_sci_record_data_save(log_mode);
#endif
}


/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_SETBWT
*
* ��������  : ���ӿ��������ÿ�ȴ�ʱ��
*
* �������  : BSP_U32 nBWT :���ó�ʱʱ��ΪBWT��nBWT��
*
* �������  : ��
*
* �� �� ֵ  : OK/ERROR
* �޸ļ�¼  : 2013��10��15��   liuyi  creat
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_SETBWT(BSP_U32 nBWT)
{
#if defined(INSTANCE_1)
        return (BSP_S32)I1_bsp_sci_set_bwt(nBWT);
#else
        return (BSP_S32)bsp_sci_set_bwt(nBWT);
#endif
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_PROTOCOL_SWITCH
*
* ��������  : ���ӿ�����֪ͨ��������T=0��T=1Э�������л�
*
* �������  : RESET_MODE enSIMProtocolMode:��Ҫ�л�Ϊ��Э������
*
* �������  : ��
*
* �� �� ֵ  : OK/ERROR
* �޸ļ�¼  : 2013��10��15��   liuyi  creat
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_PROTOCOL_SWITCH(PROTOCOL_MODE enSIMProtocolMode)
{
#if defined(INSTANCE_1)
        return (BSP_S32)I1_bsp_sci_protocol_switch(enSIMProtocolMode);
#else
        return (BSP_S32)bsp_sci_protocol_switch(enSIMProtocolMode);
#endif

}

/*****************************************************************************
* �� �� ��  : BSP_SCI_BLK_Receive
* ��������  : ���ӿ�������T=1ʱUSIM Manager��ȡ����SCI Driver�Ŀ��������ݣ�
*             �������BWT��ʱ�������ݶ�ȡʱ����һ����ʱ��ֵSCI_TIMEOUT
*
* �������  : ��
* �������  : BSP_U8 *pu8Data USIM Managerָ����Buffer��SCI Driver�����ݿ�������Buffer��
              BSP_U32 *pulLength SCI Driver���յ������ݳ��ȡ�

* �� �� ֵ  : OK : 0
              ERROR : -1
              SCI_TIMEOUT : 1
*
* �޸ļ�¼  : 2013��10��15��   liuyi  creat
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_BLK_RCV(BSP_U8 *pu8Data,BSP_U32 *pulLength)
{
#if defined(INSTANCE_1)
    return (BSP_S32)I1_bsp_sci_blk_rcv(pu8Data, pulLength);
#else
    return (BSP_S32)bsp_sci_blk_rcv(pu8Data, pulLength);
#endif

}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_RECORDLOG_READ
*
* ��������  : ���ӿڻ�ȡsim���쳣ʱ��λ��Ϣ
* �������  : pucDataBuff: ��ȡ��λ��Ϣ��buffer
              ulMaxLength: ���ֵ���ж�ʹ��
*
* �� �� ֵ  : pulLength: ��ȡ���ݳ���
*
* �� �� ֵ  : ��
*
* �޸ļ�¼  : 

*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_S32  DRV_USIMMSCI_RECORDLOG_READ(BSP_U8 *pucDataBuff, BSP_U32 * pulLength, BSP_U32 ulMaxLength)
{
#if defined(INSTANCE_1)
        return I1_bsp_sci_record_log_read(pucDataBuff, pulLength, ulMaxLength);
#else
        return bsp_sci_record_log_read(pucDataBuff, pulLength, ulMaxLength);
#endif

}

/* T=1 add End */
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_GET_ERRNO
*
* ��������  : ���ӿڻ�ȡ�ӿڵ��÷��صĴ�����
* �������  :  ��
* �������  :  ��
*
* �� �� ֵ  : ������
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_S32 DRV_USIMMSCI_GET_ERRNO(BSP_VOID) 
{
	return BSP_OK;
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_POWER_ON
*
* ��������  : ���ӿڴ�SIM �������ѹ
* �������  : �� 
* �������  : ��
*
* �� �� ֵ  : ��
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_VOID DRV_USIMMSCI_POWER_ON(BSP_VOID) 
{
	return ;
}

/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_POWER_OFF
*
* ��������  : ���ӿڹر�SIM �������ѹ
* �������  : ��
* �������  : ��
*
* �� �� ֵ  : ��
*
* �޸ļ�¼  : 
*
*****************************************************************************/
BSP_VOID DRV_USIMMSCI_POWER_OFF(BSP_VOID) 
{
	return ;
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSCI_SLOT_SWITCH
*
* ��������  : ���ӿ�ʵ�ֿ����л�
* �������  : SCI_SLOT sci_slot0   ����0��Ӧ��SCI ID
                            SCI_SLOT sci_slot1   ����1��Ӧ��SCI ID
* �������  : ��
*
* �� �� ֵ  : �л�״̬
*
* �޸ļ�¼  : 
*
*****************************************************************************/

BSP_S32  DRV_USIMMSCI_SLOT_SWITCH(SCI_SLOT sci_slot0,SCI_SLOT sci_slot1)
{
#if defined(INSTANCE_1)
    return I1_bsp_sci_slot_switch( sci_slot0,  sci_slot1);
#else
    return bsp_sci_slot_switch( sci_slot0,  sci_slot1);
#endif
}
/*****************************************************************************
* �� �� ��  : DRV_USIMMSC_GET_SLOT_STATE
*
* ��������  : ���ӿڲ�ѯ��ǰ�Ŀ��۶�Ӧ��ϵ
* �������  : 
* �������  : SCI_SLOT* sci_slot0   ����0��Ӧ��SCI ID
                            SCI_SLOT* sci_slot1   ����1��Ӧ��SCI ID
*
* �� �� ֵ  : ��ѯ״̬
*
* �޸ļ�¼  : 
*
*****************************************************************************/

BSP_S32  DRV_USIMMSCI_GET_SLOT_STATE(SCI_SLOT* sci_slot0,SCI_SLOT* sci_slot1)
{
#if defined(INSTANCE_1)
    return I1_bsp_sci_get_slot_state(sci_slot0, sci_slot1);
#else
    return bsp_sci_get_slot_state(sci_slot0, sci_slot1);
#endif
}

