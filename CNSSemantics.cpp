// CNSSemantics.cpp — CNS controller, trigger and symbol-table definitions and lookups.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSSemantics.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern "C"
{
#	include "Helpers.h"
}

//#include <antlr3.h>

const char* dataTypeNames[] =
{
	"<unknown datatype>",
	"int",
	"float",
	"number",
	"id",
	"same",
	"string"
};

//////////////////////
// TRIGGERS

//////// REGULAR SYNTAX ///////

const char * constIDs[] =
{
// [Data] group
	"DATA.LIFE",
	"DATA.POWER",
	"DATA.ATTACK",
	"DATA.DEFENCE",
	"DATA.FALL.DEFENCE_MUL",
	"DATA.LIEDOWN.TIME",
	"DATA.AIRJUGGLE",
	"DATA.SPARKNO",
	"DATA.GUARD.SPARKNO",
	"DATA.KO.ECHO",
	"DATA.VOLUME",
	"DATA.INTPERSISTINDEX",
	"DATA.FLOATPERSISTINDEX",
// [Size] group
	"SIZE.XSCALE",
	"SIZE.YSCALE",
	"SIZE.GROUND.BACK",
	"SIZE.GROUND.FRONT",
	"SIZE.AIR.BACK",
	"SIZE.AIR.FRONT",
	"SIZE.HEIGHT",
	"SIZE.ATTACK.DIST",
	"SIZE.PROJ.ATTACK.DIST",
	"SIZE.PROJ.DOSCALE",
	"SIZE.HEAD.POS.X",
	"SIZE.MID.POS.X",
	"SIZE.MID.POS.Y",
	"SIZE.SHADOWOFFSET",
	"SIZE.DRAW.OFFSET.X",
	"SIZE.DRAW.OFFSET.Y",
//[Velocity] group
	"VELOCITY.WALK.FWD.X",
	"VELOCITY.WALK.BACK.X",
	"VELOCITY.RUN.FWD.X",
	"VELOCITY.RUN.FWD.Y",
	"VELOCITY.RUN.BACK.X",
	"VELOCITY.RUN.BACK.Y",
	"VELOCITY.JUMP.Y",
	"VELOCITY.JUMP.NEU.X",
	"VELOCITY.JUMP.BACK.X",
	"VELOCITY.JUMP.FWD.X",
	"VELOCITY.RUNJUMP.BACK.X",
	"VELOCITY.RUNJUMP.FWD.X",
	"VELOCITY.AIRJUMP.Y",
	"VELOCITY.AIRJUMP.NEU.X",
	"VELOCITY.AIRJUMP.BACK.X",
	"VELOCITY.AIRJUMP.FWD.X",
	"VELOCITY.AIR.GETHIT.GROUNDRECOVER.X",
	"VELOCITY.AIR.GETHIT.GROUNDRECOVER.Y",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.MUL.X",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.MUL.Y",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.ADD.X",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.ADD.Y",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.BACK",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.FWD",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.UP",
	"VELOCITY.AIR.GETHIT.AIRRECOVER.DOWN",
// [Movement] group
	"MOVEMENT.AIRJUMP.NUM",
	"MOVEMENT.AIRJUMP.HEIGHT",
	"MOVEMENT.YACCEL",
	"MOVEMENT.STAND.FRICTION",
	"MOVEMENT.CROUCH.FRICTION",
	"MOVEMENT.STAND.FRICTION.THRESHOLD",
	"MOVEMENT.CROUCH.FRICTION.THRESHOLD",
	"MOVEMENT.JUMP.CHANGEANIM.THRESHOLD",
	"MOVEMENT.AIR.GETHIT.GROUNDLEVEL",
	"MOVEMENT.AIR.GETHIT.GROUNDRECOVER.GROUND.THRESHOLD",
	"MOVEMENT.AIR.GETHIT.GROUNDRECOVER.GROUNDLEVEL",
	"MOVEMENT.AIR.GETHIT.AIRRECOVER.THRESHOLD",
	"MOVEMENT.AIR.GETHIT.AIRRECOVER.YACCEL",
	"MOVEMENT.AIR.GETHIT.TRIP.GROUNDLEVEL",
	"MOVEMENT.DOWN.BOUNCE.OFFSET.X",
	"MOVEMENT.DOWN.BOUNCE.OFFSET.Y",
	"MOVEMENT.DOWN.BOUNCE.YACCEL",
	"MOVEMENT.DOWN.BOUNCE.GROUNDLEVEL",
	"MOVEMENT.DOWN.FRICTION.THRESHOLD",
	"\0"
};

cns_dataTypeList_t cns_IDreturns =
{
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,

	CDT_FLOAT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,

	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,

	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT
};

const char * cns_hitVarIDs[] =
{	"XVELADD",
	"YVELADD",
	"TYPE",
	"ANIMTYPE",
	"AIRTYPE",
	"GROUNDTYPE",
	"DAMAGE",
	"HITCOUNT",
	"FALLCOUNT",
	"HITSHAKETIME",
	"HITTIME",
	"SLIDETIME",
	"CTRLTIME",
	"RECOVERTIME",
	"XOFF",
	"YOFF",
	"XVEL",
	"YVEL",
	"YACCEL",
	"CHAINID",
	"GUARDED",
	"ISBOUND",
	"FALL",
	"FALL.DAMAGE",
	"FALL.XVEL",
	"FALL.YVEL",
	"FALL.RECOVER",
	"FALL.RECOVERTIME",
	"FALL.KILL",
	"FALL.ENVSHAKE.TIME",
	"FALL.ENVSHAKE.FREQ",
	"FALL.ENVSHAKE.AMPL",
	"FALL.ENVSHAKE.PHASE",
	"\0"
};

cns_dataTypeList_t cns_hitVarReturns =
{
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_FLOAT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_INT,
	CDT_FLOAT,
	CDT_INT,
	CDT_FLOAT
};

const char * vector2DIDs[] =
{
	"X",
	"Y",
	"\0"
};

const char * stageVarNames[] =		// All of them return strings
{
	"INFO.AUTHOR",
	"INFO.DISPLAYNAME",
	"INFO.NAME",
	"\0"
};

cns_dataTypeList_t cns_stageVarReturns =
{
	CDT_STRING,
	CDT_STRING,
	CDT_STRING,
};

///// Allowed IDs for RHSs
const char * transIDList[]		= {"NONE", "ADD", "ADD1", "SUB", "\0"};
const char * flagIDList[]		= {"INTRO", "INVISIBLE", "ROUNDNOTOVER", "NOBARDISPLAY", "NOBG", "NOFG", "NOSTANDGUARD", "NOCROUCHGUARD", "NOAIRGUARD", "NOAUTOTURN", "NOJUGGLECHECK", "NOKOSND", "NOKOSLOW", "NOSHADOW", "GLOBALNOSHADOW", "NOMUSIC", "NOWALK", "TIMERFREEZE", "UNGUARDABLE", "\0"};
const char * bodyHeightList[]	= {"FOOT", "MID", "HEAD", "\0"};
const char * posTypeList[]		= {"P1", "P2", "FRONT", "BACK", "LEFT", "RIGHT", "\0"};
const char * waveFormList[]		= {"SINE", "SQUARE", "SINESQUARE", "OFF", "\0"};
const char * stateTypeList[]	= {"A", "C", "S", "N", "L", "\0"};
const char * helperTypeList[]	= {"NORMAL", "PLAYER", "\0"};
const char * affectTeamList[]	= {"B", "E", "F", "\0"};
const char * animTypeList[]		= {"LIGHT", "MEDIUM", "HARD", "BACK", "UP", "DIAGUP", "HEAVY", "\0"};
const char * priorityList[]		= {"DODGE", "HIT", "MISS", "\0"};
const char * groundTypeList[]	= {"HIGH", "LOW", "TRIP", "\0"};
const char * moveTypeList[]		= {"I", "A", "H", "\0"};
const char * physicsList[]		= {"A", "C", "S", "N", "\0"};
const char * transList[]		= {"DEFAULT", "NONE", "ADD", "ADDALPHA", "ADD1", "SUB", "\0"};

const char * hitArg1List[]		= {"S", "C", "A", "\0"};
const char * hitArg1FilterList[]= {"SCA", "SC", "SA", "CA", "S", "C", "A", "\0"};
const char * hitArg2List[]		= {"NA", "SA", "HA", "NP", "SP", "HP", "NT", "ST", "HT", "\0"};

const char * hitFlagsList[]		= {	"HLMA", "HLA", "HMA", "HLM", "HA", "HL", "HM", "H", "LMA", "LM", "LA", "L", "MA", "M", "A", "HLMAF", "HLAF", "HMAF",
									"HLMF", "HAF", "HLF", "HMF", "HF", "LMAF", "LMF", "LAF", "LF", "MAF", "MF", "AF", "HLMAD", "HLAD", "HMAD", "HLMD", "HAD",
									"HLD", "HMD", "HD", "LMAD", "LMD", "LAD", "LD", "MAD", "MD", "AD", "HLMAFD", "HLAFD", "HMAFD", "HLMFD", "HAFD", "HLFD",
									"HMFD", "HFD", "LMAFD", "LMFD", "LAFD", "LFD", "MAFD", "MFD", "AFD", "\0" };
const char * guardFlagsList[]	= { "H", "L", "A", "HA", "HL", "LH", "LA", "AH", "AL", "HLA", "HAL", "ALH", "AHL", "LHA", "LAH", "M", "AM", "MA", "\0"};

const char * teamModeList[]				= {"SINGLE", "SIMUL", "TURNS", "\0"};
const char * stateTypeTriggerList[]		= {"S", "C", "A", "L", "\0"};
const char * stateTypeStateDefList[]	= {"S", "C", "A", "L", "U", "\0"};
const char * moveTypeStateDefList[]		= {"A", "I", "H", "U", "\0"};
const char * physicsStateDefList[]		= {"S", "C", "A", "N", "U", "\0"};

// Semantic table for regular syntax triggers
cns_SemanticTable_t cns_RSTriggerSymbolTable =
{
	{"ABS",					"abs",				1, {CDT_NUMBER, nullptr, false},	CDT_SAME},
	{"ACOS",				"acos",				1, {CDT_FLOAT, nullptr, false},	CDT_FLOAT},
	{"AILEVEL",				"AILevel",			0, {}, CDT_INT},
	{"ALIVE",				"alive",			0, {}, CDT_INT},
	{"ANIM",				"anim",				0, {}, CDT_INT},
	{"ANIMELEM",			"animElem",			2, {{CDT_INT, nullptr, false}, {CDT_INT, nullptr, true}}, CDT_INT},
	{"ANIMELEMNO",			"animElemNo",		1, {CDT_INT, nullptr, false}, CDT_INT},
	{"ANIMELEMTIME",		"animElemTime",		1, {CDT_INT, nullptr, false}, CDT_INT},
	{"ANIMEXIST",			"animExist",		1, {CDT_INT, nullptr, false}, CDT_INT},
	{"ANIMTIME",			"animTime",			0, {}, CDT_INT},
	{"ASIN",				"asin",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"ATAN",				"atan",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"AUTHORNAME",			"authorName",		0, {}, CDT_STRING},
	{"BACKEDGEBODYDIST",	"backEdgeBodyDist",	0, {}, CDT_FLOAT},
	{"BACKEDGEDIST",		"backEdgeDist",		0, {}, CDT_FLOAT},
	{"CANRECOVER",			"canRecover",		0, {}, CDT_INT},
	{"CEIL",				"ceil",				1, {CDT_NUMBER, nullptr, false}, CDT_INT},
	{"COMMAND",				"command",			0, {}, CDT_STRING},
	{"COND",				"cond",				3, {{CDT_NUMBER, nullptr, false}, {CDT_NUMBER, nullptr, false}, {CDT_NUMBER, nullptr, false}}, CDT_NUMBER},
	{"CONST",				"_const",			1, {{CDT_ID, constIDs, false}}, CDT_NUMBER},
	{"CONST240P",			"const240p",		1, {{CDT_NUMBER, nullptr, false}}, CDT_NUMBER},
	{"CONST480P",			"const480p",		1, {{CDT_NUMBER, nullptr, false}}, CDT_NUMBER},
	{"CONST720P",			"const720p",		1, {{CDT_NUMBER, nullptr, false}}, CDT_NUMBER},
	{"COS",					"cos",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"CTRL",				"ctrl",				0, {}, CDT_INT},
	{"DRAWGAME",			"drawGame",			0, {}, CDT_INT},
	{"E",					"e",				0, {}, CDT_FLOAT},
	{"EXP",					"exp",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"FACING",				"facing",			0, {}, CDT_INT},
	{"FLOOR",				"floor",			1, {CDT_FLOAT, nullptr, false}, CDT_INT},
	{"FRONTEDGEBODYDIST",	"frontEdgeBodyDist",0, {}, CDT_FLOAT},
	{"FRONTEDGEDIST",		"frontEdgeDist",	0, {}, CDT_FLOAT},
	{"FVAR",				"fvar",				1, {CDT_INT, nullptr, false}, CDT_FLOAT},
	{"GAMEHEIGHT",			"gameHeight",		0, {}, CDT_FLOAT},
	{"GAMETIME",			"gameTime",			0, {}, CDT_INT},
	{"GAMEWIDTH",			"gameWidth",		0, {}, CDT_FLOAT},
	{"GETHITVAR",			"getHitVar",		1, {CDT_ID,		cns_hitVarIDs, false}, CDT_NUMBER},
	{"HITCOUNT",			"hitCount",			0, {}, CDT_INT},
	{"HITDEFATTR",			"hitDefAttr",		2, {{CDT_ID, hitArg1FilterList, false},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true},
													{CDT_ID, hitArg2List, true}}, CDT_INT},
	{"HITFALL",				"hitFall",			0, {}, CDT_INT},
	{"HITOVER",				"hitOver",			0, {}, CDT_INT},
	{"HITPAUSETIME",		"hitPauseTime",		0, {}, CDT_INT},
	{"HITSHAKEOVER",		"hitShakeOver",		0, {}, CDT_INT},
	{"HITVEL",				"hitVel",			1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"ID",					"id",				0, {}, CDT_INT},
	{"IFELSE",				"ifElse",			3, {{CDT_NUMBER, nullptr, false}, {CDT_NUMBER, nullptr, false}, {CDT_NUMBER, nullptr, false}}, CDT_NUMBER},
	{"INGUARDDIST",			"inGuardDist",		0, {}, CDT_INT},
	{"ISHELPER",			"isHelper",			1, {CDT_INT, nullptr, true}, CDT_INT},
	{"ISHOMETEAM",			"isHomeTeam",		0, {}, CDT_INT},
	{"LIFE",				"life",				0, {}, CDT_INT},
	{"LIFEMAX",				"lifeMax",			0, {}, CDT_INT},
	{"LN",					"ln",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"LOG",					"log",				2, {{CDT_FLOAT, nullptr, false}, {CDT_FLOAT, nullptr, true}}, CDT_FLOAT},
	{"LOSE",				"lose",				0, {}, CDT_INT},
	{"LOSEKO",				"loseKO",			0, {}, CDT_INT},
	{"LOSETIME",			"loseTime",			0, {}, CDT_INT},
	{"MATCHNO",				"matchNo",			0, {}, CDT_INT},
	{"MATCHOVER",			"matchOver",		0, {}, CDT_INT},
	{"MOVECONTACT",			"moveContact",		0, {}, CDT_INT},
	{"MOVEGUARDED",			"moveGuarded",		0, {}, CDT_INT},
	{"MOVEHIT",				"moveHit",			0, {}, CDT_INT},
	{"MOVETYPE",			"moveType",			1, {{CDT_ID, moveTypeList, true}}, CDT_INT},
	{"MOVEREVERSED",		"moveReversed",		0, {}, CDT_INT},
	{"NAME",				"name",				0, {}, CDT_STRING},
	{"NUMENEMY",			"numEnemy",			0, {}, CDT_INT},
	{"NUMEXPLOD",			"numExplod",		1, {CDT_INT, nullptr, true}, CDT_INT},
	{"NUMHELPER",			"numHelper",		1, {CDT_INT, nullptr, true}, CDT_INT},
	{"NUMPARTNER",			"numPartner",		0, {}, CDT_INT},
	{"NUMPROJ",				"numProj",			0, {}, CDT_INT},
	{"NUMPROJID",			"numProjID",		1, {CDT_INT, nullptr, false}, CDT_INT},
	{"NUMTARGET",			"numTarget",		1, {CDT_INT, nullptr, true}, CDT_INT},
	{"P1NAME",				"p1Name",			0, {}, CDT_STRING},
	{"P2BODYDIST",			"p2BodyDist",		1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"P2DIST",				"p2Dist",			1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"P2LIFE",				"p2Life",			0, {}, CDT_INT},
	{"P2MOVETYPE",			"p2MoveType",		1, {{CDT_ID, moveTypeList, false}}, CDT_INT},
	{"P2NAME",				"p1Name",			0, {}, CDT_STRING},
	{"P2STATENO",			"p2StateNo",		0, {}, CDT_INT},
	{"P2STATETYPE",			"p2StateType",		1, {{CDT_ID, stateTypeTriggerList, false}}, CDT_INT},
	{"P3NAME",				"p1Name",			0, {}, CDT_STRING},
	{"P4NAME",				"p1Name",			0, {}, CDT_STRING},
	{"PALNO",				"palNo",			0, {}, CDT_INT},
	{"PARENTDIST",			"parentDist",		1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"PI",					"pi",				0, {}, CDT_FLOAT},
	{"POS",					"pos",				1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"POWER",				"power",			0, {}, CDT_FLOAT},
	{"POWERMAX",			"powerMax",			0, {}, CDT_INT},
	{"PLAYERIDEXIST",		"playerIdExist",	1, {CDT_INT, nullptr, false}, CDT_INT},
	{"PREVSTATENO",			"prevStateNo",		0, {}, CDT_INT},
	{"PROJCANCELTIME",		"projCancelTime",	1, {CDT_INT, nullptr, false}, CDT_INT},
	{"PROJCONTACT",			"projContact",		2, {{CDT_INT, nullptr, false}, {CDT_INT, nullptr, true}}, CDT_INT},
	{"PROJCONTACTTIME",		"projContactTime",	1, {CDT_INT, nullptr, false}, CDT_INT},
	{"PROJGUARDED",			"projGuarded",		2, {{CDT_INT, nullptr, false}, {CDT_INT, nullptr, true}}, CDT_INT},
	{"PROJGUARDEDTIME",		"projGuardedTime",	1, {CDT_INT, nullptr, false}, CDT_INT},
	{"PROJHIT",				"projHit",			2, {{CDT_INT, nullptr, false}, {CDT_INT, nullptr, true}}, CDT_INT},
	{"PROJHITTIME",			"projHitTime",		1, {CDT_INT, nullptr, false}, CDT_INT},
	{"RANDOM",				"random",			0, {}, CDT_INT},
	{"ROOTDIST",			"rootDist",			1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"ROUNDNO",				"roundNo",			0, {}, CDT_INT},
	{"ROUNDSEXISTED",		"roundsExisted",	0, {}, CDT_INT},
	{"ROUNDSTATE",			"roundState",		0, {}, CDT_INT},
	{"SCREENPOS",			"screenPos",		1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"SELFANIMEXIST",		"selfAnimExist",	1, {CDT_INT, nullptr, false}, CDT_INT},
	{"SIN",					"sin",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"STATENO",				"stateNo",			0, {}, CDT_INT},
	{"STATETYPE",			"stateType",		1, {{CDT_ID, stateTypeTriggerList, false}}, CDT_INT},
	{"STAGEVAR",			"stageVar",			1, {CDT_STRING, stageVarNames, false}, CDT_INT},
	{"SYSFVAR",				"sysFVar",			1, {CDT_INT, nullptr, false}, CDT_FLOAT},
	{"SYSVAR",				"sysVar",			1, {CDT_INT, nullptr, false}, CDT_INT},
	{"TAN",					"tan",				1, {CDT_FLOAT, nullptr, false}, CDT_FLOAT},
	{"TEAMMODE",			"teamMode",			1, {{CDT_ID, teamModeList, false}}, CDT_INT},
	{"TEAMSIDE",			"teamSide",			0, {}, CDT_INT},
	{"TICKSPERSECOND",		"ticksPerSecond",	0, {}, CDT_INT},
	{"TIME",				"time",				0, {}, CDT_INT},
//	{"TIMEMOD",				"TimeMod",			0, {}, CDT_INT},
	{"UNIQHITCOUNT",		"uniqHitCount",		0, {}, CDT_INT},
	{"VAR",					"var",				1, {CDT_INT, nullptr, false}, CDT_INT},
	{"VEL",					"vel",				1, {CDT_ID, vector2DIDs, false}, CDT_FLOAT},
	{"WIN",					"win",				0, {}, CDT_INT},
	{"WINKO",				"winKO",			0, {}, CDT_INT},
	{"WINTIME",				"winTime",			0, {}, CDT_INT},
	{"WINPERFECT",			"winPerfect",		0, {}, CDT_INT},
	{"\0",					"\0",				0, {}, CDT_INT}
};

int lookupConstStringTable(const char **table, const char *what)
{
	int i = 0;
	const char * cName;
	while((cName = table[i])[0])
	{
		if(!strcmp(what, cName))
		{
			return i;
		} else {
			++i;
		}
	}

	return -1;
}

cns_Datatype_t getConstReturnType(int constID)
{
	return cns_IDreturns[constID];
}

int getConstIDByName(const char *cnstName)
{
	return lookupConstStringTable(constIDs, cnstName);
}

cns_Datatype_t getHitVarReturnType(int constID)
{
	return cns_hitVarReturns[constID];
}

int getHitVarIDByName(const char *cnstName)
{
	return lookupConstStringTable(cns_hitVarIDs, cnstName);
}



bool lookupTriggerSignature(const char * tName, cns_TriggerSignature_t * &ts)
{
	int i = 0;

	while((ts = &cns_RSTriggerSymbolTable[i])->UCName[0])
	{
		if(!strcmp(ts->UCName, tName))
		{
			return true;
		} else {
			++i;
		}
	}

	// S | F special case
	if(tName[0] == 'S' || tName[0] == 'F')
	{
		i = 0;
		++tName;
		while((ts = &cns_RSTriggerSymbolTable[i])->UCName[0])
		{
			if(!strcmp(ts->UCName, tName))
			{
				return true;
			} else {
				++i;
			}
		}
	}
	return false;
}


// Only for regular syntax ones
cns_Datatype_t cns_getTriggerReturnType(const char* tName)
{
	// Look up the trigger in the regular list
	//printf(">> %d\n", sizeof(cns_RSTriggerSymbolTable));

	cns_TriggerSignature_t * pTriggerSignature;

	if(lookupTriggerSignature(tName, pTriggerSignature))
	{
		// Special cases:
		// CONST
//		if(!strncmp(tName, "CONST", 5))
//		{
//			return ;
//		}

		return pTriggerSignature->returnType;
	}

	// if ... (non-regular syntax)

	return CDT_ERROR;
}

const char* cns_getDataTypeName(cns_Datatype_t t)
{
	return dataTypeNames[(unsigned int)t];
}

bool cns_triggerExists(const char * tName)
{
	cns_TriggerSignature_t * pTriggerSignature;

	char_string_toUpperSelf((char*)tName);

	if(lookupTriggerSignature(tName, pTriggerSignature))
	{
		return true;
	}

	// TODO: Lookup other tables

	return false;
}

//////////////////////////
// STATES & CONTROLLERS

bool cns_lookupControllerSignature(const char * cName, cns_ControllerSignature_t * &cs)
{
	int i = 0;

	char_string_toUpperSelf((char*)cName);

	while((cs = &cns_ControllerSymbolTable[i])->UCName[0])
	{
		if(!strcmp(cs->UCName, cName))
		{
			return true;
		} else {
			++i;
		}
	}
	return false;
}

bool cns_lookupControllerCommonAttrs(char * lhs, cns_ControllerAttribute_t *& attr)
{
	char_string_toUpperSelf(lhs);

	for(unsigned int i = 0; i < cns_CommonControllerAttrs.nAttrs; ++i)
	{
		if(!strcmp(lhs, cns_CommonControllerAttrs.attrs[i].UCName))
		{
			attr = &cns_CommonControllerAttrs.attrs[i];
			return true;
		}
	}

	attr = NULL;

	return false;
}

cns_ControllerSyntax_t cns_CommonControllerAttrs =
{
	5,	// N. of attrs
	{
		{// Attr 0
			"TYPE",
			"setType",
			1,	// N. of args
			{	// Arguments
				{	// Arg 0
					CDT_ID,
					stateTypeStateDefList,	// Allowed IDs
					false	// Optional
				}
			},
			true	// Optional
		},
		{// Attr 1
			"PHYSICS",
			"setPhysics",
			1,	// N. of args
			{	// Arguments
				{	// Arg 0
					CDT_ID,
					physicsStateDefList,	// Allowed IDs
					false	// Optional
				}
			},
			true	// Optional
		},
		{// Attr 2
			"MOVETYPE",
			"setMoveType",
			1,	// N. of args
			{	// Arguments
				{	// Arg 0
					CDT_ID,
					moveTypeStateDefList,	// Allowed IDs
					false	// Optional
				}
			},
			true	// Optional
		},
		{// Attr 3
			"PERSISTENT",
			"persistent",
			1,	// N. of args
			{	// Arguments
				{	// Arg 0
					CDT_INT,
					nullptr,	// Allowed IDs
					false	// Optional
				}
			},
			true	// Optional
		},
		{// Attr 4
			"IGNOREHITPAUSE",
			"ignoreHitPause",
			1,	// N. of args
			{	// Arguments
				{	// Arg 0
					CDT_INT,
					nullptr,	// Allowed IDs
					false	// Optional
				}
			},
			true	// Optional
		}
	}
};


///// Common state attrs

cns_ControllerSignature_t cns_stateDefSignature =
{"STATEDEF", "",
	1, // N. of syntaxes
	{	// Syntax 0
		{
			10,	// N. of attrs
			{
				{// Attr 0
					"VELSET",
					"velSet",
					2,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_FLOAT,
							nullptr,	// Allowed IDs
							false	// Optional
						},
						{	// Arg 1
							CDT_FLOAT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 1
					"CTRL",
					"ctrl",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 2
					"ANIM",
					"anim",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 3
					"SPRPRIORITY",
					"sprPriority",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 4
					"POWERADD",
					"powerAdd",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 5
					"JUGGLE",
					"juggle",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 6
					"FACEP2",
					"faceP2",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 7
					"HITDEFPERSIST",
					"hitDefPersist",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 8
					"MOVEHITPERSIST",
					"moveHitPersist",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				},
				{// Attr 9
					"HITCOUNTPERSIST",
					"hitCountPersist",
					1,	// N. of args
					{	// Arguments
						{	// Arg 0
							CDT_INT,
							nullptr,	// Allowed IDs
							false	// Optional
						}
					},
					true	// Optional
				}
			}
		}
	}
};

cns_ControllerSignature_t cns_ControllerSymbolTable[] =
{
	{"AFTERIMAGE", "afterImage",
		1,	// N. of syntaxes
		{	// Syntax 0
			{
				12,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"LENGTH",
						"length",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"PALCOLOR",
						"palColor",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"PALINVERTALL",
						"palInvertAll",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"PALBRIGHT",
						"palBright",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"PALCONTRAST",
						"palContrast",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"PALPOSTBRIGHT",
						"palPostBright",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"PALADD",
						"palAdd",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"PALMUL",
						"palMul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"TIMEGAP",
						"timeGap",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"FRAMEGAP",
						"frameGap",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"TRANS",
						"trans",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								transIDList,
								//{"NONE", "ADD", "ADD1", "SUB"},	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"AFTERIMAGETIME", "afterImageTime",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"ALLPALFX", "allPalFX",
		1,	// N. of syntaxes
		{	// Syntax 0
			{
				6,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ADD",
						"add",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"MUL",
						"mul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"SINADD",
						"sinAdd",
						4,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 3
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"INVERTALL",
						"invertAll",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"COLOR",
						"color",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ANGLEADD", "angleAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"ANGLEDRAW", "angleDraw",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"SCALE",
						"scale",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ANGLEMUL", "angleMul",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"ANGLESET", "angleSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"APPENDTOCLIPBOARD", "appendToClipboard",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"TEXT",
						"text",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_STRING,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"PARAMS",
						"params",
						6,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ASSERTSPECIAL", "assertSpecial",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"FLAG",
						"flag",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								flagIDList,	// Allowed IDs
								//{"INTRO", "INVISIBLE", "ROUNDNOTOVER", "NOBARDISPLAY", "NOBG", "NOFG", "NOSTANDGUARD", "NOCROUCHGUARD", "NOAIRGUARD", "NOAUTOTURN", "NOJUGGLECHECK", "NOKOSND", "NOKOSLOW", "NOSHADOW", "GLOBALNOSHADOW", "NOMUSIC", "NOWALK", "TIMERFREEZE", "UNGUARDABLE"},	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"FLAG2",
						"flag2",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								flagIDList,	// Allowed IDs
								//{"INTRO", "INVISIBLE", "ROUNDNOTOVER", "NOBARDISPLAY", "NOBG", "NOFG", "NOSTANDGUARD", "NOCROUCHGUARD", "NOAIRGUARD", "NOAUTOTURN", "NOJUGGLECHECK", "NOKOSND", "NOKOSLOW", "NOSHADOW", "GLOBALNOSHADOW", "NOMUSIC", "NOWALK", "TIMERFREEZE", "UNGUARDABLE"},	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"FLAG3",
						"flag3",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								flagIDList,	// Allowed IDs
								//{"INTRO", "INVISIBLE", "ROUNDNOTOVER", "NOBARDISPLAY", "NOBG", "NOFG", "NOSTANDGUARD", "NOCROUCHGUARD", "NOAIRGUARD", "NOAUTOTURN", "NOJUGGLECHECK", "NOKOSND", "NOKOSLOW", "NOSHADOW", "GLOBALNOSHADOW", "NOMUSIC", "NOWALK", "TIMERFREEZE", "UNGUARDABLE"},	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ATTACKDIST", "attackDist",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"ATTACKMULSET", "attackMulSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"BGPALFX", "bgPalFX",
		1,	// N. of syntaxes
		{	// Syntax 0
			{
				6,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ADD",
						"add",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"MUL",
						"mul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"SINADD",
						"sinAdd",
						4,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 3
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"INVERTALL",
						"invertAll",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"COLOR",
						"color",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"BINDTOPARENT", "bindToParent",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"FACING",
						"facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"BINDTOROOT", "bindToRoot",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"FACING",
						"facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"BINDTOTARGET", "bindToTarget",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_ID,
								bodyHeightList,	// Allowed IDs
								//{"FOOT", "MID", "HEAD"}
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"CHANGEANIM", "changeAnim",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ELEM",
						"elem",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"CHANGEANIM2", "changeAnim2",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ELEM",
						"elem",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"CHANGESTATE", "changeState",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"CTRL",
						"ctrl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ANIM",
						"anim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"CLEARCLIPBOARD", "clearClipboard",
		0,	// N. of syntaxes
		{}
	},
	{"CTRLSET", "ctrlSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"DEFENCEMULSET", "defenceMulSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"DESTROYSELF", "destroySelf",
		0,	// N. of syntaxes
		{}
	},
	{"DISPLAYTOCLIPBOARD", "displayToClipboard",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"TEXT",
						"text",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_STRING,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"PARAMS",
						"params",
						6,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_NUMBER,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ENVCOLOR", "envColor",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},

							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"UNDER",
						"under",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"ENVSHAKE", "envShake",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				4,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"FREQ",
						"freq",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"AMPL",
						"ampl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"PHASE",
						"phase",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"EXPLOD", "explod",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				22,	// N. of attrs
				{
					{// Attr 0
						"ANIM",
						"anim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"POSTYPE",
						"posType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								posTypeList,	// Allowed IDs
								//{"P1", "P2", "FRONT", "BACK", "LEFT", "RIGHT"} //	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"FACING",
						"facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"VFACING",
						"vFacing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"BINDTIME",
						"bindTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"VEL",
						"vel",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"ACCEL",
						"accel",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"RANDOM",
						"random",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"REMOVETIME",
						"removeTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"SUPERMOVE",
						"superMove",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 12
						"SUPERMOVETIME",
						"superMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 13
						"PAUSEMOVETIME",
						"pauseMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 14
						"SCALE",
						"scale",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 15
						"SPRPRIORITY",
						"sprPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 16
						"ONTOP",
						"onTop",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 17
						"SHADOW",
						"shadow",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 18
						"OWNPAL",
						"ownPal",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 19
						"REMOVEONGETHIT",
						"removeOnGetHit",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 20
						"TRANS",
						"trans",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								transList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 21
						"ALPHA",
						"alpha",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"EXPLODBINDTIME", "explodBindTime",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 1
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"FORCEFEEDBACK", "forceFeedback",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				5,	// N. of attrs
				{
					{// Attr 0
						"WAVEFORM",
						"waveForm",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								waveFormList,	// Allowed IDs
								// {"SINE", "SQUARE", "SINESQUARE", "OFF"} //Accepted IDS
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"FREQ",
						"freq",
						4,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"AMPL",
						"ampl",
						4,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"SELF",
						"self",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"FALLENVSHAKE", "fallEnvShake",
		0,	// N. of syntaxes
		{}
	},
	{"GAMEMAKEANIM", "gameMakeAnim",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				4,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"UNDER",
						"under",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"RANDOM",
						"random",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"GRAVITY", "gravity",
		0,	// N. of syntaxes
		{}
	},
	{"HELPER", "helper",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				22,	// N. of attrs
				{
					{// Attr 0
						"HELPERTYPE",
						"helperType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								helperTypeList,	// Allowed IDs
								// {"NORMAL", "PLAYER"} // Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"NAME",
						"name",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_STRING,
								nullptr,	// Allowed IDs
								// name in double quotes
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"POSTYPE",
						"posType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								posTypeList,	// Allowed IDs
								// {""""} // Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"FACING",
						"facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"STATENO",
						"stateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"KEYCTRL",
						"keyCtrl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"OWNPAL",
						"ownPal",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"SUPERMOVETIME",
						"superMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"PAUSEMOVETIME",
						"pauseMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"SIZE.XSCALE",
						"size_xScale",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 12
						"SIZE.YSCALE",
						"size_yScale",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 13
						"SIZE.GROUND.BACK",
						"size_ground_back",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 14
						"SIZE.GROUND.FRONT",
						"size_ground_front",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 15
						"SIZE.AIR.BACK",
						"size_air_back",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 16
						"SIZE.AIR.FRONT",
						"size_air_front",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 17
						"SIZE.HEIGHT",
						"size_height",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 18
						"SIZE.PROJ.DOSCALE",
						"size_proj_doScale",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 19
						"SIZE.HEAD.POS",
						"size_head_pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 20
						"SIZE.MID.POS",
						"size_mid_pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 21
						"SIZE.SHADOWOFFSET",
						"size_shadowOffset",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"HITADD", "hitAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"HITBY", "hitBy",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						10,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitArg1FilterList,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE2",
						"value2",
						10,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitArg1List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"HITDEF", "hitDef",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				81,	// N. of attrs
				{
					{// Attr 0
						"ATTR",
						"attr",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitArg1List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"HITFLAG",
						"hitFlag",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitFlagsList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"GUARDFLAG",
						"guardFlag",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								guardFlagsList,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"AFFECTTEAM",
						"affectTeam",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								affectTeamList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"ANIMTYPE",
						"animType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								animTypeList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"AIR.ANIMTYPE",
						"air_animType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								animTypeList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"FALL.ANIMTYPE",
						"fall_animType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								animTypeList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"PRIORITY",
						"priority",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_ID,
								priorityList,	// Allowed IDs
								//{"DODGE", "HIT", "MISS"}	// Accepted IDS
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"DAMAGE",
						"damage",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"PAUSETIME",
						"pauseTime",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"GUARD.PAUSETIME",
						"guard_pauseTime",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"SPARKNO",
						"sparkNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 12
						"GUARD.SPARKNO",
						"guard_sparkNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 13
						"SPARKXY",
						"sparkXY",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 14
						"HITSOUND",
						"hitSound",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 15
						"GUARDSOUND",
						"guardSound",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 16
						"GROUND.TYPE",
						"ground_type",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								groundTypeList,	// Allowed IDs
								// {"HIGH", "LOW", "TRIP"} // Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 17
						"AIR.TYPE",
						"air_type",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								groundTypeList,	// Allowed IDs
								// {"HIGH", "LOW", "TRIP"} // Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 18
						"GROUND.SLIDETIME",
						"ground_slideTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 19
						"GUARD.SLIDETIME",
						"guard_slideTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 20
						"GROUND.HITTIME",
						"ground_hitTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 21
						"GUARD.HITTIME",
						"guard_hitTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 22
						"AIR.HITTIME",
						"air_hitTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 23
						"GUARD.CTRLTIME",
						"guard_ctrlTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 24
						"GUARD.DIST",
						"guard_dist",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 25
						"YACCEL",
						"yAccel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 26
						"GROUND.VELOCITY",
						"ground_velocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 27
						"GUARD.VELOCITY",
						"guard_velocity",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 28
						"AIR.VELOCITY",
						"air_velocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 29
						"AIRGUARD.VELOCITY",
						"airGuard_velocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 30
						"GROUND.CORNERPUSH.VELOFF",
						"ground_cornerPush_veloff",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 31
						"AIR.CORNERPUSH.VELOFF",
						"air_cornerPush_veloff",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 32
						"DOWN.CORNERPUSH.VELOFF",
						"down_cornerPush_veloff",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 33
						"GUARD.CORNERPUSH.VELOFF",
						"guard_cornerPush_veloff",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 34
						"AIRGUARD.CORNERPUSH.VELOFF",
						"airGuard_cornerPush_velOff",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 35
						"AIRGUARD.CTRLTIME",
						"airGuard_ctrlTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 36
						"AIR.JUGGLE",
						"air_juggle",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 37
						"MINDIST",
						"minDist",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 38
						"MAXDIST",
						"maxDist",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 39
						"SNAP",
						"snap",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 40
						"P1SPRPRIORITY",
						"p1SprPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 41
						"P2SPRPRIORITY",
						"p2SprPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 42
						"P1FACING",
						"p1Facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 43
						"P1GETP2FACING",
						"p1GetP2Facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 44
						"P2FACING",
						"p2Facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 45
						"P1STATENO",
						"p1StateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 46
						"P2STATENO",
						"p2StateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 47
						"P2GETP1STATE",
						"p2GetP1State",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 48
						"FORCESTAND",
						"forceStand",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 49
						"FALL",
						"fall",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 50
						"FALL.XVELOCITY",
						"fall_xVelocity",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 51
						"FALL.YVELOCITY",
						"fall_yVelocity",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 52
						"FALL.RECOVER",
						"fall_recover",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 53
						"FALL.RECOVERTIME",
						"fall_recoverTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 54
						"FALL.DAMAGE",
						"fall_damage",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 55
						"AIR.FALL",
						"air_fall",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 56
						"FORCENOFALL",
						"forceNoFall",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 57
						"DOWN.VELOCITY",
						"down_velocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 58
						"DOWN.HITTIME",
						"down_hitTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 59
						"DOWN.BOUNCE",
						"down_bounce",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 60
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 61
						"CHAINID",
						"chainId",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 62
						"NOCHAINID",
						"noChainId",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 63
						"HITONCE",
						"hitOnce",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 64
						"KILL",
						"kill",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 65
						"GUARD.KILL",
						"guard_kill",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 66
						"FALL.KILL",
						"fall_kill",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 67
						"NUMHITS",
						"numhits",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 68
						"GETPOWER",
						"getPower",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 69
						"GIVEPOWER",
						"givePower",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 70
						"PALFX.TIME",
						"palFX_Time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 71
						"PALFX.MUL",
						"palFX_mul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 72
						"PALFX.ADD",
						"palFX_add",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 73
						"ENVSHAKE.TIME",
						"envShake_time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 74
						"ENVSHAKE.FREQ",
						"envShake_freq",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 75
						"ENVSHAKE.AMPL",
						"envShake_ampl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 76
						"ENVSHAKE.PHASE",
						"envShake_phase",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 77
						"FALL.ENVSHAKE.TIME",
						"fall_envShake_time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 78
						"FALL.ENVSHAKE.FREQ",
						"fall_envShake_freq",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 79
						"FALL.ENVSHAKE.AMPL",
						"fall_envShake_ampl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 80
						"FALL.ENVSHAKE.PHASE",
						"fall_envShake_phase",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"HITFALLDAMAGE", "hitFallDamage",
		0,	// N. of syntaxes
		{}
	},
	{"HITFALLSET", "hitFallSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"XVEL",
						"xVel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"YVEL",
						"yVel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"HITFALLVEL", "hitFallVel",
		0,	// N. of syntaxes
		{}
	},
	{"HITOVERRIDE", "hitOverride",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				5,	// N. of attrs
				{
					{// Attr 0
						"ATTR",
						"attr",
						10,	// N. of args
						{
							{	// Arg 0
								CDT_ID,
								hitArg1FilterList,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"STATENO",
						"stateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 2
						"SLOT",
						"slot",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"FORCEAIR",
						"forceAir",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"HITVELSET", "hitVelSet",  //deprecated
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"LIFEADD", "lifeAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"KILL",
						"kill",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ABSOLUTE",
						"absolute",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"LIFESET", "lifeSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"MAKEDUST", "makeDust",
	1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"POS2",
						"pos2",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 0
						"SPACING",
						"spacing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"MODIFYEXPLOD", "modifyExplod",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				22,	// N. of attrs
				{
					{// Attr 0
						"ANIM",
						"anim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"POSTYPE",
						"posType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								posTypeList,	// Allowed IDs
								//{"P1", "P2", "FRONT", "BACK", "LEFT", "RIGHT"} //	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"FACING",
						"facing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"VFACING",
						"vFacing",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"BINDTIME",
						"bindTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"VEL",
						"vel",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"ACCEL",
						"accel",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"RANDOM",
						"random",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"REMOVETIME",
						"removeTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"SUPERMOVE",
						"superMove",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 12
						"SUPERMOVETIME",
						"superMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 13
						"PAUSEMOVETIME",
						"pauseMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 14
						"SCALE",
						"scale",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 15
						"SPRPRIORITY",
						"sprPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 16
						"ONTOP",
						"onTop",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 17
						"SHADOW",
						"shadow",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 18
						"OWNPAL",
						"ownPal",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 19
						"REMOVEONGETHIT",
						"removeOnGetHit",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 20
						"TRANS",
						"trans",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								transList,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 21
						"ALPHA",
						"alpha",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"MOVEHITRESET", "moveHitReset",
		0,	// N. of syntaxes
		{}
	},
	{"NOTHITBY", "notHitBy",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						10,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitArg1FilterList,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE2",
						"value2",
						10,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								nullptr,	// Allowed IDs
								//{ATTR_STRING}	// look these in detail
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"NULL", "null",
		0,	// N. of syntaxes
		{}
	},
	{"OFFSET", "offSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"PALFX", "palFX",
		1,	// N. of syntaxes
		{	// Syntax 0
			{
				6,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ADD",
						"add",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"MUL",
						"mul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"SINADD",
						"sinAdd",
						4,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 3
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"INVERTALL",
						"invertAll",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"COLOR",
						"color",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"PARENTVARADD", "parentVarAdd",
		6,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"V",
						"v",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"FV",
						"fv",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 2
				1,	// N. of attrs
				{
					{// Attr 0
						"VAR",
						"var()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 3
				1,	// N. of attrs
				{
					{// Attr 0
						"FVAR",
						"fVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 4
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSVAR",
						"sysVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 5
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSFVAR",
						"sysFVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"PARENTVARSET", "parentVarSet",
		6,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"V",
						"v",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"FV",
						"fv",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 2
				1,	// N. of attrs
				{
					{// Attr 0
						"VAR",
						"var()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 3
				1,	// N. of attrs
				{
					{// Attr 0
						"FVAR",
						"fVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 4
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSVAR",
						"sysVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 5
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSFVAR",
						"sysFVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"PAUSE", "pause",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				4,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ENDCMDBUFTIME",
						"endCmdBufTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"MOVETIME",
						"moveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"PAUSEBG",
						"pauseBG",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"PLAYERPUSH", "playerPush",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"PLAYSND", "playSnd",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				8,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"VOLUMESCALE",
						"volumeScale",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"CHANNEL",
						"channel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"LOWPRIORITY",
						"lowPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"FREQMUL",
						"freqMul",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"LOOP",
						"loop",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"PAN",
						"pan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"ABSPAN",
						"absPan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 1
				8,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"VOLUME",
						"volume",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"CHANNEL",
						"channel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"LOWPRIORITY",
						"lowPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"FREQMUL",
						"freqMul",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"LOOP",
						"loop",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"PAN",
						"pan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"ABSPAN",
						"absPan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"POSADD", "posAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"POSFREEZE", "posFreeze",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"POSSET", "posSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"POWERADD", "powerAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"POWERSET", "powerSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"PROJECTILE", "projectile",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				36,	// N. of attrs
				{
					{// Attr 0
						"PROJID",
						"projId",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"PROJANIM",
						"projAnim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"PROJHITANIM",
						"projHitAnim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"PROJREMANIM",
						"projRemanim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"PROJCANCELANIM",
						"projCancelAnim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"PROJSCALE",
						"projScale",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"PROJREMOVE",
						"projRemove",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"PROJREMOVETIME",
						"projRemoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"VELOCITY",
						"velocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"REMVELOCITY",
						"remVelocity",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"ACCEL",
						"accel",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 11
						"VELMUL",
						"velMul",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 12
						"PROJHITS",
						"projHits",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 13
						"PROJMISSTIME",
						"projMissTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 14
						"PROJPRIORITY",
						"projPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 15
						"PROJSPRPRIORITY",
						"projSprPriority",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 16
						"PROJEDGEBOUND",
						"projEdgeBound",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 17
						"PROJSTAGEBOUND",
						"ProjStageBound",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 18
						"PROJHEIGHTBOUND",
						"projHeightBound",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 19
						"OFFSET",
						"offSet",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 20
						"POSTYPE",
						"posType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								posTypeList,	// Allowed IDs
								// {"P1", "P2", "FRONT", "BACK", "LEFT", "RIGHT"} // Accepted Ids
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 21
						"PROJSHADOW",
						"projShadow",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 22
						"SUPERMOVETIME",
						"superMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 23
						"PAUSEMOVETIME",
						"pauseMoveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 24
						"AFTERIMAGE.TIME",
						"afterImage_time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 25
						"AFTERIMAGE.LENGTH",
						"afterImage_length",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 26
						"AFTERIMAGE.PALCOLOR",
						"afterImage_palColor",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 27
						"AFTERIMAGE.PALINVERTALL",
						"afterImage_palInvertAll",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 28
						"AFTERIMAGE.PALBRIGHT",
						"afterImage_palBright",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 29
						"AFTERIMAGE.PALCONTRAST",
						"afterImage_palContrast",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 30
						"AFTERIMAGE.PALPOSTBRIGHT",
						"afterImage_palPostBright",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 31
						"AFTERIMAGE.PALADD",
						"afterImage_palAdd",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 32
						"AFTERIMAGE.PALMUL",
						"afterImage_palMul",
						3,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 2
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 33
						"AFTERIMAGE.TIMEGAP",
						"afterImage_timeGap",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 34
						"AFTERIMAGE.FRAMEGAP",
						"afterImage_frameGap",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 35
						"AFTERIMAGE.TRANS",
						"afterImage_trans",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								transIDList,
								//{"NONE", "ADD", "ADD1", "SUB"},	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"REMAPPAL", "remapPal",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"SOURCE",
						"source",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"DEST",
						"dest",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"REMOVEEXPLOD", "removeExplod",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"REVERSALDEF", "reversalDef",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				6,	// N. of attrs
				{
					{// Attr 0
						"REVERSAL.ATTR",
						"reversal_attr",
						10,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								hitArg1FilterList,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 2
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 3
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 4
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 5
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 6
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 7
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 8
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 9
								CDT_ID,
								hitArg2List,	// Allowed IDs
								true	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"PAUSETIME",
						"pauseTime",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"SPARKNO",
						"sparkNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"HITSOUND",
						"hitSound",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"P1STATENO",
						"p1StateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"P2STATENO",
						"p2StateNo",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"SCREENBOUND", "screenBound",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"MOVECAMERA",
						"moveCamera",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"SELFSTATE", "selfState",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"CTRL",
						"ctrl",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ANIM",
						"anim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"SPRPRIORITY", "sprPriority",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"STATETYPESET", "stateTypeSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"STATETYPE",
						"stateType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								stateTypeList,	// Allowed IDs
								//{"A","C","S","N","L"} //Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"MOVETYPE",
						"moveType",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								moveTypeList,	// Allowed IDs
								//{"I","A","H"} //Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"PHYSICS",
						"physics",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								physicsList,	// Allowed IDs
								//{"A","C","S","N"} //Accepted IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"SNDPAN", "sndPan",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"CHANNEL",
						"channel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"PAN",
						"pan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"CHANNEL",
						"channel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ABSPAN",
						"absPan",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"STOPSND", "stopSnd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"CHANNEL",
						"channel",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"SUPERPAUSE", "superPause",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				10,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ANIM",
						"anim",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"SOUND",
						"sound",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								true	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 4
						"DARKEN",
						"darken",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 5
						"P2DEFMUL",
						"p2DefMul",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 6
						"POWERADD",
						"powerAdd",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 7
						"UNHITTABLE",
						"unHittable",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 8
						"ENDCMDBUFTIME",
						"endCmdBufTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 9
						"MOVETIME",
						"moveTime",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 10
						"PAUSEBG",
						"pauseBG",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETBIND", "targetBind",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"TIME",
						"time",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"POS",
						"pos",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETDROP", "targetDrop",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"EXCLUDEID",
						"excludeID",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"KEEPONE",
						"keepOne",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETFACING", "targetFacing",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETLIFEADD", "targetLifeAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				4,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"KILL",
						"kill",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 3
						"ABSOLUTE",
						"absolute",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETPOWERADD", "targetPowerAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETSTATE", "targetState",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETVELADD", "targetVelAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TARGETVELSET", "targetVelSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"ID",
						"id",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TRANS", "trans",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"TRANS",
						"trans",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_ID,
								transList,	// Allowed IDs
								// {"DEFAULT", "NONE", "ADD", "ADDALPHA", "ADD1", "SUB"} // Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"ALPHA",
						"alpha",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"TURN", "turn",
		0,	// N. of syntaxes
		{}
	},
	{"VARADD", "varAdd",
		6,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"V",
						"v",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"FV",
						"fv",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 2
				1,	// N. of attrs
				{
					{// Attr 0
						"VAR",
						"var()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 3
				1,	// N. of attrs
				{
					{// Attr 0
						"FVAR",
						"fVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 4
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSVAR",
						"sysVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 5
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSFVAR",
						"sysFVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"VARRANDOM", "varRandom",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"V",
						"v",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"RANGE",
						"range",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"VARRANGESET", "varRangeSet",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"FIRST",
						"first",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"LAST",
						"last",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 0
				3,	// N. of attrs
				{
					{// Attr 0
						"FVALUE",
						"fvalue",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"FIRST",
						"first",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 2
						"LAST",
						"last",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"VARSET", "varSet",
		6,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"V",
						"v",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 1
				2,	// N. of attrs
				{
					{// Attr 0
						"FV",
						"fv",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					},
					{// Attr 1
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 2
				1,	// N. of attrs
				{
					{// Attr 0
						"VAR",
						"var()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 3
				1,	// N. of attrs
				{
					{// Attr 0
						"FVAR",
						"fVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 4
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSVAR",
						"sysVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			},
			{	// Syntax 5
				1,	// N. of attrs
				{
					{// Attr 0
						"SYSFVAR",
						"sysFVar()",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						false	// Optional
					}
				}
			}
		}
	},
	{"VELADD", "velAdd",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"VELMUL", "velMul",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"VELSET", "velSet",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"X",
						"x",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"Y",
						"y",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_FLOAT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"VICTORYQUOTE", "victoryQuote",
		1,	// N. of syntaxes
		{
			{	// Syntax 0
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						1,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"WIDTH", "width",
		2,	// N. of syntaxes
		{
			{	// Syntax 0
				2,	// N. of attrs
				{
					{// Attr 0
						"EDGE",
						"edge",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					},
					{// Attr 1
						"PLAYER",
						"player",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			},
			{	// Syntax 1
				1,	// N. of attrs
				{
					{// Attr 0
						"VALUE",
						"value",
						2,	// N. of args
						{	// Arguments
							{	// Arg 0
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							},
							{	// Arg 1
								CDT_INT,
								nullptr,	// Allowed IDs
								false	// Optional
							}
						},
						true	// Optional
					}
				}
			}
		}
	},
	{"\0", "\0",
		0,
		{}
	}
};

