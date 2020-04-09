#ifndef DEFINED_TYPEDEF_FOR_ALL_COMPONENTS_
#define DEFINED_TYPEDEF_FOR_ALL_COMPONENTS_

#include <string>
#include <list>
#include <zmq.hpp>

struct Comp_InputDetails
{
    std::string InputName;
    std::string DataType;
    int Dimension;
    int InterCompPort;

    Comp_InputDetails(std::string Name, std::string Type, int Dim, int Port) : InputName(Name), DataType(Type), Dimension(Dim), InterCompPort(Port)
    {
    }
};

struct Comp_OutputDetails
{
    std::string OutputName;
    std::string DataType;
    int Dimension;
    int InterCompPort;

    Comp_OutputDetails(std::string Name, std::string Type, int Dim, int Port) : OutputName(Name), DataType(Type), Dimension(Dim), InterCompPort(Port)
    {
    }
};

class GenericComp
{
public:
    GenericComp();

    std::list<Comp_OutputDetails> SetInterCompOutputPorts(std::list<Comp_OutputDetails> outputs, int lastport, std::string mycomp);
    std::list<Comp_InputDetails> MapInterCompInputPorts(std::list<Comp_InputDetails> inputs, std::list<Comp_OutputDetails> outputs, std::string mycomp);
    int InterCompMapInputToOutput(std::string InputName, std::list<Comp_OutputDetails> outputs);

    std::vector<int> GiveInRequestGetInReply(std::list<Comp_InputDetails> inputs, int my_portgen_port, std::string mycomp);
    std::vector<int> GiveOutRequestGetOutReply(std::list<Comp_OutputDetails> outputs, int my_portgen_port, std::string mycomp);

    void GetOutRequestGiveOutReply(std::list<Comp_OutputDetails> outputs, int my_portgen_port, std::string mycomp);
    void GetInRequestGiveInReply(std::list<Comp_InputDetails> inputs, int my_portgen_port, std::string mycomp);
   
    std::list<Comp_InputDetails> DistributeInputsToComp(std::list<Comp_InputDetails> inputs, std::vector<int> inputcollector, std::string mycomp);
    std::list<Comp_OutputDetails> DistributeOutputsToComp(std::list<Comp_OutputDetails> outputs, std::vector<int> outputcollector, std::string mycomp);

    void GiveAllowRequestGetAllowReply(int my_portgen_port, std::string mycomp, void* soc);
    void GetAllowRequestGiveAllowReply(int my_portgen_port, int comp_nbr, std::list<void(*)> mySockets);
};

#endif