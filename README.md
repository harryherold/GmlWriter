# GmlWriter
Writes GML(Graph Modelling Language) files.
The following example creates a directed hierarchic graph with four nodes
and four edges.
```C++
GmlWriter g(file,true, true,"MyGraph");

g.writeNode<const char *>(1,"foo");
g.writeNode<double>(2,3.14);
g.writeNode<std::string>(3,"bar");
g.writeNode<int>(4,4);

g.writeEdge(1,2);
g.writeEdge(1,3);
g.writeEdge(2,4);
g.writeEdge(3,4);
```
If you want to visualize the graph you can use yEd:

![](https://github.com/harryherold/GmlWriter/blob/master/example-output/test.jpg)
