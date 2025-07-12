#include <fcitx/instance.h>
#include <fcitx-utils/log.h>
#include <fcitx/ime.h>
#include <fcitx-utils/utils.h>
#include <fcitx/hook.h>

static void *Fcitx4IMModuleCreate(FcitxInstance *instance);
static void Fcitx4IMModuleDestroy(void *arg);

static boolean Fcitx4IMModuleInit(void *arg);
static void Fcitx4IMModuleResetIM(void *arg);
static void Fcitx4IMModuleSave(void *arg);
static void Fcitx4IMModuleReloadConfig(void *arg);
static void Fcitx4IMModuleUpdateSurroundingText(void *arg);
static INPUT_RETURN_VALUE Fcitx4IMModuleGetCandWords(void *arg);
static void Fcitx4IMModuleOnClose(void *arg, FcitxIMCloseEventType et);
static void Fcitx4IMModuleOnChanged(void *arg);

static INPUT_RETURN_VALUE Fcitx4IMModuleDoInput(void *arg, FcitxKeySym sym, unsigned int state);
static INPUT_RETURN_VALUE Fcitx4IMModuleDoReleaseInput(void *arg, FcitxKeySym sym, unsigned int _state);

#ifdef __cplusplus
extern "C"
{
#endif
    FCITX_EXPORT_API FcitxIMClass ime = {Fcitx4IMModuleCreate, Fcitx4IMModuleDestroy};
    FCITX_EXPORT_API int ABI_VERSION = FCITX_ABI_VERSION;
#ifdef __cplusplus
}
#endif

typedef struct
{
    FcitxInstance *instance;
} Fcitx4Freewb;

void *Fcitx4IMModuleCreate(FcitxInstance *instance)
{
    FcitxLog(DEBUG, "func : %s, line : %d.", __FUNCTION__, __LINE__);
    Fcitx4Freewb *freewb = fcitx_utils_new(Fcitx4Freewb);

    FcitxIMEventHook imhook = {Fcitx4IMModuleOnChanged, freewb};
    FcitxInstanceRegisterIMChangedHook(instance, imhook);

    FcitxIMIFace iface;
    memset(&iface, 0, sizeof(FcitxIMIFace));

    iface.ResetIM = Fcitx4IMModuleResetIM;
    iface.DoInput = Fcitx4IMModuleDoInput;
    iface.GetCandWords = Fcitx4IMModuleGetCandWords;
    iface.PhraseTips = NULL;
    iface.Save = Fcitx4IMModuleSave;
    iface.Init = Fcitx4IMModuleInit;
    iface.ReloadConfig = Fcitx4IMModuleReloadConfig;
    iface.KeyBlocker = NULL;
    iface.UpdateSurroundingText = Fcitx4IMModuleUpdateSurroundingText;
    iface.DoReleaseInput = Fcitx4IMModuleDoReleaseInput;
    iface.OnClose = Fcitx4IMModuleOnClose;

    FcitxInstanceRegisterIMv2(instance,
                              freewb,
                              "freewb",
                              "极点五笔输入法跨平台版",
                              "freewb",
                              iface,
                              15,
                              "zh_CN");

    return freewb;
}

void Fcitx4IMModuleDestroy(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

void Fcitx4IMModuleResetIM(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

INPUT_RETURN_VALUE Fcitx4IMModuleGetCandWords(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
    return IRV_TO_PROCESS;
}

void Fcitx4IMModuleSave(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

boolean Fcitx4IMModuleInit(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
    return false;
}

void Fcitx4IMModuleReloadConfig(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

void Fcitx4IMModuleUpdateSurroundingText(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

INPUT_RETURN_VALUE Fcitx4IMModuleDoReleaseInput(void *arg, FcitxKeySym sym, unsigned int state)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p], sym : [%d], state : [%d].", __FUNCTION__, __LINE__, arg, sym, state);
    return IRV_TO_PROCESS;
}

INPUT_RETURN_VALUE Fcitx4IMModuleDoInput(void *arg, FcitxKeySym sym, unsigned int state)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p], sym : [%d], state : [%d].", __FUNCTION__, __LINE__, arg, sym, state);
    return IRV_TO_PROCESS;
}

void Fcitx4IMModuleOnClose(void *arg, FcitxIMCloseEventType et)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}

void Fcitx4IMModuleOnChanged(void *arg)
{
    FcitxLog(DEBUG, "func : [%s], line : [%d], arg : [%p].", __FUNCTION__, __LINE__, arg);
}
