/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-30 23:00:04
 *================================================*/

#include <sys/socket.h> 
#include <sys/un.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/stat.h>

#define PORT 8000

/* fseek移动一个文件的存取位置到文件的末尾，然后利用ftell获得目前的文件访问位置,小文件可以，单大文件2G就不行,速度也不行 */
int filelength(FILE *fp)
{
  int num;
  fseek(fp,0,SEEK_END);
  num=ftell(fp);
  fseek(fp,0,SEEK_SET);
  return num;
}

/* 读取文件信息获得文件大小,速度更快 */
int file_size2(char* filename) 
{ 
  struct stat statbuf; 
  stat(filename,&statbuf); 
  int size=statbuf.st_size; 
  
  return size; 
}

/* 通过Linux命令获得文件大小 */


char *readfile(char *path)
{
  FILE *fp;
  int length;
  char *ch;
  if((fp=fopen(path,"r"))==NULL)
  {
   printf("open file %s error.\n",path);
   exit(0);
  }
//  length=filelength(fp);
  length=file_size2(path);
  printf("length = %d\n", length);
  ch=(char *)malloc(length);
  fread(ch,length,1,fp);
  *(ch+length-1)='\0';
  return ch;
}


int main()
{ 
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); 
    struct sockaddr_in server_addr; 

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_socket, 5); 

    int client_socket = accept(server_socket, NULL, NULL); 

    char buf[1024];
    read(client_socket, buf,1024); 

    printf("%s",buf); 
    char status[] = "HTTP/1.0 200 OK\r\n"; 
    write(client_socket, status, sizeof(status));

    char header[] = "Server: DWBServer\r\n"
                    "Content-Type: text/html;"
                    "charset=utf-8\r\n\r\n"; 
    write(client_socket, header, sizeof(header));

    FILE *fp = NULL;
    char *body = malloc(1024*sizeof(char));
    strcpy(body,readfile("./hello.html"));
    char b[10]="\r\n";
    body = body + strlen(body);
    memcpy(body, b, sizeof(b));

    

/*
    char body[] =   "<html>"\
                        "<head>"\
                            "<title>C语言构建小型Web服务器</title>"\
                        "</head>"\
                        "<body>"\
                            "<h2>欢迎</h2>"\
                            "<p>Hello，World</p>"\
                            "<img src=\"/home/C/hello.jpg\" alt=\"picture test\">"\
                        "</body>"\
                    "</html>";
                    */
    
    write(client_socket, body, sizeof(body));
    close(client_socket);
    close(server_socket); 

    return 0; 
} 
