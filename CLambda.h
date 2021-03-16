#define C_LAMBDA(typeName, size, returnType, ...)\
struct typeName\
{\
	returnType(*funcPtr)(__VA_ARGS__);\
	char bin[size];\
	\
	typeName()\
	{\
		funcPtr = (returnType(*)(__VA_ARGS__))bin;\
	}\
	\
	void set(returnType(*funcPtr)(__VA_ARGS__))\
	{\
		for(unsigned int i = 0; i < size; i++)\
		{\
			*(bin + i) = *((char*)funcPtr + i);\
		}\
	}\
}

#define CALL(lambda, ...) lambda.funcPtr(__VA_ARGS__)

//returnType(*funcPtr)(__VA_ARGS__);