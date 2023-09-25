#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game{

	public:
		Game();
		int players_per_team;
		int max_balls;
		int total_players;
		std :: string players[11];

		bool is_first_innings;
		Team team_a, team_b;
		Team *batting_team, *bowling_team,*swap;
		Player *batsman, *bowler;

		void welcome();
		void show_all_players();
		int take_integer_input();
		void select_players();
		bool validate_selected_player(int);
		void show_team_players();
		void toss();
		void toss_choice(Team);
		void start_first_innings();
		void initialize_players();
		void play_innings();
		void bat();
		bool validate_innings_score();
		void show_game_score_card();
		void start_second_innings();
		void match_summary();
};
