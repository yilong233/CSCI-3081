/**
 *@file smart_path.h
 */

#ifndef SMART_PATH_H_
#define SMART_PATH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "drone.h"
#include "customer.h"
#include "package.h"
#include "vector3D.h"
#include "path_strategy.h"
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The class for SmartPath that belones to a PathStrategy.
  *
  * The SmartPath class should have attributes that indicate the Default constructor,
  * and the getpath method.
  *
  */
class SmartPath : public csci3081::PathStrategy {
 public:

   /**
    * @brief The default constructor.
    */
 	SmartPath();

  /**
   * @brief Return the path using the Smart method.
   *
   * @param[in] v1 vector<float>
   * @param[in] v1 vector<float>
   * @param[in] gragh IGraph*
   *
   * @return 	vector<vector<float>> - the path using the Smart method.
   */
 	vector<vector<float>> GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh);

};

}
#endif
