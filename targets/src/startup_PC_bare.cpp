/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */

#include <stdint.h>
#include <PC_bare_rt0.h>

extern int main(void);

#if defined (__cplusplus)
extern "C" {
#endif

/* Linker symbols that are used to prepare the C/C++ environment */
extern uint32_t __bss_start;
extern uint32_t __bss_end;
extern void (*__preinit_array_start []) (void);
extern void (*__preinit_array_end []) (void);
extern void (*__init_array_start []) (void);
extern void (*__init_array_end []) (void);

void _start(void) __attribute__((noreturn));

#if defined (__cplusplus)
} // extern "C"
#endif

void _start(void) 
{
    uint32_t *dst;

    /* Clear the bss section*/
    dst = &__bss_start;
    while (dst < &_end_bss)
        *dst++ = 0;
        
    /* execute c++ constructors */
    auto preInitFunc = __preinit_array_start;
    while(preInitFunc < __preinit_array_end)
    {
        (*preInitFunc)();
        preInitFunc++;
    }
    auto initFunc = __init_array_start;
    while(initFunc < __init_array_end)
    {
        (*initFunc)();
        initFunc++;
    }

    int retval = main();
    
    /* todo desctructors! */

    _exit(retval);
}
