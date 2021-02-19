/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <PC_bare_syscall.h>
#include <MinUnit.h>

extern void (*__preinit_array_start []) (void);
extern void (*__preinit_array_end []) (void);
extern void (*__init_array_start []) (void);
extern void (*__init_array_end []) (void);

int sysWrite( int f, const char* d, int l )
{
   int ret = syscall3( SYS_write, f, ( long )( d ), l );

   return( ret );
}

int str_len( const char *string )
{
   int length = 0;
   while( *string ) { string++; length++; }
   return( length );
}

void println( const char* string )
{
   sysWrite( 1, string, str_len( string ) );
   sysWrite( 1, "\n", 1 );
}

void print( const char* string )
{
   sysWrite( 1, string, str_len( string ) );
}

/** \brief overridden reporting function
 * 
 * Executes the minunit test framework and checks the results
 */
void minunitReport(const char * message)
{
    print(message);
}

//int main(int argc, char *argv[]) {
int main() 
{   
    /* execute constructors */
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
    minunitRun();
    // print something if we have a failure
    if(minunitTestState.failures != 0)
    {
        println("Test failures occured!");
        return -1;
    }
    else
    {
        println("All tests passed.");
        return 0;
    }
}
