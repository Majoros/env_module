
#ifndef LUA_CLASS_H
#define LUA_CLASS_H

#include "module.h"

struct M {
    std::map <std::string, std::vector<std::string> > env_paths;
    std::map <std::string, std::string> env_vars;
    PathExistsAction path_action;
    std::map <std::string, std::string> sys_info;
    std::vector<std::string> loaded;
    char *path_delim;
    M (void);

    const char *sysinfo(const char*);
    const char *modinfo(const char*);

    void set(const char*, const char*);
    void unset(const char*);

    int is_loaded(const char *);
    int not_loaded(const char *);

    int required(const char *, ...);
    int confict(const char *, ...);

    int append_path(const char*, const char*);
    int prepend_path(const char*, const char*);
    int remove_path(const char*, const char*);
    int update_path(PathAction, const char*, const char*);
    void get_paths(const char*);

    void get_loaded(void);


};

#endif //LUA_CLASS_H

