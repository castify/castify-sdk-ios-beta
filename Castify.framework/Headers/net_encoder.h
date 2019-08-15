// Copyright © 2018 evaluni. All rights reserved.

#pragma once

#include "runtime.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct CASNetEncoder_tag * CASNetEncoder;
  
  typedef NS_ENUM(int32_t, CASNetEncoderEventType)
  {
    CASNetEncoderEventType_StateChange,
    CASNetEncoderEventType_Start,
    CASNetEncoderEventType_Audio,
    CASNetEncoderEventType_Video,
    CASNetEncoderEventType_Error,
    CASNetEncoderEventType_Release,
  };
  
  typedef struct {
    CASNetEncoderEventType type;
    union {
      void  **frame;
      CASState state;
    };
    const char *value;
  } CASNetEncoderEvent;
  
  typedef struct
  {
    void *userData;
    void (*function)(void *userData, CASNetEncoderEvent);
  } CASNetEncoderCallback;
  
  CASNetEncoder CASNetEncoder_New(CASRuntime, CASNetEncoderCallback, const char *customData);
  
  void CASNetEncoder_SetAudioEncoderSetting(CASNetEncoder, const char *);
  void CASNetEncoder_SetVideoEncoderSetting(CASNetEncoder, const char *);
  void CASNetEncoder_SetAudioSource(CASNetEncoder, const char *);
  void CASNetEncoder_SetVideoSource(CASNetEncoder, const char *);
  void CASNetEncoder_Start(CASNetEncoder);
  void CASNetEncoder_Close(CASNetEncoder);
  
#ifdef __cplusplus
}
#endif
