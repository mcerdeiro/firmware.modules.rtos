/* Copyright 2008, 2009, Mariano Cerdeiro
 *
 * This file is part of OpenSEK.
 *
 * OpenSEK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking OpenSEK statically or dynamically with other modules is making a
 * combined work based on OpenSEK. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of OpenSEK give
 * you permission to combine OpenSEK program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with OpenSEK solely through the OpenSEK defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for OpenSEK and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of OpenSEK are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * OpenSEK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenSEK. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/** \brief OpenDRV DIO Init Arch implementation file
 **
 ** This file implements the Dio_Init_Arch API
 **
 ** \file Dio_Init_Arch.c
 **
 **/

/** \addtogroup OpenDRV
 ** @{ */
/** \addtogroup OpenDRV_Dio
 ** \ingroup OpenDRV
 ** @{ */
/** \addtogroup OpenDRV_Dio_Internal
 ** \ingroup OpenDRV_Dio
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090213 v0.1.1 MaCe raname Io driver to Dio
 * 20090125 v0.1.0 MaCe       - initial version
 */

/*==================[inclusions]=============================================*/
#include "Dio_Internal.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** TODO */
/* #define OpenDRV_DIO_START_SEC_CODE
 * #include "MemMap.h" */

Dio_ReturnType Dio_Init_Arch
(
	Dio_ConfigRefType config
)
{
	/* enable fast IO for port 0 and 1*/
	SCS |= 1<<0;

#if (DIO_PORT0_STATE == ENABLE)
	/* set the direction of the Dio pins of ports 0 */
	FIO0DIR = FIO0DIR & (~DIO_PORT0_MASK) | DIO_PORT0_DIR;
	/* set the correct mask for port 0 */
	FIO0MASK = FIO0MASK & (~DIO_PORT0_MASK);
	/* set init value for port 0 */
	FIO0PIN	= DIO_PORT0_INIT;
#endif
#if (DIO_PORT1_STATE == ENABLE)
	/* set the direction of the Dio pins of ports 1 */
	FIO1DIR = FIO1DIR & (~DIO_PORT1_MASK) | DIO_PORT0_DIR;
	/* set the correct mask for port 1 */
	FIO1MASK = FIO1MASK & (~DIO_PORT1_MASK);
	/* set init value for port 1 */
	FIO0PIN	= DIO_PORT1_INIT;
#endif
#if (DIO_PORT2_STATE == ENABLE)
	/* set the direction of the Dio pins of ports 2 */
	FIO2DIR = FIO2DIR & (~DIO_PORT2_MASK) | DIO_PORT0_DIR;
	/* set the correct mask for port 2 */
	FIO2MASK = FIO2MASK & (~DIO_PORT2_MASK);
	/* set init value for port 2 */
	FIO0PIN	= DIO_PORT2_INIT;
#endif
#if (DIO_PORT3_STATE == ENABLE)
	/* set the direction of the Dio pins of ports 3 */
	FIO3DIR = FIO3DIR & (~DIO_PORT3_MASK) | DIO_PORT0_DIR;
	/* set the correct mask for port 3 */
	FIO3MASK = FIO3MASK & (~DIO_PORT3_MASK);
	/* set init value for port 3 */
	FIO0PIN	= DIO_PORT3_INIT;
#endif
#if (DIO_PORT4_STATE == ENABLE)
	/* set the direction of the Dio pins of ports 4 */
	FIO4DIR = FIO4DIR & (~DIO_PORT4_MASK) | DIO_PORT0_DIR;
	/* set the correct mask for port 4 */
	FIO4MASK = FIO4MASK & (~DIO_PORT4_MASK);
	/* set init value for port 4 */
	FIO0PIN	= DIO_PORT4_INIT;
#endif

/** TODO this has to be removed */
/*	FIO4SET |= 1<<17; */
/*	FIO4SET |= 1<<16; */
/*	FIO4DIR |= 1<<17; */
/*	FIO4DIR |= 1<<16; */

}

/** TODO */
/* #define OpenDRV_DIO_STOP_SEC_CODE
 * #include "MemMap.h" */

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
