/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class Range>
LinearizedEquationsBase<Range>::LinearizedEquationsBase(
    const PhysicalData<Range>& data_to_fit,
    const DataModel<Range>& model
  ):
  the_data_ptr(data_to_fit),
  the_model(model),
  x_0(the_model.parameters()),
  the_chi2(NumericalLimits<Range>::maximum) {
}
 
