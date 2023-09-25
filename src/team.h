#include <vector>
#include "player.h"

class Team{

	public:
		Team();
		std :: string name;
		int total_runs_scored;
		int wickets_lost;
		int total_balls_bowled;
		std :: vector <Player> players;
};
