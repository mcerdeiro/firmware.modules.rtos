/* Copyright 2008, Mariano Cerdeiro
 *
 * This file is part of OpenSEK.
 *
 * OpenSEK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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

#ifndef _DIO_H_
#define _DIO_H_
/** \brief OpenDRV DIO Header File
 **
 ** This file shall be included by all files using any OpenDRV DIO API.
 **
 ** \file Dio.h
 **
 **/

/** \addtogroup OpenDRV
 ** @{ */
/** \addtogroup OpenDRV_Dio
 ** \ingroup OpenDRV
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe			 Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090213 v0.1.1 MaCe raname Io driver to Dio
 * 20090125 v0.1.0 MaCe	initial version
 */  

/*==================[inclusions]=============================================*/
#include "Types.h"
#include "Dio_Cfg.h"
#include "Dio_Arch.h"

/*==================[macros]=================================================*/
/** \brief IO driver set port service
 **
 ** This IO driver service shall be called to set a port to a specified value.
 ** The bits not configured of this port will stay unchaged. Writing to an
 ** input is not defined.
 **
 ** \param[in] port indicates the port to be set
 ** \param[in] value indicate the value to be set to this port
 ** \return IO_E_OK is always returned
 **/
#define /* Io_ReturnType */ Io_SetPort( /* Io_PortType */ port, /* Io_PortLevelType */ value) 				\
	IO_E_OK;											\
	{													\
		Io_SetPort_Arch(port, value, mask);	\
	}

/** \brief IO driver set pin service
 **
 ** This IO driver service shall be called to set a pint to a specific value.
 **
 ** \param[in] pin indicates the pin to be set
 ** \param[in] value indicates the value to be set to this pin
 ** \return IO_E_OK is always returned
 **/
#define /* Io_ReturnType */ Io_SetPin( /* Io_PinType */ pin, /* Io_PinLevelType */ value)					\
	IO_E_OK;											\
	{													\
		Io_SetPort_Arch(port, value);			\
	}

/** \brief IO driver get port service
 **
 ** This IO driver service shall be called to get the status of a specific port.
 **
 ** \param[in] port inidcates the port to be readed
 ** \param[out] value the value of the readed port is set to this variable
 ** \return IO_E_OK is always returned
 **/
#define /* Io_PortValueType */ Io_GetPort( /* Io_PortType */ port, /* Io_PortValueType */ value)				\
	IO_E_OK;											\
	{													\
		Io_GetPort_Arch(port, value);			\
	}

#if (DioDevErrorDetect == DISABLE)
/** \brief Dio Driver Read Channel service 
 **
 ** This Dio driver service shall used to read the state of a specific
 ** channel. This service is implemented as function if DioDevErrorDetect is
 ** ENABLE and as macro if DioDevErrorDetect is DISABLE
 **
 ** \param[in] ChannelId IO of DIO Channel
 ** \return Dio_LevelType DIO_HIGH the physical level of the corresponding Pin is high
 **							  DIO_LOW the physical level of the corresponding Pin is low
 **/
#define /* Dio_LevelType */ Dio_ReadChannel( /* Dio_ChannelType */ ChannelId) \
	Dio_ReadChannel_Arch(ChannelId)

/** \brief Dio Driver Write Channel service 
 **
 ** This Dio driver service shall used to write the state of a specific
 ** channel. This service is implemented as function if DioDevErrorDetect is
 ** ENABLE and as macro if DioDevErrorDetect is DISABLE
 **
 ** \param[in] ChannelId IO of DIO Channel
 ** \param[in] Level Level
 ** \return None
 **/
#define /* void */ Dio_WriteChannel( /* Dio_ChannelType */ ChannelId, /* Dio_LevelType */ Level)	\
	Dio_WriteChannel_Arch(ChannelId, Level)

#endif /* #if (DioDevErrorDetect == DISABLE) */

/** \brief High state */
/* \req DIO089-1/2 Values used by the DIO Driver for the software level of
 *	Channels are either STD_HIGH or STD_LOW. */
/* \dev DIO089-1/2 the high state is called DIO_HIGH and not STD_HIGH */
#define DIO_HIGH	1

/** \brief Low state */
/* \req DIO089-2/2 Values used by the DIO Driver for the software level of
 * Channels are either STD_HIGH or STD_LOW. */
/* \dev DIO089-2/2 the low state is called DIO_LOW and not STD_LOW */
#define DIO_LOW	0

/** \brief Dio Invalid Channel Id error code */
/* \req DIO065-1/3 The Dio module shall detect the following errors and
 * exceptions depending on its build version (development/production mode):
 * DIO_E_PARAM_INVALID_CHANNEL_ID, DIO_E_PARAM_INVALID_PORT_ID and
 * DIO_E_PARAM_INVALID_GROUP_ID
 */
#define DIO_E_PARAM_INVALID_CHANNEL_ID				10

/** \brief Dio Invalid Port Id error code */
/* \req DIO065-2/3 The Dio module shall detect the following errors and
 * exceptions depending on its build version (development/production mode):
 * DIO_E_PARAM_INVALID_CHANNEL_ID, DIO_E_PARAM_INVALID_PORT_ID and
 * DIO_E_PARAM_INVALID_GROUP_ID
 */
#define DIO_E_PARAM_INVALID_PORT_ID					20

/** \brief Dio Invalid Group Id error code */
/* \req DIO065-3/3 The Dio module shall detect the following errors and
 * exceptions depending on its build version (development/production mode):
 * DIO_E_PARAM_INVALID_CHANNEL_ID, DIO_E_PARAM_INVALID_PORT_ID and
 * DIO_E_PARAM_INVALID_GROUP_ID
 */
#define DIO_E_PARAM_INVALID_GROUP_ID				31
		
/*==================[typedef]================================================*/
/** \brief IO driver return type definition */
typedef uint8f Io_ReturnType;

/** \brief IO driver configuration type definition */
typedef struct {
   Io_ConfigArchType Io_Arch;
} Io_ConfigType;

/** \brief IO driver configuration reference type definition */
typedef Io_ConfigType* Io_ConfigRefType;

/** \brief IO driver port value type definition */
#if   (IO_PORT_BITS_WIDTH == 8)
typedef uint8 Io_PortValue;
#elif (IO_PORT_BITS_WIDTH == 16)
typedef uint16 Io_PortValue;
#elif (IO_PORT_BITS_WIDHT == 32)
typedef uint32 Io_PortValue;
#else
#error invalid IO_PORT_BITS_WIDHT value
#endif

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
/** \brief IO driver init service
 **
 ** This IO driver service shall be called to initialize the IO driver. Calls
 ** to any other IO driver service before initialization is not allowed.
 **
 ** \param[in] config pointer to the IO driver configuration
 ** \return IO_E_OK	if no error occurs
 ** \return IO_E_PARAM if the configuration is invalid
 ** \return IO_E_NOTOK if other error occurs
 **/
extern Io_ReturnType Io_Init(const Io_ConfigRefType config);

/** \brief IO driver re init service
 **
 ** This IO driver service shall be called to re initialize the IO driver.
 ** This services allows the user to change the port configuration on the go.
 **
 ** \param[in] config pointer to the new IO driver configuration
 ** \return IO_E_OK if no error occurs
 ** \return IO_E_PARAM if the configuration is invalid
 ** \return IO_E_NOTOK if other error occurs
 **/
extern Io_ReturnType Io_ReInit(const Io_ConfigRefType config);

/** \brief IO driver de-init service
 **
 ** This IO driver service shall be called to de-initialize the IO driver.
 **
 ** \return IO_E_OK if no error occurs
 ** \return IO_E_NOTOK if any error occurs
 **/
extern Io_ReturnType Io_ReInit();

/** \brief IO set port group
 **
 ** This function set a port group.
 **
 ** \param[in] portgroup port group to be set
 ** \param[in] value value to set the port group
 ** \return IO_E_OK always
 **/
extern Io_ReturnType Io_SetPortGroup(Io_PortGroupType portgroup, Io_PortGroupValueType value);

/** \brief IO set port group
 **
 ** This function get the values of a port group.
 **
 ** \param[in] portgroup port group to be readed
 ** \param[out] value reference to get the value
 ** \return IO_E_OK always
 **/
extern Io_ReturnType Io_GetPortGroup(Io_PortGroupType portgroup, Io_PortGroupValueRefType value);

#if (DioDevErrorDetect == ENABLE)
/** \brief Dio Driver Read Channel service 
 **
 ** This Dio driver service shall used to read the state of a specific
 ** channel. This service is implemented as function if DioDevErrorDetect is
 ** ENABLE and as macro if DioDevErrorDetect is DISABLE
 **
 ** \param[in] ChannelId IO of DIO Channel
 ** \return Dio_LevelType DIO_HIGH the physical level of the corresponding Pin is high
 **							  DIO_LOW the physical level of the corresponding Pin is low
 **/
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/** \brief Dio Driver Write Channel service 
 **
 ** This Dio driver service shall used to write the state of a specific
 ** channel. This service is implemented as function if DioDevErrorDetect is
 ** ENABLE and as macro if DioDevErrorDetect is DISABLE
 **
 ** \param[in] ChannelId IO of DIO Channel
 ** \param[in] Level Level
 ** \return None
 **/
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);


#endif /* #if (DioDevErrorDetect == ENABLE) */

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _DIO_H_ */

