/*
 * RstarTree.h
 *
 *  Created on: Oct 1, 2015
 *      Author: zhoujingbo
 */

#ifndef BOOSTRTREE_RSTARTREE_H_
#define BOOSTRTREE_RSTARTREE_H_


#include <iostream>
using namespace std;

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>

#include <boost/geometry/index/rtree.hpp>

// to store queries results
#include <vector>
using namespace std;




class RstarTree {
public:
	RstarTree();
	virtual ~RstarTree();

	void queryData(vector<vector<float> > data);


};

#endif /* BOOSTRTREE_RSTARTREE_H_ */
