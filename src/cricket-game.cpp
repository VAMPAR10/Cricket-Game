//============================================================================
// Name        : cricket-game.cpp
// Author      : Dev Chugh
//============================================================================

#include <windows.h>
#include "game.h"
using namespace std;

int main() {
	Game game;
	game.welcome();

	cout<<("Press enter to continue...")<<endl;
	cin.ignore(10,'\n');
	cin.get();

	game.show_all_players();

	cout<<"Press enter to continue..."<<endl;
	getchar();

	game.select_players();

	game.show_team_players();

	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //To clear input buffer memory..

	cout<<("Press enter to continue...")<<endl;
	cin.ignore(10,'\n');
	cin.get();

	game.toss();

	game.start_first_innings();

	game.start_second_innings();

	game.match_summary();

	return 0;
}
