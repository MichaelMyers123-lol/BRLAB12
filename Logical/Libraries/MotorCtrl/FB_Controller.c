
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif

void FB_Controller(struct FB_Controller* inst)
{
	// �
	double p = inst->e * inst->k_p;
	
	// ����������� ����������
	if (p > inst->max_abs_value)
	{
		p = inst->max_abs_value;
	}
	else if (p < -inst->max_abs_value)
	{
		p = -inst->max_abs_value;
	}
	
	// �
	inst->integrator.in = inst->e * inst->k_i + inst->iyOld;
	FB_Integrator(&inst->integrator);
	double pi = p + inst->integrator.out;
	
	inst->u = pi;
	
	// ����������� ������
	if (inst->u > inst->max_abs_value)
	{
		inst->u = inst->max_abs_value;
	}
	else if (inst->u < -inst->max_abs_value)
	{
		inst->u = -inst->max_abs_value;
	}
	
	// �����������������
	inst->iyOld = inst->u - pi;
}
