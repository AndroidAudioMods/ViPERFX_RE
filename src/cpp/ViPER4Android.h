#pragma once

// Source: https://github.com/vipersaudio/viperfx_core_binary/blob/master/viperfx_intf.h
// Updated parameters source: https://github.com/vipersaudio/viper4android_fx/blob/master/android_4.x/src/com/vipercn/viper4android_v2/service/ViPER4AndroidService.java

extern "C" {
enum ParamsMode {
    COMMAND_CODE_GET = 0x01,
    COMMAND_CODE_SET,
};

enum ParamsGet {
    PARAM_GET_STATUS_BEGIN = 0x08000,
    PARAM_GET_DRIVER_VERSION,
    PARAM_GET_NEONENABLED,
    PARAM_GET_ENABLED,
    PARAM_GET_CONFIGURE,
    PARAM_GET_DRVCANWORK,
    PARAM_GET_STREAMING,
    PARAM_GET_EFFECT_TYPE,
    PARAM_GET_SAMPLINGRATE,
    PARAM_GET_CONVUSABLE,
    PARAM_GET_CONVKNLID,
    PARAM_GET_STATUS_END
};

enum ParamsSet {
    PARAM_SET_STATUS_BEGIN = 0x09000,
    PARAM_SET_UNKNOWN,
    PARAM_SET_UPDATE_STATUS,
    PARAM_SET_RESET_STATUS,
    PARAM_SET_DOPROCESS_STATUS,
    PARAM_SET_FORCEENABLE_STATUS,
    PARAM_SET_SELFDIAGNOSE_STATUS,
    PARAM_SET_STATUS_END
};

enum ParamsConfigure {
    PARAM_PROCESSUNIT_FX_BEGIN = 0x10000,

    PARAM_FX_TYPE_SWITCH,
    PARAM_HPFX_CONV_PROCESS_ENABLED,
    PARAM_HPFX_CONV_UPDATEKERNEL,
    /*****************************************/
    // Please use PARAM_HPFX_CONV_UPDATEKERNEL instead
    PARAM_HPFX_CONV_PREPAREBUFFER,
    PARAM_HPFX_CONV_SETBUFFER,
    PARAM_HPFX_CONV_COMMITBUFFER,
    /*****************************************/
    PARAM_HPFX_CONV_CROSSCHANNEL,
    PARAM_HPFX_VHE_PROCESS_ENABLED,
    PARAM_HPFX_VHE_EFFECT_LEVEL,
    PARAM_HPFX_VDDC_PROCESS_ENABLED,
    PARAM_HPFX_VDDC_COEFFS,
    PARAM_HPFX_VSE_PROCESS_ENABLED,
    PARAM_HPFX_VSE_REFERENCE_BARK,
    PARAM_HPFX_VSE_BARK_RECONSTRUCT,
    PARAM_HPFX_FIREQ_PROCESS_ENABLED,
    PARAM_HPFX_FIREQ_BANDLEVEL,
    PARAM_HPFX_COLM_PROCESS_ENABLED,
    PARAM_HPFX_COLM_WIDENING,
    PARAM_HPFX_COLM_MIDIMAGE,
    PARAM_HPFX_COLM_DEPTH,
    PARAM_HPFX_DIFFSURR_PROCESS_ENABLED,
    PARAM_HPFX_DIFFSURR_DELAYTIME,
    PARAM_HPFX_REVB_PROCESS_ENABLED,
    PARAM_HPFX_REVB_ROOMSIZE,
    PARAM_HPFX_REVB_WIDTH,
    PARAM_HPFX_REVB_DAMP,
    PARAM_HPFX_REVB_WET,
    PARAM_HPFX_REVB_DRY,
    PARAM_HPFX_AGC_PROCESS_ENABLED,
    PARAM_HPFX_AGC_RATIO,
    PARAM_HPFX_AGC_VOLUME,
    PARAM_HPFX_AGC_MAXSCALER,
    PARAM_HPFX_DYNSYS_PROCESS_ENABLED,
    PARAM_HPFX_DYNSYS_XCOEFFS,
    PARAM_HPFX_DYNSYS_YCOEFFS,
    PARAM_HPFX_DYNSYS_SIDEGAIN,
    PARAM_HPFX_DYNSYS_BASSGAIN,
    PARAM_HPFX_VIPERBASS_PROCESS_ENABLED,
    PARAM_HPFX_VIPERBASS_MODE,
    PARAM_HPFX_VIPERBASS_SPEAKER,
    PARAM_HPFX_VIPERBASS_BASSGAIN,
    PARAM_HPFX_VIPERCLARITY_PROCESS_ENABLED,
    PARAM_HPFX_VIPERCLARITY_MODE,
    PARAM_HPFX_VIPERCLARITY_CLARITY,
    PARAM_HPFX_CURE_PROCESS_ENABLED,
    PARAM_HPFX_CURE_CROSSFEED,
    PARAM_HPFX_TUBE_PROCESS_ENABLED,
    PARAM_HPFX_ANALOGX_PROCESS_ENABLED,
    PARAM_HPFX_ANALOGX_MODE,
    PARAM_HPFX_OUTPUT_VOLUME,
    PARAM_HPFX_OUTPUT_PAN,
    PARAM_HPFX_LIMITER_THRESHOLD,
    PARAM_SPKFX_CONV_PROCESS_ENABLED,
    PARAM_SPKFX_CONV_UPDATEKERNEL,
    PARAM_SPKFX_CONV_PREPAREBUFFER,
    PARAM_SPKFX_CONV_SETBUFFER,
    PARAM_SPKFX_CONV_COMMITBUFFER,
    PARAM_SPKFX_CONV_CROSSCHANNEL,
    PARAM_SPKFX_FIREQ_PROCESS_ENABLED,
    PARAM_SPKFX_FIREQ_BANDLEVEL,
    PARAM_SPKFX_REVB_PROCESS_ENABLED,
    PARAM_SPKFX_REVB_ROOMSIZE,
    PARAM_SPKFX_REVB_WIDTH,
    PARAM_SPKFX_REVB_DAMP,
    PARAM_SPKFX_REVB_WET,
    PARAM_SPKFX_REVB_DRY,
    PARAM_SPKFX_AGC_PROCESS_ENABLED,
    PARAM_SPKFX_AGC_RATIO,
    PARAM_SPKFX_AGC_VOLUME,
    PARAM_SPKFX_AGC_MAXSCALER,
    PARAM_SPKFX_OUTPUT_VOLUME,
    PARAM_SPKFX_LIMITER_THRESHOLD,
    PARAM_HPFX_FETCOMP_PROCESS_ENABLED,
    PARAM_HPFX_FETCOMP_THRESHOLD,
    PARAM_HPFX_FETCOMP_RATIO,
    PARAM_HPFX_FETCOMP_KNEEWIDTH,
    PARAM_HPFX_FETCOMP_AUTOKNEE_ENABLED,
    PARAM_HPFX_FETCOMP_GAIN,
    PARAM_HPFX_FETCOMP_AUTOGAIN_ENABLED,
    PARAM_HPFX_FETCOMP_ATTACK,
    PARAM_HPFX_FETCOMP_AUTOATTACK_ENABLED,
    PARAM_HPFX_FETCOMP_RELEASE,
    PARAM_HPFX_FETCOMP_AUTORELEASE_ENABLED,
    PARAM_HPFX_FETCOMP_META_KNEEMULTI,
    PARAM_HPFX_FETCOMP_META_MAXATTACK,
    PARAM_HPFX_FETCOMP_META_MAXRELEASE,
    PARAM_HPFX_FETCOMP_META_CREST,
    PARAM_HPFX_FETCOMP_META_ADAPT,
    PARAM_HPFX_FETCOMP_META_NOCLIP_ENABLED,
    PARAM_SPKFX_FETCOMP_PROCESS_ENABLED,
    PARAM_SPKFX_FETCOMP_THRESHOLD,
    PARAM_SPKFX_FETCOMP_RATIO,
    PARAM_SPKFX_FETCOMP_KNEEWIDTH,
    PARAM_SPKFX_FETCOMP_AUTOKNEE_ENABLED,
    PARAM_SPKFX_FETCOMP_GAIN,
    PARAM_SPKFX_FETCOMP_AUTOGAIN_ENABLED,
    PARAM_SPKFX_FETCOMP_ATTACK,
    PARAM_SPKFX_FETCOMP_AUTOATTACK_ENABLED,
    PARAM_SPKFX_FETCOMP_RELEASE,
    PARAM_SPKFX_FETCOMP_AUTORELEASE_ENABLED,
    PARAM_SPKFX_FETCOMP_META_KNEEMULTI,
    PARAM_SPKFX_FETCOMP_META_MAXATTACK,
    PARAM_SPKFX_FETCOMP_META_MAXRELEASE,
    PARAM_SPKFX_FETCOMP_META_CREST,
    PARAM_SPKFX_FETCOMP_META_ADAPT,
    PARAM_SPKFX_FETCOMP_META_NOCLIP_ENABLED,

    PARAM_PROCESSUNIT_FX_END
};

}
