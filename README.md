# Obj2RasterTekTxt
This is a simple converter from Wavefront's .obj format to the Raster Tek's txt format used in Raster Tek's tutorials at https://www.rastertek.com/ where DirectX 11 and OpenGL 4.0 are used. By using this tool you can create models e.g. in Blender and export them as .obj files, and after conversion load them into the tutorials. Take a look for example at a model loading tutorial at https://www.rastertek.com/dx11win10tut07.html.

This converter takes into account the following four tags:
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
That can be loaded by Raster Tek's tutorials. There are 8 values per row: 3 for a position, 2 for a texture coordinate and 3 for a normal. You must use "Triangulated Mesh" when exporting a model from Blender as Raster Tek does not support quads as a faces.

# Compiling the Project
This project was created using Visual Studio and Windows but this should compile on other platforms as well. First, clone the project. To build the project on Windows create an empty project. Copy the source folder into the empty project's directory. Add files in the source folder into the project in Visual Studio. For example, add .h files into "Header Files" and .cpp files into "Source Files". Finally, set C++ Language Standard to "ISO C++17 Standard" in Project Properties -> C/C++ -> Language. Build the project and use the application in command prompt in the following way:
<pre>appname pyramid.obj pyramid.txt</pre>
You can test the application using the file "pyramid.obj" that is in the repo. After conversion a converted file "pyramid.txt" should be created and it can be used in the Raster Tek's tutorials.

