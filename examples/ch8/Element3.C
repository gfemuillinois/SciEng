
#include "examples/ch8/Element3.h"

Number Element::maxAngle() const {
    Number maxang = 0.0;
    for (NodesOfElement nodes(*this); nodes.more(); nodes.advance()) {
                           Number angle = nodes.current().angle(nodes.cwNeighbor(), nodes.ccwNeighbor());
                           if ( angle > maxang ) maxang = angle;
    }
    return maxang;
}
