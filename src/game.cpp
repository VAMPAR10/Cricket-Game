#include "game.h"
using namespace std;

Game :: Game (){
	players_per_team = 4;
	max_balls = 6;
	total_players = 11;
	players[0] = "Zafkiel";
	players[1] = "Vampario";
	players[2] = "Knifu";
	players[3] = "Devil";
	players[4] = "Ezikiel";
	players[5] = "Zeal";
	players[6] = "Zadkiel";
	players[7] = "Gabriel";
	players[8] = "Raphael";
	players[9] = "Matron";
	players[10] = "Venti";

	is_first_innings = false;
	team_a.name = "Team-A";
	team_b.name = "Team-B";
}

void Game :: welcome(){

	cout<<"--------------------------------------------------"<<endl;
	cout<<"|=*=*=*=*=*=*=*=*=*=*CRIC- IN*=*=*=*=*=*=*=*=*=*=|"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"|                                                |"<<endl;
	cout<<"|         Welcome to Virtual Cricket Game        |"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<endl<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"|=*=*=*=*=*=*=*=*=*Instructions*=*=*=*=*=*=*=*=*=|"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"|                                                |"<<endl;
	cout<<"| 1.Create 2 teams (Team-A and Team-B with 4     |"<<endl;
	cout<<"| players each) from a given pool of 11 players. |"<<endl;
	cout<<"| 2.Lead the toss and decide the choice of play. |"<<endl;
	cout<<"| 3.Each innings will be of 6 balls.             |"<<endl;
	cout<<"--------------------------------------------------"<<endl;
}

void Game :: show_all_players(){

	cout<<"--------------------------------------------------"<<endl;
	cout<<"|=*=*=*=*=*=*=*=*=*Players Pool*=*=*=*=*=*=*=*=*=|"<<endl;
	cout<<"--------------------------------------------------"<<endl;

	for (int i=0;i<total_players;i++) {
		cout<<"\t\t["<<i<<"]  "<<players[i]<<endl;
	}

	cout<<"--------------------------------------------------"<<endl;
}

int Game :: take_integer_input(){

	int n;

	while (!(cin>>n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid Input!! Please try again with valid input: ";

	}
	return n;
}

bool Game :: validate_selected_player (int id){

	int n;
	vector<Player> players;

	players = team_a.players;
	n = players.size();
	for (int i = 0; i<n; i++){
		if (players[i].index == id){
			return false;
		}
	}

	players = team_b.players;
	n = players.size();
	for (int i = 0; i<n; i++){
		if (players[i].index == id){
			return false;
		}
	}

	return true;
}

void Game :: select_players(){

	cout<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"|=*=Distributing Players over Team-A & Team-B*=*=|"<<endl;
	cout<<"--------------------------------------------------"<<endl;

	for(int i=0; i<players_per_team; i++){

		selection_a:
			cout<<endl<<"Select player "<<i+1<<" of Team-A: ";
			int player_index_team_a = take_integer_input();
			if (player_index_team_a < 0 || player_index_team_a > 10) {

				cout<<endl<<"Please enter valid index value!"<<endl;
				goto selection_a;
			}
			else if (!validate_selected_player(player_index_team_a)){

				cout<<endl<<"This player has been already selected.Please select another player."<<endl;
				goto selection_a;
			}
			else{
				Player team_a_player;
				team_a_player.index = player_index_team_a;
				team_a_player.name = players[player_index_team_a];
				team_a.players.push_back(team_a_player);
			}


		selection_b:
			cout<<endl<<"Select player "<<i+1<<" of Team-B: ";
			int player_index_team_b = take_integer_input();
			if ((player_index_team_b < 0) || (player_index_team_b > 10)) {

				cout<<endl<<"Please enter valid index value!"<<endl;
				goto selection_b;
			}
			else if (!validate_selected_player(player_index_team_b)){

				cout<<endl<<"This player has been already selected.Please select another player."<<endl;
				goto selection_b;
			}
			else {
				Player team_b_player;
				team_b_player.index = player_index_team_b;
				team_b_player.name = players[player_index_team_b];
				team_b.players.push_back(team_b_player);
			}
	}
}

void Game :: show_team_players(){

	vector<Player> team_a_players = team_a.players;
	vector<Player> team_b_players = team_b.players;

	cout<<endl;
	cout<<"-------------------------\t-------------------------"<<endl;
	cout<<"|=*=*=*=*Team-A=*=*=*=*=|\t|=*=*=*=*Team-B=*=*=*=*=|"<<endl;
	cout<<"-------------------------\t-------------------------"<<endl;
	for (int i =0; i<players_per_team; i++){
		cout<<"|\t["<<i<<"] "<<team_a_players[i].name<<"\t|\t"<<"|\t["<<i<<"] "<<team_b_players[i].name<<"\t|"<<endl;
	}
	cout<<"-------------------------\t-------------------------"<<endl;
}

void Game :: toss(){

	cout<<"--------------------------------------------------"<<endl;
	cout<<"|=*=*=*=*=*=*=*=*=*Coin tossing*=*=*=*=*=*=*=*=*=|"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<endl<<"Tossing the coin..."<<endl<<endl;

	srand(time(NULL));
	int random_value = rand()%2;

	switch(random_value){
		case 0:
			cout<<"Team-A won the toss!!"<<endl<<endl;
			toss_choice(team_a);
			break;
		case 1:
			cout<<"Team-B won the toss!!"<<endl<<endl;
			toss_choice(team_b);
			break;
	}
}

void Game :: toss_choice(Team toss_winning_team){

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" <<endl
        	 << "2. Bowl " <<endl
			 <<"Choice: ";

	int toss_input = take_integer_input();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (toss_input){
		case 1:
			cout << endl << toss_winning_team.name << " won the toss and elected to bat first" << endl << endl;

			if (toss_winning_team.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				batting_team = &team_a;
				bowling_team = &team_b;
			} else {	// else Team-B is the toss winner
				batting_team = &team_b;
				bowling_team = &team_a;
			}

			break;
		case 2:
			cout << endl << toss_winning_team.name << " won the toss and choose to bowl first" << endl << endl;
			if (toss_winning_team.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowling_team = &team_a;
				batting_team = &team_b;
			} else {	// else Team-B is the toss winner
				bowling_team = &team_b;
				batting_team = &team_a;
			}
			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			toss_choice(toss_winning_team);
			break;
   	}
}

void Game :: start_first_innings(){

	cout<<"\t\t :::| FIRST INNINGS STARTS |:::"<<endl<<endl;

	is_first_innings = true;

	initialize_players();
	play_innings();
}

void Game :: initialize_players(){

	batsman = &(batting_team->players[0]);
	bowler = &(bowling_team->players[0]);

	cout<< batting_team->name << " - "<< batsman->name <<" is batting."<<endl;
	cout<< bowling_team->name << " - "<< bowler->name <<" is bowling."<<endl;
}

void Game :: play_innings(){

	for (int i =0; i<max_balls; i++){

		cout<<"Press enter to bowl..."<<endl;
		getchar();
		cout<<"Bowling..."<<endl;

		bat();

		if(!validate_innings_score()){
			break;
		}
	}
}

void Game :: bat(){

	srand(time(NULL));
	int runs_scored = rand() % 7;

	batsman->runs_scored = batsman->runs_scored + runs_scored;
	batting_team->total_runs_scored = batting_team->total_runs_scored + runs_scored;
	batsman->balls_played += 1;

	bowler->balls_bowled += 1;
	bowling_team->total_balls_bowled += 1;
	bowler->runs_given = bowler->runs_given + runs_scored;

	if (runs_scored != 0){

		cout << endl << bowler->name << " to " << batsman->name << " " << runs_scored << " runs!" << endl << endl;

		show_game_score_card();
	}
	else {
		cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

		show_game_score_card();

		batting_team->wickets_lost += 1;
		bowler->wickets_taken += 1;

		int next_player_index = batting_team->wickets_lost;
		batsman = &(batting_team->players[next_player_index]);

		if(bowling_team->total_balls_bowled != max_balls){

			cout<<"Batting next is "<< batsman->name <<endl<<endl;
		}
	}
}

bool Game :: validate_innings_score(){

	if (is_first_innings){

		if(batting_team->wickets_lost == players_per_team || bowling_team->total_balls_bowled == max_balls){

			cout<<endl<<"\t\t :::| FIRST INNINGS ENDS |::: "<<endl<<endl;
			cout<< batting_team->name <<" "<< batting_team->total_runs_scored <<" - "<<batting_team->wickets_lost <<" ("<<bowling_team->total_balls_bowled <<")"<<endl;
			cout<< bowling_team->name <<" needs "<< (batting_team->total_runs_scored +1) <<" runs to win the match."<<endl<<endl;

			return false;
		}
	}
	else {

		if(batting_team->total_runs_scored > bowling_team->total_runs_scored){

			cout<<endl<<"\t\t :::| MATCH ENDS |::: "<<endl<<endl;
			cout<< batting_team->name <<" Won the game by "<< (players_per_team-batting_team->wickets_lost)
					<<" wickets."<<endl<<endl;
			return false;
		}
		else if(batting_team->wickets_lost == players_per_team || bowling_team->total_balls_bowled == max_balls){

			if(batting_team->total_runs_scored == bowling_team->total_runs_scored){

				cout<<endl<<"\t\t :::| MATCH ENDS |::: "<<endl<<endl;
				cout<<"Match Tied."<<endl<<endl;
				return false;
			}
			else if(batting_team->total_runs_scored < bowling_team->total_runs_scored){
				cout<<endl<<"\t\t :::| MATCH ENDS |::: "<<endl<<endl;
				cout<< bowling_team->name <<" Won the game by "<< (bowling_team->total_runs_scored-batting_team->total_runs_scored )
						<<" runs."<<endl<<endl;
				return false;
			}
		}
	}

	return true;
}

void Game :: show_game_score_card(){

	cout << "--------------------------------------------------------------------------" << endl;
	cout<<"\t"<< batting_team->name << " "<< batting_team->total_runs_scored <<" - "
			<< batting_team->wickets_lost << " ("<< bowling_team->total_balls_bowled <<") | "
			<< batsman->name <<" "<< batsman->runs_scored <<" ("<<batsman->balls_played <<")\t"
			<< bowler->name <<" "<< bowler->balls_bowled <<" - "<< bowler->runs_given <<" - "
			<< bowler->wickets_taken <<"\t"<<endl;
	cout << "--------------------------------------------------------------------------" << endl<<endl;
}

void Game :: start_second_innings(){

	cout<<"\t\t :::| SECOND INNINGS STARTS |:::"<<endl<<endl;

	is_first_innings = false;

	swap = batting_team;
	batting_team = bowling_team;
	bowling_team = swap;

	initialize_players();
	play_innings();
}

void Game :: match_summary(){

	cout<<endl<<"Team-A "<< team_a.total_runs_scored <<" - "<< team_b.wickets_lost <<" ("<< team_a.total_balls_bowled <<")"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"| PLAYER               BATTING          BOWLING  |"<<endl;
	cout<<"|------------------------------------------------|"<<endl;

	for(int i = 0; i<players_per_team; i++){

		vector <Player> first = team_a.players;
		cout<<"| ["<<i<<"] "<<first[i].name <<"\t\t"<< first[i].runs_scored <<"("<< first[i].balls_played
				<<")\t\t"<< first[i].balls_bowled <<"-"<< first[i].runs_given <<"-"<< first[i].wickets_taken<<"\t |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
	}
	cout<<"|                                                |"<<endl;
	cout<<"=================================================="<<endl<<endl;

	cout<<endl<<"Team-B "<< team_b.total_runs_scored <<" - "<< team_b.wickets_lost <<" ("<< team_b.total_balls_bowled <<")"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"| PLAYER               BATTING          BOWLING  |"<<endl;
	cout<<"|------------------------------------------------|"<<endl;

	for(int i = 0; i<players_per_team; i++){

		vector <Player> second = team_b.players;
		cout<<"| ["<<i<<"] "<<second[i].name <<"\t\t"<< second[i].runs_scored <<"("<< second[i].balls_played
				<<")\t\t"<< second[i].balls_bowled <<"-"<< second[i].runs_given <<"-"<< second[i].wickets_taken<<"\t |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
	}
	cout<<"|                                                |"<<endl;
	cout<<"=================================================="<<endl;
}
