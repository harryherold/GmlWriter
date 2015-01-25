/*
 * gml_writer.cpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */
#include "gml_writer.hpp"
#include <iomanip>

using namespace gw;

GmlWriter::GmlWriter(const char * file, bool h, bool d, const std::string & label)
:fileOut_{file},bHierarchic_{h},bDirected_{d}
{
	fileOut_ << "graph\n[\n";
	fileOut_ << "hierarchic " << h << '\n';
	fileOut_ << "label " << '"' << label << '"' << "\n";
	fileOut_ << "directed " << d << '\n';
}

GmlWriter::~GmlWriter()
{
	if (fileOut_.is_open())
	{
		fileOut_ << "]\n";
		fileOut_.close();
	}
}

const char * GmlWriter::getShapeText(Shape s)
{
	switch (s)
	{
	case Shape::Rectangle:
		return "rectangle";
	case Shape::Roundrectangle:
		return "roundrectangle";
	case Shape::Ellipse:
		return "ellipse";
	case Shape::Triangle:
		return "triangle";
	}
	return nullptr;
}

const char * GmlWriter::getEdgeStyleText(EdgeStyle es)
{
	switch (es)
	{
		case EdgeStyle::Dotted:
			return "dotted";
		case EdgeStyle::DashedDotted:
			return "dashed_dotted";
		case EdgeStyle::Default:
			return "";
	}
	return "";
}

void GmlWriter::writeNodeBegin()
{
	fileOut_ << "node\n";
	fileOut_ << "[\n";
}

void GmlWriter::writeEdgeBegin()
{
	fileOut_ << "edge\n";
	fileOut_ << "[\n";
}

void GmlWriter::writeEdgeDirection(uint64_t s, uint64_t d)
{
	fileOut_ << "source " << s << '\n';
	fileOut_ << "target " << d << '\n';
}

void GmlWriter::writeGraphicsBegin()
{
	fileOut_ << "graphics\n";
	fileOut_ << "[\n";
}

void GmlWriter::writeEnd()
{
	fileOut_ << "]\n";
}

void GmlWriter::writeLabel(const char * l)
{
	fileOut_ << "label " << '"' << l << '"' << "\n";
}

void GmlWriter::writeId(uint64_t id)
{
	fileOut_ << "id " << id << '\n';
}

void GmlWriter::writeNodeAttribute(Shape & s)
{
	fileOut_ << "type " << '"' << getShapeText(s) << '"' << "\n";
}

void GmlWriter::writeNodeAttribute(Geometry & c)
{
	fileOut_ << "x " << c.x << "\n";
	fileOut_ << "y " << c.y << "\n";
	fileOut_ << "w " << c.w << "\n";
	fileOut_ << "h " << c.h << "\n";
}

void GmlWriter::writeNode(uint64_t id, const char * label)
{
	writeNodeBegin();
	writeId(id);
	writeLabel(label);
	writeEnd();
}

void GmlWriter::writeEdge(uint64_t id_src, uint64_t id_dest)
{
	writeEdgeBegin();
	writeEdgeDirection(id_src, id_dest);
	writeEnd();
}

void GmlWriter::writeEdge(uint64_t id_src, uint64_t id_dest, const char * label)
{
	writeEdgeBegin();
	writeEdgeDirection(id_src, id_dest);
	writeLabel(label);
	writeEnd();
}

void GmlWriter::writeEdgeAttribute(EdgeStyle & es)
{
	fileOut_ << "style " << '"' << getEdgeStyleText(es) << '"' << '\n';
}

void GmlWriter::writeTargetArrow()
{
	fileOut_ << "targetArrow " << '"' << "standard" << '"' << '\n';
}
