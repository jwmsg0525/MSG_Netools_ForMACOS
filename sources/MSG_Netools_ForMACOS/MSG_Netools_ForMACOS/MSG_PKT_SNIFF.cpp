//
//  MSG_PKT_SNIFF.cpp
//  MSG_Netools_ForMACOS
//
//  Created by Jaewan Jeong on 2018. 3. 14..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#include "MSG_PKT_SNIFF.h"

MSG_PKT_SNIFF::MSG_PKT_SNIFF()
{
    cout<<"[Start MSG_PKT_SNIFF]....";
}

MSG_PKT_SNIFF::~MSG_PKT_SNIFF()
{
    cout<<"[Stop MSG_PKT_SNIFF]";
}

bool MSG_PKT_SNIFF::setSniffMode(bool onoff)
{
    this->sniffmode = onoff;
    cout<<"[Set SniffMode ";
    onoff?cout<<"true":cout<<"false";
    cout<<"]...."<<endl;
    return sniffmode;
    
}

bool MSG_PKT_SNIFF::getSniffMode()
{
    return sniffmode;
}



void MSG_PKT_SNIFF::stSniff(string interface)
{
   
    SnifferConfiguration snconfig;
    snconfig.set_promisc_mode(true);
    snconfig.set_snap_len(500);
    Sniffer snf(interface,snconfig);
    if(getSniffMode()==false){
        cout<<"Sniffmode is not enabled \"\"setSniffMode(true);\"\" First!"<<endl;
        return;
    }
    cout<<"[StartSniff]..."<<endl;
    while(getSniffMode())
    {
        if(Packet tmp = snf.next_packet())
        {
            cout<<"[Sniff Infomations]----------------------------------"<<endl;
            cout<<"TIMESTAMP:\t"<<tmp.timestamp().seconds()<<endl;
            
            if((tmp.pdu()->find_pdu<EthernetII>()))
            {
                //Layer2
                cout<<"[EthernetII Infomations]-----------------------------"<<endl;
                EthernetII *pkt_eth = tmp.pdu()->find_pdu<EthernetII>();
                cout<<"srcMAC:\t"<<pkt_eth->src_addr()<<endl;
                cout<<"dstMAC:\t"<<pkt_eth->dst_addr()<<endl;
            }
            
            if((tmp.pdu()->find_pdu<IP>()))
            {
                //Layer3
                cout<<"[Internet Protocol Infomations]----------------------"<<endl;
                IP *pkt_ip = tmp.pdu()->find_pdu<IP>();
                cout<<"srcIP:\t"<<pkt_ip->src_addr()<<endl;
                cout<<"dstIP:\t"<<pkt_ip->dst_addr()<<endl;
            }
            
            if((tmp.pdu()->find_pdu<TCP>()))
            {
                //Layer4
                cout<<"[TCP Infomations]------------------------------------"<<endl;
                TCP *pkt_tcp = tmp.pdu()->find_pdu<TCP>();
                cout<<"srcPORT:\t"<<pkt_tcp->sport()<<endl;
                cout<<"dstPORT:\t"<<pkt_tcp->dport()<<endl;
            }
            
            if((tmp.pdu()->find_pdu<UDP>()))
            {
                //Layer4
                cout<<"[UDP Infomations]------------------------------------"<<endl;
                UDP *pkt_udp = tmp.pdu()->find_pdu<UDP>();
                cout<<"srcPORT:\t"<<pkt_udp->sport()<<endl;
                cout<<"dstPORT:\t"<<pkt_udp->dport()<<endl;
                
                if(pkt_udp->find_pdu<DNS>())
                {   cout<<"[DNS]----------------------"<<endl;
                    DNS *pkt_dns =pkt_udp->find_pdu<DNS>();
                    cout<<"URL:\t"<<pkt_dns->queries()[0].dname()<<endl;
                }
            }
            
            cout<<"[Finish!!]"<<endl;
            cout<<endl<<endl;
            //system("clear");
            
        }
    }
    
}
