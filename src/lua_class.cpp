#include "module.h"


struct M  {
    M (void){
        map <string, vector<string> > env_paths;
        map <string, string> env_vars;
        PathExistsAction path_action = UPDATE;
        char *path_delim = ":";
    }

    void set(const char* key, const char* val) {
        env_vars[key] = val;
    }

    int append_path(const char* key, const char* path) {
        return update_path( APPEND, key, path);
    }
    int prepend_path(const char* key, const char* path) {
        return update_path( PREPEND, key, path);
    }

    int remove_path(const char* key, const char* path) {
        get_paths(key);
        for ( unsigned int i = 0; i < cur_paths.size(); ++i){
            if( path == cur_paths[i] ){
                cur_paths.erase(cur_paths.begin() + i);
            }
        }
    }

    int update_path(PathAction action, const char* key, const char* path) {
        get_paths(key);
        int replace = 0;
        for ( unsigned int i = 0; i < cur_paths.size(); ++i){
            if( cur_paths[i] == path ){
                if( path_action == LEAVE){
                    // path already there so simply leaving it alone
                    return 0;
                }else if( path_action == UPDATE ){
                    // path already there removing so we can update it
                    // with out having duplicates.
                    // not breaking so we can remove pre-existing
                    // duplicates as well.
                    std::cout << "Removing: " << cur_paths[i] << "\n";
                    cur_paths.erase(cur_paths.begin() + i);
                    replace = 1;
                    //since we are removing this we want to check the value that
                    //is now in its place.
                    i--;
                }
                else{
                    // Errr.... #FIXME: add error handling
                }
            }
        }

    }

    void get_paths(const char* key) {

        if (env_paths.find(key) == m.end()){
            return
        }
        char *token;

        char *cur_env = getenv (key);
        token = strtok( cur_env, path_delim );

        std::vector<std::string> vec_paths;
        while( token != NULL ){
            vec_paths.push_back(token);
            token = strtok( NULL, path_delim );
        }
        env_paths[key] = vec_paths;
    }
}



