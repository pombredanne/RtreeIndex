/*
 * BulkLoadStream.h
 *
 *  Created on: Oct 6, 2015
 *      Author: zhoujingbo
 */

#ifndef SPATIALRTREE_BULKLOADVECSTREAM_H_
#define SPATIALRTREE_BULKLOADVECSTREAM_H_

#include <vector>
#include <iostream>
using namespace std;


// include library header file.
#include <spatialindex/SpatialIndex.h>

using namespace SpatialIndex;

#define INSERT 1
#define DELETE 0
#define QUERY 2

class BulkLoadVecStream : public IDataStream
{
public:
	BulkLoadVecStream(vector<vector<double> >& inData) : m_pNext(0),data(inData), vec_idx(0)
	{	cout<<"for debug: inData.size()"<<inData.size()<<endl;
		cout<<"create BulkLoadVecStream"<<endl;
		readNextEntry();
		cout<<"end BulkLoadVecStream"<<endl;

	}

	virtual ~BulkLoadVecStream()
	{
		if (m_pNext != 0) delete m_pNext;
	}

	virtual IData* getNext()
	{
		if (m_pNext == 0) return 0;

		RTree::Data* ret = m_pNext;
		m_pNext = 0;
		readNextEntry();
		return ret;
	}

	virtual bool hasNext()
	{
		return (m_pNext != 0);
	}

	virtual uint32_t size()
	{
		throw Tools::NotSupportedException("Operation not supported.");
	}

	virtual void rewind()
	{
		if (m_pNext != 0)
		{
			delete m_pNext;
			m_pNext = 0;
		}
		vec_idx = 0;
		readNextEntry();
	}

	void readNextEntry()
	{


		cout<<"for debug data.size():"<<data.size()<<endl;
		cout<<"for debug vec_idx:"<<vec_idx<<endl;

		if(vec_idx<data.size()){
			size_t dim = data[vec_idx].size();
			id_type id = vec_idx;
			Point p(data[vec_idx].data(),dim);
			cout<<"for debug: pritn dim:"<<dim<<endl;
			Region r(p, p);
			cout<<"for debug: print  Region.getMargin()"<<r.getMargin()<<endl;

			m_pNext = new RTree::Data(0, reinterpret_cast<byte*>(vec_idx), r, id);

			cout<<"for debug: print after inserting Region, print m_pNext.getIdentifier() "<<m_pNext->getIdentifier()<<endl;
		}
		vec_idx++;

	}

	std::ifstream m_fin;
	size_t vec_idx;
	vector<vector<double> >& data;
	RTree::Data* m_pNext;
};


#endif /* SPATIALRTREE_BULKLOADVECSTREAM_H_ */
