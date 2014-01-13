#ifndef SPHERECOLLIDEDEFORMER_H
#define SPHERECOLLIDEDEFORMER_H

#include <maya/MDagModifier.h>
#include <maya/MGlobal.h>
#include <maya/MFnMatrixAttribute.h>
#include <maya/MItGeometry.h>
#include <maya/MMatrix.h>
#include <maya/MPoint.h>
#include <maya/MPxDeformerNode.h>

class SphereCollideDeformer : public MPxDeformerNode
{
public:
	SphereCollideDeformer();
	virtual				~SphereCollideDeformer();
	static  void*		creator();

	virtual MStatus     deform(MDataBlock& data,
		MItGeometry& itGeo,
		const MMatrix& localToWorldMatrix,
		unsigned int geomIndex);

	virtual MObject&    accessoryAttribute() const;
	virtual MStatus     accessoryNodeSetup(MDagModifier& dagMod);


	static  MStatus		initialize();

	static MObject aCollideMatrix;

	static MTypeId	id;

};

#endif
