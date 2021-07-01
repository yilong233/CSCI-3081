/**
 *@file drone.h
 */

#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "battery.h"
#include "robot.h"
#include "customer.h"
#include "package.h"
#include "vector3D.h"
#include "path_strategy.h"
#include <EntityProject/graph.h>
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for drone entity.
 *
 * The drone to pick up the package and deliver it to the customer.
 * In addition to the information in EntityBase, we also know it speed.
 *
 */
class Drone : public csci3081::EntityBase {
 public:

   /**
    * @brief The default constructor.
    */
 	Drone();

  /**
   * @brief Constructor that set the value of varables according to obj
   *
   * @param[in] obj JSON object - contains all data information for drone.
   */
  Drone(const picojson::object& obj);

  /**
   * @brief The destructor.
   */
  ~Drone();

  /**
   * @brief Return the speed.
   *
   * @return float the speed.
   */
  float GetSpeed();

  /**
   * @brief Set the speede for the drone.
   *
   * @param[in] s float
   * @return nothing.
   */
  void SetSpeed(float s);

  /**
   * @brief Moves the drone by given time. And the position = position + speed * time
   *
   * @param[in] dt float - time
   *
   * @return Nothing.
   */
  void move(float time);

  /**
   * @brief Return the path of drone from origin to package position.
   *
   * @return  vector<vector<float>>  the path to the package.
   */
  vector<vector<float>> GetPathToPackage();

  /**
   * @brief Set the path of drone from origin to package position.
   *
   * @param[in] path vector<vector<float>>
   * @return nothing.
   */
  void SetPathToPackage(vector<vector<float>> path);

  /**
   * @brief Return the path of drone from package position to customer position.
   *
   * @return  vector<vector<float>>  the path from the package to customer.
   */
  vector<vector<float>> GetPathToCustomer();

  /**
   * @brief Set the path of drone from package position to customer position.
   *
   * @param[in] path vector<vector<float>>
   * @return nothing.
   */
  void SetPathToCustomer(vector<vector<float>> path);

  /**
   * @brief Return the package that drone delivers.
   *
   * @return Package*  the package the drone picks up.
   */
  Package* GetPackage();

  /**
   * @brief Set the package that drone delivers.
   *
   * @param[in] package Package* .
   * @return nothing.
   */
  void SetPackage(Package* p);

  /**
   * @brief Return the customer of the package.
   *
   * @return  Customer*  the package the drone drop off.
   */
  Customer* GetCustomer();

  /**
   * @brief Set the customer of the package.
   *
   * @param[in] c Customer* .
   * @return nothing.
   */
  void SetCustomer(Customer* c);

  /**
   * @brief Return ture if drone is delivering a package.
   *
   * @return bool -true is delivering a package; false is not.
   */
  bool IfHasPackage();

  /**
   * @brief Set the state of hasPackage.
   *
   * @param[in] h bool .
   * @return nothing.
   */
  void SetHasPackage(bool h);

  /**
   * @brief Set the state of drone, and pass the path to its current destination to all observers.
   *
   * @param[in] value string .
   * @param[in] d Drone* .
   * @return nothing.
   */
	void NotifyForDrone(std::string value, Drone* d);

  /**
   * @brief Return the path of the drone using different routes.
   *
   * @return  vector<vector<float>>  the path of the drone.
   */
	vector<vector<float>> GetPath(vector<float> v1,vector<float> v2,const IGraph* graph_);

  /**
   * @brief Set the state of drone.
   *
   * @param[in] s string .
   * @return nothing.
   */
	void SetState(std::string s);

  /**
   * @brief Return the state of the drone
   *
   * @return string -the state of the drone
   */
	std::string GetState();

  /**
   * @brief Return the Battery of the drone
   *
   * @return Battery*
   */
	Battery* GetBattery();

  /**
   * @brief  The drone drops the package.
   *
   * @return nothing.
   */
	void drop();

  /**
   * @brief  The drone drops the package when it in low power.
   *
   * @return nothing.
   */
  void dropnocharge();
  /**
   * @brief Set the Empty drone
   *
   * @param[in] e IEntity*
   * @return nothing.
   */
	void SetEmpty(IEntity* e);

  /**
   * @brief Return the Empty drone.
   *
   * @return IEntity* -the Empty drone.
   */
	IEntity* GetEmpty();
 private:
	float speed;
  vector<vector<float>> pathToPackage;
  vector<vector<float>> pathToCustomer;
  Package* package_;
  Customer* customer_;
  IEntity* empty;
  bool hasPackage;
  Battery* battery;
  int pathToPackageIndex;
  int pathToCustomerIndex;
  std::string path;

  PathStrategy* strategy;
  //std::string state;
};

}
#endif
