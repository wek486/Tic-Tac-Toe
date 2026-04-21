#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<string>
#include<windows.h>
//初始化地图
#define delay 1000/60
void initmap(char (*p)[15],int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 15; j++) {
			p[i][j] = '-';
		}
	}
}
//全局变量当前棋子
char current_piece = 'o';
//判断指定棋子的玩家是否获胜
bool Checkwin(char a,char (*p)[3]){
	
	if (p[0][0] == a && p[0][1] == a && p[0][2] == a)return true;
	if (p[1][0] == a && p[1][1] == a && p[1][2] == a)return true;
	if (p[2][0] == a && p[2][1] == a && p[2][2] == a)return true;
	if (p[0][0] == a && p[1][0] == a && p[2][0] == a)return true;
	if (p[0][1] == a && p[1][1] == a && p[2][1] == a)return true;
	if (p[0][2] == a && p[1][2] == a && p[2][2] == a)return true;
	if (p[0][0] == a && p[1][1] == a && p[2][2] == a)return true;
	if (p[2][0] == a && p[1][1] == a && p[0][2] == a)return true;
	return false;
}
//是否平局
bool CheckDraw(char (*p)[15],int row){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 15; j++) {
			if (p[i][j] == '-') {
				return false;
			}
		}
	}
	
	return true;
}
//棋盘网格
void DrawBoard() {
	line(0,200,600,200);
	line(0, 400, 600, 400);
	line(200,0,200, 600);
	line(400,0,400, 600);
}
//绘制棋子
void DrawPiece(char (*p)[15], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 15; j++) {
			switch (p[i][j]) {
			case ('o'):
				circle(200 * j + 100, 200 * i + 100, 100);
					break;
			case ('x'):
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200*(j+1),200*i,200*j,200*(i+1));
				break;
			case ('-'):
				break;
			default:
				break;
			}

		}
	}
}
//绘制棋子信息
void DrawPieceinfo() {
	std::string s="当前棋子类型："+std::string(1,current_piece);

	settextcolor(RGB(225, 175, 45));
	outtextxy(0,0,s.c_str());
}
int main(void) {
	initgraph(600, 600);
	bool running = true;
	ExMessage msg;
	BeginBatchDraw();
	releasecapture();
	char map[3][3];
	initmap(map,3);
	//游戏主循环
	while (running) {
		DWORD S = GetTickCount();
		//获取信息
		while (peekmessage(&msg)) {
			
			if (msg.message ==WM_LBUTTONDOWN ) {
				int x = (msg.x)/200;
				int y = (msg.y)/200;
				//尝试落子
				if (map[y][x]=='-') {
					map[y][x] = current_piece;
					if (current_piece == 'o') {
						current_piece = 'x';
					}
					else {
						current_piece = 'o';
					}
				}
			}
		} 
		//绘制图形
		cleardevice();
		DrawPieceinfo();
		DrawBoard();
		DrawPiece(map, 3);
		FlushBatchDraw();
		//信息处理
		if (Checkwin('o',map)){
			running = false;
			MessageBox(GetHWnd(),_T("o玩家获胜"),_T("游戏结束"),MB_OK);
		}
		else if (Checkwin('x',map) ){
			running = false;
			MessageBox(GetHWnd(), _T("x玩家获胜"), _T("游戏结束"), MB_OK);
		}
		else if (CheckDraw(map,3)) {
			running = false;
			MessageBox(GetHWnd(), _T("平局！"), _T("游戏结束！"),MB_OK);
		}
		DWORD now = GetTickCount()-S;
		if ((now) < delay) {
			Sleep(delay-now);
		}
	
	}
	EndBatchDraw();
	_getch();
	closegraph();
	return 0;
}