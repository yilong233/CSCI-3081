#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include "../include/robot.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <string>
#include <iostream>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class RobotTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "robot");
    JsonHelper::AddStringToJsonObject(obj, "name", "robot");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
    JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
    std::vector<float> position_to_add={1,2,3};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add={1,0,0};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    robot1 = new Robot(obj);

  }
  Robot* robot1;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RobotTest, PosTest) {
  EXPECT_FLOAT_EQ(robot1 -> GetPosition()[0], 1);
  EXPECT_FLOAT_EQ(robot1 -> GetPosition()[1], 2);
  EXPECT_FLOAT_EQ(robot1 -> GetPosition()[2], 3);

}

TEST_F(RobotTest, DirTest) {
  EXPECT_FLOAT_EQ(robot1 -> GetDirection()[0], 1);
  EXPECT_FLOAT_EQ(robot1 -> GetDirection()[1], 0);
  EXPECT_FLOAT_EQ(robot1 -> GetDirection()[2], 0);
}

TEST_F(RobotTest, GetSpeedTest) {
  EXPECT_FLOAT_EQ(robot1 -> GetSpeed(), 30);
}

TEST_F(RobotTest, SetSpeedTest) {
  robot1 -> SetSpeed(10);
  EXPECT_EQ(robot1 -> GetSpeed(),10);
}

TEST_F(RobotTest, HasPackagerTest) {
  robot1 -> SetHasPackager(true);
  EXPECT_EQ(robot1 -> IfHasPackage(), true);
}

}  // namespace csci3081