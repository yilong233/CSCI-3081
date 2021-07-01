/**
 *@file customer_factory.h
 */
#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>
#include <vector>
#include <string>
#include "customer.h"
#include "json_helper.h"
namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for creating customer entity.
 *
 * This class can create a drone entity if the "type" of val is customer
 *
 */
class CustomerFactory : public IEntityFactory {
 public:

   /**
    * @brief The default constructor.
    */
  CustomerFactory();

  /**
   * @brief The destructor.
   */
  ~CustomerFactory();

  /**
   * @brief  Create a Customer entity by json object val.
   *
   * @param[in] val picojson object - contains all data information for customer.
   *
   * @return Customer entity or NULL.
   */
  IEntity* CreateEntity(const picojson::object& val);
};

}  // namespace csci3081
#endif  // CUSTOMER_FACTORY_H_
