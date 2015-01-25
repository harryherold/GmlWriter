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

enum class Shape: uint64_t
{
	Rectangle,
	Roundrectangle,
	Ellipse,
	Triangle
};

const char * getShapeText(Shape s);

struct Coordinate
{
	uint64_t x;
	uint64_t y;
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


	template<typename T>
	void writeEdge(uint64_t id_src, uint64_t id_dest, T label)
	{
		writeEdgeBegin();
		writeLabel<T>(label);
		writeEdgeDirection(id_src, id_dest);
		writeEnd();
	}

	void writeEdge(uint64_t id_src, uint64_t id_dest)
	{
		writeEdgeBegin();
		writeEdgeDirection(id_src, id_dest);
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
	void writeEnd();

	void writeGraphicsBegin();

	const char * getShapeText(Shape);

	template<typename First,typename...Rest>
	void writeNodeAttribute(const First& first, Rest&... rest)
	{
		writeNodeAttribute(first);
		writeNodeAttribute(rest...);
	}
	{
		fileOut_ << "label " << '"' << l << '"' << "\n";
	}
};

}

#endif /* SRC_GML_WRITER_HPP_ */
