/**
 *@file robot.h
 */

#ifndef ROBOT_H_
#define ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "battery.h"
#include "customer.h"
#include "package.h"
#include "vector3D.h"
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for robot entity.
 *
 * The robot to pick up the package and deliver it to the customer.
 * In addition to the information in EntityBase, we also know it speed.
 *
 */
 class Robot : public csci3081::EntityBase {
  public:

    /**
     * @brief The default constructor.
     */
  	Robot();

   /**
    * @brief Constructor that set the value of varables according to obj
    *
    * @param[in] obj JSON object - contains all data information for drone.
    */
   Robot(const picojson::object& obj);

   /**
    * @brief The destructor.
    */
   ~Robot();

   /**
    * @brief Return the speed.
    *
    * @return float the speed.
    */
   float GetSpeed();


   /**
    * @brief Set the speede for the robot.
    *
    * @param[in] s float
    * @return nothing.
    */
   void SetSpeed(float s);

   /**
    * @brief Moves the robot by given time. And the position = position + speed * time
    *
    * @param[in] dt float - time
    *
    * @return Nothing.
    */
   void move(float time);

   /**
    * @brief Return the path of robot from origin to package position.
    *
    * @return  vector<vector<float>>  the path to the package.
    */
   vector<vector<float>> GetPathToPackage();

   /**
    * @brief Set the path of robot from origin to package position.
    *
    * @param[in] path vector<vector<float>>
    * @return nothing.
    */
   void SetPathToPackage(vector<vector<float>> path);

   /**
    * @brief Return the path of robot from package position to customer position.
    *
    * @return  vector<vector<float>>  the path from the package to customer.
    */
   vector<vector<float>> GetPathToCustomer();

   /**
    * @brief Set the path of robot from package position to customer position.
    *
    * @param[in] path vector<vector<float>>
    * @return nothing.
    */
   void SetPathToCustomer(vector<vector<float>> path);

   /**
    * @brief Return the package that robot delivers.
    *
    * @return Package*  the package the robot picks up.
    */
   Package* GetPackage();

   /**
    * @brief Set the package that robot delivers.
    *
    * @param[in] package Package* .
    * @return nothing.
    */

   void SetPackage(Package* p);

   /**
    * @brief Return the customer of the package.
    *
    * @return  Customer*  the package the robot drop off.
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
    * @brief Return ture if robot is delivering a package.
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
   void SetHasPackager(bool h);

   /**
    * @brief Set the state of robot, and pass the path to its current destination to all observers.
    *
    * @param[in] value string .
    * @param[in] d Drone* .
    * @return nothing.
    */
 	void NotifyForRobot(std::string value, Robot* d);


  /**
   * @brief Return the Battery of the robot
   *
   * @return Battery*
   */
	Battery* GetBattery();

  /**
   * @brief  The robot drops the package.
   *
   * @return nothing.
   */
	void drop();
  void dropnocharge();

 private:
	float speed;
  vector<vector<float>> pathToPackage;
  vector<vector<float>> pathToCustomer;
  Package* package_;
  Customer* customer_;
  bool hasPackage;
  Battery* battery;
  int pathToPackageIndex;
  int pathToCustomerIndex;

};

}
#endif
