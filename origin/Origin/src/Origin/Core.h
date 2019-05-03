#pragma once


#ifdef OG_PLATFORM_WINDOWS
	#ifdef ORIGIN_DLL
		#define ORIGIN_API __declspec(dllexport) 
	#else
		#define ORIGIN_API __declspec(dllimport) 

	#endif // ORIGIN_DLL 
#else
	#error Origin only support windows!
#endif // OG_PLATFORM_WINDOWS
