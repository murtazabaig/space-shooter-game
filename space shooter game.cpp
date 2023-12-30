#include<conio.h>                    
#include <iostream>                   
#include<cstdlib>                     
#include<cmath>                      
#include<time.h>         
#include<cstring>             
using namespace std;
const int rows = 20;
const int columns = 50;
char arr[rows][columns];
int randomiser;
int health = 10;
int stage = 1;
int stage2 = 2;
const char spaceship = '&';
const char borders = '*';
int scoring = 0;
char key;
static int speed = 0;
int check = 0;



void healthdec(int rows, int columns)    

{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[rows][columns] == '$')
				if (arr[rows][columns] == '!')
					health = health - 10;

		}
	}
	 cout << "\nscore =" << scoring ; 
		cout << "\t\t\t\thealth = " << health << endl;
}


void scoreincrease(int rows, int columns)  
{

	char ship = '$';
	static int speed_fire = 0;
	if (speed_fire >= 2)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (arr[rows][columns] == '#')
					if (arr[rows][columns] == '!')
					{
						arr[rows][columns] = ' ';
					}
				if (arr[i ][j] == '&' && arr[i  +1][j] == '#')
				{
					arr[i][j] = ' ';
					scoring = scoring + 2;
				}



			}
		}
	}
	
}

void sides(int _row, int _col)          
{

	

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i == 0 || i == rows - 1)
				{
					arr[i][j] = borders;
				}
				else if (j == 0 || j == columns - 1)
				{
					
					arr[i][j] = '*';
				}
				else
				{
					arr[i][j] = ' ';
				}


			}
		}
	arr[_row][_col] = spaceship;
}


void screen()    
{
	system("cls");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	if (scoring > 30)
	{
		swap(stage, stage2);
	}
	healthdec(rows, columns);
	scoreincrease(rows, columns);
	if (scoring < 30)
	{
		cout << "\n\t\t\tSTAGE : 1" << endl;
	}
	else if (scoring > 30)
	{
		cout << "\nSTAGE : 2" << endl;
	}
}
void movementofspaceship(char input)     
{

	if (input == 'u' || input == 'U')  //up
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				int temp = i - 1;
				if (arr[i][j] == spaceship)
				{
					swap(arr[temp][j], arr[i][j]);
					break;
				}
			}
		}
	}
	else if (input == 'h' || input == 'H')      //left
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (arr[i][j] == spaceship)
				{
					swap(arr[i][j - 1], arr[i][j]);

				}



			}
		}
	}
	else if (input == 'j' || input == 'J')   //down
	{

		for (int i = rows; i >= 0; i--)
		{
			for (int j = 0; j < columns; j++)
			{
				if (arr[i][j] == spaceship)
				{

					arr[i + 1][j] = '&';
					arr[i][j] = ' ';

					break;

				}
			}
		}
	}
	else if (input == 'K' || input == 'k')    //right
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (arr[i][j] == spaceship)
				{
					swap(arr[i][j + 1], arr[i][j]);
					break;
				}
			}
		}

	}
	if (input == ' ')   
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (arr[i][j] == spaceship)
				{
					arr[i - 1][j] = '0';
					break;
				}
			}
		}


	}

}


bool locationofenemy()   
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 49; j++)
		{
			if (arr[i][j] == '#')
			{
				return true;
			}
		}
	}      return false;
}
void enemysmovement()   
{

	static int speed = 0;
	speed++;
	if (!locationofenemy())
	{
		int pos = rand() % 48 + 1;
		arr[1][pos] = '#';

	}
	if (speed == 2)
	{
		speed = 0;
		for (int i = 19; i >= 0; i--)
		{
			for (int j = 48; j >= 0; j--)
			{
				int temp = i + 1;
				if (arr[i][j] == '#')
					if (i == 18)
					{
						arr[i][j] = ' ';
					}

				if (arr[i][j] == '#')
				{
					arr[i][j] = ' ';

					arr[temp][j] = '#';
				}

			}
		}
	}
}




void fireofenemy()    
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] == '#')
			{
				arr[i + 1][j] = '!';
				break;
			}
		}
	}
}

void enemysfiremovement() 

{

	{

		speed++;

		if (speed == 2)
		{
			speed = 0;
			for (int i = 19; i >= 0; i--)
			{
				for (int j = 48; j >= 0; j--)
				{
					if (arr[i][j] == '!')
						if (j == 48 || i == 18)
						{
							arr[i][j] = ' ';
						}

					if (arr[i + 1][j] == '&')
						if (arr[i][j] == '!')
						{
							arr[i][j] = ' ';
							health--;
							
						}

					if (arr[i][j] == '!')
					{
						arr[i][j] = ' ';
						arr[i + 1][j] = '!';
					}
					if (arr[i - 1][j] == '#' && arr[i][j] == '!')
					{
						arr[i - 1][j] = ' ';
					
					}
					if(arr[i][j]=='0')
						if (arr[i+1][j] == '#')
						{
							scoring++;
						}
				}
			}
		}
	}



}
void enemyremoval() //removing enemy
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (arr[i][j] == '#')
				if (arr[i][j] == '0')
				{   scoring++;
					arr[i][j] = ' ';
					

				}
			if (arr[i + 1][j] == '#' && arr[i][j] == '0')                   
			{
				arr[i][j] = ' ';
				scoring = scoring + 2;
			}

		}
	}
}



void shipfiremove()  // solving border intruption
{
	static int speed_fire = 0;
	speed_fire++;
	if (speed_fire >= 2)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (arr[i][j] == '0')
					if (i == 1)
					{
						arr[i][j] = ' ';

					}

				if (arr[i][j] == '0')
					if (i != 0)
					{
						arr[i][j] = ' ';
						arr[i - 1][j] = '0';
					}

			}
		}

	}
}
void enemymovementtwo()   //stage 2  
{
	static int speed = 2;
	speed++;
	if (!locationofenemy())
	{

		for (int i = 2; i < 4; i++)
		{
			srand(time(0));

			for (int j = 1; j < 9; j++)
			{
				srand(time(0));
				int position = rand() % 48 + 1;
				arr[position][i] = '#';
				arr[position + 1][i] = '#';
				arr[position + 2][i] = '#';
				arr[position + 3][i] = '#';
				arr[i][position] = '#';
				arr[i][position + 1] = '#';
				arr[i][position + 2] = '#';
				arr[i][position + 3] = '#';

			}
		}

	}
	if (speed == 2)
	{
		speed = 0;
		for (int i = 2; i <= 4; i++)
		{
			for (int j = 48; j >= 0; j--)
			{
				if (arr[i][j] == '#' && j == 48)                             
				{
					arr[i][j] = ' ';
				}
				if (arr[i][j] == '#')                                      
				{
					arr[i][j] = ' ';
					arr[i][j + 1] = '#';                                  			
				}
			}
		}
	}
}
void gifts()             //    gifts
{
	static	 int gs = 0; 
	gs++;

	
		int position2 = rand() % 48 + 1;                     
		int position1 = rand() % 18 + 1;                         
		arr[position1][position2] = '+';
	


	static int speed = 0; //static is used  the value don,t decrease
	speed++;


	if (speed == 3)
	{
		speed = 0;
		for (int i = 19; i >= 0; i--)
		{
			for (int j = 48; j >= 0; j--)
			{
				if (arr[i][j] == '+' && i == 18) //border intruption and  overlaping gifts solved
				{
					arr[i][j] = ' ';
				}

				if (arr[i + 1][j] == '&' && arr[i][j] == '+')               //score will increase on gifts     
				{
					arr[i][j] = ' ';
					scoring = scoring + 2;
				}

				if (arr[i][j] == '+')                                      //moving next index
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = '+';


				}
			}
		}
	}
}
int main()  // all functions called inside
{

	cout << "\t       HAMID & MURTAZA GAMES WORLD" << endl;
	cout << "\n\t\t1 for instructions" << endl;  //main menu
	cout << "\t\t2 FOR play game" << endl;

	cin >> check;
	if (check == 1)
	{

		cout << "- w a s d is for moving space ship" << endl;    //instructions
		cout << "- health zero = game over" << endl;
	}
	cin >> check;
	if (check == 2)
	{
	

		srand(time(0));
		int temp = 0;

		sides(15, 20);

		int em = 0;
		while (health >= 0) //check for health 
		{
			while (1)
			{

				if (scoring < 30)  //stage 1
				{
					em++;
					if (em == 7)
					{
						enemysmovement();
						em = 0;
					}
					fireofenemy();

					enemysfiremovement();
					screen();
					if (_kbhit())    //checks for a recent keystroke
					{
						int move = 0;
						move = _getch();
						movementofspaceship(move);
					}
			
					shipfiremove();
					system("cls");
					if (health <= 0)   //game over when health is zero
					{
						
						cout << "\n\t\t  GAME OVER!!!" << endl;
						cout << "\n\t\t  OH MY GOD! YOU LOST !!!" << endl;
						cout << "\n\t\t YOUR TOTAL SCORE IS : " << scoring << endl;
						system("pause");

					}

				}
				 if (scoring > 30)  //stage 2
				{
					
					
					em++;
					if (em == 7)
					{
						enemymovementtwo();
						em = 0;
					} //gifts();
					fireofenemy();
					gifts();

					enemysfiremovement();
					screen();
					if (_kbhit())
					{
						int move = 0;
						move = _getch();
						movementofspaceship(move);
					}
				
					shipfiremove();
					system("cls");
					if (health <= 0)
					{

						

						cout << "\n\n\t\t  GAME OVER" << endl;
						cout << "\n\n\t\t  YOU LOST !!!" << endl;
						cout << "\n\n\t\ttotal score is : " << scoring << endl;
						system("pause");

					}
					if (scoring >= 45)   
					{
					
						system("cls");
						
						cout << "\n\n\t\tYOU WON THE GAME!!!!" << endl;
				
						cout << "\n\tcongratulations!!!!" << endl;
						cout << "\n\n\t\tyour total score is : " <<scoring<< endl;

						system("pause");
					}
				}
			}
		}
	}

}