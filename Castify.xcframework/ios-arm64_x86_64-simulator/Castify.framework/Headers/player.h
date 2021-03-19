// Copyright © 2019 Castify Inc. All rights reserved.

#pragma once

#include "runtime.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct CASPlayer_tag * CASPlayer;
  
  typedef NS_ENUM(int32_t, CASPlayerEventType)
  {
    CASPlayerEventType_StateChange,
    CASPlayerEventType_Timer,
    CASPlayerEventType_Audio,
    CASPlayerEventType_Video,
    CASPlayerEventType_Index,
    CASPlayerEventType_Error,
    CASPlayerEventType_Release,
  };
  
  typedef struct {
    CASPlayerEventType type;
    union {
      void  **frame;
      struct {
        CASState state;
        CASError error;
      };
    };
    union {
      int64_t     time;
      const char *value;
    };
  } CASPlayerEvent;
  
  typedef struct
  {
    void *userData;
    void (*function)(void *userData, CASPlayerEvent);
  } CASPlayerCallback;
  
  CASPlayer CASPlayer_New(CASRuntime, CASPlayerCallback, const char *config);

  void CASPlayer_SetUrl(CASPlayer, const char *);

  void CASPlayer_SetPaused(CASPlayer, bool);
  bool CASPlayer_GetPaused(CASPlayer);
  
  void CASPlayer_Seek(CASPlayer, double time);
  
  void CASPlayer_SetMediaSelector(CASPlayer, const char *);

  void CASPlayer_SetAudioEnabled(CASPlayer, bool);
  void CASPlayer_SetVideoEnabled(CASPlayer, bool);
  
#ifdef __cplusplus
}
#endif
