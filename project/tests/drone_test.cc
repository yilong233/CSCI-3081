#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include "../include/drone.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081 {

using entity_project::IEntity;

class DroneTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
    JsonHelper::AddStringToJsonObject(obj, "name", "drone");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
    JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
    std::vector<float> position_to_add={1,2,3};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add={1,0,0};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    drone1 = new Drone(obj);

  }
  Drone* drone1;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(DroneTest, ConstructorTest) {
  EXPECT_FLOAT_EQ(drone1 -> GetPosition()[0], 1);
  EXPECT_FLOAT_EQ(drone1 -> GetPosition()[1], 2);
  EXPECT_FLOAT_EQ(drone1 -> GetPosition()[2], 3);
	
  EXPECT_FLOAT_EQ(drone1 -> GetDirection()[0], 1);
  EXPECT_FLOAT_EQ(drone1 -> GetDirection()[1], 0);
  EXPECT_FLOAT_EQ(drone1 -> GetDirection()[2], 0);

  EXPECT_FLOAT_EQ(drone1 -> GetId(), 1);

  EXPECT_FLOAT_EQ(drone1 -> GetRadius(), 1);

  EXPECT_FLOAT_EQ(drone1 -> GetVersion(), 0);

  EXPECT_FLOAT_EQ(drone1 -> GetSpeed(), 30);

  EXPECT_FLOAT_EQ(drone1 -> IsDynamic(), false);

  EXPECT_FLOAT_EQ(drone1 -> IsSleep(), false);

}

TEST_F(DroneTest, GetSpeedTest) {
  EXPECT_FLOAT_EQ(drone1 -> GetSpeed(), 30);
}

TEST_F(DroneTest, SetSpeedTest) {

  drone1 -> SetSpeed(10);
  EXPECT_EQ(drone1 -> GetSpeed(),10);
}

TEST_F(DroneTest, HasPackageTest) {
  drone1 -> SetHasPackage(true);
  EXPECT_EQ(drone1 -> IfHasPackage(), true);
}


}  // namespace csci3081
