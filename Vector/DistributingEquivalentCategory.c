/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class AnArray>
Boolean DistributingEquivalentCategory<AnArray>::equivalentTo(const AnArray& rhs) const {
  const AnArray& lhs = (const AnArray&)(*this);
  if (!hasSameShapeAs(lhs, rhs)) return Boolean::IsFalse;
  
  typename AnArray::BrowserType il(lhs);
  typename AnArray::BrowserType ir(rhs);
  while (il.more()) {
    if (il.current() != ir.current()) return Boolean::IsFalse;
    il.advance();
    ir.advance();
  }
  return Boolean::IsTrue;
}
