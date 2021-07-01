/**
 *@file schedule.h
 */
#ifndef SCHEDULE_H_
#define SCHEDULE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>

//#include <EntityProject/entity_factory.h>
#include <EntityProject/entity.h>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class can be used to simplify the delivery-simulation class.
 * And it includes GetMinDistanceIndex(), GetMinRechargeDistanceIndex(), ScheduleDelivery() and
 * ScheduleRecharge() function.
 */

class Schedule {
 public:

   /**
    * @brief The default constructor.
    */
  Schedule();

  /**
   * @brief The destructor.
   */
  ~Schedule();

  /**
   * @brief Get the min distance index
   *
   * @param[in] entities_ std::vector<entity_project::IEntity*>
   * @param[in] package entity_project::IEntity*
   *
   * @return int.
   */
  int GetMinDistanceIndex(std::vector<entity_project::IEntity*> entities_, entity_project::IEntity* package);
  /**
   * @brief Get the min recharge distance index
   *
   * @param[in] entities_ std::vector<entity_project::IEntity*>
   * @param[in] package entity_project::IEntity*
   *
   * @return int.
   */
  int GetMinRechargeDistanceIndex(std::vector<entity_project::IEntity*> entities_, entity_project::IEntity* empty);
  /**
   * @brief Set the information for the drone or the robot without the power
   *
   * @param[in] package entity_project::IEntity*
   * @param[in] dest entity_project::IEntity*
   * @param[in] tran entity_project::IEntity*
   * @param[in]  graph_ const IGraph*
   * @return Nothing.
   */

  void ScheduleDelivery(entity_project::IEntity* package, entity_project::IEntity* dest, entity_project::IEntity* tran, const IGraph* graph_);

  /**
   * @brief Set the information for the recharge drone.
   *
   * @param[in] empty entity_project::IEntity*
   * @param[in] tran entity_project::IEntity*
   * @param[in]  graph_ const IGraph*
   * @return Nothing.
   */
  void ScheduleRecharge(entity_project::IEntity* empty, entity_project::IEntity* tran, const IGraph* graph_);

};

}  // namespace csci3081
#endif  // SCHEDULE_H_
