#include <stdio.h>
#include <stdlib.h>




#ifdef __cplusplus
extern "c" {
#endif



	void hand_func(void)
	{
		printf("File:%s Line:%d\n",__FILE__,__LINE__);
		return 0;
	}

#ifdef __cplusplus
}
#endif
