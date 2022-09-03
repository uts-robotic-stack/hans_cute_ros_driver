#ifndef _JOINT_POSITION_CONTROLLER_H_
#define _JOINT_POSITION_CONTROLLER_H_

#include "controller.h"

#include "serial_command_robot/serial_command_robot_interface.h"

namespace HansCuteController
{
  class JointPositionController : public Controller
  {
  public:
    JointPositionController(const std::shared_ptr<SerialCommandRobotInterface> &robot_driver_ptr,
                            const std::string &controller_namespace, const std::string &port_namespace);
    ~JointPositionController();

    void initialise();
    void start();
    void stop();

    void processCommand(Data &data);

    // Getters
    void getJointPositions();
    void getJointVelocites();

  private:
    std::vector<HansCuteRobot::ServoModel> servos_model_;

    // void posRadToRaw(const double &rad, unsigned int &raw, const ServoParams &params);
  };
};

#endif