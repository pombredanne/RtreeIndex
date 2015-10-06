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

#include "BulkLoadVecStream.h"

SpatialRtree::SpatialRtree() {
	// TODO Auto-generated constructor stub

	stree = NULL;
	msm = NULL;

}

SpatialRtree::~SpatialRtree() {
	// TODO Auto-generated destructor stub

	if(stree!=NULL){
		delete stree;
	}

	if(msm!=NULL){
		delete msm;
	}
}



void SpatialRtree::loadData(vector<vector<double> > data){

	msm = StorageManager::createNewMemoryStorageManager();

	BulkLoadVecStream blv(data);
	double fillFactor =0.95;//Property FillFactor must be in range (0.0, 1.0) for RSTAR index type
	uint32_t indexCapacity= 4096;
	uint32_t leafCapacity = 4096;
	uint32_t dimension = data[0].size();

	id_type indexIdentifier;

//	SIDX_DLL ISpatialIndex* createAndBulkLoadNewRTree(
//				BulkLoadMethod m,
//				IDataStream& stream,
//				IStorageManager& sm,
//				double fillFactor,
//				uint32_t indexCapacity,
//				uint32_t leafCapacity,
//				uint32_t dimension,
//				RTreeVariant rv,
//				id_type& indexIdentifier
//			);

	stree = RTree::createAndBulkLoadNewRTree(
			RTree::BLM_STR,
			blv,
			*msm,
			fillFactor,indexCapacity,leafCapacity,
			dimension,
			SpatialIndex::RTree::RV_RSTAR,
			indexIdentifier);

	std::cerr << *stree;
	std::cerr << "Index ID: " << indexIdentifier << std::endl;

	bool ret = stree->isIndexValid();
	if (ret == false) std::cerr << "ERROR: Structure is invalid!" << std::endl;
		else std::cerr << "The stucture seems O.K." << std::endl;


}
