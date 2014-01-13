#include "blendMeshDeformer.h"
#include "bulgeDeformer.h"
#include "sphereCollideDeformer.h"

#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus status;

	MFnPlugin fnPlugin(obj, "Gnaf", "1.0", "Any");

	status = fnPlugin.registerNode("blendMesh",
		BlendMesh::id,
		BlendMesh::creator,
		BlendMesh::initialize,
		MPxNode::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode("bulgeMesh",
		BulgeDeformer::id,
		BulgeDeformer::creator,
		BulgeDeformer::initialize,
		MPxNode::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode("sphereCollide",
		SphereCollideDeformer::id,
		SphereCollideDeformer::creator,
		SphereCollideDeformer::initialize,
		MPxNode::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);


	return MS::kSuccess;
}


MStatus uninitializePlugin(MObject obj)
{
	MStatus status;

	MFnPlugin fnPlugin(obj);

	status = fnPlugin.deregisterNode(BlendMesh::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(BulgeDeformer::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(SphereCollideDeformer::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}
