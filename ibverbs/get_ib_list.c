#include <stdio.h>
#include <stdlib.h>
#include <infiniband/verbs.h>



int main()
{
	int num_of_device = 0; 
	struct ibv_device ** dev_list;
	struct ibv_device * ib_dev = NULL;


	dev_list = ibv_get_device_list(&num_of_device);

	int i = 0;
	for (i=0;i<num_of_device;i++) 
		printf("name:%s dev_name:%s dev_path:%s ibdev_path:%s\n", \
			dev_list[i]->name, 	\
			dev_list[i]->dev_name,	\
			dev_list[i]->dev_path,  \
			dev_list[i]->ibdev_path
		);
		
	return 0;
}
