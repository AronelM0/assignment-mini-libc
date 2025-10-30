/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef _STDINT_H
#define _STDINT_H    1

/* Define types like uint32_t, int64_t, etc. */
/* These assume a standard LP64 model (Linux x86_64) */

/* Unsigned types */
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long       uint64_t;

/* Signed types */
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef signed long         int64_t;

/* Optional: Define pointer types if needed */
typedef uint64_t            uintptr_t;
typedef int64_t             intptr_t;

#endif /* _STDINT_H */
