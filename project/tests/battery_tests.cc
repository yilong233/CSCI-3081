#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include "../include/battery.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class BatteryTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        batt = new Battery(6793.4);
    }
     protected:
        Battery* batt;  
};
    TEST_F(BatteryTest, MaxChargeTest){
        EXPECT_FLOAT_EQ(batt -> GetMax(), 10000);
    }

    TEST_F(BatteryTest, GetRemainingTest){
        batt -> SetRemaining(453.3);
        EXPECT_FLOAT_EQ(batt -> GetRemaining(), 453.3);
    }

    TEST_F(BatteryTest, ReduceRemainingTest){
        batt -> ReduceRemaining(23);
        EXPECT_FLOAT_EQ(batt -> GetRemaining(), 6770.3999);
    }

   TEST_F(BatteryTest, IsEmptyTest){
        EXPECT_FLOAT_EQ(batt -> IsEmpty(), false);
    }

    TEST_F(BatteryTest, SetEmptyTest){
        batt -> SetRemaining(0.0);
        batt -> SetEmpty(true);
        EXPECT_FLOAT_EQ(batt -> IsEmpty(), true);
    }
}
