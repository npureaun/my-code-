#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define X 10
#define Y 10

void menu();
void battle(int m, int i);
void select(int userp);
void pworselect(int userp);
void start(int tile[X][Y]);
void print(int tile[X][Y]);
int random(int z);
int work(int z);

int main()
{
	srand((unsigned)time(NULL));
	int tile[X][Y];
	int xu, xM, xm, xg;//x좌표 백업//
	int yu, yM, ym, yg;//y좌표 백업//
	int x = 0, y = 0;//좌표//
	char c;
	int a[4] = { 0 };
	int i; 
	int userp, user = 1;
	int bonus = 6;
	int score = 0;
	int vic = 0;
	int M=100,m = 100;
	int trun = 0;
	int up = 1;
	int t = 1;
	int lapf = 0;
	start(tile);
	for (i = 0; i < 4; i++)
	{
		while (1)
		{
			x = random(x);
			y = random(y);
			if (tile[x][y] == '.') {
				if (i == 0) {
					tile[x][y] = '#';
					xu = x;
					yu = y;
				}
				else if (i == 1) {
					tile[x][y] = 'M';
					xM = x;
					yM = y;
				}
				else if (i == 2) {
					tile[x][y] = 'm';
					xm = x;
					ym = y;
				}
				else if (i == 3) {
					tile[x][y] = 'G';
					xg = x;
					yg = y;
				}
				break;
			}
			else
				continue;
		}
	}
	while (1)
	{
		print(tile);
		do
		{
			char c;
			c = _getch();
			if (c == 'w') {
				if (xu - 1 >= 0 && xu - 1 < 10 && yu >= 0 && yu < 10) {
					tile[xu][yu] = '.';
					tile[xu - 1][yu] = '#';
					xu = xu - 1;
					yu = yu;
				}
				else { break; }
			}
			else if (c == 'a') {
				if (xu >= 0 && xu < 10 && yu - 1 >= 0 && yu - 1 < 10) {
					tile[xu][yu] = '.';
					tile[xu][yu - 1] = '#';
					xu = xu;
					yu = yu - 1;
				}
				else { break; }
			}
			else if (c == 'd') {
				if (xu >= 0 && xu < 10 && yu + 1 >= 0 && yu + 1 < 10) {
					tile[xu][yu] = '.';
					tile[xu][yu + 1] = '#';
					xu = xu;
					yu = yu + 1;
				}
				else { break; }
			}
			else if (c == 's') {
				if (xu + 1 >= 0 && xu + 1 < 10 && yu >= 0 && yu < 10) {
					tile[xu][yu] = '.';
					tile[xu + 1][yu] = '#';
					xu = xu + 1;
					yu = yu;
				}
				else { break; }
			}
			else {
				printf("\n방향을 입력하시오");
				continue;
			}
			break;
		} while (1);
		do
		{
			lapf = 0;
			lapf = work(lapf);
			if (lapf == 0) {
				if (xM - 1 >= 0 && xM - 1 < 10 && yM >= 0 && yM < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM - 1;
					yM = yM;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 1) {
				if (xM - 1 >= 0 && xM - 1 < 10 && yM + 1 >= 0 && yM + 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM - 1;
					yM = yM + 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 2) {
				if (xM >= 0 && xM < 10 && yM + 1 >= 0 && yM + 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM;
					yM = yM + 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 3) {
				if (xM + 1 >= 0 && xM + 1 < 10 && yM + 1 >= 0 && yM + 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM + 1;
					yM = yM + 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 4) {
				if (xM + 1 >= 0 && xM + 1 < 10 && yM >= 0 && yM < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM + 1;
					yM = yM;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 5) {
				if (xM + 1 >= 0 && xM + 1 < 10 && yM - 1 >= 0 && yM - 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM + 1;
					yM = yM - 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 6) {
				if (xM >= 0 && xM < 10 && yM - 1 >= 0 && yM - 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM;
					yM = yM - 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else if (lapf == 7) {
				if (xM - 1 >= 0 && xM - 1 < 10 && yM - 1 >= 0 && yM - 1 < 10) {
					if (tile[xu][yu] == tile[xM][yM])
						tile[xu][yu] = '#';
					else tile[xM][yM] = '.';
					xM = xM - 1;
					yM = yM - 1;
					tile[xM][yM] = 'M';
				}
				else { continue; }
			}
			else { continue; }
			if (tile[xm][ym] == tile[xM][yM])
				continue;
			else
				break;
		} while (1);
		do
		{
			lapf = 0;
			lapf = work(lapf);

			if (lapf == 0) {
				if (xm - 1 >= 0 && xm - 1 < 10 && ym >= 0 && ym < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm - 1;
					ym = ym;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 1) {
				if (xm - 1 >= 0 && xm - 1 < 10 && ym + 1 >= 0 && ym + 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm - 1;
					ym = ym + 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 2) {
				if (xm >= 0 && xm < 10 && ym + 1 >= 0 && ym + 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm;
					ym = ym + 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 3) {
				if (xm + 1 >= 0 && xm + 1 < 10 && ym + 1 >= 0 && ym + 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm + 1;
					ym = ym + 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 4) {
				if (xm + 1 >= 0 && xm + 1 < 10 && ym >= 0 && ym < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm + 1;
					ym = ym;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 5) {
				if (xm + 1 >= 0 && xm + 1 < 10 && ym - 1 >= 0 && ym - 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm + 1;
					ym = ym - 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 6) {
				if (xm >= 0 && xm < 10 && ym - 1 >= 0 && ym - 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm;
					ym = ym - 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			else if (lapf == 7) {
				if (xm - 1 >= 0 && xm - 1 < 10 && ym - 1 >= 0 && ym - 1 < 10) {
					if (tile[xu][yu] == tile[xm][ym])
						tile[xu][yu] = '#';
					else tile[xm][ym] = '.';
					xm = xm - 1;
					ym = ym - 1;
					tile[xm][ym] = 'm';
				}
				else { continue; }
			}
			if (tile[xm][ym] == tile[xM][yM])
				continue;
			if (tile[xM][yM] == '.')
				tile[xM][yM] = 'M';
			else
				break;
		} while (1);
		if (tile[xu][yu] == tile[xg][yg]) {
			print(tile);
			printf("승리");
			return 0;
		}
		else if (tile[xM][yM] == tile[xg][yg]) {
			printf("패배");
			break;
		}
		else if (tile[xm][ym] == tile[xg][yg]) {
			printf("패배");
			break;
		}
		else if (tile[xu][yu] == tile[xM][yM]) {
			while (1)
			{
				if (bonus == -1)
				{
					printf("패배");
					return 0;
				}
				battle(m, bonus);
				printf("유저의 공격력: %d\n", user);
				printf("--------------------------\n");
				menu();
				c = _getch();
				for (i = 0; i < 4; i++) {
					a[i] = rand() % 4 + 1;
				}
				if (c == 'w')
				{
					user += a[0] * up;
					i = a[0];
				}
				else if (c == 'a')
				{
					user += a[1] * up;
					i = a[1];
				}
				else if (c == 's')
				{
					user += a[2] * up;
					i = a[2];
				}
				else if (c == 'd')
				{
					user += a[3] * up;
					i = a[3];
				}
				pworselect(i);
				c = _getch();
				battle(m, bonus);
				printf("유저의 공격력: %d\n", user);
				printf("--------------------------\n");
				printf("카드를 고르십시오\n");
				printf("W  A  S  D\n");
				c = _getch();
				for (i = 0; i < 4; i++) {
					a[i] = rand() % 4 + 2;
				}
				userp = user;
				if (c == 'w')
				{
					userp *= a[0];
					i = a[0];
				}
				else if (c == 'a')
				{
					userp *= a[1];
					i = a[1];
				}
				else if (c == 's')
				{
					userp *= a[2];
					i = a[2];
				}
				else if (c == 'd')
				{
					userp *= a[3];
					i = a[3];
				}
				select(i);
				printf("데미지 %d\n", userp);
				m -= userp;
				if (m <= 0)
				{
					t++;
					M = M * 10;
					m = M;
					if (t <= 3)
					{
						bonus += 1 + t;
					}
					else {
						bonus += 1;
					}
					vic++;
					up *= 10;
					printf("승리");
					c = _getch();
					break;
				}
				c = _getch();
				bonus--;
				score++;
			}
			continue;
		}
		else if (tile[xu][yu] == tile[xm][ym]) {
			while (1)
			{
				if (bonus == -1)
				{
					printf("패배");
					return 0;
				}
				battle(m, bonus);
				printf("유저의 공격력: %d\n", user);
				printf("--------------------------\n");
				menu();
				c = _getch();
				for (i = 0; i < 4; i++) {
					a[i] = rand() % 4 + 1;
				}
				if (c == 'w')
				{
					user += a[0] * up;
					i = a[0];
				}
				else if (c == 'a')
				{
					user += a[1] * up;
					i = a[1];
				}
				else if (c == 's')
				{
					user += a[2] * up;
					i = a[2];
				}
				else if (c == 'd')
				{
					user += a[3] * up;
					i = a[3];
				}
				pworselect(i);
				c = _getch();
				battle(m, bonus);
				printf("유저의 공격력: %d\n", user);
				printf("--------------------------\n");
				printf("카드를 고르십시오\n");
				printf("W  A  S  D\n");
				c = _getch();
				for (i = 0; i < 4; i++) {
					a[i] = rand() % 4 + 2;
				}
				userp = user;
				if (c == 'w')
				{
					userp *= a[0];
					i = a[0];
				}
				else if (c == 'a')
				{
					userp *= a[1];
					i = a[1];
				}
				else if (c == 's')
				{
					userp *= a[2];
					i = a[2];
				}
				else if (c == 'd')
				{
					userp *= a[3];
					i = a[3];
				}
				select(i);
				printf("데미지 %d\n", userp);
				m -= userp;
				if (m <= 0)
				{
					t++;
					M = M * 10;
					m = M;
					if (t <= 3)
					{
						bonus += 1 + t;
					}
					else {
						bonus += 1;
					}
					vic++;
					up *= 10;
					printf("승리");
					c = _getch();
					break;
				}
				c = _getch();
				bonus--;
			}
			continue;
		}
	}
	return 0;
}
void menu()
{
	printf("정비시간입니다\n");
	printf("w, s, a, d중에 고르십시오\n");
}
void battle(int m, int i)
{
	system("cls");
	printf("                남은 턴: %d\n", i+1);
	printf("--------------------------\n");
	printf("몬스터의 체력: %d\n", m);
	printf("==========================\n");
}
void select(int userp)
{
	if (userp == 2)
	{
		printf("2배의 추가데미지!\n");
	}
	else if (userp == 3)
	{
		printf("3배의 추가데미지!\n");
	}
	else if (userp == 4)
	{
		printf("4배의 추가데미지!\n");
	}
	else if (userp == 5)
	{
		printf("5배의 추가데미지!\n");
	}
}
void pworselect(int userp)
{
	if (userp == 1)
	{
		printf("검을 강화합니다\n");
	}
	else if (userp == 2)
	{
		printf("힘을 강화합니다\n");
	}
	else if (userp == 3)
	{
		printf("마력을 강화합니다\n");
	}
	else if (userp == 4)
	{
		printf("기합을 강화합니다\n");
	}
}
void start(int tile[X][Y])
{
	int i, j;
	for (i = 0; i < X; i++)
		for (j = 0; j < Y; j++)
			tile[i][j] = '.';
}
int work(int z)
{
	return z = rand() % 8;
}
int  random(int z)
{
	z = rand() % 10;
	return z;
}
void print(int tile[X][Y])
{
	int i, j;
	system("cls");
	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			printf("%c", tile[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}