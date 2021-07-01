/**
 *@file customer.h
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include "json_helper.h"
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for customer entity.
 *
 * The customer is the destination of the delivery. It should get the package
 * from a transport entity.
 *
 */

class Customer : public csci3081::EntityBase {
 public:

   /**
    * @brief The default constructor.
    */
 	Customer();

  /**
   * @brief Constructor that set the value of varables according to obj
   *
   * @param[in] details JSON object - contains all data information for customer
   */
  Customer(const picojson::object& details);
};

}
#endif
