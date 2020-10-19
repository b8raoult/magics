#ifndef _WINDUX_H
#define _WINDUX_H

#ifdef _WIN32

struct timeval;
struct dirent;
struct DIR;

int gettimeofday(struct timeval* t, void* timezone);

DIR* opendir(const char* path);
struct dirent* readdir(DIR* dir);
void closedir(DIR* dir);

#endif
#endif
