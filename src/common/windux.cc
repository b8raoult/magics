// from https://www.linuxjournal.com/article/5574
#include "windux.h"

#define WIN32_LEAN_AND_MEAN  // otherwise windows.h includes winsock.h which clashes with winsock2.h
#define NOMINMAX             // otherwise min/max macros in windows.h clash
#include <sys/timeb.h>
#include <sys/types.h>
#include <time.h>
#include <windows.h>
#include <winsock2.h>

int gettimeofday(struct timeval* t, void* timezone) {
    struct _timeb timebuffer;
    _ftime(&timebuffer);
    t->tv_sec  = timebuffer.time;
    t->tv_usec = 1000 * timebuffer.millitm;
    return 0;
}

#include <direct.h>
#include <io.h>

struct dirent {
    const char* d_name;
};
struct DIR {
    dirent e_;
    struct _finddata_t fileinfo_;
    intptr_t handle_;
    bool ok_;
    bool first_;

    DIR(const std::string& path) : handle_(-1), ok_(true), first_(true) {
        handle_   = _findfirst((path + "/*").c_str(), &fileinfo_);
        ok_       = (handle_ != -1);
        e_.d_name = fileinfo_.name;
    }

    ~DIR() {
        if (handle_ != -1) {
            _findclose(handle_);
        }
    }


    bool ok() { return ok_; }

    struct dirent* next() {
        if (first_) {
            return &e_;
        }
        if (_findnext(handle_, &fileinfo_)) {
            return &e_;
        }
        return nullptr;
    }
};

DIR* opendir(const char* path) {
    DIR* dir = new DIR(path);
    if (dir->ok()) {
        return dir;
    }
    delete dir;
    return nullptr;
}

struct dirent* readdir(DIR* dir) {
    return dir->next();
}

void closedir(DIR* dir) {
    delete dir;
}
