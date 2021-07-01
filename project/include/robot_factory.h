/**
 *@file robot_factory.h
 */
#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>
#include <vector>
#include <string>
#include "json_helper.h"
#include "robot.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for creating drone entity.
 *
 * This class can create a drone entity if the "type" of val is drone
 *
 */
class RobotFactory : public IEntityFactory {
 public:

   /**
    * @brief The default constructor.
    */
  RobotFactory();

  /**
   * @brief The destructor.
   */
  ~RobotFactory();

  /**
   * @brief  Create a robot entity by json object val.
   *
   * @param[in] val picojson object - detail informations of the entity
   *
   * return Entity that is of the type specified in the picojson object.
   */
  IEntity* CreateEntity(const picojson::object& val);
};

}  // namespace csci3081
#endif  // ROBOT_FACTORY_H_
