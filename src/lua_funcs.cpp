#include "module.h"


std::vector<std::string> get_paths(const char* key) {
    char *token;
    std::vector<std::string> vec_paths;

    char *cur_env = getenv (key);
    token = strtok( cur_env, path_delim );

    while( token != NULL ){
        vec_paths.push_back(token);
        token = strtok( NULL, path_delim );
    }

    return vec_paths;
}

int set (const char* key, const char* val) {
    std::cout << "export " << key << "=\"" << val << "\";\n";
    return 0;
}

int append_path(const char* key, const char* path) {
}

int prepend_path(const char* key, const char* path) {
    cur_paths = get_paths(key);
	 int replace = 0;
    for ( unsigned int i = 0; i < cur_paths.size(); ++i){
        if( path_action == LEAVE){
            // path already there so simply leaving it alone
            return 0;
		}else if( path_action == UPDATE ){
            // path already there removing so we can update it
            // with out having duplicates.
            // not breaking so we can remove pre-existing
            // duplicates as well.
            cur_paths.erase(cur_paths.begin() + i);
			replace = 1;
		}
		else{
            // Errr.... #FIXME: add error handling
		}
    }

    if(replace){
        std::cout << "export " << key << "=\"" << path;
        for ( unsigned int i = 0; i < cur_paths.size(); ++i){
            std::cout << cur_paths[i];
		}
		std::cout << "\"";
	}
	else{
        std::cout << "export " << key << "=\"" << path << path_delim << "$" << key;
	}
	return 0;
}

int remove_path(const char* key, const char* path) {
    cur_paths = get_paths(key);
    for ( unsigned int i = 0; i < cur_paths.size(); ++i){
        if( path == cur_paths[i] ){
            cur_paths.erase(cur_paths.begin() + i);
		}
    }
}

