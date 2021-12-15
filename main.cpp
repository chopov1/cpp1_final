#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;



class CupRecepticle {
const int maxCups =4;
const int minCups =0;

public: 
bool hasBeans = false;
bool hasWater = false;
bool isHot = false;
bool isGrinded = false;
bool isPoured = false;


CupRecepticle(){

}
    

bool IsNumber(const char * pstr){
    if(NULL == pstr || *pstr == '\0'){
        return false;
    }
    char c = *pstr;
    if(c < '0' || c > '4'){
         return false;
    }
    return true;
}



int getInput(){
    cout<<"How many cups of coffee do you want? Pick a number between 1 and 4"<< endl;
    std::string input;
    cin >> input;
    string inputchar = input;
    int num;
    char chars[52];
    strcpy(chars, inputchar.c_str());
    if(IsNumber(chars)){
        num = stoi(input);
    }else{
        cout<<"You did not enter a number"<<endl;
        return 0;
    }
    if(num <= 0 || num > 4){
        std::cout<<"You did not pick a valid amount of cups" <<endl;
        return 0;
    }
    return num;
}
};

class CoffeeMaker{
 
 
    public:
    
    CoffeeMaker(){
        // CupRecepticle cuprecepticle = CupRecepticle();
        // int cupsToMake = cuprecepticle.getInput();
        // Hopper hopper = Hopper(cupsToMake);
    }
    public:
    template<class T>
    bool isAvailable(T &amountRequired, T &amountAvailable){
        if(amountAvailable < amountRequired){
            return false;
        }
        return true;
    };

};


class Hopper : public CoffeeMaker{

public:

const int maxGrams = 200;
const int gramsPerCup = 50;
int availableGrams = maxGrams;

    Hopper(){
        
    }

    bool HasBeans(int cups){
        cout<<"hopper created"<<endl;
        int requiredGrams = cups * gramsPerCup;
        if(!isAvailable(requiredGrams, availableGrams)){
            cout<<"There is not enough grams of beans to fulfill this order. Please refill the hopper"<<endl;
            return false;
        }else{
            std::cout << "Hopper added "<< requiredGrams << " grams of beans to the mix" << endl;
            return true;
        }
        
    }

    void RefillHopper(){
        availableGrams = maxGrams;
        cout<< "Hopper has been refilled. It now has " << availableGrams << " grams of beans available." <<endl;
    }
    

};

class WaterReservoir : public CoffeeMaker {
    public:
const float maxLiters = 1.0f;
const float litersPerCup = .25f;
float availableLiters = maxLiters;
    WaterReservoir(){
    
    }

    bool HasWater(int cups){
        float requiredLiters = cups * litersPerCup;
        if(!isAvailable(requiredLiters, availableLiters)){
            cout<<"There is not enough liters of water to fulfill this order. Please refill the water reservoir"<<endl;
            return false;
        }else{
            cout<<"Water Reservoir added "<< requiredLiters << " liters of water to the mix"<<endl;
            return true;
        }
    }

    void RefillWater(){
        availableLiters = maxLiters;
        cout << "Water Reservoir has been refilled. It now has " << availableLiters << " liters of water available."<<endl;
    }
};

class HeatSource : public CoffeeMaker{
    public:
const int startTemp = 30;
const int boilTemp = 100;
int currentTemp = startTemp;
    HeatSource(){
         
}

bool isHeated(bool hasWater){
if(hasWater == true){
            while(currentTemp < boilTemp){
                cout<<"Water is at "<<currentTemp <<" degrees" << endl;
                currentTemp++; 
            }
            return true;
        }else{
            cout<<"You do not have water to heat up."<<endl;
            return false;
        }
}
    

};

class Grinder : public CoffeeMaker{
public:
    Grinder(){
        
    }

    bool isGrinded(bool hasBeans){
        if(hasBeans == true){
            cout<<"The beans have been grinded"<<endl;
            return true;
        }
        return false;
    }
};






int main() {
CupRecepticle cuprecepticle = CupRecepticle();
int cups = 0;
while(cups == 0){
cups = cuprecepticle.getInput();
}

//int cups = 4;
Hopper hopper = Hopper();
//hopper.isAvailable(hopper.availableGrams, cups);
cuprecepticle.hasBeans = hopper.HasBeans(cups);
WaterReservoir water = WaterReservoir();
float f = (float)cups;
cuprecepticle.hasWater = water.HasWater(cups);
//water.isAvailable(water.availableLiters, f);
HeatSource heat = HeatSource();
cuprecepticle.isHot = heat.isHeated(cuprecepticle.hasWater);
Grinder grinder = Grinder();
cuprecepticle.isGrinded = grinder.isGrinded(cuprecepticle.hasBeans);

cout<< "Here are your " << cups << " cups of coffee. Thanks you for using." << endl;


}
