#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFF_SIZE 512*1024
#define BACKLOG  16

typedef struct testConf {
	unsigned int port;
	int buffSize;
	int backlog;
} TestConf;

typedef struct _request {
	int sockfd;
	struct sockaddr * cli_addr;
} Request;

#define MAKE_REQ(req,fd,addr)    			 \
	req = malloc(sizeof(Request));     		 \
	req->sockfd = fd;				 \
	req->cli_addr = addr;				 

#define FREE_REQ(req)  					\
	Request * _req_ = (Request *) req;		\
	free(_req_->cli_addr);				\
	free(_req_);					\
	_req_ = req = NULL;	

TestConf runConf =  {
	.port = 5001,
	.buffSize = BUFF_SIZE,
	.backlog = BACKLOG,
};

void usage(int argc,char **argv)
{
	fprintf(stderr,"%s usage:\n",argv[0]);
	fprintf(stderr,"	: -p portNum default 5001\n");
	fprintf(stderr,"	: -b buffer size default 512*1024\n");
	fprintf(stderr,"	: -q backlog backlog size of listen sock\n");
	exit (1);
}


void parse_args(int argc,char **argv)
{
	int c;

	while (( c=getopt(argc,argv,"b:p:")) != -1 ) {
		char * v;
		switch(c) {
		case 'b':
			 v = optarg;
                         if (!isdigit(v[0])) {
                                printf("%s is not valid for thread num,bye\n",v);
                                usage(argc,argv);
                        }
                        runConf.buffSize = atoi(v);
                        break;

		case 'p':
			  v = optarg;
                         if (!isdigit(v[0])) {
                                printf("%s is not valid for thread num,bye\n",v);
                                usage(argc,argv);
                        }
                        runConf.port= atoi(v);
                        break;
		default:
			fprintf(stderr,"unknown option %c \n",c);
			break;
		}
	}
	return;
}


void* worker_fn(void * req)
{
	int * ret;
	char *buffer; 
	int recv;
	int totalRecv = 0;
	Request * _req = (Request *) req;
	buffer = malloc(sizeof(char) * runConf.buffSize);
        fprintf(stdout,"Processing Request for port....\n");	
	while ( (recv = read(_req->sockfd,buffer,runConf.buffSize)) > 0 ) 
		totalRecv += recv;
	fprintf(stdout,"Get %d bytes in thread id :%ld\n",totalRecv,pthread_self());
	free(buffer);
	close(_req->sockfd);
	FREE_REQ(req);
	return ret;
}

void print_args() 
{
	fprintf(stderr,"============================================\n");
	fprintf(stderr,"Readig to run net test with following option\n");
	fprintf(stderr,"Port   Num :%d\n",runConf.port);
	fprintf(stderr,"Buffer Size :%d\n",runConf.buffSize);
}

int main(int argc, char *argv[]) {

   char *buffer;
   int t_index;
   int sockfd,newsockfd;
   struct sockaddr_in serv_addr;
   struct sockaddr_in *cli_addr;
   socklen_t clilen;
   parse_args(argc,argv);
   print_args();

   sockfd = socket(AF_INET,SOCK_STREAM,0); 
   if (sockfd < 0) {
	perror("socket");
	exit(1);
   }

   bzero( (char*) &serv_addr,sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(runConf.port);

   if (bind(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
	perror("bind");
	exit(1);
   }
   listen(sockfd,runConf.backlog);

   while (1) {
	Request *req;
	pthread_t t;
	cli_addr = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in));
   	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr *) cli_addr,&clilen);
	if (newsockfd < 0) {
		perror("accept");
		exit(1);
	}

	MAKE_REQ(req,newsockfd,(struct sockaddr *)cli_addr);
	pthread_create(&t,NULL,worker_fn,req);	
   }

   
   return 0;
}

