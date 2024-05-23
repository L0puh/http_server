#ifndef WEBSERV_H 
#define WEBSERV_H 

#include <string>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <filesystem>

#define ASSERT(n, a) if(n){ printf("%s\n", a); exit(-1); }
std::string get_file_content(std::string filename);
char const *parse(const char* line, const char symbol[]);

inline void log(std::string str) { printf("[+] %s\n", str.c_str()); }
inline void log(std::string str, int num) { printf("[+] %s: %d\n", str.c_str(), num); }

#endif
