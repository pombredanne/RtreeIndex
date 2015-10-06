/*
 * WrapperRstarTree.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: zhoujingbo
 */

#include "../boostRtree/WrapperRstarTree.h"

#include "../boostRtree/RstarTree.h"

WrapperRstarTree::WrapperRstarTree() {
	// TODO Auto-generated constructor stub

}

WrapperRstarTree::~WrapperRstarTree() {
	// TODO Auto-generated destructor stub
}

void test_data(){

	vector<vector<float> > data;

	for(int i=0;i<10;i++){
		vector<float> vi;
		for (int j = 0;j<5;j++){
			vi.push_back(j+i);
		}
		data.push_back(vi);
	}

	RstarTree rt;
	rt.queryData(data);
}

void WrapperRstarTree::run_rtree(){

	test_data();

}
