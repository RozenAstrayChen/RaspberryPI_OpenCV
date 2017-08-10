//
//  Control.cpp
//  main
//
//  Created by 陳家麒 on 2017/8/6.
//
//

#include "Control.hpp"

using namespace std;
void Control::test_direction(){
    char input;
    do {
        input = getch();
        printf("%x",input);
        
    } while (input != 27);
    
}
void Control::Control_left(int value){
    byte2_4byte(value);
    Send(value);
}
void Control::Control_right(int value){
    byte2_4byte(value);
    Send(value);
}
void Control::Control_ahead(int value){
    byte2_4byte(value);
    Send(value);
}
void Control::Control_Back(int value){
    byte2_4byte(value);
    Send(value);
}
void Control::Control_Turn_back(int value){
    byte2_4byte(value);
    Send(value);
}
string Control::byte2_4byte(int value){
    int value_int = (int)value;
    char* temp = nullptr;

    string s = to_string(value_int);
    if(s.size()<=4){
        sprintf(temp, "%04d",value_int);
        s.assign(temp);
        
    }else if(s.size()>4){
        return "funcking_error";
    }else{
        
    }
    cout << s << endl;
    return  s;
}
int Control::getch(){
    int ch;
    struct termios oldt, newt;
    
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK |
                      ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}

