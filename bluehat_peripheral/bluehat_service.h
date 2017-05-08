#ifndef BLUEHAT_SERVICE_H__
#define BLUEHAT_SERVICE_H__

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"

#define BLE_UUID_BLUEHAT_BASE_UUID    {0x82, 0x49, 0x29, 0x15, 0x43, 0x1A, 0x4E, 0x6E, 0xA2, 0xD1, 0x06, 0x8F, 0x00, 0x00, 0x00, 0x00} // 128-bit base UUID
#define BLE_UUID_BLUEHAT_SERVICE        0x0726

/**
 * @brief This structure contains various status information for BlueHat service.
 * It only holds one entry now, but will be populated with more items as we go.
 * The name is based on the naming convention used in Nordic's SDKs.
 * 'ble’ indicates that it is a Bluetooth Low Energy relevant structure and
 * ‘bluehat’ is short for BlueHat Service).
 */
typedef struct
{
  uint16_t    service_handle;     /**< Handle of BlueHat Service (as provided by the BLE stack). */
} ble_bluehat_t;

/**@brief Function for initializing BlueHat new service.
 *
 * @param[in]   p_bluehat_service       Pointer to Bluehat Service structure.
 */
void bluehat_service_init(ble_bluehat_t * p_bluehat_service);

#endif  /* _ BLUEHAT_SERVICE_H__ */
