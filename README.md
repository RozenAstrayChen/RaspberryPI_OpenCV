# RaspberryPI_OpenCV
- Use xcode as an editor, and then throw the project to scaspberry pi through scp.
- Compiler
  - clang++
- if you want build...
```
# sudo cmake ..
# sudo make
# ./main
```
- if you want cmake to Xcode project
```
cmake -GXcode ..
```
## Not completed
1. --use pi camera store image--
2. Identfiy features


## Update 2017/8/4
1. change image track method
2. add trackFiliterObject
3. we like tennis~
## Update 2017/8/5
1. add uart for transmission
2. new raspberry pi  method in TrackFiliterObject
## Update 2017/8/10
1. complete ```Control.cpp```
2. New features in the ```Process``` Object

##Update 2017/8/17
1. Use ```Serial_termios``` to test serial port on __MAC OSX__  but It does'nt work.when use ```open(const char*...)``` which will blocking.and serial will crash......
2. I use ```ls /dev/tty.*``` to find my serial device
3. Modify argument, ex: ```Left_XXX```
