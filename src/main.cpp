#include "webserv.h"

int main(int argc, char* argv[]) {
   ASSERT(argc == 1, "no args were provided");
   int port = std::atoi(argv[1]);
   int server_socket = socket(AF_INET, SOCK_STREAM, 0);

   struct sockaddr_in addr, client_addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(port);
   addr.sin_addr.s_addr = INADDR_ANY;
   int res = bind(server_socket, (struct sockaddr*)&addr, sizeof(addr));
   ASSERT(res == -1, "binding failed");
   log("listen connection");
   listen(server_socket, 1);
   socklen_t client_addr_sz = sizeof(client_addr);
   char buffer[4096];
   int bytes_recv=0;
   int client_socket; 
   while(true){
      client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_addr_sz);
      if (client_socket == -1){
           fprintf(stderr, "server error: %s\n", strerror(errno));
           exit(-1);
      }
      log("connected");
      while((bytes_recv = recv(client_socket, buffer, sizeof(buffer), 0)) <= 0){}
      std::string filename = parse(buffer, " ");
      printf("%s\n", buffer);

      std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
      std::string message = get_file_content(filename);
      std::string response = header + std::to_string(message.size()) + "\n\n" + message;
      int b_sent=0, b_total=response.size();
      while (b_sent < b_total){
         b_sent = send(client_socket, response.c_str(), response.size(), 0);
         ASSERT(b_sent < 0, "send error");
      }
      log("sent", b_sent);
   }
   close(client_socket);
   close(server_socket);
   return 0;
} 
