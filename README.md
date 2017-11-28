# stellarium-oculus
Currently, you can manipulate the field of view in Stellarium using an Arduino-based IMU. The code for the Arduino is src/Arduino/imu.ino, and it should work as is with the MPU9255 via the I2C interface (other MPU devices could be used by changing the device ID and register addresses, though I think these might be the same for others like the MPU6050).
