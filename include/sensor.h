#pragma once
#include<string>
#include<array>
/**
 * @brief namespace for the Assignment
 * 
 */
namespace RWA2{
/**
 * @brief Class for the Sensor
 * 
 */
    class sensor
    {
    private:

        /*  private attributes */

        std::string model_;
        std::array<double,50> data_;

    public:

        /*Constructor*/

        sensor(){
            model_ = 'OSDome';
        }

        /*public Methods*/
        
        void read_data(unsigned int duration);

    };//class sensor
   
}//namespace RWA2