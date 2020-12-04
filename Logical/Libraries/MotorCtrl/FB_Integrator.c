
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif

void FB_Integrator(struct FB_Integrator* inst)
{
	inst->temp = inst->temp + inst->in * inst->dt;
	inst->out = inst->temp;
}
