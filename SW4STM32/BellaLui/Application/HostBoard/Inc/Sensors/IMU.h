/*
 * IMU.h
 *
 *  Created on: 6 Dec 2020
 *      Author: Arion
 */

#ifndef APPLICATION_HOSTBOARD_INC_SENSORS_IMU_H_
#define APPLICATION_HOSTBOARD_INC_SENSORS_IMU_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <Sensors/BNO055/bno055.h>
#ifdef __cplusplus
}
#endif

#include <Sensors/I2CDriver.h>
#include <Sensors/Sensor.h>
#include <Sensors/DataStructures.h>



class IMU : public Sensor<IMUData> {
public:
	IMU(const char* identifier, I2CDriver* driver, uint8_t address, bool flip);

	bool load();
	bool unload();
	bool fetch(IMUData* data);

private:
	I2CDriver* driver;
	bno055_t dev;
	bool flip;

	uint8_t accel_data[BNO055_ACCEL_XYZ_DATA_SIZE];
	uint8_t gyro_data[BNO055_GYRO_XYZ_DATA_SIZE];
	uint8_t accel_counter = 0;
	uint8_t gyro_counter = 0;
};

#endif /* APPLICATION_HOSTBOARD_INC_SENSORS_IMU_H_ */
