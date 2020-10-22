// Copyright © 2019 Castify Inc. All rights reserved.

#pragma once

#include "runtime.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct CASBroadcaster_tag * CASBroadcaster;
  
  typedef NS_ENUM(int32_t, CASBroadcasterEventType)
  {
    CASBroadcasterEventType_StateChange,
    CASBroadcasterEventType_Start,
    CASBroadcasterEventType_Audio,
    CASBroadcasterEventType_Video,
    CASBroadcasterEventType_Index,
    CASBroadcasterEventType_Error,
    CASBroadcasterEventType_Release,
  };
  
  typedef struct {
    CASBroadcasterEventType type;
    union {
      void  **frame;
      CASState state;
    };
    const char *value;
  } CASBroadcasterEvent;
  
  typedef struct
  {
    void *userData;
    void (*function)(void *userData, CASBroadcasterEvent);
  } CASBroadcasterCallback;
  
  CASBroadcaster CASBroadcaster_New(CASRuntime, CASBroadcasterCallback, const char *customData);
  
  void CASBroadcaster_SetAudioEncoderSetting(CASBroadcaster, const char *);
  void CASBroadcaster_SetVideoEncoderSetting(CASBroadcaster, const char *);
  void CASBroadcaster_SetAudioSource(CASBroadcaster, const char *);
  void CASBroadcaster_SetVideoSource(CASBroadcaster, const char *);
  void CASBroadcaster_Start(CASBroadcaster, const char *);
  void CASBroadcaster_Close(CASBroadcaster);
  void CASBroadcaster_Resume(CASBroadcaster, const char *broadcastId, const char *token);
  
#ifdef __cplusplus
}
#endif
