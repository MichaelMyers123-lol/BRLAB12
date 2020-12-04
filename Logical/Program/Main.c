
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	double dt = 0.01;
	
	Motor.dt = dt;
	Motor.ke = 0.16;
	Motor.phi = 0;
	Motor.Tm = 0.04;
	Motor.u = 0;
	Motor.w = 0;
	Motor.integrator1.in = 0;
	Motor.integrator1.dt = dt;
	Motor.integrator1.temp = 0;
	Motor.integrator2.in = 0;
	Motor.integrator2.dt = dt;
	Motor.integrator2.temp = 0;
	
//	/*
	Motor2.dt = dt;
	Motor2.ke = 0.16;
	Motor2.phi = 0;
	Motor2.Tm = 0.04;
	Motor2.u = 0;
	Motor2.w = 0;
	Motor2.integrator1.in = 0;
	Motor2.integrator1.dt = dt;
	Motor2.integrator1.temp = 0;
	Motor2.integrator2.in = 0;
	Motor2.integrator2.dt = dt;
	Motor2.integrator2.temp = 0;
//	*/
	
	Controller.dt = dt;
	Controller.e = 0;
	Controller.iyOld = 0;
	Controller.k_i = Motor.ke;
	Controller.k_p = Motor.ke * Motor.Tm;
	Controller.max_abs_value = 12;
	Controller.integrator.in = 0;
	Controller.integrator.out = 0;
	Controller.integrator.temp = 0;
	Controller.integrator.dt = dt;
	
	Speed = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(Counter == 0)
	{
		Speed = 20 - Speed;
	}
	FB_Controller(&Controller);
	
	Motor.u = Controller.u;
	FB_Motor(&Motor);
	
//	/*
	Motor2.u = Speed * Motor2.ke;
	FB_Motor(&Motor2);
//	*/
	
	Controller.e = Speed - Motor.w;
	
	Counter++;
	if(Counter == 500)
	{
		Counter = 0;
	}
}

void _EXIT ProgramExit(void)
{
	
}

