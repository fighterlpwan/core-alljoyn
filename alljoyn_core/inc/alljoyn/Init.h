/**
 * @file
 * Functions required to startup and cleanup AllJoyn.
 */

/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/
#ifndef _ALLJOYN_INIT_H
#define _ALLJOYN_INIT_H

#include <qcc/platform.h>
#include <alljoyn/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This must be called prior to instantiating or using any AllJoyn
 * functionality.
 *
 * This function is not thread-safe.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL AllJoynInit(void);

/**
 * Call this to release any resources acquired in AllJoynInit().  No AllJoyn
 * functionality may be used after calling this.
 *
 * This function is not thread-safe.
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL AllJoynShutdown(void);

/**
 * This must be called before using any AllJoyn router functionality.
 *
 * For an application that is a routing node (either standalone or bundled), the
 * complete initialization sequence is:
 * @code
 * AllJoynInit();
 * AllJoynRouterInit();
 * @endcode
 *
 * This function is not thread-safe.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL AllJoynRouterInit(void);

/**
 * Call this to release any resources acquired in AllJoynRouterInit().
 *
 * For an application that is a routing node (either standalone or bundled), the
 * complete shutdown sequence is:
 * @code
 * AllJoynRouterShutdown();
 * AllJoynShutdown();
 * @endcode
 *
 * This function is not thread-safe.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL AllJoynRouterShutdown(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
