/*
   cloudi_cmd.cpp
   Generated from cloudi.cmd
   on 2026-05-13.

   by Sourcy Code Translator
   (c) 2017 - radexx

   Runtime version: 1.0

*/

#include "../cns/Cloudi_master.h"

void Cloudi::state_m1()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		setStateParams(params);
	}
	
	// State controller
	if ((command("AI_ATK_Back")) ) {
		if ((stateType() == "S") && (ctrl()) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 203) && ((hitCount()) == 2) ) {
			changeState_data d;
			d.value = 201;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Foward")) ) {
		if ((stateType() == "S") && (ctrl()) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 206) || (command("holddown")) && (moveHit()) && ((stateNo()) == 203) && ((hitCount()) == 2) ) {
			changeState_data d;
			d.value = 202;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Down")) ) {
		if ((stateType() == "S") && (ctrl()) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 202) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 200) ) {
			changeState_data d;
			d.value = 206;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Up")) ) {
		if ((stateType() == "S") && (ctrl()) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 202) ) {
			changeState_data d;
			d.value = 204;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Foward0")) ) {
		if ((stateType() == "A") && (ctrl()) || ((stateNo()) == 201) && ((moveHit()) && ((time()) > 15)) && (command("holdback")) ) {
			changeState_data d;
			d.value = 602;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Down0")) ) {
		if ((stateType() == "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 601;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Up0")) ) {
		if ((stateType() == "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 603;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Run")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 888;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Down")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 2000;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Up")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 300;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Foward")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 500;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Back0")) && (stateType() == "A") && (ctrl()) ) {
		changeState_data d;
		d.value = 510;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Up0")) && (stateType() == "A") && (ctrl()) ) {
		changeState_data d;
		d.value = 305;
		changeState(d);
	}
	
	// State controller
	if ((command("AI_SP_Down0")) && (stateType() == "A") && (ctrl()) ) {
		changeState_data d;
		d.value = 2001;
		changeState(d);
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("AI_OUGI1")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3155;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("AI_OUGI2")) ) {
		if (((stateType() == "S") || (stateType() == "A")) && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3200;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("AI_OUGI3")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3300;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI4")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3400;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI4")) ) {
		if ((stateType() == "A") && (ctrl()) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3410;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI5")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3500;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI6")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3600;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI7")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3700;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI7")) ) {
		if ((stateType() == "A") && (ctrl()) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3701;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("AI_OUGI8")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3860;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("FF")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 100;
		changeState(d);
	}
	
	// State controller
	if ((command("BB")) && (stateType() == "S") && (ctrl()) ) {
		changeState_data d;
		d.value = 105;
		changeState(d);
	}
	
	// State controller
	if ((command("s")) ) {
		if ((stateType() != "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 195;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("ougi1")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3155;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("ougi2")) ) {
		if (((stateType() == "S") || (stateType() == "A")) && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3200;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (command("ougi3")) ) {
		if ((stateType() == "S") && ((stateNo()) == 40) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3300;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi4")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3400;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi4")) ) {
		if ((stateType() == "A") && (ctrl()) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3410;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi5")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3500;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi6")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3600;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi7")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3700;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi7")) ) {
		if ((stateType() == "A") && (ctrl()) || (stateType() == "A") && (((((stateNo()) == 601) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) ) {
			changeState_data d;
			d.value = 3701;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("ougi8")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((stateType() == "S") && ((stateNo()) == 204)) && (moveHit())) && ((hitCount()) >= 2)) ) {
			changeState_data d;
			d.value = 3860;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_ATK_Run")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 888;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if (((stateNo()) == 100) && (stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 888;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && ((var(20)) == 1) && (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (command("b")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 2110;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && ((var(20)) == 3) && (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (command("b")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 2115;
			changeState(d);
		}
	}
	
	// State controller
	if (((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && ((var(20)) == 2) && (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (command("b")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 2120;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("holdfwd")) && (command("b")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 2100;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("holdback")) && (command("b")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 2101;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (stateType() == "S") && (ctrl()) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 206) || (command("holddown")) && (moveHit()) && ((stateNo()) == 202) || (moveHit()) && (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && ((stateNo()) == 400) ) {
			changeState_data d;
			d.value = 200;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holdback")) && (stateType() == "S") && (ctrl()) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 203) && ((hitCount()) == 2) || (moveHit()) && (((stateNo()) == 400) && (command("holdback"))) ) {
			changeState_data d;
			d.value = 201;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holdfwd")) && (stateType() == "S") && (ctrl()) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 206) || (command("holddown")) && (moveHit()) && ((stateNo()) == 203) && ((hitCount()) == 2) || (moveHit()) && (((stateNo()) == 400) && (command("holdfwd"))) ) {
			changeState_data d;
			d.value = 202;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holdup")) && (stateType() == "S") && ((stateNo()) == 40) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 202) ) {
			changeState_data d;
			d.value = 204;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holdup")) && (stateType() == "S") && ((stateNo()) == 40) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 200) || (command("holddown")) && (moveHit()) && ((stateNo()) == 206) || (moveHit()) && (((stateNo()) == 400) && (command("holdup"))) ) {
			changeState_data d;
			d.value = 203;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holddown")) && (stateType() == "C") && ((stateNo()) == 10) || (command("holdfwd")) && (moveHit()) && ((stateNo()) == 202) || (command("holdback") == 0) && (command("holdfwd") == 0) && (command("holddown") == 0) && (command("holdup") == 0) && (moveHit()) && ((stateNo()) == 200) || (moveHit()) && (((stateNo()) == 400) && (command("holddown"))) ) {
			changeState_data d;
			d.value = 206;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holddown")) && (stateType() == "C") && ((stateNo()) != 40) && (ctrl()) || (((stateNo()) == 5888) && ((time()) > 10)) ) {
			changeState_data d;
			d.value = 400;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) && (command("holddown") == 0) ) {
		if ((stateType() == "A") && (moveHit()) && ((stateNo()) == 602) && ((stateNo()) != 603) && ((hitCount()) == 2) ) {
			changeState_data d;
			d.value = 603;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) && (command("holddown") == 0) ) {
		if ((stateType() == "A") && (moveHit()) && ((stateNo()) == 600) && ((stateNo()) != 602) ) {
			changeState_data d;
			d.value = 602;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) && (command("holddown") == 0) ) {
		if ((stateType() == "A") && (moveHit()) && ((stateNo()) == 603) && ((stateNo()) != 601) ) {
			changeState_data d;
			d.value = 601;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("x")) ) {
		if ((command("holddown") == 0) && (command("holdback") == 0) && (command("holdup") == 0) && (stateType() == "A") && (ctrl()) || ((stateNo()) == 201) && ((moveHit()) && ((time()) > 15)) && (command("holdback")) ) {
			changeState_data d;
			d.value = 600;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("down_x")) ) {
		if ((stateType() == "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 601;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("back_x")) ) {
		if ((stateType() == "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 602;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("up_x")) ) {
		if ((stateType() == "A") && (ctrl()) ) {
			changeState_data d;
			d.value = 603;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdback") == 0) && (command("holdup") == 0) && (command("holdfwd") == 0) ) {
		if ((stateType() == "s") && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() != "A") ) {
			changeState_data d;
			d.value = 1000;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdback") == 0) && (command("holdup") == 0) && (command("holdfwd") == 0) ) {
		if ((stateType() == "a") && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() == "A") ) {
			changeState_data d;
			d.value = 1010;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holdup")) ) {
		if ((stateType() == "S") && ((stateNo()) == 40) && ((stateNo()) != 307) && ((stateNo()) != 302) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() != "A") ) {
			changeState_data d;
			d.value = 300;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdback") == 0) && (command("holdup")) && (command("holdfwd") == 0) ) {
		if ((stateType() == "A") && (ctrl()) && ((stateNo()) != 307) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() == "A") ) {
			changeState_data d;
			d.value = 305;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown")) && (command("holdback") == 0) && (command("holdup") == 0) && (command("holdfwd") == 0) ) {
		if ((stateType() == "C") && ((stateNo()) != 307) && ((stateNo()) != 302) && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() != "A") ) {
			changeState_data d;
			d.value = 2000;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown")) && (command("holdback") == 0) && (command("holdup") == 0) && (command("holdfwd") == 0) ) {
		if ((stateType() == "A") && ((stateNo()) != 307) && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() == "A") ) {
			changeState_data d;
			d.value = 2001;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdback") == 0) && (command("holdup") == 0) && (command("holdfwd")) ) {
		if ((stateType() == "S") && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() != "A") ) {
			changeState_data d;
			d.value = 500;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdup") == 0) && (command("holdfwd")) ) {
		if ((stateType() == "A") && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() == "A") ) {
			changeState_data d;
			d.value = 510;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holddown") == 0) && (command("holdback")) && (command("holdup") == 0) ) {
		if ((stateType() == "A") && (ctrl()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() == "A") ) {
			changeState_data d;
			d.value = 510;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("y")) && (command("holdback")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) || ((((((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) || ((stateNo()) == 601)) || ((stateNo()) == 602)) || ((stateNo()) == 603)) || ((stateNo()) == 600)) && (moveHit()) && (stateType() != "A") ) {
			changeState_data d;
			d.value = 410;
			changeState(d);
		}
	}
	
	// State controller
	if ((command("AI_SP_Back")) ) {
		if ((stateType() == "S") && (ctrl()) || (stateType() == "S") && ((((((stateNo()) == 200) || ((stateNo()) == 201)) || ((stateNo()) == 202)) || ((stateNo()) == 206)) || ((stateNo()) == 888)) && (moveHit()) ) {
			changeState_data d;
			d.value = 420;
			changeState(d);
		}
	}
	
	// State controller
	if ((((command("z")) && (getHelper(30000).var(20))) && (moveType() != "H")) && !(numHelper(130000)) && !(numExplod(140000)) ) {
		if ((ctrl()) || (! (stateNo()).inInterval('[', 40000, 50000, ']')) ) {
			explod_data d;
			d.anim = {"F", (140000 + (100 * (getHelper(30000).var(20))))};
			d.id = 140000;
			d.pos = {160, 232};
			d.posType = "left";
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 276447231;
			explod(d);
		}
	}
	
	// State controller
	if ((((command("z")) && (getHelper(30000).var(20))) && (moveType() != "H")) && !(numHelper(130000)) ) {
		if ((ctrl()) || (! (stateNo()).inInterval('[', 40000, 50000, ']')) ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "ranker_ABC";
			d.id = 130000;
			d.stateNo = (30000 + ((getHelper(30000).var(20)) * 100));
			d.pos = {-60, 0};
			d.posType = "p1";
			d.facing = 1;
			d.keyCtrl = 0;
			d.ownPal = 1;
			helper(d);
		}
	}
	
	// State controller
	if (((life()) < 200) && ((getHelper(30000).var(45)) > 0) && ((var(58)) >= 1000) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(1)) >= 1)) && (((getHelper(20000).stateNo()) == 20001) && ((getHelper(20000).fvar(2)) >= 1)) && (command("a")) ) {
		if ((stateType() == "S") && (ctrl()) ) {
			changeState_data d;
			d.value = 7999;
			changeState(d);
		}
	}
}

