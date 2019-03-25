//Bob's octo guacamole
#include <kipr/botball.h>

void move(int speed){ //move forward or backward at desired speed
    mav(0, speed);
    mav(1, speed);
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

void empetyBox(){
    
}

void grabPeeps(){ //grab people off the skybridge and out of the flood zone
    set_servo_position(2, 2047);
    set_servo_position(3, 990);
	while(digital(0) != 1){
        move(1000);
    }
    ao();
    slowClose(2, 2047, 1090);
    slowClose(3, 990, 1890);
    move(-1000);
    msleep(1000);
    ao();
    slowClose(2, 1050, 1050);
    msleep(1000);
    move(-1000);
    msleep(2000);
    ao();
}

int main()
{
    //wait_for_light(6);
    //shut_down_in(119);
    enable_servos();
    
    grabPeeps();
    return 0;
}
