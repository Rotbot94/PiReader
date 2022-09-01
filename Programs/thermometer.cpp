//
// Created by Ali on 30/08/2022.
//

#include <SenseHat.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

    SenseHat sHat;
    
    sHat.WipeScreen();
    cout << "The temperature is currently " << sHat.GetTemperature() << endl;    
    sHat << setcouleur(sHat.ConvertRGB565(255,153,51));
    
    while(1) {
    sHat << sHat.GetTemperature() << flush;
    sleep(1);
    }
    return 0;
}
