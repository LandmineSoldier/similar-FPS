#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#pragma warning(disable:4996)

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#define MAX 49

#define True 1
#define False 0

int flat[MAX][MAX] = { 0, };
float max_x = 0, min_x = 0;
float max_y = 0, min_y = 0;
int aim_pos[3] = { 0, };
float z[8] = { 0, };

enum colorName
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void color(int bgColor, int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

int lining(float* px1, float* px2, float* py1, float* py2, float max_x, float min_x, float max_y, float min_y) // x1,y1의 좌표와 x2,y2의 좌표를 선으로 이음
{
	float x, y, a;
	if (*px2 - *px1 >= *py2 - *py1)
	{
		for (int i = min_x; i <= max_x; i++)
		{
			if ((*py2 - *py1) < (*px2 - *px1)) {
				a = ((*py2 - *py1) / (*px2 - *px1));
				if ((*px2 - *px1) == 0)
					a = 0;
				y = a * (i - *px1) + 0.5 + *py1;
				flat[(int)y][i] = 1;
			}
			else {
				a = ((*py1 - *py2) / (*px1 - *px2));
				if ((*px1 - *px2) == 0)
					a = 0;
				y = a * (i - *px2) + 0.5 + *py2;
				flat[(int)y][i] = 1;
			}
		}
		for (int i = min_y; i <= max_y; i++)
		{
			if ((*py2 - *py1) > (*px2 - *px1)) {
				a = ((*px2 - *px1) / (*py2 - *py1));
				if ((*py2 - *py1) == 0)
					a = 0;
				x = a * (i - *py1) + 0.5 + *px1;
				flat[i][(int)x] = 1;
			}
			else {
				a = ((*px1 - *px2) / (*py1 - *py2));
				if ((*py1 - *py2) == 0)
					a = 0;
				x = a * (i - *py2) + 0.5 + *px2;
				flat[i][(int)x] = 1;
			}
		}
	}

	else if (*py2 - *py1 > * px2 - *px1)
	{
		for (int i = min_x; i <= max_x; i++)
		{
			if ((*py2 - *py1) < (*px2 - *px1)) {
				a = ((*py2 - *py1) / (*px2 - *px1));
				if ((*px2 - *py1) == 0)
					a = 0;
				y = a * (i - *px1) + 0.5 + *py1;
				flat[(int)y][i] = 1;
			}
			else {
				a = ((*py1 - *py2) / (*px1 - *px2));
				if ((*px1 - *px2) == 0)
					a = 0;
				y = a * (i - *px2) + 0.5 + *py2;
				flat[(int)y][i] = 1;
			}
		}
		for (int i = min_y; i <= max_y; i++)
		{
			if ((*py2 - *py1) > (*px2 - *px1)) {
				a = ((*px2 - *px1) / (*py2 - *py1));
				if ((*py2 - *py1) == 0)
					a = 0;
				x = a * (i - *py1) + 0.5 + *px1;
				flat[i][(int)x] = 1;
			}
			else {
				a = ((*px1 - *px2) / (*py1 - *py2));
				if ((*py1 - *py2) == 0)
					a = 0;
				x = a * (i - *py2) + 0.5 + *px2;
				flat[i][(int)x] = 1;
			}
		}
	}
}

int print_map(int under) // FLAT 맵 출력
{
	int start1 = 0, start2 = 0;
	int end1 = 0, end2 = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			//if (j <= MAX / 6 * 5 && j >= MAX / 6 * 1)
			//{
			for (int i = under + 1; i < MAX - 1; i++)
			{
				/*int count = 0;
				int a;
				for (int j = 0; j < MAX; j++)
				{
					if (flat[i][j] == 1)
						count++;
				}

				if (count > 1)
					a = 1;
				else if (count == 1)
					a = 0;


				for (int j = a; j < MAX - 1; j++)
				{
					if (flat[i][j] == 1)
					{
						start1 = j;
						for (j = start1 + 1; j < MAX; j++)
						{
							if (flat[i][j] == 1)
							{
								end1 = j;
								break;
							}
						}
						break;
					}
				}
				for (int j = MAX - 2; j >= a; j--)
				{
					if (flat[i][j] == 1)
					{
						start2 = j;
						for (j = MAX - 1; j >= start2; j--)
						{
							if (flat[i][j] == 1)
							{
								end2 = j;
								break;
							}
						}
						break;
					}
				}
				for (int j = start1 + 1; j < end1; j++)
				{
					flat[i][j] = 30;
				}
				for (int j = start2 - 1; j >= end2; j--)
				{
					flat[i][j] = 30;
				}*/
			}
			if (flat[i][j] == 0)
			{
				color(BLACK, BLACK);
				printf("  ");
			}
			else if (flat[i][j] == 1)
			{
				if (z[4] < -1)
					color(D_GRAY, D_GRAY);
				else if (z[4] < 4)
					color(GRAY, GRAY);
				else
					color(WHITE, WHITE);
				printf("■");
			}
			else if (flat[i][j] == 3)
			{
				if (aim_pos[1] == 1)
				{
					if (z[4] < -1)
						color(D_GRAY, GREEN);
					else if (z[4] < 4)
						color(GRAY, GREEN);
					else
						color(WHITE, GREEN);
				}
				else
					color(BLACK, GREEN);
				printf("─ ");
			}
			else if (flat[i][j] == 4)
			{
				if (aim_pos[2] == 1)
				{
					if (z[4] < -1)
						color(D_GRAY, GREEN);
					else if (z[4] < 4)
						color(GRAY, GREEN);
					else
						color(WHITE, GREEN);
				}
				else
					color(BLACK, GREEN);
				printf("─ ");
			}
			else if (flat[i][j] == 5)
			{
				if (aim_pos[0] == 1)
				{
					if (z[4] < -1)
						color(D_GRAY, GREEN);
					else if (z[4] < 4)
						color(GRAY, GREEN);
					else
						color(WHITE, GREEN);
				}
				else
					color(BLACK, GREEN);
				printf("┼ ");
			}
			//}
			//else if (flat[i][j] == 30)
			//{
			//	color(BLACK, WHITE);
			//	printf("# ");
			//}
		}

		color(BLACK, WHITE);
		printf("\n");
	}
}

int MAXorMIN(float x1, float x2, float  y1, float y2) // x1과 x2, y1과 y2의 위치 정리
{
	max_x = x2 >= x1 ?
		x2 : x1;
	min_x = x1 <= x2 ?
		x1 : x2;

	max_y = y2 >= y1 ?
		y2 : y1;
	min_y = y1 <= y2 ?
		y1 : y2;
}

int flatCLEAR() // 클린업
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			flat[i][j] = 0;
		}
	}
}

int main(void)
{

	float x[8];
	float y[8];

	x[0] = 0;
	y[0] = 0;

	x[1] = 0;
	y[1] = MAX - 1;

	max_x = x[1] >= x[0] ? // x0과 x1, y0과 y1을 지정하여 1차함수를 사용해 선을 연결함
		x[1] : x[0];
	min_x = x[0] <= x[1] ?
		x[0] : x[1];

	max_y = y[1] >= y[0] ?
		y[1] : y[0];
	min_y = y[0] <= y[1] ?
		y[0] : y[1];

	lining(&x[0], &x[1], &y[0], &y[1], max_x, min_x, max_y, min_y); // 선 연결

	x[2] = MAX - 1;
	y[2] = MAX - 1;

	MAXorMIN(x[1], x[2], y[1], y[2]);
	lining(&x[1], &x[2], &y[1], &y[2], max_x, min_x, max_y, min_y);

	x[3] = MAX - 1;
	y[3] = 0;

	MAXorMIN(x[2], x[3], y[2], y[3]);
	lining(&x[2], &x[3], &y[2], &y[3], max_x, min_x, max_y, min_y);

	MAXorMIN(x[3], x[0], y[3], y[0]);
	lining(&x[3], &x[0], &y[3], &y[0], max_x, min_x, max_y, min_y);


	x[4] = MAX / 3;
	y[4] = MAX / 3;

	x[5] = MAX / 3;
	y[5] = MAX / 3 * 2;

	max_x = x[5] >= x[4] ?
		x[5] : x[4];
	min_x = x[4] <= x[4] ?
		x[4] : x[5];

	max_y = y[5] >= y[4] ?
		y[5] : y[4];
	min_y = y[4] <= y[5] ?
		y[4] : x[5];

	lining(&x[4], &x[5], &y[4], &y[5], max_x, min_x, max_y, min_y);

	x[6] = MAX / 3 * 2;
	y[6] = MAX / 3 * 2;

	MAXorMIN(x[5], x[6], y[5], y[6]);
	lining(&x[5], &x[6], &y[5], &y[6], max_x, min_x, max_y, min_y);

	x[7] = MAX / 3 * 2;
	y[7] = MAX / 3;

	MAXorMIN(x[6], x[7], y[6], y[7]);
	lining(&x[6], &x[7], &y[6], &y[7], max_x, min_x, max_y, min_y);

	MAXorMIN(x[7], x[4], y[7], y[4]);
	lining(&x[7], &x[4], &y[7], &y[4], max_x, min_x, max_y, min_y);


	MAXorMIN(x[0], x[4], y[0], y[4]);
	lining(&x[0], &x[4], &y[0], &y[4], max_x, min_x, max_y, min_y);
	MAXorMIN(x[1], x[5], y[1], y[5]);
	lining(&x[1], &x[5], &y[1], &y[5], max_x, min_x, max_y, min_y);
	MAXorMIN(x[2], x[6], y[2], y[6]);
	lining(&x[2], &x[6], &y[2], &y[6], max_x, min_x, max_y, min_y);
	MAXorMIN(x[3], x[7], y[3], y[7]);
	lining(&x[3], &x[7], &y[3], &y[7], max_x, min_x, max_y, min_y);



	print_map((int)y[5]);
	while (True) // 내부 사각형 이동시키기
	{
		//if ((kbhit()))
		//{
		int move = _getch(); // 화살표값 받음
		if (move != 224) // 쓰레기 화살표값 제외
		{
			switch (move) // p1 무빙
			{
			case UP:
				if ((x[7] - x[4] <= MAX / 3 * 2) && (x[4] != 0 && x[7] != MAX - 1)) // 소형 사각형 확대
				{
					y[4]--;  // 좌측 상단
					x[4]--;


					y[5]++;  // 좌측 하단
					x[5]--;

					y[6]++;  // 우측 하단
					x[6]++;

					y[7]--;  // 우측 상단
					x[7]++;

					for (int i = 4; i < 8; i++)
						z[i]++;
				}
				break;
			case RIGHT:
				if (x[4] != 0 || x[5] != 0) // 소형 사각형 왼쪽으로 이동
				{
					if (x[7] - x[4] >= MAX / 3 * 2)
					{
						if ((x[4] == 1 || x[5] == 1))
						{
							x[4]--;
							x[5]--;
							x[6]--;
							x[7]--;
						}
						else if ((x[4] == 2 || x[5] == 2))
						{
							x[4] -= 2;
							x[5] -= 2;
							x[6] -= 2;
							x[7] -= 2;
						}
						else
						{
							x[4] -= 3;
							x[5] -= 3;
							x[6] -= 3;
							x[7] -= 3;
						}
					}
					else
					{
						if ((x[4] == 1 || x[5] == 1) || (x[4] == 2 || x[5] == 2))
						{
							x[4]--;
							x[5]--;
							x[6]--;
							x[7]--;
						}
						else
						{
							x[4] -= 2;
							x[5] -= 2;
							x[6] -= 2;
							x[7] -= 2;
						}
					}
				}
				break;
			case LEFT:
				if (x[6] != MAX - 1 || x[7] != MAX - 1) // 소형 사각형 오른쪽으로 이동
				{
					if (x[7] - x[4] >= MAX / 3 * 2)
					{
						if ((x[6] == MAX - 2 || x[7] == MAX - 2))
						{
							x[4]++;
							x[5]++;
							x[6]++;
							x[7]++;
						}
						else if ((x[6] == MAX - 3 || x[7] == MAX - 3))
						{
							x[4] += 2;
							x[5] += 2;
							x[6] += 2;
							x[7] += 2;
						}
						else
						{
							x[4] += 3;
							x[5] += 3;
							x[6] += 3;
							x[7] += 3;
						}
					}
					else
					{
						if ((x[6] == MAX - 2 || x[7] == MAX - 2))
						{
							x[4]++;
							x[5]++;
							x[6]++;
							x[7]++;
						}
						else
						{
							x[4] += 2;
							x[5] += 2;
							x[6] += 2;
							x[7] += 2;
						}
					}
				}
				break;
			case DOWN:
				if ((y[5] != MAX - 1 || y[6] != MAX - 1) && x[4] + 10 != x[7]) // 소형 사각형 축소
				{
					y[4]++;
					x[4]++;

					y[5]--;
					x[5]++;

					y[6]--;
					x[6]--;

					y[7]++;
					x[7]--;

					for (int i = 4; i < 8; i++)
						z[i]--;
				}
				break;
			}
			//}
			flatCLEAR();

			MAXorMIN(x[0], x[1], y[0], y[1]);
			lining(&x[0], &x[1], &y[0], &y[1], max_x, min_x, max_y, min_y);
			MAXorMIN(x[1], x[2], y[1], y[2]);
			lining(&x[1], &x[2], &y[1], &y[2], max_x, min_x, max_y, min_y);
			MAXorMIN(x[2], x[3], y[2], y[3]);
			lining(&x[2], &x[3], &y[2], &y[3], max_x, min_x, max_y, min_y);
			MAXorMIN(x[3], x[0], y[3], y[0]);
			lining(&x[3], &x[0], &y[3], &y[0], max_x, min_x, max_y, min_y);

			MAXorMIN(x[4], x[5], y[4], y[5]);
			lining(&x[4], &x[5], &y[4], &y[5], max_x, min_x, max_y, min_y);
			MAXorMIN(x[5], x[6], y[5], y[6]);
			lining(&x[5], &x[6], &y[5], &y[6], max_x, min_x, max_y, min_y);
			MAXorMIN(x[6], x[7], y[6], y[7]);
			lining(&x[6], &x[7], &y[6], &y[7], max_x, min_x, max_y, min_y);
			MAXorMIN(x[7], x[4], y[7], y[4]);
			lining(&x[7], &x[4], &y[7], &y[4], max_x, min_x, max_y, min_y);

			MAXorMIN(x[0], x[4], y[0], y[4]);
			lining(&x[0], &x[4], &y[0], &y[4], max_x, min_x, max_y, min_y);
			MAXorMIN(x[1], x[5], y[1], y[5]);
			lining(&x[1], &x[5], &y[1], &y[5], max_x, min_x, max_y, min_y);
			MAXorMIN(x[2], x[6], y[2], y[6]);
			lining(&x[2], &x[6], &y[2], &y[6], max_x, min_x, max_y, min_y);
			MAXorMIN(x[3], x[7], y[3], y[7]);
			lining(&x[3], &x[7], &y[3], &y[7], max_x, min_x, max_y, min_y);

			if (flat[MAX / 2][MAX / 2] == 0)
				aim_pos[0] = 0;
			else
				aim_pos[0] = 1;

			if (flat[MAX / 2][MAX / 2 + 1] == 0)
				aim_pos[1] = 0;
			else
				aim_pos[1] = 1;

			if (flat[MAX / 2][MAX / 2 - 1] == 0)
				aim_pos[2] = 0;
			else
				aim_pos[2] = 1;

			flat[MAX / 2][MAX / 2] = 5; // +
			flat[MAX / 2][MAX / 2 + 1] = 3; // 좌측 -
			flat[MAX / 2][MAX / 2 - 1] = 4; // 우측 -

			system("cls");
			print_map((int)y[5]);
		}
	}


}
