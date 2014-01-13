Maya-blendMesh
==============

Maya blendMesh/ bulgeMesh/ sphereCollide plugin

--------------------------------------------------

In Maya pluginmanager Load compiled blendMesh.mll

--------------------------------------------------

To build blendMesh.mll in visual studio:


Visual studio project prefs change:

-Linker general: Output File: change .dll into .mll

-Linker general additional library directories: C:\Program Files\Autodesk\Maya2012\lib

-Linker input additional dependencies: Foundation.lib;OpenMaya.lib;OpenMayaUI.lib;OpenMayaAnim.lib;

OpenMayaFX.lib;OpenMayaRender.lib;Image.lib;opengl32.lib;glu32.lib

-Linker Command Line Additional Options: /export:initializePlugin /export:uninitializePlugin

-C/C++ general Additional Include Directories: C:\Program Files\Autodesk\Maya2012\include

-C/C++ preprocessor Preprocessor Defenitions: WIN32;NDEBUG;_ WINDOWS;NT_ PLUGIN;REQUIRE_IOSTREAM

---------------------------------------------------

-Visual studio: start win32 project: .dll and empty

-compile: config x64

---------------------------------------------------
---------------------------------------------------

Maya create deformer in mel cmdline:


deformer -type blendMesh

deformer -type bulgeMesh

deformer -type sphereCollide

---------------------------------------------------
