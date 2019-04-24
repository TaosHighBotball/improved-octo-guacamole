//Bob's octo guacamole
#include <kipr/botball.h>
#define seePeep (analog(2) < 800 && analog(2) > 700)
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
        move(2500);
    }
    if(black){
        ao();
        mav(0, -2000);
    }
    if(white){
        ao();
        mav(1, -2000);
    }
}

void slowClose(int port, int spos, int epos){ // slowly move any   
    int c = spos;                             // servo at any position 
    while(c != epos){                         // to any desired position
        set_servo_position(port, c);
        if(spos > epos){
            c--;
        }
        else if(spos < epos){
            c++;
        }
    }
}

void findPeeps(){
    while (!seePeep){
       lineFollow();
    }
    ao();
    cmpc(0);
    printf("%d\n",analog(2));
    cmpc(0);
    cmpc(0);
    mrp(0, 1000, 3540);
    msleep(5000);
    ao();
}

void leaveBox(){
    mav(1,1900);
    mav(0,0);
    msleep(3000);
    while (white){
           move(2000);
    }
    while (black){
           mav(0,2000);
           mav(1,500);
           msleep(3000);
           move(2000);
    }
    while (white){
           move(2000);
    }
    ao();
    move(-1000);
    msleep(600);
    while (analog(1) < 1000){
        mav(0,-2000);
        mav(1,2000);
        set_servo_position(1,1330);
    }
    while(analog(1) > 1000){
        mav(0,-2000);
        mav(1,2000);
    }
    ao();
    msleep(500);
    ao();
    int i = 0;
    while(i < 250){
        lineFollow();
        i++;
    }
    move(-1000);
    msleep(500);
    ao();
  
}

void getBack(){
    while(black){
        move(-2000);
    }
    ao();
    while(analog(0) < 2000){
        mav(1, -1000);
    }
    ao();
    while(black){
        move(2000);
    }
    while(!(analog(0) && analog(1) > 1500)){
        move(2000);
    }
    ao();
    
}


void grabPeeps(){ //grab people off the skybridge and out of the flood zone
    set_servo_position(1, 2047);
    slowClose(2, 1330, 400);
	while(digital(0) != 1){
        move(1000);
    }
    move(-500);
    msleep(200);
    ao();
    slowClose(1, 2047, 1218);
    slowClose(2, 400, 1006);
    move(-1000);
    msleep(800);
    ao();
    move(500);
    msleep(200);   
    ao();
    slowClose(1, 1018, 1000);
    msleep(1000);
    move(-1000);
    msleep(2000);
    ao();
}

int main()
{
    //wait_for_light(6);
    shut_down_in(119);
    enable_servos();
    set_servo_position(1, 1100);
    set_servo_position(2, 1330);
    
    leaveBox();
    findPeeps();
    grabPeeps();
    getBack();
    return 0;
}

