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
    cout << "The humidity level is currently " << sHat.GetHumidity() << endl;    
    sHat << setcouleur(sHat.ConvertRGB565(10,62,233));

    while(1) {
        sHat << sHat.GetHumidity() << flush;
        sleep(1);
    }
    return 0;

}
