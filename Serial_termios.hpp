//
//  Serial_termios.hpp
//  main
//
//  Created by 陳家麒 on 2017/8/17.
//
//

#ifndef Serial_termios_hpp
#define Serial_termios_hpp

#include <stdio.h>
#include <iostream>
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>			//Used for UART
#include <string>
using namespace std;
class Serial_termios{
public:
    
    //Constructor
    Serial_termios(string devicename,int baud);
    //Destructor
    ~Serial_termios();
    bool Send( unsigned char  * data,int len);
    bool Send(unsigned char value);
    bool Send( std::string value);
    int Receive( unsigned char  * data, int len);
    bool IsOpen(void);
    void Close(void);
    bool Open(std::string deviceName, int baud);
    bool NumberByteRcv(int &bytelen);
public:
    int handle,baud;
    string devicename;
};


#endif /* Serial_termios_hpp */
