#include <stdint.h>
#include <string.h>
#include "bluehat_service.h"
#include "ble_srv_common.h"
#include "app_error.h"
#include "SEGGER_RTT.h"

/**@brief Function for initiating BlueHat new service.
 *
 * @param[in]   p_bluehat_service        BlueHat Service structure.
 *
 */
void bluehat_service_init(ble_bluehat_t * p_bluehat_service)
{
  uint32_t          err_code;
  ble_uuid_t        service_uuid;
  ble_uuid128_t     base_uuid = {BLE_UUID_BLUEHAT_BASE_UUID};
  service_uuid.uuid = BLE_UUID_BLUEHAT_SERVICE;
  
  err_code = sd_ble_uuid_vs_add(&base_uuid, &service_uuid.type);
  APP_ERROR_CHECK(err_code);

  err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY,
                                      &service_uuid,
                                      &p_bluehat_service->service_handle);
  APP_ERROR_CHECK(err_code);
}
