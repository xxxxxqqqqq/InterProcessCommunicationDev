#ifndef DEFINED_TYPEDEF_FOR_ALL_SOCKETS_
#define DEFINED_TYPEDEF_FOR_ALL_SOCKETS_

#include <string>
#include <list>
#include <zmq.hpp>

class AvailableSockets
{
    std::list<void(*)> initialized_sockets;
    void *soc001 = NULL;
    void *soc002 = NULL;
    void *soc003 = NULL;
    void *soc004 = NULL;
    void *soc005 = NULL;
    void *soc006 = NULL;
    void *soc007 = NULL;
    void *soc008 = NULL;
    void *soc009 = NULL;
    void *soc010 = NULL;
    void *soc011 = NULL;
    void *soc012 = NULL;
    void *soc013 = NULL;
    void *soc014 = NULL;
    void *soc015 = NULL;
    void *soc016 = NULL;
    void *soc017 = NULL;
    void *soc018 = NULL;
    void *soc019 = NULL;
    void *soc020 = NULL;

public:
    AvailableSockets();

    void InitializeSockets();
    std::list<void(*)> GetSockets(int inputsockets, int outputsockets);
};

#endif