#include "SphereCollideDeformer.h"

MTypeId     SphereCollideDeformer::id(0x00007175);
MObject     SphereCollideDeformer::aCollideMatrix;


SphereCollideDeformer::SphereCollideDeformer()
{
}


SphereCollideDeformer::~SphereCollideDeformer()
{
}


void* SphereCollideDeformer::creator()
{
	return new SphereCollideDeformer();
}


MObject& SphereCollideDeformer::accessoryAttribute() const
{
	return aCollideMatrix;
}


MStatus SphereCollideDeformer::accessoryNodeSetup(MDagModifier& dagMod)
{
	MStatus status;

	MObject oLocator = dagMod.createNode("locator", MObject::kNullObj, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnDependencyNode fnLocator(oLocator, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	MPlug plugWorldMatrix = fnLocator.findPlug("worldMatrix", false, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	status = plugWorldMatrix.selectAncestorLogicalIndex(0, plugWorldMatrix.attribute());
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MObject oThis = thisMObject();
	MPlug plugCollideMatrix(oThis, aCollideMatrix);

	status = dagMod.connect(plugWorldMatrix, plugCollideMatrix);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}


MStatus SphereCollideDeformer::deform(MDataBlock& data, MItGeometry& itGeo,
	const MMatrix& localToWorldMatrix, unsigned int geomIndex)
{
	MStatus status;

	MMatrix collideMatrix = data.inputValue(aCollideMatrix).asMatrix();
	MMatrix collideMatrixInverse = collideMatrix.inverse();
	MMatrix worldToLocalMatrix = localToWorldMatrix.inverse();

	float env = data.inputValue(envelope).asFloat();

	MPoint point;
	for (; !itGeo.isDone(); itGeo.next())
	{
		point = itGeo.position();
		point *= localToWorldMatrix;
		point *= collideMatrixInverse;
		if (MVector(point).length() < 1.0)
		{
			// Matrix is colliding
			point = MVector(point).normal();
		}
		point *= collideMatrix;
		point *= worldToLocalMatrix;

		itGeo.setPosition(point);
	}

	return MS::kSuccess;
}


MStatus SphereCollideDeformer::initialize()
{
	MStatus status;

	MFnMatrixAttribute mAttr;

	aCollideMatrix = mAttr.create("collideMatrix", "collideMatrix");
	addAttribute(aCollideMatrix);
	attributeAffects(aCollideMatrix, outputGeom);

	return MS::kSuccess;
}
