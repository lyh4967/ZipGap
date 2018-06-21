#include "Structure.h"


Point Structure::GetPoint() const { return point; }
string Structure::GetName() const { return name; }
void Structure::Link(Point item) {
	linkedStructure.InsertItem(item);
}
UnsortedType<Point> Structure::GetLinkList() const {
	return linkedStructure;
}
//friend ostream& operator<<(ostream& os, const Structure& structure) {//지도에출력
//	os << structure.name << structure.point;
//	return os;
//}