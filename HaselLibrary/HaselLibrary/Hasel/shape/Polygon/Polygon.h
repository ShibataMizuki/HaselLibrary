#pragma once

#include<vector>
#include"shape/ShapeBase/ShapeBase.h"
#include"shape/Segment/Segment.h"

namespace hasel
{
	namespace shape
	{
		class Polygon :public ShapeBase
		{
		private:
			std::vector<sptr<Segment>> segments;
		};
	}
}