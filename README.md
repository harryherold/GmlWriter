# GmlWriter
Writes GML(Graph Modelling Language) files.
The following example creates a directed hierarchic graph with four nodes
and four edges.
```C++
#include "gml_writer.hpp"

using namespace gw;

int main()
{
	const char * file = "/home/harry/GmlWriter/test/test.gml";
	GmlWriter g(file,true, true,"MyGraph");

	g.writeNode(1,"foo");
	g.writeNode(2, "3.14");

	Shape shape_elipse = Shape::Ellipse;

	g.writeNode(3, "bar", shape_elipse);
	g.writeNode(4, "4");

	g.writeEdge(1, 2);
	g.writeEdge(1, 3);

	EdgeStyle es = EdgeStyle::Dotted;
	g.writeEdge(2, 4, "1.2", es);
	g.writeEdge(3, 4, "baz", es);

	return 0;
}
```
If you want to visualize the graph you can use yEd:

![](https://github.com/harryherold/GmlWriter/blob/master/example-output/test.jpg)
