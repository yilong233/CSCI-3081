#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include "../include/package.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class PackageTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
    std::vector<float> position_to_add={1,2,3};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add={1,0,0};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    package1 = new Package(obj);

  }
  Package* package1;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PackageTest, ConstructorTest) {
  EXPECT_FLOAT_EQ(package1 -> GetPosition()[0], 1);
  EXPECT_FLOAT_EQ(package1 -> GetPosition()[1], 2);
  EXPECT_FLOAT_EQ(package1 -> GetPosition()[2], 3);
	
  EXPECT_FLOAT_EQ(package1 -> GetDirection()[0], 1);
  EXPECT_FLOAT_EQ(package1 -> GetDirection()[1], 0);
  EXPECT_FLOAT_EQ(package1 -> GetDirection()[2], 0);

  EXPECT_FLOAT_EQ(package1 -> GetId(), 11);
   
  EXPECT_EQ(package1 -> GetName(), "package");

  EXPECT_FLOAT_EQ(package1 -> GetRadius(), 1);

  EXPECT_FLOAT_EQ(package1 -> GetVersion(), 0);

  EXPECT_FLOAT_EQ(package1 -> IsDynamic(), false);

}
TEST_F(PackageTest, WeightTest) {
  float w =1.0;
  package1 -> Setweight(w);
  EXPECT_FLOAT_EQ(package1 -> GetWeight(), 1);

	
}

}
