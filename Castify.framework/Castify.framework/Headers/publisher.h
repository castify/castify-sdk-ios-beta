// Copyright © 2019 Castify Inc. All rights reserved.

#pragma once

#include "runtime.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct CASAudioPublisher_tag * CASAudioPublisher;
  
  CASAudioPublisher CASAudioPublisher_New(CASRuntime);
  
  uint64_t CASAudioPublisher_GetID(CASAudioPublisher);
  void CASAudioPublisher_Append(CASAudioPublisher, void *);
  
  typedef struct CASVideoPublisher_tag * CASVideoPublisher;
  
  CASVideoPublisher CASVideoPublisher_New(CASRuntime);
  
  uint64_t CASVideoPublisher_GetID(CASVideoPublisher);
  void CASVideoPublisher_Append(CASVideoPublisher, void *);
  
#ifdef __cplusplus
}
#endif
