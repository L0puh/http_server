#include "webserv.h"

char const *parse(const char* line, const char symbol[]){
    char *copy = (char *)malloc(strlen(line) + 1);
    strcpy(copy, line);

    char const*message;
    char * token = strtok(copy, symbol);
    int current = 0;

    while( token != NULL ) {
      token = strtok(NULL, " ");
      if(current == 0){
          message = token;
          if(message == NULL)
              message = "";
          if (std::strcmp(message, "/") == 0) 
             return "/index.html";
          return message;
      }
      current = current + 1;
   }
   free(token);
   free(copy);
   return message;
}

std::string get_file_content(std::string filename){
   std::string line, result;
   std::ifstream file;
   std::string current_path = std::filesystem::current_path();
   filename = current_path + "/res" + filename;
   file.open(filename);
   if (!file.is_open()) {
      printf("cannot open the file: %s\n", filename.c_str());
      return get_file_content("/error.html");
   }
   else {
      while(getline(file, line)) result+=line;
      file.close();
   }
   return result;
}

