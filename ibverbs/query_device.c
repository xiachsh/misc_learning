#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <infiniband/verbs.h>



int main()
{
	int num_of_device = 0; 
	struct ibv_device ** dev_list;
	struct ibv_device * ib_dev = NULL;
	struct ibv_context ** ctx; 



	dev_list = ibv_get_device_list(&num_of_device);
	int i = 0;
	if (num_of_device) {
		ctx = malloc(sizeof(struct ibv_context*) * num_of_device);
		bzero(ctx,sizeof(struct ibv_context*) * num_of_device);
	}
	for (i=0;i<num_of_device;i++)  {
		printf("name:%s dev_name:%s dev_path:%s ibdev_path:%s\n", \
			dev_list[i]->name, 	\
			dev_list[i]->dev_name,	\
			dev_list[i]->dev_path,  \
			dev_list[i]->ibdev_path
		);

		printf("try to open device :%s", dev_list[i]->name);
		ctx[i] = NULL;
		ctx[i] = ibv_open_device(dev_list[i]);
		if (ctx[i]) {
			printf("\tOK\n");	
			struct ibv_device_attr  dev_attr ;
			int ret =  ibv_query_device(ctx[i],&dev_attr);

			printf("Dev :%s contains %d ports\n", dev_list[i]->name,dev_attr.phys_port_cnt);
			ibv_close_device(ctx[i]);
		}
		else 
			printf("FAIL\n");
	}
	
	ibv_free_device_list(dev_list);
	if (num_of_device)
		free(ctx);

	return 0;
}
