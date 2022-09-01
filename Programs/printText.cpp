#include <SenseHat.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

    SenseHat sHat;
    string name;

    sHat.WipeScreen();
    cout << "Enter your name: ";
    getline(cin, name);

    sHat << setcouleur(sHat.ConvertRGB565(255,255,255)) << setrotation(270);
    while(1){

    sHat << name << flush;
	sleep(1);
    }
    return 0;
}

