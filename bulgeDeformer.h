#ifndef BULGEDEFORMER_H
#define BULGEDEFORMER_H

#include <maya/MItGeometry.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MPxDeformerNode.h>
#include <maya/MFnMesh.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MVectorArray.h>
#include <maya/MGlobal.h>

class BulgeDeformer : public MPxDeformerNode
{
public:
	BulgeDeformer();
	virtual				~BulgeDeformer();
	static  void*		creator();

	virtual MStatus     deform(MDataBlock& data,
		MItGeometry& itGeo,
		const MMatrix& localToWorldMatrix,
		unsigned int geomIndex);


	static  MStatus		initialize();

	static MTypeId	id;

	static MObject aBulgeAmount;

};

#endif
