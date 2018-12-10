#pragma once

#define Nex_DEBUG

#ifdef Nex_DEBUG
#define Nex_PRINT(format,...) printf(">>Time: %s, Line: %05d, Function: %s: "format"", __TIME__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define Nex_PRINT(...) do{}while(0)
#endif


typedef struct 
{
	const char* FileVersion;
	const char* Id;
	const char* Name;
	const char* ImageData;

}Vendor_t;

typedef struct 
{
	const char* Type;
	const char* Name;
	const char* ImageData;

}group_t;