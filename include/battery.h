#pragma once 
#include<string>

/**
 * @brief namespace for the assignment RWA2
 * 
 */
namespace RWA2{
/**
 * @brief class for the battery
 * 
 */
    class battery
    {
    private:

        /* private attributes */

        std::string model_;
        int current_charge_{86};
        int capacity_{100};
        bool is_charging{false};

        
        /*private methods*/

        void stop_charging();
        

    public:

        /*constructor*/

        battery(){
            model_ = 'LiFePO4';
        }

        /*accessors*/
        
        int get_current_charge()const{
            return current_charge_;
        }

        bool get_charge_status()const{
            return is_charging;
        }

        /* public methods*/

        void start_charging();
        void discharge(double amount);

    }; //class battery
    
} //namespace RWA2

