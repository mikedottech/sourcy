/*
   cloudi.cpp
   Generated from cloudi.cns
   on 2026-05-13.

   by Sourcy Code Translator
   (c) 2017 - radexx

   Runtime version: 1.0

*/

#include "../cns/Cloudi_master.h"

void Cloudi::state_1000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		params.ctrl = 0;
		params.anim = 1000;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) > 26) ) {
		explod_data d;
		d.persistent = 12;
		d.anim = 425;
		d.id = 2323;
		d.pos = {(ifElse(((random()) > 499), -20, -30)), -13};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.28, 0.28};
		explod(d);
	}
	
	// State controller
	if (((time()) > 26) ) {
		explod_data d;
		d.persistent = 12;
		d.anim = 425;
		d.id = 2323;
		d.pos = {(ifElse(((random()) > 499), -20, -30)), -13};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.18, 0.18};
		explod(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 0};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.anim = 8777;
		d.id = 1011;
		d.pos = {100, -45};
		d.posType = "p1";
		d.facing = 1;
		d.vFacing = 1;
		d.bindTime = 1;
		d.scale = {0.8, 0.8};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		helper_data d;
		d.persistent = 1;
		d.helperType = "normal";
		d.name = "bladebeam";
		d.id = 1000;
		d.stateNo = 1001;
		d.pos = {25, 0};
		d.posType = "p1";
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 17}, 5};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		sprPriority_data d;
		d.value = -1;
		sprPriority(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {0, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-10, -20};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = 0;
		d.air_velocity = {0, 3};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_1001()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 8779;
		setStateParams(params);
	}
	
	// State controller
	if ((isHelper()) ) {
		if ((((getRoot().stateNo()) == 50000) || ((getRoot().stateNo()) == 40000)) ) {
			destroySelf_data d;
			destroySelf(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		velSet_data d;
		d.x = 0;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 1};
		playSnd(d);
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
		d.x = 6;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 25) ) {
		velSet_data d;
		d.x = 9;
		velSet(d);
	}
	
	// State controller
	if (1 ) {
		assertSpecial_data d;
		d.flag = "noshadow";
		assertSpecial(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		explod_data d;
		d.anim = 8778;
		d.id = 1011;
		d.pos = {-30, -28};
		d.posType = "p1";
		d.facing = 1;
		d.vFacing = 1;
		d.bindTime = -1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 50;
		d.guardFlag = "MA";
		d.pauseTime = {0, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = 0;
		d.sparkXY = {-10, -25};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = 0;
		d.air_velocity = {0, -4};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		destroySelf_data d;
		destroySelf(d);
	}
}

void Cloudi::state_1010()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.ctrl = 0;
		params.anim = 1010;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 1) ) {
		velSet_data d;
		d.x = -2;
		d.y = -3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		explod_data d;
		d.anim = 8777;
		d.id = 1011;
		d.pos = {55, -45};
		d.posType = "p1";
		d.facing = 1;
		d.vFacing = 1;
		d.bindTime = 1;
		d.scale = {0.6, 0.6};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		explod_data d;
		d.anim = 8777;
		d.id = 1011;
		d.pos = {-45, 35};
		d.posType = "p1";
		d.facing = -1;
		d.vFacing = -1;
		d.bindTime = 1;
		d.scale = {0.6, 0.6};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		helper_data d;
		d.persistent = 1;
		d.helperType = "normal";
		d.name = "bladebeam";
		d.id = 1112;
		d.stateNo = 1011;
		d.pos = {-42, -15};
		d.posType = "p1";
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 12}, 0};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 3};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		sprPriority_data d;
		d.value = -1;
		sprPriority(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {10, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-10, -20};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = 0;
		d.air_velocity = {0, -1};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_1011()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 8780;
		setStateParams(params);
	}
	
	// State controller
	if ((isHelper()) ) {
		if ((((getRoot().stateNo()) == 50000) || ((getRoot().stateNo()) == 40000)) ) {
			destroySelf_data d;
			destroySelf(d);
		}
	}
	
	// State controller
	if ((animElem(2)) ) {
		stateTypeSet_data d;
		d.physics = "A";
		stateTypeSet(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		stateTypeSet_data d;
		d.physics = "N";
		stateTypeSet(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		explod_data d;
		d.anim = 8781;
		d.id = 1016;
		d.pos = {0, -45};
		d.posType = "p1";
		d.facing = 1;
		d.vFacing = 1;
		d.removeTime = -1;
		d.bindTime = -1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (1 ) {
		assertSpecial_data d;
		d.flag = "noshadow";
		assertSpecial(d);
	}
	
	// State controller
	if (1 ) {
		velSet_data d;
		d.x = 4;
		d.y = 4;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 50;
		d.guardFlag = "MA";
		d.pauseTime = {0, 10};
		d.hitSound = {{"S", 20}, 0};
		d.guardSound = {6, 0};
		d.sparkXY = {-10, -20};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = 0;
		d.air_velocity = {0, -4};
		hitDef(d);
	}
}

void Cloudi::state_1013()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		setStateParams(params);
	}
	
	// State controller
	if ((isHelper()) ) {
		if ((((getRoot().stateNo()) == 50000) || ((getRoot().stateNo()) == 40000)) ) {
			destroySelf_data d;
			destroySelf(d);
		}
	}
	
	// State controller
	if (((time()) == 0) ) {
		posAdd_data d;
		d.x = -20;
		d.y = 10;
		posAdd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posAdd_data d;
		d.x = -20;
		d.y = 65;
		posAdd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 50;
		d.guardFlag = "MA";
		d.pauseTime = {0, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 1, 0))};
		d.guardSound = {6, 0};
		d.sparkXY = {-10, -20};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = 0;
		d.air_velocity = {0, -4};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		destroySelf_data d;
		destroySelf(d);
	}
}

void Cloudi::state_180()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		changeState_data d;
		d.value = 181;
		changeState(d);
	}
}

void Cloudi::state_181()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.anim = 180;
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "windata";
		d.id = 10000;
		d.stateNo = 10000;
		d.pos = {0, 0};
		d.posType = "left";
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if ((((time()) == 1) && ((random()) > 499)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(40)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 0};
		playSnd(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = "SCA";
		d.time = 1;
		notHitBy(d);
	}
}

void Cloudi::state_195()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.ctrl = 0;
		params.anim = 195;
		params.velSet = {0, 0};
		params.moveType = 'I';
		params.physics = 'S';
		params.sprPriority = 2;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 2}, 2};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 2};
		playSnd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_200()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 200;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8906;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8907;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(9)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 5};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 2, 3))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 8};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9112};
		d.sparkXY = {-20, -30};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = -1;
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_2000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 2000;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(3)) ) {
		velSet_data d;
		d.y = -11;
		velSet(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 101}, 0};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 10) ) {
		changeState_data d;
		d.value = 2001;
		d.ctrl = 0;
		changeState(d);
	}
}

void Cloudi::state_2001()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.ctrl = 0;
		params.velSet = {0, -8};
		params.anim = 2001;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 15}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((animElem(3)) || (animElem(4))) || (((animElem(5)) || (animElem(6))) || (animElem(7))) ) {
		velSet_data d;
		d.y = -2;
		velSet(d);
	}
	
	// State controller
	if (((time()) >= 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {0, 2};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9113};
		d.sparkXY = {-40, 10};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-2, 3};
		d.air_velocity = {-2, 3};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.y = 13;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) && ((prevStateNo()) == 2000) ) {
		velSet_data d;
		d.x = 7;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) && ((prevStateNo()) != 2000) ) {
		velSet_data d;
		d.x = 4;
		velSet(d);
	}
}

void Cloudi::state_2002()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		params.ctrl = 0;
		params.velSet = {0, 0};
		params.anim = 2002;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 14}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		explod_data d;
		d.anim = 6501;
		d.id = 1213;
		d.pos = {20, -30};
		d.posType = "p1";
		d.scale = {0.6, 0.6};
		d.sprPriority = 5;
		explod(d);
	}
	
	// State controller
	if (((time()) >= 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 10;
		d.guardFlag = "MA";
		d.pauseTime = {0, 0};
		d.hitSound = {{"S", 21}, 1};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9113};
		d.sparkXY = {-40, 10};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-1, -2};
		d.air_velocity = {-1, -2};
		d.fall = 1;
		hitDef(d);
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
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_201()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 201;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 4};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 3, 4))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8901;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "SA"};
		d.damage = {60, 10};
		d.animType = "Heavy";
		d.guardFlag = "MA";
		d.priority = {4, "Hit"};
		d.pauseTime = {6, 8};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-20, -30};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.ground_type = "High";
		d.ground_slideTime = 6;
		d.ground_hitTime = 14;
		d.ground_velocity = {-1, -8};
		d.airGuard_velocity = {-1.9, -.8};
		d.air_type = "High";
		d.air_velocity = {-1.4, -5};
		d.air_hitTime = 12;
		d.ground_cornerPush_veloff = -8;
		d.air_cornerPush_veloff = 0;
		d.airGuard_cornerPush_velOff = 0;
		d.fall = 1;
		d.guard_pauseTime = {3, 5};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		velSet_data d;
		d.ignoreHitPause = 1;
		d.x = 4;
		velSet(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		velSet_data d;
		d.ignoreHitPause = 1;
		d.x = 1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		velSet_data d;
		d.ignoreHitPause = 1;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_202()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 202;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8902;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 5;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.x = 1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 4, 6))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 8};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9112};
		d.sparkXY = {-20, -30};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = -2;
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_203()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 203;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8904;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8905;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		velSet_data d;
		d.x = 6;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 6, 7))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {5, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-20, -30};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -5};
		d.air_velocity = {-2, -3};
		d.fall = 1;
		d.fall_recover = 0;
		hitDef(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "";
		d.pauseTime = {5, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.numhits = 1;
		d.sparkNo = {"S", 9113};
		d.sparkXY = {-45, -21};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-3, 14};
		d.air_velocity = {-2, 1};
		d.fall = 1;
		hitDef(d);
	}
	
	// State controller
	if ((animElem(13)) ) {
		posAdd_data d;
		d.x = 14;
		posAdd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_204()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 203;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 30) ) {
		explod_data d;
		d.persistent = 12;
		d.anim = 425;
		d.id = 2323;
		d.facing = -1;
		d.pos = {70, -13};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.28, 0.28};
		explod(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8904;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8905;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		velSet_data d;
		d.x = 6;
		velSet(d);
	}
	
	// State controller
	if ((animElem(11)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 3};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 5, 4))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {5, 2};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-20, -30};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -5};
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "";
		d.pauseTime = {5, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.numhits = 1;
		d.sparkNo = {"S", 9113};
		d.sparkXY = {-45, -21};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-3, 14};
		d.air_velocity = {-2, 14};
		d.fall = 1;
		hitDef(d);
	}
	
	// State controller
	if ((animElem(13)) ) {
		posAdd_data d;
		d.x = 14;
		posAdd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_206()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 204;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8903;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		playSnd_data d;
		d.value = {{"S", 40}, 2};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 2, 4))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 8};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9116};
		d.sparkXY = {-30, -30};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = -3;
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		posAdd_data d;
		d.x = 10;
		posAdd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_300()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 300;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 15}, 0};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 301;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 0};
		playSnd(d);
	}
}

void Cloudi::state_301()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 302;
		setStateParams(params);
	}
	
	// State controller
	if (((((animElem(2)) || (animElem(10))) || (animElem(18))) || (animElem(26))) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		explod_data d;
		d.anim = 9105;
		d.id = 2323;
		d.pos = {18, -35};
		d.bindTime = -1;
		d.scale = {0.9, 0.9};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		velSet_data d;
		d.x = 1;
		d.y = -1.5;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		posAdd_data d;
		d.x = 12;
		d.y = -30;
		posAdd(d);
	}
	
	// State controller
	if (((time()) >= 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 20;
		d.guardFlag = "MA";
		d.pauseTime = {0, 0};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9117};
		d.sparkXY = {-20, -30};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-1, -4};
		d.air_velocity = {-1, -4};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(22)) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 302;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_302()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.velSet = {0, 0};
		params.ctrl = 1;
		params.anim = 303;
		setStateParams(params);
	}
}

void Cloudi::state_305()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.ctrl = 0;
		params.velSet = {-1, -3};
		params.anim = 304;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 15}, 0};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 306;
		changeState(d);
	}
}

void Cloudi::state_306()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.ctrl = 0;
		params.anim = 302;
		setStateParams(params);
	}
	
	// State controller
	if (((((animElem(2)) || (animElem(10))) || (animElem(18))) || (animElem(26))) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 1) ) {
		velSet_data d;
		d.x = 5;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		explod_data d;
		d.anim = 9105;
		d.id = 2323;
		d.pos = {18, -35};
		d.bindTime = -1;
		d.scale = {0.9, 0.9};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) >= 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 18;
		d.guardFlag = "MA";
		d.pauseTime = {0, 0};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9117};
		d.sparkXY = {-20, -30};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {-3, -2};
		d.air_velocity = {-3, -2};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 307;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if ((animElem(22)) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_307()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.velSet = {0, 0};
		params.ctrl = 1;
		params.anim = 303;
		setStateParams(params);
	}
}

void Cloudi::state_400()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 400;
		params.ctrl = 0;
		params.stateType = 'C';
		params.moveType = 'A';
		params.physics = 'C';
		params.faceP2 = 1;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(3)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8902;
		d.id = 101;
		d.pos = {6, 17};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		d.volume = 0;
		d.channel = -1;
		d.freqMul = 1;
		d.loop = 0;
		d.pan = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		varRandom_data d;
		d.v = 3;
		d.range = {0, 1};
		varRandom(d);
	}
	
	// State controller
	if (((var(3)) == 1) && (animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 2};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"C", "NA"};
		d.damage = 30;
		d.guardFlag = "A";
		d.pauseTime = {8, 6};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9112};
		d.sparkXY = {-20, -14};
		d.animType = "medium";
		d.ground_type = "low";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = -1;
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) && (command("holddown")) ) {
		changeState_data d;
		d.value = 11;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_410()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 410;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 5;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(9)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 3};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 2, 3))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.anim = 426;
		d.id = 426;
		d.pos = {0, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -10};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.2, 0.2};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 420;
		d.id = 410;
		d.pos = {30, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 420;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9110};
		d.sparkXY = {40, -60};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-1, -2};
		d.air_velocity = {-1, -2};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		varSet_data d;
		d.v = 11;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if ((((((command("holdback")) && (command("y"))) && ((time()) > 1)) && ((time()) <= 18)) && ((var(11)) == 0)) ) {
		varSet_data d;
		d.v = 11;
		d.value = 3;
		varSet(d);
	}
	
	// State controller
	if (((((command("holdback")) && (command("y"))) && ((time()) > 18)) && ((var(11)) == 0)) ) {
		varSet_data d;
		d.v = 11;
		d.value = 1;
		varSet(d);
	}
	
	// State controller
	if ((((time()) > 21) && ((var(11)) == 1)) ) {
		changeState_data d;
		d.value = 411;
		changeState(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_411()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 411;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {240, 50, 0};
		d.mul = {250, 224, 120};
		d.sinAdd = {110, 55, 85, 10};
		d.invertAll = 0;
		d.color = 0;
		palFX(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		velSet_data d;
		d.x = 6;
		velSet(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 2};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		explod_data d;
		d.anim = 427;
		d.id = 427;
		d.pos = {-10, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -15};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.25, 0.25};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 4, 5))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((animElem(5)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 421;
		d.id = 410;
		d.pos = {10, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(5)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 421;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9110};
		d.sparkXY = {40, -60};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-.4, -4};
		d.air_velocity = {-.4, -4};
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		varSet_data d;
		d.v = 11;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if ((((((command("holdback")) && (command("y"))) && ((time()) > 1)) && ((time()) <= 17)) && ((var(11)) == 0)) ) {
		varSet_data d;
		d.v = 11;
		d.value = 3;
		varSet(d);
	}
	
	// State controller
	if ((((command("holdback")) && (command("y"))) && ((time()) > 17)) ) {
		varSet_data d;
		d.v = 11;
		d.value = 1;
		varSet(d);
	}
	
	// State controller
	if ((((time()) > 20) && ((var(11)) == 1)) ) {
		changeState_data d;
		d.value = 412;
		changeState(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_412()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 412;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {240, 50, 0};
		d.mul = {250, 224, 120};
		d.sinAdd = {110, 55, 85, 10};
		d.invertAll = 0;
		d.color = 0;
		palFX(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 8;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 5) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 3};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 31) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 11}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 428;
		d.id = 428;
		d.pos = {-10, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -15};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.3, 0.3};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 422;
		d.id = 410;
		d.pos = {10, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 422;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if ((moveHit()) ) {
		bgPalFX_data d;
		d.persistent = 22;
		d.time = 5;
		d.add = {255, 255, 255};
		d.mul = {256, 256, 256};
		d.sinAdd = {255, 255, 255, 10};
		bgPalFX(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 12};
		d.hitSound = {{"S", 21}, 1};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9110};
		d.sparkXY = {40, -60};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-.3, -7};
		d.air_velocity = {-.3, -7};
		d.fall = 1;
		d.fall_envShake_phase = 888;
		hitDef(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_420()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 410;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 5;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(9)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 3};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 2, 3))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.anim = 426;
		d.id = 426;
		d.pos = {0, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -10};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.2, 0.2};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 420;
		d.id = 410;
		d.pos = {30, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 420;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkXY = {-10, -25};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-1, -2};
		d.air_velocity = {-1, -2};
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		varSet_data d;
		d.v = 11;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if ((moveHit()) ) {
		varSet_data d;
		d.v = 11;
		d.value = 1;
		varSet(d);
	}
	
	// State controller
	if ((((time()) > 21) && ((var(11)) == 1)) ) {
		changeState_data d;
		d.value = 421;
		changeState(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_421()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 411;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {240, 50, 0};
		d.mul = {250, 224, 120};
		d.sinAdd = {110, 55, 85, 10};
		d.invertAll = 0;
		d.color = 0;
		palFX(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		velSet_data d;
		d.x = 6;
		velSet(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 2};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(4)) ) {
		explod_data d;
		d.anim = 427;
		d.id = 427;
		d.pos = {-10, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -15};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.25, 0.25};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) >= 499), 4, 5))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((animElem(5)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 421;
		d.id = 410;
		d.pos = {10, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(5)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 421;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 10};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkXY = {-10, -25};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-.4, -4};
		d.air_velocity = {-.4, -4};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		changeState_data d;
		d.value = 422;
		changeState(d);
	}
}

void Cloudi::state_422()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 412;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		palFX_data d;
		d.time = 3;
		d.add = {240, 50, 0};
		d.mul = {250, 224, 120};
		d.sinAdd = {110, 55, 85, 10};
		d.invertAll = 0;
		d.color = 0;
		palFX(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 8;
		velSet(d);
	}
	
	// State controller
	if ((animElem(8)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 5) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 3};
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 31) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 11}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 428;
		d.id = 428;
		d.pos = {-10, 0};
		d.posType = "p1";
		d.bindTime = -1;
		d.sprPriority = 5;
		d.facing = -1;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		explod_data d;
		d.anim = 425;
		d.id = 425;
		d.pos = {-30, -15};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.3, 0.3};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == 1)) ) {
		explod_data d;
		d.anim = 422;
		d.id = 410;
		d.pos = {10, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = 1;
		explod(d);
	}
	
	// State controller
	if (((animElem(6)) && ((facing()) == -1)) ) {
		explod_data d;
		d.anim = 422;
		d.id = 410;
		d.pos = {90, -30};
		d.posType = "p1";
		d.bindTime = 1;
		d.scale = {0.5, 0.5};
		d.sprPriority = 5;
		d.ownPal = 1;
		d.removeOnGetHit = 1;
		d.facing = -1;
		explod(d);
	}
	
	// State controller
	if ((moveHit()) ) {
		bgPalFX_data d;
		d.persistent = 22;
		d.time = 5;
		d.add = {255, 255, 255};
		d.mul = {256, 256, 256};
		d.sinAdd = {255, 255, 255, 10};
		bgPalFX(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 12};
		d.hitSound = {{"S", 21}, 1};
		d.guardSound = {6, 0};
		d.sparkXY = {-10, -25};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 14;
		d.ground_velocity = {-.3, -7};
		d.air_velocity = {-.3, -7};
		d.fall = 1;
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		posAdd_data d;
		d.x = -7;
		posAdd(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_500()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		params.ctrl = 0;
		params.anim = 500;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 12) ) {
		explod_data d;
		d.anim = 425;
		d.id = 2323;
		d.pos = {0, -15};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.28, 0.28};
		explod(d);
	}
	
	// State controller
	if (((time()) == 12) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 2323;
		d.pos = {0, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if (((time()) == 15) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 23236;
		d.pos = {0, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if (((time()) == 21) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 23236;
		d.pos = {0, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 16}, 0};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		velSet_data d;
		d.x = 17;
		velSet(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		afterImage_data d;
		d.time = 7;
		d.length = 9;
		d.palBright = {10, 10, 10};
		d.palContrast = {120, 120, 120};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 1;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 80;
		d.guardFlag = "MA";
		d.pauseTime = {0, 29};
		d.guard_pauseTime = {0, 5};
		d.hitSound = {0, 0};
		d.guardSound = {6, 0};
		d.sparkNo = 6600;
		d.sparkXY = {-20, -5};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -4};
		d.air_velocity = {0, -4};
		d.fall = 1;
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 40) && (moveHit()) ) {
		explod_data d;
		d.anim = 9110;
		d.id = 232336;
		d.pos = {-40, -60};
		d.posType = "p2";
		d.sprPriority = 5;
		d.scale = {0.8, 0.8};
		explod(d);
	}
	
	// State controller
	if (((time()) == 40) && (moveHit()) ) {
		playSnd_data d;
		d.value = {{"S", 100}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((((time()) > 13) && ((time()) < 23)) ) {
		playerPush_data d;
		d.value = 0;
		playerPush(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_50000()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.moveType = 'I';
		params.physics = 'N';
		params.velSet = {0, 0};
		params.sprPriority = -1;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 0) ) {
		posSet_data d;
		d.y = 0;
		posSet(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		removeExplod_data d;
		d.id = -1;
		removeExplod(d);
	}
	
	// State controller
	if (1 ) {
		playerPush_data d;
		d.value = 0;
		playerPush(d);
	}
	
	// State controller
	if (1 ) {
		notHitBy_data d;
		d.value = {"SCA", "NA", "SA", "HA", "NP", "SP", "HP", "NT", "ST", "HT"};
		d.time = 1;
		notHitBy(d);
	}
	
	// State controller
	if (1 ) {
		assertSpecial_data d;
		d.flag = "invisible";
		assertSpecial(d);
	}
	
	// State controller
	if (((id()) != (var(40))) && ((getPlayerID((var(40))).stateNo()) == 45000) || ((id()) != (var(41))) && ((getPlayerID((var(41))).stateNo()) == 45000) || ((id()) != (var(42))) && ((getPlayerID((var(42))).stateNo()) == 45000) || ((id()) != (var(43))) && ((getPlayerID((var(43))).stateNo()) == 45000) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_510()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {-3, 0};
		params.ctrl = 0;
		params.anim = 510;
		setStateParams(params);
	}
	
	// State controller
	if ((((time()) > 13) && ((time()) < 23)) ) {
		playerPush_data d;
		d.value = 0;
		playerPush(d);
	}
	
	// State controller
	if (((time()) == 17) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 2323;
		d.pos = {10, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if (((time()) == 20) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 23236;
		d.pos = {10, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if (((time()) == 24) ) {
		explod_data d;
		d.anim = 6600;
		d.id = 23236;
		d.pos = {10, -20};
		d.posType = "p1";
		d.sprPriority = 5;
		d.scale = {0.7, 0.6};
		explod(d);
	}
	
	// State controller
	if ((animElem(1)) ) {
		playSnd_data d;
		d.value = {{"S", 16}, 0};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		velSet_data d;
		d.x = 17;
		velSet(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		velSet_data d;
		d.x = 3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 2;
		velSet(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		afterImage_data d;
		d.time = 7;
		d.length = 9;
		d.palBright = {10, 10, 10};
		d.palContrast = {120, 120, 120};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 1;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 80;
		d.guardFlag = "MA";
		d.pauseTime = {0, 5};
		d.guardSound = {6, 0};
		d.hitSound = {{"S", 100}, 1};
		d.sparkNo = {"S", 9100};
		d.sparkXY = {30, -60};
		d.animType = "hard";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -4};
		d.air_velocity = {0, -4};
		d.fall = 1;
		hitDef(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		stateTypeSet_data d;
		d.physics = "A";
		d.stateType = "A";
		stateTypeSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if ((((animTime()) == 0) && ((p2Dist().x) < 0)) ) {
		turn_data d;
		turn(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeAnim_data d;
		d.value = 45;
		d.elem = 3;
		changeAnim(d);
	}
}

void Cloudi::state_600()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.juggle = 2;
		params.powerAdd = 11;
		params.ctrl = 0;
		params.anim = 600;
		setStateParams(params);
	}
	
	// State controller
	if (((animElem(1)) && ((prevStateNo()) == 201)) ) {
		velSet_data d;
		d.x = 1;
		d.y = -9;
		velSet(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8908;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8909;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		d.volume = 0;
		d.channel = -1;
		d.freqMul = 1;
		d.loop = 0;
		d.pan = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		varRandom_data d;
		d.v = 3;
		d.range = {0, 1};
		varRandom(d);
	}
	
	// State controller
	if (((var(3)) == 1) && (animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 2};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {10, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-20, -30};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -3};
		d.air_velocity = {0, -2};
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 20) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_601()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.juggle = 2;
		params.velSet = {0, -2};
		params.powerAdd = 11;
		params.ctrl = 0;
		params.anim = 601;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(5)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8905;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		d.volume = 0;
		d.channel = -1;
		d.freqMul = 1;
		d.loop = 0;
		d.pan = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(5)) ) {
		velSet_data d;
		d.x = 0;
		d.y = -4;
		velSet(d);
	}
	
	// State controller
	if (((animElem(2)) && ((prevStateNo()) < 200)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 4};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((animElem(2)) && ((prevStateNo()) > 200)) ) {
		playSnd_data d;
		d.value = {{"S", 15}, 1};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {10, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9113};
		d.sparkXY = {-45, -21};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, 21};
		d.air_velocity = {0, 21};
		d.fall = 4;
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 40) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_602()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'A';
		params.juggle = 2;
		params.powerAdd = 11;
		params.ctrl = 0;
		params.anim = 602;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(3)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8910;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8911;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		d.volume = 0;
		d.channel = -1;
		d.freqMul = 1;
		d.loop = 0;
		d.pan = 0;
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		varRandom_data d;
		d.v = 3;
		d.range = {0, 1};
		varRandom(d);
	}
	
	// State controller
	if (((var(3)) == 1) && (animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 2};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) >= 0) ) {
		hitDef_data d;
		d.persistent = 5;
		d.attr = {"S", "NA"};
		d.damage = 10;
		d.guardFlag = "MA";
		d.pauseTime = {10, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", (ifElse(((random()) > 499), 9112, 9115))};
		d.sparkXY = {-20, -30};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -4};
		d.air_velocity = {0, -4};
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 20) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_603()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'A';
		params.moveType = 'A';
		params.physics = 'N';
		params.juggle = 2;
		params.velSet = {((vel().x) / 2), -2};
		params.powerAdd = 11;
		params.ctrl = 0;
		params.anim = 603;
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(6)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8914;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if (((time()) == 3) ) {
		velSet_data d;
		d.x = ((vel().x) / 2);
		d.y = -1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) ) {
		velSet_data d;
		d.x = 4;
		d.y = -9;
		velSet(d);
	}
	
	// State controller
	if ((animElem(9)) ) {
		velSet_data d;
		d.x = 2;
		d.y = -3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		velSet_data d;
		d.x = 0.5;
		d.y = -1;
		velSet(d);
	}
	
	// State controller
	if ((animElem(11)) ) {
		stateTypeSet_data d;
		d.physics = "A";
		stateTypeSet(d);
	}
	
	// State controller
	if (((time()) == 6) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, (ifElse(((random()) > 499), 4, 7))};
		d.channel = 0;
		playSnd(d);
	}
	
	// State controller
	if (((time()) == 0) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {10, 5};
		d.hitSound = {{"S", 21}, (ifElse(((random()) > 499), 0, 1))};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9114};
		d.sparkXY = {-45, -36};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 12;
		d.ground_velocity = {0, -6};
		d.air_velocity = {0, -6};
		hitDef(d);
	}
	
	// State controller
	if (((time()) == 40) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
}

void Cloudi::state_622()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'S';
		params.ctrl = 0;
		params.anim = 622;
		setStateParams(params);
	}
	
	// State controller
	if (((var(4)) <= 2) ) {
		varAdd_data d;
		d.v = 4;
		d.value = 1;
		varAdd(d);
	}
	
	// State controller
	if (((var(4)) >= 3) ) {
		varSet_data d;
		d.v = 4;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_888()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		params.anim = 888;
		params.ctrl = 0;
		params.stateType = 'S';
		params.moveType = 'A';
		params.physics = 'N';
		params.velSet = {0, 0};
		setStateParams(params);
	}
	
	// State controller
	if ((animElem(2)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8912;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = 5;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		explod_data d;
		d.ignoreHitPause = 0;
		d.anim = 8913;
		d.id = 101;
		d.pos = {0, 0};
		d.bindTime = -1;
		d.sprPriority = -1;
		d.removeOnGetHit = 1;
		explod(d);
	}
	
	// State controller
	if ((animElem(1)) || (animElem(9)) ) {
		velSet_data d;
		d.x = 5;
		velSet(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		velSet_data d;
		d.x = 3;
		velSet(d);
	}
	
	// State controller
	if ((animElem(5)) || (animElem(10)) ) {
		velSet_data d;
		d.x = 1.5;
		velSet(d);
	}
	
	// State controller
	if ((animElem(7)) || (animElem(11)) ) {
		velSet_data d;
		d.x = 0;
		velSet(d);
	}
	
	// State controller
	if (((time()) == 6) || ((time()) == 26) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(2)) ) {
		varRandom_data d;
		d.v = 3;
		d.range = {0, 1};
		varRandom(d);
	}
	
	// State controller
	if (((var(3)) == 1) && (animElem(2)) ) {
		playSnd_data d;
		d.value = {{"S", 20}, 2};
		playSnd(d);
	}
	
	// State controller
	if ((animElem(3)) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 8};
		d.hitSound = {{"S", 21}, 1};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9112};
		d.sparkXY = {-20, -30};
		d.animType = "medium";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 16;
		d.ground_velocity = {-1, -3};
		d.air_velocity = {-2, -3};
		hitDef(d);
	}
	
	// State controller
	if ((animElem(10)) ) {
		hitDef_data d;
		d.attr = {"S", "NA"};
		d.damage = 30;
		d.guardFlag = "MA";
		d.pauseTime = {6, 9};
		d.hitSound = {{"S", 21}, 0};
		d.guardSound = {6, 0};
		d.sparkNo = {"S", 9115};
		d.sparkXY = {-30, -30};
		d.animType = "heavy";
		d.ground_type = "High";
		d.ground_slideTime = 5;
		d.ground_hitTime = 16;
		d.ground_velocity = {-3, 3};
		d.air_velocity = {-3, 3};
		hitDef(d);
	}
	
	// State controller
	if (((moveHit()) && ((time()) > 26)) ) {
		ctrlSet_data d;
		d.value = 1;
		ctrlSet(d);
	}
	
	// State controller
	if (((animTime()) == 0) ) {
		changeState_data d;
		d.value = 0;
		d.ctrl = 1;
		changeState(d);
	}
}

void Cloudi::state_m2()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		setStateParams(params);
	}
	
	// State controller
	if ((((life()) <= ((lifeMax()) / 5)) && !(numHelper(20500))) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "critic";
		d.id = 20500;
		d.stateNo = 20500;
		d.pos = {0, 0};
		d.posType = "p1";
		d.facing = 1;
		d.keyCtrl = 0;
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if (!(numHelper(20000)) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "powerbar";
		d.id = 20000;
		d.stateNo = 20000;
		d.pos = {0, -10000};
		d.posType = "p1";
		d.facing = 1;
		d.keyCtrl = 0;
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if (!(numHelper(21000)) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "munico";
		d.id = 21000;
		d.stateNo = 21000;
		d.pos = {(ifElse(((teamSide()) == 1), 49, 271)), 46};
		d.posType = "left";
		d.facing = 1;
		d.keyCtrl = 0;
		d.ownPal = 1;
		helper(d);
	}
	
	// State controller
	if (((teamMode() == "single") && (getEnemy().teamMode() == "single")) ) {
		if ((!(numHelper(30000)) && (alive())) ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "ranker";
			d.id = 30000;
			d.stateNo = 30000;
			d.pos = {0, -10000};
			d.posType = "p1";
			d.facing = 1;
			d.keyCtrl = 0;
			d.ownPal = 1;
			helper(d);
		}
	}
	
	// State controller
	if (((stateNo()) >= 5000) ) {
		afterImageTime_data d;
		d.time = 1;
		afterImageTime(d);
	}
	
	// State controller
	if (!(alive()) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && ((getPlayerID((var(40))).stateNo()).inInterval('[', 40000, 44000, ']')) || (((id()) != (var(41))) && ((var(41)) != 0)) && ((getPlayerID((var(41))).stateNo()).inInterval('[', 40000, 44000, ']')) || (((id()) != (var(42))) && ((var(42)) != 0)) && ((getPlayerID((var(42))).stateNo()).inInterval('[', 40000, 44000, ']')) || (((id()) != (var(43))) && ((var(43)) != 0)) && ((getPlayerID((var(43))).stateNo()).inInterval('[', 40000, 44000, ']')) ) {
			assertSpecial_data d;
			d.flag = "invisible";
			assertSpecial(d);
		}
	}
	
	// State controller
	if ((! (stateNo()).inInterval('[', 40005, 40100, ']')) && (alive()) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && ((getPlayerID((var(40))).stateNo()) == 40000) || (((id()) != (var(41))) && ((var(41)) != 0)) && ((getPlayerID((var(41))).stateNo()) == 40000) || (((id()) != (var(42))) && ((var(42)) != 0)) && ((getPlayerID((var(42))).stateNo()) == 40000) || (((id()) != (var(43))) && ((var(43)) != 0)) && ((getPlayerID((var(43))).stateNo()) == 40000) ) {
			changeState_data d;
			d.value = 50000;
			d.ctrl = 0;
			changeState(d);
		}
	}
	
	// State controller
	if (((numTarget()) > 0) ) {
		if (((getTarget().getHitVar("hitcount")) > (var(34))) ) {
			varSet_data d;
			d.v = 34;
			d.value = (getTarget().getHitVar("hitcount"));
			varSet(d);
		}
	}
	
	// State controller
	if (1 ) {
		displayToClipboard_data d;
		d.text = "%d";
		d.params = (var(39));
		displayToClipboard(d);
	}
	
	// State controller
	if ((teamMode() == "single") && ((var(36)) == 0) && ((life()) == (lifeMax())) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && (((getPlayerID((var(40))).life()) < (getPlayerID((var(40))).lifeMax())) && ((getPlayerID((var(40))).var(36)) == 0)) || (((id()) != (var(41))) && ((var(41)) != 0)) && (((getPlayerID((var(41))).life()) < (getPlayerID((var(41))).lifeMax())) && ((getPlayerID((var(41))).var(36)) == 0)) || (((id()) != (var(42))) && ((var(42)) != 0)) && (((getPlayerID((var(42))).life()) < (getPlayerID((var(42))).lifeMax())) && ((getPlayerID((var(42))).var(36)) == 0)) || (((id()) != (var(43))) && ((var(43)) != 0)) && (((getPlayerID((var(43))).life()) < (getPlayerID((var(43))).lifeMax())) && ((getPlayerID((var(43))).var(36)) == 0)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 750;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((var(36)) == 0) && ((life()) == (lifeMax())) && ((numExplod(23000)) == 0) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && (((getPlayerID((var(40))).life()) < (getPlayerID((var(40))).lifeMax())) && ((getPlayerID((var(40))).var(36)) == 0)) || (((id()) != (var(41))) && ((var(41)) != 0)) && (((getPlayerID((var(41))).life()) < (getPlayerID((var(41))).lifeMax())) && ((getPlayerID((var(41))).var(36)) == 0)) || (((id()) != (var(42))) && ((var(42)) != 0)) && (((getPlayerID((var(42))).life()) < (getPlayerID((var(42))).lifeMax())) && ((getPlayerID((var(42))).var(36)) == 0)) || (((id()) != (var(43))) && ((var(43)) != 0)) && (((getPlayerID((var(43))).life()) < (getPlayerID((var(43))).lifeMax())) && ((getPlayerID((var(43))).var(36)) == 0)) ) {
			explod_data d;
			d.ignoreHitPause = 1;
			d.anim = {"F", (ifElse(((teamSide()) == 1), 3100, 3101))};
			d.id = 23000;
			d.pos = {(ifElse(((teamSide()) == 1), 40, 330)), (((110 + (ifElse(((numExplod(23100)) == 0), 0, 12))) + (ifElse(((numExplod(23200)) == 0), 0, 12))) + (ifElse(((numExplod(23300)) == 0), 0, 12)))};
			d.posType = "left";
			d.facing = 1;
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 999999999;
			explod(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((var(36)) == 0) && ((life()) == (lifeMax())) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && ((getPlayerID((var(40))).life()) < (getPlayerID((var(40))).lifeMax())) || (((id()) != (var(41))) && ((var(41)) != 0)) && ((getPlayerID((var(41))).life()) < (getPlayerID((var(41))).lifeMax())) || (((id()) != (var(42))) && ((var(42)) != 0)) && ((getPlayerID((var(42))).life()) < (getPlayerID((var(42))).lifeMax())) || (((id()) != (var(43))) && ((var(43)) != 0)) && ((getPlayerID((var(43))).life()) < (getPlayerID((var(43))).lifeMax())) ) {
			varSet_data d;
			d.v = 36;
			d.value = 1;
			varSet(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if (((prevStateNo()).inInterval('[', 120, 159, ']')) && (((moveHit()) && ((moveContact()) == 1)) && ((hitCount()) == 1)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 250;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((numExplod(23100)) == 0) ) {
		if (((prevStateNo()).inInterval('[', 120, 159, ']')) && ((moveHit()) && ((hitCount()) == 1)) ) {
			explod_data d;
			d.ignoreHitPause = 1;
			d.anim = {"F", (ifElse(((teamSide()) == 1), 3110, 3111))};
			d.id = 23100;
			d.pos = {(ifElse(((teamSide()) == 1), 40, 330)), ((((110 + (ifElse(((numExplod(23000)) == 0), 0, 12))) + (ifElse(((numExplod(23200)) == 0), 0, 12))) + (ifElse(((numExplod(23300)) == 0), 0, 12))) + (ifElse(((numExplod(23400)) == 0), 0, 12)))};
			d.posType = "left";
			d.facing = 1;
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 999999999;
			explod(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if (((stateNo()).inInterval('[', 3000, 3700, ']')) && ((((((((((prevStateNo()) == 200) || ((prevStateNo()) == 201)) || ((prevStateNo()) == 202)) || ((prevStateNo()) == 206)) || ((prevStateNo()) == 888)) || ((prevStateNo()) == 601)) || ((prevStateNo()) == 602)) || ((prevStateNo()) == 603)) || ((prevStateNo()) == 600)) && (animElem(2)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 500;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if ((((getEnemy().numHelper(20800)) != 0) && (((time()) % 10) == 0)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 500;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((numExplod(23200)) == 0) ) {
		if (((stateNo()).inInterval('[', 3000, 3700, ']')) && ((((((((((prevStateNo()) == 200) || ((prevStateNo()) == 201)) || ((prevStateNo()) == 202)) || ((prevStateNo()) == 206)) || ((prevStateNo()) == 888)) || ((prevStateNo()) == 601)) || ((prevStateNo()) == 602)) || ((prevStateNo()) == 603)) || ((prevStateNo()) == 600)) && (animElem(2)) ) {
			explod_data d;
			d.ignoreHitPause = 1;
			d.anim = {"F", (ifElse(((teamSide()) == 1), 3130, 3131))};
			d.id = 23200;
			d.pos = {(ifElse(((teamSide()) == 1), 40, 330)), (((110 + (ifElse(((numExplod(23000)) == 0), 0, 12))) + (ifElse(((numExplod(23100)) == 0), 0, 12))) + (ifElse(((numExplod(23300)) == 0), 0, 12)))};
			d.posType = "left";
			d.facing = 1;
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 999999999;
			explod(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if ((((stateNo()) == 9000) && ((time()) == 0)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = -1000;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if ((((getEnemy().numHelper(20800)) != 0) && (((time()) % 10) == 0)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 200;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") ) {
		if ((((stateNo()) == 9005) && ((animElemTime(1)) < 2)) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 200;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((numExplod(23300)) == 0) ) {
		if ((((stateNo()) == 9000) && ((time()) == 0)) ) {
			explod_data d;
			d.ignoreHitPause = 1;
			d.anim = {"F", (ifElse(((teamSide()) == 1), 3120, 3121))};
			d.id = 23300;
			d.pos = {(ifElse(((teamSide()) == 1), 40, 330)), ((((110 + (ifElse(((numExplod(23000)) == 0), 0, 12))) + (ifElse(((numExplod(23100)) == 0), 0, 12))) + (ifElse(((numExplod(23200)) == 0), 0, 12))) + (ifElse(((numExplod(23400)) == 0), 0, 12)))};
			d.posType = "left";
			d.facing = 1;
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 999999999;
			explod(d);
		}
	}
	
	// State controller
	if (((numExplod(23400)) == 0) && (teamMode() == "single") && (((stateNo()) == 45000) && ((animTime()) == 0)) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && ((getPlayerID((var(40))).alive()) == 0) || (((id()) != (var(41))) && ((var(41)) != 0)) && ((getPlayerID((var(41))).alive()) == 0) || (((id()) != (var(42))) && ((var(42)) != 0)) && ((getPlayerID((var(42))).alive()) == 0) || (((id()) != (var(43))) && ((var(43)) != 0)) && ((getPlayerID((var(43))).alive()) == 0) ) {
			varAdd_data d;
			d.v = 39;
			d.value = 10000;
			varAdd(d);
		}
	}
	
	// State controller
	if ((teamMode() == "single") && ((numExplod(23400)) == 0) && (((stateNo()) == 45000) && ((animTime()) == 0)) ) {
		if ((((id()) != (var(40))) && ((var(40)) != 0)) && ((getPlayerID((var(40))).alive()) == 0) || (((id()) != (var(41))) && ((var(41)) != 0)) && ((getPlayerID((var(41))).alive()) == 0) || (((id()) != (var(42))) && ((var(42)) != 0)) && ((getPlayerID((var(42))).alive()) == 0) || (((id()) != (var(43))) && ((var(43)) != 0)) && ((getPlayerID((var(43))).alive()) == 0) ) {
			explod_data d;
			d.ignoreHitPause = 1;
			d.anim = {"F", (ifElse(((teamSide()) == 1), 3140, 3141))};
			d.id = 23400;
			d.pos = {(ifElse(((teamSide()) == 1), 40, 330)), ((((110 + (ifElse(((numExplod(23000)) == 0), 0, 12))) + (ifElse(((numExplod(23100)) == 0), 0, 12))) + (ifElse(((numExplod(23200)) == 0), 0, 12))) + (ifElse(((numExplod(23300)) == 0), 0, 12)))};
			d.posType = "left";
			d.facing = 1;
			d.bindTime = -1;
			d.sprPriority = 5;
			d.onTop = 1;
			d.ownPal = 1;
			d.superMoveTime = 999999999;
			explod(d);
		}
	}
	
	// State controller
	if (((teamMode() == "single") && ((roundState()) == 2)) ) {
		if ((((((id()) == (var(40))) && ((playerIdExist((var(41)))) & ((getPlayerID((var(41))).alive()) == 1))) && ((playerIdExist((var(42)))) & ((getPlayerID((var(42))).alive()) == 1))) && ((playerIdExist((var(43)))) & ((getPlayerID((var(43))).alive()) == 1))) || (((((id()) == (var(41))) && ((playerIdExist((var(40)))) & ((getPlayerID((var(40))).alive()) == 1))) && ((playerIdExist((var(42)))) & ((getPlayerID((var(42))).alive()) == 1))) && ((playerIdExist((var(43)))) & ((getPlayerID((var(43))).alive()) == 1))) || (((((id()) == (var(42))) && ((playerIdExist((var(41)))) & ((getPlayerID((var(41))).alive()) == 1))) && ((playerIdExist((var(40)))) & ((getPlayerID((var(40))).alive()) == 1))) && ((playerIdExist((var(43)))) & ((getPlayerID((var(43))).alive()) == 1))) || (((((id()) == (var(44))) && ((playerIdExist((var(41)))) & ((getPlayerID((var(41))).alive()) == 1))) && ((playerIdExist((var(42)))) & ((getPlayerID((var(42))).alive()) == 1))) && ((playerIdExist((var(40)))) & ((getPlayerID((var(40))).alive()) == 1))) ) {
			varSet_data d;
			d.v = 37;
			d.value = (getHelper(21000).time());
			varSet(d);
		}
	}
	
	// State controller
	if ((! (stateNo()).inInterval('[', 40000, 50000, ']')) && ((var(58)) < 1000) ) {
		varAdd_data d;
		d.v = 58;
		d.value = 1;
		varAdd(d);
	}
	
	// State controller
	if (((numExplod(32710)) && ((stateNo()) != 31310)) ) {
		explod_data d;
		d.anim = {"F", 32713};
		d.id = 32711;
		d.pos = {0, -25};
		d.posType = "p1";
		d.bindTime = 1;
		d.sprPriority = 5;
		d.scale = {1, 1};
		explod(d);
	}
	
	// State controller
	if (((numExplod(32710)) && ((stateNo()) != 31310)) ) {
		playSnd_data d;
		d.value = {{"F", 30126}, 0};
		playSnd(d);
	}
	
	// State controller
	if (((numExplod(32710)) && ((stateNo()) != 31310)) ) {
		removeExplod_data d;
		d.id = 32710;
		removeExplod(d);
	}
	
	// State controller
	if ((!(numExplod(329120)) && ((prevStateNo()) == 31520)) ) {
		playSnd_data d;
		d.value = {{"F", 5001}, 0};
		playSnd(d);
	}
	
	// State controller
	if ((!(numExplod(329120)) && ((prevStateNo()) == 31520)) ) {
		palFX_data d;
		d.time = 1;
		d.add = {0, 0, 0};
		d.mul = {256, 256, 256};
		d.invertAll = 0;
		d.color = 256;
		palFX(d);
	}
	
	// State controller
	if ((!(numExplod(329120)) && ((prevStateNo()) == 31520)) ) {
		explod_data d;
		d.anim = {"F", 32912};
		d.id = 329120;
		d.pos = {0, -20};
		d.posType = "p1";
		d.bindTime = 1;
		d.sprPriority = 5;
		explod(d);
	}
	
	// State controller
	if (((getHitVar("damage")) && ((prevStateNo()) == 31520)) ) {
		lifeAdd_data d;
		d.value = -(getHitVar("damage"));
		d.kill = 1;
		d.absolute = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((getHitVar("chainid")) == 999) && ((stateNo()).inInterval('[', 120, 169, ']'))) ) {
		varSet_data d;
		d.fv = 14;
		d.value = 20;
		varSet(d);
	}
	
	// State controller
	if (((numHelper(36614)) > 0) ) {
		lifeAdd_data d;
		d.value = (floor(((getHitVar("damage")) / 2)));
		d.kill = 1;
		d.absolute = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((numHelper(36614)) > 0) && ((stateNo()).inInterval('[', 5000, 5050, ']'))) && (((numExplod(34810)) == 0) && ((time()) == 0)) ) {
		playSnd_data d;
		d.persistent = 22;
		d.value = {{"F", 30146}, 1};
		playSnd(d);
	}
	
	// State controller
	if ((((numHelper(36614)) > 0) && ((stateNo()).inInterval('[', 5000, 5050, ']'))) && (((numExplod(34810)) == 0) && ((time()) == 0)) ) {
		explod_data d;
		d.persistent = 22;
		d.anim = {"F", 34810};
		d.id = 34810;
		d.pos = {20, -25};
		d.posType = "p1";
		d.bindTime = 1;
		d.sprPriority = 5;
		explod(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (numHelper(32899))) || (((roundState()) == 2) && (getEnemy().numHelper(32898))) ) {
		lifeAdd_data d;
		d.value = 50;
		d.kill = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (numHelper(32897))) ) {
		varAdd_data d;
		d.value = (ifElse(((getHelper(32897).var(11)) == 0), 10, (ifElse(((getHelper(32897).var(11)) == 1), 50, 200))));
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(32896))) ) {
		varAdd_data d;
		d.value = 10;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(32895))) ) {
		varAdd_data d;
		d.value = 50;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(32894))) ) {
		varAdd_data d;
		d.value = 200;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((numHelper(36910)) ) {
		attackMulSet_data d;
		d.value = 1.5;
		attackMulSet(d);
	}
	
	// State controller
	if (!(numHelper(36910)) ) {
		attackMulSet_data d;
		d.value = 1;
		attackMulSet(d);
	}
	
	// State controller
	if (((((roundState()) == 2) && (getEnemy().numHelper(38006))) && (((time()) % 2) == 0)) ) {
		lifeAdd_data d;
		d.value = -1;
		d.kill = 0;
		lifeAdd(d);
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 1)) || (((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 1)) ) {
			assertSpecial_data d;
			d.flag = "invisible";
			assertSpecial(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 1)) || (((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 1)) ) {
			hitBy_data d;
			d.value = "";
			d.time = 1;
			hitBy(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			posSet_data d;
			d.x = (getHelper(130000).var(10));
			posSet(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			velSet_data d;
			d.x = 0;
			d.y = 0;
			velSet(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			posSet_data d;
			d.x = (getHelper(130000).var(10));
			d.y = (getHelper(130000).var(11));
			posSet(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 3)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			changeState_data d;
			d.value = 50;
			d.ctrl = 1;
			changeState(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			velSet_data d;
			d.x = 0;
			d.y = 0;
			velSet(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 1)) || (((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 1)) ) {
			assertSpecial_data d;
			d.flag = "invisible";
			assertSpecial(d);
		}
	}
	
	// State controller
	if (((stateNo()).inInterval('[', 0, 199, ']')) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 1)) || (((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 1)) ) {
			hitBy_data d;
			d.value = "";
			d.time = 1;
			hitBy(d);
		}
	}
	
	// State controller
	if (((stateType() != "L") && ((stateNo()).inInterval('[', 5000, 5999, ']'))) ) {
		if ((((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			posSet_data d;
			d.x = (getHelper(130000).var(10));
			posSet(d);
		}
	}
	
	// State controller
	if (((stateType() != "L") && ((stateNo()).inInterval('[', 5000, 5999, ']'))) ) {
		if ((((getHelper(130000).stateNo()) == 33001) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			velSet_data d;
			d.x = 0;
			d.y = 0;
			velSet(d);
		}
	}
	
	// State controller
	if (((stateType() != "L") && ((stateNo()).inInterval('[', 5000, 5999, ']'))) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			posSet_data d;
			d.x = (getHelper(130000).var(10));
			d.y = (getHelper(130000).var(11));
			posSet(d);
		}
	}
	
	// State controller
	if (((stateType() != "L") && ((stateNo()).inInterval('[', 5000, 5999, ']'))) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 3)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			changeState_data d;
			d.value = 50;
			d.ctrl = 1;
			changeState(d);
		}
	}
	
	// State controller
	if (((stateType() != "L") && ((stateNo()).inInterval('[', 5000, 5999, ']'))) ) {
		if ((((getHelper(130000).stateNo()) == 33002) && ((getHelper(130000).time()) == 2)) && (((getHelper(130000).rootDist().x) < 40) && ((getHelper(130000).rootDist().x) > -40)) && (((getHelper(130000).rootDist().y) < 20) && ((getHelper(130000).rootDist().y) > -20)) ) {
			velSet_data d;
			d.x = 0;
			d.y = 0;
			velSet(d);
		}
	}
	
	// State controller
	if (((((getEnemy().numHelper(37350)) == 1) && ((numHelper(130100)) == 0)) && ((getEnemy().numHelper(130000)) == 1)) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "shadowclon";
		d.id = 130100;
		d.stateNo = 37350;
		d.pos = {40, -5};
		d.posType = "p2";
		d.facing = 1;
		d.keyCtrl = 0;
		d.ownPal = 0;
		d.size_xScale = 1;
		d.size_yScale = 1;
		d.size_ground_back = 0;
		d.size_ground_front = 26;
		helper(d);
	}
	
	// State controller
	if (((((numHelper(130000)) == 1) && ((getHelper(130000).stateNo()) == 33100)) && !(numHelper(130002))) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "raziel absortion2";
		d.id = 130002;
		d.stateNo = 33120;
		d.pos = {50, -10};
		d.posType = "p2";
		d.facing = 1;
		d.keyCtrl = 0;
		helper(d);
	}
	
	// State controller
	if (((getEnemy().numHelper(130002)) && !(numHelper(130001))) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "raziel absortion";
		d.id = 130001;
		d.stateNo = 33111;
		d.pos = {50, -10};
		d.posType = "p2";
		d.facing = 1;
		d.keyCtrl = 0;
		helper(d);
	}
	
	// State controller
	if (((random()) > 400) && (getEnemy().numHelper(33210)) ) {
		if ((((ctrl()) && (command("y"))) && (moveType() != "H")) || (((ctrl()) && (command("x"))) && (moveType() != "H")) ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "paralisis";
			d.id = 33230;
			d.stateNo = 33230;
			d.pos = {0, 0};
			d.posType = "p1";
			helper(d);
		}
	}
	
	// State controller
	if (((getEnemy().numHelper(39390)) && !(numHelper(39398))) ) {
		helper_data d;
		d.helperType = "normal";
		d.name = "theboy acidrain";
		d.id = 39398;
		d.stateNo = 39398;
		d.pos = {0, 0};
		d.posType = "p1";
		d.facing = 1;
		d.keyCtrl = 0;
		helper(d);
	}
	
	// State controller
	if ((((getHelper(39398).var(10)) == 1) && (((time()) % 10) == 0)) ) {
		palFX_data d;
		d.time = 3;
		d.add = {100, 100, 50};
		d.mul = {250, 250, 24};
		d.sinAdd = {115, 110, 55, 10};
		d.invertAll = 0;
		d.color = 0;
		palFX(d);
	}
	
	// State controller
	if ((((getHelper(39398).var(10)) == 1) && (((time()) % 2) == 0)) ) {
		lifeAdd_data d;
		d.value = -2;
		d.kill = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((getEnemy().stateNo()) == 33415) && ((getEnemy().numHelper(33416)) == 0)) ) {
		varSet_data d;
		d.fv = 31;
		d.value = (p2Dist().x);
		varSet(d);
	}
	
	// State controller
	if ((((getEnemy().stateNo()) == 33415) && ((getEnemy().numHelper(33416)) == 0)) ) {
		varSet_data d;
		d.fv = 32;
		d.value = (p2Dist().y);
		varSet(d);
	}
	
	// State controller
	if (1 ) {
		displayToClipboard_data d;
		d.text = "%d %d  ___ %f %f";
		d.params = {(getEnemy().stateNo()), (getEnemy().numHelper(33416)), (fvar(31)), (fvar(32))};
		displayToClipboard(d);
	}
	
	// State controller
	if ((((getEnemy().stateNo()) == 33415) && ((getEnemy().numHelper(33416)) == 0)) ) {
		changeAnim_data d;
		d.value = 44;
		changeAnim(d);
	}
	
	// State controller
	if (((getEnemy().stateNo()) == 33415) || ((getEnemy().numHelper(33416)) == 1) ) {
		playerPush_data d;
		d.value = 0;
		playerPush(d);
	}
	
	// State controller
	if ((((getEnemy().stateNo()) == 33415) && ((getEnemy().numHelper(33416)) == 0)) ) {
		velSet_data d;
		d.x = 0;
		d.y = 0;
		velSet(d);
	}
	
	// State controller
	if (((getEnemy().numHelper(33416)) == 1) ) {
		posAdd_data d;
		d.persistent = 22;
		d.x = (fvar(31));
		d.y = (fvar(32));
		posAdd(d);
	}
	
	// State controller
	if (((getEnemy().numHelper(33416)) == 1) ) {
		turn_data d;
		d.persistent = 22;
		turn(d);
	}
	
	// State controller
	if (((getEnemy().numHelper(33416)) == 1) ) {
		changeState_data d;
		d.persistent = 22;
		d.value = 51;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if (((((getHelper(130000).stateNo()) == 33304) && ((vel().y) > 1)) && ((getHelper(130000).var(10)) == 0)) ) {
		explod_data d;
		d.anim = {"F", 36020};
		d.id = 36020;
		d.pos = {-5, -7};
		d.posType = "p1";
		d.bindTime = 1;
		d.sprPriority = -1;
		d.ownPal = 1;
		d.scale = {0.5, 0.5};
		explod(d);
	}
	
	// State controller
	if (((((getHelper(130000).stateNo()) == 33304) && ((vel().y) > 1)) && ((getHelper(130000).var(10)) == 0)) ) {
		changeState_data d;
		d.value = 33310;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (numHelper(37515))) || (((roundState()) == 2) && (getEnemy().numHelper(37516))) ) {
		lifeAdd_data d;
		d.value = 250;
		d.kill = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (numHelper(37525))) || (((roundState()) == 2) && (getEnemy().numHelper(37526))) ) {
		lifeAdd_data d;
		d.value = 1;
		d.kill = 0;
		lifeAdd(d);
	}
	
	// State controller
	if ((((numHelper(33730)) == 0) && ((roundState()) == 2)) ) {
		if (((getEnemy().numHelper(33710)) == 1) || ((getEnemy().numHelper(33711)) == 1) || ((getEnemy().numHelper(33712)) == 1) ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "p2janken";
			d.id = 33730;
			d.stateNo = 33730;
			d.pos = {0, 0};
			d.posType = "p1";
			d.facing = 1;
			d.keyCtrl = 0;
			d.ownPal = 0;
			helper(d);
		}
	}
	
	// State controller
	if (((alive()) && ((roundState()) == 2)) ) {
		if ((((((getHelper(34010).stateNo()) == 34030) && (ctrl())) && ((stateNo()) != 34045)) && (command("z"))) && ((getHelper(34010).var(35)) < 100) ) {
			changeState_data d;
			d.value = 34045;
			d.ctrl = 0;
			changeState(d);
		}
	}
	
	// State controller
	if (((getEnemy().numHelper(34210)) > 0) ) {
		if (((vel().x) == 0) && (((time()) % 3) == 0) ) {
			velMul_data d;
			d.x = 0.6;
			velMul(d);
		}
	}
	
	// State controller
	if (((getEnemy().numHelper(34210)) > 0) ) {
		if (((vel().y) < 0) && (((time()) % 3) == 0) ) {
			velMul_data d;
			d.y = 0.6;
			velMul(d);
		}
	}
	
	// State controller
	if (((getHitVar("damage")) >= (life())) && ((getHelper(39510).stateNo()) == 39511) ) {
		lifeAdd_data d;
		d.value = 250;
		d.kill = 1;
		d.absolute = 0;
		lifeAdd(d);
	}
	
	// State controller
	if (((getHelper(39510).stateNo()) == 39511) ) {
		superPause_data d;
		d.time = 20;
		d.anim = -1;
		d.sound = {-1, -1};
		d.pos = {0, 0};
		superPause(d);
	}
	
	// State controller
	if (((getHelper(39510).stateNo()) == 39511) ) {
		velSet_data d;
		d.x = 0;
		d.y = -.1;
		velSet(d);
	}
	
	// State controller
	if (((getHelper(39510).stateNo()) == 39511) ) {
		changeState_data d;
		d.value = 45;
		d.ctrl = 1;
		changeState(d);
	}
	
	// State controller
	if (((((getEnemy().numHelper(32010)) && ((var(48)) != 0)) && !(getHitVar("guarded"))) && ((numExplod(9002)) == 0)) ) {
		bgPalFX_data d;
		d.time = 5;
		d.add = {255, 255, 255};
		d.mul = {256, 256, 256};
		d.sinAdd = {255, 255, 255, 10};
		d.invertAll = 0;
		bgPalFX(d);
	}
	
	// State controller
	if (((((getEnemy().numHelper(32010)) && ((var(48)) != 0)) && !(getHitVar("guarded"))) && ((numExplod(9002)) == 0)) ) {
		playSnd_data d;
		d.value = {{"F", 120}, 10};
		playSnd(d);
	}
	
	// State controller
	if (((((getEnemy().numHelper(32010)) && ((var(48)) != 0)) && !(getHitVar("guarded"))) && ((numExplod(9002)) == 0)) ) {
		explod_data d;
		d.anim = {"F", (ifElse(((teamSide()) == 1), 485, 486))};
		d.id = 30004;
		d.pos = {(ifElse(((teamSide()) == 1), 3, 306)), (210 + (ifElse((var(4)), 39, 1)))};
		d.posType = "left";
		d.scale = {1, 1};
		d.facing = 1;
		d.onTop = 1;
		d.ownPal = 1;
		d.bindTime = -1;
		d.sprPriority = 5;
		explod(d);
	}
	
	// State controller
	if (((((getEnemy().numHelper(32010)) && ((var(48)) != 0)) && !(getHitVar("guarded"))) && ((numExplod(9002)) == 0)) ) {
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
	if (((numHelper(130000)) && ((getHelper(130000).facing()) == (facing()))) ) {
		if (((getHelper(130000).stateNo()).inInterval('[', 38200, 38299, ']')) ) {
			varSet_data d;
			d.v = 57;
			d.value = (floor((getHelper(130000).rootDist().x)));
			varSet(d);
		}
	}
	
	// State controller
	if (((numHelper(130000)) && ((getHelper(130000).facing()) != (facing()))) ) {
		if (((getHelper(130000).stateNo()).inInterval('[', 38200, 38299, ']')) ) {
			varSet_data d;
			d.v = 57;
			d.value = (floor(-(getHelper(130000).rootDist().x)));
			varSet(d);
		}
	}
	
	// State controller
	if ((! (stateNo()).inInterval('[', 38200, 38299, ']')) ) {
		removeExplod_data d;
		d.id = 39510;
		removeExplod(d);
	}
	
	// State controller
	if (((((roundState()) == 2) && (numHelper(37910))) && ((getHelper(37910).stateNo()) == 37913)) ) {
		varAdd_data d;
		d.value = (getHelper(37910).var(12));
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(37920))) ) {
		varAdd_data d;
		d.value = 500;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(37921))) ) {
		varAdd_data d;
		d.value = 1200;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((roundState()) == 2) && (getEnemy().numHelper(37922))) ) {
		varAdd_data d;
		d.value = 2000;
		d.v = 39;
		varAdd(d);
	}
	
	// State controller
	if ((((getHelper(34910).var(12)) == 1) && ((numHelper(34910)) == 1)) ) {
		hitBy_data d;
		d.value = "";
		d.time = 10;
		hitBy(d);
	}
	
	// State controller
	if ((((numHelper(34910)) == 1) && (((time()) % 10) == 0)) ) {
		afterImage_data d;
		d.time = 10;
		d.length = 5;
		d.palBright = {0, 70, 0};
		d.palContrast = {50, 120, 50};
		d.palAdd = {0, 0, 0};
		d.palMul = {1, 1, 1};
		d.timeGap = 1;
		d.frameGap = 2;
		d.trans = "Add";
		afterImage(d);
	}
	
	// State controller
	if ((((getHelper(34910).var(12)) == 1) && ((numHelper(34910)) == 1)) ) {
		trans_data d;
		d.trans = "add1";
		d.alpha = {256, 128};
		trans(d);
	}
	
	// State controller
	if (((getHitVar("fall.envshake.phase")) != 999) ) {
		if ((((getHitVar("damage")) && ((random()) < ((getHitVar("damage")) * 2))) && ((getHitVar("fall.envshake.phase")) != 888)) || (((getHitVar("damage")) && ((random()) < 500)) && ((getHitVar("fall.envshake.phase")) == 888)) ) {
			helper_data d;
			d.helperType = "normal";
			d.name = "critical hits";
			d.id = 20800;
			d.stateNo = 20800;
			d.pos = {0, 0};
			d.posType = "p1";
			d.facing = 1;
			d.keyCtrl = 0;
			d.ownPal = 0;
			helper(d);
		}
	}
	
	// State controller
	if ((((numHelper(20800)) != 0) && (((time()) % 10) == 0)) ) {
		lifeAdd_data d;
		d.ignoreHitPause = 0;
		d.value = (ceil((-(getHitVar("damage")) * (ifElse(((random()) < 333), (ifElse(((random()) < 499), 1.2, .9)), .75)))));
		d.kill = 1;
		d.absolute = 0;
		lifeAdd(d);
	}
}

void Cloudi::state_m3()
{
	// State initialization
	if(time().GetInt32() == 0) {
		setStateParams_data params;
		setStateParams(params);
	}
	
	// State controller
	if (((time()) == 1) ) {
		if (((stateNo()) == 52) || ((stateNo()) == 106) ) {
			playSnd_data d;
			d.value = {101, 2};
			playSnd(d);
		}
	}
	
	// State controller
	if (((stateNo()) >= 5000) ) {
		afterImageTime_data d;
		d.time = 1;
		afterImageTime(d);
	}
	
	// State controller
	if (((((stateNo()) >= 3000) && ((stateNo()) <= 3900)) && ((time()) == 0)) ) {
		removeExplod_data d;
		d.id = 101;
		removeExplod(d);
	}
	
	// State controller
	if ((((getHitVar("HitShakeTime")) >= 0) && ((getHitVar("HitShakeTime")) < 10)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + .15
			}
		}
	}
	
	// State controller
	if (((getHitVar("chainid")) == 140) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = 14
			}
		}
	}
	
	// State controller
	if (((getHitVar("chainid")) == 120) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + .7
			}
		}
	}
	
	// State controller
	if ((numHelper(30000)) && ((getHelper(30000).var(45)) > 0) && (((getHitVar("HitShakeTime")) >= 0) && ((getHitVar("HitShakeTime")) < 10)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.15
			}
		}
	}
	
	// State controller
	if ((((getHitVar("HitShakeTime")) >= 10) && ((getHitVar("HitShakeTime")) < 15)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + .24
			}
		}
	}
	
	// State controller
	if ((numHelper(30000)) && ((getHelper(30000).var(45)) > 0) && (((getHitVar("HitShakeTime")) >= 10) && ((getHitVar("HitShakeTime")) < 15)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.24
			}
		}
	}
	
	// State controller
	if ((((getHitVar("HitShakeTime")) >= 15) && ((getHitVar("HitShakeTime")) < 30)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + .35
			}
		}
	}
	
	// State controller
	if ((numHelper(30000)) && ((getHelper(30000).var(45)) > 0) && (((getHitVar("HitShakeTime")) >= 15) && ((getHitVar("HitShakeTime")) < 30)) ) {
		if ((((stateNo()) == 150) || ((stateNo()) == 152)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.35
			}
		}
	}
	
	// State controller
	if ((((((fvar(14)) > 0) && !(time())) && ((stateNo()) == 5000)) && (alive())) ) {
		if ((((((anim()) == 5000) || ((anim()) == 5001)) || ((anim()) == 5010)) || ((anim()) == 5011)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.02
			}
		}
	}
	
	// State controller
	if ((((((fvar(14)) > 0) && !(time())) && ((stateNo()) == 5010)) && (alive())) ) {
		if ((((anim()) == 5020) || ((anim()) == 5021)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.02
			}
		}
	}
	
	// State controller
	if ((((((fvar(14)) > 0) && !(time())) && ((stateNo()) == 5000)) && (alive())) ) {
		if ((((anim()) == 5002) || ((anim()) == 5012)) ) {
			canExecuteController_data d;
			d.ignoreHitPause = 1;
			if( canExecuteController(d) ) {
				fvar(14) = fvar(14) + -.06
			}
		}
	}
	
	// State controller
	if (((((((fvar(14)) > 0) && !(time())) && ((stateNo()) == 5010)) && (alive())) && ((anim()) == 5022)) ) {
		canExecuteController_data d;
		d.ignoreHitPause = 1;
		if( canExecuteController(d) ) {
			fvar(14) = fvar(14) + -.06
		}
	}
	
	// State controller
	if ((((((fvar(14)) > 0) && !(time())) && ((stateNo()) == 5100)) && (alive())) ) {
		canExecuteController_data d;
		d.ignoreHitPause = 1;
		if( canExecuteController(d) ) {
			fvar(14) = fvar(14) + -.12
		}
	}
	
	// State controller
	if ((((((fvar(14)) > 0) && (((gameTime()) % 5) == 0)) && (moveType() != "H")) && (! (stateNo()).inInterval('[', 130, 160, ']'))) ) {
		canExecuteController_data d;
		d.ignoreHitPause = 1;
		if( canExecuteController(d) ) {
			fvar(14) = fvar(14) + -.02
		}
	}
	
	// State controller
	if (((fvar(14)) >= 15) ) {
		changeState_data d;
		d.ignoreHitPause = 1;
		d.value = 9000;
		d.ctrl = 0;
		changeState(d);
	}
	
	// State controller
	if (((fvar(14)) < 0) ) {
		canExecuteController_data d;
		d.ignoreHitPause = 1;
		if( canExecuteController(d) ) {
			fvar(14) = 0
		}
	}
	
	// State controller
	if ((((stateNo()) != 9005) && (! (stateNo()).inInterval('[', 120, 190, ']'))) ) {
		varSet_data d;
		d.ignoreHitPause = 1;
		d.v = 16;
		d.value = 0;
		varSet(d);
	}
	
	// State controller
	if (((((getHitVar("guarded")) && !(hitShakeOver())) && ((time()) < 4)) && ((var(16)) == 0)) ) {
		palFX_data d;
		d.time = 1;
		d.add = {16, 16, 56};
		d.mul = {256, 256, 256};
		d.sinAdd = {10, 10, 20, 10};
		d.invertAll = 0;
		d.color = 256;
		palFX(d);
	}
	
	// State controller
	if (((command("fwd")) && (hitShakeOver())) || ((command("fwd")) && ((stateNo()).inInterval('[', 120, 140, ']'))) ) {
		varSet_data d;
		d.ignoreHitPause = 1;
		d.v = 16;
		d.value = 1;
		varSet(d);
	}
	
	// State controller
	if (((numHelper(9001)) == 1) ) {
		assertSpecial_data d;
		d.flag = "nostandguard";
		d.flag2 = "noairguard";
		assertSpecial(d);
	}
	
	// State controller
	if ((((((getHitVar("guarded")) && !(hitShakeOver())) && ((time()) < 4)) && (command("fwd"))) && ((var(16)) == 0)) ) {
		changeState_data d;
		d.ignoreHitPause = 1;
		d.value = 9005;
		d.ctrl = 0;
		changeState(d);
	}
	
	// State controller
	if (1 ) {
		varSet_data d;
		d.ignoreHitPause = 1;
		d.v = 48;
		d.value = (getHelper(30000).var(20));
		varSet(d);
	}
}

