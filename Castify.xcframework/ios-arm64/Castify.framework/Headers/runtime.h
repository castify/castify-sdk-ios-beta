// Copyright © 2019 Castify Inc. All rights reserved.

#pragma once

#if !defined(__cplusplus) && __has_include(<Foundation/Foundation.h>)
#import <Foundation/Foundation.h>
#endif

#include <stdint.h>

#ifndef NS_ENUM
#ifdef __cplusplus
#define NS_ENUM(Int, Type) \
void Type##_; \
enum Type: Int
#else
#define NS_ENUM(Int, Type) \
enum Type##_tag: Int Type; \
enum Type##_tag: Int
#endif
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
    CASError_Unknown,
    CASError_Runtime,
    CASError_Validation,
    CASError_Defined,
    CASError_Webhook,
  };
  
  void CASObject_Acquire(void *);
  void CASObject_Release(void *);
  
  typedef struct CASRuntime_tag * CASRuntime;
  
  CASRuntime CASRuntime_New(const char *token, const char *config);
  
  void CASDebug_SetLoggingOption(const char *loggingOption);

#ifdef __cplusplus
}
#endif
