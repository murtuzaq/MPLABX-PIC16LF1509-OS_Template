/* 
 * File:   projectOS.h
 * Author: mquaizar
 *
 * Created on December 8, 2016, 5:36 PM
 */

#ifndef PROJECTOS_H
#define	PROJECTOS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
void OS_AddThreads( void(*func1)(void), 
                        void(*func2)(void),
                        void(*func3)(void),
                        void(*func4)(void));

void OS_Launch(void);

void OS_Scheduler(void);

uint8_t OS_Wait(int8_t *semaPt);

void OS_Signal(int8_t *semaPt);


#ifdef	__cplusplus
}
#endif

#endif	/* PROJECTOS_H */

