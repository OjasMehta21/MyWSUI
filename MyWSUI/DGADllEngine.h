#ifndef DGADLLENGINE_H
#define DGADLLENGINE_H

#ifdef DGADLLENGINE_EXPORTS
#define DGADLLENGINE_API __declspec(dllexport)
#else
#define DGADLLENGINE_API __declspec(dllimport)
#endif

#ifdef DGADLLENGINE_EXPORTS
extern "C" {
#endif // DGADLLENGINE_EXPORTS


// This function starts DGA engine
DGADLLENGINE_API void Startup();


// This function shuts down DGA engine
DGADLLENGINE_API void Shutdown();


// This function loads given data file into memory from HDD. 
// Only one file can be loaded at a time. This application doesn't support 
// working with multiple files simulteneously
// 
// Papameters:
//		dataFileName - file name on the local HDD
//		shapeBackWeightage - the weightage used to create shape map. 
//					100 - shape will be created from back
//					0 - shape will be created from Front
//					50  - shape will be cerated equaliy from Front and Back
//					any other value between 0 and 100, weightage will be used for back.
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadDataFile(const char* dataFileName);
DGADLLENGINE_API int loadDataFile2(const char* dataFileName, int* dataFileID);
DGADLLENGINE_API int loadDataFile3(const char* dataFileName, 
												const int shapeBackWeightage);
DGADLLENGINE_API int loadDataFile4(const char* dataFileName, 
								   const int shapeBackWeightage, int* dataFileID);

// This function loads given data file into memory from a memory stream. 
// Only one file can be loaded at a time. This application doesn't support 
// working with multiple files simulteneously
// 
// Papameters:
//		stream - memory stream that contains .pwg file content
//		streamSize - the size of the stream
//		fileID - output parameter, contains fileID that the rest of API will
//		accept to identify the loaded data file.
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadDataFileFromStream(
	const unsigned char* stream, 
	const int streamSize,
	int* fileID);


// This function loads given data file into memory from a memory stream. 
// Only one file can be loaded at a time. This application doesn't support 
// working with multiple files simulteneously
// 
// Papameters:
//		stream - memory stream that contains .pwg file content
//		streamSize - the size of the stream
//		shapeBackWeightage - weightage on the back for creating shape
//		fileID - output parameter, contains fileID that the rest of API will
//		accept to identify the loaded data file.
//		shapeBackWeightage - the weightage used to create shape map. 
//					100 - shape will be created from back
//					0 - shape will be created from Front
//					50  - shape will be cerated equaliy from Front and Back
//					any other value between 0 and 100, weightage will be used for back.
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadDataFileFromStream2(
	const unsigned char* stream,
	const int streamSize,
	const int shapeBackWeightage,
	int* fileID);


// This function unloads (releases from memory) data file with given name 
// or fileID
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		0 - Success
//		-5 - File with given name is not loaded
DGADLLENGINE_API int unloadDataFile(const char* dataFileName);
DGADLLENGINE_API int unloadDataFile2(const int dataFileID);


// This function unloads currently loaded data file if it was loaded previously
// (from previous call to loadDataFile(...))
DGADLLENGINE_API void unloadCurrentDataFiles();


// This function checks if a data file with given name is loaded in memory
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		1 - File with given name is loaded
//		0 - File with given name is not loaded
DGADLLENGINE_API int isDataFileLoaded(const char* dataFileName);
DGADLLENGINE_API int isDataFileLoaded2(const int dataFileID);


// This function returns number of rows in Thickness map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and thickness map exists
//		-2 - Thickness map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getThicknessMapRows(const char* dataFileName);
DGADLLENGINE_API int getThicknessMapRows2(const int dataFileID);


// This function returns number of rows in Thickness map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and thickness map exists
//		-2 - Thickness map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getThicknessMapColumns(const char* dataFileName);
DGADLLENGINE_API int getThicknessMapColumns2(const int dataFileID);


// This function fills out Thickness Map pixels and mask pixels indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Thickness pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid (0). 
//		Entries thicknessMap pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Thickness map is missing
//		-3 - Size of allocated buffers is different than size of loaded Thickness map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillThicknessMapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillThicknessMapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-2 - Thickness map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapeMapRows(const char* dataFileName);
DGADLLENGINE_API int getShapeMapRows2(const int dataFileID);


// This function returns number of rows in Shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-2 - Thickness map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapeMapColumns(const char* dataFileName);
DGADLLENGINE_API int getShapeMapColumns2(const int dataFileID);


// This function fills out Shape Map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillShapeMapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillShapeMapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Front 200um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFront200MapRows(const char* dataFileName);
DGADLLENGINE_API int getFront200MapRows2(const int dataFileID);


// This function returns number of columns in Front 200um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFront200MapColumns(const char* dataFileName);
DGADLLENGINE_API int getFront200MapColumns2(const int dataFileID);


// This function fills out Front 200um map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Front pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-7 - Front map is missing
//		-3 - Size of allocated buffers is different than size of loaded Front map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillFront200MapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillFront200MapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Front 500um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFront500MapRows(const char* dataFileName);
DGADLLENGINE_API int getFront500MapRows2(const int dataFileID);


// This function returns number of columns in Front 500um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFront500MapColumns(const char* dataFileName);
DGADLLENGINE_API int getFront500MapColumns2(const int dataFileID);


// This function fills out Front 500um map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Front pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-7 - Front map is missing
//		-3 - Size of allocated buffers is different than size of loaded Front map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillFront500MapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillFront500MapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Back 200um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and Back map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBack200MapRows(const char* dataFileName);
DGADLLENGINE_API int getBack200MapRows2(const int dataFileID);


// This function returns number of columns in Back 200um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Back map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBack200MapColumns(const char* dataFileName);
DGADLLENGINE_API int getBack200MapColumns2(const int dataFileID);


// This function fills out Back 200um map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Back pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-8 - Back map is missing
//		-3 - Size of allocated buffers is different than size of loaded Front map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillBack200MapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillBack200MapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Back 500um map if data file is loaded
// Return Value:
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and Back map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBack500MapRows(const char* dataFileName);
DGADLLENGINE_API int getBack500MapRows2(const int dataFileID);


// This function returns number of columns in Back 500um map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Back map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBack500MapColumns(const char* dataFileName);
DGADLLENGINE_API int getBack500MapColumns2(const int dataFileID);


// This function fills out Back 500um map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Back pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-8 - Back map is missing
//		-3 - Size of allocated buffers is different than size of loaded Front map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API 
	int fillBack500MapArray(
			const char* dataFileName, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);
DGADLLENGINE_API 
	int fillBack500MapArray2(
			const int dataFileID, 
			double *map, 
			int* badPixelsMask, 
			int rows, 
			int columns);


// This function returns number of rows in Front NT map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFrontNTMapRows(const char* dataFileName);
DGADLLENGINE_API int getFrontNTMapRows2(const int dataFileID);


// This function returns number of columns in Front NT map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-7 - Front map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFrontNTMapColumns(const char* dataFileName);
DGADLLENGINE_API int getFrontNTMapColumns2(const int dataFileID);


// This function fills out Front NT map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		fMaxCutoff - maximum cut-off radius for filtering
//		fMinCutoff - minimum cut-off radius for filtering
//		fMaxEE - maximum Edge Exclusion
//		fprefilterEE - pre-fileter Edge Exclusion
//		map - buffer to Back pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-7 - Front map is missing
//		-3 - Size of allocated buffers is different than size of loaded Front map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-23 - leveling algorithm error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API 
	int fillFrontNTMapArray(
		const char* dataFileName,
		double fMaxCutoff,
		double fMinCutoff,
		double fMaxEE,
		double fprefilterEE,
		double* map,
		int* badPixelsMask,
		int rows,
		int columns);
DGADLLENGINE_API 
	int fillFrontNTMapArray2(
		const int dataFileID,
		double fMaxCutoff,
		double fMinCutoff,
		double fMaxEE,
		double fprefilterEE,
		double* map,
		int* badPixelsMask,
		int rows,
		int columns);

// This function returns number of rows in Back NT map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-8 - Back map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBackNTMapRows(const char* dataFileName);
DGADLLENGINE_API int getBackNTMapRows2(const int dataFileID);


// This function returns number of columns in Back NT map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and Front map exists
//		-5 - data file is not loaded
//		-8 - Back map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getBackNTMapColumns(const char* dataFileName);
DGADLLENGINE_API int getBackNTMapColumns2(const int dataFileID);


// This function fills out Back NT map pixels and mask indicating 
// which pixels are valid
// This function fills out Front NT map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		fMaxCutoff - maximum cut-off radius for filtering
//		fMinCutoff - minimum cut-off radius for filtering
//		fMaxEE - maximum Edge Exclusion
//		fprefilterEE - pre-fileter Edge Exclusion
//		map - buffer to Back pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-8 - Back map is missing
//		-3 - Size of allocated buffers is different than size of loaded Back map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-23 - leveling algorithm error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillBackNTMapArray(
	const char* dataFileName,
	double fMaxCutoff,
	double fMinCutoff,
	double fMaxEE,
	double fprefilterEE,
	double* map, 
	int* badPixelsMask,
	int rows, 
	int columns);
DGADLLENGINE_API int fillBackNTMapArray2(
	const int dataFileID,
	double fMaxCutoff,
	double fMinCutoff,
	double fMaxEE,
	double fprefilterEE,
	double* map, 
	int* badPixelsMask,
	int rows, 
	int columns);


// This function fills out Derivative Shape Map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShapedXMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShapedXMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function fills out Derivative Shape Map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShapedYMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShapedYMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function returns IPD X map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		mode - 1 (mode 1) or 2 (mode 2)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapeXIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int mode, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShapeXIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int mode, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns IPD Y map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		mode - 1 (mode 1) or 2 (mode 2)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapeYIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int mode, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShapeYIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int mode, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns wafer date/time if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWaferDateTime(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getWaferDateTime2(
			const int dataFileID, const char** res);


// This function returns wafer file name if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getFileName(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getFileName2(
			const int dataFileID, const char** res);


// This function returns wafer load port if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWaferDataLoadPort(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getWaferDataLoadPort2(
			const int dataFileID, const char** res);


// This function returns wafer carrier ID if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWaferDataCarrierID(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getWaferDataCarrierID2(
			const int dataFileID, const char** res);


// This function returns wafer data slot if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWaferDataSlot(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getWaferDataSlot2(
			const int dataFileID, const char** res);


// This function returns wafer cycle if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getJobWaferCycle(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getJobWaferCycle2(
			const int dataFileID, const char** res);


// This function returns wafer cycle if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getJobWaferRepeat(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getJobWaferRepeat2(
			const int dataFileID, const char** res);


// This function returns number of shots if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWafersightPWGNumShots(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getWafersightPWGNumShots2(
			const int dataFileID, const char** res);


// This function returns wafer ID if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getWaferID(const char* dataFileName, const char** res);
DGADLLENGINE_API int getWaferID2(const int dataFileID, const char** res);


// This function returns tool ID if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getDataAcquiredOn(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getDataAcquiredOn2(
			const int dataFileID, const char** res);


// This function returns lot ID if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getLotID(const char* dataFileName, const char** res);
DGADLLENGINE_API int getLotID2(const int dataFileID, const char** res);


// This function returns current step if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getCurrentStep(const char* dataFileName, const char** res);
DGADLLENGINE_API int getCurrentStep2(const int dataFileID, const char** res);


// This function returns reference step if data file is loaded, or 
// empty string the value was not found
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - output parameter; contains string with requested metadata item
// Return Value:
//		0 - Success
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getReferenceStep(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getReferenceStep2(
			const int dataFileID, const char** res);

DGADLLENGINE_API int getScannerID(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getScannerID2(
			const int dataFileID, const char** res);

DGADLLENGINE_API int getChamberID(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getChamberID2(
			const int dataFileID, const char** res);

DGADLLENGINE_API int getProcessToolID(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getProcessToolID2(
			const int dataFileID, const char** res);

DGADLLENGINE_API int getDeviceID(
			const char* dataFileName, const char** res);
DGADLLENGINE_API int getDeviceID2(
			const int dataFileID, const char** res);

DGADLLENGINE_API int getCustomFieldName(
			const char* dataFileName, const char* fieldName, const char** res);
DGADLLENGINE_API int getCustomFieldName2(
			const int dataFileID, const char* fieldName, const char** res);


// This function returns license availability for a feature with given name
// Papameters:
//		featureName - the name of the feature to be queried
// Return Value:
//		0 - Disabled
//		1 - Enabled
DGADLLENGINE_API int isFeatureEnabled(const char* featureName);


// This function loads given pair of reference and current data files into 
// memory from the HDD. Only one pair can be loaded at a time. This application 
// doesn't support working with multiple pairs of data files simultaneously
// Papameters:
//		preDataFileName - pre-step file name on the local HDD
//		postDataFileName - post-step file name on the local HDD
//		pairID - ID of the Pre-Post pair to be referred to from the rest of API
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadPrePostPair(
			const char* preDataFileName, 
			const char* postDataFileName,
			int* pairID);

// This function loads given pair of reference and current data files into 
// memory from the HDD. Only one pair can be loaded at a time. This application 
// doesn't support working with multiple pairs of data files simultaneously
// Papameters:
//		preDataFileName - pre-step file name on the local HDD
//		postDataFileName - post-step file name on the local HDD
//		preshapeBackWeightage - weightage on the back for creating shape for pre
//		postshapeBackWeightage - weightage on the back for creating shape for post
//					100 - shape will be created from back
//					0 - shape will be created from Front
//					50  - shape will be cerated equaliy from Front and Back
//					any other value between 0 and 100, weightage will be used for back.
//		pairID - ID of the Pre-Post pair to be referred to from the rest of API
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadPrePostPair2(
	const char* preDataFileName,
	const char* postDataFileName,
	const int preBackShapeWeightage,
	const int postBackShapeWeightage,
	int* pairID);


// This function loads given pair of reference and current data files into 
// memory from memory stream. Only one pair can be loaded at a time. This 
// application doesn't support working with multiple pairs of data files 
// simultaneously
// Papameters:
//		preStream - memory stream that contains pre- .pwg file content
//		preStreamSize - the size of the pre-stream
//		postStream - memory stream that contains post- .pwg file content
//		postStreamSize - the size of the post-stream
//		pairID - ID of the Pre-Post pair to be referred to from the rest of API
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadPrePostPairFromStream(
			const unsigned char* preStream,
			const int preStreamSize, 
			const unsigned char* postStream,
			const int postStreamSize, 
			int* pairID);


// This function loads given pair of reference and current data files into 
// memory from memory stream. Only one pair can be loaded at a time. This 
// application doesn't support working with multiple pairs of data files 
// simultaneously
// Papameters:
//		preStream - memory stream that contains pre- .pwg file content
//		preStreamSize - the size of the pre-stream
//		postStream - memory stream that contains post- .pwg file content
//		postStreamSize - the size of the post-stream
//		preshapeBackWeightage - weightage on the back for creating shape for pre
//		postshapeBackWeightage - weightage on the back for creating shape for post
//					100 - shape will be created from back
//					0 - shape will be created from Front
//					50  - shape will be cerated equaliy from Front and Back
//					any other value between 0 and 100, weightage will be used for back.
//		pairID - ID of the Pre-Post pair to be referred to from the rest of API
// Return Value:
//		0 - Success
//		-1 - File does not exist
//		-5 - data file is not loaded
//		-10 - File is corrupted
//		-11 - Unknown problem while reading data file
//		-27 - Metadata query error
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int loadPrePostPairFromStream2(
	const unsigned char* preStream,
	const int preStreamSize,
	const unsigned char* postStream,
	const int postStreamSize,
	const int preBackShapeWeightage,
	const int postBackShapeWeightage,
	int* pairID);
	

// This function unloads (releases from memory) data reference and current data 
// files with given names
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		0 - Success
//		-5 - File with given name is not loaded
DGADLLENGINE_API int unloadPrePostPair(const int pairID);


// This function unloads currently loaded pre- and post- files that were 
// previousble loaded by calling loadPrePostPair(...) / 
// loadPrePostPairFromStream(...)
DGADLLENGINE_API void unloadCurrentPrePostPairs();


// This function checks if reference and current data file with given name 
// are loaded in memory
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		1 - File with given name is loaded
//		0 - File with given name is not loaded
DGADLLENGINE_API int isPrePostPairLoaded(const int pairID);


// This function returns number of rows in Shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePairDiffRows(const int pairID);


// This function returns number of rows in Shape difference map if data file 
// is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePairDiffColumns(const int pairID);


// This function returns difference between two Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-19 - Post-Pre substr5uction error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiffMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns);


// This function returns difference between Post-Pre Shape difference Map and 
// 2nd degree polynomial fit to teh difference map
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-25 - Remove 2nd degree plynomial fit error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_ResidualMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns);


// This function returns X derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dXMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns);


// This function returns Y derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dYMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns);


// This function returns IPD X map after removing 4, 6, or 10 corrections terms 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_XIPDMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int term,
		double siteSizeX,
		double siteSizeY,
		double siteOffsetX,
		double siteOffsetY);
 

// This function returns IPD Y map after removing 4, 6, or 10 corrections terms 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
int DGADLLENGINE_API fillShapePairDiff_YIPDMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int term,
		double siteSizeX,
		double siteSizeY,
		double siteOffsetX,
		double siteOffsetY);


// This function returns IPD Mag map after removing 4, 6, or 10 corrections terms 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
int DGADLLENGINE_API fillShapePairDiff_MagIPDMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int term,
		double siteSizeX,
		double siteSizeY,
		double siteOffsetX,
		double siteOffsetY);


// This function returns 2nd X derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dX2Map(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns 2nd Y derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dY2Map(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns Mean LSC of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_meanLSCMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns Mag LSC of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_magLSCMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns 3rd X derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dX3Map(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns 3rd Y derivative of the difference between two 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dY3Map(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns twisted - X then Y  derivative of the difference 
// between two Shape maps: Post - Pre. 
// Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePairDiff_dXYMap(
		const int pairID, 
		double* map, 
		int* badPixelsMask,
		int rows, 
		int columns,
		int smoothKernelSize);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShape200MapRows(const char* dataFileName);
DGADLLENGINE_API int getShape200MapRows2(int dataFileID);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShape200MapColumns(const char* dataFileName);
DGADLLENGINE_API int getShape200MapColumns2(int dataFileID);


// This function fills out shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - success
//		-2 - shape map is missing
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-4 - memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape200MapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape200MapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape200dXMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape200dXMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape200dYMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape200dYMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function returns IPD X map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShape200XIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShape200XIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns IPD Y map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShape200YIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShape200YIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns number of rows in Shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePair200DiffRows(int pairID);


// This function returns number of rows in Shape difference map if data file 
// is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePair200DiffColumns(int pairID);


// This function returns difference between two shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-19 - post-pre substr5uction error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - unknown C++ error occurred
//		-500 - unknown error occurred
DGADLLENGINE_API int fillShapePair200DiffMap(
			int pairID, double* map, int* badPixelsMask, int rows, int columns);


// This function returns 2nd Y derivative of the difference between two 
// HiRes Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePair200Diff_dX2Map(
		int pairID, double* map, int* badPixelsMask, int rows, int columns,
														  int smoothKernelSize);


// This function returns 2nd Y derivative of the difference between two 
// HiRes Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePair200Diff_dY2Map(
		int pairID, double* map, int* badPixelsMask, int rows, int columns,
														  int smoothKernelSize);


// This function returns Mean LSC of the difference between two 
// HiRes Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePair200Diff_meanLSCMap(
		int pairID, double* map, int* badPixelsMask, int rows, int columns,
														  int smoothKernelSize);


// This function returns Mag LSC of the difference between two 
// HiRes Shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-28 - Smoothing for requested derivative computation is not supported
//		-15 - Smoothing kernel size must be odd
//		-20 - Smoothing of derivative map error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapePair200Diff_magLSCMap(
		int pairID, double* map, int* badPixelsMask, int rows, int columns,
														  int smoothKernelSize);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShape100MapRows(const char* dataFileName);
DGADLLENGINE_API int getShape100MapRows2(int dataFileID);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShape100MapColumns(const char* dataFileName);
DGADLLENGINE_API int getShape100MapColumns2(int dataFileID);


// This function fills out shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - success
//		-2 - shape map is missing
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-4 - memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape100MapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape100MapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape100dXMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape100dXMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShape100dYMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
														 int rows, int columns);
DGADLLENGINE_API int fillShape100dYMapArray2(
		int dataFileID, double* map, int* badPixelsMask, int rows, int columns);


// This function returns IPD X map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShape100XIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShape100XIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns IPD Y map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShape100YIPDMapArray(
		const char* dataFileName, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShape100YIPDMapArray2(
		int dataFileID, double* map, int* badPixelsMask,
			int rows, int columns, int term, double siteSizeX,
					  double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePair100DiffRows(int pairID);


// This function returns number of columns in shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePair100DiffColumns(int pairID);


// This function returns difference between two shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
// Return Value:
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-19 - post-pre substr5uction error occurred
//		-100 - if PWGDataExport license is disabled
//		-400 - unknown C++ error occurred
//		-500 - unknown error occurred
DGADLLENGINE_API int fillShapePair100DiffMap(
			int pairID, double* map, int* badPixelsMask, int rows, int columns);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapeResMapRows(const char* dataFileName, unsigned int res);
DGADLLENGINE_API int getShapeResMapRows2(int dataFileID, unsigned int res);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
// Return Value:
//		N - number of columns, if data file is loaded and shape map exists
//		-2 - shape map is missing
//		-5 - data file is not loaded
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapeResMapColumns(const char* dataFileName, unsigned int res);
DGADLLENGINE_API int getShapeResMapColumns2(int dataFileID, unsigned int res);


// This function fills out shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map - Currently the dll supports 500,
//		200, 100 and 60 
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - success
//		-2 - shape map is missing
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-4 - memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map. 
//		-100 - if PWGDataExport license is disabled

DGADLLENGINE_API int fillShapeResMapArray(const char* dataFileName, unsigned int res, 
								double* map, int* badPixelsMask, int rows, int columns);
DGADLLENGINE_API int fillShapeResMapArray2(int dataFileID, unsigned int res, 
						double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int fillShapeResdXMapArray(const char* dataFileName, unsigned int res,
					double* map, int* badPixelsMask, int rows, int columns);
DGADLLENGINE_API int fillShapeResdXMapArray2(int dataFileID, unsigned int res,
						double* map, int* badPixelsMask, int rows, int columns);


// This function fills out derivative shape map pixels and mask indicating 
// which pixels are valid
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
//		map - buffer to Shape pixel values
//		badPixelsMask - mask indicating which pixels are valid (1) or invalid(0). 
//		Entries map pixels whose corresponding badPixelsMask values = 0 
//		are undefined.
// Return Value:
//		0 - Success
//		-2 - Shape map is missing
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-4 - Memory for input array(s) is not allocated
//		-5 - data file is not loaded
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled

DGADLLENGINE_API int fillShapeResdYMapArray(const char* dataFileName, unsigned int res,
				double* map, int* badPixelsMask, int rows, int columns);
DGADLLENGINE_API int fillShapeResdYMapArray2(int dataFileID, unsigned int res,
							double* map, int* badPixelsMask, int rows, int columns);


// This function returns IPD X map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapeResXIPDMapArray(
	const char* dataFileName, unsigned int res, 
	double* map, int* badPixelsMask, int rows, int columns, int term, 
	double siteSizeX, double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShapeResXIPDMapArray2(
	int dataFileID, unsigned int res, 
	double* map, int* badPixelsMask, int rows, int columns, int term, 
	double siteSizeX, double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns IPD Y map after removing 4, 6, or 10 corrections terms;
// no correction is applied if terms is set to 0.
// Papameters:
//		dataFileName - file name on the local HDD
//		dataFileID - fileID returned from loadDataFile(...)
//		res - resolution of the requested map
//		term - 0 (no correction), 4, 6, 10, 24 (HOWA3), 28 (W3F1) and 42 (W3F3)
//		siteSizeX, siteSizeY - user specified site size in millimeters (only
//							   used for corections with 10 terms and above)
//		siteOffsetX, siteOffsetY - user specified site offset in millimeters
//								   (for corections with 10 terms and above)
// Return Value:
//		-3 - Size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - Shape map is missing
//		-14 - Derivative is not computed
//		-21 - Invalid IPD Term requested
//		-22 - Error while removing surface Mean and Tilt
//		-26 - IPD Term removal Error
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
//		-400 - Unknown C++ error occurred
//		-500 - Unknown error occurred
DGADLLENGINE_API int fillShapeResYIPDMapArray(
	const char* dataFileName, unsigned int res, 
	double* map, int* badPixelsMask, int rows, int columns, int term, 
	double siteSizeX, double siteSizeY, double siteOffsetX, double siteOffsetY);

DGADLLENGINE_API int fillShapeResYIPDMapArray2(
	int dataFileID, unsigned int res, 
	double* map, int* badPixelsMask, int rows, int columns, int term, 
	double siteSizeX, double siteSizeY, double siteOffsetX, double siteOffsetY);


// This function returns number of rows in shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
//		res - resolution of the requested map
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePairDiffResRows(int pairID, unsigned int res);


// This function returns number of columns in shape map if data file is loaded
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
//		res - resolution of the requested map
// Return Value:
//		N - number of rows, if data file is loaded and shape map exists
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-100 - if PWGDataExport license is disabled
DGADLLENGINE_API int getShapePairDiffResColumns(int pairID, unsigned int res);


// This function returns difference between two shape maps: Post - Pre. 
// Papameters:
//		pairID - ID of the Pre-Post pair to returned from loadPrePostPair(...) / 
//		loadPrePostPairFromStream(...)
//		res - resolution of the requested map
// Return Value:
//		-3 - size of allocated buffers is different than size of loaded Shape map
//		-5 - data file is not loaded
//		-6 - shape map is missing
//		-19 - post-pre substr5uction error occurred
//		-30 - Requested resolution not supported.
//		-31 - Resolution of the input pwg file is too low to produce the requested map.
//		-100 - if PWGDataExport license is disabled
//		-400 - unknown C++ error occurred
//		-500 - unknown error occurred
DGADLLENGINE_API int fillShapePairDiffResMap(int pairID, unsigned int res,
						double* map, int* badPixelsMask, int rows, int columns);



#ifdef DGADLLENGINE_EXPORTS
}
#endif //DGADLLENGINE_EXPORTS

#endif //DGADLLENGINE_H

