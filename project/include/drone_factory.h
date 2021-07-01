/**
 *@file drone_factory.h
 */
#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>
#include <vector>
#include <string>
#include "json_helper.h"
#include "drone.h"

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
class DroneFactory : public IEntityFactory {
 public:

   /**
    * @brief The default constructor.
    */
  DroneFactory();

  /**
   * @brief The destructor.
   */
  ~DroneFactory();

  /**
   * @brief  Create a drone entity by json object val.   
   *
   * @param[in] val picojson object - detail informations of the entity
   *
   * return Entity that is of the type specified in the picojson object.
   */
  IEntity* CreateEntity(const picojson::object& val);
};

}  // namespace csci3081
#endif  // DRONE_FACTORY_H_
