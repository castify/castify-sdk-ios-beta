// Copyright © 2018 evaluni. All rights reserved.

#pragma once

#if !defined(__cplusplus) && __has_include(<Foundation/Foundation.h>)
#import <Foundation/Foundation.h>
#endif

#include <stdint.h>

#ifndef NS_ENUM
#define NS_ENUM(Int, Type) \
enum Type##_tag: Int Type; \
enum Type##_tag: Int
#endif

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef NS_ENUM(int32_t, CASState)
  {
    CASState_Closed,
    CASState_Opened,
    CASState_WIP,
  };
  
  typedef NS_ENUM(int32_t, CASError)
  {
    CASError_None,
    CASError_Unknown,
    CASError_Runtime,
    CASError_InvalidParameter,
    CASError_InvalidOperation,
    CASError_API,
  };
  
  void CASObject_Acquire(void *);
  void CASObject_Release(void *);
  
  typedef struct CASRuntime_tag * CASRuntime;
  
  CASRuntime CASRuntime_New(const char *token, const char *config);
  
  void CASDebug_SetJitterBufferDisabled(bool);
  bool CASDebug_GetJitterBufferDisabled();
  
  void   CASDebug_SetHLSBitrateLimit(double);
  double CASDebug_GetHLSBitrateLimit();

#ifdef __cplusplus
}
#endif