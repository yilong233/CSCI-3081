/**
 *@file PATH_STRATEGY.h
 */

#ifndef PATH_STRATEGY_H_
#define PATH_STRATEGY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include "drone.h"
#include <EntityProject/graph.h>
namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for Path Strategy
 *
 * The BeelinePath class should have attributes that indicate the Default constructor,
 * and the getpath method.
 *
 */
class PathStrategy {

 public:

   /**
    * @brief Return the path using the beeline method.
    *
    * @param[in] v1 vector<float>
    * @param[in] v1 vector<float>
    * @param[in] gragh IGraph*
    *
    * @return 	vector<vector<float>> - the path using the beeline method.
    */
 	virtual vector<vector<float>> GetPath(vector<float> v1,vector<float> v2,const IGraph* gragh)=0;

  /**
   * @brief The destructor.
   */
  virtual ~PathStrategy(){}

};

}
#endif
