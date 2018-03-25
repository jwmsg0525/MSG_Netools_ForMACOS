//
//  MSG_PKT_SNIFF.h
//  MSG_Netools_ForMACOS
//
//  Created by Jaewan Jeong on 2018. 3. 14..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//


#ifndef MSG_PKT_SNIFF_h
#define MSG_PKT_SNIFF_h
#include<iostream>
#include<tins/tins.h>
#include<unistd.h>
using namespace std;
using namespace Tins;
class MSG_PKT_SNIFF{
public:
    MSG_PKT_SNIFF();
    
    //setting Sniff Mode(True == run, False == stop)
    bool setSniffMode(bool onoff);
    bool getSniffMode();
    
    //Sniff Essencial...
    void stSniff(string interface);
    
    ~MSG_PKT_SNIFF();
    
private:
    bool sniffmode = false;
    
};



#endif /* MSG_PKT_SNIFF_h */
