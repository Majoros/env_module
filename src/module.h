
#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <regex>
#include <sys/utsname.h>

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

enum SysInfoType {
    SYSNAME = 0,
    NODENAME,
    RELEASE,
    VERSION,
    MACHINE,
    DOMAINNAME
};


//typedef void (*path_action_dt)(void);
//static path_action_dt exec_action[] = {
//}
#endif //MODULE_H
