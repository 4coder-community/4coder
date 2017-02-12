/*
 * Mr. 4th Dimention - Allen Webster
 *
 * 09.02.2016
 *
 * Shared system functions
 *
 */

// TOP

// NOTE(allen): This serves as a list of functions to implement
// in addition to those in 4ed_system.h  These are not exposed to
// the application code, but system_shared.cpp
// rely on the functions listed here.

struct File_Data{
    char *data;
    u32 size;
    b32 got_file;
};
global File_Data null_file_data = {0};

#define Sys_Get_Memory_Sig(name) void* name(i32 size, i32 line_number, char *file_name)
#define Sys_Free_Memory_Sig(name) void name(void *block)
#define Sys_File_Can_Be_Made_Sig(name) b32 name(char *filename)
#define Sys_Get_Binary_Path_Sig(name) i32 name(String *out)

internal Sys_Get_Memory_Sig(system_get_memory_);
internal Sys_Free_Memory_Sig(system_free_memory);
internal Sys_File_Can_Be_Made_Sig(system_file_can_be_made);
internal Sys_Get_Binary_Path_Sig(system_get_binary_path);

#define system_get_memory(size) system_get_memory_((size), __LINE__, __FILE__)

// BOTTOM
