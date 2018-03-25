//
//  MSG_PKT_GEN.cpp
//  MSG_Netools_ForMACOS
//
//  Created by Jaewan Jeong on 2018. 3. 14..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#include "MSG_PKT_GEN.hpp"

MSG_PKT_GEN::MSG_PKT_GEN()
{
    
}
//setting Hardware and ip protocol
void MSG_PKT_GEN::setHW(string interface, string srcMAC, string dstMAC)
{
    
    this->hwsetting.interface = interface;
    this->hwsetting.srcMAC = srcMAC;
    this->hwsetting.dstMAC = dstMAC;
    this->hwsetting.HWenable = true;
    
}
void MSG_PKT_GEN::setIP(string srcIP, string dstIP)
{
    this->ipsetting.srcIP = srcIP;
    this->ipsetting.dstIP = dstIP;
    this->ipsetting.IPenable = true;
}

//make packet (Not Need L1L2);
void MSG_PKT_GEN::makeArp(string srcIP, string srcMAC, string dstIP, string dstMAC)
{
    Packet pkt;
    ARP rp = ARP();
    rp.sender_hw_addr(srcMAC);
    rp.sender_ip_addr(srcIP);
    rp.target_hw_addr(dstMAC);
    rp.target_ip_addr(dstIP);
    pkt = rp;
    this->pkt = pkt;
}
void MSG_PKT_GEN::makeARPSF(string vicIP, string vicMAC, string myIP, string myMAC, string gtIP, string gtMAC)
{
    Packet togt;
    Packet tovic;
    
    ARP rptovic = ARP();
    rptovic.sender_hw_addr(myMAC);
    rptovic.sender_ip_addr(gtIP);
    rptovic.target_hw_addr(vicMAC);
    rptovic.target_ip_addr(vicIP);
    tovic = rptovic;
    ARP rptogt = ARP();
    rptogt.sender_hw_addr(myMAC);
    rptogt.sender_ip_addr(vicIP);
    rptogt.target_hw_addr(gtMAC);
    rptogt.target_ip_addr(gtIP);
    togt = rptogt;
    
    
}

//make packet (Need L1L2);
void MSG_PKT_GEN::makeDNSQR(string cname, string seerverIp)
{
    
}
void MSG_PKT_GEN::makeDNSRS(string cname, string ip, string serverIP)
{
    
}
void MSG_PKT_GEN::makeHttp(string url, string mathod, string header, string param)
{
    
}

//sendpacket;
void MSG_PKT_GEN::sending()
{
    
}


MSG_PKT_GEN::~MSG_PKT_GEN()
{
    
}
