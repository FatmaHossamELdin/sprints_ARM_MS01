#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_


/*
*	please choose form the followings
*	NVIC_GROUPING_SYSTEM_XXX : [0-7] Groups, [0]subgroups
*	NVIC_GROUPING_SYSTEM_XXY : [0-3] Groups, [0-1]subgroups
*	NVIC_GROUPING_SYSTEM_XYY : [0-1] Groups, [0-3]subgroups
*	NVIC_GROUPING_SYSTEM_XYY : [0] Groups,	 [0-7]subgroups Non-Preemtion system

*/

#define NVIC_GROUPING_SYSTEM   NVIC_GROUPING_SYSTEM_XXX


#define NVIC_ACTIVATED_INT_SIZE  3

#endif
