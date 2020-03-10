#ifndef Include_FOREACH_HPP
#define Include_FOREACH_HPP

// Preprocessor trick to allow nested loops
#define Include_PP_CAT_IMPL(a, b) a ## b
#define Include_PP_CAT(a, b) Include_PP_CAT_IMPL(a, b)
#define Include_ID(identifier) Include_PP_CAT(auroraDetail_, identifier)
#define Include_LINE_ID(identifier) Include_PP_CAT(Include_ID(identifier), __LINE__)


// Macro to emulate C++11 range-based for loop
// Instead of for (decl : range) you write FOREACH(decl, range) as in the following example
//
// std::vector<int> v = ...;
// FOREACH(int& i, v)
// {
//     i += 2;
// }
#define FOREACH(declaration, container)																											\
	if (bool Include_LINE_ID(broken) = false) {} else																								\
	for (auto Include_LINE_ID(itr) = (container).begin(); Include_LINE_ID(itr) != (container).end() && !Include_LINE_ID(broken); ++Include_LINE_ID(itr))	\
	if (bool Include_LINE_ID(passed) = false) {} else																								\
	if (Include_LINE_ID(broken) = true, false) {} else																								\
	for (declaration = *Include_LINE_ID(itr); !Include_LINE_ID(passed); Include_LINE_ID(passed) = true, Include_LINE_ID(broken) = false)

#endif // Include_FOREACH_HPP
