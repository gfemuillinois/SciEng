/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
class VoltageSupply {};
class Acme130 : public VoltageSupply {};
template<class D, class B> class CopyableWrapper1d;
template<class D, class B> class ShareableWrapper1d;
template<class D> class NewPtr;



extern CopyableWrapper1d<Acme130, VoltageSupply>  copyWrap(const NewPtr<Acme130>& p);
extern ShareableWrapper1d<Acme130, VoltageSupply> shareWrap(const NewPtr<Acme130>& p);


