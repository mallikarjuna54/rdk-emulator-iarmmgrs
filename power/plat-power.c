#include <stdio.h>
#include <stdlib.h>
#include "plat_power.h"

static IARM_Bus_PWRMgr_PowerState_t power_state;

/**
 * @brief Initialize the underlying Power Management module.
 *
 * This function must initialize all aspects of the CPE's Power Management module.
 *
 * @param None.
 * @return    Return Code.
 * @retval    0 if successful.
 */
int PLAT_INIT(void)
{
    power_state = IARM_BUS_PWRMGR_POWERSTATE_ON;
    return 0;
}

/**
 * @brief Set the CPE Power State.
 *
 * This function sets the CPE's current power state to the specified state.
 *
 * @param [in]  newState    The power state to which to set the CPE.
 * @return    Return Code.
 * @retval    0 if successful.
 */
int PLAT_API_SetPowerState(IARM_Bus_PWRMgr_PowerState_t newState)
{
    /* TODO: Add standby mode */
    power_state = newState;
    return 0;
}

/**
 * @brief Get the CPE Power State.
 *
 * This function returns the current power state of the CPE.
 *
 * @param [in]  curState    The address of a location to hold the current power state of
 *                          the CPE on return.
 * @return    Return Code.
 * @retval    0 if successful.
 */
int PLAT_API_GetPowerState(IARM_Bus_PWRMgr_PowerState_t *curState)
{
    *curState = power_state;
    return 0;
}

/**
 * @brief Close the IR device module.
 *
 * This function must terminate the CPE Power Management module. It must reset any data
 * structures used within Power Management module and release any Power Management
 * specific handles and resources.
 *
 * @param None.
 * @return None.
 */
void PLAT_TERM(void)
{
    return;
}


void PLAT_Reset(IARM_Bus_PWRMgr_PowerState_t newState)
{
    system("reboot");
}

void PLAT_WHReset()
{
    return;
}

void PLAT_FactoryReset()
{
    return;
}

