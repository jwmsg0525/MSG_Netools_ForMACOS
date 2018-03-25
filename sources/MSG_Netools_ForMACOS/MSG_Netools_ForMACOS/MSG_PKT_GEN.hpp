//
//  MSG_PKT_GEN.hpp
//  MSG_Netools_ForMACOS
//
//  Created by Jaewan Jeong on 2018. 3. 14..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#ifndef MSG_PKT_GEN_hpp
#define MSG_PKT_GEN_hpp

#include<iostream>
#include<tins/tins.h>
#include<unistd.h>

using namespace std;
using namespace Tins;

typedef struct HWstruct
{
    bool HWenable;
    string interface;
    string srcMAC;
    string dstMAC;
}HWstruct;

typedef struct IPstruct
{
    bool IPenable;
    string srcIP;
    string dstIP;
    
}IPstruct;

typedef struct TCPstruct
{
    bool TCPenable;
    string srcPort;
    string dstPort;
}TCPstruct;

typedef struct ARPstruct
{
    bool ARPenable;
    int mode; // 1 : request, 2: response
    string srcIP;
    string srcMAC;
    string dstIP;
    string dstMAC;
    string gtIP;
    string gtMAC;
}ARPstruct;

typedef struct DNSstruct
{
    bool DNSenable;
    int mode; // 1: Quary, 2: response
    string cname;
    string ip;
    string racode;
    string serverIP;
    
}DNSstruct;



class MSG_PKT_GEN
{
public:
    MSG_PKT_GEN();
    //setting Hardware and ip protocol
    void setHW(string interface, string srcMAC, string dstMAC);
    void setIP(string srcIP, string dstIP);
    
    //make packet (Not Need L1L2);
    void makeArp(string srcIP, string srcMAC, string dstIP, string dstMAC);
    void makeARPSF(string vicIP, string vicMAC, string myIP, string myMAC, string gtIP, string gtMAC);
    
    //make packet (Need L1L2);
    void makeDNSQR(string cname, string seerverIp);
    void makeDNSRS(string cname, string ip, string serverIP);
    void makeHttp(string url, string mathod, string header, string param);
    
    //sendpacket;
    void sending();
    
    ~MSG_PKT_GEN();
    
private:
    HWstruct hwsetting;
    IPstruct ipsetting;
    Packet pkt;
    bool sniffmode = false;
    
};



#endif /* MSG_PKT_GEN_hpp */
