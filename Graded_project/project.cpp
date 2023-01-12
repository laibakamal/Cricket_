#include<iostream>		//basic input & output services (cin , cout)
#include<iomanip>		//manipulator functions (setw , setfill , setprecision)
#include<cmath>			//mathematical operations (sqrt , log , trigonometric functions)
#include<cstring>			//for strings
#include<cstdlib>			//defines several general purpose functions,random number generation, including dynamic memory management, communication with the environment, integer arithmetics, searching, sorting and converting.
#include<windows.h>		//for functions
#include<fstream>			//fule handling
using namespace std;



int score = 0,ball = 6, no_of_fours = 0, no_of_sixes = 0, wicket = 10, ball_wise_score = 0;	//global
int score_2 = 0, ball_2 = 6, no_of_fours_2 = 0, no_of_sixes_2 = 0, wicket_2 = 10, ball_wise_score_2 = 0, target = 0;	//global
struct ball_status
{
	int Const_distanceV = 50, Const_distanceH = 10, Const_height = 5;
};
struct ball_info
{
	int Entered_distanceV = 0, Entered_distanceH = 0, Entered_height = 0;
	double Entered_angle_of_deviation = 0;
};
struct computer_score
{
	int noball = (rand() % 3) + 1, bouncer = (rand() % 2), spin = rand() % 7, isStrike = rand() % 2;
};
struct ball_info_2
{
	int Entered_distanceV = rand() % 100;
	int Entered_distanceH = rand() % 20;
	int Entered_height = rand() % 10;
	double Entered_angle_of_deviation = rand() % 20;
};



void DecisionOfToss(int x, int y, int choice, ball_status s, ball_info i, computer_score cs, ball_info_2 i2, int bool_vlue);
void bowling(ball_status s, ball_info i, computer_score cs, int bool_value);
void batting(ball_status s, ball_info_2 i2, computer_score cs, int bool_value);
void decisionOfGame();




int main()
{
	char char_choice = 'q';
	int w = 0, choice = 0, x = 0, y = 0;
	ball_status s;	 ball_info i;		 computer_score cs;		ball_info_2 i2;
	DecisionOfToss((rand() % 2), ((rand() % 2) + 1), 1, s, i, cs, i2, 0);
	return 0;
}


// decision of toss
void DecisionOfToss(int x, int y, int choice, ball_status s, ball_info i, computer_score cs, ball_info_2 i2, int bool_vlue)
{
	int bool_value = 0;;
	char char_choice = 'q';
	cout << "Welcome to ALL STAR CRICKET!!!\nLets play!\nLets toss first!\n";
	cout << "Remember!! Team 1 is you(user) and team 2 is computer.\n";
	cout << "Note! THIS IS A 1 OVER MATCH.\n";
	cout << "\n\nEnter 1 if you choose head for the toss and 0 if you choose tail: ";
	cin >> choice;
	{
		if (x == choice)
		{
			cout << "You've won the toss.\n";
			cout << "Now enter a if you wanna bat first and b if you wanna bowl first: ";
			cin >> char_choice;
			{
				if (char_choice == 'a')
				{
					cout << "Ok! Team 1 (user) has chosen to bat first.\n";
				}
				else if (char_choice == 'b')
				{
					cout << "Ok! Team 1 (user) has chosen to bowl first.\n";
				}
			}
		}
		else if (x != choice)
		{
			cout << "Team 2 (COMPUTER) has won the toss.\n";
			if (y == 1)
			{
				cout << "And has chosen to bat. Team 1(user) , now you've to bowl first.\n";
			}
			else if (y == 2)
			{
				cout << "And has chosen to bowl. Team 1(user) , now you've to bat first.\n";
			}
		}
	}
	{
		if (((x == choice) && (char_choice == 'b')) || ((x != choice) && (y == 1)))
		{
			int counter = 1;
			while (ball > 0 && wicket > 0)
			{
				cout << "\n\nThrow your ball no " << counter << endl;
				bowling(s, i, cs, 0);
				ball_wise_score = 0;
				counter = counter + 1;
				system("pause");
				system("CLS");
			}
			cout << "\nBATTING SUMMARY OF TEAM 2 (COMPUTER):\n";
			cout << "Score : " << score << endl;
			cout << "No of balls thrown by team 1 : " << (counter - 1) << endl;
			cout << "Total fours : " << no_of_fours << endl;
			cout << "Total sixes : " << no_of_sixes << endl;
			cout << "Out batsmen of team 2(computer) / wickets taken by team 1 : " << (10 - wicket) << endl;
			target = score + 1;
			cout << "Target set by team 2(computer) for team 1(user) : " << target << endl;
			system("pause");
			system("CLS");
			int counter_2 = 1;
			int ball_2 = 6, wicket_2 = 10;
			while (ball_2 > 0 && wicket_2 > 0)
			{
				cout << "Now its team 2(computer)'s turn to bowl\n" << "And team 1, you've to bat now.\n";
				cout << "Lets start!\n\n";
				cout << "Ball " << counter_2 << " : ";
				batting(s, i2, cs, bool_value);
				cout << "Score needed to win is : " << (target - score) << endl;
				ball_wise_score_2 = 0;
				counter_2 = counter_2 + 1;
				system("pause");
				system("CLS");
			}
				cout << "\nBATTING SUMMARY OF TEAM 1 (USER):\n";
				cout << "Score : " << score_2 << endl;
				cout << "No of balls thrown by team 1 : " << (counter_2 - 1) << endl;
				cout << "Total fours : " << no_of_fours_2 << endl;
				cout << "Total sixes : " << no_of_sixes_2 << endl;
				cout << "Out batsmen of team 2(computer) / wickets taken by team 1 : " << (10 - wicket_2) << endl;
				system("pause");
				system("CLS");
			
		}
		else if (((x == choice) && (char_choice == 'a')) || ((x != choice) && (y == 2)))
		{
			int counter_2 = 1;
			int ball_2 = 6, wicket_2 = 10;
			while (ball_2 > 0 && wicket_2 > 0)
			{
				int a = 0;
				cout << "Now its team 2(computer)'s turn to bowl\n" << "And team 1, you've to bat now.\n";
				cout << "Lets start!\n\n";
				cout << "Ball " << counter_2 << " : ";
				batting(s, i2, cs, bool_value);
				ball_wise_score_2 = 0;
				counter_2 = counter_2 + 1;
				system("pause");
				system("CLS");
				cout << "\nBATTING SUMMARY OF TEAM 1 (USER):\n";
				cout << "Score : " << score_2 << endl;
				cout << "No of balls thrown by team 2 : " << (counter_2 - 1) << endl;
				cout << "Total fours : " << no_of_fours_2 << endl;
				cout << "Total sixes : " << no_of_sixes_2 << endl;
				cout << "Out batsmen of team 1(user) / wickets taken by team 1 : " << (10 - wicket_2) << endl;
				target = score_2 + 1;
				cout << "Target set by team 1(user) for team 2(computer) : " << target << endl;
				system("pause");
				system("CLS");
			}

			int counter = 1;
			while (ball > 0 && wicket > 0)
			{
				cout << "\n\nThrow your ball no " << counter << endl;
				bowling(s, i, cs, 0);
				ball_wise_score = 0;
				counter = counter + 1;
				system("pause");
				system("CLS");
			}
			cout << "\nBATTING SUMMARY OF TEAM 2 (COMPUTER):\n";
			cout << "Score : " << score << endl;
			cout << "No of balls thrown by team 1 : " << (counter - 1) << endl;
			cout << "Total fours : " << no_of_fours << endl;
			cout << "Total sixes : " << no_of_sixes << endl;
			cout << "Out batsmen of team 2(computer) / wickets taken by team 1 : " << (10 - wicket) << endl;
			system("pause");
			system("CLS");
		}
	}
	void decisionOfGame();
}









void bowling(ball_status s, ball_info i, computer_score cs, int bool_value)
{
	cout << "Enter the distance (length of pitch in feet) ball has covered which you've just thrown: ";
	cin >> i.Entered_distanceV;
	cout << "Enter that width of pitch (in feet) which your ball has taken: ";
	cin >> i.Entered_distanceH;
	cout << "Enter the height (in feet) your ball has reached: ";
	cin >> i.Entered_height;
	cout << "Enter the angle of deviation (in degrees) of ball from 90 degrees: ";
	cin >> i.Entered_angle_of_deviation;
	{
		if (i.Entered_distanceV < s.Const_distanceV)
		{
			cout << "\nNoball!\n";
			ball = ball + 1;
			score = score + 1;
			{
				if (cs.isStrike == 1)
				{
					cout << "Your opponent has strike/played the ball.\n";
					if (cs.noball == 1)
					{
						ball_wise_score = ball_wise_score + 4;
						score = score + ball_wise_score;
						no_of_fours = no_of_fours + 1;
						cout << "Its an amazing four!\n";
						cout << "Score of this ball is: " << ball_wise_score << endl;
						cout << "Total score uptil now is : " << score << endl;
					}
					else if (cs.noball == 2)
					{
						ball_wise_score = ball_wise_score + 6;
						cout << "Its an amazing six!\n";
						score = score + ball_wise_score;
						no_of_sixes = no_of_sixes + 1;
						cout << "Score of this ball is: " << ball_wise_score << endl;
						cout << "Total score uptil now is : " << score << endl;
					}
					else
					{
						cout << "Batsman out!!! Wicket!!!\n";
						wicket = wicket - 1;
						cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
						cout << "Next batsman from team 2 (computer) , come to bat" << endl;
						cout << "Score of this ball is: " << ball_wise_score << endl;
						cout << "Total score uptil now is : " << score << endl;
					}
				}
				else if (cs.isStrike == 0)
				{
					cout << "Your opponent has not played the ball.\n";
					ball_wise_score = ball_wise_score + 1;
					cout << "Score of this ball is:" << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score  << endl;
				}
			}
		}
		else if (i.Entered_distanceH > s.Const_distanceH)
		{
			cout << "\nWide!\n";
			{
				score = score + 1;
				if (cs.isStrike == 1)
				{
					cout << "Your opponent has strike/played the ball.\n";
					ball_wise_score = ball_wise_score + 4;
					no_of_fours = no_of_fours + 1;
					cout << "Its an amazing four!\n";
					score = score + ball_wise_score;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
				}
				else if (cs.isStrike == 0)
				{
					cout << "Your opponent has not played the ball.\n";
					cout << "Score of this ball is: 1" << endl;
					cout << "Total score uptil now is : " << score << endl;
				}
			}
		}
		else if (i.Entered_height > s.Const_height)
		{
			cout << "\nBouncer!\n";
			{
				if (cs.bouncer == 0)
				{
					cout << "Your opponent has not played the ball.\n";
					cout << "Batsman out!!! Wicket!!!\n";
					wicket = wicket - 1;
					cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
					cout << "Next batsman from team 2 (computer) , come to bat" << endl;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
				}
				else if (cs.bouncer == 1)
				{
					cout << "Your opponent has strike/played the ball.\n";
					ball_wise_score = ball_wise_score + 6;
					cout << "Its an amazing six!\n";
					score = score + ball_wise_score;
					no_of_sixes = no_of_sixes + 1;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
				}
			}
		}
		else if (i.Entered_angle_of_deviation < (-5) || i.Entered_angle_of_deviation>5)
		{
			cout << "\nSpin!\n";
			if (cs.isStrike == 1)
			{
				cout << "Your opponent has strike/played the ball.\n";
				if ((cs.spin == 5) || (cs.spin == 3))
				{
					cout << "Batsman out!!! Wicket!!!\n";
					wicket = wicket - 1;
					cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
					cout << "Next batsman from team 2 (computer) , come to bat" << endl;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
				}
				else if (cs.spin == 4)
				{
					ball_wise_score = ball_wise_score + 4;
					cout << "Its an amazing four!\n";
					score = score + ball_wise_score;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
					no_of_fours = no_of_fours + 1;
				}
				else if (cs.spin == 6)
				{
					ball_wise_score = ball_wise_score + 6;
					cout << "Its an amazing six!\n";
					score = score + ball_wise_score;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;
					no_of_sixes = no_of_sixes + 1;
				}
				else
				{
					ball_wise_score = ball_wise_score + cs.spin;
					score = score + ball_wise_score;
					cout << "Score of this ball is: " << ball_wise_score << endl;
					cout << "Total score uptil now is : " << score << endl;

				}
			}
			else if (cs.isStrike == 0)
			{
				cout << "Batsman out!!! Wicket!!!\n";
				wicket = wicket - 1;
				cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
				cout << "Next batsman from team 2 (computer) , come to bat" << endl;
				cout << "Score of this ball is: " << ball_wise_score << endl;
				cout << "Total score uptil now is : " << score << endl;
			}
		}
		else
		{
			cout << "\nSimple ball!\n";
			if (cs.isStrike == 1)
			{
				cout << "Your opponent has strike/played the ball.\n";
				ball_wise_score = 1;
				score = score + ball_wise_score;
				cout << "Score of this ball is: " << ball_wise_score << endl;
				cout << "Total score uptil now is : " << score << endl;
			}
			else if (cs.isStrike == 0)
			{
				cout << "Your opponent has not played the ball.\n";
				cout << "Batsman out!!! Wicket!!!\n";
				wicket = wicket - 1;
				cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
				cout << "Next batsman from team 2 (computer) , come to bat" << endl;
				cout << "Total score uptil now is : " << score << endl;
			}
		}
	}
	ball = ball - 1;
	cout << "Team 1 !!! You've left with " << ball << " balls now!\n";
}










void batting(ball_status s, ball_info_2 i2, computer_score cs, int bool_value)
{
	{
		if (i2.Entered_distanceV < s.Const_distanceV)
		{
			cout << "Noball!\n";
			score_2 = score_2 + 1;
			ball_2 = ball_2 + 1;
			cout << "Enter 1 if you want to strike the ball and 0 if not : ";
			cin >> bool_value;
			{
				if (bool_value == 1)
				{
					cout << "You've played the ball.\n";
					if (cs.noball == 1)
					{
						ball_wise_score_2 = ball_wise_score_2 + 4;
						score_2 = score_2 + ball_wise_score_2;
						no_of_fours_2 = no_of_fours_2 + 1;
						cout << "Its an amazing four!\n";
						cout << "Your score of this ball is: " << ball_wise_score_2 << endl;
						cout << "your total score uptil now is : " << score_2 << endl;
					}
					else if (cs.noball == 2)
					{
						ball_wise_score_2 = ball_wise_score_2 + 6;
						cout << "Its an amazing six!\n";
						score_2 = score_2 + ball_wise_score_2;
						no_of_sixes_2 = no_of_sixes_2 + 1;
						cout << "Score of this ball is: " << ball_wise_score_2 << endl;
						cout << "Total score uptil now is : " << score_2 << endl;
					}
					else
					{
						cout << "Batsman out!!! Wicket!!!\n";
						wicket_2 = wicket_2 - 1;
						cout << "Team 1(user) has " << wicket_2 << " wickets remainig now.\n";
						cout << "Next batsman from team 1(user) , come to bat" << endl;
						cout << "Your score of this ball is: " << ball_wise_score_2 << endl;
						cout << "Your total score uptil now is : " << score_2 << endl;
					}
				}
				else if (bool_value == 0)
				{
					cout << "You've not played the ball.\n";
					ball_wise_score_2 = 1;
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score_2 << endl;
				}
			}
		}
		else if (i2.Entered_distanceH > s.Const_distanceH)
		{
			cout << "Wide!\n";
			score_2 = score_2+ 1;
			cout << "Enter 1 if you want to strike the ball and 0 if not : ";
			cin >> bool_value;
			{
				if (bool_value == 1)
				{
					cout << "You've played the ball.\n";
					ball_wise_score_2 = ball_wise_score_2 + 4;
					no_of_fours_2 = no_of_fours_2 + 1;
					cout << "Its an amazing four!\n";
					score_2 = score_2 + ball_wise_score_2;
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score_2 << endl;
				}
				else if (bool_value == 0)
				{
					cout << "You've not played the ball.\n";
					ball_wise_score_2 = 1;
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score_2 << endl;
				}
			}
		}
		else if (i2.Entered_height > s.Const_height)
		{
			cout << "Bouncer!\n";
			cout << "Enter 1 if you want to strike the ball and 0 if not : ";
			cin >> bool_value;
			{
				if (bool_value == 1)
				{
					cout << "You've played the ball.\n";
					ball_wise_score_2 = ball_wise_score_2 + 6;
					cout << "Its an amazing six!\n";
					score_2 = score_2 + ball_wise_score_2;
					no_of_sixes_2 = no_of_sixes_2 + 1;
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score_2 << endl;
				}
				else if (bool_value == 0)
				{
					cout << "You've not played the ball.\n";
					cout << "Batsman out!!! Wicket!!!\n";
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score_2 << endl;
					wicket_2 = wicket_2 - 1;
					cout << "Team 1(user) has " << wicket_2 << " wickets remainig now.\n";
					cout << "Next batsman from team 1(user) , come to bat" << endl;
				}
			}
		}
		else if (i2.Entered_angle_of_deviation < (-5) || i2.Entered_angle_of_deviation>5)
		{
			cout << "Spin!\n";
			cout << "Enter 1 if you want to strike the ball and 0 if not : ";
			cin >> bool_value;
			{
				if (bool_value == 1)
				{
					cout << "You've played the ball.\n";
					{
						if ((cs.spin == 5) || (cs.spin == 3))
						{
							cout << "Batsman out!!! Wicket!!!\n";
							wicket = wicket - 1;
							cout << "Team 2 (computer) has " << wicket << " wickets remainig now.\n";
							cout << "Next batsman from team 2 (computer) , come to bat" << endl;
							cout << "Score of this ball is: " << ball_wise_score << endl;
							cout << "Total score uptil now is : " << score << endl;
						}
						else if (cs.spin == 4)
						{
							ball_wise_score = ball_wise_score + 4;
							cout << "Its an amazing four!\n";
							score = score + ball_wise_score;
							cout << "Score of this ball is: " << ball_wise_score << endl;
							cout << "Total score uptil now is : " << score << endl;
							no_of_fours = no_of_fours + 1;
						}
						else if (cs.spin == 6)
						{
							ball_wise_score = ball_wise_score + 6;
							cout << "Its an amazing six!\n";
							score = score + ball_wise_score;
							cout << "Score of this ball is: " << ball_wise_score << endl;
							cout << "Total score uptil now is : " << score << endl;
							no_of_sixes = no_of_sixes + 1;
						}

						else
						{
							ball_wise_score = ball_wise_score + cs.spin;
							score = score + ball_wise_score;
							cout << "Score of this ball is: " << ball_wise_score << endl;
							cout << "Total score uptil now is : " << score << endl;
						}
					}
				}
				else if (bool_value == 0)
				{
					cout << "You've not played the ball.\n";
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score << endl;
				}
			}
		}
		else
		{
			cout << "Simple ball!\n";
			cout << "Enter 1 if you want to strike the ball and 0 if not : ";
			cin >> bool_value;
			{
				if (bool_value == 1)
				{
					cout << "You've played the ball.\n";
					ball_wise_score_2 = 1;
					score_2 = score_2 + ball_wise_score_2;
					cout << "Your score of this ball is : " << ball_wise_score_2 << endl;
					cout << "Your total score uptill now is : " << score << endl;
				}
				else if (bool_value == 0)
				{
					cout << "You've not played the ball.\n";
					cout << "Batsman out!!! Wicket!!!\n";
					wicket_2 = wicket_2 - 1;
					cout << "Team 1(user) has " << wicket_2 << " wickets remainig now.\n";
					cout << "Next batsman from team 1(user) , come to bat" << endl;
				}
			}
		}
	}
	ball_2 = ball_2 - 1;
	cout << "Team 2 has " << ball_2 << " balls left\n";
}






void decisionOfGame()
{
	if (score > score_2)
	{
		cout << "Team 2 (computer) has won the match.\n";
	}
	else if (score < score_2)
	{
		cout << "Team 1 (user) has won the match.\n";
	}
}