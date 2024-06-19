#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>

//algorithms used
//1 for line generation

int absn(int n)//function for finding absolute value
{
    return ( (n>0) ? n : ( n * (-1)));
}
 
//DDA Function for line generation
void line_d(int x1, int y1, int x2, int y2)
{
	int i;
    // calculate dx & dy
    int dx = x2 - x1;
    int dy = y2 - y1;
 
    // calculate steps required for generating pixels
    int steps = absn(dx) > absn(dy) ? absn(dx) : absn(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = x1;
    float Y = y1;
    for ( i = 0; i <= steps; i++)
    {
        putpixel (X,Y,WHITE);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
	delay(5);          // for visualization of line-
                             // generation step by step
    }
}

//2.midpoint circle generation algoritham used
 
void circle_m(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
    	delay(60);
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
 
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

// 3.boundary fill algorithm 
void boundaryFill4(int x, int y, int fill_color,int boundary_color)
{
		
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
        
    }

}

//4.Bezier algoritham for Curve generation
void bezier(int x[],int y[])
{
int i;
double t,xt,yt;
for (t = 0.0; t < 1.0; t += 0.0005)
{
xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel (xt, yt,WHITE);
delay(1);
}
}


// Used Function Declaration FOR india gate
void india_gate();
void coloring();
void taj_mahal();
void taj_color();

void main()
{
	int gd = DETECT, gm,i,j=1;

	// Initialize of gdriver with
	// DETECT macros
	initgraph(&gd, &gm,
			"C:\\turboc3\\bgi");
	for(i=0;i<=getmaxx()-620;i++)
	{
	cleardevice();
	settextstyle(1,0,5);
	setcolor(14);
	outtextxy(i,30,"         WELCOME ");
	settextstyle(1,0,3);
	setcolor(j+2);
	outtextxy(i,135,"               MICROPROJECT ON :");
	setcolor(14);
	settextstyle(1,0,4);
	outtextxy(i,170,"STRUCTURE OF INDIA GATE & TAJMAHAL");
	setcolor(j+2);
	outtextxy(i,210,"           ******************     ");
	settextstyle(1,0,2);
	setcolor(14);
	outtextxy(i,320,"                     TEAM MEMBERS : ");
	setcolor(3);
	outtextxy(i,360,"                  1203 PRANALI BHOSALE");
	outtextxy(i,380,"                  1219 SAKSHI  GHORPADE");
	outtextxy(i,400,"                  1222 SHREYA  HANDE");

	delay(5);
	}


	  delay(4000);
	  cleardevice();

	setcolor(15);
       //	 calling function for india gate
		india_gate();
	      coloring();
	      setcolor(15);
		delay(1000);
	       cleardevice();

    //calling function for taj mahal
	     taj_mahal();
	     taj_color();

	// Holding The Screen For A While
	getch();

	// Close the initialized gdriver
	closegraph();
}

void india_gate()
{
	 double u;
		// Base Line
	line_d(100, 333, 530, 333);
	line_d(100,350,530,350);
	//two small lines
	line_d(100,333,100,350);
	line_d(530,333,530,350);

	
//draw the left part of the India Gate

	// Left Base Rectangle
	rectangle(166, 233,
			233, 333);
			delay(300);

	// Lower Inner Rectangle
	rectangle(176, 233,
			223, 333);
			delay(300);
	rectangle(186, 306,
			213, 333);
			delay(500);
	line_d(166, 306, 233, 306);
			delay(300);
	line_d(166, 233, 233, 233);
			delay(300);
	line_d(160, 226, 256, 226);
			delay(300);
	line_d(166, 233, 160, 226);
		       delay(500);
	line_d(233, 233, 240, 226);
	delay(300);

	// Left Upper Rectangle

	rectangle(166, 133,
			233, 226);
    delay(300);
	// Upper Inner Rectangle
	rectangle(176, 166,
			223, 226);
	line_d(176, 183, 223, 183);
	line_d(192, 166, 192, 183);
	line_d(207, 166, 207, 183);
	line_d(166, 193, 256, 193);
	line_d(176, 200, 223, 200);
	delay(300);
	rectangle(186, 200,
			213, 210);
			
	circle_m(200, 153, 13);
	circle_m(200, 153, 10); 
	//left part done
	
	

// draw the right part of the India Gate

	// Right Base Rectangle
	delay(300);
	rectangle(400, 233,
			466, 333);
    delay(300);
	// Lower Inner Rectangle
	rectangle(410, 233,
			456, 333);
	delay(300);
	rectangle(420, 306,
			446, 333);  
			
	line_d(400, 306, 466, 306);
	line_d(400, 233, 466, 233);
	line_d(376, 226, 473, 226);
	line_d(400, 233, 393, 226);
	line_d(466, 233, 473, 226);
    delay(300);
	// Right Upper Ractangle
	rectangle(400, 133,
			466, 226);
    delay(300);

	// Upper Inner Rectangle
	rectangle(410, 166,
			456,226);
	line_d(410, 183, 456, 183);
	line_d(425, 166, 425, 183);
	line_d(440, 166, 440, 183);
	line_d(376, 193, 466, 193);
	line_d(410, 200, 456, 200);
	delay(300);
	rectangle(420, 200,
			446, 210);
    delay(300);
	circle_m(433, 153, 13);
	circle_m(433, 153, 10);
	
	//right side part done
	
	//  draw the middle part of the India Gate
	
	line_d(233, 133, 400, 133);
	line_d(233, 143, 311, 143);
	line_d(321, 143, 400,143);
	line_d(311, 160, 311, 143);
	line_d(321, 160, 321, 143);
	line_d(311, 160, 321, 160);
    delay(300);
	// Left side arcs
	ellipse(311, 193, 90,
			180, 55, 35);

	// Right Side Arcs
	ellipse(321, 193, 0,
			90, 55, 35);

     delay(300);
	// Left Side Vertical Line
	line_d(256, 333, 256, 193);
	line_d(256,193,256,225);

	// Right Side Vertical Line
	line_d(376, 333, 376, 193);
	line_d(376,193,376,225);
            //middle part done



 //void up()
	u = 173;
	delay(300);
	rectangle(166, 123, 466, 133);
	delay(500);

	// Defining A loop To Draw
	// Many Lines
	while (u <= 466) {
		line(u, 123, u, 133);
		u = u + 6;
		delay(7);
	}
	line_d(166,134,466,134);
	rectangle(160, 118, 473, 123);
	
	delay(300);
	line_d(166, 133, 160, 123);
	delay(300);
	line_d(466, 133, 473, 123);
	delay(500);
	rectangle(166, 118, 466, 98);


	delay(300);
	rectangle(173, 88, 460, 98);

	delay(500);
	// Main Rectangle To Write
	// India
	rectangle(233, 45, 400, 88);
	delay(300);
	circle_m(260, 73, 10);
	delay(300);
	circle_m(373, 73, 10);
	delay(300);

	line_d(276, 63, 356, 63);
	delay(300);
	line_d(276, 63, 276, 80);
	delay(300);

	line_d(276, 80, 300, 80);
	line_d(356, 63, 356, 80);
	line_d(356, 80, 333, 80);
	line_d(333, 80,333, 83);
	line_d(300, 80, 300, 83);
	line_d(300, 83, 333, 83);
	delay(300);

	// Writing India
	settextstyle(8, 0, 1);
	outtextxy(293, 57, "INDIA");
	delay(300);
	rectangle(266, 41,366,45);
	delay(300);

	rectangle(293, 23, 340, 30);
	delay(300);

	arc(293, 41, 90, 180, 11);
	delay(300);
	arc(340, 41, 0, 90, 11);
	delay(300);
       }
       void coloring()
       {
//coloring

	   int i,x=316,y=228;
	boundaryFill4(167,235,2,15);          //2
      //	boundaryFill4(177,235,2,15);
	boundaryFill4(187,307,2,15);

	setfillstyle(1,2);
	floodfill(177,235,15);
	boundaryFill4(251,270,2,15);

	boundaryFill4(225,270,2,15);
	boundaryFill4(167,330,2,15);
	boundaryFill4(215,330,2,15);
	delay(1000);
	boundaryFill4(185,330,2,15);
	boundaryFill4(224,330,2,15);
	boundaryFill4(167,230,2,15);

	// side(right)
	boundaryFill4(401,235,2,15);
      //	boundaryFill4(177,235,2,15);
	boundaryFill4(415,307,2,15);

	setfillstyle(1,2);
	floodfill(422,235,15);
	boundaryFill4(425,307,2,15);

	boundaryFill4(397,235,2,15);

	boundaryFill4(448,330,2,15);

	boundaryFill4(402,330,2,15);
	boundaryFill4(460,300,2,15);
	boundaryFill4(460,330,2,15);
	boundaryFill4(460,230,2,15);
	setfillstyle(3,15);
	floodfill(167,225,15);
	floodfill(167,138,15);
	floodfill(168,223,15);
	floodfill(230,223,15);

      boundaryFill4(234,223,15,15);
      boundaryFill4(234,185,15,15);
      boundaryFill4(325,148,15,15);
	      //boundaryFill4(234,136,15,15);
	 boundaryFill4(385,223,15,15);

	 //right side h ata
	 setfillstyle(3,15);
      floodfill(402,225,15);
      floodfill(402,138,15);
      floodfill(465,223,15);
      //circles
      boundaryFill4(189,153,15,15);
      boundaryFill4(422,153,15,15);

 //
     boundaryFill4(162,119,4,15);
	setfillstyle(1,4);
	floodfill(167,117,15);
	boundaryFill4(174,89,4,15);
	boundaryFill4(260,73,1,15);
	boundaryFill4(373,73,1,15);

	line_d(250,73,270,73);
	line_d(260,63,260,83);
	line_d(254,65,266,81);
	line_d(266,65,254,81);

	line_d(363,73,383,73);
	line_d(373,63,373,83);
	line_d(367,65,379,81);
	line_d(379,65,367,81);
	boundaryFill4(267,42,4,15);
	boundaryFill4(295,25,4,15);


	setfillstyle(1,4);
	floodfill(295,32,15);

	setfillstyle(1,4);
	floodfill(234,46,15);

	setfillstyle(1,4);
	floodfill(295,32,15);
	i=1;

	settextstyle(1,0,4);
	setcolor(4);
	outtextxy(230,350," IN");
	setcolor(15);
	outtextxy(230,350,"   DI  GA");
	setcolor(15);
	outtextxy(230,350,"     A");
	setcolor(2);
	outtextxy(230,350,"         TE");
     while(i!=7000)
{
i++;
delay(1);
setcolor(0);
circle(x+(37*cos(i)),y+(37*sin(i)),3);
setcolor(2);
circle(x+(37*cos(i+25)),y+(37*sin(i+25)),3);
setcolor(0);
circle(x+(27*cos(i)),y+(27*sin(i)),2);
setcolor(15);
circle(x+(27*cos(i+25)),y+(27*sin(i+25)),2);
setcolor(0);
circle(x+(17*cos(i)),y+(17*sin(i)),2);
setcolor(4);
circle(x+(17*cos(i+25)),y+(17*sin(i+25)),2);

}
delay(500);
}

void taj_mahal()
{
	int a[4]={233,238,402,414};
	int b[4]={127,5,5,125};            //for bezier curve
	// Main Base
	rectangle(0, 325, 639, 340);
	delay(200);
	rectangle(260, 150, 385, 325);
	delay(200);
	rectangle(255, 145, 390, 325);


	// Left Door Line
	line_d(285, 325, 285, 200);

	// Right Door Line
	line_d(360, 325, 360, 200);

	line_d(285, 200, 322.5, 195);
       line_d(322.5,195, 360, 200);
	  bezier(a,b);
      //	arc(323, 125, 0, 181,90);

	// Main Finial
	line_d(311.5, 35, 322.5, 8);
	line_d(322.5, 8, 333.5, 35);


	// Left Side
	line_d(255, 157.5, 208, 157.5);
	arc(230, 157.5, 0, 177, 22.5);
	line_d(225, 135, 230, 125);

	line_d(230, 125, 235, 135);

	// Left Vertical Line
	line_d(207.5, 157.5, 207.5, 177.5);

	// Lower Left Join
	line_d(207.5, 177.5, 255, 177.5);

	// Again Lower Left Join
	line_d(207.5, 187.5, 255, 187.5);

	// Left Tangent
	line_d(207.5, 177.5, 172.5, 185.5);

	// Lower Left Tangent
	line_d(207.5, 187.5, 172.5, 195);

	// Left Last Vertical
	line_d(172.5, 185, 172.5, 325);
	 delay(300);
	// Middle Left Rectangle
	rectangle(210, 195, 250,325);
	 delay(300) ;
	// Left Rectangle Divider
	line_d(210, 260, 250, 260);
	// Left Rectangle Side Structure
	line_d(205, 325, 205, 195);

	line_d(177.5, 325, 177.5, 202.5);
	line_d(205, 195, 177.5, 202.5);

	// Divider
	line_d(205, 260, 178, 260);

	// Creating Left Lower Spike
	line_d(215, 325, 215, 292.5);
	line_d(245, 325, 245, 292.5);
	line_d(215, 292.5, 230, 277.5);
	line_d(245, 292.5, 230, 277.5);

	// Creating Left Upper Spike
	line_d(215, 260, 215, 227.5);
	line_d(245, 260, 245, 227.5);
	line_d(215, 227.5, 230, 212.5);
	line_d(245, 227.5, 230, 212.5);

	// Right Side
	line_d(390, 157.5, 437.5, 157.5);
	arc(414, 157.5, 0, 175, 22.5);

	// Right Finial
	line_d(410.5, 135, 415, 125);

	line_d(415, 125, 420, 135);

	// Right Vertical Line
	line_d(437.5, 157.5, 437.5, 177.5);
	line_d(437.5, 177.5, 390, 177.5);

	// Lower Right Join
	line_d(437.5, 175.5, 390, 177.5);

	// Again Right Left Join
	line_d(437.5, 187.5, 390, 187.5);

	// Right Tangent
	line_d(437.5, 177.5, 472.5, 185);

	// Lower Right Tangent
	line_d(437.5, 187.5, 472.5, 195);

	// Right Last Vertical
	line_d(472.5, 185, 472.5, 325);

	// Middle Right Rectangle
	rectangle(395, 195, 435, 325);
	// Right Rectangle Divider
	line_d(396, 260, 435, 260);       //

	// Right Rectangle Side Structure
	line_d(440, 325, 440, 195);
	line_d(467, 325, 467, 202.5);

	line_d(440, 195, 467, 202.5);

	// Divider
	line_d(440, 260, 467, 260);

	// Creating Right Lower Spike
	line_d(400, 325, 400, 292.5);
	line_d(430, 325, 430, 292.5);
	line_d(400, 292.5, 415, 277.5);
	line_d(430, 292.5, 415, 277.5);

	// Creating Right Upper Spike
	line_d(400, 260, 400, 227.5);
	line_d(430, 260, 430, 227.5);
	line_d(400, 227.5, 415, 212.5);
	line_d(430, 227.5, 415, 212.5);

	circle_m(130,60,30);



//void left_minars()

	// 1st Left Minar
	// 1st Step
	line_d(0, 325, 5, 250);
	line_d(50, 325, 45, 250);
	//main char line
	line_d(45, 250, 5, 250);
	// 2nd Step
	line_d(5, 250, 0, 240);
   //	delay(500);
	line_d(45, 250, 50, 240);
	line_d(50, 240, 0, 240);


       ///end of char lne
	line_d(5, 240, 10, 165);
	line_d(45, 240, 40, 165);
	line_d(10, 165, 40, 165);


	line_d(10, 165, 5, 155);
	line_d(40, 165, 45, 155);
	line_d(45, 155, 5, 155);


	// 3rd Step
	line_d(10, 155, 15, 80);
	line_d(40, 155, 35, 80);
	line_d(15, 80, 35, 80);


	line_d(15,80, 10, 70);
	line_d(35, 80, 40, 70);
	line_d(10, 70, 40, 70);


	line_d(10, 70, 20, 60);
	line_d(40, 70, 30, 60);
	line_d(20, 60, 30, 60);



	line_d(20, 60, 25, 50);
	line_d(25, 50, 30, 60);



	// 2nd Left Minar
	// 1st Step
	line_d(75,325, 80, 287.5);
	line_d(125,325, 120, 287.5);
	line_d(80,287.5, 120, 287.5);


	// 2nd Step
	line_d(80, 287.5, 75, 277.5);
	line_d(120, 287.5, 126, 277.5);
	line_d(75, 277.5, 126, 277.5);




	line_d(80, 277.5, 85, 240);
	line_d(120,277.5, 115, 240);
	line_d(85, 240, 115, 240);



	// 3rd Step
	line_d(85,240, 80, 230);
	line_d(115,240,120, 230);
	line_d(80, 230, 120, 230);



	line_d(85, 230, 90, 192.5);
	line_d(115,230, 110, 192.5);
	line_d(90, 192.5, 110, 192.5);



	line_d(90, 192.5, 85,182.5);
	line_d(110, 192.5, 115, 182.5);
	line_d(85, 182.5, 115, 182.5);



	line_d(85, 183.5, 95, 172.5);
	line_d(115, 183.5, 105, 172.5);
	line_d(95, 172.5, 105, 172.5);


	line_d(95, 172.5, 100, 162.5);
	line_d(100, 162.5, 105, 172.5);


  // void right_minars()

  //1st right minar

//1st step

 line_d(639,325,634,250);

 line_d(587,325,592,250);

 line_d(593,250,634,250);


 //2nd step

    line_d(635,250,639,240);
    line_d(592,250,587,240);
    line_d(587,240,639,240);


    line_d(634,240,629,165);
    line_d(592,240,599,165);
    line_d(629,165,599,165);


    line_d(629,165,634,155);
    line_d(599,165,594,155);
    line_d(594,155,634,155);

//3rd step
    line_d(629,155,624,80);
    line_d(599,155,604,80);
    line_d(624,80,604,80);


    line_d(624,80,629,70);
    line_d(604,80,599,70);
    line_d(629,70,599,70);


    line_d(629,70,619,60);
    line_d(599,70,609,60);
    line_d(619,60,609,60);

    line_d(609,60,614,50);
    line_d(614,50,619,60);


 //2nd right minar


//1st step

   line_d(515,325,520,287);
   line_d(565,325,560,287);
   line_d(520,287,560,287);

 //2nd step

   line_d(520,287,515,277);
   line_d(560,287,565,277);
   line_d(515,277,565,277);


   line_d(520,277,525,240);
   line_d(560,277,555,240);
   line_d(525,240,555,240);

 //3rd step

   line_d(525,240,520,230);
   line_d(555,240,560,230);
   line_d(520,230,560,230);

  line_d(525,230,530,192);
  line_d(555,230,550,192);

  line_d(530,192,550,192);
      //


    line_d(555,183,550,193);
    line_d(525,182,530,192);    //line(545,182,550,182);
    line_d(525,182,555,182);



    line_d(525,182,535,172);
    line_d(555,182,545,172);
    line_d(535,172,545,172);


    line_d(535,172,540,162);
    line_d(540,162,545,172);
 }

void taj_color()
{
//coloring
	 int i,j;
	 for(j=1;j<=2;j++)
	 {
		 for(i=1;i<15;i++)
	 {
       //	  left_minars()

setfillstyle(6,i);
floodfill(6,245,15);
delay(10);
setfillstyle(10,15);
floodfill(6,255,15);
delay(10);

setfillstyle(10,15);
floodfill(8,235,15);

delay(10);

setfillstyle(6,i);
floodfill(11,160,15);
delay(10);

setfillstyle(10,15);
floodfill(15,150,15);
delay(10);


setfillstyle(6,i);
floodfill(17,75,15);
delay(10);
	
setfillstyle(10,15);
floodfill(15,67,15);
delay(10);

setfillstyle(6,i);
floodfill(25,57,15);
delay(10);


	// 2nd Left Minar

setfillstyle(10,15);
floodfill(80,320,15);
		     delay(10);
	
setfillstyle(6,i);
floodfill(81,282.5,15);
delay(10);
	
setfillstyle(10,15);
floodfill(85,272.5,15);
delay(10);

setfillstyle(6,i);
floodfill(86,235,15);
delay(10);

setfillstyle(10,15);
floodfill(90,225,15);
delay(10);

setfillstyle(6,i);
floodfill(91,187.5,15);
delay(10);

setfillstyle(10,15);
floodfill(90,180.5,15);
delay(10);

setfillstyle(6,i);
floodfill(97,170.5,15);
 delay(10);


settextstyle(1,0,4);
setcolor(i);
outtextxy(240,350,"TAJ MAHAL");
	// Main Base
	setfillstyle(6,i);         //12=i
	floodfill(256,146,15);
	delay(10);
	// Left Door Line
//	line(285, 325, 285, 200);
	setfillstyle(10,15);
	floodfill(286,326,15);
	delay(10);
	// Right Door Line

       setfillstyle(6,i);
       floodfill(323,196,15);
       delay(10);
	// Left Side
	setfillstyle(6,i);
	floodfill(226,136,15);
	delay(10);

	setfillstyle(10,15);
	floodfill(205,180,15);
	delay(10);
	// Left Rectangle Divider
	// Left Rectangle Side Structure
	setfillstyle(10,15);
	floodfill(200,320,15);
	delay(10);
	floodfill(200,220,15);
	delay(10);
	setfillstyle(6,i);
	floodfill(246,293,15);
	// Creating Left Upper Spike
	delay(10);
	setfillstyle(6,i);
	floodfill(246,228,15);
	delay(10);
	// Right Side

	setfillstyle(6,i);
	floodfill(411,136,15);
	delay(10);
	setfillstyle(10,15);
	floodfill(410,120,15);
	delay(10);

	setfillstyle(10,15);
	floodfill(390,180,15);
	delay(10);

	setfillstyle(10,15);
	floodfill(463,320,15);
	delay(10);
	floodfill(463,220,15);
	delay(10);
	setfillstyle(10,15);
	floodfill(435,180,15);
	delay(10);

	// Divider
	setfillstyle(10,15);
	floodfill(439,259,15);
	delay(10);
	// Creating Right Lower Spike

	setfillstyle(6,i);
	floodfill(431,293,15);
	delay(10);

	setfillstyle(6,i);
	floodfill(431,228,15);
	delay(10);
	setfillstyle(1,15);
	floodfill(130,60,15);
setfillstyle(6,i);
floodfill(323,15,15);
delay(10);


  // void right_minars()

  //1st right minar

setfillstyle(10,15);
floodfill(593,255,15);
delay(10);

 //2nd step

setfillstyle(6,i);
floodfill(592,245,15);
delay(10);

setfillstyle(10,15);
floodfill(597,230,15);
delay(10);

setfillstyle(6,i);
floodfill(600,160,15);
delay(10);
setfillstyle(10,15);
floodfill(610,145,15);
delay(10);

setfillstyle(6,i);
floodfill(620,75,15);
delay(10);

setfillstyle(10,15);
floodfill(622,67,15);
delay(10);
setfillstyle(6,i);
floodfill(615,57,15);
delay(10);
 //2nd right minar

//1st step

setfillstyle(10,15);
floodfill(525,320,15);
 //2nd step
delay(10);

setfillstyle(6,i);
floodfill(520,280,15);
delay(10);

setfillstyle(10,15);
floodfill(530,270,15);
delay(10);
 //3rd step


setfillstyle(6,i);
floodfill(526,235,15);
delay(10);

setfillstyle(10,15);
floodfill(540,195,15);       //
delay(10);

setfillstyle(6,i);
floodfill(530,185,15);
delay(10);

setfillstyle(10,15);
floodfill(540,177,15);
delay(10);

setfillstyle(6,i);
floodfill(543,170,15);


delay(50);
   }
   }

 i=1;
  while(!kbhit())
	{
	delay(20);
	putpixel(random(630),random(330),random(16));
	i++;
	}

}
