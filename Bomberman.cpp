/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include<math.h>

int x2=300, y2=0;
int x = 60;
int y = 0;
int flag,flag2;
int i,j;
int m,n;
int p,q;
int down,up,left,right;
int temp,click;
bool vanish=true;
int x4=540,y4=540;
int x5=540,y5=60;
int x6=0,y6=540;
int x7=0,y7=240;


int a[11]={0,60,120,180,240,300,360,420,480,540,600};
int b[11]={0,60,120,180,240,300,360,420,480,540,600};
int block[10][10]={
	{1,1,0,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,1,0,0,1,0,0,0,0,0},
	{1,0,1,0,0,0,0,0,0,1},
	{0,1,0,0,1,0,0,1,0,1},
	{0,0,0,0,1,0,0,0,1,1},
	{0,0,0,0,0,1,0,0,0,1},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,0},
	{0,0,1,1,0,1,0,0,0,0}
};



int x3=540,y3=0;
int up2,down2,left2,right2;







/* 
	function iDraw() is called again and again by the system.
*/



//int wallsx[35]={""}


/*void moveDown(){
    for(i=0;i<10;i++){
		//down=0;
		if(y==a[i]){
			for(j=0;j<10;j++){
				if(x>=b[j] && x<b[j+1]){
					if(block[j][i]==1){
					    down=1;
						temp=1;
						
					}
					else if(j>0 && block[j-1][i]==1){
					    down=1;
						temp=1;
						
					}
					else
						down=0;
					//return;
				}
				
				//if(temp)break;
			}
		
		}
		//if(temp)break;
	}
}*/

void startmenu()
{

	if(click==0){
	iSetColor(255,220,220);//yellow

	iShowBMP(0,0,"Background.bmp");
	
	iText(450,300,"MENU", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(420,250,"Start Game", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(420,220,"High Score", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(420,190,"Controls", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(420,160,"Credits", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(420,130,"Exit", GLUT_BITMAP_TIMES_ROMAN_24);

}
}

void highscore(){

	iShowBMP(0,0,"Highscore.bmp");
	//iText(420,220,"High Score", GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP(540,0,"back.bmp");
}

void controls(){

	iSetColor(128,0,64);
	iShowBMP(0,0,"Controls.bmp");
	iText(10,490,"Press 'UP' arrow key to move UP", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,450,"Press 'DOWN' arrow key to move DOWN", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,410,"Press 'LEFT' arrow key to move LEFT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,370,"Press 'RIGHT' arrow key to move RIGHT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,330,"Press 'X' to put the Bomb", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,290,"Press 'C' to blast the Bomb", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(540,0,"back.bmp");
}

void credits(){

	iShowBMP(0,0,"Credits.bmp");
	iText(10,490,"Shihab Shahriar Ahamed (14.02.04.029)", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,450,"Shehabul Alam Shatu (14.02.04.030)", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(540,0,"back.bmp");

}

void moveDown(){
    if((x>=0 && x<60) && ((y<=480&& y>420) || (y<=420 && y>360) || (y<=240 && y>180) || (y<=120 && y>60) || (y<=60 && y>0)))
	    down=1;
	else if((x>0 && x<120) && (y<=480 && y>420))
		down=1;
	else if((x>60 && x<180) && ((y<=300 && y>240) || (y<=120 && y>60)))
		down=1;
	else if((x>120 && x<240) && ((y<=600 && y>540) || (y<=180 && y>120) || (y<=60 && y>0)))
		down =1;
	else if((x>180 && x<300) && ((y<=600 && y>540) || (y<=480 && y>420) || (y<=300 && y>240) || (y<=120 && y>60)))
		down=1;
	else if((x>240 && x<360) && ((y<=600 && y>540) || (y<=540 && y>480) || (y<=300 && y>240)))
		down=1;
	else if((x>300 && x<420) && ((y<=600 && y>540) || (y<=360 && y>300)))
		down=1;
	else if((x>360 && x<480) && (y<=180 && y>120))
		down=1;
	else if((x>420 && x<540) && ((y<=540 && y>480) || (y<=480 && y>420)))
		down=1;
	else if((x>480 && x<600) && ((y<=360 && y>300) || (y<=240 && y>180) || (y<=180 && y>120)))
		down=1;
	else 
		down=0;
}


void moveUp(){
     if((x>=0 && x<60) && ((y<360 && y>=300) || (y<420 && y>=360) || (y>=120 && y<180) || (y<60 && y>=0)))
	    up=1;
	else if((x>0 && x<120) && (y>=360 && y<420))
		up=1;
	else if((x>60 && x<180) && ((y>=0 && y<60) || (y>=180 && y<240)))
		up=1;
	else if((x>120 && x<240) && ((y>=480 && y<540) || (y>=60 && y<120)))
		up =1;
	else if((x>180 && x<300) && ((y>=480 && y<540) || (y>=360 && y<420) || (y>=180 && y<240) || (y>=0 && y<60)))
		up=1;
	else if((x>240 && x<360) && ((y>=480 && y<540) || (y>=420 && y<480) || (y>=180 && y<240)))
		up=1;
	else if((x>300 && x<420) && ((y>=480 && y<540) || (y>=240 && y<300)))
		up=1;
	else if((x>360 && x<480) && (y>=60 && y<120))
		up=1;
	else if((x>420 && x<540) && ((y>=420 && y<480) || (y>=360 && y<420)))
		up=1;
	else if((x>480 && x<600) && ((y>=240 && y<300) || (y>=120 && y<180) || (y>=60 && y<120)))
		up=1;
	else 
		up=0;
}



void moveLeft(){

    if((x>=0 && x<=60) && ((y>=0 && y<60) || (y>0 && y<120) || (y>120 && y<240) || (y>300 && y<420) || (y>360 && y<420)))
	    left=1;
	else if((x>60 && x<=120) && (y>360 && y<480))
		left=1;
	else if((x>120 && x<=180) && ((y>0 && y<120) || (y>180 && y<300)))
		left=1;
	else if((x>180 && x<=240) && ((y>=0 && y<60) || (y>60 && y<180) || (y>60 && y<18)))
		left=1;
	else if((x>240 && x<=300) && ((y>0 && y<120) || (y>180 && y<300) || (y>360 && y<480) || (y>480 && y<600)))
		left=1;
	else if((x>300 && x<=360) && ((y>480 && y<600) || (y>420 && y<540) || (y>180 && y<300)))
		left=1;
	else if((x>360 && x<=420) && ((y>480 && y<600) || (y>240 && y<360)))
		left=1;
	else if((x>420 && x<=480) && (y>60 && y<180))
		left=1;
	else if((x>480 && x<=540) && ((y>420 && y<540) || (y>360 && y<480)))
		left=1;
	else if((x>540 && x<=600) && ((y>240 && y<360) || (y>120 && y<240) || (y>60 && y<180)))
		left=1;
	else 
		left=0;
}



void moveRight(){
   
	if((x>=0 && x<60) && (y<480 && y>360))
		right=1;
	else if((x>=60 && x<120) && ((y>0 && y<120) || (y<300 && y>180)))
		right=1;
	else if((x>=120 && x<240) && ((y<600 && y>480) || (y<180 && y>60) || (y<60 && y>=0)))
		right =1;
	else if((x>=180 && x<240) && ((y<180 && y>0) || (y<300 && y>180) || (y<480 && y>360) || (y<600 && y>480)))
		right=1;
	else if((x>=240 && x<300) && ((y<300 && y>180) || (y<540 && y>420) || (y<600 && y>480)))
		right=1;
	else if((x>=300 && x<360) && ((y<600 && y>480) || (y<360 && y>240)))
		right=1;
	else if((x>=360 && x<420) && (y<180 && y>60))
		right=1;
	else if((x>=420 && x<480) && ((y<540 && y>420) || (y<480 && y>360)))
		right=1;
	else if((x>=480 && x<540) && ((y<360 && y>240) || (y<240 && y>120) || (y<180 && y>60)))
		right=1;
	else 
		right=0;

}


void moveDown2(){
    if((x2>=0 && x2<60) && ((y2<=480&& y2>420) || (y2<=420 && y2>360) || (y2<=240 && y2>180) || (y2<=120 && y2>60) || (y2<=60 && y2>0)))
	    down2=1;
	else if((x2>0 && x2<120) && (y2<=480 && y2>420))
		down2=1;
	else if((x2>60 && x2<180) && ((y2<=300 && y2>240) || (y2<=120 && y2>60)))
		down2=1;
	else if((x2>120 && x2<240) && ((y2<=600 && y2>540) || (y2<=180 && y2>120) || (y2<=60 && y2>0)))
		down2 =1;
	else if((x2>180 && x2<300) && ((y2<=600 && y2>540) || (y2<=480 && y2>420) || (y2<=300 && y2>240) || (y2<=120 && y2>60)))
		down2=1;
	else if((x2>240 && x2<360) && ((y2<=600 && y2>540) || (y2<=540 && y2>480) || (y2<=300 && y2>240)))
		down2=1;
	else if((x2>300 && x2<420) && ((y2<=600 && y2>540) || (y2<=360 && y2>300)))
		down2=1;
	else if((x2>360 && x2<480) && (y2<=180 && y2>120))
		down2=1;
	else if((x2>420 && x2<540) && ((y2<=540 && y2>480) || (y2<=480 && y2>420)))
		down2=1;
	else if((x2>480 && x2<600) && ((y2<=360 && y2>300) || (y2<=240 && y2>180) || (y2<=180 && y2>120)))
		down2=1;
	else 
		down2=0;
}


void moveUp2(){
     if((x2>=0 && x2<60) && ((y2<360 && y2>=300) || (y2<420 && y2>=360) || (y2>=120 && y2<180) || (y2<60 && y2>=0)))
	    up2=1;
	else if((x2>0 && x2<120) && (y2>=360 && y2<420))
		up2=1;
	else if((x2>60 && x2<180) && ((y2>=0 && y2<60) || (y2>=180 && y2<240)))
		up2=1;
	else if((x2>120 && x2<240) && ((y2>=480 && y2<540) || (y2>=60 && y2<120)))
		up2=1;
	else if((x2>180 && x2<300) && ((y2>=480 && y2<540) || (y2>=360 && y2<420) || (y2>=180 && y2<240) || (y2>=0 && y2<60)))
		up2=1;
	else if((x2>240 && x2<360) && ((y2>=480 && y2<540) || (y2>=420 && y2<480) || (y2>=180 && y2<240)))
		up2=1;
	else if((x2>300 && x2<420) && ((y2>=480 && y2<540) || (y2>=240 && y2<300)))
		up2=1;
	else if((x2>360 && x2<480) && (y2>=60 && y2<120))
		up2=1;
	else if((x2>420 && x2<540) && ((y2>=420 && y2<480) || (y2>=360 && y2<420)))
		up2=1;
	else if((x2>480 && x2<600) && ((y2>=240 && y2<300) || (y2>=120 && y2<180) || (y2>=60 && y2<120)))
		up2=1;
	else 
		up2=0;
}


void moveLeft2(){

    if((x2>=0 && x2<=60) && ((y2>=0 && y2<60) || (y2>0 && y2<120) || (y2>120 && y2<240) || (y2>300 && y2<420) || (y2>360 && y2<420)))
	    left2=1;
	else if((x2>60 && x2<=120) && (y2>360 && y2<480))
		left2=1;
	else if((x2>120 && x2<=180) && ((y2>0 && y2<120) || (y2>180 && y2<300)))
		left2=1;
	else if((x2>180 && x2<=240) && ((y2>=0 && y2<60) || (y2>60 && y2<180) || (y2>60 && y2<18)))
		left2=1;
	else if((x2>240 && x2<=300) && ((y2>0 && y2<120) || (y2>180 && y2<300) || (y2>360 && y2<480) || (y2>480 && y2<600)))
		left2=1;
	else if((x2>300 && x2<=360) && ((y2>480 && y2<600) || (y2>420 && y2<540) || (y2>180 && y2<300)))
		left2=1;
	else if((x2>360 && x2<=420) && ((y2>480 && y2<600) || (y2>240 && y2<360)))
		left2=1;
	else if((x2>420 && x2<=480) && (y2>60 && y2<180))
		left2=1;
	else if((x2>480 && x2<=540) && ((y2>420 && y2<540) || (y2>360 && y2<480)))
		left2=1;
	else if((x2>540 && x2<=600) && ((y2>240 && y2<360) || (y2>120 && y2<240) || (y2>60 && y2<180)))
		left2=1;
	else 
		left2=0;
}



void moveRight2(){
   
	if((x2>=0 && x2<60) && (y2<480 && y2>360))
		right2=1;
	else if((x2>=60 && x2<120) && ((y2>0 && y2<120) || (y2<300 && y2>180)))
		right2=1;
	else if((x2>=120 && x2<240) && ((y2<600 && y2>480) || (y2<180 && y2>60) || (y2<60 && y2>=0)))
		right2=1;
	else if((x2>=180 && x2<240) && ((y2<180 && y2>0) || (y2<300 && y2>180) || (y2<480 && y2>360) || (y2<600 && y2>480)))
		right2=1;
	else if((x2>=240 && x2<300) && ((y2<300 && y2>180) || (y2<540 && y2>420) || (y2<600 && y2>480)))
		right2=1;
	else if((x2>=300 && x2<360) && ((y2<600 && y2>480) || (y2<360 && y2>240)))
		right2=1;
	else if((x2>=360 && x2<420) && (y2<180 && y2>60))
		right2=1;
	else if((x2>=420 && x2<480) && ((y2<540 && y2>420) || (y2<480 && y2>360)))
		right2=1;
	else if((x2>=480 && x2<540) && ((y2<360 && y2>240) || (y2<240 && y2>120) || (y2<180 && y2>60)))
		right2=1;
	else 
		right2=0;

}

int rightz=1,upz=1,downz=1,leftz=1;

/*void finalMove(int a,int b){
    if((x>=a+60 && x<a+120) && (y>=b && y<b+60))rightz=0;else rightz=1;
	if((x>=a && x<a+60) && (y>=b+60 && y<b+120))upz=0;else upz=1;
	if((x>a-60 && x<=a) && (y>=b && y<b+60))leftz=0;else leftz=1;
	if((x>=a && x<a+60) && (y>b-60 && y<=b))downz=0;else downz=1;
	
}*/


bool MoveBomb=true;
bool Survive=true;
int variable1,variable2;
void bomb(){
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if((x>=a[i] && x<a[i+1]) && (y>=b[j] && y<b[j+1])){
				if(MoveBomb==true){p=a[i];variable1=i;}
				if(MoveBomb==true){q=b[j];variable2=j;}
                //if(flag2==1){finalMove(p,q);}
				
			}
			
		}
	}
}

bool alienSurvive1=true;
bool alienSurvive2=true;
bool alienSurvive3=true;
bool alienSurvive4=true;

bool alien(){
	if(x4>=p+60 && x4<p+120 && y4>=q && y4<=q+60){x4=x4*-1;y4=y4*-1;return true;}
	else if(x4>=p && x4<p+60 && y4>=q+60 && y4<q+120) {x4=x4*-1;y4=y4*-1;return true;}
	else if(x4<p && x4>=p-60 && y4>=q && y4<=q+60){x4=x4*-1;y4=y4*-1;return true;}
	else if(x4>=p && x4<p+60 && y4<q && y4>=q-60){x4=x4*-1;y4=y4*-1;return true;}
	else if(x4>=p && x4<p+60 && y4>=q && y4<q+60){x4=x4*-1;y4=y4*-1;return true;}
	else return false;
}

bool alien2(){
	if(x5>=p+60 && x5<p+120 && y5>=q && y5<=q+60){x5=x5*-1;y5=y5*-1;return true;}
	else if(x5>=p && x5<p+60 && y5>=q+60 && y5<q+120) {x5=x5*-1;y5=y5*-1;return true;}
	else if(x5<p && x5>=p-60 && y5>=q && y5<=q+60){x5=x5*-1;y5=y5*-1;return true;}
	else if(x5>=p && x5<p+60 && y5<q && y5>=q-60){x5=x5*-1;y5=y5*-1;return true;}
	else if(x5>=p && x5<p+60 && y5>=q && y5<q+60){x5=x5*-1;y5=y5*-1;return true;}
	else return false;
}

bool alien3(){
	if(x6>=p+60 && x6<p+120 && y6>=q && y6<=q+60){x6=x6*-1;y6=y6*-1;return true;}
	else if(x6>=p && x6<p+60 && y6>=q+60 && y6<q+120){x6=x6*-1;y6=y6*-1;return true;}
	else if(x6<p && x6>=p-60 && y6>=q && y6<=q+60){x6=x6*-1;y6=y6*-1;return true;}
	else if(x6>=p && x6<p+60 && y6<q && y6>=q-60){x6=x6*-1;y6=y6*-1;return true;}
	else if(x6>=p && x6<p+60 && y6>=q && y6<q+60){x6=x6*-1;y6=y6*-1;return true;}
	else return false;
}

bool alien4(){
	if(x7>=p+60 && x7<p+120 && y7>=q && y7<=q+60){x7=x7*-1;y7=y7*-1;return true;}
	else if(x7>=p && x7<p+60 && y7>=q+60 && y7<q+120){x7=x7*-1;y7=y7*-1;return true;}
	else if(x7<p && x7>=p-60 && y7>=q && y7<=q+60){x7=x7*-1;y7=y7*-1;return true;}
	else if(x7>=p && x7<p+60 && y7<q && y7>=q-60){x7=x7*-1;y7=y7*-1;return true;}
	else if(x7>=p && x7<p+60 && y7>=q && y7<q+60){x7=x7*-1;y7=y7*-1;return true;}
	else return false;
}

void ChangeBlock(int i, int j, bool value){
	block[i][j]=value;
}

bool isDeadAlien1(){

	if((x4<x+60 && x4>x-60) && (y4>y-60 && y4<y+60))return false;
	if((x4>x-60 && x4<x+60) && (y4>y && y4<y+60))return false;
	if((x4>x && x4<x+60) && (y4>y-60 && y4<y+60))return false;
	if((x4>x-60 && x4<x+60) && (y4>y && y4<y+60))return false;
	else return true;
	
}

bool isDeadAlien2(){

	if((x5<x+60 && x5>x-60) && (y5>y-60 && y5<y+60))return false;
	if((x5>x-60 && x5<x+60) && (y5>y && y5<y+60))return false;
	if((x5>x && x5<x+60) && (y5>y-60 && y5<y+60))return false;
	if((x5>x-60 && x5<x+60) && (y5>y && y5<y+60))return false;
	else return true;
	
}

bool isDeadAlien3(){
if((x6<x+60 && x6>x-60) && (y6>y-60 && y6<y+60))return false;
	if((x6>x-60 && x6<x+60) && (y6>y && y6<y+60))return false;
	if((x6>x && x6<x+60) && (y6>y-60 && y6<y+60))return false;
	if((x6>x-60 && x6<x+60) && (y6>y && y6<y+60))return false;
	else return true;
	
}

bool isDeadAlien4(){

	if((x7<x+60 && x7>x-60) && (y7>y-60 && y7<y+60))return false;
	if((x7>x-60 && x7<x+60) && (y7>y && y7<y+60))return false;
	if((x7>x && x7<x+60) && (y7>y-60 && y7<y+60))return false;
	if((x7>x-60 && x7<x+60) && (y7>y && y7<y+60))return false;
	else return true;
	
}

/*void bombBlast(){

    if(MoveBomb==true){
		p=p*-1;
        q=q*-1;
	}

}*/

//bool alien1=true,alien2=false,alien3=false,alien4=false;
int shihab=0;

void alienMove(){
	    
	if((x4<=540 && x4>420) && (y4==540))x4=x4-1;
	else if((shihab==0) && (y4<=540 && y4>180) && (x4==420)){
		y4=y4-1;
		if(y4==180)shihab=1;
	}
    else if((x4<=420 && x4>180) && (y4==180))x4--;
	else if((y4>=180 && y4<360)&& (x4==180))y4++;
    else if((shihab==1) && (x4>=180 && x4<540) && (y4==360)){
		x4++;
		if(x4==540)shihab=0;
	}
	else if((y4>=360 && y4<540) && (x4==540))y4++;

}

void alienMove2(){

if((x5<=540 && x5>360) && (y5==60))x5--;
else if((y5>=60 && y5<240) && (x5==360))y5++;
else if((x5>=360 && x5<420) && (y5==240))x5++;
else if((y5>=240 && y5<360) && (x5==420))y5++;
else if((x5<=420 && x5>180) && (y5==360))x5--;
else if((y5<=360 && y5>180) && (x5==180))y5--;
else if((x5>=180 && x5<300) && (y5==180))x5++;
else if((y5<=180 && y5>0) && (x5==300))y5--;
else if((x5>=300 && x5<540) && (y5==0))x5++;
else if((y5>=0 && y5<60) && (x5==540))y5++;

}

int shatu=0;
void alienMove3(){
    
	if((x6>=0 && x6<120) && (y6==540))x6++;
	else if(shatu==0 && (y6<=540 && y6>300) && (x6==120)){
		y6--;
		if(y6==300)shatu=1;
	}
	else if((x6<=120 && x6>60) && (y6==300))x6--;
    else if((y6<=300 && y6>180) && (x6==60))y6--;
    else if((x6>=60 && x6<420) && (y6==180))x6++;
    else if((y6>=180 && y6<360) && (x6==420))y6++;
    else if((x6<=420 && x6>120) && (y6==360))x6--;
    else if(shatu==1 && (y6>=360 && y6<480) && (x6==120)){
		y6++;
		if(y6==480)shatu=2;
	}
	else if(shatu==2 && (x6<=120 && x6>0) && (y6==480)){
		x6--;
		if(x6==0)shatu=0;
	}
    else if((y6>=480 && y6<540) && (x6==0))y6++;
}

int jitu=0;
void alienMove4(){
    if((x7>=0 && x7<60) && (y7==240))x7++;
	else if((y7<=240 && y7>180) && (x7==60))y7--;
	else if((x7>=60 && x7<180) && (y7==180))x7++;
    else if((y7>=180 && y7<480) && (x7==180))y7++;
	else if((x7<=180 && x7>120) && (y7==480))x7--;
	else if((y7<=480 && y7>300) && (x7==120))y7--;
    else if((x7<=120 && x7>0) && (y7==300))x7--;
    else if((y7<=300 && y7>240) && (x7==0))y7--;

}
int shahriar;
void iDraw()
{
			
	iClear();

	if(click==0){
		startmenu();
	}

	if(click==2){
		highscore();
	}

    if(click==3){
		controls();
	}
	
	if(click==4){
		credits();
	}
	
	//place your drawing codes here	
	if(click==1){
	moveDown();
    moveUp();
	moveLeft();
	moveRight();
	moveDown2();
    moveUp2();
	moveLeft2();
	moveRight2();
	if(isDeadAlien1()==false)Survive=false;
	if(isDeadAlien2()==false)Survive=false;
	if(isDeadAlien3()==false)Survive=false;
	if(isDeadAlien4()==false)Survive=false;
	iClear();
	iSetColor(255,255,255);
	iFilledRectangle(0,0,600,600);
	moveDown();
	if(alienSurvive1==true)iShowBMP(x4,y4,"alien.bmp");
    if(alienSurvive2==true)iShowBMP(x5,y5,"alien.bmp");
    if(alienSurvive3==true)iShowBMP(x6,y6,"alien.bmp");
	if(alienSurvive4==true)iShowBMP(x7,y7,"alien.bmp");
	//alienMove();
	
	if(Survive==true)iShowBMP(x,y,"bomberman.bmp");
	//iShowBMP(x2,y2,"a.bmp");

	   for(i=0;i<10;i++){
		   for(j=0;j<10;j++){
			   if(block[i][j]==1){
				   m=a[i];
				   n=b[j];
			       iShowBMP(m,n,"wall.bmp");
				   
			   }
		   }
	   }
	if(flag==1){
	    bomb();
	    iShowBMP(p,q,"Bomb.bmp");
		MoveBomb=false;
	   }
	
	if(Survive==false){iShowBMP(0,0,"gameover.bmp");shahriar=1;}
	}
	if(alienSurvive1==false && alienSurvive2==false && alienSurvive3==false && alienSurvive4==false)iShowBMP(0,0,"win.bmp");
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my){

	if( mx >= 415 && mx <= 415 + 100 && my >= 245 && my<= 245 + 20 && click == 0){
			
			click=1;
	}
	if( mx >= 420 && mx <= 420 + 100 && my >= 215 && my<= 215 + 20 && click == 0){
			
			click=2;  
		    
			
	}
	if( mx >= 420 && mx <= 420 + 100 && my >= 185 && my<= 185 + 20 && click == 0){
			
			click=3;
	}
	if( mx >= 420 && mx <= 420 + 100 && my >= 155 && my<= 155 + 20 && click == 0){
			
			click=4;
	}

	if( mx >= 540 && mx <= 600  && my >= 0 && my<= 30 && (click==2 || click==3 || click==4 || shahriar==1))click=0;
	
	
	if(mx>=420 && mx<=500 && my>=125 && my<=145 && click == 0){
		
			exit(0);
		}
	
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
bool isDeadBomb(void){
	//printf("%d %d", p, q);
	if(x>=p+60 && x<p+120 && y>=q && y<=q+60)return true;
	else if(x>=p && x<p+60 && y>=q+60 && y<q+120) return true;
	else if(x<p && x>=p-60 && y>=q && y<=q+60) return true;
	else if(x>=p && x<p+60 && y<q && y>=q-60)return true;
	else if(x>=p && x<p+60 && y>=q && y<q+60)return true;
	else return false;

}
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//x4+=10;
		//x5+=10;
		//do something with 'q'
	}
	if(key == 'w') {
		//x4 -=10;
		//x5 -=10;
	//place your codes for other keys here
}
	if(key == 'x') {
		flag = 1;
		flag2=0;
	}
	if(key == 'c') {
		flag = 0;
		flag2=1;
		if(isDeadBomb()==true && MoveBomb==false)Survive=false;
		if(alien()==true)alienSurvive1=false;
		if(alien2()==true)alienSurvive2=false;
		if(alien3()==true)alienSurvive3=false;
		if(alien4()==true)alienSurvive4=false;
		MoveBomb=true;
		p=x;q=y;
	//	ChangeBlock(variable1+1,variable2,false);
	//	ChangeBlock(variable1-1,variable2,false);
	//	ChangeBlock(variable1,variable2+1,false);
	//	ChangeBlock(variable1,variable2-1,false); 
		
	//	printf("%d\n", MoveBomb);
	}

	if(key == 'w'){
	    if(y2<540 && up2==0){
		    y2+=10;
		}
	}

	if(key == 's'){
	    
        if(y2>0 && down2==0)  {
			y2-=10;
		}

	}

	if(key == 'a'){
	
	    if(x2>0 && left2==0){
			x2-=10;
		}
	
	}

	if(key == 'd'){
	
	    if( x2<540 && right2==0){
				x2+=10;
		}
	
	}
	if(key == 'p'){
		click=0;
	}
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

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP) {

		//int temp=y+10;
		if(y<540 && upz==0){
		    y+=10;
		}

		else if(y<540 && up==0){
		    y+=10;
		}
	}
	if(key == GLUT_KEY_DOWN){
        
	    if(y>0 && downz==0)  {
			y-=10;
		}
		
		else if(y>0 && down==0)  {
			y-=10;
		}



	}
	if(key == GLUT_KEY_RIGHT){
		if( x<540 && rightz==0){
				x+=10;
		}
		
		else if( x<540 && right==0){
				x+=10;
		}
	}
	if(key == GLUT_KEY_LEFT){
		if(x>0 && leftz==0){
			x-=10;
		}
		
		else if(x>0 && left==0){
			x-=10;
		}
}
}
int main()
{
	//place your own initialization codes here. 
	iSetTimer(1,alienMove);
	iSetTimer(1,alienMove2);
    iSetTimer(1,alienMove3);
	iSetTimer(1,alienMove4);
	iInitialize(600,600, "demooo");
	return 0 ;
}	