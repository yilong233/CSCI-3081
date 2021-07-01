#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class FactoryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryTest, DroneCreated) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "drone");
  JsonHelper::AddStringToJsonObject(obj, "name", "drone");
  JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
  JsonHelper::AddFloatToJsonObject(obj, "speed", 30);  
  std::vector<float> position_to_add;
  position_to_add.push_back(498.292);
  position_to_add.push_back(253.883);
  position_to_add.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
  std::vector<float> direction_to_add;
  direction_to_add.push_back(1);
  direction_to_add.push_back(0);
  direction_to_add.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
  IEntity* entity = system->CreateEntity(obj);
  
  
  ///
	picojson::object obj2 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj2, "type", "customer");
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add);
	JsonHelper::AddStringToJsonObject(obj2, "name", "customer");
  JsonHelper::AddFloatToJsonObject(obj2, "radius", 1);
  IEntity* entity2 = system->CreateEntity(obj2);
  
  
  picojson::object obj3 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj3, "type", "package");
	JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add);
	JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add);
	JsonHelper::AddStringToJsonObject(obj3, "name", "package");
  JsonHelper::AddFloatToJsonObject(obj3, "radius", 1);
  IEntity* entity3 = system->CreateEntity(obj3);
	///

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  
  system->AddEntity(entity2);
  system->AddEntity(entity3);
  
  ASSERT_EQ(3, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());
	ASSERT_EQ(picojson::value(system->GetEntities()[1]->GetDetails()).serialize(), picojson::value(obj2).serialize());
	ASSERT_EQ(picojson::value(system->GetEntities()[2]->GetDetails()).serialize(), picojson::value(obj3).serialize());
}

TEST_F(FactoryTest, RobotCreated) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "robot");
  JsonHelper::AddStringToJsonObject(obj, "name", "robot");
  JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
  JsonHelper::AddFloatToJsonObject(obj, "speed", 30);  
  std::vector<float> position_to_add;
  position_to_add.push_back(498.292);
  position_to_add.push_back(253.883);
  position_to_add.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
  std::vector<float> direction_to_add;
  direction_to_add.push_back(1);
  direction_to_add.push_back(0);
  direction_to_add.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
  IEntity* entity = system->CreateEntity(obj);
  
  
  ///
	picojson::object obj2 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj2, "type", "customer");
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add);
	JsonHelper::AddStringToJsonObject(obj2, "name", "customer");
  JsonHelper::AddFloatToJsonObject(obj2, "radius", 1);
  IEntity* entity2 = system->CreateEntity(obj2);
  
  
  picojson::object obj3 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj3, "type", "package");
	JsonHelper::AddStdFloatVectorToJsonObject(obj3, "position", position_to_add);
	JsonHelper::AddStdFloatVectorToJsonObject(obj3, "direction", direction_to_add);
	JsonHelper::AddStringToJsonObject(obj3, "name", "package");
  JsonHelper::AddFloatToJsonObject(obj3, "radius", 1);
  IEntity* entity3 = system->CreateEntity(obj3);
	///

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  
  system->AddEntity(entity2);
  system->AddEntity(entity3);
  
  ASSERT_EQ(3, system->GetEntities().size());
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position_to_add[2]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[0], direction_to_add[0]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[1], direction_to_add[1]);
  ASSERT_FLOAT_EQ(entity->GetDirection()[2], direction_to_add[2]);

  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());
	ASSERT_EQ(picojson::value(system->GetEntities()[1]->GetDetails()).serialize(), picojson::value(obj2).serialize());
	ASSERT_EQ(picojson::value(system->GetEntities()[2]->GetDetails()).serialize(), picojson::value(obj3).serialize());
}
}  // namespace csci3081
