/**
 *@file composite_factory.h
 */
#ifndef COMPOSITEFACTORY_H_
#define COMPOSITEFACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include <string>

#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The composite class for creating entity factorties.
 *
 * This class can add and store the many kinds of entity factories.
 * And call the proper entity factory to create a new entity.
 */
class CompositeFactory : public entity_project::IEntityFactory {
 public:

   /**
    * @brief The default constructor.
    */
  CompositeFactory();

  /**
   * @brief The destructor.
   */
  ~CompositeFactory();

  /**
   * @brief Creates an entity by different picojson object type.
   *
   * @param[in] val picojson object - detail informations of the entity
   *
   * return Entity that is of the type specified in the picojson object.
   */
  entity_project::IEntity* CreateEntity(const picojson::object& val);

  /**
   * @brief Push entity factory into composite.
   *
   * @param[in] newFac IEntityFactory - add the Entity Factory to the composite
   *
   * @return Nothing.
   */
  void AddFactory(entity_project::IEntityFactory* newFac);

 private:
 	std::vector<IEntityFactory*> factories;

};

}  // namespace csci3081
#endif  // ENTITY_BASE_H_
