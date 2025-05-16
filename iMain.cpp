#include "iGraphics.h"
#define SCREENWIDTH 1530
#define SCREENHEIGHT 785
#define PERWIDTH 153
#define lowerBackGroundSpeed 68
#define JUMPLIMIT 200
#define BANDORNUM 25
#define SHAPNUM 20
#define FIRENUM 2
#define NSTAR 5



struct buttoncord
{
	int x;
	int y;

}bcord[5];

int mposx, mposy;
int gamestate = -1;
char homemenu[15] = "menu\\menu1.bmp";
char button[5][20] = { "button\\12.bmp", "button\\13.bmp", "button\\10.bmp", "button\\14.bmp", "button\\15.bmp" };
char pausemenu[25] = "pmenu\\pausemenu.bmp";
char pausebutton[5][20] = { "pmenu\\1.bmp", "pmenu\\2.bmp", "pmenu\\3.bmp", "pmenu\\3.bmp" };
char highscore[25] = "pmenu\\highscore.bmp";
char credits[25] = "pmenu\\credits2.bmp";
char instruction[25] = "pmenu\\ins.bmp";
char out[25] = "pmenu\\exit2.bmp";
//backbutton
struct backbuttoncord
{
	int bx;
	int by;
}bbcord[1];
struct yesbuttoncord
{
	int yx;
	int yy;
}ycord[1];
struct nobuttoncord
{
	int nx;
	int ny;
}ncord[1];
char no[5][20] = { "button\\no.bmp" };
char yes[5][20] = { "button\\yes.bmp" };
char back[5][20] = { "button\\16.bmp" };

void menu()
{
	if (gamestate == -1)
	{
		iShowBMP(0, 0, homemenu);
		for (int i = 0; i<5; i++)
		{
			iShowBMP2(bcord[i].x, bcord[i].y, button[i], 0);
		}
	}
	
	else if (gamestate == 1)
	{
		iShowBMP(0, 0, highscore);
		//for (int i=1; i <1; )
		
			iShowBMP2(bbcord[1].bx, bbcord[1].by, back[0], 0);
		
		
	}
	else if (gamestate == 2)
	{
		iShowBMP(0, 0, instruction);
		iShowBMP2(bbcord[1].bx, bbcord[1].by, back[0], 0);


	}
	else if (gamestate == 3)
	{
		iShowBMP(0, 0, credits);
		iShowBMP2(bbcord[1].bx, bbcord[1].by, back[0], 0);

		
	}
	else if (gamestate == 4)
	{
		iShowBMP(0, 0, out);
		iShowBMP2(bbcord[1].bx, bbcord[1].by, back[0], 0);
		iShowBMP2(ycord[1].yx, ycord[1].yy, yes[0], 0);
		iShowBMP2(ncord[1].nx, ncord[1].ny, no[0], 0);

	}
	else
	{

	}

}
	






int mousepos_x = -1, mousepos_y = -1;
int mouseDragPos_x = -1, mouseDragPos_y = -1;
int mouseClickPos_x = -1, mouseClickPos_y = -1;
char mouse_button[20] = "", mouse_state[20] = "";
char keyButton = '\0', spcial_key = '\0';
int circle_x = 0, circle_y = 0;
int circleStatus = false;
int r = 255, g = 255, b = 255;
int x = 10, y = 10;
int dx = 10, dy = 10;

bool jump = false;
bool jup = false;
int jCor = 0;

int pic_x = 900, pic_y = 100;

char Running[8][20] = { "char\\1.bmp", "char\\2.bmp", "char\\3.bmp", "char\\4.bmp", "char\\5.bmp", "char\\6.bmp", "char\\7.bmp", "char\\8.bmp" };
char Kakajump[3][20] = { "char\\j1.bmp", "char\\j2.bmp", "char\\j3.bmp" };
int rIn = 0;
int k_x = 110;
int k_y = 135;

int k_f_x = 200;
int k_f_y = 80;
char fighting[6][20] = { "char\\f1.bmp", "char\\f2.bmp", "char\\f3.bmp" };
int fIn = 0;
bool fight = false;

int k_p_x = 200;
int k_p_y = 80;
char pow_arr[3][20] = {  "char\\p2.bmp",  "char\\p4.bmp", "char\\p6.bmp", };
//char pow_arr[7][20] = { "char\\p1.bmp", "char\\p2.bmp", "char\\p3.bmp", "char\\p4.bmp","char\\p5.bmp", "char\\p6.bmp", "char\\p7.bmp" };
int pIn = 0;
bool power = false;
char pow_ball[4][20] = { "char\\pb1.bmp", "char\\pb2.bmp" };
int p_bIn = 0;
bool p_bS = false;
int p_b_x;
int p_b_y;

char nStar[3][20] = { "char\\n1.bmp", "char\\n2.bmp", "char\\n3.bmp" };
int nIn = 0;
bool nS = false;
int n_x;
int n_y;

void position_of_Kakashi()
{
	if (jump)
	{
		if (fight)
		{
			//k_f_x = jCor;
			//jump = false;
			//n_y = jCor+k_y+50;
			iShowBMP2(k_x, k_y+jCor, fighting[fIn], 255);
			iShowBMP2(n_x, n_y, nStar[nIn], 0);
		}
		/*else if (nS)
		{
			iShowBMP2(n_x, n_y + jCor, nStar[nIn], 0);
		}*/
		else if (jup)
		{

			iShowBMP2(k_x, k_y + jCor, Kakajump[0], 255);
			iShowBMP2(k_x, k_y + jCor, Kakajump[1], 255);
		}
		else
		{
			iShowBMP2(k_x, k_y+jCor, Kakajump[2], 255);
		}
	}
	else
	{
		if (fight)
		{
			k_f_x = 200;
			k_f_y = 80;
			//nS = true;
			iShowBMP2(k_x, k_y, fighting[fIn], 255);
		}
		else if (power)
		{
			k_p_x = 200;
			k_p_y = 80;
			//nS = true;
			iShowBMP2(k_x, k_y, pow_arr[pIn], 255);
		}
		else
		{
			iShowBMP2(k_x, k_y, Running[rIn], 255);
		}

	}
	if (nS)
	{
		iShowBMP2(n_x, n_y, nStar[nIn], 0);
	}
	if (p_bS)
	{
		iShowBMP2(p_b_x, p_b_y, pow_ball[p_bIn], 255);
	}
}

//BG


char upperBackGround[10][15] = { "stage1\\11.bmp", "stage1\\12.bmp", "stage1\\13.bmp", "stage1\\14.bmp", "stage1\\15.bmp", "stage1\\16.bmp", "stage1\\17.bmp", "stage1\\18.bmp", "stage1\\19.bmp", "stage1\\20.bmp" };
struct background
{
	int x = 0;
	int y = 0;
};
background upperBackGround1[10];

void showBG()
{
	for (int i = 0; i < 10; i++)
	{
		iShowBMP(upperBackGround1[i].x, upperBackGround1[i].y, upperBackGround[i]);
	}
}



int b_x = 1350;
int b_y = 130;
int bIn = 0;
char bbandor[8][20] = { "char\\b1.bmp", "char\\b2.bmp", "char\\b3.bmp", "char\\b4.bmp", "char\\b5.bmp", "char\\b6.bmp", "char\\b7.bmp", "char\\b8.bmp" };
//char bandor_t[1][20] = {"char\\b9.bmp"};
int b_tIn = 0;
int bt_x = 1250;
int bt_y = 110;

struct bandor{
	int b_x;
	int b_y;
	int bIn;
	bool bShow;
};

bandor enemy[BANDORNUM];

char shaap[5][20] = { "char\\en1.bmp", "char\\en2.bmp", "char\\en3.bmp", "char\\en4.bmp", "char\\en5.bmp" };
int sIn = 0;
int s_x = 1350;
int s_y = 130;


struct Shap{
int s_x = 1350;
int s_y = 130;
int sIn;
bool sShow;
};

Shap enemy1[SHAPNUM];

char fire_arr[6][20] = { "snake\\f1.bmp", "snake\\f2.bmp", "snake\\f3.bmp", "snake\\f4.bmp", "snake\\f5.bmp", "snake\\f6.bmp" };
int fireIn = 0;
int f_x = 1350;
int f_y = 120;


struct fire{
	int f_x;
	int f_y;
	int fireIn;
	bool fShow;
};

fire enemy2[FIRENUM];

void enemyMove()
{
	//bandor
	for (int i = 1; i<BANDORNUM; i++)
	{
		if (enemy[i].bShow == true)
		{
			iShowBMP2(enemy[i].b_x, enemy[i].b_y, bbandor[enemy[i].bIn], 0);
		}
	}

	//shaap
	for (int i = 1; i<SHAPNUM; i++)
	{
		if (enemy1[i].sShow == true)
		{
			iShowBMP2(enemy1[i].s_x, enemy1[i].s_y, shaap[enemy1[i].sIn], 0);
		}
	}

	//snake
	for (int i = 1; i<FIRENUM; i++)
	{
		if (enemy2[i].fShow == true)
		{
			iShowBMP2(enemy2[i].f_x, enemy2[i].f_y, fire_arr[enemy2[i].fireIn], 255);
		}
	}
}

//sound
bool soundOn = true;
char sound[50] = {"music\\Naruto Soundtrack - Naruto Main Theme.wav"};
void sou();
void music();




//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	showBG();
	position_of_Kakashi();
	enemyMove();
	//enterName();

	menu();
	//iShowBMP2(700, 120, "char\\en1.bmp", 0);

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	mouseDragPos_x = mx;
	mouseDragPos_y = my;
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	mousepos_x = mx;
	mousepos_y = my;
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//fight = true;
		for (int i = 0; i<5; i++)
		{
			if (mx >= bcord[i].x && mx <= bcord[i].x + 300 && my >= bcord[i].y && my <= bcord[i].y + 50)
			{
				gamestate = i;
			}
			
		}
		//backbutton
		if (mx >= bbcord[1].bx && mx <= bbcord[1].bx + 300 && my >= bbcord[1].by && my <= bbcord[1].by + 50)
		{
			gamestate = -1;
		}
		//yes
		if (mx >= ycord[1].yx && mx <= ycord[1].yx + 300 && my >= ycord[1].yy && my <= ycord[1].yy + 50)
		{
			gamestate = -3;
		}
		//no
		if (mx >= ncord[1].nx && mx <= ncord[1].nx + 300 && my >= ncord[1].ny && my <= ncord[1].ny + 50)
		{
			gamestate = -1;
		}
		
		if (!fight){
			fight = true;
			nS = true;
			n_x = k_x;
			if (jump)
			{
				n_y = jCor + k_y + 50;
			}
			else
			{
				n_y = k_y + 50;
			}
		}
		
	}
	
	
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (!power){
			power = true;
			p_bS = true;
			p_b_x = k_x;
			p_b_y = k_y + 50;
		}
		if (jump)
		{
			p_bS = false;
			power = false;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		fight = false;
		//nS = false;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		power = false;
	}

	mouseClickPos_x = mx;
	mouseClickPos_y = my;
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'a')
	{
		k_x -= 20;
	}

	if (key == 'd')
	{
		k_x += 20;
	}
	
	if (key == ' ')
	{
		if (!jump){
			jump = true;
			jup = true;
		}
	}

	if (key == 'k')
	{
		music();
	}
	
	keyButton = key;
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}

	spcial_key = key;
	
}

void run()
{
	rIn++;
	if (rIn >= 8)
	{
		rIn = 0;
	}
}

void ninjaStar()
{

	nIn++;
	if (nS)
	{
		n_x = n_x + 90;
		if (n_x >= SCREENWIDTH)
		{
			nS = false;
			n_x = k_x;
			//n_y = k_y + 40;
		}
	}

	if (nIn >= 3)
	{
		nIn = 0;
	}
}

void fig()
{
	fIn++;
	if (fIn >= 3)
	{
		fIn = 0;
	}
}

void pow_fun()
{

	pIn++;
	if (pIn >= 3)
	{
		pIn = 0;
	}
}

void p_b_function()
{

	p_bIn++;
	if (p_bS)
	{
		p_b_x = p_b_x + 90;
	}

	if (p_bIn >= 2)
	{
		p_bIn = 0;
	}
}

void setEnemy()
{
	//bandor
	for (int i = 1; i <= BANDORNUM; i++)
	{
		enemy[i].b_x = SCREENWIDTH + rand() % 100000000;
		enemy[i].b_y = b_y;
		enemy[i].bIn = rand() % 8;
		enemy[i].bShow = true;
	}

	
	//shap
	for (int i = 1; i <= SHAPNUM; i++)
	{
		enemy1[i].s_x = SCREENWIDTH + rand() % 100000000000;
		enemy1[i].s_y = s_y;
		enemy1[i].sIn = rand() % 5;
		enemy1[i].sShow = true;
	}

	
	//snake
	for (int i = 1; i <= FIRENUM; i++)
	{
		enemy2[i].f_x = SCREENWIDTH + rand() % 100;
		enemy2[i].f_y = f_y;
		enemy2[i].fireIn = rand() % 6;
		enemy2[i].fShow = true;
	}
}

void b_change()
{

	//bandor
	for (int i = 1; i<BANDORNUM; i++)
	{
		enemy[i].b_x -= 10;
		if (enemy[i].b_x <= 0)
		{
			enemy[i].b_x = SCREENWIDTH + rand() % 100;
			//enemy[i+1].b_x = 1366 + 30;
		}
		enemy[i].bIn++;
		if (enemy[i].bIn >= 8)
		{
			enemy[i].bIn = 0;
		}
	}

	
	//shaap
	for (int i = 1; i<SHAPNUM; i++)
	{
		enemy1[i].s_x -= 20;
		if (enemy1[i].s_x <= 0)
		{
			enemy1[i].s_x = SCREENWIDTH + rand() % 100;
			//enemy[i+1].b_x = 1366 + 30;
		}
		enemy1[i].sIn++;
		if (enemy1[i].sIn >= 5)
		{
			enemy1[i].sIn = 0;
		}
	}

	
	
	//fire
	for (int i = 1; i<FIRENUM; i++)
	{
		enemy2[i].f_x -= 50;
		if (enemy2[i].f_x <= 0)
		{
			enemy2[i].f_x = SCREENWIDTH + rand() % 100;
			//enemy[i+1].b_x = 1366 + 30;
		}
		enemy2[i].fireIn++;
		if (enemy2[i].fireIn >= 6)
		{
			enemy2[i].fireIn = 0;
		}
	}

}


void change(){
	
	b_change();
	run();
	p_b_function();
	if (fight)
	{
		fig();
	}

	if (power)
	{
		pow_fun();
	}


	if (jump)
	{
		if (jup)
		{
			jCor += 90;
			if (jCor > JUMPLIMIT)
			{
				jup = false;
			}
		}
		else
		{
			jCor -= 90;
			if (jCor < 0)
			{
				jump = false;
				jCor = 100;
			}
		}
	}
}


//bg coordinate set
void setAll(){

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{

		upperBackGround1[i].y = 0;

		upperBackGround1[i].x = sum;



		sum += PERWIDTH;
	}
}


//bg render
void render()
{
	for (int i = 0; i < 10; i++)
	{
		upperBackGround1[i].x -= PERWIDTH;

		if (upperBackGround1[i].x < 0)
		{
			upperBackGround1[i].x = SCREENWIDTH - PERWIDTH;

		}

	}
}



//collision
/*void collison()
{
	if (n_x + 10 > b_x)
	{

	}
}*/


//sound function

void music()
{
	if (soundOn)
	{
		soundOn = false;
		//PlaySound(sound, NULL, SND_LOOP | SND_ASYNC);
		PlaySound(0, 0, 0);
	}
	else
	{
		soundOn = true;
		PlaySound(sound, NULL, SND_ASYNC | SND_LOOP);
	}
}

void sou()
{
	if (soundOn)
	{
		PlaySound(sound, NULL, SND_LOOP | SND_ASYNC);
	}
}


void set()
{
	int sum = 200;
	for (int i = 5; i >= 0; i--)
	{
		bcord[i].x = 70;
		bcord[i].y = sum;
		sum += 80;
	}

}
void bset()
{
	bbcord[1].bx = 600;
	bbcord[1].by = 20;
}
void yset()
{
	ycord[1].yx = 420;
	ycord[1].yy = 400;
}
void nset()
{
	ncord[1].nx = 820;
	ncord[1].ny = 400;
}

/*int scoredPlayer = 0;
boolean editName = true;
boolean backgroundChange = false;
boolean nameFieldOn = false;
boolean nameLimit = true;
boolean emptyNameField = false; // 9-2-16:: added: if true then there is no name in the namefield

int nameField_x = 450, nameField_y = 250;
char str[20], playerName[20];
int len, i;

int ap_x = 350, ap_y = 300, score = 0;
char s[100] = "SCORE =";
//String scoreText;
char gu[100];
void enterName()
{
	iShowBMP2(nameField_x + 20, nameField_y + 100, "button\\12.bmp", 0);

	if (!nameFieldOn){
		iShowBMP2(nameField_x, nameField_y, "button\\12.bmp", 0);
		iSetColor(0, 0, 0);
		iText(nameField_x, nameField_y - 20, "Click to activate the box, enter to finish.", GLUT_BITMAP_9_BY_15);
	}
	else{
		iShowBMP2(nameField_x, nameField_y - 15, "button\\12.bmp", 255);

		iSetColor(0, 0, 0);
		iText(nameField_x + 130, nameField_y + 30, str, GLUT_BITMAP_TIMES_ROMAN_24);

		if (!nameLimit){

			iSetColor(255, 255, 255);
			iFilledRectangle(nameField_x + 100, nameField_y - 40, 180, 30);


			iSetColor(255, 0, 0);
			iText(nameField_x + 110, nameField_y - 30, "Name Limit reached", GLUT_BITMAP_HELVETICA_18);
		}
		else if (emptyNameField){
			iSetColor(255, 255, 255);
			iFilledRectangle(nameField_x + 60, nameField_y - 40, 250, 30);


			iSetColor(255, 0, 0);
			iText(nameField_x + 75, nameField_y - 30, "Please Enter a Name First", GLUT_BITMAP_HELVETICA_18);
		}
	}
}*/



int main()
{
	///srand((unsigned)time(NULL));
	//enterName();
	nset();
	yset();
	bset();
	set();
	setAll();
	iSetTimer(25, ninjaStar);
	iSetTimer(250, render);
	setEnemy();
    //sou();
	iSetTimer(200, change);
	iInitialize(SCREENWIDTH, SCREENHEIGHT, "ShinobiRun");
	///updated see the documentations
	iStart();
	return 0;
}