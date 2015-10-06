/*
 * SpatialRtree.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: zhoujingbo
 */

#include "SpatialRtree.h"

#include <vector>
using namespace std;

using namespace SpatialIndex;


SpatialRtree::SpatialRtree() {
	// TODO Auto-generated constructor stub

	stree = NULL;

}

SpatialRtree::~SpatialRtree() {
	// TODO Auto-generated destructor stub

	if(stree!=NULL){
		delete stree;
	}
}

void SpatialRtree::loadData(vector<vector<float> > data){

	stree = StorageManager::createNewDiskStorageManager(baseName, 4096);
}



