#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include "../include/customer.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class CustomerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "customer");
    JsonHelper::AddStringToJsonObject(obj, "name", "customer");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
    std::vector<float> position_to_add={1,2,3};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add={1,0,0};
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    customer1 = new Customer(obj);

  }
  Customer* customer1;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(CustomerTest, ConstructorTest) {
  EXPECT_FLOAT_EQ(customer1 -> GetPosition()[0], 1);
  EXPECT_FLOAT_EQ(customer1 -> GetPosition()[1], 2);
  EXPECT_FLOAT_EQ(customer1 -> GetPosition()[2], 3);
	
  EXPECT_FLOAT_EQ(customer1 -> GetDirection()[0], 1);
  EXPECT_FLOAT_EQ(customer1 -> GetDirection()[1], 0);
  EXPECT_FLOAT_EQ(customer1 -> GetDirection()[2], 0);

  EXPECT_FLOAT_EQ(customer1 -> GetId(), 0);
   
  EXPECT_EQ(customer1 -> GetName(), "customer");

  EXPECT_FLOAT_EQ(customer1 -> GetRadius(), 1);

  EXPECT_FLOAT_EQ(customer1 -> GetVersion(), 0);

  EXPECT_FLOAT_EQ(customer1 -> IsDynamic(), false);

}

}
