/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_observer.h>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information
 */
class EntityBase : public IEntity {
 public:

   /**
    * @brief Returns the details informaton.
    *
    * @return picojson::object  the details informaton.
    */
  virtual ~EntityBase() {}

  /**
   * @brief Returns the id.
   *
   * @return int  the id.
   */
  const picojson::object& GetDetails() { return details_; }

  /**
   * @brief Returns the name.
   *
   * @return string  the name.
   */
  int GetId() const { return id; }

  /**
   * @brief Returns the position.
   *
   * @return vector<float> - x, y, z position.
   */
  const std::string& GetName(){ return name; }

  /**
   * @brief Set the position.
   *
   * @param[in] p vector<float> - x, y, z position to set.
   * @return nothing.
   */
  const std::vector<float>& GetPosition() const { return position; }

  /**
   * @brief Returns the direction.
   *
   * @return vector<float> - x, y, z dosition.
   */
  void SetPosition(std::vector<float> p) {position = p;}

  /**
   * @brief Set the direction.
   *
   * @param[in] p vector<float> - x, y, z direction to set.
   * @return nothing.
   */
  const std::vector<float>& GetDirection() const { return direction; }

  /**
   * @brief Returns the radius.
   *
   * @return float  the radius.
   */
  void SetDirection(std::vector<float> p) {direction = p;}

  /**
   * @brief Returns the version.
   *
   * @return int  the version.
   */
  float GetRadius() const{ return radius; }

  /**
   * @brief judge whether there is not Dynamic.
   * @return bool true there is Dynamic, false no Dynamic.
   */
  int GetVersion() const { return version; }

  /**
   * @brief Set the Dynamic.
   *
   * @param[in] d bool
   * @return nothing.
   */
  bool IsDynamic() const {return dynamic;}

  /**
   * @brief Set the observer.
   *
   * @param[in] observers std::vector<IEntityObserver*>
   * @return nothing.
   */
  void SetDynamic(bool d) {dynamic = d;}
	bool dynamic;

  /**
   * @brief Set the observer.
   *
   * @param[in] observers std::vector<IEntityObserver*>
   * @return nothing.
   */
	void SetObserver( std::vector<IEntityObserver*> observers ){
		observers_ = observers;
	}

  /**
   * @brief judge whether there is not charge for the drone.
   * @return bool true there is not charge, false there is.
   */
	bool IsSleep(){return sleep;}

  /**
   * @brief Set the sleep.
   *
   * @param[in] s bool
   * @return nothing.
   */  
	void SetSleep(bool s){sleep = s;}
 protected:
  picojson::object details_;
  std::vector<float> position;
  std::vector<float> direction;
  int id;
  std::string name;
  std::string type;
  float radius;
  int version;
  static int count;
  std::vector<IEntityObserver*> observers_;
  bool sleep;
};

}  // namespace csci3081


#endif  // ENTITY_BASE_H_
