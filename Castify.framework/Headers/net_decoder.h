// Copyright © 2018 evaluni. All rights reserved.

#pragma once

#include "runtime.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct CASNetDecoder_tag * CASNetDecoder;
  
  typedef NS_ENUM(int32_t, CASNetDecoderEventType)
  {
    CASNetDecoderEventType_StateChange,
    CASNetDecoderEventType_Audio,
    CASNetDecoderEventType_Video,
    CASNetDecoderEventType_Error,
    CASNetDecoderEventType_Release,
  };
  
  typedef struct {
    CASNetDecoderEventType type;
    union {
      void  **frame;
      struct {
        CASState state;
        CASError error;
      };
    };
    const char *value;
  } CASNetDecoderEvent;
  
  typedef struct
  {
    void *userData;
    void (*function)(void *userData, CASNetDecoderEvent);
  } CASNetDecoderCallback;
  
  CASNetDecoder CASNetDecoder_New(CASRuntime, CASNetDecoderCallback
                                  , const char *playbackKey
                                  , const char *customData);
  
  void CASNetDecoder_Play(CASNetDecoder, const char *broadcastId, double time);
  void CASNetDecoder_Stop(CASNetDecoder);
  
  void CASNetDecoder_SetAudioEnabled(CASNetDecoder, bool);
  void CASNetDecoder_SetVideoEnabled(CASNetDecoder, bool);
  
#ifdef __cplusplus
}
#endif
