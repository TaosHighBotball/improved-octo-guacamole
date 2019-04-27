#include <kipr/botball.h>


void getThere(){
    while((analog(0) < 1000)){
    	mav(0, 1480);
    	mav(1, 1500);
    }
    ao();
    msleep(200);
    while((analog(0) > 1000)){
        mav(0, 1490);
    	mav(1, 1500);
    }
    ao();
    msleep(200);
    while((analog(1) < 1000)){
    	mav(0, 1480);
    	mav(1, 1500);
    }
    ao();
    msleep(200);
    set_servo_position(0, 1670);
    mav(0, 1400);
    mav(1, 1500);
    msleep(600);
    ao();
    
}
    
void swipe(){
    ao();
    mav(1, 1000);
    set_servo_position(0, 0);
    ao();
    mav(0, -1480);
    mav(1, -1500);
    msleep(800);
    ao();
    set_servo_position(0, 1670);
    ao();
    //msleep(500);
    ao();
    mav(0, 1480);
    mav(1, 1500);
    msleep(800);
    ao();
}
    
int main()
{
    wait_for_light(2);
    shut_down_in(117);
    enable_servos();
    set_servo_position(0, 1670);
    getThere();
    int i = 0;
    while(i < 6){
        swipe();
        i++;
    }
    mav(0, -1000);
    mav(1, -1000);
    msleep(200);
    ao();
    mav(1, 1500);
    msleep(500);
    ao();
    return 0;
}
