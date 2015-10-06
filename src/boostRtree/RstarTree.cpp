/*
 * RstarTree.cpp
 *
 *  Created on: Oct 1, 2015
 *      Author: zhoujingbo
 */

#include "../boostRtree/RstarTree.h"

#include <vector>
using namespace std;

// just for output

#include <iostream>
using namespace std;

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>

#include <boost/geometry/index/rtree.hpp>

// to store queries results
#include <vector>

// just for output
#include <iostream>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

using namespace std;




RstarTree::RstarTree() {
	// TODO Auto-generated constructor stub


}

RstarTree::~RstarTree() {
	// TODO Auto-generated destructor stub

}
#define dim  10
typedef bg::model::point<float, dim, bg::cs::cartesian> point;
typedef std::pair<point, unsigned> value;

void RstarTree::queryData(vector<vector<float> > data){


	vector<value> values;
	values.reserve(data.size());
	for(size_t i=0;i<data.size();i++){
		point p;
		for (size_t j=0;j<dim;j++){
			p.set<0>(data[i][j]);

			values.push_back(std::make_pair(p,i));
		}
	}


	bgi::rtree<value,bgi::rstar<32> > rt( values);

	//rtree = new
	//		bgi::rtree(bgi::dynamic_rstar<nodeSize>);


}
