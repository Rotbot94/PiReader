#include <SenseHat.h>
#include <ncurses.h>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


void barometer() {
	
	SenseHat sHat;
    sHat.WipeScreen();
    clear();
    refresh();
    printw("The air pressure is currently:");
    printw("%f", sHat.GetPressure());
    printw("\n Press any button to continue");
    refresh();
    sHat << setcouleur(sHat.ConvertRGB565(255,153,255));
    sHat << sHat.GetPressure() << flush;
    refresh();
    getch();
    return;
}

void hygrometer() {	
	SenseHat sHat;
    sHat.WipeScreen();
    clear();
    refresh();
    printw("The humidity level is currently:");
    printw("%f", sHat.GetHumidity());
    printw("\n Press any button to continue");
    refresh();
    sHat << setcouleur(sHat.ConvertRGB565(10,62,233));
    sHat << sHat.GetHumidity() << flush;
    refresh();
    getch();
    return;
}

void thermometer() {
	SenseHat sHat;
    sHat.WipeScreen();
    clear();
    refresh();
    printw("The temperature is currently:");
    printw("%f", sHat.GetTemperature());
    printw("\n Press any button to continue");
    refresh();
    sHat << setcouleur(sHat.ConvertRGB565(255,153,51));
    sHat << sHat.GetTemperature() << flush;
    refresh();
    getch();
    return;
}

void printString() {
	SenseHat sHat;
	stringstream ss;
	char str[80];
	sHat.WipeScreen();
   
    clear();
    refresh();
    
    string name;
    printw("Enter your name: ");
    echo();
    getstr(str);
    noecho();
    refresh();
    printw("You Entered: %s", str);
    printw("\n Press any button to continue");
    refresh();
    
    ss << str;
    ss >> name;
    
    sHat << setcouleur(sHat.ConvertRGB565(255,255,255)) << setrotation(270);
    sHat << name << flush;
    refresh();
    getch();
    return;
}

void writeToFile() {
	SenseHat sHat;

    float temperature = sHat.GetTemperature();
    float pressure = sHat.GetPressure();
    float humidity = sHat.GetHumidity();
    
    std::ofstream dataDump;
    dataDump.open ("dataDump.csv");
    dataDump << "Temperature, Pressure, Humidity \n";
    dataDump << temperature << ",\t" << pressure << ",\t"<< humidity << endl;
    dataDump.close();
    
    return;
}

int main(int argc, char ** argv) {
	
	// inits ncurses
	initscr();
	noecho();
	cbreak();
	
	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	
	//input window
	WINDOW * menuwin = newwin(8, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	
	keypad(menuwin, true);
	
	string programs[6] = {"Barometer", "Hygrometer", "Thermometer", "Print name", "Write current data to file", "Exit"};
	int choice;
	int highlight = 0;
	
	while(1) {
		for(int i = 0; i < 6; i++) {
			if (i == highlight) {
				wattron(menuwin, A_REVERSE);
			}
			mvwprintw(menuwin, i+1, 1, programs[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		
		choice = wgetch(menuwin);
		
		switch(choice) {
			case KEY_UP:
				highlight--;
				if (highlight == -1)
				highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 6)
				highlight = 5;
				break;
			case KEY_RIGHT:
				if(programs[highlight] == "Barometer") {
					clear();
					refresh();
					barometer();
					wrefresh(menuwin);
					break;
				}
				else if(programs[highlight] == "Hygrometer") {
					clear();
					refresh();
					hygrometer();
					wrefresh(menuwin);
					break;
				}	
				else if(programs[highlight] == "Thermometer") {
					clear();
					refresh();
					thermometer();
					wrefresh(menuwin);
					break;
				}	
				else if(programs[highlight] == "Print name") {
					clear();
					refresh();
					printString();
					wrefresh(menuwin);
					break;
				}
				else if (programs[highlight] == "Write current data to file") {
					clear();
					refresh();
					writeToFile();
					wrefresh(menuwin);
					break;
				}
				else if(programs[highlight] == "Exit") {
					clear();
					refresh();
					printw("Program was terminated, press any button to exit.");
					refresh();
					getch();
					exit(3);
				}	
				break;
			default:
				break;
		}
	}

	endwin();
	
	return 0;
}
