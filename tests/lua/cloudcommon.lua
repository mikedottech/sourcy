--[[
   cloudcommon.lua
   Generated from cloudcommon.cns
   on 2026-05-13.

   by Sourcy Code Translator
   (c) 2012 - radexx

   Runtime version: 1.0

]]

function Cloudi:state_0()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		sprPriority = 0,
	}
	
	-- State controller
	if (((self:anim()) ~= 0) and ((self:anim()) ~= 5)) or (((self:anim()) == 5) and ((self:animTime()) == 0)) then
		self:changeAnim {
			value = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:abs((self:vel().x))) < 2) or ((self:time()) == 4) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if not (self:alive()) then
		self:changeState {
			value = 5050
		}
	end
end

function Cloudi:state_10()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		physics = "C",
		anim = 10,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:velMul {
			x = 0.75
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 11
		}
	end
end

function Cloudi:state_100()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		anim = 100,
		sprPriority = 1,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:explod {
			anim = {"F", 1105},
			id = 100,
			pos = {-10, -16},
			posType = "p1",
			bindTime = 1,
			scale = {0.3, 0.3},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 0
		}
	end
	
	-- State controller
	if (self:animElem(6)) then
		self:playSnd {
			value = {180, 0}
		}
	end
	
	-- State controller
	if (self:animElem(11)) then
		self:playSnd {
			value = {180, 1}
		}
	end
	
	-- State controller
	if ((self:numHelper(33811)) and (((self:time()) % 10) == 0)) then
		self:afterImage {
			time = 10,
			length = 9,
			palBright = {70, 60, 0},
			palContrast = {120, 100, 50},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 2,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if ((self:vel().x) > 0) and (((self:time()) % (self:ifElse(((self:random()) < 499), 3, 4))) == 0) then
		if (((self:numExplod(37810)) < 10) and (self:numHelper(33811))) or (((self:numExplod(37810)) < 10) and (self:getEnemy():numHelper(33812))) then
			self:explod {
				anim = {"F", 37810},
				id = 37810,
				pos = {(10 + ((self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))) * (self:ifElse(((self:random()) < 499), 1, 2)))), (-28 + (self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 14, -13.5)))))},
				posType = "p1",
				sprPriority = 5,
				vel = {(self:ifElse(((self:random()) < 499), -2, (self:ifElse(((self:random()) < 499), -4, -3.5)))), 0},
				scale = {(self:ifElse(((self:random()) < 499), .4, (self:ifElse(((self:random()) < 499), .2, .6)))), (self:ifElse(((self:random()) < 499), 1, .5))}
			}
		end
	end
	
	-- State controller
	if 1 then
		self:velSet {
			x = ((self:_const("velocity.run.fwd.x")) + ((self:numHelper(33811)) * (self:_const("velocity.run.fwd.x"))))
		}
	end
	
	-- State controller
	if (self:getEnemy():numHelper(33812)) then
		if 1 then
			self:velSet {
				x = ((self:_const("velocity.run.fwd.x")) + ((self:getEnemy():numHelper(33812)) * (self:_const("velocity.run.fwd.x"))))
			}
		end
	end
	
	-- State controller
	if (self:getEnemy():numHelper(34210)) then
		self:velMul {
			x = 0.6
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "NoWalk"
		}
	end
	
	-- State controller
	if 1 then
		self:assertSpecial {
			flag = "NoAutoTurn"
		}
	end
	
	-- State controller
	if (self:command("holdfwd") == 0) then
		self:changeState {
			value = 101
		}
	end
end

function Cloudi:state_101()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		anim = 90,
		velSet = {3, 0},
		sprPriority = 1,
		ctrl = 1,
	}
	
	-- State controller
	if ((self:time()) == 1) then
		self:explod {
			anim = {"F", 1118},
			id = 100,
			pos = {42, -21},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0
		}
	end
end

function Cloudi:state_105()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		physics = "A",
		ctrl = 0,
		anim = 105,
		sprPriority = 1,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"F", 130}, 0}
		}
	end
	
	-- State controller
	if ((self:numHelper(33811)) and (((self:time()) % 10) == 0)) or ((self:getEnemy():numHelper(33812)) and (((self:time()) % 10) == 0)) then
		self:afterImage {
			time = 10,
			length = 9,
			palBright = {70, 60, 0},
			palContrast = {120, 100, 50},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 2,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if ((self:vel().x) < 0) and (((self:time()) % (self:ifElse(((self:random()) < 499), 3, 4))) == 0) then
		if (((self:numExplod(37810)) < 10) and (self:numHelper(33811))) or (((self:numExplod(37810)) < 10) and (self:getEnemy():numHelper(33812))) then
			self:explod {
				anim = {"F", 37810},
				id = 37810,
				pos = {(10 + ((self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))) * (self:ifElse(((self:random()) < 499), 1, 2)))), (-28 + (self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 14, -13.5)))))},
				posType = "p1",
				sprPriority = 5,
				vel = {(self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))), 0},
				scale = {(self:ifElse(((self:random()) < 499), .4, (self:ifElse(((self:random()) < 499), .2, .6)))), (self:ifElse(((self:random()) < 499), 1, .5))}
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			x = ((self:_const("velocity.run.back.x")) + ((self:numHelper(33811)) * (self:_const("velocity.run.back.x")))),
			y = (self:_const("velocity.run.back.y"))
		}
	end
	
	-- State controller
	if (self:getEnemy():numHelper(33812)) then
		if ((self:time()) == 0) then
			self:velSet {
				x = ((self:_const("velocity.run.back.x")) + ((self:getEnemy():numHelper(33812)) * (self:_const("velocity.run.back.x")))),
				y = (self:_const("velocity.run.back.y"))
			}
		end
	end
	
	-- State controller
	if ((self:getEnemy():numHelper(34210)) and not (self:time())) then
		self:velMul {
			x = 0.6
		}
	end
	
	-- State controller
	if ((self:time()) == 2) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 0) then
		self:changeState {
			value = 106
		}
	end
end

function Cloudi:state_106()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		ctrl = 0,
		anim = 47,
	}
	
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
	if ((self:time()) == 2) then
		self:makeDust {
			pos = {-5, -2},
			spacing = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 7) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_11()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		physics = "C",
		anim = 11,
		sprPriority = 0,
	}
	
	-- State controller
	if (((self:anim()) == 6) and ((self:animTime()) == 0)) then
		self:changeAnim {
			value = 11
		}
	end
end

function Cloudi:state_12()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		anim = 12,
	}
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 0
		}
	end
end

function Cloudi:state_120()
	-- State initialization
	self:setStateParams
	{
		stateType = "U",
		physics = "U",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeAnim {
			value = ((120 + (self:stateType() == "C")) + ((self:stateType() == "A") * 2))
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "S")) then
		self:stateTypeSet {
			physics = "S"
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "C")) then
		self:stateTypeSet {
			physics = "C"
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "A")) then
		self:stateTypeSet {
			physics = "A"
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = ((130 + (self:stateType() == "C")) + ((self:stateType() == "A") * 2))
		}
	end
	
	-- State controller
	if (self:command("holdback") == 0) or not (self:inGuardDist()) then
		self:changeState {
			value = 140
		}
	end
end

function Cloudi:state_130()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
	}
	
	-- State controller
	if ((self:anim()) ~= 130) then
		self:changeAnim {
			value = 130
		}
	end
	
	-- State controller
	if (self:command("holddown")) then
		self:changeState {
			value = 131
		}
	end
	
	-- State controller
	if (self:command("holdback") == 0) or not (self:inGuardDist()) then
		self:changeState {
			value = 140
		}
	end
end

function Cloudi:state_131()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		physics = "C",
	}
	
	-- State controller
	if ((self:anim()) ~= 131) then
		self:changeAnim {
			value = 131
		}
	end
	
	-- State controller
	if (self:command("holddown") == 0) then
		self:changeState {
			value = 130
		}
	end
	
	-- State controller
	if (self:command("holdback") == 0) or not (self:inGuardDist()) then
		self:changeState {
			value = 140
		}
	end
end

function Cloudi:state_132()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		physics = "N",
	}
	
	-- State controller
	if ((self:anim()) ~= 132) then
		self:changeAnim {
			value = 132
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:_const("movement.yaccel"))
		}
	end
	
	-- State controller
	if 1 then
		if self:canExecuteController{
			} then
			self.sysvar[0] = (self:floor((((self:pos().y) >= 0) and ((self:vel().y) > 0))))
		end
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:velSet {
			y = 0
		}
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if (self.sysvar[0]) and (self:command("holdback")) and (self:inGuardDist()) then
		self:changeState {
			value = 130
		}
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:changeState {
			value = 52
		}
	end
	
	-- State controller
	if (self:command("holdback") == 0) or not (self:inGuardDist()) then
		self:changeState {
			value = 140
		}
	end
end

function Cloudi:state_140()
	-- State initialization
	self:setStateParams
	{
		stateType = "U",
		physics = "U",
		ctrl = 1,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeAnim {
			value = ((140 + (self:stateType() == "C")) + ((self:stateType() == "A") * 2))
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "S")) then
		self:stateTypeSet {
			physics = "S"
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "C")) then
		self:stateTypeSet {
			physics = "C"
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:stateType() == "A")) then
		self:stateTypeSet {
			physics = "A"
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
end

function Cloudi:state_150()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"S", 131}, 0}
		}
	end
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = 150
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = (151 + (2 * (self:command("holddown"))))
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:forceFeedback {
			waveForm = "square",
			time = 3
		}
	end
end

function Cloudi:state_151()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "H",
		physics = "S",
		anim = 150,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1
		}
	end
	
	-- State controller
	if ((self:time()) == (self:getHitVar("slidetime"))) or (self:hitOver()) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == (self:getHitVar("ctrltime"))) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:changeState {
			value = 130,
			ctrl = 1
		}
	end
end

function Cloudi:state_152()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"S", 131}, 0}
		}
	end
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = 151
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = (151 + (2 * (self:command("holddown"))))
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:forceFeedback {
			waveForm = "square",
			time = 4
		}
	end
end

function Cloudi:state_153()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		moveType = "H",
		physics = "C",
		anim = 151,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1
		}
	end
	
	-- State controller
	if ((self:time()) == (self:getHitVar("slidetime"))) or (self:hitOver()) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == (self:getHitVar("ctrltime"))) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:stateType() == "S") and (self:command("holddown"))) then
		self:stateTypeSet {
			physics = "C",
			stateType = "C"
		}
	end
	
	-- State controller
	if ((self:stateType() == "C") and (self:command("holddown") == 0)) then
		self:stateTypeSet {
			physics = "S",
			stateType = "S"
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:changeState {
			value = 131,
			ctrl = 1
		}
	end
end

function Cloudi:state_154()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"S", 131}, 0}
		}
	end
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = 152
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = 155
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:forceFeedback {
			waveForm = "square",
			time = 4
		}
	end
end

function Cloudi:state_155()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
		anim = 152,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1,
			y = 1
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:_const("movement.yaccel"))
		}
	end
	
	-- State controller
	if ((self:time()) == (self:getHitVar("ctrltime"))) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if 1 then
		if self:canExecuteController{
			} then
			self.sysvar[0] = (self:floor((((self:pos().y) >= 0) and ((self:vel().y) > 0))))
		end
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:velSet {
			y = 0
		}
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if (self.sysvar[0]) and (self:command("holdback")) and (self:inGuardDist()) then
		self:changeState {
			value = 130
		}
	end
	
	-- State controller
	if (self.sysvar[0]) then
		self:changeState {
			value = 52
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

function Cloudi:state_175()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) and not (self:selfAnimExist(175)) then
		self:changeState {
			value = 170
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeAnim {
			value = 175
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
		velSet = {0, 0},
	}
	
	-- State controller
	if (self:selfAnimExist(190)) then
		self:changeAnim {
			value = 190
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeState {
			value = 191
		}
	end
end

function Cloudi:state_191()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeState {
			value = 0
		}
	end
end

function Cloudi:state_20()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		sprPriority = 0,
	}
	
	-- State controller
	if ((self:animElem(5)) and ((self:anim()) == 20)) or ((self:animElem(6)) and ((self:anim()) == 21)) then
		self:playSnd {
			value = {180, 0}
		}
	end
	
	-- State controller
	if ((self:numHelper(33811)) and (((self:time()) % 10) == 0)) or ((self:getEnemy():numHelper(33812)) and (((self:time()) % 10) == 0)) then
		self:afterImage {
			time = 10,
			length = 9,
			palBright = {70, 60, 0},
			palContrast = {120, 100, 50},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 2,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if ((self:vel().x) > 0) and (((self:time()) % (self:ifElse(((self:random()) < 499), 3, 4))) == 0) then
		if (((self:numExplod(37810)) < 10) and (self:numHelper(33811))) or (((self:numExplod(37810)) < 10) and (self:getEnemy():numHelper(33812))) then
			self:explod {
				anim = {"F", 37810},
				id = 37810,
				pos = {(10 + ((self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))) * (self:ifElse(((self:random()) < 499), 1, 2)))), (-28 + (self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 14, -13.5)))))},
				posType = "p1",
				sprPriority = 5,
				vel = {(self:ifElse(((self:random()) < 499), -2, (self:ifElse(((self:random()) < 499), -4, -3.5)))), 0},
				scale = {(self:ifElse(((self:random()) < 499), .4, (self:ifElse(((self:random()) < 499), .2, .6)))), (self:ifElse(((self:random()) < 499), 1, .5))}
			}
		end
	end
	
	-- State controller
	if ((self:vel().x) < 0) and (((self:time()) % (self:ifElse(((self:random()) < 499), 3, 4))) == 0) then
		if (((self:numExplod(37810)) < 10) and (self:numHelper(33811))) or (((self:numExplod(37810)) < 10) and (self:getEnemy():numHelper(33812))) then
			self:explod {
				anim = {"F", 37810},
				id = 37810,
				pos = {(10 + ((self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))) * (self:ifElse(((self:random()) < 499), 1, 2)))), (-28 + (self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 14, -13.5)))))},
				posType = "p1",
				sprPriority = 5,
				vel = {(self:ifElse(((self:random()) < 499), 2, (self:ifElse(((self:random()) < 499), 4, 3.5)))), 0},
				scale = {(self:ifElse(((self:random()) < 499), .4, (self:ifElse(((self:random()) < 499), .2, .6)))), (self:ifElse(((self:random()) < 499), 1, .5))}
			}
		end
	end
	
	-- State controller
	if (self:command("holdfwd")) then
		self:velSet {
			x = ((self:_const("velocity.walk.fwd.x")) + ((self:numHelper(33811)) * (self:_const("velocity.walk.fwd.x"))))
		}
	end
	
	-- State controller
	if (self:command("holdback")) then
		self:velSet {
			x = ((self:_const("velocity.walk.back.x")) + ((self:numHelper(33811)) * (self:_const("velocity.walk.back.x"))))
		}
	end
	
	-- State controller
	if (self:getEnemy():numHelper(33812)) then
		if (self:command("holdfwd")) then
			self:velSet {
				x = ((self:_const("velocity.walk.fwd.x")) + ((self:getEnemy():numHelper(33812)) * (self:_const("velocity.walk.fwd.x"))))
			}
		end
	end
	
	-- State controller
	if (self:getEnemy():numHelper(33812)) then
		if (self:command("holdback")) then
			self:velSet {
				x = ((self:_const("velocity.walk.back.x")) + ((self:getEnemy():numHelper(33812)) * (self:_const("velocity.walk.back.x"))))
			}
		end
	end
	
	-- State controller
	if (self:getEnemy():numHelper(34210)) then
		self:velMul {
			x = 0.6
		}
	end
	
	-- State controller
	if ((self:vel().x) > 0) then
		if (((self:anim()) ~= 20) and ((self:anim()) ~= 5)) or (((self:anim()) == 5) and ((self:animTime()) == 0)) then
			self:changeAnim {
				value = 20
			}
		end
	end
	
	-- State controller
	if ((self:vel().x) < 0) then
		if (((self:anim()) ~= 21) and ((self:anim()) ~= 5)) or (((self:anim()) == 5) and ((self:animTime()) == 0)) then
			self:changeAnim {
				value = 21
			}
		end
	end
end

function Cloudi:state_40()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		anim = 40,
		ctrl = 0,
		sprPriority = 1,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(0))
		end
	end
	
	-- State controller
	if (self:command("holdfwd")) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(1))
		end
	end
	
	-- State controller
	if (self:command("holdback")) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(-1))
		end
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:velSet {
			x = (self:ifElse(((self.sysvar[1]) == 0), (self:_const("velocity.jump.neu.x")), (self:ifElse(((self.sysvar[1]) == 1), (self:_const("velocity.jump.fwd.x")), (self:_const("velocity.jump.back.x")))))),
			y = (self:_const("velocity.jump.y"))
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) and ((self:prevStateNo()) == 100) and ((self.sysvar[1]) == 1) then
		self:velSet {
			x = (self:_const("velocity.runjump.fwd.x"))
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 50,
			ctrl = 1
		}
	end
end

function Cloudi:state_45()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		physics = "N",
		ctrl = 0,
		velSet = {0, 0},
	}
	
	-- State controller
	if (((self:time()) == 0) and ((self:random()) > 699)) then
		self:playSnd {
			value = {{"S", 101}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if (self:selfAnimExist(44)) then
		self:changeAnim {
			value = 44
		}
	end
	
	-- State controller
	if not (self:selfAnimExist(44)) then
		self:changeAnim {
			value = 41
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(0))
		end
	end
	
	-- State controller
	if (self:command("holdfwd")) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(1))
		end
	end
	
	-- State controller
	if (self:command("holdback")) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor(-1))
		end
	end
	
	-- State controller
	if ((self:time()) == 2) then
		self:velSet {
			x = (self:ifElse(((self.sysvar[1]) == 0), (self:_const("velocity.airjump.neu.x")), (self:ifElse(((self.sysvar[1]) == 1), (self:_const("velocity.airjump.fwd.x")), (self:_const("velocity.airjump.back.x")))))),
			y = (self:_const("velocity.airjump.y"))
		}
	end
	
	-- State controller
	if (((self:time()) == 2) and ((self:vel().x) == 0)) then
		self:explod {
			anim = {"F", 1115},
			id = 100,
			pos = {0, -10},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = -3,
			ownPal = 1,
			removeOnGetHit = 0
		}
	end
	
	-- State controller
	if (((self:time()) == 2) and ((self:vel().x) ~= 0)) then
		self:explod {
			anim = {"F", 1116},
			id = 100,
			pos = {(-6 + (self:ifElse(((self:vel().x) < 0), 12, 0))), -10},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = -3,
			ownPal = 1,
			removeOnGetHit = 0,
			facing = (self:ifElse(((self:vel().x) > 0), 1, -1))
		}
	end
	
	-- State controller
	if ((self:time()) == 2) then
		self:changeState {
			value = 50,
			ctrl = 1
		}
	end
end

function Cloudi:state_50()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		physics = "A",
	}
	
	-- State controller
	if ((self:numHelper(33811)) and (((self:time()) % 10) == 0)) or ((self:getEnemy():numHelper(33812)) and (((self:time()) % 10) == 0)) then
		self:afterImage {
			time = 10,
			length = 9,
			palBright = {70, 60, 0},
			palContrast = {120, 100, 50},
			palAdd = {0, 0, 0},
			palMul = {1, 1, 1},
			timeGap = 2,
			frameGap = 2,
			trans = "Add"
		}
	end
	
	-- State controller
	if (not (self:time()) and (self:numHelper(33811))) or (not (self:time()) and (self:getEnemy():numHelper(33812))) then
		self:velMul {
			x = 1.5,
			y = 1.3
		}
	end
	
	-- State controller
	if ((((self:time()) == 0) and ((self:prevStateNo()) == 40)) and ((self:vel().x) == 0)) then
		self:explod {
			anim = {"F", 1113},
			id = 100,
			pos = {0, -24},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = -3,
			ownPal = 1,
			removeOnGetHit = 0
		}
	end
	
	-- State controller
	if ((((self:time()) == 0) and ((self:prevStateNo()) == 40)) and ((self:vel().x) ~= 0)) then
		self:explod {
			anim = {"F", 1114},
			id = 100,
			pos = {(-14 + (self:ifElse(((self:vel().x) < 0), 21, 0))), -27},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = -3,
			ownPal = 1,
			removeOnGetHit = 0,
			facing = (self:ifElse(((self:vel().x) > 0), 1, -1))
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"F", 125}, 1}
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and ((self:random()) > 699)) then
		self:playSnd {
			value = {{"S", 101}, 1},
			channel = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = 0
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:changeAnim {
			value = (self:ifElse(((self:vel().x) == 0), 41, (self:ifElse(((self:vel().x) > 0), 42, 43))))
		}
	end
	
	-- State controller
	if ((self:vel().y) > -2) and (self:selfAnimExist(((self:anim()) + 3))) then
		self:changeAnim {
			persistent = 0,
			value = ((self:anim()) + 3)
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
end

function Cloudi:state_5001()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		moveType = "H",
		physics = "S",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeAnim {
			value = ((5005 + (self:getHitVar("animtype"))) + (((self:getHitVar("groundtype")) == 2) * 10))
		}
	end
	
	-- State controller
	if ((self:time()) >= (self:getHitVar("slidetime"))) then
		self:velMul {
			x = 0.6
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:defenceMulSet {
			value = 1
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_5010()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:getHitVar("animtype")), "[", 3, 5, "]")) then
		self:changeAnim {
			value = (5020 + (self:getHitVar("animtype")))
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
	if ((self:time()) == 0) then
		if (((self:getHitVar("yvel")) ~= 0) or (self:getHitVar("fall"))) or ((self:pos().y) ~= 0) then
			self:stateTypeSet {
				stateType = "a"
			}
		end
	end
	
	-- State controller
	if (self:hitShakeOver()) and (((self:getHitVar("yvel")) == 0) and not (self:getHitVar("fall"))) then
		self:changeState {
			value = 5011
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = 5030
		}
	end
	
	-- State controller
	if ((self:anim()) == 5020) then
		self:forceFeedback {
			persistent = 0,
			time = 6,
			waveForm = "square"
		}
	end
	
	-- State controller
	if ((self:anim()) == 5021) then
		self:forceFeedback {
			persistent = 0,
			time = 8,
			waveForm = "sinesquare",
			ampl = {110, -1, -.3}
		}
	end
	
	-- State controller
	if ((self:anim()) == 5022) then
		self:forceFeedback {
			persistent = 0,
			time = 15,
			waveForm = "sinesquare",
			ampl = 140
		}
	end
end

function Cloudi:state_5011()
	-- State initialization
	self:setStateParams
	{
		stateType = "C",
		moveType = "H",
		physics = "C",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeAnim {
			value = (5025 + (self:getHitVar("animtype")))
		}
	end
	
	-- State controller
	if ((self:time()) >= (self:getHitVar("slidetime"))) then
		self:velMul {
			x = 0.6
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:defenceMulSet {
			value = 1
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:changeState {
			value = 11,
			ctrl = 1
		}
	end
end

function Cloudi:state_5020()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:getHitVar("animtype")), "[", 3, 5, "]")) then
		self:changeAnim {
			value = ((self:ifElse(((self:getHitVar("airtype")) == 1), 5000, 5010)) + (self:getHitVar("animtype")))
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
	if ((self:anim()) == 5012) or ((self:anim()) == 5002) or ((self:anim()) == 5030) or (Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) then
		self:forceFeedback {
			persistent = 0,
			time = 15,
			waveForm = "sinesquare",
			ampl = 140
		}
	end
end

function Cloudi:state_5030()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
		ctrl = 0,
	}
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1,
			y = 1
		}
	end
	
	-- State controller
	if not (self:hitFall()) then
		if (self:hitOver()) or ((self:vel().y) > 0) and ((self:pos().y) >= 10) then
			self:changeState {
				value = 5040
			}
		end
	end
	
	-- State controller
	if (self:hitFall()) then
		if (self:hitOver()) or ((self:vel().y) > 0) and ((self:pos().y) >= 10) then
			self:changeState {
				value = 5050
			}
		end
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 5035
		}
	end
end

function Cloudi:state_5035()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) and (self:selfAnimExist(5035)) and (not Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) and ((self:anim()) ~= 5090) then
		self:changeAnim {
			value = 5035
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if not (self:hitFall()) then
		if (self:hitOver()) or ((self:animTime()) == 0) or ((self:vel().y) > 0) and ((self:pos().y) >= 10) or ((self:time()) == 0) and ((self:anim()) ~= 5035) then
			self:changeState {
				value = 5040
			}
		end
	end
	
	-- State controller
	if (self:hitFall()) then
		if (self:hitOver()) or ((self:animTime()) == 0) or ((self:vel().y) > 0) and ((self:pos().y) >= 10) or ((self:time()) == 0) and ((self:anim()) ~= 5035) then
			self:changeState {
				value = 5050
			}
		end
	end
end

function Cloudi:state_5040()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if not (self:alive()) then
		self:changeState {
			value = 5050
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) and ((self:anim()) ~= 5040) or ((self:time()) == 0) and ((self:anim()) ~= 5035) then
		self:changeAnim {
			value = 5040
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:stateTypeSet {
			moveType = "I"
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 0) then
		self:changeState {
			value = 52
		}
	end
end

function Cloudi:state_5050()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:animTime()) == 0) and ((self:anim()) == 5035) or ((self:time()) == 0) and ((self:anim()) ~= 5035) and ((not Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) and (not Utils.inInterval((self:anim()), "[", 5061, 5069, "]"))) and ((self:anim()) ~= 5090) then
		self:changeAnim {
			value = 5050
		}
	end
	
	-- State controller
	if (Utils.inInterval((self:anim()), "[", 5050, 5059, "]")) and ((self:vel().y) >= (self:ifElse(((self:anim()) == 5050), 1, -2))) and (self:selfAnimExist(((self:anim()) + 10))) then
		self:changeAnim {
			persistent = 0,
			value = ((self:anim()) + 10)
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= -20) and (self:alive()) and (self:canRecover()) then
		if (self:command("recovery")) then
			self:changeState {
				value = 5200
			}
		end
	end
	
	-- State controller
	if ((self:vel().y) > -1) and (self:alive()) and (self:canRecover()) then
		if (self:command("recovery")) then
			self:changeState {
				value = 5210
			}
		end
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= (self:ifElse(((Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) or (Utils.inInterval((self:anim()), "[", 5061, 5069, "]"))), 0, 25))) then
		self:changeState {
			value = 5100
		}
	end
end

function Cloudi:state_5070()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = 5070
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) then
		self:changeState {
			value = 5071
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:forceFeedback {
			time = 12,
			waveForm = "sinesquare",
			ampl = 140
		}
	end
end

function Cloudi:state_5071()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1,
			y = 1
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 15) then
		self:changeState {
			value = 5110
		}
	end
end

function Cloudi:state_5080()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "N",
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[2] = (self:ifElse(((self:getHitVar("yvel")) == 0), 5080, 5090))
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((Utils.inInterval((self:anim()), "[", 5081, 5089, "]")) or (Utils.inInterval((self:anim()), "[", 5111, 5119, "]"))) and (self:selfAnimExist(((self.sysvar[2]) + ((self:anim()) % 10)))) then
		if self:canExecuteController{
			} then
			self.sysvar[2] = self.sysvar[2] + ((self:anim()) % 10)
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self.sysvar[2]) == 5090) and not (self:selfAnimExist(5090)) then
		if self:canExecuteController{
			} then
			self.sysvar[2] = 5030
		end
	end
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = (self.sysvar[2])
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) and ((self:getHitVar("yvel")) == 0) then
		self:changeState {
			value = 5081
		}
	end
	
	-- State controller
	if (self:hitShakeOver()) and ((self:getHitVar("yvel")) ~= 0) then
		self:changeState {
			value = 5030
		}
	end
end

function Cloudi:state_5081()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "C",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitVelSet {
			x = 1
		}
	end
	
	-- State controller
	if (self:hitOver()) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[0] = 1
		end
	end
	
	-- State controller
	if (self:hitOver()) then
		self:changeState {
			value = 5110
		}
	end
end

function Cloudi:state_51()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		physics = "A",
	}
end

function Cloudi:state_5100()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) and ((self:getHitVar("fall.yvel")) == 0) and ((self:vel().x) > 1) then
		self:velSet {
			x = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:fallEnvShake {
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor((self:vel().y)))
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if ((not Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) and (not Utils.inInterval((self:anim()), "[", 5061, 5069, "]"))) or not (self:selfAnimExist((5100 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = 5100
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((Utils.inInterval((self:anim()), "[", 5051, 5059, "]")) or (Utils.inInterval((self:anim()), "[", 5061, 5069, "]"))) and (self:selfAnimExist((5100 + ((self:anim()) % 10)))) then
		self:changeAnim {
			value = (5100 + ((self:anim()) % 10))
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
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velMul {
			x = 0.75
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:getHitVar("fall.yvel")) == 0) then
		self:changeState {
			value = 5110
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:gameMakeAnim {
			value = ((60 + ((self.sysvar[1]) > 5)) + ((self.sysvar[1]) > 14)),
			pos = {0, 0},
			under = ((self.sysvar[1]) <= 14)
		}
	end
	
	-- State controller
	if (((self:time()) == 1) and ((self.sysvar[1]) > 14)) then
		self:gameMakeAnim {
			value = 61,
			pos = {0, 0},
			under = ((self.sysvar[1]) <= 14)
		}
	end
	
	-- State controller
	if ((self:time()) == 3) then
		self:hitFallDamage {
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:playSnd {
			value = {{"F", 7}, (((self.sysvar[1]) > 5) + ((self.sysvar[1]) > 14))}
		}
	end
	
	-- State controller
	if 1 then
		self:posFreeze {
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:changeState {
			value = 5101
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:forceFeedback {
			waveForm = "sinesquare",
			ampl = {128, -3, -.2, 0.005},
			time = 20
		}
	end
end

function Cloudi:state_5101()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		if (not Utils.inInterval((self:anim()), "[", 5101, 5109, "]")) or not (self:selfAnimExist((5160 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = 5160
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if (Utils.inInterval((self:anim()), "[", 5101, 5109, "]")) and (self:selfAnimExist((5160 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = (5160 + ((self:anim()) % 10))
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitFallVel {
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 20
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = 0.4
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 12) then
		self:changeState {
			value = 5110
		}
	end
end

function Cloudi:state_5110()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:fallEnvShake {
		}
	end
	
	-- State controller
	if (self:selfAnimExist((5110 + ((self:anim()) % 10)))) and (Utils.inInterval((self:anim()), "[", 5081, 5089, "]")) then
		self:changeAnim {
			persistent = 0,
			value = (5110 + ((self:anim()) % 10))
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:anim()), "[", 5110, 5119, "]")) then
		if (not Utils.inInterval((self:anim()), "[", 5161, 5169, "]")) or not (self:selfAnimExist((5170 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = 5170
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:anim()), "[", 5110, 5119, "]")) then
		if (Utils.inInterval((self:anim()), "[", 5161, 5169, "]")) and (self:selfAnimExist((5170 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = (5170 + ((self:anim()) % 10))
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:hitFallDamage {
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:getHitVar("fall.yvel")) ~= 0) then
		if self:canExecuteController{
			} then
			self.sysvar[1] = (self:floor((self:vel().y)))
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and not (self.sysvar[0]) then
		self:playSnd {
			value = {{"F", 7}, (((self.sysvar[1]) > 5) + ((self.sysvar[1]) > 14))}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and not (self.sysvar[0]) then
		self:gameMakeAnim {
			value = ((60 + ((self.sysvar[1]) > 5)) + ((self.sysvar[1]) > 14)),
			pos = {0, 0},
			under = ((self.sysvar[1]) <= 14)
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			y = 0
		}
	end
	
	-- State controller
	if (Utils.inInterval((self:anim()), "[", 5171, 5179, "]")) and (self:selfAnimExist((5110 + ((self:anim()) % 10)))) then
		if ((self:animTime()) == 0) or (self.sysvar[0]) then
			self:changeAnim {
				persistent = 0,
				value = (5110 + ((self:anim()) % 10))
			}
		end
	end
	
	-- State controller
	if (not Utils.inInterval((self:anim()), "[", 5111, 5119, "]")) then
		if ((self:animTime()) == 0) or (self.sysvar[0]) then
			self:changeAnim {
				persistent = 0,
				value = 5110
			}
		end
	end
	
	-- State controller
	if not (self:alive()) then
		if ((self:animTime()) == 0) or (self.sysvar[0]) or (Utils.inInterval((self:anim()), "[", 5110, 5119, "]")) then
			self:changeState {
				value = 5150
			}
		end
	end
	
	-- State controller
	if (self.sysvar[0]) and ((self:time()) == 0) then
		if self:canExecuteController{
			} then
			self.sysvar[0] = 0
		end
	end
	
	-- State controller
	if 1 then
		self:velMul {
			x = 0.85
		}
	end
	
	-- State controller
	if (self:alive()) and ((self:time()) == 0) then
		self:forceFeedback {
			time = 8,
			ampl = 240,
			waveForm = "sine"
		}
	end
	
	-- State controller
	if not (self:alive()) and ((self:time()) == 0) then
		self:forceFeedback {
			ampl = {200, 7, -.467},
			time = 30,
			waveForm = "sine"
		}
	end
	
	-- State controller
	if ((self:alive()) and ((self:time()) > 2)) then
		if ((self:command("back")) or (self:command("fwd"))) or ((self:command("holdback")) or (self:command("holdfwd"))) then
			self:changeState {
				value = 5888,
				ctrl = 0
			}
		end
	end
end

function Cloudi:state_5120()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "I",
		physics = "N",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		if (not Utils.inInterval((self:anim()), "[", 5111, 5119, "]")) or not (self:selfAnimExist((5120 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = 5120
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if (Utils.inInterval((self:anim()), "[", 5111, 5119, "]")) and (self:selfAnimExist((5120 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = (5120 + ((self:anim()) % 10))
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			x = 0
		}
	end
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = "SCA",
			time = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:hitFallSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:notHitBy {
			value = {"", "NT", "ST", "HT"},
			time = 12
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) then
		self:notHitBy {
			value2 = {"S", "NA"},
			time = 3
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

function Cloudi:state_5150()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "H",
		physics = "N",
		sprPriority = -3,
	}
	
	-- State controller
	if ((self:time()) == 0) and (self:selfAnimExist(5140)) then
		if ((not Utils.inInterval((self:anim()), "[", 5111, 5119, "]")) and (not Utils.inInterval((self:anim()), "[", 5171, 5179, "]"))) or not (self:selfAnimExist((5140 + ((self:anim()) % 10)))) then
			self:changeAnim {
				value = 5140
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((Utils.inInterval((self:anim()), "[", 5111, 5119, "]")) or (Utils.inInterval((self:anim()), "[", 5171, 5179, "]"))) and (self:selfAnimExist((5140 + ((self:anim()) % 10)))) then
		self:changeAnim {
			value = (5140 + ((self:anim()) % 10))
		}
	end
	
	-- State controller
	if ((self:matchOver()) == 1) and (Utils.inInterval((self:anim()), "[", 5140, 5149, "]")) and (self:selfAnimExist(((self:anim()) + 10))) then
		self:changeAnim {
			persistent = 0,
			value = ((self:anim()) + 10)
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and (not Utils.inInterval((self:anim()), "[", 5140, 5159, "]")) and (not Utils.inInterval((self:anim()), "[", 5110, 5119, "]")) then
		self:changeAnim {
			value = 5110
		}
	end
	
	-- State controller
	if 1 then
		self:velMul {
			x = 0.85
		}
	end
	
	-- State controller
	if ((self:vel().x) < .05) then
		self:velSet {
			persistent = 0,
			x = 0
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

function Cloudi:state_52()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		physics = "S",
		velSet = {0, 0},
		ctrl = 0,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:removeExplod {
			id = 101
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:isHelper(1112))) then
		self:modifyExplod {
			id = 1016,
			removeTime = 1
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:isHelper(1112))) then
		self:changeState {
			value = 1001
		}
	end
	
	-- State controller
	if (((self:time()) == 0) and (self:isHelper(3500))) or (((self:time()) == 0) and (self:isHelper(3501))) or (((self:time()) == 0) and (self:isHelper(3502))) or (((self:time()) == 0) and (self:isHelper(3503))) or (((self:time()) == 0) and (self:isHelper(3504))) or (((self:time()) == 0) and (self:isHelper(3505))) then
		self:changeState {
			value = 3503
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) == 3705) then
		self:changeState {
			value = 3706
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) == 3100) then
		self:changeState {
			value = 3101
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) == 3300) then
		self:changeState {
			value = 3301
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) == 3402) then
		self:changeState {
			value = 3403
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) == 2001) then
		self:changeState {
			value = 2002
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:prevStateNo()) ~= 2001) and ((self:prevStateNo()) ~= 8005) then
		self:changeAnim {
			value = 47
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
	if ((self:time()) == 3) and ((self:prevStateNo()) ~= 2001) and ((self:prevStateNo()) ~= 8005) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:explod {
			anim = {"F", 1117},
			id = 100,
			pos = {2, -16},
			posType = "p1",
			bindTime = 1,
			scale = {1, 1},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 0
		}
	end
	
	-- State controller
	if ((self:animTime()) == 0) and ((self:prevStateNo()) ~= 8005) then
		self:changeState {
			value = 0,
			ctrl = 1
		}
	end
end

function Cloudi:state_5200()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "N",
	}
	
	-- State controller
	if ((self:anim()) == 5035) and ((self:animTime()) == 0) then
		self:changeAnim {
			value = 5050
		}
	end
	
	-- State controller
	if 1 then
		self:velAdd {
			y = (self:getHitVar("yaccel"))
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 10) then
		self:selfState {
			value = 5201
		}
	end
end

function Cloudi:state_5201()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "H",
		physics = "A",
		anim = 5200,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:explod {
			ignoreHitPause = 0,
			anim = {"F", 320},
			id = 102,
			pos = {0, -30},
			posType = "p1",
			bindTime = -1,
			removeTime = -2,
			scale = {0.8, 0.8},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"S", 25}, 6}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:p2Dist().x) < -5) then
		self:turn {
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:velSet {
			x = -.15,
			y = -3.5
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = "SCA",
			time = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {128, 128, 128}
		}
	end
	
	-- State controller
	if ((self:time()) == 1) then
		self:gameMakeAnim {
			value = 60,
			pos = {0, 0},
			under = 1
		}
	end
end

function Cloudi:state_5210()
	-- State initialization
	self:setStateParams
	{
		stateType = "A",
		moveType = "I",
		physics = "N",
		anim = 5210,
		ctrl = 0,
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:explod {
			ignoreHitPause = 0,
			anim = {"F", 320},
			id = 102,
			pos = {0, -30},
			posType = "p1",
			bindTime = -1,
			removeTime = -2,
			scale = {0.8, 0.8},
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"S", 25}, 6}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:palFX {
			time = 3,
			add = {128, 128, 128}
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:posFreeze {
			value = 4
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:p2Dist().x) < -20) then
		self:turn {
		}
	end
	
	-- State controller
	if ((self:time()) == 4) then
		self:velMul {
			x = 0.8,
			y = 0.8
		}
	end
	
	-- State controller
	if ((self:time()) == 4) then
		self:velAdd {
			y = -4.5
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and ((self:vel().y) > 0) then
		self:velMul {
			y = 0.5
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and ((self:vel().y) > -3) then
		self:velAdd {
			y = -2
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and ((self:vel().y) > -2) then
		self:velAdd {
			y = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and (self:command("holdup")) then
		self:velAdd {
			y = -2
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and (self:command("holddown")) then
		self:velAdd {
			y = 1.5
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and (self:command("holdfwd")) then
		self:velMul {
			x = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 4) and (self:command("holdback")) then
		self:velAdd {
			x = -1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:notHitBy {
			value = "SCA",
			time = 15
		}
	end
	
	-- State controller
	if ((self:time()) == 20) then
		self:ctrlSet {
			value = 1
		}
	end
	
	-- State controller
	if ((self:time()) >= 4) then
		self:velAdd {
			y = 0.35
		}
	end
	
	-- State controller
	if ((self:vel().y) > 0) and ((self:pos().y) >= 0) then
		self:changeState {
			value = 52,
			ctrl = 1
		}
	end
end

function Cloudi:state_5500()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
		ctrl = 0,
		anim = 5300,
		velSet = {0, 0},
	}
	
	-- State controller
	if ((self:time()) == 0) and (self:selfAnimExist(5500)) then
		self:changeAnim {
			value = 5500
		}
	end
end

function Cloudi:state_5888()
	-- State initialization
	self:setStateParams
	{
		stateType = "L",
		moveType = "I",
		physics = "N",
		anim = 5120,
		velSet = {0, 0},
		ctrl = 0,
		powerAdd = 0,
		juggle = 0,
		faceP2 = 1,
		hitDefPersist = 0,
		moveHitPersist = 0,
		hitCountPersist = 0,
		sprPriority = 0,
	}
	
	-- State controller
	if 1 then
		self:notHitBy {
			value = "SCA"
		}
	end
	
	-- State controller
	if 1 then
		self:playerPush {
			value = 0
		}
	end
	
	-- State controller
	if not (self:time()) then
		self:posSet {
			y = 0
		}
	end
	
	-- State controller
	if (not (self:time()) and (self:command("holdfwd"))) then
		self:velSet {
			x = 4.5,
			y = 0
		}
	end
	
	-- State controller
	if (not (self:time()) and (self:command("holdback"))) then
		self:velSet {
			x = -4.5,
			y = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"F", 125}, 50}
		}
	end
	
	-- State controller
	if (((self:time()) == 1) and ((self:vel().x) > 0)) then
		self:changeAnim {
			value = 111
		}
	end
	
	-- State controller
	if (((self:time()) == 1) and ((self:vel().x) < 0)) then
		self:changeAnim {
			value = 110
		}
	end
	
	-- State controller
	if 1 then
		self:explod {
			persistent = 14,
			ignoreHitPause = 0,
			anim = {"F", 1201},
			id = 31402,
			pos = {1, -5},
			posType = "p1",
			bindTime = 1,
			scale = {0.2, 0.2},
			facing = (self:ifElse(((self:vel().x) > 0), 1, -1)),
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if 1 then
		self:explod {
			persistent = 7,
			ignoreHitPause = 0,
			anim = {"F", 1201},
			id = 31402,
			pos = {1, 1},
			posType = "p1",
			bindTime = 1,
			scale = {0.1, 0.1},
			facing = (self:ifElse(((self:vel().x) > 0), 1, -1)),
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((((self:time()) > 20) and (self:command("holdfwd") == 0)) or (((self:time()) > 30) and (self:command("holdfwd")))) or ((((self:time()) > 20) and (self:command("holdback") == 0)) or (((self:time()) > 30) and (self:command("holdback")))) or ((self:vel().x) == 0) then
		self:changeState {
			value = 5120
		}
	end
end

function Cloudi:state_5900()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
	}
	
	-- State controller
	if ((self:roundsExisted()) == 0) then
		self:varRangeSet {
			value = 0,
			first = 0,
			last = 57
		}
	end
	
	-- State controller
	if 1 then
		self:varSet {
			v = 58,
			value = 1000
		}
	end
	
	-- State controller
	if ((self:roundsExisted()) == 0) then
		self:varRangeSet {
			fvalue = 0
		}
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 1) then
		if ((self:teamMode() == "Single") or (self:teamMode() == "Turns")) or (self:teamMode() == "Simul") and ((self:id()) < (self:getPartner():id())) then
			self:varSet {
				v = 40,
				value = (self:id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if ((self:teamSide()) == 1) then
			self:varSet {
				v = 41,
				value = (self:getEnemyNear():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 1) then
		if (self:teamMode() == "Simul") and ((self:id()) < (self:getPartner():id())) then
			self:varSet {
				v = 42,
				value = (self:getPartner():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 1) then
		if (self:getEnemyNear():teamMode() == "Simul") then
			self:helper {
				helperType = "normal",
				name = "GrabIDHelper",
				id = 90000,
				pos = {0, 0},
				posType = "right",
				stateNo = 90000,
				keyCtrl = 0
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) then
		if ((self:teamSide()) == 2) then
			self:varSet {
				v = 40,
				value = (self:getEnemyNear():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 2) then
		if ((self:teamMode() == "Single") or (self:teamMode() == "Turns")) or (self:teamMode() == "Simul") and ((self:id()) < (self:getPartner():id())) then
			self:varSet {
				v = 41,
				value = (self:id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 2) then
		if (self:getEnemyNear():teamMode() == "Simul") then
			self:helper {
				helperType = "normal",
				name = "GrabIDHelper",
				id = 90000,
				pos = {0, 0},
				posType = "left",
				stateNo = 90000,
				keyCtrl = 0
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 2) then
		if (self:teamMode() == "Simul") and ((self:id()) < (self:getPartner():id())) then
			self:varSet {
				v = 43,
				value = (self:getPartner():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 1) then
		if (self:teamMode() == "Simul") and ((self:id()) > (self:getPartner():id())) then
			self:varSet {
				v = 40,
				value = (self:getPartner():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 1) then
		if (self:teamMode() == "Simul") and ((self:id()) > (self:getPartner():id())) then
			self:varSet {
				v = 42,
				value = (self:id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 2) then
		if (self:teamMode() == "Simul") and ((self:id()) > (self:getPartner():id())) then
			self:varSet {
				v = 41,
				value = (self:getPartner():id())
			}
		end
	end
	
	-- State controller
	if ((self:time()) == 0) and ((self:teamSide()) == 2) then
		if (self:teamMode() == "Simul") and ((self:id()) > (self:getPartner():id())) then
			self:varSet {
				v = 43,
				value = (self:id())
			}
		end
	end
	
	-- State controller
	if ((self:roundNo()) == 1) then
		self:changeState {
			value = 190
		}
	end
end

function Cloudi:state_9000()
	-- State initialization
	self:setStateParams
	{
		stateType = "U",
		moveType = "H",
		physics = "U",
		anim = (self:ifElse(((self:pos().y) <= 0), 5010, 5030)),
		ctrl = 0,
	}
	
	-- State controller
	if not (self:time()) then
		self:explod {
			anim = {"F", 94},
			id = 9002,
			pos = {0, -30},
			posType = "p1",
			facing = (self:ifElse(((self:facing()) == 1), 1, -1)),
			sprPriority = 12,
			onTop = 1,
			ownPal = 1,
			removeOnGetHit = 0,
			pauseMoveTime = 99999,
			superMoveTime = 99999,
			bindTime = 1
		}
	end
	
	-- State controller
	if (not (self:time()) and ((self:numHelper(30000)) ~= 0)) then
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
	if not (self:time()) then
		self:explod {
			anim = {"F", 310},
			id = 9002,
			pos = {(self:ifElse(((self:teamSide()) == 1), 60, 259)), 9},
			posType = "left",
			bindTime = -1,
			scale = {1.4, 0.4},
			sprPriority = 5,
			onTop = 1,
			ownPal = 1,
			superMoveTime = 99999999,
			pauseMoveTime = 99999999,
			facing = (self:ifElse(((self:teamSide()) == 1), 1, -1))
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:playSnd {
			value = {{"F", 120}, 10}
		}
	end
	
	-- State controller
	if not (self:time()) then
		self:bgPalFX {
			ignoreHitPause = 1,
			time = 6,
			add = {255, 0, 0},
			mul = {256, 256, 256},
			sinAdd = {255, 0, 0, 10},
			invertAll = 0,
			color = 256
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:superPause {
			time = 10,
			anim = 310,
			sound = {{"S", 25}, 7},
			pos = {-10, -30},
			darken = 1,
			p2DefMul = 0,
			powerAdd = 0,
			unHittable = 1
		}
	end
	
	-- State controller
	if not (self:time()) then
		self:varSet {
			fv = 14,
			value = 0
		}
	end
	
	-- State controller
	if ((self:time()) < 10) then
		self:notHitBy {
			value = "SCA"
		}
	end
	
	-- State controller
	if (not (self:time()) and ((self:pos().y) <= 0)) then
		self:stateTypeSet {
			physics = "S"
		}
	end
	
	-- State controller
	if (not (self:time()) and ((self:pos().y) <= 0)) then
		self:velSet {
			x = -2
		}
	end
	
	-- State controller
	if (((self:time()) == 85) and (self:stateType() ~= "A")) then
		self:changeState {
			value = 5050,
			ctrl = 0
		}
	end
	
	-- State controller
	if (((self:time()) == 15) and (self:stateType() == "A")) then
		self:changeState {
			value = 5050,
			ctrl = 0
		}
	end
	
	-- State controller
	if not (self:time()) then
		self:helper {
			helperType = "normal",
			name = "guardbreak",
			id = 9001,
			stateNo = 9001,
			pos = {0, -2000},
			posType = "p1",
			facing = 1,
			keyCtrl = 0,
			ownPal = 0
		}
	end
end

function Cloudi:state_90000()
	-- State initialization
	self:setStateParams
	{
		stateType = "S",
	}
	
	-- State controller
	if ((self:time()) == 0) then
		self:parentVarSet {
			v = (self:ifElse(((self:teamSide()) == 1), 43, 42)),
			value = (self:getEnemyNear():id())
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:destroySelf {
		}
	end
end

function Cloudi:state_9001()
	-- State initialization
	self:setStateParams
	{
		anim = 99999,
		ctrl = 0,
	}
	
	-- State controller
	if ((self:time()) == 100) then
		self:destroySelf {
		}
	end
end

function Cloudi:state_9005()
	-- State initialization
	self:setStateParams
	{
		moveType = "I",
		stateType = "U",
		physics = "U",
		ctrl = 1,
	}
	
	-- State controller
	if not (self:time()) then
		self:envShake {
			time = 4,
			freq = 60,
			ampl = -4,
			phase = 90
		}
	end
	
	-- State controller
	if (not (self:time()) and ((self:pos().y) <= 0)) then
		self:explod {
			ignoreHitPause = 0,
			anim = {"F", 1201},
			id = 9005,
			pos = {((self:ifElse(((self:random()) > 499), -21, (self:ifElse(((self:random()) > 499), -27, (self:ifElse(((self:random()) > 499), -15, -12)))))) - 5), -13},
			posType = "p1",
			bindTime = -1,
			scale = {0.3, 0.3},
			facing = 1,
			sprPriority = 5,
			ownPal = 1,
			removeOnGetHit = 1
		}
	end
	
	-- State controller
	if ((self:time()) == 0) then
		self:superPause {
			time = 10,
			sound = {{"F", 90}, 120},
			pos = {10, -25},
			anim = 315,
			darken = 1,
			p2DefMul = 0,
			powerAdd = 0,
			unHittable = 1
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
	if not (self:time()) then
		self:varAdd {
			fv = 14,
			value = -1.5
		}
	end
	
	-- State controller
	if 1 then
		self:changeAnim {
			value = (self:anim()),
			elem = (self:animElemNo(0))
		}
	end
	
	-- State controller
	if ((self:time()) == 11) then
		self:changeState {
			value = (self:prevStateNo()),
			ctrl = 0
		}
	end
end

