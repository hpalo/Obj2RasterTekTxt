# Obj2RasterTekTxt
This is a simple converter from Wavefront's .obj format to the Raster Tek's txt format used in their tutorials at https://www.rastertek.com/. By using this you can create models e.g. in Blender, and after conversion load them into the tutorials. 

This converter takes into account the next four tags:
- v (vertex position)
- vt (texture coordinates)
- vn (normals)
- f (face or triangle in this case)

For example the following .obj file exported from Blender can be converted to the Raster Tek's format:
<pre>
# Blender 4.3.2
# www.blender.org
o Pyramid
v -1.000000 0.000000 1.000000
v -1.000000 0.000000 -1.000000
v 1.000000 0.000000 1.000000
v 1.000000 0.000000 -1.000000
v 0.000000 1.000000 0.000000
vn -0.7071 0.7071 -0.0000
vn -0.0000 0.7071 -0.7071
vn -0.0000 0.7071 0.7071
vn 0.7071 0.7071 -0.0000
vn -0.0000 -1.0000 -0.0000
vt 0.001113 0.001113
vt -0.704420 0.500000
vt 0.001113 0.998887
vt 0.998887 0.998887
vt 0.500000 1.704420
vt 0.998887 0.001113
vt 0.500000 -0.704420
vt 1.704420 0.500000
s 0
f 1/1/1 5/2/1 2/3/1
f 4/4/2 2/3/2 5/5/2
f 1/1/3 3/6/3 5/7/3
f 3/6/4 4/4/4 5/8/4
f 1/1/5 4/4/5 3/6/5
f 1/1/5 2/3/5 4/4/5
</pre>
When this is converted, we get:

<pre>
Vertex Count: 18

Data:

-1 0 1 0.001113 0.001113 -0.7071 0.7071 -0
0 1 0 -0.70442 0.5 -0.7071 0.7071 -0
-1 0 -1 0.001113 0.998887 -0.7071 0.7071 -0
1 0 -1 0.998887 0.998887 -0 0.7071 -0.7071
-1 0 -1 0.001113 0.998887 -0 0.7071 -0.7071
0 1 0 0.5 1.70442 -0 0.7071 -0.7071
-1 0 1 0.001113 0.001113 -0 0.7071 0.7071
1 0 1 0.998887 0.001113 -0 0.7071 0.7071
0 1 0 0.5 -0.70442 -0 0.7071 0.7071
1 0 1 0.998887 0.001113 0.7071 0.7071 -0
1 0 -1 0.998887 0.998887 0.7071 0.7071 -0
0 1 0 1.70442 0.5 0.7071 0.7071 -0
-1 0 1 0.001113 0.001113 -0 -1 -0
1 0 -1 0.998887 0.998887 -0 -1 -0
1 0 1 0.998887 0.001113 -0 -1 -0
-1 0 1 0.001113 0.001113 -0 -1 -0
-1 0 -1 0.001113 0.998887 -0 -1 -0
1 0 -1 0.998887 0.998887 -0 -1 -0
</pre>
That can be loaded by Raster Tek's tutorials. You must use "Triangulated Mesh" when exporting a model from Blender as Raster Tek does not support quads as a faces.

# Compiling the project
This project was created using Visual Studio and Windows but this should compile on other platforms as well. To build the project on Windows create an empty project or a console project and remove all existing files. Copy all files in the source folder into the project's directory. Add files in the source folder into the project. If everything went well the application should build.

