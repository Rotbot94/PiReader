#include <ncurses.h>
#include <string>


using namespace std;

int main(int argc, char ** argv) {
	
	// inits ncurses
	initscr();
	noecho();
	cbreak();
	
	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	
	//input window
	WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	
	keypad(menuwin, true);
	
	string programs[4] = {"Barometer", "Hygrometer", "Thermometer", "Print name"};
	int choice;
	int highlight = 0;
	
	while(1) {
		for(int i = 0; i < 4; i++) {
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
				if (highlight == 4)
				highlight = 3;
				break;
			default:
				break;
		}
		if(choice == 10) {
			break;
		}
	}
	
	printw("Your choice was %s", programs[highlight].c_str());	
	
	//ends ncurses
	endwin();
	
	return 0;
	
}
