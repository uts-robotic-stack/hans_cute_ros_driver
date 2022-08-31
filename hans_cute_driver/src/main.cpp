#include <iostream>

#include "hans_cute_driver/hans_cute_driver.h"
#include "hans_cute_driver/hans_cute_datatype.h"

#include "custom_serial_port/custom_serial_port.h"
#include "custom_serial_port/serial_port_interface.h"

int main(int argc, char *argv[])
{
  std::shared_ptr<SerialPortInterface> serial_port = std::make_shared<SerialPort>("/dev/ttyUSB0", 250000, 50);
  HansCuteRobot::ServoDriver hans_robot;
  hans_robot.setSerialPort(serial_port);
  hans_robot.open();

  std::vector<unsigned int> servo_ids;
  // std::vector<unsigned int> positions;
  // std::vector<unsigned int> speeds;

  for (int i = 0; i <= 6; i++)
  {
    servo_ids.push_back(i);
    hans_robot.setTorqueEnable(i, true);
    hans_robot.setAcceleration(i, 20);
    hans_robot.setSpeed(i,300);

    unsigned int position = 0;
    hans_robot.getPosition(i, position);
    hans_robot.setPosition(i, position);
    hans_robot.setPosition(i, 2048);
  }

  // std::this_thread::sleep_for(std::chrono::milliseconds((2500)));
  // // hans_robot.setMultiSpeed(servo_ids,speeds);
  // hans_robot.setPosition(5, 3000);
  // hans_robot.setAcceleration(5, 20);
  // hans_robot.setSpeed(5,300);

  // std::this_thread::sleep_for(std::chrono::milliseconds((2500)));
  // hans_robot.setMultiSpeed(servo_ids,speeds);
  // hans_robot.setPosition(5, 900);

  hans_robot.close();
  return 0;
}