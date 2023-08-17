// This file implement the PT Node
// TODO: what actually this file is working on
#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <set>
#include <tuple>
#include <vector>
#include "Common.h"
#include "Instance.h"

const double EPSILON = 0.000001;

class PTNode{
public:
	vector<Path> plan; //plan is vector of paths	size of vector = size of vehicles
	std::vector<std::vector<double>> control_points;
	std::vector<double> optimal_T;
	std::vector<double> start_time;

	std::map<int, std::set<int>> priority; //map of index with set of lower prio
	double cost;

	PTNode();
	PTNode(vector<Path>, std::vector<std::vector<double>> old_control_points, std::vector<double> old_optimal_T, std::vector<double> old_start_time, std::map<int, std::set<int> >);
	void writeToFile(Instance&, const string&);	
	void calculateCost();
	void topologicalSortUtil(int, bool*, std::list<int>&);
	std::list<int> topologicalSort();
	std::list<int> topologicalSort(int);
	std::tuple<int, int, int> getFirstCollision(Instance&);
	//void getRT(ReservationTable&, int);
	void getRTP(std::set<int>&, int);
	void getRTFromP(Instance&, ReservationTable&, std::set<int>);
	void getRTFromP(Instance&, ReservationTable&, std::set<int>, int,std::map<int, std::map<int,std::vector<int> > >&);
	void printPlan();
	double calculateDelay(std::shared_ptr<Instance> instance_ptr);
};

