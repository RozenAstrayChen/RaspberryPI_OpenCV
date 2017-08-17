//
//  Serial_termios.cpp
//  main
//
//  Created by 陳家麒 on 2017/8/17.
//
//

#include "Serial_termios.hpp"
using namespace std;

Serial_termios::Serial_termios(string deviceName, int baud){
    handle = -1;
    Open(deviceName, baud);
}
Serial_termios::~Serial_termios(){
    if(handle >=0)
        Close();
}
void Serial_termios::Close(){
    if(handle >=0)
        close(handle);
    handle = -1;
}
bool Serial_termios::Open(string devicename, int baud){
    
    struct termios options;
    this->devicename = devicename;
    this->baud = baud;
    //handle = open(this->devicename.c_str() ,O_RDONLY | O_NOCTTY | O_NOCTTY);
    handle  = open(this->devicename.c_str(),O_RDWR | O_NOCTTY /* | O_NONBLOCK */);
    if(handle<0){
        printf("init Serial failed!\n");
        return false;
    }
    //CONFIGURE THE UART
    //The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
    //	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
    //	CSIZE:- CS5, CS6, CS7, CS8
    //	CLOCAL - Ignore modem status lines
    //	CREAD - Enable receiver
    //	IGNPAR = Ignore characters with parity errors
    //	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
    //	PARENB - Parity enable
    //	PARODD - Odd parity (else even)
    tcgetattr(handle, &options);
    options.c_cflag = baud | CS8 | PARENB | CLOCAL | CREAD; // set baud
    options.c_iflag = IGNCR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(handle, TCIFLUSH);
    tcsetattr(handle, TCSANOW, &options);
    
    return  true;
    
}
bool Serial_termios::IsOpen(){
    return (handle >=0);
}
bool Serial_termios::Send( unsigned char  * data,int len){
    if(!IsOpen()) return false;
    int rlen= write(handle,data,len);
    return(rlen == len);
}
bool Serial_termios::Send(unsigned char value){
    if(!IsOpen()) return false;
    int rlen= write(handle,&value,1);
    return(rlen == 1);
}
bool Serial_termios::Send(string value){
    if(!IsOpen()) return false;
    int rlen= write(handle,value.c_str(),value.size());
    return(rlen == value.size());
}
int Serial_termios::Receive(unsigned char *data, int len){
    if(!IsOpen()) return -1;
    
    // this is a blocking receives
    int lenRCV=0;
    while(lenRCV < len)
    {
        int rlen = read(handle,&data[lenRCV],len - lenRCV);
        lenRCV+=rlen;
    }
    return  lenRCV;
}
