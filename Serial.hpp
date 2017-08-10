//
//  Serial.hpp
//  main
//
//  Created by 陳家麒 on 2017/8/5.
//
//

#ifndef Serial_hpp
#define Serial_hpp

#include <stdio.h>
#include <string>
using namespace std;
class mySerial{
public:
    int handle,baud;
    string deviceName;
    //Constructor
    mySerial(std::string deviceName, int baud);
    //Destructor
    ~mySerial();
    
    bool Send( unsigned char  * data,int len);
    bool Send(unsigned char value);
    bool Send( std::string value);
    int Receive( unsigned char  * data, int len);
    bool IsOpen(void);
    void Close(void);
    bool Open(std::string deviceName, int baud);
    bool NumberByteRcv(int &bytelen);
   
    
private:
    
};

#endif /* Serial_hpp */
