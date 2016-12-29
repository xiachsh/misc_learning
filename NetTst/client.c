#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#define BLOCKSIZE 512*1024


typedef struct testConf {
	unsigned int threadNum;
	unsigned int port;
	unsigned int blockSize;
	char * server;

} TestConf;

typedef struct testOutput {
	unsigned long int bandWidth;
	time_t * eclapsedTime;
	time_t  maxCostTime;
	time_t  minCostTime;
	int sec;
} TestOutput ;

TestConf runConf =  {
	.threadNum = 16,
	.port = 5001,
	.blockSize = BLOCKSIZE,
	.server = "127.0.0.1",
};

TestOutput result = { 
	.bandWidth = 0,
	.eclapsedTime = NULL,
	.maxCostTime = 0,
	.minCostTime = 0,
	.sec = 0,
};

void usage(int argc,char **argv)
{
	fprintf(stderr,"%s usage:\n",argv[0]);
	fprintf(stderr,"	: -h print this help\n");
	fprintf(stderr,"	: -t threadNum default CPU of current hosts\n");
	fprintf(stderr,"	: -b blockSize default 1M\n");
	fprintf(stderr,"	: -s serverName default 127.0.0.1\n");
	fprintf(stderr,"	: -p portNum default 5001\n");
	exit (1);
}


void parse_args(int argc,char **argv)
{
	int c;

	while (( c=getopt(argc,argv,"t:b:s:p:h")) != -1 ) {
		char * v;
		switch(c) {
		case 't':
			 v = optarg;
			if (!isdigit(v[0])) {
				printf("%s is not valid for thread num,bye\n",v);
				usage(argc,argv);			
			}
			runConf.threadNum = atoi(v);
			break;
		case 'b':
			 v = optarg;
			 if (!isdigit(v[0])) {
                                printf("%s is not valid for thread num,bye\n",v);
                                usage(argc,argv);
                        }
                        runConf.blockSize= atoi(v);
                        break;
		case 's':
			runConf.server = optarg;
			break;
		case 'p':
			  v = optarg;
                         if (!isdigit(v[0])) {
                                printf("%s is not valid for thread num,bye\n",v);
                                usage(argc,argv);
                        }
                        runConf.port= atoi(v);
                        break;
		case 'h':
			usage(argc,argv);
			break;
		default:
			fprintf(stderr,"unknown option %c \n",c);
			break;
		}
	}
	return;
}


void* worker_fn()
{
	
   int sockfd;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   int * retStat = malloc(sizeof(int) * 1);
   char * buffer;
   int sent = 0;
   *retStat = 1;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("ERROR opening socket");
      return retStat;
   }
   server = gethostbyname(runConf.server);
   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      return retStat;
   }
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(runConf.port);
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR connecting");
      return retStat;
   }
   buffer = malloc(sizeof (char) * runConf.blockSize);
   bzero(buffer,sizeof (char) * runConf.blockSize);
   sent = write(sockfd, buffer, runConf.blockSize);
   if (sent != runConf.blockSize ) {
     	 	perror("ERROR writing to socket");
     		 exit(1);
   }
   free(buffer);
   close(sockfd);	

   *retStat = 0;
   return retStat;

}

void print_args() 
{
	fprintf(stderr,"============================================\n");
	fprintf(stderr,"Readig to run net test with following option\n");
	fprintf(stderr,"Thread Num :%d\n",runConf.threadNum);
	fprintf(stderr,"Port   Num :%d\n",runConf.port);
	fprintf(stderr,"Server     :%s\n",runConf.server);
	fprintf(stderr,"Block Size :%d\n",runConf.blockSize);


}

void print_result(void)
{
	fprintf(stderr,"============================================\n");	
	fprintf(stderr,"================Test Result=================\n");
	fprintf(stderr,"Avg BandWidth:%d b/s\n",result.bandWidth);
}

int main(int argc, char *argv[]) {

   char *buffer;
   pthread_t * t_arr;
   int t_index;
   time_t t1,t2;
   parse_args(argc,argv);
   print_args();

   t_arr = malloc(sizeof(pthread_t) * runConf.threadNum);
   t1 = time(NULL);
   for (t_index=0;t_index<runConf.threadNum;t_index++){
	pthread_create(&t_arr[t_index],NULL,worker_fn,NULL);
   }
   
   for (t_index=0;t_index<runConf.threadNum;t_index++){
	void *ret = NULL;
	pthread_join(t_arr[t_index],&ret);
	free(ret);
   }
<<<<<<< HEAD
   t2 = time(NULL);
   if (t2 - t1) 
   result.bandWidth = ( BLOCKSIZE*8*runConf.threadNum )/(t2-t1);

   print_result();
=======
   
>>>>>>> ca4abf3af97c6ef4d15f04c8cbd18c809cb035cd
   free(t_arr);
   return 0;
}

