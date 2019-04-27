
  //Bob's octo guacamole
#include <kipr/botball.h>
#define seePeep (analog(5) < 630 && analog(5) > 570)
#define black (analog(0) && analog(1) > 1000)
#define white (analog(0) && analog(1) < 1000)
//looked at from back
#define whiteBlack (analog(0) < 1000 && analog(1) > 1000)

void move(int speed){ //move forward or backward at desired speed
    mav(0, speed);
    mav(1, speed);
}

void lineFollow(){
    if(whiteBlack){
        ao();
        move(1500);
    }
    if(black){
        ao();
        mav(0, 1500);
    }
    if(white){
        ao();
        mav(1, 1500);
    }
}


       


void leaveBox(){
    while (white){
    	mav(0,2000);
    	mav(1,0);
    }
    ao();
    mav(0, 300);
    msleep(180);
    ao();
    while (black){
        move(2000);     
    }
    while(white){
        mav(0,2000);
        mav(1,1550);
    }
    while(black){
        move(-2000);
        //msleep(800);
    }
    while(white){
        move(2000);
        //msleep(800);
        
    }
    while(black){
        mav(1,1000);
        mav(0,0);
        move(1000);
    }
      
    while(white){
        mav(1,1000);
        mav(0,0);
    }
    int i = 0;
    while (i < 900){
        lineFollow();
        i++;
    }
}
void getBack(){
   while (analog(1)>1000){
    mav(0,0);
    mav(1,1000);

}
    while(white){
        mav(1,1000);
        mav(0,-1000);
    }
    while(black){
        move(1000);
    }
    while(white){
        mav(0,1000);
        mav(1,800);
    }
    while(black){
        mav(0,1000);
        mav(1,0);
    }
    mav(0,1000);
    mav(1,0);
    msleep(2200);
    move(1000);
    msleep(400);  

}

  

int main()
{

    wait_for_light(4);
    shut_down_in(117);
    leaveBox();
    lineFollow();
    getBack();
    return 0;
}

