/*
 * SpatialRtree.h
 *
 *  Created on: Oct 5, 2015
 *      Author: zhoujingbo
 */

#ifndef SPATIALRTREE_SPATIALRTREE_H_
#define SPATIALRTREE_SPATIALRTREE_H_

#include <vector>
using namespace std;

// include library header file.
#include <spatialindex/SpatialIndex.h>
using namespace SpatialIndex;

class SpatialRtree {
public:
	SpatialRtree();
	virtual ~SpatialRtree();

	void loadData(vector<vector<float> > data);

	ISpatialIndex* stree;
};

#endif /* SPATIALRTREE_SPATIALRTREE_H_ */
