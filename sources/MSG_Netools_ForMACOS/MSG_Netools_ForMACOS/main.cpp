//
//  main.cpp
//  MSG_Netools_ForMACOS
//
//  Created by Jaewan Jeong on 2018. 3. 14..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#include <iostream>
#include <tins/tins.h>
#include "MSG_PKT_SNIFF.h"
using namespace std;
using namespace Tins;

int main(int argc, const char * argv[]) {
    MSG_PKT_SNIFF SNF = MSG_PKT_SNIFF();
    SNF.setSniffMode(true);
    SNF.stSniff("en0");
    
    
    
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
