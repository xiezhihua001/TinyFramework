/*
 * TF.h
 *
 *  Created on: Nov 23, 2014
 *      Author: tov
 */

#ifndef TF_H_
#define TF_H_

// Include configuration of top project
#include "TF_Config.h"  // Remember to place a config file in your project directory.

// Configure OS
#ifdef __ZEPHYR__
#define _TF_OS_ZEPHYR_
#include <zephyr.h>
// __linux__ may be included when compiling zephyr as posix! Hence "#elif"...
#elif __linux__
#define _TF_OS_LINUX_
#define _TF_HAL_LINUX_
#endif

#ifdef _TF_OS_FREERTOS_
#include "FreeRTOS.h"
#endif


// Use std types throughout...
#include <stdint.h>
#include <stddef.h>

// Configure default Log output
#ifndef _TF_LOG_FILE_
#ifdef _TF_OS_ZEPHYR_
#define _TF_LOG_FILE_ stdout
#else
#define _TF_LOG_FILE_ stderr
#endif
#endif


namespace TF {

} /* namespace TF */

#endif /* TF_H_ */
