/**
 *@file package_factory.h
 */
#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>
#include <vector>
#include <string>
#include "package.h"
#include "json_helper.h"
namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for creating package entity.
 *
 * This class can create a drone entity if the "type" of val is package
 *
 */
class PackageFactory : public IEntityFactory {
 public:

   /**
    * @brief The default constructor.
    */
  PackageFactory();

  /**
   * @brief The destructor.
   */
  ~PackageFactory();

  /**
   * @brief  Create a package entity by json object val.   
   * @param[in] val picojson object - detail informations of the entity
   *
   * return Entity that is of the type specified in the picojson object.
   */
  IEntity* CreateEntity(const picojson::object& val);
};

}  // namespace csci3081
#endif  // PACKAGE_FACTORY_H_
