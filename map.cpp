#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void get_data(int map_num[]);
void print_step();
void print_map(WINDOW* win1, int map_num[], int row, int col);
void print_level(int level);


int main()
{
	WINDOW *map_loc;
	int map_num[63];	 
	get_data(map_num);
	
	initscr();
	start_color();
	resize_term(100,100);	//나중에 다시 지정

	init_pair(1, COLOR_WHITE, COLOR_RED);
	
	border('*','*','*','*','*','*','*','*');
	refresh();
	getch();
	
		

	map_loc = newwin(20,20,10,10);		//행,열, 윈도우 시작 y좌표, x
	wbkgd(map_loc, COLOR_PAIR(1));
	wattron(map_loc, COLOR_PAIR(1));
	print_map(map_loc, map_num, 7, 9);	//WINDOW*, int[], int, int
	
	wborder(map_loc,'@','@','@','@','@','@','@','@');
	wrefresh(map_loc);

	getch();
	delwin(map_loc);	//새 윈도우 소멸
	endwin();

	return 0;
}

void print_level(int level)
{
	WINDOW *level_win;
	char a = char(level+48);
	const char* tmp = &a;
	init_pair(2, COLOR_RED, COLOR_WHITE);
	level_win = newwin(10,10,1,1);
	wbkgd(level_win, COLOR_PAIR(2));
	wattron(level_win, COLOR_PAIR(2));
	wborder(level_win, '*','*','*','*','*','*','*','*');
	mvwprintw(level_win, 1, 1, tmp);

	wrefresh(level_win);
	getch();
}

void get_data(int map_num[])
{
	static int level = 0;
	level++;		//레벨에 따른 input(숫자).txt 불러오기
	string tmp;
	tmp += char(level+48);
	print_level(level);
	string filePath = "input"+tmp+".txt";		//파일 이름
	ifstream ifs;
	ifs.open(filePath);
	int arr_size = 7*9;	//동적배열을 사용해야 할
	int cnt = 0;
	if(ifs.is_open()){
		while(!ifs.eof()){
			ifs>>map_num[cnt];
			cnt++;
		}
	}
	
}

void print_map(WINDOW* win1, int map_num[], int row, int col)
{
	int x, y;
	int cnt = 0;
	for(int i = 1; i<=col; i++)
	{
		for(int j = 1; j<=row; j++)
		{
			y = i+1;
			x = j+1;
			if(map_num[cnt] == 1)
				mvwprintw(win1, y, x, "1");
			else if(map_num[cnt] == 2)
				mvwprintw(win1, y, x, "2");
			else if(map_num[cnt] == 3)
				mvwprintw(win1, y, x, "3");
			else if(map_num[cnt] == 4)
				mvwprintw(win1, y, x, "4");
			else if(map_num[cnt] == 0)
				mvwprintw(win1, y, x, "0");
			cnt++;
		}
	}
}
