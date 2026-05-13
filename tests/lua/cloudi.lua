--[[
   cloudi.lua
   Generated from cloudi.cns
   on 2026-05-13.

   by Sourcy Code Translator
   (c) 2012 - radexx

   Runtime version: 1.0

]]

function Cloudi:state_1000()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "S",
		ctrl = 0,
		anim = 1000,
	}
	
	-- State controller
	if ((self:time()) > 26) then
		self:explod {
			persistent = 12,
			anim = 425,
			id = 2323,
			pos = {(self:ifElse(((self:random()) > 499), -20, -30)), -13},
			posType = "p1",
			sprPriority = 5,
			scale = {0.28, 0.28}
		}
	end
	
	-- State controller
	if ((self:time()) > 26) then
		self:explod {
			persistent = 12,
			anim = 425,
			id = 2323,
			pos = {(self:ifElse(((self:random()) > 499), -20, -30)), -13},
			posType = "p1",
			sprPriority = 5,
			scale = {0.18, 0.18}
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 100}, 0}
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			anim = 8777,
			id = 1011,
			pos = {100, -45},
			posType = "p1",
			facing = 1,
			vFacing = 1,
			bindTime = 1,
			scale = {0.8, 0.8},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:helper {
			persistent = 1,
			helperType = "normal",
			name = "bladebeam",
			id = 1000,
			stateNo = 1001,
			pos = {25, 0},
			posType = "p1",
			ownPal = 1
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 17}, 5},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:sprPriority {
			value = -1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {0, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-10, -20},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = 0,
			air_velocity = {0, 3}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_1001()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 8779,
	}
	
	-- State controller
	if (self:isHelper()) then
		if (((self:getRoot():stateNo()) == 50000) or ((self:getRoot():stateNo()) == 40000)) then
			self:destroySelf {
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			x = 0,
			y = 0
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 100}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			x = 6
		}
	end
	
	-- State controller
	if ((self:time()) == 25) then
		self:velSet {
			x = 9
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "noshadow"
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:explod {
			anim = 8778,
			id = 1011,
			pos = {-30, -28},
			posType = "p1",
			facing = 1,
			vFacing = 1,
			bindTime = -1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 50,
			guardFlag = "MA",
			pauseTime = {0, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = 0,
			sparkXY = {-10, -25},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = 0,
			air_velocity = {0, -4}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:destroySelf {
		}
	end
end

function Cloudi:state_1010()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		ctrl = 0,
		anim = 1010,
	}
	
	-- State controller
	if ((self:time()) == 1) then
		self:velSet {
			x = -2,
			y = -3
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:explod {
			anim = 8777,
			id = 1011,
			pos = {55, -45},
			posType = "p1",
			facing = 1,
			vFacing = 1,
			bindTime = 1,
			scale = {0.6, 0.6},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:explod {
			anim = 8777,
			id = 1011,
			pos = {-45, 35},
			posType = "p1",
			facing = -1,
			vFacing = -1,
			bindTime = 1,
			scale = {0.6, 0.6},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:helper {
			persistent = 1,
			helperType = "normal",
			name = "bladebeam",
			id = 1112,
			stateNo = 1011,
			pos = {-42, -15},
			posType = "p1",
			ownPal = 1
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 12}, 0},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 100}, 3}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:sprPriority {
			value = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {10, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-10, -20},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = 0,
			air_velocity = {0, -1}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_1011()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 8780,
	}
	
	-- State controller
	if (self:isHelper()) then
		if (((self:getRoot():stateNo()) == 50000) or ((self:getRoot():stateNo()) == 40000)) then
			self:destroySelf {
			}
		end
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:stateTypeSet {
			physics = "A"
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:stateTypeSet {
			physics = "N"
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:explod {
			anim = 8781,
			id = 1016,
			pos = {0, -45},
			posType = "p1",
			facing = 1,
			vFacing = 1,
			removeTime = -1,
			bindTime = -1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "noshadow"
		}
	end
	
	-- State controller
	if 1 then
		self:velSet {
			x = 4,
			y = 4
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 50,
			guardFlag = "MA",
			pauseTime = {0, 10},
			hitSound = {{"S", 20}, 0},
			guardSound = {6, 0},
			sparkXY = {-10, -20},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = 0,
			air_velocity = {0, -4}
		}
	end
end

function Cloudi:state_1013()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "N",
		ctrl = 0,
	}
	
	-- State controller
	if (self:isHelper()) then
		if (((self:getRoot():stateNo()) == 50000) or ((self:getRoot():stateNo()) == 40000)) then
			self:destroySelf {
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posAdd {
			x = -20,
			y = 10
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posAdd {
			x = -20,
			y = 65
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 50,
			guardFlag = "MA",
			pauseTime = {0, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 1, 0))},
			guardSound = {6, 0},
			sparkXY = {-10, -20},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = 0,
			air_velocity = {0, -4}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:destroySelf {
		}
	end
end

function Cloudi:state_170()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		anim = 170,
		velSet = {0, 0},
	}
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = "SCA",
			time = 1
		}
	end
end

function Cloudi:state_180()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeState {
			value = 181
		}
	end
end

function Cloudi:state_181()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		anim = 180,
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:helper {
			helperType = "normal",
			name = "windata",
			id = 10000,
			stateNo = 10000,
			pos = {0, 0},
			posType = "left",
			ownPal = 1
		}
	end
	
	-- State controller
	if (((self:time()) == 1) and ((self:random()) > 499)) then
		self:playSnd {
			value = {{"S", 40}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(40)) then
		self:playSnd {
			value = {{"S", 100}, 0}
		}
	end
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = "SCA",
			time = 1
		}
	end
end

function Cloudi:state_190()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		anim = 190,
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:roundState()) == 0) then
		self:changeAnim {
			value = 190
		}
	end
	
	-- State controller
	if (self:animElem(7)) or (self:animElem(13)) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 102}, 0}
		}
	end
	
	-- State controller
	if (self:animElem(18)) then
		self:playSnd {
			value = {{"S", 100}, 0}
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			anim = 427,
			id = 426,
			pos = {-20, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(13)) then
		self:explod {
			anim = 428,
			id = 426,
			pos = {0, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(18)) then
		self:explod {
			anim = 426,
			id = 426,
			pos = {0, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "Intro"
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0
		}
	end
end

function Cloudi:state_195()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		anim = 195,
		velSet = {0, 0},
		moveType = "I",
		physics = "S",
		sprPriority = 2,
	}
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 2}, 2}
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:playSnd {
			value = {{"S", 40}, 2}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_200()
	-- State initialization
	self:setStateParams
	{
		anim = 200,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "S",
	}
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8906,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8907,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(9)) then
		self:playSnd {
			value = {{"S", 40}, 5}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 2, 3))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 8},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9112},
			sparkXY = {-20, -30},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = -1,
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_2000()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 2000,
	}
	
	-- State controller
	if (self:animElem(3)) then
		self:velSet {
			y = -11
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 101}, 0}
		}
	end
	
	-- State controller
	if ((self:time()) == 10) then
		self:changeState {
			value = 2001,
			ctrl = 0
		}
	end
end

function Cloudi:state_2001()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		ctrl = 0,
		velSet = {0, -8},
		anim = 2001,
	}
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 15}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if ((self:animElem(3)) or (self:animElem(4))) or (((self:animElem(5)) or (self:animElem(6))) or (self:animElem(7))) then
		self:velSet {
			y = -2
		}
	end
	
	-- State controller
	if ((self:time()) >= 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {0, 2},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9113},
			sparkXY = {-40, 10},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-2, 3},
			air_velocity = {-2, 3}
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			y = 13
		}
	end
	
	-- State controller
	if (self:animElem(8)) and ((self:prevStateNo()) == 2000) then
		self:velSet {
			x = 7
		}
	end
	
	-- State controller
	if (self:animElem(8)) and ((self:prevStateNo()) ~= 2000) then
		self:velSet {
			x = 4
		}
	end
end

function Cloudi:state_2002()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "S",
		ctrl = 0,
		velSet = {0, 0},
		anim = 2002,
	}
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 14}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:explod {
			anim = 6501,
			id = 1213,
			pos = {20, -30},
			posType = "p1",
			scale = {0.6, 0.6},
			sprPriority = 5
		}
	end
	
	-- State controller
	if ((self:time()) >= 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 10,
			guardFlag = "MA",
			pauseTime = {0, 0},
			hitSound = {{"S", 21}, 1},
			guardSound = {6, 0},
			sparkNo = {"S", 9113},
			sparkXY = {-40, 10},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-1, -2},
			air_velocity = {-1, -2},
			fall = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_201()
	-- State initialization
	self:setStateParams
	{
		anim = 201,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:playSnd {
			value = {{"S", 40}, 4}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 3, 4))},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8901,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "SA"},
			damage = {60, 10},
			animType = "Heavy",
			guardFlag = "MA",
			priority = {4, "Hit"},
			pauseTime = {6, 8},
			sparkNo = {"S", 9115},
			sparkXY = {-20, -30},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			ground_type = "High",
			ground_slideTime = 6,
			ground_hitTime = 14,
			ground_velocity = {-1, -8},
			airGuard_velocity = {-1.9, -.8},
			air_type = "High",
			air_velocity = {-1.4, -5},
			air_hitTime = 12,
			ground_cornerPush_veloff = -8,
			air_cornerPush_veloff = 0,
			airGuard_cornerPush_velOff = 0,
			fall = 1,
			guard_pauseTime = {3, 5}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:velSet {
			ignoreHitPause = 1,
			x = 4
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:velSet {
			ignoreHitPause = 1,
			x = 1
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:velSet {
			ignoreHitPause = 1,
			x = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_202()
	-- State initialization
	self:setStateParams
	{
		anim = 202,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8902,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 5
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 3
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			x = 1
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 4, 6))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 8},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9112},
			sparkXY = {-20, -30},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = -2,
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_203()
	-- State initialization
	self:setStateParams
	{
		anim = 203,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "S",
	}
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8904,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8905,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:velSet {
			x = 6
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 6, 7))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {5, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-20, -30},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -5},
			air_velocity = {-2, -3},
			fall = 1,
			fall_recover = 0
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "",
			pauseTime = {5, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			numhits = 1,
			sparkNo = {"S", 9113},
			sparkXY = {-45, -21},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-3, 14},
			air_velocity = {-2, 1},
			fall = 1
		}
	end
	
	-- State controller
	if (self:animElem(13)) then
		self:posAdd {
			x = 14
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_204()
	-- State initialization
	self:setStateParams
	{
		anim = 203,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "S",
	}
	
	-- State controller
	if ((self:time()) == 30) then
		self:explod {
			persistent = 12,
			anim = 425,
			id = 2323,
			facing = -1,
			pos = {70, -13},
			posType = "p1",
			sprPriority = 5,
			scale = {0.28, 0.28}
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8904,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8905,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:velSet {
			x = 6
		}
	end
	
	-- State controller
	if (self:animElem(11)) then
		self:playSnd {
			value = {{"S", 40}, 3}
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 5, 4))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {5, 2},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-20, -30},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -5},
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "",
			pauseTime = {5, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			numhits = 1,
			sparkNo = {"S", 9113},
			sparkXY = {-45, -21},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-3, 14},
			air_velocity = {-2, 14},
			fall = 1
		}
	end
	
	-- State controller
	if (self:animElem(13)) then
		self:posAdd {
			x = 14
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_206()
	-- State initialization
	self:setStateParams
	{
		anim = 204,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "S",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8903,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:playSnd {
			value = {{"S", 40}, 2}
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 2, 4))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 8},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9116},
			sparkXY = {-30, -30},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = -3,
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:posAdd {
			x = 10
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_300()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 300,
	}
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 15}, 0},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 301
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:playSnd {
			value = {{"S", 100}, 0}
		}
	end
end

function Cloudi:state_301()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 302,
	}
	
	-- State controller
	if ((((self:animElem(2)) or (self:animElem(10))) or (self:animElem(18))) or (self:animElem(26))) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:explod {
			anim = 9105,
			id = 2323,
			pos = {18, -35},
			bindTime = -1,
			scale = {0.9, 0.9},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:velSet {
			x = 1,
			y = -1.5
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:posAdd {
			x = 12,
			y = -30
		}
	end
	
	-- State controller
	if ((self:time()) >= 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 20,
			guardFlag = "MA",
			pauseTime = {0, 0},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9117},
			sparkXY = {-20, -30},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-1, -4},
			air_velocity = {-1, -4}
		}
	end
	
	-- State controller
	if (self:animElem(22)) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 302,
			ctrl = 1
		}
	end
end

function Cloudi:state_302()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		velSet = {0, 0},
		ctrl = 1,
		anim = 303,
	}
end

function Cloudi:state_305()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		ctrl = 0,
		velSet = {-1, -3},
		anim = 304,
	}
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 15}, 0},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 306
		}
	end
end

function Cloudi:state_306()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		ctrl = 0,
		anim = 302,
	}
	
	-- State controller
	if ((((self:animElem(2)) or (self:animElem(10))) or (self:animElem(18))) or (self:animElem(26))) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:velSet {
			x = 5,
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:explod {
			anim = 9105,
			id = 2323,
			pos = {18, -35},
			bindTime = -1,
			scale = {0.9, 0.9},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) >= 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 18,
			guardFlag = "MA",
			pauseTime = {0, 0},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9117},
			sparkXY = {-20, -30},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {-3, -2},
			air_velocity = {-3, -2}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 307,
			ctrl = 1
		}
	end
	
	-- State controller
	if (self:animElem(22)) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_307()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		velSet = {0, 0},
		ctrl = 1,
		anim = 303,
	}
end

function Cloudi:state_400()
	-- State initialization
	self:setStateParams
	{
		anim = 400,
		ctrl = 0,
		stateType = "C",
		moveType = "A",
		physics = "C",
		faceP2 = 1,
	}
	
	-- State controller
	if (self:animElem(3)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8902,
			id = 101,
			pos = {6, 17},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1},
			volume = 0,
			channel = -1,
			freqMul = 1,
			loop = 0,
			pan = 0
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:varRandom {
			v = 3,
			range = {0, 1}
		}
	end
	
	-- State controller
	if ((self.var[3]) == 1) and (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, 2},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"C", "NA"},
			damage = 30,
			guardFlag = "A",
			pauseTime = {8, 6},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9112},
			sparkXY = {-20, -14},
			animType = "medium",
			ground_type = "low",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = -1,
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) and (self:command("holddown")) then
		self:changeState {
			value = 11,
			ctrl = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_410()
	-- State initialization
	self:setStateParams
	{
		anim = 410,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 5
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 1
		}
	end
	
	-- State controller
	if (self:animElem(9)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:playSnd {
			value = {{"S", 100}, 3}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 2, 3))},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			anim = 426,
			id = 426,
			pos = {0, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -10},
			posType = "p1",
			bindTime = 1,
			scale = {0.2, 0.2},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 420,
			id = 410,
			pos = {30, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 420,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9110},
			sparkXY = {40, -60},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-1, -2},
			air_velocity = {-1, -2}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:varSet {
			v = 11,
			value = 0
		}
	end
	
	-- State controller
	if (((((self:command("holdback")) and (self:command("y"))) and ((self:time()) > 1)) and ((self:time()) <= 18)) and ((self.var[11]) == 0)) then
		self:varSet {
			v = 11,
			value = 3
		}
	end
	
	-- State controller
	if ((((self:command("holdback")) and (self:command("y"))) and ((self:time()) > 18)) and ((self.var[11]) == 0)) then
		self:varSet {
			v = 11,
			value = 1
		}
	end
	
	-- State controller
	if (((self:time()) > 21) and ((self.var[11]) == 1)) then
		self:changeState {
			value = 411
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_411()
	-- State initialization
	self:setStateParams
	{
		anim = 411,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {240, 50, 0},
			mul = {250, 224, 120},
			sinAdd = {110, 55, 85, 10},
			invertAll = 0,
			color = 0
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:velSet {
			x = 6
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 100}, 2}
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:explod {
			anim = 427,
			id = 427,
			pos = {-10, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -15},
			posType = "p1",
			bindTime = 1,
			scale = {0.25, 0.25},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 4, 5))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:animElem(5)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 421,
			id = 410,
			pos = {10, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(5)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 421,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9110},
			sparkXY = {40, -60},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-.4, -4},
			air_velocity = {-.4, -4}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:varSet {
			v = 11,
			value = 0
		}
	end
	
	-- State controller
	if (((((self:command("holdback")) and (self:command("y"))) and ((self:time()) > 1)) and ((self:time()) <= 17)) and ((self.var[11]) == 0)) then
		self:varSet {
			v = 11,
			value = 3
		}
	end
	
	-- State controller
	if (((self:command("holdback")) and (self:command("y"))) and ((self:time()) > 17)) then
		self:varSet {
			v = 11,
			value = 1
		}
	end
	
	-- State controller
	if (((self:time()) > 20) and ((self.var[11]) == 1)) then
		self:changeState {
			value = 412
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_412()
	-- State initialization
	self:setStateParams
	{
		anim = 412,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {240, 50, 0},
			mul = {250, 224, 120},
			sinAdd = {110, 55, 85, 10},
			invertAll = 0,
			color = 0
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 8
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 5) then
		self:playSnd {
			value = {{"S", 100}, 3}
		}
	end
	
	-- State controller
	if ((self:time()) == 31) then
		self:playSnd {
			value = {{"S", 100}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 11}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 428,
			id = 428,
			pos = {-10, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -15},
			posType = "p1",
			bindTime = 1,
			scale = {0.3, 0.3},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 422,
			id = 410,
			pos = {10, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 422,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if (self:moveHit()) then
		self:bgPalFX {
			persistent = 22,
			time = 5,
			add = {255, 255, 255},
			mul = {256, 256, 256},
			sinAdd = {255, 255, 255, 10}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 12},
			hitSound = {{"S", 21}, 1},
			guardSound = {6, 0},
			sparkNo = {"S", 9110},
			sparkXY = {40, -60},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-.3, -7},
			air_velocity = {-.3, -7},
			fall = 1,
			fall_envShake_phase = 888
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_420()
	-- State initialization
	self:setStateParams
	{
		anim = 410,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 5
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 1
		}
	end
	
	-- State controller
	if (self:animElem(9)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:playSnd {
			value = {{"S", 100}, 3}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 2, 3))},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			anim = 426,
			id = 426,
			pos = {0, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -10},
			posType = "p1",
			bindTime = 1,
			scale = {0.2, 0.2},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 420,
			id = 410,
			pos = {30, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 420,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkXY = {-10, -25},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-1, -2},
			air_velocity = {-1, -2}
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:varSet {
			v = 11,
			value = 0
		}
	end
	
	-- State controller
	if (self:moveHit()) then
		self:varSet {
			v = 11,
			value = 1
		}
	end
	
	-- State controller
	if (((self:time()) > 21) and ((self.var[11]) == 1)) then
		self:changeState {
			value = 421
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_421()
	-- State initialization
	self:setStateParams
	{
		anim = 411,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {240, 50, 0},
			mul = {250, 224, 120},
			sinAdd = {110, 55, 85, 10},
			invertAll = 0,
			color = 0
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:velSet {
			x = 6
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:playSnd {
			value = {{"S", 100}, 2}
		}
	end
	
	-- State controller
	if (self:animElem(4)) then
		self:explod {
			anim = 427,
			id = 427,
			pos = {-10, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -15},
			posType = "p1",
			bindTime = 1,
			scale = {0.25, 0.25},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) >= 499), 4, 5))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:animElem(5)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 421,
			id = 410,
			pos = {10, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(5)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 421,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 10},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkXY = {-10, -25},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-.4, -4},
			air_velocity = {-.4, -4}
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:changeState {
			value = 422
		}
	end
end

function Cloudi:state_422()
	-- State initialization
	self:setStateParams
	{
		anim = 412,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {240, 50, 0},
			mul = {250, 224, 120},
			sinAdd = {110, 55, 85, 10},
			invertAll = 0,
			color = 0
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 8
		}
	end
	
	-- State controller
	if (self:animElem(8)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 5) then
		self:playSnd {
			value = {{"S", 100}, 3}
		}
	end
	
	-- State controller
	if ((self:time()) == 31) then
		self:playSnd {
			value = {{"S", 100}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 11}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 428,
			id = 428,
			pos = {-10, 0},
			posType = "p1",
			bindTime = -1,
			sprPriority = 5,
			facing = -1,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:explod {
			anim = 425,
			id = 425,
			pos = {-30, -15},
			posType = "p1",
			bindTime = 1,
			scale = {0.3, 0.3},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == 1)) then
		self:explod {
			anim = 422,
			id = 410,
			pos = {10, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = 1
		}
	end
	
	-- State controller
	if ((self:animElem(6)) and ((self:facing()) == -1)) then
		self:explod {
			anim = 422,
			id = 410,
			pos = {90, -30},
			posType = "p1",
			bindTime = 1,
			scale = {0.5, 0.5},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1,
			facing = -1
		}
	end
	
	-- State controller
	if (self:moveHit()) then
		self:bgPalFX {
			persistent = 22,
			time = 5,
			add = {255, 255, 255},
			mul = {256, 256, 256},
			sinAdd = {255, 255, 255, 10}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 12},
			hitSound = {{"S", 21}, 1},
			guardSound = {6, 0},
			sparkXY = {-10, -25},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 14,
			ground_velocity = {-.3, -7},
			air_velocity = {-.3, -7},
			fall = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:posAdd {
			x = -7
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_500()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "S",
		ctrl = 0,
		anim = 500,
	}
	
	-- State controller
	if ((self:time()) == 12) then
		self:explod {
			anim = 425,
			id = 2323,
			pos = {0, -15},
			posType = "p1",
			sprPriority = 5,
			scale = {0.28, 0.28}
		}
	end
	
	-- State controller
	if ((self:time()) == 12) then
		self:explod {
			anim = 6600,
			id = 2323,
			pos = {0, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if ((self:time()) == 15) then
		self:explod {
			anim = 6600,
			id = 23236,
			pos = {0, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if ((self:time()) == 21) then
		self:explod {
			anim = 6600,
			id = 23236,
			pos = {0, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 16}, 0},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:velSet {
			x = 17
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 3
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:afterImage {
			time = 7,
			length = 9,
			palBright = {10, 10, 10},
			palContrast = {120, 120, 120},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 1,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 80,
			guardFlag = "MA",
			pauseTime = {0, 29},
			guard_pauseTime = {0, 5},
			hitSound = {0, 0},
			guardSound = {6, 0},
			sparkNo = 6600,
			sparkXY = {-20, -5},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -4},
			air_velocity = {0, -4},
			fall = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 40) and (self:moveHit()) then
		self:explod {
			anim = 9110,
			id = 232336,
			pos = {-40, -60},
			posType = "p2",
			sprPriority = 5,
			scale = {0.8, 0.8}
		}
	end
	
	-- State controller
	if ((self:time()) == 40) and (self:moveHit()) then
		self:playSnd {
			value = {{"S", 100}, 1}
		}
	end
	
	-- State controller
	if (((self:time()) > 13) and ((self:time()) < 23)) then
		self:playerPush {
			value = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_5000()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:getHitVar("animtype")), "[", 3, 5, "]")) then
		self:changeAnim {
			value = ((self:ifElse(((self:getHitVar("groundtype")) == 1), 5000, 5010)) + (self:getHitVar("animtype")))
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and (Utils.inInterval((self:getHitVar("animtype")), "[", 3, 5, "]")) then
		self:changeAnim {
			value = 5030
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((Utils.inInterval((self:getHitVar("animtype")), "[", 4, 5, "]")) and (self:selfAnimExist((5047 + (self:getHitVar("animtype")))))) then
		self:changeAnim {
			value = (5047 + (self:getHitVar("animtype")))
		}
	end
	
	-- State controller
	if ((self:time()) > 0) then
		self:changeAnim {
			value = (self:anim())
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and (((self:getHitVar("yvel")) ~= 0) or (self:getHitVar("fall"))) or ((self:pos().y) ~= 0) then
		self:stateTypeSet {
			stateType = "a"
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) and (((self:getHitVar("yvel")) == 0) and not (self:getHitVar("fall"))) then
		self:changeState {
			value = 5001
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = 5030
		}
	end
	
	-- State controller
	if ((self:anim()) == 5000) or ((self:anim()) == 5010) then
		self:forceFeedback {
			persistent = 0,
			time = 6,
			waveForm = "square"
		}
	end
	
	-- State controller
	if ((self:anim()) == 5001) or ((self:anim()) == 5011) then
		self:forceFeedback {
			persistent = 0,
			time = 8,
			waveForm = "sinesquare",
			ampl = {110, -1, -.3}
		}
	end
	
	-- State controller
	if ((self:anim()) == 5012) or ((self:anim()) == 5002) or ((self:anim()) == 5030) then
		self:forceFeedback {
			persistent = 0,
			time = 15,
			waveForm = "sinesquare",
			ampl = 140
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:varRandom {
			v = 5,
			range = {1, 4}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) and ((self.var[5]) == 1) then
		self:playSnd {
			value = {{"S", 5}, 0}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) and ((self.var[5]) == 2) then
		self:playSnd {
			value = {{"S", 5}, 1}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) and ((self.var[5]) == 3) then
		self:playSnd {
			value = {{"S", 5}, 2}
		}
	end
end

function Cloudi:state_50000()
	-- State initialization
	self:setStateParams
	{
		moveType = "I",
		physics = "N",
		velSet = {0, 0},
		sprPriority = -1,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:removeExplod {
			id = -1
		}
	end
	
	-- State controller
	if 1 then
		self:playerPush {
			value = 0
		}
	end
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = {"SCA", "NA", "SA", "HA", "NP", "SP", "HP", "NT", "ST", "HT"},
			time = 1
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "invisible"
		}
	end
	
	-- State controller
	if ((self:id()) ~= (self.var[40])) and ((self:getPlayerID((self.var[40])):stateNo()) == 45000) or ((self:id()) ~= (self.var[41])) and ((self:getPlayerID((self.var[41])):stateNo()) == 45000) or ((self:id()) ~= (self.var[42])) and ((self:getPlayerID((self.var[42])):stateNo()) == 45000) or ((self:id()) ~= (self.var[43])) and ((self:getPlayerID((self.var[43])):stateNo()) == 45000) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_510()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		velSet = {-3, 0},
		ctrl = 0,
		anim = 510,
	}
	
	-- State controller
	if (((self:time()) > 13) and ((self:time()) < 23)) then
		self:playerPush {
			value = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 17) then
		self:explod {
			anim = 6600,
			id = 2323,
			pos = {10, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if ((self:time()) == 20) then
		self:explod {
			anim = 6600,
			id = 23236,
			pos = {10, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if ((self:time()) == 24) then
		self:explod {
			anim = 6600,
			id = 23236,
			pos = {10, -20},
			posType = "p1",
			sprPriority = 5,
			scale = {0.7, 0.6}
		}
	end
	
	-- State controller
	if (self:animElem(1)) then
		self:playSnd {
			value = {{"S", 16}, 0},
			channel = 0
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:velSet {
			x = 17
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:velSet {
			x = 3
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 2
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:afterImage {
			time = 7,
			length = 9,
			palBright = {10, 10, 10},
			palContrast = {120, 120, 120},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 1,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 80,
			guardFlag = "MA",
			pauseTime = {0, 5},
			guardSound = {6, 0},
			hitSound = {{"S", 100}, 1},
			sparkNo = {"S", 9100},
			sparkXY = {30, -60},
			animType = "hard",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -4},
			air_velocity = {0, -4},
			fall = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:stateTypeSet {
			physics = "A",
			stateType = "A"
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if (((self:animTime()) == 0) and ((self:p2Dist().x) < 0)) then
		self:turn {
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeAnim {
			value = 45,
			elem = 3
		}
	end
end

function Cloudi:state_600()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		juggle = 2,
		powerAdd = 11,
		ctrl = 0,
		anim = 600,
	}
	
	-- State controller
	if ((self:animElem(1)) and ((self:prevStateNo()) == 201)) then
		self:velSet {
			x = 1,
			y = -9
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8908,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8909,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1},
			volume = 0,
			channel = -1,
			freqMul = 1,
			loop = 0,
			pan = 0
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:varRandom {
			v = 3,
			range = {0, 1}
		}
	end
	
	-- State controller
	if ((self.var[3]) == 1) and (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, 2},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {10, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-20, -30},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -3},
			air_velocity = {0, -2}
		}
	end
	
	-- State controller
	if ((self:time()) == 20) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_601()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		juggle = 2,
		velSet = {0, -2},
		powerAdd = 11,
		ctrl = 0,
		anim = 601,
	}
	
	-- State controller
	if (self:animElem(5)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8905,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1},
			volume = 0,
			channel = -1,
			freqMul = 1,
			loop = 0,
			pan = 0
		}
	end
	
	-- State controller
	if (self:animElem(5)) then
		self:velSet {
			x = 0,
			y = -4
		}
	end
	
	-- State controller
	if ((self:animElem(2)) and ((self:prevStateNo()) < 200)) then
		self:playSnd {
			value = {{"S", 20}, 4},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:animElem(2)) and ((self:prevStateNo()) > 200)) then
		self:playSnd {
			value = {{"S", 15}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {10, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9113},
			sparkXY = {-45, -21},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, 21},
			air_velocity = {0, 21},
			fall = 4
		}
	end
	
	-- State controller
	if ((self:time()) == 40) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_602()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "A",
		juggle = 2,
		powerAdd = 11,
		ctrl = 0,
		anim = 602,
	}
	
	-- State controller
	if (self:animElem(3)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8910,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8911,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1},
			volume = 0,
			channel = -1,
			freqMul = 1,
			loop = 0,
			pan = 0
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:varRandom {
			v = 3,
			range = {0, 1}
		}
	end
	
	-- State controller
	if ((self.var[3]) == 1) and (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, 2},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) >= 0) then
		self:hitDef {
			persistent = 5,
			attr = {"S", "NA"},
			damage = 10,
			guardFlag = "MA",
			pauseTime = {10, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", (self:ifElse(((self:random()) > 499), 9112, 9115))},
			sparkXY = {-20, -30},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -4},
			air_velocity = {0, -4}
		}
	end
	
	-- State controller
	if ((self:time()) == 20) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_603()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "A",
		physics = "N",
		juggle = 2,
		velSet = {((self:vel().x) / 2), -2},
		powerAdd = 11,
		ctrl = 0,
		anim = 603,
	}
	
	-- State controller
	if (self:animElem(6)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8914,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 3) then
		self:velSet {
			x = ((self:vel().x) / 2),
			y = -1
		}
	end
	
	-- State controller
	if (self:animElem(7)) then
		self:velSet {
			x = 4,
			y = -9
		}
	end
	
	-- State controller
	if (self:animElem(9)) then
		self:velSet {
			x = 2,
			y = -3
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:velSet {
			x = 0.5,
			y = -1
		}
	end
	
	-- State controller
	if (self:animElem(11)) then
		self:stateTypeSet {
			physics = "A"
		}
	end
	
	-- State controller
	if ((self:time()) == 6) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, (self:ifElse(((self:random()) > 499), 4, 7))},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {10, 5},
			hitSound = {{"S", 21}, (self:ifElse(((self:random()) > 499), 0, 1))},
			guardSound = {6, 0},
			sparkNo = {"S", 9114},
			sparkXY = {-45, -36},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 12,
			ground_velocity = {0, -6},
			air_velocity = {0, -6}
		}
	end
	
	-- State controller
	if ((self:time()) == 40) then
		self:ctrlSet {
			value = 1
		}
	end
end

function Cloudi:state_622()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "A",
		physics = "S",
		ctrl = 0,
		anim = 622,
	}
	
	-- State controller
	if ((self.var[4]) <= 2) then
		self:varAdd {
			v = 4,
			value = 1
		}
	end
	
	-- State controller
	if ((self.var[4]) >= 3) then
		self:varSet {
			v = 4,
			value = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_888()
	-- State initialization
	self:setStateParams
	{
		anim = 888,
		ctrl = 0,
		stateType = "S",
		moveType = "A",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:animElem(2)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8912,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = 5,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:explod {
			ignoreHitPause = 0,
			anim = 8913,
			id = 101,
			pos = {0, 0},
			bindTime = -1,
			sprPriority = -1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if (self:animElem(1)) or (self:animElem(9)) then
		self:velSet {
			x = 5
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:velSet {
			x = 3
		}
	end
	
	-- State controller
	if (self:animElem(5)) or (self:animElem(10)) then
		self:velSet {
			x = 1.5
		}
	end
	
	-- State controller
	if (self:animElem(7)) or (self:animElem(11)) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 6) or ((self:time()) == 26) then
		self:playSnd {
			value = {{"S", 20}, 1}
		}
	end
	
	-- State controller
	if (self:animElem(2)) then
		self:varRandom {
			v = 3,
			range = {0, 1}
		}
	end
	
	-- State controller
	if ((self.var[3]) == 1) and (self:animElem(2)) then
		self:playSnd {
			value = {{"S", 20}, 2}
		}
	end
	
	-- State controller
	if (self:animElem(3)) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 8},
			hitSound = {{"S", 21}, 1},
			guardSound = {6, 0},
			sparkNo = {"S", 9112},
			sparkXY = {-20, -30},
			animType = "medium",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 16,
			ground_velocity = {-1, -3},
			air_velocity = {-2, -3}
		}
	end
	
	-- State controller
	if (self:animElem(10)) then
		self:hitDef {
			attr = {"S", "NA"},
			damage = 30,
			guardFlag = "MA",
			pauseTime = {6, 9},
			hitSound = {{"S", 21}, 0},
			guardSound = {6, 0},
			sparkNo = {"S", 9115},
			sparkXY = {-30, -30},
			animType = "heavy",
			ground_type = "High",
			ground_slideTime = 5,
			ground_hitTime = 16,
			ground_velocity = {-3, 3},
			air_velocity = {-3, 3}
		}
	end
	
	-- State controller
	if ((self:moveHit()) and ((self:time()) > 26)) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

Cloudi.m_constants["data"] = {
	["life"] = 1000,
	["power"] = 3000,
	["attack"] = 80,
	["defence"] = 100,
	["fall.defence_up"] = 50,
	["liedown.time"] = 60,
	["airjuggle"] = 15,
	["sparkno"] = 2,
	["guard.sparkno"] = 40,
	["ko.echo"] = 0,
	["volume"] = 0,
	["intpersistindex"] = 57,
	["floatpersistindex"] = 40
}

Cloudi.m_constants["movement"] = {
	["airjump.num"] = 1,
	["airjump.height"] = 35,
	["yaccel"] = .44,
	["stand.friction"] = .85,
	["crouch.friction"] = .82
}

Cloudi.m_constants["size"] = {
	["xscale"] = 1,
	["yscale"] = 1,
	["ground.back"] = 15,
	["ground.front"] = 16,
	["air.back"] = 12,
	["air.front"] = 12,
	["height"] = 60,
	["attack.dist"] = 160,
	["proj.attack.dist"] = 90,
	["proj.doscale"] = 0,
	["head.pos"] = {-5, -90},
	["mid.pos"] = {-5, -60},
	["shadowoffset"] = 0,
	["draw.offset"] = {0, 0}
}

Cloudi.m_constants["velocity"] = {
	["walk.fwd"] = 1.6,
	["walk.back"] = -1.0,
	["run.fwd"] = {3.2, 0},
	["run.back"] = {-3.5, -3.2},
	["jump.neu"] = {0, -7.4},
	["jump.back"] = -2.55,
	["jump.fwd"] = 2.5,
	["runjump.back"] = {-2.55, -7.1},
	["runjump.fwd"] = {4, -7.8},
	["airjump.neu"] = {0, -7.1},
	["airjump.back"] = -2.55,
	["airjump.fwd"] = 2.5
}

function Cloudi:state_m2()
	-- State initialization
	self:setStateParams
	{
	}
	
	-- State controller
	if (((self:life()) <= ((self:lifeMax()) / 5)) and not (self:numHelper(20500))) then
		self:helper {
			helperType = "normal",
			name = "critic",
			id = 20500,
			stateNo = 20500,
			pos = {0, 0},
			posType = "p1",
			facing = 1,
			keyCtrl = 0,
			ownPal = 1
		}
	end
	
	-- State controller
	if not (self:numHelper(20000)) then
		self:helper {
			helperType = "normal",
			name = "powerbar",
			id = 20000,
			stateNo = 20000,
			pos = {0, -10000},
			posType = "p1",
			facing = 1,
			keyCtrl = 0,
			ownPal = 1
		}
	end
	
	-- State controller
	if not (self:numHelper(21000)) then
		self:helper {
			helperType = "normal",
			name = "munico",
			id = 21000,
			stateNo = 21000,
			pos = {(self:ifElse(((self:teamSide()) == 1), 49, 271)), 46},
			posType = "left",
			facing = 1,
			keyCtrl = 0,
			ownPal = 1
		}
	end
	
	-- State controller
	if ((self:teamMode() == "single") and (self:getEnemy():teamMode() == "single")) then
		if (not (self:numHelper(30000)) and (self:alive())) then
			self:helper {
				helperType = "normal",
				name = "ranker",
				id = 30000,
				stateNo = 30000,
				pos = {0, -10000},
				posType = "p1",
				facing = 1,
				keyCtrl = 0,
				ownPal = 1
			}
		end
	end
	
	-- State controller
	if ((self:stateNo()) >= 5000) then
		self:afterImageTime {
			time = 1
		}
	end
	
	-- State controller
	if not (self:alive()) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and (Utils.inInterval((self:getPlayerID((self.var[40])):stateNo()), "[", 40000, 44000, "]")) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and (Utils.inInterval((self:getPlayerID((self.var[41])):stateNo()), "[", 40000, 44000, "]")) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and (Utils.inInterval((self:getPlayerID((self.var[42])):stateNo()), "[", 40000, 44000, "]")) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and (Utils.inInterval((self:getPlayerID((self.var[43])):stateNo()), "[", 40000, 44000, "]")) then
			self:assertSpecial {
				flag = "invisible"
			}
		end
	end
	
	-- State controller
	if (not Utils.inInterval((self:stateNo()), "[", 40005, 40100, "]")) and (self:alive()) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and ((self:getPlayerID((self.var[40])):stateNo()) == 40000) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and ((self:getPlayerID((self.var[41])):stateNo()) == 40000) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and ((self:getPlayerID((self.var[42])):stateNo()) == 40000) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and ((self:getPlayerID((self.var[43])):stateNo()) == 40000) then
			self:changeState {
				value = 50000,
				ctrl = 0
			}
		end
	end
	
	-- State controller
	if ((self:numTarget()) > 0) then
		if ((self:getTarget():getHitVar("hitcount")) > (self.var[34])) then
			self:varSet {
				v = 34,
				value = (self:getTarget():getHitVar("hitcount"))
			}
		end
	end
	
	-- State controller
	if 1 then
		self:displayToClipboard {
			text = "%d",
			params = (self.var[39])
		}
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self.var[36]) == 0) and ((self:life()) == (self:lifeMax())) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and (((self:getPlayerID((self.var[40])):life()) < (self:getPlayerID((self.var[40])):lifeMax())) and ((self:getPlayerID((self.var[40])).var[36]) == 0)) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and (((self:getPlayerID((self.var[41])):life()) < (self:getPlayerID((self.var[41])):lifeMax())) and ((self:getPlayerID((self.var[41])).var[36]) == 0)) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and (((self:getPlayerID((self.var[42])):life()) < (self:getPlayerID((self.var[42])):lifeMax())) and ((self:getPlayerID((self.var[42])).var[36]) == 0)) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and (((self:getPlayerID((self.var[43])):life()) < (self:getPlayerID((self.var[43])):lifeMax())) and ((self:getPlayerID((self.var[43])).var[36]) == 0)) then
			self:varAdd {
				v = 39,
				value = 750
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self.var[36]) == 0) and ((self:life()) == (self:lifeMax())) and ((self:numExplod(23000)) == 0) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and (((self:getPlayerID((self.var[40])):life()) < (self:getPlayerID((self.var[40])):lifeMax())) and ((self:getPlayerID((self.var[40])).var[36]) == 0)) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and (((self:getPlayerID((self.var[41])):life()) < (self:getPlayerID((self.var[41])):lifeMax())) and ((self:getPlayerID((self.var[41])).var[36]) == 0)) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and (((self:getPlayerID((self.var[42])):life()) < (self:getPlayerID((self.var[42])):lifeMax())) and ((self:getPlayerID((self.var[42])).var[36]) == 0)) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and (((self:getPlayerID((self.var[43])):life()) < (self:getPlayerID((self.var[43])):lifeMax())) and ((self:getPlayerID((self.var[43])).var[36]) == 0)) then
			self:explod {
				ignoreHitPause = 1,
				anim = {"F", (self:ifElse(((self:teamSide()) == 1), 3100, 3101))},
				id = 23000,
				pos = {(self:ifElse(((self:teamSide()) == 1), 40, 330)), (((110 + (self:ifElse(((self:numExplod(23100)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23200)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23300)) == 0), 0, 12)))},
				posType = "left",
				facing = 1,
				bindTime = -1,
				sprPriority = 5,
				onTop = 1,
				ownPal = 1,
				superMoveTime = 999999999
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self.var[36]) == 0) and ((self:life()) == (self:lifeMax())) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and ((self:getPlayerID((self.var[40])):life()) < (self:getPlayerID((self.var[40])):lifeMax())) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and ((self:getPlayerID((self.var[41])):life()) < (self:getPlayerID((self.var[41])):lifeMax())) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and ((self:getPlayerID((self.var[42])):life()) < (self:getPlayerID((self.var[42])):lifeMax())) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and ((self:getPlayerID((self.var[43])):life()) < (self:getPlayerID((self.var[43])):lifeMax())) then
			self:varSet {
				v = 36,
				value = 1
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (Utils.inInterval((self:prevStateNo()), "[", 120, 159, "]")) and (((self:moveHit()) and ((self:moveContact()) == 1)) and ((self:hitCount()) == 1)) then
			self:varAdd {
				v = 39,
				value = 250
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self:numExplod(23100)) == 0) then
		if (Utils.inInterval((self:prevStateNo()), "[", 120, 159, "]")) and ((self:moveHit()) and ((self:hitCount()) == 1)) then
			self:explod {
				ignoreHitPause = 1,
				anim = {"F", (self:ifElse(((self:teamSide()) == 1), 3110, 3111))},
				id = 23100,
				pos = {(self:ifElse(((self:teamSide()) == 1), 40, 330)), ((((110 + (self:ifElse(((self:numExplod(23000)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23200)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23300)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23400)) == 0), 0, 12)))},
				posType = "left",
				facing = 1,
				bindTime = -1,
				sprPriority = 5,
				onTop = 1,
				ownPal = 1,
				superMoveTime = 999999999
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (Utils.inInterval((self:stateNo()), "[", 3000, 3700, "]")) and ((((((((((self:prevStateNo()) == 200) or ((self:prevStateNo()) == 201)) or ((self:prevStateNo()) == 202)) or ((self:prevStateNo()) == 206)) or ((self:prevStateNo()) == 888)) or ((self:prevStateNo()) == 601)) or ((self:prevStateNo()) == 602)) or ((self:prevStateNo()) == 603)) or ((self:prevStateNo()) == 600)) and (self:animElem(2)) then
			self:varAdd {
				v = 39,
				value = 500
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (((self:getEnemy():numHelper(20800)) ~= 0) and (((self:time()) % 10) == 0)) then
			self:varAdd {
				v = 39,
				value = 500
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self:numExplod(23200)) == 0) then
		if (Utils.inInterval((self:stateNo()), "[", 3000, 3700, "]")) and ((((((((((self:prevStateNo()) == 200) or ((self:prevStateNo()) == 201)) or ((self:prevStateNo()) == 202)) or ((self:prevStateNo()) == 206)) or ((self:prevStateNo()) == 888)) or ((self:prevStateNo()) == 601)) or ((self:prevStateNo()) == 602)) or ((self:prevStateNo()) == 603)) or ((self:prevStateNo()) == 600)) and (self:animElem(2)) then
			self:explod {
				ignoreHitPause = 1,
				anim = {"F", (self:ifElse(((self:teamSide()) == 1), 3130, 3131))},
				id = 23200,
				pos = {(self:ifElse(((self:teamSide()) == 1), 40, 330)), (((110 + (self:ifElse(((self:numExplod(23000)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23100)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23300)) == 0), 0, 12)))},
				posType = "left",
				facing = 1,
				bindTime = -1,
				sprPriority = 5,
				onTop = 1,
				ownPal = 1,
				superMoveTime = 999999999
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (((self:stateNo()) == 9000) and ((self:time()) == 0)) then
			self:varAdd {
				v = 39,
				value = -1000
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (((self:getEnemy():numHelper(20800)) ~= 0) and (((self:time()) % 10) == 0)) then
			self:varAdd {
				v = 39,
				value = 200
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") then
		if (((self:stateNo()) == 9005) and ((self:animElemTime(1)) < 2)) then
			self:varAdd {
				v = 39,
				value = 200
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self:numExplod(23300)) == 0) then
		if (((self:stateNo()) == 9000) and ((self:time()) == 0)) then
			self:explod {
				ignoreHitPause = 1,
				anim = {"F", (self:ifElse(((self:teamSide()) == 1), 3120, 3121))},
				id = 23300,
				pos = {(self:ifElse(((self:teamSide()) == 1), 40, 330)), ((((110 + (self:ifElse(((self:numExplod(23000)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23100)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23200)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23400)) == 0), 0, 12)))},
				posType = "left",
				facing = 1,
				bindTime = -1,
				sprPriority = 5,
				onTop = 1,
				ownPal = 1,
				superMoveTime = 999999999
			}
		end
	end
	
	-- State controller
	if ((self:numExplod(23400)) == 0) and (self:teamMode() == "single") and (((self:stateNo()) == 45000) and ((self:animTime()) == 0)) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and ((self:getPlayerID((self.var[40])):alive()) == 0) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and ((self:getPlayerID((self.var[41])):alive()) == 0) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and ((self:getPlayerID((self.var[42])):alive()) == 0) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and ((self:getPlayerID((self.var[43])):alive()) == 0) then
			self:varAdd {
				v = 39,
				value = 10000
			}
		end
	end
	
	-- State controller
	if (self:teamMode() == "single") and ((self:numExplod(23400)) == 0) and (((self:stateNo()) == 45000) and ((self:animTime()) == 0)) then
		if (((self:id()) ~= (self.var[40])) and ((self.var[40]) ~= 0)) and ((self:getPlayerID((self.var[40])):alive()) == 0) or (((self:id()) ~= (self.var[41])) and ((self.var[41]) ~= 0)) and ((self:getPlayerID((self.var[41])):alive()) == 0) or (((self:id()) ~= (self.var[42])) and ((self.var[42]) ~= 0)) and ((self:getPlayerID((self.var[42])):alive()) == 0) or (((self:id()) ~= (self.var[43])) and ((self.var[43]) ~= 0)) and ((self:getPlayerID((self.var[43])):alive()) == 0) then
			self:explod {
				ignoreHitPause = 1,
				anim = {"F", (self:ifElse(((self:teamSide()) == 1), 3140, 3141))},
				id = 23400,
				pos = {(self:ifElse(((self:teamSide()) == 1), 40, 330)), ((((110 + (self:ifElse(((self:numExplod(23000)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23100)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23200)) == 0), 0, 12))) + (self:ifElse(((self:numExplod(23300)) == 0), 0, 12)))},
				posType = "left",
				facing = 1,
				bindTime = -1,
				sprPriority = 5,
				onTop = 1,
				ownPal = 1,
				superMoveTime = 999999999
			}
		end
	end
	
	-- State controller
	if ((self:teamMode() == "single") and ((self:roundState()) == 2)) then
		if (((((self:id()) == (self.var[40])) and ((self:playerIdExist((self.var[41]))) & ((self:getPlayerID((self.var[41])):alive()) == 1))) and ((self:playerIdExist((self.var[42]))) & ((self:getPlayerID((self.var[42])):alive()) == 1))) and ((self:playerIdExist((self.var[43]))) & ((self:getPlayerID((self.var[43])):alive()) == 1))) or (((((self:id()) == (self.var[41])) and ((self:playerIdExist((self.var[40]))) & ((self:getPlayerID((self.var[40])):alive()) == 1))) and ((self:playerIdExist((self.var[42]))) & ((self:getPlayerID((self.var[42])):alive()) == 1))) and ((self:playerIdExist((self.var[43]))) & ((self:getPlayerID((self.var[43])):alive()) == 1))) or (((((self:id()) == (self.var[42])) and ((self:playerIdExist((self.var[41]))) & ((self:getPlayerID((self.var[41])):alive()) == 1))) and ((self:playerIdExist((self.var[40]))) & ((self:getPlayerID((self.var[40])):alive()) == 1))) and ((self:playerIdExist((self.var[43]))) & ((self:getPlayerID((self.var[43])):alive()) == 1))) or (((((self:id()) == (self.var[44])) and ((self:playerIdExist((self.var[41]))) & ((self:getPlayerID((self.var[41])):alive()) == 1))) and ((self:playerIdExist((self.var[42]))) & ((self:getPlayerID((self.var[42])):alive()) == 1))) and ((self:playerIdExist((self.var[40]))) & ((self:getPlayerID((self.var[40])):alive()) == 1))) then
			self:varSet {
				v = 37,
				value = (self:getHelper(21000):time())
			}
		end
	end
	
	-- State controller
	if (not Utils.inInterval((self:stateNo()), "[", 40000, 50000, "]")) and ((self.var[58]) < 1000) then
		self:varAdd {
			v = 58,
			value = 1
		}
	end
	
	-- State controller
	if ((self:numExplod(32710)) and ((self:stateNo()) ~= 31310)) then
		self:explod {
			anim = {"F", 32713},
			id = 32711,
			pos = {0, -25},
			posType = "p1",
			bindTime = 1,
			sprPriority = 5,
			scale = {1, 1}
		}
	end
	
	-- State controller
	if ((self:numExplod(32710)) and ((self:stateNo()) ~= 31310)) then
		self:playSnd {
			value = {{"F", 30126}, 0}
		}
	end
	
	-- State controller
	if ((self:numExplod(32710)) and ((self:stateNo()) ~= 31310)) then
		self:removeExplod {
			id = 32710
		}
	end
	
	-- State controller
	if (not (self:numExplod(329120)) and ((self:prevStateNo()) == 31520)) then
		self:playSnd {
			value = {{"F", 5001}, 0}
		}
	end
	
	-- State controller
	if (not (self:numExplod(329120)) and ((self:prevStateNo()) == 31520)) then
		self:palFX {
			time = 1,
			add = {0, 0, 0},
			mul = {256, 256, 256},
			invertAll = 0,
			color = 256
		}
	end
	
	-- State controller
	if (not (self:numExplod(329120)) and ((self:prevStateNo()) == 31520)) then
		self:explod {
			anim = {"F", 32912},
			id = 329120,
			pos = {0, -20},
			posType = "p1",
			bindTime = 1,
			sprPriority = 5
		}
	end
	
	-- State controller
	if ((self:getHitVar("damage")) and ((self:prevStateNo()) == 31520)) then
		self:lifeAdd {
			value = -(self:getHitVar("damage")),
			kill = 1,
			absolute = 0
		}
	end
	
	-- State controller
	if (((self:getHitVar("chainid")) == 999) and (Utils.inInterval((self:stateNo()), "[", 120, 169, "]"))) then
		self:varSet {
			fv = 14,
			value = 20
		}
	end
	
	-- State controller
	if ((self:numHelper(36614)) > 0) then
		self:lifeAdd {
			value = (self:floor(((self:getHitVar("damage")) / 2))),
			kill = 1,
			absolute = 0
		}
	end
	
	-- State controller
	if (((self:numHelper(36614)) > 0) and (Utils.inInterval((self:stateNo()), "[", 5000, 5050, "]"))) and (((self:numExplod(34810)) == 0) and ((self:time()) == 0)) then
		self:playSnd {
			persistent = 22,
			value = {{"F", 30146}, 1}
		}
	end
	
	-- State controller
	if (((self:numHelper(36614)) > 0) and (Utils.inInterval((self:stateNo()), "[", 5000, 5050, "]"))) and (((self:numExplod(34810)) == 0) and ((self:time()) == 0)) then
		self:explod {
			persistent = 22,
			anim = {"F", 34810},
			id = 34810,
			pos = {20, -25},
			posType = "p1",
			bindTime = 1,
			sprPriority = 5
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:numHelper(32899))) or (((self:roundState()) == 2) and (self:getEnemy():numHelper(32898))) then
		self:lifeAdd {
			value = 50,
			kill = 0
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:numHelper(32897))) then
		self:varAdd {
			value = (self:ifElse(((self:getHelper(32897).var[11]) == 0), 10, (self:ifElse(((self:getHelper(32897).var[11]) == 1), 50, 200)))),
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(32896))) then
		self:varAdd {
			value = 10,
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(32895))) then
		self:varAdd {
			value = 50,
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(32894))) then
		self:varAdd {
			value = 200,
			v = 39
		}
	end
	
	-- State controller
	if (self:numHelper(36910)) then
		self:attackMulSet {
			value = 1.5
		}
	end
	
	-- State controller
	if not (self:numHelper(36910)) then
		self:attackMulSet {
			value = 1
		}
	end
	
	-- State controller
	if ((((self:roundState()) == 2) and (self:getEnemy():numHelper(38006))) and (((self:time()) % 2) == 0)) then
		self:lifeAdd {
			value = -1,
			kill = 0
		}
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 1)) or (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 1)) then
			self:assertSpecial {
				flag = "invisible"
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 1)) or (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 1)) then
			self:hitBy {
				value = "",
				time = 1
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:posSet {
				x = (self:getHelper(130000).var[10])
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:velSet {
				x = 0,
				y = 0
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:posSet {
				x = (self:getHelper(130000).var[10]),
				y = (self:getHelper(130000).var[11])
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 3)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:changeState {
				value = 50,
				ctrl = 1
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:velSet {
				x = 0,
				y = 0
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 1)) or (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 1)) then
			self:assertSpecial {
				flag = "invisible"
			}
		end
	end
	
	-- State controller
	if (Utils.inInterval((self:stateNo()), "[", 0, 199, "]")) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 1)) or (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 1)) then
			self:hitBy {
				value = "",
				time = 1
			}
		end
	end
	
	-- State controller
	if ((self:stateType() ~= "L") and (Utils.inInterval((self:stateNo()), "[", 5000, 5999, "]"))) then
		if (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:posSet {
				x = (self:getHelper(130000).var[10])
			}
		end
	end
	
	-- State controller
	if ((self:stateType() ~= "L") and (Utils.inInterval((self:stateNo()), "[", 5000, 5999, "]"))) then
		if (((self:getHelper(130000):stateNo()) == 33001) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:velSet {
				x = 0,
				y = 0
			}
		end
	end
	
	-- State controller
	if ((self:stateType() ~= "L") and (Utils.inInterval((self:stateNo()), "[", 5000, 5999, "]"))) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:posSet {
				x = (self:getHelper(130000).var[10]),
				y = (self:getHelper(130000).var[11])
			}
		end
	end
	
	-- State controller
	if ((self:stateType() ~= "L") and (Utils.inInterval((self:stateNo()), "[", 5000, 5999, "]"))) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 3)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:changeState {
				value = 50,
				ctrl = 1
			}
		end
	end
	
	-- State controller
	if ((self:stateType() ~= "L") and (Utils.inInterval((self:stateNo()), "[", 5000, 5999, "]"))) then
		if (((self:getHelper(130000):stateNo()) == 33002) and ((self:getHelper(130000):time()) == 2)) and (((self:getHelper(130000):rootDist().x) < 40) and ((self:getHelper(130000):rootDist().x) > -40)) and (((self:getHelper(130000):rootDist().y) < 20) and ((self:getHelper(130000):rootDist().y) > -20)) then
			self:velSet {
				x = 0,
				y = 0
			}
		end
	end
	
	-- State controller
	if ((((self:getEnemy():numHelper(37350)) == 1) and ((self:numHelper(130100)) == 0)) and ((self:getEnemy():numHelper(130000)) == 1)) then
		self:helper {
			helperType = "normal",
			name = "shadowclon",
			id = 130100,
			stateNo = 37350,
			pos = {40, -5},
			posType = "p2",
			facing = 1,
			keyCtrl = 0,
			ownPal = 0,
			size_xScale = 1,
			size_yScale = 1,
			size_ground_back = 0,
			size_ground_front = 26
		}
	end
	
	-- State controller
	if ((((self:numHelper(130000)) == 1) and ((self:getHelper(130000):stateNo()) == 33100)) and not (self:numHelper(130002))) then
		self:helper {
			helperType = "normal",
			name = "raziel absortion2",
			id = 130002,
			stateNo = 33120,
			pos = {50, -10},
			posType = "p2",
			facing = 1,
			keyCtrl = 0
		}
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(130002)) and not (self:numHelper(130001))) then
		self:helper {
			helperType = "normal",
			name = "raziel absortion",
			id = 130001,
			stateNo = 33111,
			pos = {50, -10},
			posType = "p2",
			facing = 1,
			keyCtrl = 0
		}
	end
	
	-- State controller
	if ((self:random()) > 400) and (self:getEnemy():numHelper(33210)) then
		if (((self:ctrl()) and (self:command("y"))) and (self:moveType() ~= "H")) or (((self:ctrl()) and (self:command("x"))) and (self:moveType() ~= "H")) then
			self:helper {
				helperType = "normal",
				name = "paralisis",
				id = 33230,
				stateNo = 33230,
				pos = {0, 0},
				posType = "p1"
			}
		end
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(39390)) and not (self:numHelper(39398))) then
		self:helper {
			helperType = "normal",
			name = "theboy acidrain",
			id = 39398,
			stateNo = 39398,
			pos = {0, 0},
			posType = "p1",
			facing = 1,
			keyCtrl = 0
		}
	end
	
	-- State controller
	if (((self:getHelper(39398).var[10]) == 1) and (((self:time()) % 10) == 0)) then
		self:palFX {
			time = 3,
			add = {100, 100, 50},
			mul = {250, 250, 24},
			sinAdd = {115, 110, 55, 10},
			invertAll = 0,
			color = 0
		}
	end
	
	-- State controller
	if (((self:getHelper(39398).var[10]) == 1) and (((self:time()) % 2) == 0)) then
		self:lifeAdd {
			value = -2,
			kill = 0
		}
	end
	
	-- State controller
	if (((self:getEnemy():stateNo()) == 33415) and ((self:getEnemy():numHelper(33416)) == 0)) then
		self:varSet {
			fv = 31,
			value = (self:p2Dist().x)
		}
	end
	
	-- State controller
	if (((self:getEnemy():stateNo()) == 33415) and ((self:getEnemy():numHelper(33416)) == 0)) then
		self:varSet {
			fv = 32,
			value = (self:p2Dist().y)
		}
	end
	
	-- State controller
	if 1 then
		self:displayToClipboard {
			text = "%d %d  ___ %f %f",
			params = {(self:getEnemy():stateNo()), (self:getEnemy():numHelper(33416)), (self.fvar[31]), (self.fvar[32])}
		}
	end
	
	-- State controller
	if (((self:getEnemy():stateNo()) == 33415) and ((self:getEnemy():numHelper(33416)) == 0)) then
		self:changeAnim {
			value = 44
		}
	end
	
	-- State controller
	if ((self:getEnemy():stateNo()) == 33415) or ((self:getEnemy():numHelper(33416)) == 1) then
		self:playerPush {
			value = 0
		}
	end
	
	-- State controller
	if (((self:getEnemy():stateNo()) == 33415) and ((self:getEnemy():numHelper(33416)) == 0)) then
		self:velSet {
			x = 0,
			y = 0
		}
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(33416)) == 1) then
		self:posAdd {
			persistent = 22,
			x = (self.fvar[31]),
			y = (self.fvar[32])
		}
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(33416)) == 1) then
		self:turn {
			persistent = 22
		}
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(33416)) == 1) then
		self:changeState {
			persistent = 22,
			value = 51,
			ctrl = 1
		}
	end
	
	-- State controller
	if ((((self:getHelper(130000):stateNo()) == 33304) and ((self:vel().y) > 1)) and ((self:getHelper(130000).var[10]) == 0)) then
		self:explod {
			anim = {"F", 36020},
			id = 36020,
			pos = {-5, -7},
			posType = "p1",
			bindTime = 1,
			sprPriority = -1,
			ownPal = 1,
			scale = {0.5, 0.5}
		}
	end
	
	-- State controller
	if ((((self:getHelper(130000):stateNo()) == 33304) and ((self:vel().y) > 1)) and ((self:getHelper(130000).var[10]) == 0)) then
		self:changeState {
			value = 33310,
			ctrl = 1
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:numHelper(37515))) or (((self:roundState()) == 2) and (self:getEnemy():numHelper(37516))) then
		self:lifeAdd {
			value = 250,
			kill = 0
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:numHelper(37525))) or (((self:roundState()) == 2) and (self:getEnemy():numHelper(37526))) then
		self:lifeAdd {
			value = 1,
			kill = 0
		}
	end
	
	-- State controller
	if (((self:numHelper(33730)) == 0) and ((self:roundState()) == 2)) then
		if ((self:getEnemy():numHelper(33710)) == 1) or ((self:getEnemy():numHelper(33711)) == 1) or ((self:getEnemy():numHelper(33712)) == 1) then
			self:helper {
				helperType = "normal",
				name = "p2janken",
				id = 33730,
				stateNo = 33730,
				pos = {0, 0},
				posType = "p1",
				facing = 1,
				keyCtrl = 0,
				ownPal = 0
			}
		end
	end
	
	-- State controller
	if ((self:alive()) and ((self:roundState()) == 2)) then
		if (((((self:getHelper(34010):stateNo()) == 34030) and (self:ctrl())) and ((self:stateNo()) ~= 34045)) and (self:command("z"))) and ((self:getHelper(34010).var[35]) < 100) then
			self:changeState {
				value = 34045,
				ctrl = 0
			}
		end
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(34210)) > 0) then
		if ((self:vel().x) == 0) and (((self:time()) % 3) == 0) then
			self:velMul {
				x = 0.6
			}
		end
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(34210)) > 0) then
		if ((self:vel().y) < 0) and (((self:time()) % 3) == 0) then
			self:velMul {
				y = 0.6
			}
		end
	end
	
	-- State controller
	if ((self:getHitVar("damage")) >= (self:life())) and ((self:getHelper(39510):stateNo()) == 39511) then
		self:lifeAdd {
			value = 250,
			kill = 1,
			absolute = 0
		}
	end
	
	-- State controller
	if ((self:getHelper(39510):stateNo()) == 39511) then
		self:superPause {
			time = 20,
			anim = -1,
			sound = {-1, -1},
			pos = {0, 0}
		}
	end
	
	-- State controller
	if ((self:getHelper(39510):stateNo()) == 39511) then
		self:velSet {
			x = 0,
			y = -.1
		}
	end
	
	-- State controller
	if ((self:getHelper(39510):stateNo()) == 39511) then
		self:changeState {
			value = 45,
			ctrl = 1
		}
	end
	
	-- State controller
	if ((((self:getEnemy():numHelper(32010)) and ((self.var[48]) ~= 0)) and not (self:getHitVar("guarded"))) and ((self:numExplod(9002)) == 0)) then
		self:bgPalFX {
			time = 5,
			add = {255, 255, 255},
			mul = {256, 256, 256},
			sinAdd = {255, 255, 255, 10},
			invertAll = 0
		}
	end
	
	-- State controller
	if ((((self:getEnemy():numHelper(32010)) and ((self.var[48]) ~= 0)) and not (self:getHitVar("guarded"))) and ((self:numExplod(9002)) == 0)) then
		self:playSnd {
			value = {{"F", 120}, 10}
		}
	end
	
	-- State controller
	if ((((self:getEnemy():numHelper(32010)) and ((self.var[48]) ~= 0)) and not (self:getHitVar("guarded"))) and ((self:numExplod(9002)) == 0)) then
		self:explod {
			anim = {"F", (self:ifElse(((self:teamSide()) == 1), 485, 486))},
			id = 30004,
			pos = {(self:ifElse(((self:teamSide()) == 1), 3, 306)), (210 + (self:ifElse((self.var[4]), 39, 1)))},
			posType = "left",
			scale = {1, 1},
			facing = 1,
			onTop = 1,
			ownPal = 1,
			bindTime = -1,
			sprPriority = 5
		}
	end
	
	-- State controller
	if ((((self:getEnemy():numHelper(32010)) and ((self.var[48]) ~= 0)) and not (self:getHitVar("guarded"))) and ((self:numExplod(9002)) == 0)) then
		self:explod {
			anim = {"F", 310},
			id = 9002,
			pos = {(self:ifElse(((self:teamSide()) == 1), 4, 315)), 223},
			posType = "left",
			bindTime = -1,
			scale = {0.7, 0.7},
			sprPriority = 5,
			onTop = 1,
			ownPal = 1,
			superMoveTime = 99999999,
			pauseMoveTime = 99999999,
			facing = (self:ifElse(((self:teamSide()) == 1), 1, -1))
		}
	end
	
	-- State controller
	if ((self:numHelper(130000)) and ((self:getHelper(130000):facing()) == (self:facing()))) then
		if (Utils.inInterval((self:getHelper(130000):stateNo()), "[", 38200, 38299, "]")) then
			self:varSet {
				v = 57,
				value = (self:floor((self:getHelper(130000):rootDist().x)))
			}
		end
	end
	
	-- State controller
	if ((self:numHelper(130000)) and ((self:getHelper(130000):facing()) ~= (self:facing()))) then
		if (Utils.inInterval((self:getHelper(130000):stateNo()), "[", 38200, 38299, "]")) then
			self:varSet {
				v = 57,
				value = (self:floor(-(self:getHelper(130000):rootDist().x)))
			}
		end
	end
	
	-- State controller
	if (not Utils.inInterval((self:stateNo()), "[", 38200, 38299, "]")) then
		self:removeExplod {
			id = 39510
		}
	end
	
	-- State controller
	if ((((self:roundState()) == 2) and (self:numHelper(37910))) and ((self:getHelper(37910):stateNo()) == 37913)) then
		self:varAdd {
			value = (self:getHelper(37910).var[12]),
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(37920))) then
		self:varAdd {
			value = 500,
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(37921))) then
		self:varAdd {
			value = 1200,
			v = 39
		}
	end
	
	-- State controller
	if (((self:roundState()) == 2) and (self:getEnemy():numHelper(37922))) then
		self:varAdd {
			value = 2000,
			v = 39
		}
	end
	
	-- State controller
	if (((self:getHelper(34910).var[12]) == 1) and ((self:numHelper(34910)) == 1)) then
		self:hitBy {
			value = "",
			time = 10
		}
	end
	
	-- State controller
	if (((self:numHelper(34910)) == 1) and (((self:time()) % 10) == 0)) then
		self:afterImage {
			time = 10,
			length = 5,
			palBright = {0, 70, 0},
			palContrast = {50, 120, 50},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 1,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if (((self:getHelper(34910).var[12]) == 1) and ((self:numHelper(34910)) == 1)) then
		self:trans {
			trans = "add1",
			alpha = {256, 128}
		}
	end
	
	-- State controller
	if ((self:getHitVar("fall.envshake.phase")) ~= 999) then
		if (((self:getHitVar("damage")) and ((self:random()) < ((self:getHitVar("damage")) * 2))) and ((self:getHitVar("fall.envshake.phase")) ~= 888)) or (((self:getHitVar("damage")) and ((self:random()) < 500)) and ((self:getHitVar("fall.envshake.phase")) == 888)) then
			self:helper {
				helperType = "normal",
				name = "critical hits",
				id = 20800,
				stateNo = 20800,
				pos = {0, 0},
				posType = "p1",
				facing = 1,
				keyCtrl = 0,
				ownPal = 0
			}
		end
	end
	
	-- State controller
	if (((self:numHelper(20800)) ~= 0) and (((self:time()) % 10) == 0)) then
		self:lifeAdd {
			ignoreHitPause = 0,
			value = (self:ceil((-(self:getHitVar("damage")) * (self:ifElse(((self:random()) < 333), (self:ifElse(((self:random()) < 499), 1.2, .9)), .75))))),
			kill = 1,
			absolute = 0
		}
	end
end

function Cloudi:state_m3()
	-- State initialization
	self:setStateParams
	{
	}
	
	-- State controller
	if ((self:time()) == 1) then
		if ((self:stateNo()) == 52) or ((self:stateNo()) == 106) then
			self:playSnd {
				value = {101, 2}
			}
		end
	end
	
	-- State controller
	if ((self:stateNo()) >= 5000) then
		self:afterImageTime {
			time = 1
		}
	end
	
	-- State controller
	if ((((self:stateNo()) >= 3000) and ((self:stateNo()) <= 3900)) and ((self:time()) == 0)) then
		self:removeExplod {
			id = 101
		}
	end
	
	-- State controller
	if (((self:getHitVar("HitShakeTime")) >= 0) and ((self:getHitVar("HitShakeTime")) < 10)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + .15
			end
		end
	end
	
	-- State controller
	if ((self:getHitVar("chainid")) == 140) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = 14
			end
		end
	end
	
	-- State controller
	if ((self:getHitVar("chainid")) == 120) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + .7
			end
		end
	end
	
	-- State controller
	if (self:numHelper(30000)) and ((self:getHelper(30000).var[45]) > 0) and (((self:getHitVar("HitShakeTime")) >= 0) and ((self:getHitVar("HitShakeTime")) < 10)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.15
			end
		end
	end
	
	-- State controller
	if (((self:getHitVar("HitShakeTime")) >= 10) and ((self:getHitVar("HitShakeTime")) < 15)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + .24
			end
		end
	end
	
	-- State controller
	if (self:numHelper(30000)) and ((self:getHelper(30000).var[45]) > 0) and (((self:getHitVar("HitShakeTime")) >= 10) and ((self:getHitVar("HitShakeTime")) < 15)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.24
			end
		end
	end
	
	-- State controller
	if (((self:getHitVar("HitShakeTime")) >= 15) and ((self:getHitVar("HitShakeTime")) < 30)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + .35
			end
		end
	end
	
	-- State controller
	if (self:numHelper(30000)) and ((self:getHelper(30000).var[45]) > 0) and (((self:getHitVar("HitShakeTime")) >= 15) and ((self:getHitVar("HitShakeTime")) < 30)) then
		if (((self:stateNo()) == 150) or ((self:stateNo()) == 152)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.35
			end
		end
	end
	
	-- State controller
	if (((((self.fvar[14]) > 0) and not (self:time())) and ((self:stateNo()) == 5000)) and (self:alive())) then
		if (((((self:anim()) == 5000) or ((self:anim()) == 5001)) or ((self:anim()) == 5010)) or ((self:anim()) == 5011)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.02
			end
		end
	end
	
	-- State controller
	if (((((self.fvar[14]) > 0) and not (self:time())) and ((self:stateNo()) == 5010)) and (self:alive())) then
		if (((self:anim()) == 5020) or ((self:anim()) == 5021)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.02
			end
		end
	end
	
	-- State controller
	if (((((self.fvar[14]) > 0) and not (self:time())) and ((self:stateNo()) == 5000)) and (self:alive())) then
		if (((self:anim()) == 5002) or ((self:anim()) == 5012)) then
			if self:canExecuteController{
				ignoreHitPause = 1,
				} then
				self.fvar[14] = self.fvar[14] + -.06
			end
		end
	end
	
	-- State controller
	if ((((((self.fvar[14]) > 0) and not (self:time())) and ((self:stateNo()) == 5010)) and (self:alive())) and ((self:anim()) == 5022)) then
		if self:canExecuteController{
			ignoreHitPause = 1,
			} then
			self.fvar[14] = self.fvar[14] + -.06
		end
	end
	
	-- State controller
	if (((((self.fvar[14]) > 0) and not (self:time())) and ((self:stateNo()) == 5100)) and (self:alive())) then
		if self:canExecuteController{
			ignoreHitPause = 1,
			} then
			self.fvar[14] = self.fvar[14] + -.12
		end
	end
	
	-- State controller
	if (((((self.fvar[14]) > 0) and (((self:gameTime()) % 5) == 0)) and (self:moveType() ~= "H")) and (not Utils.inInterval((self:stateNo()), "[", 130, 160, "]"))) then
		if self:canExecuteController{
			ignoreHitPause = 1,
			} then
			self.fvar[14] = self.fvar[14] + -.02
		end
	end
	
	-- State controller
	if ((self.fvar[14]) >= 15) then
		self:changeState {
			ignoreHitPause = 1,
			value = 9000,
			ctrl = 0
		}
	end
	
	-- State controller
	if ((self.fvar[14]) < 0) then
		if self:canExecuteController{
			ignoreHitPause = 1,
			} then
			self.fvar[14] = 0
		end
	end
	
	-- State controller
	if (((self:stateNo()) ~= 9005) and (not Utils.inInterval((self:stateNo()), "[", 120, 190, "]"))) then
		self:varSet {
			ignoreHitPause = 1,
			v = 16,
			value = 0
		}
	end
	
	-- State controller
	if ((((self:getHitVar("guarded")) and not (self:hitShakeOver())) and ((self:time()) < 4)) and ((self.var[16]) == 0)) then
		self:palFX {
			time = 1,
			add = {16, 16, 56},
			mul = {256, 256, 256},
			sinAdd = {10, 10, 20, 10},
			invertAll = 0,
			color = 256
		}
	end
	
	-- State controller
	if ((self:command("fwd")) and (self:hitShakeOver())) or ((self:command("fwd")) and (Utils.inInterval((self:stateNo()), "[", 120, 140, "]"))) then
		self:varSet {
			ignoreHitPause = 1,
			v = 16,
			value = 1
		}
	end
	
	-- State controller
	if ((self:numHelper(9001)) == 1) then
		self:assertSpecial {
			flag = "nostandguard",
			flag2 = "noairguard"
		}
	end
	
	-- State controller
	if (((((self:getHitVar("guarded")) and not (self:hitShakeOver())) and ((self:time()) < 4)) and (self:command("fwd"))) and ((self.var[16]) == 0)) then
		self:changeState {
			ignoreHitPause = 1,
			value = 9005,
			ctrl = 0
		}
	end
	
	-- State controller
	if 1 then
		self:varSet {
			ignoreHitPause = 1,
			v = 48,
			value = (self:getHelper(30000).var[20])
		}
	end
end

