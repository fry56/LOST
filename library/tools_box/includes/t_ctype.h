/*
** EPITECH PROJECT, 2022
** tctype.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TCTYPE_H
    #define TOOLS_BOX_TCTYPE_H
    #include <stdio.h>

    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef signed long long int int128_t;

    #ifndef _INT64_T
        #define _INT64_T
        typedef signed long int int64_t;
    #endif
    #ifndef _UINT64_T
        #define _UINT64_T
        typedef unsigned long long uint64_t;
    #endif

    typedef uint8_t u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
    typedef unsigned long ulong;
    typedef unsigned long long ullong;

    typedef unsigned long tsize_t;

    #ifndef NULL
        #define NULL (0)
    #endif

    #ifndef bool
        #define bool    _Bool
        #define true    (1)
        #define false   (0)
    #endif

    #define UNUSED __attribute__((unused))

#endif //TOOLS_BOX_TCTYPE_H
