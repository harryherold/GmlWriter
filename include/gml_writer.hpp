/*
 * gml_writer.hpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */

#ifndef SRC_GML_WRITER_HPP_
#define SRC_GML_WRITER_HPP_
#include <fstream>
#include <string>

namespace gw
{

enum class EdgeStyle: uint64_t
{
	Default,
	Dotted,
	DashedDotted,
};

enum class Shape: uint64_t
{
	Rectangle,
	Roundrectangle,
	Ellipse,
	Triangle
};

struct Geometry
{
	double x;
	double y;
	double w;
	double h;
};

class GmlWriter
{

public:
	GmlWriter(const char *, bool, bool, const std::string &);

	void writeNode(uint64_t id, const char * label);

	template<typename...Rest>
	void writeNode(uint64_t id, const char * label, Rest&... rest)
	{
		writeNodeBegin();
		writeId(id);
		writeLabel(label);
		writeGraphicsBegin();
		writeNodeAttribute(rest...);
		writeEnd();
		writeEnd();
	}

	void writeEdge(uint64_t id_src, uint64_t id_dest);

	void writeEdge(uint64_t id_src, uint64_t id_dest, const char *);

	template<typename...Rest>
	void writeEdge(uint64_t id_src, uint64_t id_dest, const char * label,  Rest&... rest)
	{
		writeEdgeBegin();
		writeEdgeDirection(id_src, id_dest);
		writeLabel(label);
		writeGraphicsBegin();
		writeTargetArrow();
		writeEdgeAttribute(rest...);
		writeEnd();
		writeEnd();
	}

	~GmlWriter();

private:
	std::ofstream fileOut_;
	bool bHierarchic_;
	bool bDirected_;

	void writeNodeBegin();
	void writeEdgeBegin();
	void writeEdgeDirection(uint64_t, uint64_t);
	void writeLabel(const char * l);
	void writeId(uint64_t id);
	void writeNodeAttribute(Shape & s);
	void writeNodeAttribute(Geometry & c);
	void writeEdgeAttribute(EdgeStyle &);
	void writeTargetArrow();
	void writeEnd();

	void writeGraphicsBegin();

	const char * getShapeText(Shape);
	const char * getEdgeStyleText(EdgeStyle);

	template<typename First,typename...Rest>
	void writeNodeAttribute(const First& first, Rest&... rest)
	{
		writeNodeAttribute(first);
		writeNodeAttribute(rest...);
	}
	template<typename First,typename...Rest>
	void writeEdgeAttribute(const First& first, Rest&... rest)
	{
		writeEdgeAttribute(first);
		writeEdgeAttribute(rest...);
	}
};

}

#endif /* SRC_GML_WRITER_HPP_ */
