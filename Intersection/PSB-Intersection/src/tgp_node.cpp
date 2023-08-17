/**
 * Implementation of TGP node
*/
#include "../include/tgp_node.h"

/**
 * Constructor of the TGP Node class
 * 
 * @param name A string as node name, which will be used in printing node and graph, generating MILP etc.
*/
TGP_Node::TGP_Node(std::string name)
{
    node_name = name;
    delta = 0;
    next_node = NULL;
    type2 = NULL;
}

/**
 * Set the delta value of the node
 * 
 * @param set_delta The delta value want to set
*/
bool TGP_Node::SetDelta(double set_delta)
{
    delta = set_delta;
    return true;
}

/**
 * Add the pointer of the next node to the current node
 * 
 * @param next_node_ptr The pointer to the next node
 * @return The success of this operation
*/
bool TGP_Node::AddNextNode(std::shared_ptr<TGP_Node> next_node_ptr)
{
    next_node = next_node_ptr;
    return true;
}

/**
 * Add the pointer of the edge to the current node
 * 
 * @param next_node_ptr The pointer to the edge
 * @return The success of this operation
*/
bool TGP_Node::AddType2Edge(std::shared_ptr<TGP_Node> next_node_ptr)
{
    type2 = next_node_ptr;
}

/**
 * Get the value of the delta
 * 
 * @return The value of delta
*/
double TGP_Node::GetDelta()
{
    return delta;
}