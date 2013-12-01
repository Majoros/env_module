
#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "LuaBridge/LuaBridge.h"
#include "LuaBridge/RefCountedPtr.h"
#include "LuaBridge/RefCountedObject.h"

enum PathExistsAction {
    LEAVE = 0,
    UPDATE
};

enum PathAction {
    APPEND = 0,
    PREPEND
};


int set(const char*, const char*);
int append_path(const char*, const char*);
int prepend_path(const char*, const char*);
int remove_path(const char*, const char*);


//typedef void (*path_action_dt)(void);
//static path_action_dt exec_action[] = {
//}
#endif //MODULE_H
