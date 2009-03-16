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

/** \brief OpenSEK Posix Memory Mapping Header File
 **
 ** \file arm/MemMap_Arch.h
 **
 **/

/** \addtogroup OpenGEN
 ** @{ */
/** \addtogroup OpenGEN_Global
 ** \ingroup OpenGEN
 ** @{ */

/*
 * Initials	  Name
 * ---------------------------
 * MaCe			 Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * v0.1.0 20081116 MaCe	initial version
 */

/*==================[Start OpenSEK OS Mapping]===============================*/
#ifdef OpenSEK_START_SEC_CODE
	#define START_SECTION_CODE
	#undef OpenSEK_START_SEC_CODE
#endif

#ifdef OpenSEK_STOP_SEC_CODE
	#define STOP_SECTION_CODE
	#undef OpenSEK_STOP_SEC_CODE
#endif

#ifdef OpenSEK_START_SEC_DATA
	#define START_SECTION_DATA
	#undef OpenSEK_START_SEC_DATA
#endif

#ifdef OpenSEK_STOP_SEC_DATA
	#define STOP_SECTION_DATA
	#undef OpenSEK_STOP_SEC_DATA
#endif

/*==================[Stop OpenSEK OS Mapping]===============================*/

/*==================[Start TestSuite Mapping]===============================*/
#ifdef TestSuite_START_SEC_CODE
	#define START_SECTION_CODE
	#undef TestSuite_START_SEC_CODE
#endif

#ifdef TestSuite_STOP_SEC_CODE
   #define STOP_SECTION_CODE
   #undef TestSuite_STOP_SEC_CODE
#endif

#ifdef TestSuite_START_SEC_DATA
   #define START_SECTION_DATA
   #undef TestSuite_START_SEC_DATA
#endif

#ifdef TestSuite_STOP_SEC_DATA
   #define STOP_SECTION_DATA
   #undef TestSuite_STOP_SEC_DATA
#endif

/*==================[Stop TestSuite Mapping]=================================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
