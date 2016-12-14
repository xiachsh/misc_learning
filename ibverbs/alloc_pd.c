#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>


#include <infiniband/verbs.h>


/* contains memory problem for ibv_close_device */

struct ibv_device ** dev_list;

struct ibv_context *  pick_device()
{
	struct ibv_device * dev;
	struct ibv_context * ctx ;
	struct ibv_device_attr dev_attr;
	struct ibv_port_attr port_attr;
	int ret = 0;
	int i = 0;
	int port_num;	
	int num_device = 0;

	dev_list = ibv_get_device_list(&num_device);
	if (num_device < 1) {
		printf("Error, Cannot find any RDMA device,exiting\n");
		exit(-1);
	}

	for (i=0;i<num_device;i++) {
		ctx = NULL;
		ctx = ibv_open_device(dev_list[i]);
		if (ctx)  {
			ret = ibv_query_device(ctx,&dev_attr);
			if (ret) {
				printf("WARN,Skip dev: %s, Cann't query device\n",dev_list[i]->name );	 
				continue;
			}	
			int ports = dev_attr.phys_port_cnt;
			for (port_num=1;port_num<=ports;port_num++) {
				memset(&port_attr,0,sizeof(struct ibv_port_attr));
				ret = ibv_query_port(ctx,port_num,&port_attr);
				if (ret) {
					printf("WARN,Skip dev: %s port: %d,Cann't query port info\n",dev_list[i]->name,port_num);
					continue;
				}
				else {
					if (port_attr.state == IBV_PORT_ACTIVE) {
						printf("OK: Return dev: %s port: %d\n",dev_list[i]->name,port_num);
						return ctx;
					}
				}
			}
		}	
		else 
			printf("WARN,Skip dev :%s,Cann't open device\n",dev_list[i]->name);
	}
	return NULL;
}


int main()
{
	struct ibv_pd* pd ;
	struct ibv_context* ctx;
	ctx = pick_device(&ctx);
	printf("Returned Dev :%s\n",ctx->device->name);

	pd = NULL;
	pd = ibv_alloc_pd(ctx);
	if (!pd)  {
		printf("Error,Cann't alloc protected domains\n");
		return 1;
	}
	ibv_dealloc_pd(pd);
	ibv_close_device(ctx);
	ibv_free_device_list(dev_list);
	return 0;
}
