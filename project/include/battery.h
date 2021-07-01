/**
 *@file battery.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include <vector>
#include <string>


namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for batery that belones to a transport entity.
 *
 * The battery class should have attributes that indicate the max charge,
 * remaining battery life, and also if it has no charge remaining.
 *
 */

class Battery {
 public:

   /**
    * @brief The default constructor.
    */
  Battery();

  /**
   * @brief The constructor.
   *
   * @param[in] m float - max charge
   */
  Battery(float m);

  /**
   * @brief Set the remaining of a battery.
   *
   * @param[in] remaining float - remaining charge.
   * @return nothing.
   */
  void SetRemaining(float m);

  /**
   * @brief Returns the max charge of a battery.
   *
   * @return float the max charge.
   */
  float GetMax() const;

  /**
   * @brief Returns the remaining battery life of a battery.
   *
   * @return float the remaining charge.
   */
  float GetRemaining() const;

  /**
   * @brief Set the remaining battery life of a battery.
   *
   * @param[in] m float - remaining charge.
   * @return nothing.
   */
  void ReduceRemaining(float m);

  /**
   * @brief Returns true if a battery is has no charge remaining.
   *
   * @return nothing
   */
  bool IsEmpty() const;

  /**
   * @brief check if the battery is empty, and update empty.
   *
   * @return nothing
   */
  void CheckEmpty();

  /**
   * @brief Set the true or false for the Empty
   *
   * @param[in] e bool
   * @return nothing.
   */
  void SetEmpty(bool e);

 private:
  float maxCharge;
  float remaining;
  bool empty;
};

}
#endif
