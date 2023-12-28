/*
 * Std_Types.h
 *
 *  Created on: Nov 16, 2023
 *      Author: admin
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define STD_TYPES_VENDOR_ID                                  (1000U)

/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (3U)

typedef uint8 Std_Return_Type;

typedef struct
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;



#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */



#define E_OK            ((Std_Return_Type)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_Return_Type)0x01U)      /* Function Return NOT OK */

#endif /* STD_TYPES_H_ */
