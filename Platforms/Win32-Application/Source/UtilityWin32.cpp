#include "pch.h"
#include "UtilityWin32.h"
#include <stdio.h>

//static AAssetManager* g_pAssetManager = 0;

double MyGetSystemTime()
{
    unsigned __int64 freq;
    unsigned __int64 time;

    QueryPerformanceFrequency( (LARGE_INTEGER*)&freq );
    QueryPerformanceCounter( (LARGE_INTEGER*)&time );

    double timeseconds = (double)time / freq;

    return timeseconds;
}

char* LoadCompleteFile(const char* filename, long* length)
{
    char* filecontents = 0;

    FILE* filehandle;
    errno_t error = fopen_s( &filehandle, filename, "rb" );

    if( filehandle )
    {
        fseek( filehandle, 0, SEEK_END );
        long size = ftell( filehandle );
        rewind( filehandle );

        filecontents = new char[size+1];
        fread( filecontents, size, 1, filehandle );
        filecontents[size] = 0;

        if( length )
            *length = size;

        fclose( filehandle );
    }

    return filecontents;
}
