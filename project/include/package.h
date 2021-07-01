/**
 *@file package.h
 */
 #ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include "customer.h"
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for package entity.
 *
 * The package is the stuff that be delivered by a transport entity.
 * It should contain the weight and the customer(destination)'s information.
 *
 */

class Package : public csci3081::EntityBase {

 public:

   /**
    * @brief The default constructor.
    */
 	Package();

  /**
 * @brief Constructor that set the value of varables according to obj
 *
 * @param[in] details JSON object - contains all data information for package.
 */
  Package(const picojson::object& details);

  /**
   * @brief Returns the weight of the package.
   *
   * @return float  the weight of the package.
   */
  float GetWeight() const;

  /**
   * @brief Set the weight for the package.
   *
   * @param[in] weight float - the weight of the package.
   * @return nothing.
   */
  void Setweight(float w);

  /**
   * @brief Return the destination for the package.
   *
   * @return Customer the destination for the package.
   */
  Customer* GetCustomer() const;

  /**
   * @brief Set the destination for the package.
   *
   * @param[in] cus Customer* - the destination of the package.
   * @return nothing.
   */
  void SetCustomer(Customer* cus);

  /**
   * @brief Set the state of package, and pass the path to its current destination to all observers.
   *
   * @param[in] value string .
   * @param[in] d Package* .
   * @return nothing.
   */
	void NotifyForPackage(std::string value, Package* d);

 private:
  std::vector<float> destination;
  float weight;
  Customer* customer;
};

}
#endif
