/*
 * WrapperSpatialRtree.cpp
 *
 *  Created on: Oct 6, 2015
 *      Author: zhoujingbo
 */

#include "WrapperSpatialRtree.h"

#include <vector>
#include <iostream>
using namespace std;

#include "SpatialRtree.h"

WrapperSpatialRtree::WrapperSpatialRtree() {
	// TODO Auto-generated constructor stub

}

WrapperSpatialRtree::~WrapperSpatialRtree() {
	// TODO Auto-generated destructor stub
}

void test_toy(){
	cout<<"prepare toy data for testing"<<endl;
	int dim = 500;
	int N = 50000;

	vector<vector<double> > data;

	for (int i=0;i<N;i++){
		vector<double> vi;
		for(int j=0;j<dim;j++){
			vi.push_back(j+i);
		}
		data.push_back(vi);
	}

	SpatialRtree rt;
	cout<<"start loading data"<<endl;
	rt.loadData(data);
	cout<<"end loading data"<<endl;

}

void WrapperSpatialRtree:: run_spatialRtree(){
	test_toy();

}
