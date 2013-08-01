/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "ouyaFace.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*ouyaInit_t)(const char* pDeveloperId, const char* pApplicationKey);
typedef       void(*ouyaTerm_t)();
typedef       bool(*ouyaFacadeIsInitialised_t)();
typedef       bool(*ouyaFacadeIsRunningOnOUYAHardware_t)();
typedef       void(*ouyaFacadeGetGameData_t)(const char* pKey, char* pBuffer, int bufferSize);
typedef       void(*ouyaFacadePutGameData_t)(const char* pKey, const char* pValue);
typedef       void(*ouyaFacadeSetTestMode_t)();
typedef  s3eResult(*ouyaFacadeRequestGamerUUID_t)(s3eCallback pCallback, void* pUserData);
typedef  s3eResult(*ouyaFacadeRequestReceipts_t)(s3eCallback pCallback, void* pUserData);
typedef  s3eResult(*ouyaFacadeRequestProductList_t)(const char** parPurchasable, int numPurchasables, s3eCallback pCallback, void* pUserData);
typedef  s3eResult(*ouyaFacadeRequestPurchase_t)(const char* pPurchasable, s3eCallback pCallback, void* pUserData);
typedef  s3eResult(*ouyaControllerRegister_t)(OuyaControllerEvent type, s3eCallback pCallback, void* pUserData);
typedef  s3eResult(*ouyaControllerUnRegister_t)(OuyaControllerEvent type, s3eCallback pCallback);
typedef       bool(*ouyaControllerGetButtonState_t)(uint32 controller, uint32 button);
typedef      float(*ouyaControllerGetAxis_t)(uint32 controller, uint32 axis);

/**
 * struct that gets filled in by ouyaFaceRegister
 */
typedef struct ouyaFaceFuncs
{
    ouyaInit_t m_ouyaInit;
    ouyaTerm_t m_ouyaTerm;
    ouyaFacadeIsInitialised_t m_ouyaFacadeIsInitialised;
    ouyaFacadeIsRunningOnOUYAHardware_t m_ouyaFacadeIsRunningOnOUYAHardware;
    ouyaFacadeGetGameData_t m_ouyaFacadeGetGameData;
    ouyaFacadePutGameData_t m_ouyaFacadePutGameData;
    ouyaFacadeSetTestMode_t m_ouyaFacadeSetTestMode;
    ouyaFacadeRequestGamerUUID_t m_ouyaFacadeRequestGamerUUID;
    ouyaFacadeRequestReceipts_t m_ouyaFacadeRequestReceipts;
    ouyaFacadeRequestProductList_t m_ouyaFacadeRequestProductList;
    ouyaFacadeRequestPurchase_t m_ouyaFacadeRequestPurchase;
    ouyaControllerRegister_t m_ouyaControllerRegister;
    ouyaControllerUnRegister_t m_ouyaControllerUnRegister;
    ouyaControllerGetButtonState_t m_ouyaControllerGetButtonState;
    ouyaControllerGetAxis_t m_ouyaControllerGetAxis;
} ouyaFaceFuncs;

static ouyaFaceFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x3bf17132, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: ouyaFace");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x3bf17132, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool ouyaFaceAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void ouyaInit(const char* pDeveloperId, const char* pApplicationKey)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[0] func: ouyaInit"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ouyaInit(pDeveloperId, pApplicationKey);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void ouyaTerm()
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[1] func: ouyaTerm"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ouyaTerm();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

bool ouyaFacadeIsInitialised()
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[2] func: ouyaFacadeIsInitialised"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_ouyaFacadeIsInitialised();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool ouyaFacadeIsRunningOnOUYAHardware()
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[3] func: ouyaFacadeIsRunningOnOUYAHardware"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_ouyaFacadeIsRunningOnOUYAHardware();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void ouyaFacadeGetGameData(const char* pKey, char* pBuffer, int bufferSize)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[4] func: ouyaFacadeGetGameData"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ouyaFacadeGetGameData(pKey, pBuffer, bufferSize);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void ouyaFacadePutGameData(const char* pKey, const char* pValue)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[5] func: ouyaFacadePutGameData"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ouyaFacadePutGameData(pKey, pValue);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void ouyaFacadeSetTestMode()
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[6] func: ouyaFacadeSetTestMode"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_ouyaFacadeSetTestMode();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

s3eResult ouyaFacadeRequestGamerUUID(s3eCallback pCallback, void* pUserData)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[7] func: ouyaFacadeRequestGamerUUID"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaFacadeRequestGamerUUID(pCallback, pUserData);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult ouyaFacadeRequestReceipts(s3eCallback pCallback, void* pUserData)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[8] func: ouyaFacadeRequestReceipts"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaFacadeRequestReceipts(pCallback, pUserData);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult ouyaFacadeRequestProductList(const char** parPurchasable, int numPurchasables, s3eCallback pCallback, void* pUserData)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[9] func: ouyaFacadeRequestProductList"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaFacadeRequestProductList(parPurchasable, numPurchasables, pCallback, pUserData);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult ouyaFacadeRequestPurchase(const char* pPurchasable, s3eCallback pCallback, void* pUserData)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[10] func: ouyaFacadeRequestPurchase"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaFacadeRequestPurchase(pPurchasable, pCallback, pUserData);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult ouyaControllerRegister(OuyaControllerEvent type, s3eCallback pCallback, void* pUserData)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[11] func: ouyaControllerRegister"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaControllerRegister(type, pCallback, pUserData);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult ouyaControllerUnRegister(OuyaControllerEvent type, s3eCallback pCallback)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[12] func: ouyaControllerUnRegister"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_ouyaControllerUnRegister(type, pCallback);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool ouyaControllerGetButtonState(uint32 controller, uint32 button)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[13] func: ouyaControllerGetButtonState"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_ouyaControllerGetButtonState(controller, button);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float ouyaControllerGetAxis(uint32 controller, uint32 axis)
{
    IwTrace(OUYAFACE_VERBOSE, ("calling ouyaFace[14] func: ouyaControllerGetAxis"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_ouyaControllerGetAxis(controller, axis);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
