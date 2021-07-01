#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/vector3D.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

#include <iostream>


namespace csci3081 {

  class Vector3DTest : public ::testing::Test {
   protected:
    virtual void SetUp() {
      std::vector<float> v1={1,2,3};
      vec1 = Vector3D(v1);
      vec2 = Vector3D();
    }
    Vector3D vec1;
    Vector3D vec2;
  };

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

 TEST_F(Vector3DTest, MagnitudeTest) {
   float expected_out1 = sqrt(1*1+2*2+3*3);
   float expected_out2 = 0;
   EXPECT_FLOAT_EQ(vec1.magnitude(),expected_out1) << "Magnitude of vec1 not setup properly";
   EXPECT_FLOAT_EQ(vec2.magnitude(),expected_out2) << "Magnitude of vec2 not setup properly";
 }


  TEST_F(Vector3DTest, NormalizeTest) {
    std::vector<float> expected_out1 = {1/sqrt(1*1+2*2+3*3),2/sqrt(1*1+2*2+3*3),3/sqrt(1*1+2*2+3*3)};
    std::vector<float> expected_out2 = {0,0,0};
    vec1.normalize();
    vec2.normalize();
    EXPECT_FLOAT_EQ(vec1.GetVec()[0], expected_out1[0]) << "Normalize of vec1 not setup properly";
    EXPECT_FLOAT_EQ(vec1.GetVec()[1], expected_out1[1]) << "Normalize of vec1 not setup properly";
    EXPECT_FLOAT_EQ(vec1.GetVec()[2], expected_out1[2]) << "Normalize of vec1 not setup properly";

    EXPECT_FLOAT_EQ(vec2.GetVec()[0], expected_out2[0]) << "Normalize of vec2 not setup properly";
    EXPECT_FLOAT_EQ(vec2.GetVec()[1], expected_out2[1]) << "Normalize of vec2 not setup properly";
    EXPECT_FLOAT_EQ(vec2.GetVec()[2], expected_out2[2]) << "Normalize of vec2 not setup properly";
  }


}
