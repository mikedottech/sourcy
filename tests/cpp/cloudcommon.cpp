/*
   cloudcommon.cpp
   Generated from cloudcommon.cns
   on 2026-05-13.

   by Sourcy Code Translator
   (c) 2017 - radexx

   Runtime version: 1.0

*/

#include "../cns/Cloudi_master.h"

void Cloudi::state_0()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.sprPriority = 0;
		setStateParams(params);
	}
	
	// State controller
	if ((((anim()) != 0) && ((anim()) != 5)) || (((anim()) == 5) && ((animTime()) == 0)) ) {
		changeAnim_data d;
		d.value = 0;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((abs((vel().x))) < 2) || ((time()) == 4) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (!(alive()) ) {
		changeState_data d;
		d.value = 5050;
		changeState(d);
	}
}

void Cloudi::state_10()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.physics = 'C';
		params.anim = 10;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velMul_data d;
		d.x = 0.75;
		velMul(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 11;
		changeState(d);
	}
}

void Cloudi::state_100()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.anim = 100;
		params.sprPriority = 1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		explod_data d;
		d.anim = {"F", 1105};
		d.id = 100;
		d.pos = {-10, -16};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.3, 0.3};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		explod(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		playSnd_data d;
		d.value = {180, 0};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(11)) ) {
		playSnd_data d;
		d.value = {180, 1};
		playSnd(d);
	}
	
	// State controller
	if (((numHelper(33811)) && (((time()) % 10) == 0)) ) {
		afterImage_data d;
		d.time = 10;
		d.length = 9;
		d.palBright = {70, 60, 0};
		d.palContrast = {120, 100, 50};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 2;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if (((vel().x) > 0) && (((time()) % (ifElse(((random()) < 499), 3, 4))) == 0) ) {
		if ((((numExplod(37810)) < 10) && (numHelper(33811))) || (((numExplod(37810)) < 10) && (getEnemy().numHelper(33812))) ) {
			explod_data d;
			d.anim = {"F", 37810};
			d.id = 37810;
			d.pos = {(10 + ((ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))) * (ifElse(((random()) < 499), 1, 2)))), (-28 + (ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 14, -13.5)))))};
			d.posType = "p1";
			d.sprPriority = 5;
			d.vel = {(ifElse(((random()) < 499), -2, (ifElse(((random()) < 499), -4, -3.5)))), 0};
			d.scale = {(ifElse(((random()) < 499), .4, (ifElse(((random()) < 499), .2, .6)))), (ifElse(((random()) < 499), 1, .5))};
			explod(d);
		}
	}
	
	// State controller
	if (1 ) {
		velSet_data d;
		d.x = ((_const("velocity.run.fwd.x")) + ((numHelper(33811)) * (_const("velocity.run.fwd.x"))));
		velSet(d);
	}
	
	// State controller
	if ((getEnemy().numHelper(33812)) ) {
		if (1 ) {
			velSet_data d;
			d.x = ((_const("velocity.run.fwd.x")) + ((getEnemy().numHelper(33812)) * (_const("velocity.run.fwd.x"))));
			velSet(d);
		}
	}
	
	// State controller
	if ((getEnemy().numHelper(34210)) ) {
		velMul_data d;
		d.x = 0.6;
		velMul(d);
	}
	
	// State controller
	if (1 ) {
		assertSpecial_data d;
		d.flag = "NoWalk";
		assertSpecial(d);
	}
	
	// State controller
	if (1 ) {
		assertSpecial_data d;
		d.flag = "NoAutoTurn";
		assertSpecial(d);
	}
	
	// State controller
	if ((command("holdfwd") == 0) ) {
		changeState_data d;
		d.value = 101;
		changeState(d);
	}
}

void Cloudi::state_101()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.anim = 90;
		params.velSet = {3, 0};
		params.sprPriority = 1;
		params.ctrl = 1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 1) ) {
		explod_data d;
		d.anim = {"F", 1118};
		d.id = 100;
		d.pos = {42, -21};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		explod(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		changeState(d);
	}
}

void Cloudi::state_105()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.physics = 'A';
		params.ctrl = 0;
		params.anim = 105;
		params.sprPriority = 1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"F", 130}, 0};
		playSnd(d);
	}
	
	// State controller
	if (((numHelper(33811)) && (((time()) % 10) == 0)) || ((getEnemy().numHelper(33812)) && (((time()) % 10) == 0)) ) {
		afterImage_data d;
		d.time = 10;
		d.length = 9;
		d.palBright = {70, 60, 0};
		d.palContrast = {120, 100, 50};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 2;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if (((vel().x) < 0) && (((time()) % (ifElse(((random()) < 499), 3, 4))) == 0) ) {
		if ((((numExplod(37810)) < 10) && (numHelper(33811))) || (((numExplod(37810)) < 10) && (getEnemy().numHelper(33812))) ) {
			explod_data d;
			d.anim = {"F", 37810};
			d.id = 37810;
			d.pos = {(10 + ((ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))) * (ifElse(((random()) < 499), 1, 2)))), (-28 + (ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 14, -13.5)))))};
			d.posType = "p1";
			d.sprPriority = 5;
			d.vel = {(ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))), 0};
			d.scale = {(ifElse(((random()) < 499), .4, (ifElse(((random()) < 499), .2, .6)))), (ifElse(((random()) < 499), 1, .5))};
			explod(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.x = ((_const("velocity.run.back.x")) + ((numHelper(33811)) * (_const("velocity.run.back.x"))));
		d.y = (_const("velocity.run.back.y"));
		velSet(d);
	}
	
	// State controller
	if ((getEnemy().numHelper(33812)) ) {
		if (((time()) == 0) ) {
			velSet_data d;
			d.x = ((_const("velocity.run.back.x")) + ((getEnemy().numHelper(33812)) * (_const("velocity.run.back.x"))));
			d.y = (_const("velocity.run.back.y"));
			velSet(d);
		}
	}
	
	// State controller
	if (((getEnemy().numHelper(34210)) && !(time())) ) {
		velMul_data d;
		d.x = 0.6;
		velMul(d);
	}
	
	// State controller
	if (((time()) == 2) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 0) ) {
		changeState_data d;
		d.value = 106;
		changeState(d);
	}
}

void Cloudi::state_106()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.ctrl = 0;
		params.anim = 47;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (((time()) == 2) ) {
		makeDust_data d;
		d.pos = {-5, -2};
		d.spacing = 1;
		makeDust(d);
	}
	
	// State controller
	if (((time()) == 7) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_11()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.physics = 'C';
		params.anim = 11;
		params.sprPriority = 0;
		setStateParams(params);
	}
	
	// State controller
	if ((((anim()) == 6) && ((animTime()) == 0)) ) {
		changeAnim_data d;
		d.value = 11;
		changeAnim(d);
	}
}

void Cloudi::state_12()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.anim = 12;
		setStateParams(params);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		changeState(d);
	}
}

void Cloudi::state_120()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'U';
		params.physics = 'U';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeAnim_data d;
		d.value = ((120 + (stateType() == "C")) + ((stateType() == "A") * 2));
		changeAnim(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "S")) ) {
		stateTypeSet_data d;
		d.physics = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "C")) ) {
		stateTypeSet_data d;
		d.physics = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "A")) ) {
		stateTypeSet_data d;
		d.physics = "A";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = ((130 + (stateType() == "C")) + ((stateType() == "A") * 2));
		changeState(d);
	}
	
	// State controller
	if ((command("holdback") == 0) || !(inGuardDist()) ) {
		changeState_data d;
		d.value = 140;
		changeState(d);
	}
}

void Cloudi::state_130()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((anim()) != 130) ) {
		changeAnim_data d;
		d.value = 130;
		changeAnim(d);
	}
	
	// State controller
	if ((command("holddown")) ) {
		changeState_data d;
		d.value = 131;
		changeState(d);
	}
	
	// State controller
	if ((command("holdback") == 0) || !(inGuardDist()) ) {
		changeState_data d;
		d.value = 140;
		changeState(d);
	}
}

void Cloudi::state_131()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.physics = 'C';
		setStateParams(params);
	}
	
	// State controller
	if (((anim()) != 131) ) {
		changeAnim_data d;
		d.value = 131;
		changeAnim(d);
	}
	
	// State controller
	if ((command("holddown") == 0) ) {
		changeState_data d;
		d.value = 130;
		changeState(d);
	}
	
	// State controller
	if ((command("holdback") == 0) || !(inGuardDist()) ) {
		changeState_data d;
		d.value = 140;
		changeState(d);
	}
}

void Cloudi::state_132()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((anim()) != 132) ) {
		changeAnim_data d;
		d.value = 132;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (_const("movement.yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (1 ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(0) = (floor((((pos().y) >= 0) && ((vel().y) > 0))))
		}
	}
	
	// State controller
	if ((sysvar(0)) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if ((sysvar(0)) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if ((sysvar(0)) && (command("holdback")) && (inGuardDist()) ) {
		changeState_data d;
		d.value = 130;
		changeState(d);
	}
	
	// State controller
	if ((sysvar(0)) ) {
		changeState_data d;
		d.value = 52;
		changeState(d);
	}
	
	// State controller
	if ((command("holdback") == 0) || !(inGuardDist()) ) {
		changeState_data d;
		d.value = 140;
		changeState(d);
	}
}

void Cloudi::state_140()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'U';
		params.physics = 'U';
		params.ctrl = 1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeAnim_data d;
		d.value = ((140 + (stateType() == "C")) + ((stateType() == "A") * 2));
		changeAnim(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "S")) ) {
		stateTypeSet_data d;
		d.physics = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "C")) ) {
		stateTypeSet_data d;
		d.physics = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if ((((time()) == 0) && (stateType() == "A")) ) {
		stateTypeSet_data d;
		d.physics = "A";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
}

void Cloudi::state_150()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"S", 131}, 0};
		playSnd(d);
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = 150;
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = (151 + (2 * (command("holddown"))));
		changeState(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		forceFeedback_data d;
		d.waveForm = "square";
		d.time = 3;
		forceFeedback(d);
	}
}

void Cloudi::state_151()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'H';
		params.physics = 'S';
		params.anim = 150;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (((time()) == (getHitVar("slidetime"))) || (hitOver()) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == (getHitVar("ctrltime"))) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		changeState_data d;
		d.value = 130;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_152()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"S", 131}, 0};
		playSnd(d);
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = 151;
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = (151 + (2 * (command("holddown"))));
		changeState(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		forceFeedback_data d;
		d.waveForm = "square";
		d.time = 4;
		forceFeedback(d);
	}
}

void Cloudi::state_153()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.moveType = 'H';
		params.physics = 'C';
		params.anim = 151;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (((time()) == (getHitVar("slidetime"))) || (hitOver()) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == (getHitVar("ctrltime"))) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((stateType() == "S") && (command("holddown"))) ) {
		stateTypeSet_data d;
		d.physics = "C";
		d.stateType = "C";
		stateTypeSet(d);
	}
	
	// State controller
	if (((stateType() == "C") && (command("holddown") == 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		d.stateType = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		changeState_data d;
		d.value = 131;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_154()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"S", 131}, 0};
		playSnd(d);
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = 152;
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = 155;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		forceFeedback_data d;
		d.waveForm = "square";
		d.time = 4;
		forceFeedback(d);
	}
}

void Cloudi::state_155()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		params.anim = 152;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		d.y = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (_const("movement.yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((time()) == (getHitVar("ctrltime"))) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (1 ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(0) = (floor((((pos().y) >= 0) && ((vel().y) > 0))))
		}
	}
	
	// State controller
	if ((sysvar(0)) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if ((sysvar(0)) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if ((sysvar(0)) && (command("holdback")) && (inGuardDist()) ) {
		changeState_data d;
		d.value = 130;
		changeState(d);
	}
	
	// State controller
	if ((sysvar(0)) ) {
		changeState_data d;
		d.value = 52;
		changeState(d);
	}
}

void Cloudi::state_170()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.anim = 170;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
}

void Cloudi::state_175()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && !(selfAnimExist(175)) ) {
		changeState_data d;
		d.value = 170;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeAnim_data d;
		d.value = 175;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
}

void Cloudi::state_190()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((selfAnimExist(190)) ) {
		changeAnim_data d;
		d.value = 190;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeState_data d;
		d.value = 191;
		changeState(d);
	}
}

void Cloudi::state_191()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeState_data d;
		d.value = 0;
		changeState(d);
	}
}

void Cloudi::state_20()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.sprPriority = 0;
		setStateParams(params);
	}
	
	// State controller
	if (((animElem(5)) && ((anim()) == 20)) || ((animElem(6)) && ((anim()) == 21)) ) {
		playSnd_data d;
		d.value = {180, 0};
		playSnd(d);
	}
	
	// State controller
	if (((numHelper(33811)) && (((time()) % 10) == 0)) || ((getEnemy().numHelper(33812)) && (((time()) % 10) == 0)) ) {
		afterImage_data d;
		d.time = 10;
		d.length = 9;
		d.palBright = {70, 60, 0};
		d.palContrast = {120, 100, 50};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 2;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if (((vel().x) > 0) && (((time()) % (ifElse(((random()) < 499), 3, 4))) == 0) ) {
		if ((((numExplod(37810)) < 10) && (numHelper(33811))) || (((numExplod(37810)) < 10) && (getEnemy().numHelper(33812))) ) {
			explod_data d;
			d.anim = {"F", 37810};
			d.id = 37810;
			d.pos = {(10 + ((ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))) * (ifElse(((random()) < 499), 1, 2)))), (-28 + (ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 14, -13.5)))))};
			d.posType = "p1";
			d.sprPriority = 5;
			d.vel = {(ifElse(((random()) < 499), -2, (ifElse(((random()) < 499), -4, -3.5)))), 0};
			d.scale = {(ifElse(((random()) < 499), .4, (ifElse(((random()) < 499), .2, .6)))), (ifElse(((random()) < 499), 1, .5))};
			explod(d);
		}
	}
	
	// State controller
	if (((vel().x) < 0) && (((time()) % (ifElse(((random()) < 499), 3, 4))) == 0) ) {
		if ((((numExplod(37810)) < 10) && (numHelper(33811))) || (((numExplod(37810)) < 10) && (getEnemy().numHelper(33812))) ) {
			explod_data d;
			d.anim = {"F", 37810};
			d.id = 37810;
			d.pos = {(10 + ((ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))) * (ifElse(((random()) < 499), 1, 2)))), (-28 + (ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 14, -13.5)))))};
			d.posType = "p1";
			d.sprPriority = 5;
			d.vel = {(ifElse(((random()) < 499), 2, (ifElse(((random()) < 499), 4, 3.5)))), 0};
			d.scale = {(ifElse(((random()) < 499), .4, (ifElse(((random()) < 499), .2, .6)))), (ifElse(((random()) < 499), 1, .5))};
			explod(d);
		}
	}
	
	// State controller
	if ((command("holdfwd")) ) {
		velSet_data d;
		d.x = ((_const("velocity.walk.fwd.x")) + ((numHelper(33811)) * (_const("velocity.walk.fwd.x"))));
		velSet(d);
	}
	
	// State controller
	if ((command("holdback")) ) {
		velSet_data d;
		d.x = ((_const("velocity.walk.back.x")) + ((numHelper(33811)) * (_const("velocity.walk.back.x"))));
		velSet(d);
	}
	
	// State controller
	if ((getEnemy().numHelper(33812)) ) {
		if ((command("holdfwd")) ) {
			velSet_data d;
			d.x = ((_const("velocity.walk.fwd.x")) + ((getEnemy().numHelper(33812)) * (_const("velocity.walk.fwd.x"))));
			velSet(d);
		}
	}
	
	// State controller
	if ((getEnemy().numHelper(33812)) ) {
		if ((command("holdback")) ) {
			velSet_data d;
			d.x = ((_const("velocity.walk.back.x")) + ((getEnemy().numHelper(33812)) * (_const("velocity.walk.back.x"))));
			velSet(d);
		}
	}
	
	// State controller
	if ((getEnemy().numHelper(34210)) ) {
		velMul_data d;
		d.x = 0.6;
		velMul(d);
	}
	
	// State controller
	if (((vel().x) > 0) ) {
		if ((((anim()) != 20) && ((anim()) != 5)) || (((anim()) == 5) && ((animTime()) == 0)) ) {
			changeAnim_data d;
			d.value = 20;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((vel().x) < 0) ) {
		if ((((anim()) != 21) && ((anim()) != 5)) || (((anim()) == 5) && ((animTime()) == 0)) ) {
			changeAnim_data d;
			d.value = 21;
			changeAnim(d);
		}
	}
}

void Cloudi::state_40()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.anim = 40;
		params.ctrl = 0;
		params.sprPriority = 1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(0))
		}
	}
	
	// State controller
	if ((command("holdfwd")) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(1))
		}
	}
	
	// State controller
	if ((command("holdback")) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(-1))
		}
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		velSet_data d;
		d.x = (ifElse(((sysvar(1)) == 0), (_const("velocity.jump.neu.x")), (ifElse(((sysvar(1)) == 1), (_const("velocity.jump.fwd.x")), (_const("velocity.jump.back.x"))))));
		d.y = (_const("velocity.jump.y"));
		velSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) && ((prevStateNo()) == 100) && ((sysvar(1)) == 1) ) {
		velSet_data d;
		d.x = (_const("velocity.runjump.fwd.x"));
		velSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 50;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_45()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((((time()) == 0) && ((random()) > 699)) ) {
		playSnd_data d;
		d.value = {{"S", 101}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((selfAnimExist(44)) ) {
		changeAnim_data d;
		d.value = 44;
		changeAnim(d);
	}
	
	// State controller
	if (!(selfAnimExist(44)) ) {
		changeAnim_data d;
		d.value = 41;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(0))
		}
	}
	
	// State controller
	if ((command("holdfwd")) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(1))
		}
	}
	
	// State controller
	if ((command("holdback")) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor(-1))
		}
	}
	
	// State controller
	if (((time()) == 2) ) {
		velSet_data d;
		d.x = (ifElse(((sysvar(1)) == 0), (_const("velocity.airjump.neu.x")), (ifElse(((sysvar(1)) == 1), (_const("velocity.airjump.fwd.x")), (_const("velocity.airjump.back.x"))))));
		d.y = (_const("velocity.airjump.y"));
		velSet(d);
	}
	
	// State controller
	if ((((time()) == 2) && ((vel().x) == 0)) ) {
		explod_data d;
		d.anim = {"F", 1115};
		d.id = 100;
		d.pos = {0, -10};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = -3;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		explod(d);
	}
	
	// State controller
	if ((((time()) == 2) && ((vel().x) != 0)) ) {
		explod_data d;
		d.anim = {"F", 1116};
		d.id = 100;
		d.pos = {(-6 + (ifElse(((vel().x) < 0), 12, 0))), -10};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = -3;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		d.facing = (ifElse(((vel().x) > 0), 1, -1));
		explod(d);
	}
	
	// State controller
	if (((time()) == 2) ) {
		changeState_data d;
		d.value = 50;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_50()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.physics = 'A';
		setStateParams(params);
	}
	
	// State controller
	if (((numHelper(33811)) && (((time()) % 10) == 0)) || ((getEnemy().numHelper(33812)) && (((time()) % 10) == 0)) ) {
		afterImage_data d;
		d.time = 10;
		d.length = 9;
		d.palBright = {70, 60, 0};
		d.palContrast = {120, 100, 50};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 2;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if ((!(time()) && (numHelper(33811))) || (!(time()) && (getEnemy().numHelper(33812))) ) {
		velMul_data d;
		d.x = 1.5;
		d.y = 1.3;
		velMul(d);
	}
	
	// State controller
	if (((((time()) == 0) && ((prevStateNo()) == 40)) && ((vel().x) == 0)) ) {
		explod_data d;
		d.anim = {"F", 1113};
		d.id = 100;
		d.pos = {0, -24};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = -3;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		explod(d);
	}
	
	// State controller
	if (((((time()) == 0) && ((prevStateNo()) == 40)) && ((vel().x) != 0)) ) {
		explod_data d;
		d.anim = {"F", 1114};
		d.id = 100;
		d.pos = {(-14 + (ifElse(((vel().x) < 0), 21, 0))), -27};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = -3;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		d.facing = (ifElse(((vel().x) > 0), 1, -1));
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"F", 125}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((((time()) == 0) && ((random()) > 699)) ) {
		playSnd_data d;
		d.value = {{"S", 101}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = 0
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeAnim_data d;
		d.value = (ifElse(((vel().x) == 0), 41, (ifElse(((vel().x) > 0), 42, 43))));
		changeAnim(d);
	}
	
	// State controller
	if (((vel().y) > -2) && (selfAnimExist(((anim()) + 3))) ) {
		changeAnim_data d;
		d.persistent = 0;
		d.value = ((anim()) + 3);
		changeAnim(d);
	}
}

void Cloudi::state_5000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (! (getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = ((ifElse(((getHitVar("groundtype")) == 1), 5000, 5010)) + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = 5030;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (((getHitVar("animtype")).inInterval('[', 4, 5, ']')) && (selfAnimExist((5047 + (getHitVar("animtype")))))) ) {
		changeAnim_data d;
		d.value = (5047 + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) > 0) ) {
		changeAnim_data d;
		d.value = (anim());
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (((getHitVar("yvel")) != 0) || (getHitVar("fall"))) || ((pos().y) != 0) ) {
		stateTypeSet_data d;
		d.stateType = "a";
		stateTypeSet(d);
	}
	
	// State controller
	if ((hitShakeOver()) && (((getHitVar("yvel")) == 0) && !(getHitVar("fall"))) ) {
		changeState_data d;
		d.value = 5001;
		changeState(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = 5030;
		changeState(d);
	}
	
	// State controller
	if (((anim()) == 5000) || ((anim()) == 5010) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 6;
		d.waveForm = "square";
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5001) || ((anim()) == 5011) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 8;
		d.waveForm = "sinesquare";
		d.ampl = {110, -1, -.3};
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5012) || ((anim()) == 5002) || ((anim()) == 5030) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 15;
		d.waveForm = "sinesquare";
		d.ampl = 140;
		forceFeedback(d);
	}
}

void Cloudi::state_5001()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'H';
		params.physics = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeAnim_data d;
		d.value = ((5005 + (getHitVar("animtype"))) + (((getHitVar("groundtype")) == 2) * 10));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) >= (getHitVar("slidetime"))) ) {
		velMul_data d;
		d.x = 0.6;
		velMul(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		defenceMulSet_data d;
		d.value = 1;
		defenceMulSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_5010()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (! (getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = (5020 + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = 5030;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (((getHitVar("animtype")).inInterval('[', 4, 5, ']')) && (selfAnimExist((5047 + (getHitVar("animtype")))))) ) {
		changeAnim_data d;
		d.value = (5047 + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) > 0) ) {
		changeAnim_data d;
		d.value = (anim());
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		if ((((getHitVar("yvel")) != 0) || (getHitVar("fall"))) || ((pos().y) != 0) ) {
			stateTypeSet_data d;
			d.stateType = "a";
			stateTypeSet(d);
		}
	}
	
	// State controller
	if ((hitShakeOver()) && (((getHitVar("yvel")) == 0) && !(getHitVar("fall"))) ) {
		changeState_data d;
		d.value = 5011;
		changeState(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = 5030;
		changeState(d);
	}
	
	// State controller
	if (((anim()) == 5020) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 6;
		d.waveForm = "square";
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5021) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 8;
		d.waveForm = "sinesquare";
		d.ampl = {110, -1, -.3};
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5022) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 15;
		d.waveForm = "sinesquare";
		d.ampl = 140;
		forceFeedback(d);
	}
}

void Cloudi::state_5011()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'C';
		params.moveType = 'H';
		params.physics = 'C';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeAnim_data d;
		d.value = (5025 + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) >= (getHitVar("slidetime"))) ) {
		velMul_data d;
		d.x = 0.6;
		velMul(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		defenceMulSet_data d;
		d.value = 1;
		defenceMulSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		changeState_data d;
		d.value = 11;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_5020()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (! (getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = ((ifElse(((getHitVar("airtype")) == 1), 5000, 5010)) + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("animtype")).inInterval('[', 3, 5, ']')) ) {
		changeAnim_data d;
		d.value = 5030;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (((getHitVar("animtype")).inInterval('[', 4, 5, ']')) && (selfAnimExist((5047 + (getHitVar("animtype")))))) ) {
		changeAnim_data d;
		d.value = (5047 + (getHitVar("animtype")));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) > 0) ) {
		changeAnim_data d;
		d.value = (anim());
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = 5030;
		changeState(d);
	}
	
	// State controller
	if (((anim()) == 5000) || ((anim()) == 5010) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 6;
		d.waveForm = "square";
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5001) || ((anim()) == 5011) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 8;
		d.waveForm = "sinesquare";
		d.ampl = {110, -1, -.3};
		forceFeedback(d);
	}
	
	// State controller
	if (((anim()) == 5012) || ((anim()) == 5002) || ((anim()) == 5030) || ((anim()).inInterval('[', 5051, 5059, ']')) ) {
		forceFeedback_data d;
		d.persistent = 0;
		d.time = 15;
		d.waveForm = "sinesquare";
		d.ampl = 140;
		forceFeedback(d);
	}
}

void Cloudi::state_5030()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		d.y = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (!(hitFall()) ) {
		if ((hitOver()) || ((vel().y) > 0) && ((pos().y) >= 10) ) {
			changeState_data d;
			d.value = 5040;
			changeState(d);
		}
	}
	
	// State controller
	if ((hitFall()) ) {
		if ((hitOver()) || ((vel().y) > 0) && ((pos().y) >= 10) ) {
			changeState_data d;
			d.value = 5050;
			changeState(d);
		}
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 5035;
		changeState(d);
	}
}

void Cloudi::state_5035()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (selfAnimExist(5035)) && (! (anim()).inInterval('[', 5051, 5059, ']')) && ((anim()) != 5090) ) {
		changeAnim_data d;
		d.value = 5035;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (!(hitFall()) ) {
		if ((hitOver()) || ((animTime()) == 0) || ((vel().y) > 0) && ((pos().y) >= 10) || ((time()) == 0) && ((anim()) != 5035) ) {
			changeState_data d;
			d.value = 5040;
			changeState(d);
		}
	}
	
	// State controller
	if ((hitFall()) ) {
		if ((hitOver()) || ((animTime()) == 0) || ((vel().y) > 0) && ((pos().y) >= 10) || ((time()) == 0) && ((anim()) != 5035) ) {
			changeState_data d;
			d.value = 5050;
			changeState(d);
		}
	}
}

void Cloudi::state_5040()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (!(alive()) ) {
		changeState_data d;
		d.value = 5050;
		changeState(d);
	}
	
	// State controller
	if (((animTime()) == 0) && ((anim()) != 5040) || ((time()) == 0) && ((anim()) != 5035) ) {
		changeAnim_data d;
		d.value = 5040;
		changeAnim(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		stateTypeSet_data d;
		d.moveType = "I";
		stateTypeSet(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 0) ) {
		changeState_data d;
		d.value = 52;
		changeState(d);
	}
}

void Cloudi::state_5050()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((animTime()) == 0) && ((anim()) == 5035) || ((time()) == 0) && ((anim()) != 5035) && ((! (anim()).inInterval('[', 5051, 5059, ']')) && (! (anim()).inInterval('[', 5061, 5069, ']'))) && ((anim()) != 5090) ) {
		changeAnim_data d;
		d.value = 5050;
		changeAnim(d);
	}
	
	// State controller
	if (((anim()).inInterval('[', 5050, 5059, ']')) && ((vel().y) >= (ifElse(((anim()) == 5050), 1, -2))) && (selfAnimExist(((anim()) + 10))) ) {
		changeAnim_data d;
		d.persistent = 0;
		d.value = ((anim()) + 10);
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= -20) && (alive()) && (canRecover()) ) {
		if ((command("recovery")) ) {
			changeState_data d;
			d.value = 5200;
			changeState(d);
		}
	}
	
	// State controller
	if (((vel().y) > -1) && (alive()) && (canRecover()) ) {
		if ((command("recovery")) ) {
			changeState_data d;
			d.value = 5210;
			changeState(d);
		}
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= (ifElse((((anim()).inInterval('[', 5051, 5059, ']')) || ((anim()).inInterval('[', 5061, 5069, ']'))), 0, 25))) ) {
		changeState_data d;
		d.value = 5100;
		changeState(d);
	}
}

void Cloudi::state_5070()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = 5070;
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) ) {
		changeState_data d;
		d.value = 5071;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		forceFeedback_data d;
		d.time = 12;
		d.waveForm = "sinesquare";
		d.ampl = 140;
		forceFeedback(d);
	}
}

void Cloudi::state_5071()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		d.y = 1;
		hitVelSet(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 15) ) {
		changeState_data d;
		d.value = 5110;
		changeState(d);
	}
}

void Cloudi::state_5080()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(2) = (ifElse(((getHitVar("yvel")) == 0), 5080, 5090))
		}
	}
	
	// State controller
	if (((time()) == 0) && (((anim()).inInterval('[', 5081, 5089, ']')) || ((anim()).inInterval('[', 5111, 5119, ']'))) && (selfAnimExist(((sysvar(2)) + ((anim()) % 10)))) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(2) = sysvar(2) + ((anim()) % 10)
		}
	}
	
	// State controller
	if (((time()) == 0) && ((sysvar(2)) == 5090) && !(selfAnimExist(5090)) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(2) = 5030
		}
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = (sysvar(2));
		changeAnim(d);
	}
	
	// State controller
	if ((hitShakeOver()) && ((getHitVar("yvel")) == 0) ) {
		changeState_data d;
		d.value = 5081;
		changeState(d);
	}
	
	// State controller
	if ((hitShakeOver()) && ((getHitVar("yvel")) != 0) ) {
		changeState_data d;
		d.value = 5030;
		changeState(d);
	}
}

void Cloudi::state_5081()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'C';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitVelSet_data d;
		d.x = 1;
		hitVelSet(d);
	}
	
	// State controller
	if ((hitOver()) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(0) = 1
		}
	}
	
	// State controller
	if ((hitOver()) ) {
		changeState_data d;
		d.value = 5110;
		changeState(d);
	}
}

void Cloudi::state_51()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.physics = 'A';
		setStateParams(params);
	}
}

void Cloudi::state_5100()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("fall.yvel")) == 0) && ((vel().x) > 1) ) {
		velSet_data d;
		d.x = 1;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		fallEnvShake_data d;
		fallEnvShake(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor((vel().y)))
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		if (((! (anim()).inInterval('[', 5051, 5059, ']')) && (! (anim()).inInterval('[', 5061, 5069, ']'))) || !(selfAnimExist((5100 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = 5100;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && (((anim()).inInterval('[', 5051, 5059, ']')) || ((anim()).inInterval('[', 5061, 5069, ']'))) && (selfAnimExist((5100 + ((anim()) % 10)))) ) {
		changeAnim_data d;
		d.value = (5100 + ((anim()) % 10));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velMul_data d;
		d.x = 0.75;
		velMul(d);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("fall.yvel")) == 0) ) {
		changeState_data d;
		d.value = 5110;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		gameMakeAnim_data d;
		d.value = ((60 + ((sysvar(1)) > 5)) + ((sysvar(1)) > 14));
		d.pos = {0, 0};
		d.under = ((sysvar(1)) <= 14);
		gameMakeAnim(d);
	}
	
	// State controller
	if ((((time()) == 1) && ((sysvar(1)) > 14)) ) {
		gameMakeAnim_data d;
		d.value = 61;
		d.pos = {0, 0};
		d.under = ((sysvar(1)) <= 14);
		gameMakeAnim(d);
	}
	
	// State controller
	if (((time()) == 3) ) {
		hitFallDamage_data d;
		hitFallDamage(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		playSnd_data d;
		d.value = {{"F", 7}, (((sysvar(1)) > 5) + ((sysvar(1)) > 14))};
		playSnd(d);
	}
	
	// State controller
	if (1 ) {
		posFreeze_data d;
		posFreeze(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 5101;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		forceFeedback_data d;
		d.waveForm = "sinesquare";
		d.ampl = {128, -3, -.2, 0.005};
		d.time = 20;
		forceFeedback(d);
	}
}

void Cloudi::state_5101()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		if ((! (anim()).inInterval('[', 5101, 5109, ']')) || !(selfAnimExist((5160 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = 5160;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		if (((anim()).inInterval('[', 5101, 5109, ']')) && (selfAnimExist((5160 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = (5160 + ((anim()) % 10));
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitFallVel_data d;
		hitFallVel(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 20;
		posSet(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = 0.4;
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 12) ) {
		changeState_data d;
		d.value = 5110;
		changeState(d);
	}
}

void Cloudi::state_5110()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		fallEnvShake_data d;
		fallEnvShake(d);
	}
	
	// State controller
	if ((selfAnimExist((5110 + ((anim()) % 10)))) && ((anim()).inInterval('[', 5081, 5089, ']')) ) {
		changeAnim_data d;
		d.persistent = 0;
		d.value = (5110 + ((anim()) % 10));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (! (anim()).inInterval('[', 5110, 5119, ']')) ) {
		if ((! (anim()).inInterval('[', 5161, 5169, ']')) || !(selfAnimExist((5170 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = 5170;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && (! (anim()).inInterval('[', 5110, 5119, ']')) ) {
		if (((anim()).inInterval('[', 5161, 5169, ']')) && (selfAnimExist((5170 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = (5170 + ((anim()) % 10));
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitFallDamage_data d;
		hitFallDamage(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (((time()) == 0) && ((getHitVar("fall.yvel")) != 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(1) = (floor((vel().y)))
		}
	}
	
	// State controller
	if (((time()) == 0) && !(sysvar(0)) ) {
		playSnd_data d;
		d.value = {{"F", 7}, (((sysvar(1)) > 5) + ((sysvar(1)) > 14))};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) && !(sysvar(0)) ) {
		gameMakeAnim_data d;
		d.value = ((60 + ((sysvar(1)) > 5)) + ((sysvar(1)) > 14));
		d.pos = {0, 0};
		d.under = ((sysvar(1)) <= 14);
		gameMakeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((anim()).inInterval('[', 5171, 5179, ']')) && (selfAnimExist((5110 + ((anim()) % 10)))) ) {
		if (((animTime()) == 0) || (sysvar(0)) ) {
			changeAnim_data d;
			d.persistent = 0;
			d.value = (5110 + ((anim()) % 10));
			changeAnim(d);
		}
	}
	
	// State controller
	if ((! (anim()).inInterval('[', 5111, 5119, ']')) ) {
		if (((animTime()) == 0) || (sysvar(0)) ) {
			changeAnim_data d;
			d.persistent = 0;
			d.value = 5110;
			changeAnim(d);
		}
	}
	
	// State controller
	if (!(alive()) ) {
		if (((animTime()) == 0) || (sysvar(0)) || ((anim()).inInterval('[', 5110, 5119, ']')) ) {
			changeState_data d;
			d.value = 5150;
			changeState(d);
		}
	}
	
	// State controller
	if ((sysvar(0)) && ((time()) == 0) ) {
		canExecuteController_data d;
		if( canExecuteController(d) ) {
			sysvar(0) = 0
		}
	}
	
	// State controller
	if (1 ) {
		velMul_data d;
		d.x = 0.85;
		velMul(d);
	}
	
	// State controller
	if ((alive()) && ((time()) == 0) ) {
		forceFeedback_data d;
		d.time = 8;
		d.ampl = 240;
		d.waveForm = "sine";
		forceFeedback(d);
	}
	
	// State controller
	if (!(alive()) && ((time()) == 0) ) {
		forceFeedback_data d;
		d.ampl = {200, 7, -.467};
		d.time = 30;
		d.waveForm = "sine";
		forceFeedback(d);
	}
	
	// State controller
	if (((alive()) && ((time()) > 2)) ) {
		if (((command("back")) || (command("fwd"))) || ((command("holdback")) || (command("holdfwd"))) ) {
			changeState_data d;
			d.value = 5888;
			d.ctrl = 0;
			changeState(d);
		}
	}
}

void Cloudi::state_5120()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'I';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		if ((! (anim()).inInterval('[', 5111, 5119, ']')) || !(selfAnimExist((5120 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = 5120;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		if (((anim()).inInterval('[', 5111, 5119, ']')) && (selfAnimExist((5120 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = (5120 + ((anim()) % 10));
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		hitFallSet_data d;
		d.value = 1;
		hitFallSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		notHitBy_data d;
		d.value = {"", "NT", "ST", "HT"};
		d.time = 12;
		notHitBy(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		notHitBy_data d;
		d.value2 = {"S", "NA"};
		d.time = 3;
		notHitBy(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_5150()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'H';
		params.physics = 'N';
		params.sprPriority = -3;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (selfAnimExist(5140)) ) {
		if (((! (anim()).inInterval('[', 5111, 5119, ']')) && (! (anim()).inInterval('[', 5171, 5179, ']'))) || !(selfAnimExist((5140 + ((anim()) % 10)))) ) {
			changeAnim_data d;
			d.value = 5140;
			changeAnim(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && (((anim()).inInterval('[', 5111, 5119, ']')) || ((anim()).inInterval('[', 5171, 5179, ']'))) && (selfAnimExist((5140 + ((anim()) % 10)))) ) {
		changeAnim_data d;
		d.value = (5140 + ((anim()) % 10));
		changeAnim(d);
	}
	
	// State controller
	if (((matchOver()) == 1) && ((anim()).inInterval('[', 5140, 5149, ']')) && (selfAnimExist(((anim()) + 10))) ) {
		changeAnim_data d;
		d.persistent = 0;
		d.value = ((anim()) + 10);
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) && (! (anim()).inInterval('[', 5140, 5159, ']')) && (! (anim()).inInterval('[', 5110, 5119, ']')) ) {
		changeAnim_data d;
		d.value = 5110;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		velMul_data d;
		d.x = 0.85;
		velMul(d);
	}
	
	// State controller
	if (((vel().x) < .05) ) {
		velSet_data d;
		d.persistent = 0;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
}

void Cloudi::state_52()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.physics = 'S';
		params.velSet = {0, 0};
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		removeExplod_data d;
		d.id = 101;
		removeExplod(d);
	}
	
	// State controller
	if ((((time()) == 0) && (isHelper(1112))) ) {
		modifyExplod_data d;
		d.id = 1016;
		d.removeTime = 1;
		modifyExplod(d);
	}
	
	// State controller
	if ((((time()) == 0) && (isHelper(1112))) ) {
		changeState_data d;
		d.value = 1001;
		changeState(d);
	}
	
	// State controller
	if ((((time()) == 0) && (isHelper(3500))) || (((time()) == 0) && (isHelper(3501))) || (((time()) == 0) && (isHelper(3502))) || (((time()) == 0) && (isHelper(3503))) || (((time()) == 0) && (isHelper(3504))) || (((time()) == 0) && (isHelper(3505))) ) {
		changeState_data d;
		d.value = 3503;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) == 3705) ) {
		changeState_data d;
		d.value = 3706;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) == 3100) ) {
		changeState_data d;
		d.value = 3101;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) == 3300) ) {
		changeState_data d;
		d.value = 3301;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) == 3402) ) {
		changeState_data d;
		d.value = 3403;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) == 2001) ) {
		changeState_data d;
		d.value = 2002;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) && ((prevStateNo()) != 2001) && ((prevStateNo()) != 8005) ) {
		changeAnim_data d;
		d.value = 47;
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (((time()) == 3) && ((prevStateNo()) != 2001) && ((prevStateNo()) != 8005) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		explod_data d;
		d.anim = {"F", 1117};
		d.id = 100;
		d.pos = {2, -16};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {1, 1};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		explod(d);
	}
	
	// State controller
	if (((animTime()) == 0) && ((prevStateNo()) != 8005) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_5200()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'N';
		setStateParams(params);
	}
	
	// State controller
	if (((anim()) == 5035) && ((animTime()) == 0) ) {
		changeAnim_data d;
		d.value = 5050;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		velAdd_data d;
		d.y = (getHitVar("yaccel"));
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 10) ) {
		selfState_data d;
		d.value = 5201;
		selfState(d);
	}
}

void Cloudi::state_5201()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'H';
		params.physics = 'A';
		params.anim = 5200;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = {"F", 320};
		d.id = 102;
		d.pos = {0, -30};
		d.posType = "p1";
		d.bindTime = -1;
		d.removeTime = -2;
		d.scale = {0.8, 0.8};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"S", 25}, 6};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) && ((p2Dist().x) < -5) ) {
		turn_data d;
		turn(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.x = -.15;
		d.y = -3.5;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {128, 128, 128};
		palFX(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		gameMakeAnim_data d;
		d.value = 60;
		d.pos = {0, 0};
		d.under = 1;
		gameMakeAnim(d);
	}
}

void Cloudi::state_5210()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'I';
		params.physics = 'N';
		params.anim = 5210;
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = {"F", 320};
		d.id = 102;
		d.pos = {0, -30};
		d.posType = "p1";
		d.bindTime = -1;
		d.removeTime = -2;
		d.scale = {0.8, 0.8};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"S", 25}, 6};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {128, 128, 128};
		palFX(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posFreeze_data d;
		d.value = 4;
		posFreeze(d);
	}
	
	// State controller
	if (((time()) == 0) && ((p2Dist().x) < -20) ) {
		turn_data d;
		turn(d);
	}
	
	// State controller
	if (((time()) == 4) ) {
		velMul_data d;
		d.x = 0.8;
		d.y = 0.8;
		velMul(d);
	}
	
	// State controller
	if (((time()) == 4) ) {
		velAdd_data d;
		d.y = -4.5;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 4) && ((vel().y) > 0) ) {
		velMul_data d;
		d.y = 0.5;
		velMul(d);
	}
	
	// State controller
	if (((time()) == 4) && ((vel().y) > -3) ) {
		velAdd_data d;
		d.y = -2;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 4) && ((vel().y) > -2) ) {
		velAdd_data d;
		d.y = -1;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 4) && (command("holdup")) ) {
		velAdd_data d;
		d.y = -2;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 4) && (command("holddown")) ) {
		velAdd_data d;
		d.y = 1.5;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 4) && (command("holdfwd")) ) {
		velMul_data d;
		d.x = 1;
		velMul(d);
	}
	
	// State controller
	if (((time()) == 4) && (command("holdback")) ) {
		velAdd_data d;
		d.x = -1;
		velAdd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 15;
		notHitBy(d);
	}
	
	// State controller
	if (((time()) == 20) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((time()) >= 4) ) {
		velAdd_data d;
		d.y = 0.35;
		velAdd(d);
	}
	
	// State controller
	if (((vel().y) > 0) && ((pos().y) >= 0) ) {
		changeState_data d;
		d.value = 52;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_5500()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.anim = 5300;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) && (selfAnimExist(5500)) ) {
		changeAnim_data d;
		d.value = 5500;
		changeAnim(d);
	}
}

void Cloudi::state_5888()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'L';
		params.moveType = 'I';
		params.physics = 'N';
		params.anim = 5120;
		params.velSet = {0, 0};
		params.ctrl = 0;
		params.powerAdd = 0;
		params.juggle = 0;
		params.faceP2 = 1;
		params.hitDefPersist = 0;
		params.moveHitPersist = 0;
		params.hitCountPersist = 0;
		params.sprPriority = 0;
		setStateParams(params);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		notHitBy(d);
	}
	
	// State controller
	if (1 ) {
		playerPush_data d;
		d.value = 0;
		playerPush(d);
	}
	
	// State controller
	if (!(time()) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if ((!(time()) && (command("holdfwd"))) ) {
		velSet_data d;
		d.x = 4.5;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if ((!(time()) && (command("holdback"))) ) {
		velSet_data d;
		d.x = -4.5;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"F", 125}, 50};
		playSnd(d);
	}
	
	// State controller
	if ((((time()) == 1) && ((vel().x) > 0)) ) {
		changeAnim_data d;
		d.value = 111;
		changeAnim(d);
	}
	
	// State controller
	if ((((time()) == 1) && ((vel().x) < 0)) ) {
		changeAnim_data d;
		d.value = 110;
		changeAnim(d);
	}
	
	// State controller
	if (1 ) {
		explod_data d;
		d.persistent = 14;
		d.ignoreHitPause = 0;
		d.anim = {"F", 1201};
		d.id = 31402;
		d.pos = {1, -5};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.2, 0.2};
		d.facing = (ifElse(((vel().x) > 0), 1, -1));
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (1 ) {
		explod_data d;
		d.persistent = 7;
		d.ignoreHitPause = 0;
		d.anim = {"F", 1201};
		d.id = 31402;
		d.pos = {1, 1};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.1, 0.1};
		d.facing = (ifElse(((vel().x) > 0), 1, -1));
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((((time()) > 20) && (command("holdfwd") == 0)) || (((time()) > 30) && (command("holdfwd")))) || ((((time()) > 20) && (command("holdback") == 0)) || (((time()) > 30) && (command("holdback")))) || ((vel().x) == 0) ) {
		changeState_data d;
		d.value = 5120;
		changeState(d);
	}
}

void Cloudi::state_5900()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((roundsExisted()) == 0) ) {
		varRangeSet_data d;
		d.value = 0;
		d.first = 0;
		d.last = 57;
		varRangeSet(d);
	}
	
	// State controller
	if (1 ) {
		varSet_data d;
		d.v = 58;
		d.value = 1000;
		varSet(d);
	}
	
	// State controller
	if (((roundsExisted()) == 0) ) {
		varRangeSet_data d;
		d.fvalue = 0;
		varRangeSet(d);
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 1) ) {
		if (((teamMode() == "Single") || (teamMode() == "Turns")) || (teamMode() == "Simul") && ((id()) < (getPartner().id())) ) {
			varSet_data d;
			d.v = 40;
			d.value = (id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		if (((teamSide()) == 1) ) {
			varSet_data d;
			d.v = 41;
			d.value = (getEnemyNear().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 1) ) {
		if ((teamMode() == "Simul") && ((id()) < (getPartner().id())) ) {
			varSet_data d;
			d.v = 42;
			d.value = (getPartner().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 1) ) {
		if ((getEnemyNear().teamMode() == "Simul") ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "GrabIDHelper";
			d.id = 90000;
			d.pos = {0, 0};
			d.posType = "right";
			d.stateNo = 90000;
			d.keyCtrl = 0;
			helper(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		if (((teamSide()) == 2) ) {
			varSet_data d;
			d.v = 40;
			d.value = (getEnemyNear().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 2) ) {
		if (((teamMode() == "Single") || (teamMode() == "Turns")) || (teamMode() == "Simul") && ((id()) < (getPartner().id())) ) {
			varSet_data d;
			d.v = 41;
			d.value = (id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 2) ) {
		if ((getEnemyNear().teamMode() == "Simul") ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "GrabIDHelper";
			d.id = 90000;
			d.pos = {0, 0};
			d.posType = "left";
			d.stateNo = 90000;
			d.keyCtrl = 0;
			helper(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 2) ) {
		if ((teamMode() == "Simul") && ((id()) < (getPartner().id())) ) {
			varSet_data d;
			d.v = 43;
			d.value = (getPartner().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 1) ) {
		if ((teamMode() == "Simul") && ((id()) > (getPartner().id())) ) {
			varSet_data d;
			d.v = 40;
			d.value = (getPartner().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 1) ) {
		if ((teamMode() == "Simul") && ((id()) > (getPartner().id())) ) {
			varSet_data d;
			d.v = 42;
			d.value = (id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 2) ) {
		if ((teamMode() == "Simul") && ((id()) > (getPartner().id())) ) {
			varSet_data d;
			d.v = 41;
			d.value = (getPartner().id());
			varSet(d);
		}
	}
	
	// State controller
	if (((time()) == 0) && ((teamSide()) == 2) ) {
		if ((teamMode() == "Simul") && ((id()) > (getPartner().id())) ) {
			varSet_data d;
			d.v = 43;
			d.value = (id());
			varSet(d);
		}
	}
	
	// State controller
	if (((roundNo()) == 1) ) {
		changeState_data d;
		d.value = 190;
		changeState(d);
	}
}

void Cloudi::state_9000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'U';
		params.moveType = 'H';
		params.physics = 'U';
		params.anim = (ifElse(((pos().y) <= 0), 5010, 5030));
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (!(time()) ) {
		explod_data d;
		d.anim = {"F", 94};
		d.id = 9002;
		d.pos = {0, -30};
		d.posType = "p1";
		d.facing = (ifElse(((facing()) == 1), 1, -1));
		d.sprPriority = 12;
		d.onTop = 1;
		d.ownPal = 1;
		d.removeOnGetHit = 0;
		d.pauseMoveTime = 99999;
		d.superMoveTime = 99999;
		d.bindTime = 1;
		explod(d);
	}
	
	// State controller
	if ((!(time()) && ((numHelper(30000)) != 0)) ) {
		explod_data d;
		d.anim = {"F", 310};
		d.id = 9002;
		d.pos = {(ifElse(((teamSide()) == 1), 4, 315)), 223};
		d.posType = "left";
		d.bindTime = -1;
		d.scale = {0.7, 0.7};
		d.sprPriority = 5;
		d.onTop = 1;
		d.ownPal = 1;
		d.superMoveTime = 99999999;
		d.pauseMoveTime = 99999999;
		d.facing = (ifElse(((teamSide()) == 1), 1, -1));
		explod(d);
	}
	
	// State controller
	if (!(time()) ) {
		explod_data d;
		d.anim = {"F", 310};
		d.id = 9002;
		d.pos = {(ifElse(((teamSide()) == 1), 60, 259)), 9};
		d.posType = "left";
		d.bindTime = -1;
		d.scale = {1.4, 0.4};
		d.sprPriority = 5;
		d.onTop = 1;
		d.ownPal = 1;
		d.superMoveTime = 99999999;
		d.pauseMoveTime = 99999999;
		d.facing = (ifElse(((teamSide()) == 1), 1, -1));
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		playSnd_data d;
		d.value = {{"F", 120}, 10};
		playSnd(d);
	}
	
	// State controller
	if (!(time()) ) {
		bgPalFX_data d;
		d.ignoreHitPause = 1;
		d.time = 6;
		d.add = {255, 0, 0};
		d.mul = {256, 256, 256};
		d.sinAdd = {255, 0, 0, 10};
		d.invertAll = 0;
		d.color = 256;
		bgPalFX(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		superPause_data d;
		d.time = 10;
		d.anim = 310;
		d.sound = {{"S", 25}, 7};
		d.pos = {-10, -30};
		d.darken = 1;
		d.p2DefMul = 0;
		d.powerAdd = 0;
		d.unHittable = 1;
		superPause(d);
	}
	
	// State controller
	if (!(time()) ) {
		varSet_data d;
		d.fv = 14;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if (((time()) < 10) ) {
		notHitBy_data d;
		d.value = "SCA";
		notHitBy(d);
	}
	
	// State controller
	if ((!(time()) && ((pos().y) <= 0)) ) {
		stateTypeSet_data d;
		d.physics = "S";
		stateTypeSet(d);
	}
	
	// State controller
	if ((!(time()) && ((pos().y) <= 0)) ) {
		velSet_data d;
		d.x = -2;
		velSet(d);
	}
	
	// State controller
	if ((((time()) == 85) && (stateType() != "A")) ) {
		changeState_data d;
		d.value = 5050;
		d.ctrl = 0;
		changeState(d);
	}
	
	// State controller
	if ((((time()) == 15) && (stateType() == "A")) ) {
		changeState_data d;
		d.value = 5050;
		d.ctrl = 0;
		changeState(d);
	}
	
	// State controller
	if (!(time()) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "guardbreak";
		d.id = 9001;
		d.stateNo = 9001;
		d.pos = {0, -2000};
		d.posType = "p1";
		d.facing = 1;
		d.keyCtrl = 0;
		d.ownPal = 0;
		helper(d);
	}
}

void Cloudi::state_90000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		parentVarSet_data d;
		d.v = (ifElse(((teamSide()) == 1), 43, 42));
		d.value = (getEnemyNear().id());
		parentVarSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		destroySelf_data d;
		destroySelf(d);
	}
}

void Cloudi::state_9001()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 99999;
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 100) ) {
		destroySelf_data d;
		destroySelf(d);
	}
}

void Cloudi::state_9005()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.moveType = 'I';
		params.stateType = 'U';
		params.physics = 'U';
		params.ctrl = 1;
		setStateParams(params);
	}
	
	// State controller
	if (!(time()) ) {
		envShake_data d;
		d.time = 4;
		d.freq = 60;
		d.ampl = -4;
		d.phase = 90;
		envShake(d);
	}
	
	// State controller
	if ((!(time()) && ((pos().y) <= 0)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = {"F", 1201};
		d.id = 9005;
		d.pos = {((ifElse(((random()) > 499), -21, (ifElse(((random()) > 499), -27, (ifElse(((random()) > 499), -15, -12)))))) - 5), -13};
		d.posType = "p1";
		d.bindTime = -1;
		d.scale = {0.3, 0.3};
		d.facing = 1;
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		superPause_data d;
		d.time = 10;
		d.sound = {{"F", 90}, 120};
		d.pos = {10, -25};
		d.anim = 315;
		d.darken = 1;
		d.p2DefMul = 0;
		d.powerAdd = 0;
		d.unHittable = 1;
		superPause(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = {"SCA", "NA", "SA", "HA", "NP", "SP", "HP", "NT", "ST", "HT"};
		d.time = 1;
		notHitBy(d);
	}
	
	// State controller
	if (!(time()) ) {
		varAdd_data d;
		d.fv = 14;
		d.value = -1.5;
		varAdd(d);
	}
	
	// State controller
	if (1 ) {
		changeAnim_data d;
		d.value = (anim());
		d.elem = (animElemNo(0));
		changeAnim(d);
	}
	
	// State controller
	if (((time()) == 11) ) {
		changeState_data d;
		d.value = (prevStateNo());
		d.ctrl = 0;
		changeState(d);
	}
}

