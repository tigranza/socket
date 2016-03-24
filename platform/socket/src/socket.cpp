//
//  tsocket.cpp
//  Sockets
//
//  Created by Tigran Hovhannisyan on 19/03/2016.
//  Copyright © 2016 TIKO. All rights reserved.
//

#include "socket.hpp"

#include "dbg.hpp"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>



Socket::Socket(int sockid)
: m_sockid(sockid)
{
}

Socket::~Socket() {
    SAFE(close(m_sockid));
    TRACE("Socket closed");
}

void SocketClient::connect(std::string ip, int port)
{
    sockaddr_in addrport;
    addrport.sin_family = AF_INET;
    addrport.sin_port = htons(port);
    addrport.sin_addr.s_addr = inet_addr(ip.c_str());
    ::connect(m_sockid, (sockaddr *)&addrport, sizeof(addrport));
}

void Socket::send(std::string str) {
    SAFE(::send(m_sockid, str.c_str(), str.size(), 0));
    TRACE("Sent: " << str);
}

std::string Socket::recv() {
    return recv(m_sockid);
}

std::string Socket::recv(int sockId) {
    const int msgLen = 255;
    std::string res;
    res.resize(msgLen);
    SAFE(::recv(sockId, &res[0], msgLen, 0));
    TRACE("received: " << res);
    return res;
}