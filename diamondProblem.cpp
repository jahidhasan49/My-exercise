#include<iostream>

using namespace std;

class Vehicle{
    protected:
        string name;
        double speed;
    public:
        Vehicle(){
            this->speed = 0;
        }

        Vehicle(string name, double speed){
            this->name = name;
            this->speed = speed;
        }

        string getName(){
            return this->name;
        }

        void setName(string name){
            this->name = name;
        }

        double getSpeed(){
            return this->speed;
        }

        void setSpeed(double speed){
            this->speed = speed;
        }
};

class AirVehicle: virtual public Vehicle{
    protected:
        int noOfPropellers;

    public:
        AirVehicle(): Vehicle(){
            this->noOfPropellers = 0;
        }

        AirVehicle(string name, double speed, int noOfPropellers): Vehicle(name, speed){
            this->noOfPropellers = noOfPropellers;
        }

        int getNoOfPropellers(){
            return this->noOfPropellers;
        }

        void setNoOfPropellers(int noOfPropellers){
            this->noOfPropellers = noOfPropellers;
        }

        void moveOnAir(){
            cout << this->name << " is moving on the air with speed: " << this->speed
                 << " using " << this->noOfPropellers << " propellers..." << endl;
        }
};

class WaterVehicle: virtual public Vehicle{
    protected:
        int noOfTurbines;

    public:
        WaterVehicle(): Vehicle(){
            this->noOfTurbines = 0;
        }

        WaterVehicle(string name, double speed, int noOfTurbines): Vehicle(name, speed){
            this->noOfTurbines = noOfTurbines;
        }

        int getNoOfTurbines(){
            return this->noOfTurbines;
        }

        void setNoOfTurbines(int noOfTurbines){
            this->noOfTurbines = noOfTurbines;
        }

        void moveOnWater(){
            cout << this->name << " is moving on the water with speed: " << this->speed
                 << " using " << this->noOfTurbines << " turbines..." << endl;
        }
};

class HybridVehicle: public AirVehicle, public WaterVehicle{

    public:
        HybridVehicle(): AirVehicle(), WaterVehicle(){

        }

        HybridVehicle(string name, double speed, int noOfPropellers, int noOfTurbines): AirVehicle(name, speed, noOfPropellers), WaterVehicle(name, speed, noOfTurbines){
            this->name = name;
            this->speed = speed;
        }

        void moveOnAirWater(){
            cout << this->name << " is moving on the air and water with speed: " << this->speed
                 << " using " << this->noOfPropellers << " propellers and " << this->noOfTurbines
                 << " turbines..." << endl;
        }
};

int main(){
    AirVehicle helicopter("Helicopter", 200.23, 2);
    WaterVehicle ship("Titanic", 122.23, 4);

    helicopter.moveOnAir();
    ship.moveOnWater();

    HybridVehicle airCruise("AirCruise", 400.45, 3, 5);
    airCruise.moveOnAirWater();

    return 0;
}
