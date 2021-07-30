#include <stdio.h>
#include "stdlib.h"
#include <Windows.h>

#pragma warning (disable : 4996)


void main() {

	HANDLE fileHandle = CreateFile(
		L"1065_BeberecheAlexandru-Eugen.lnk",
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);


	FILETIME creationTime, lastAccessTime, lastWriteTime;

	if (fileHandle != INVALID_HANDLE_VALUE)
	{
		GetFileTime(fileHandle, &creationTime, &lastAccessTime, &lastWriteTime);


		_SYSTEMTIME _systemTime;
		LPSYSTEMTIME lpTest = &_systemTime;




		printf("\n----------");

		FileTimeToSystemTime(&creationTime, lpTest);
		printf("\n----CreationTime--------\n");
		printf("hour: %d  | minute:%d", lpTest->wHour + 2, lpTest->wMinute);


		FileTimeToSystemTime(&lastAccessTime, lpTest);
		printf("\n----Last access--------\n");
		printf("hour: %d  | minute:%d", lpTest->wHour + 2, lpTest->wMinute);


		FileTimeToSystemTime(&lastWriteTime, lpTest);
		printf("\n----Write time--------\n");
		printf("hour: %d  | minute:%d", lpTest->wHour + 2, lpTest->wMinute);




		printf("\n---------------\n");
		DWORD dw = GetFileAttributes(L"1065_BeberecheAlexandru-Eugen.lnk");

		if (dw == INVALID_FILE_ATTRIBUTES) return;

		printf("\nREAD_ONLY: ");
		if (dw & FILE_ATTRIBUTE_READONLY) {
			printf("TRUE");
		}
		else {
			printf("FALSE");

		}

		printf("\nHIDDEN: ");
		if (dw & FILE_ATTRIBUTE_HIDDEN) {
			printf("TRUE");
		}
		else {
			printf("FALSE");

		}

		printf("\nCOMPRESSED: ");
		if (dw & FILE_ATTRIBUTE_COMPRESSED) {
			printf("TRUE");
		}
		else {
			printf("FALSE");

		}




		CloseHandle(fileHandle);

		printf("\n----------");

	}
	else
	{
		printf("\n-----invalid------");
	}





	FILE* pFile = fopen("1065_BeberecheAlexandru-Eugen.lnk", "rb");


	if (pFile) {
		printf("\nfile opened");
	}
	else {
		printf("\nfile didn't open");
	}


	fseek(pFile, 0, SEEK_END);
	int size = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);


	fclose(pFile);
	printf("\nSize:%d", size);
}
