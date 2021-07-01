/**
 *@file parabolic_path.h
 */

#ifndef PARABOLIC_PATH_H_
#define PARABOLIC_PATH_H_

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
  * @brief The class for ParabolicPath that belones to a PathStrategy.
  *
  * The ParabolicPath class should have attributes that indicate the Default constructor,
  * and the getpath method.
  *
  */
class ParabolicPath : public csci3081::PathStrategy {
 public:

   /**
    * @brief The default constructor.
    */
 	ParabolicPath();

  /**
   * @brief Return the path using the Parabolic method.
   *
   * @param[in] v1 vector<float>
   * @param[in] v1 vector<float>
   * @param[in] gragh IGraph*
   *
   * @return 	vector<vector<float>> - the path using the Parabolic method.
   */
 	vector<vector<float>> GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh);

};

}
#endif
