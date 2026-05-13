/*
   Cloudi_master.cpp
   Master file for Cloudi
   Generated on 2026-05-13.

   by Sourcy Code Translator
   (c) 2017 - radexx

  Runtime version: 1.0

*/


#include "../cns/Cloudi_master.h"

void Cloudi::InitInfo(Constants& constants, ButtonRemaps& btnRemaps, Commands& commands, CommandDefaults& cmdDefaults)
{
	// Button remaps
	

	btnRemaps[BTN_x] = BTN_x;
	btnRemaps[BTN_y] = BTN_y;
	btnRemaps[BTN_z] = BTN_z;
	btnRemaps[BTN_b] = BTN_b;
	btnRemaps[BTN_s] = BTN_s;
	{
		CommandDefinition cd;
		cd.name = "ougi1";
		cd.command = "F,B,D,F,x";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi2";
		cd.command = "D,F,x";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Up";
		cd.command = "D,F,B,U,a+b+c+x+y+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Foward";
		cd.command = "D,D,B,U,x+y+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Down0";
		cd.command = "D,F,B,U,U,a+b+c+x+y+z+b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Up0";
		cd.command = "D,F,B,U,U,a+b+c+x+y+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Foward0";
		cd.command = "D,D,B,U+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Run";
		cd.command = "D,D,B,B,U,x+y+y+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Down";
		cd.command = "D,D,B,U,x+y+y+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Up";
		cd.command = "D,D,B,U,x+y+y+c+x+y+z+y+z+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Foward";
		cd.command = "D,D,B,U,x+y+y+c+x+y+z+y+y+y+y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Back";
		cd.command = "D,U,U,x+y+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi3";
		cd.command = "D,F,U,x";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Back0";
		cd.command = "D,U,U,x+y+c+x+y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Up0";
		cd.command = "D,D,B,U,B,x+y+y+c+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_SP_Down0";
		cd.command = "D,D,B,B,x+y+y+c+c+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI1";
		cd.command = "D,U,U,x+y+x+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI2";
		cd.command = "D,D,D,x+y+z+z+b+c+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI3";
		cd.command = "D,U,x+y+x+z+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI4";
		cd.command = "D,D,D,x+y+z+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI5";
		cd.command = "U,U,x+y+x+z+b+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI6";
		cd.command = "D,D,x+y+z+z+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI7";
		cd.command = "D,D,x+y+z+z+z+z+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi4";
		cd.command = "B,F,B,y";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_OUGI8";
		cd.command = "D,D,x+y+z+z+z+z+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "FF";
		cd.command = "F,F";
		cd.time = 10;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "BB";
		cd.command = "B,B";
		cd.time = 10;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "x+y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "x+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "a+b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "b+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "recovery";
		cd.command = "a+c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_x";
		cd.command = "/$B,x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi5";
		cd.command = "F,B,D,y";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_y";
		cd.command = "/$B,y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_z";
		cd.command = "/$B,z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_x";
		cd.command = "/$D,x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_y";
		cd.command = "/$D,y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_z";
		cd.command = "/$D,z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_x";
		cd.command = "/$F,x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_y";
		cd.command = "/$F,y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_z";
		cd.command = "/$F,z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_x";
		cd.command = "/$U,x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_y";
		cd.command = "/$U,y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi6";
		cd.command = "D,B,F,y";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_z";
		cd.command = "/$U,z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_a";
		cd.command = "/$B,a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_b";
		cd.command = "/$B,b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back_c";
		cd.command = "/$B,c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_a";
		cd.command = "/$D,a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_b";
		cd.command = "/$D,b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down_c";
		cd.command = "/$D,c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_a";
		cd.command = "/$F,a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_b";
		cd.command = "/$F,b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd_c";
		cd.command = "/$F,c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi7";
		cd.command = "F,D,B,y+x";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_a";
		cd.command = "/$U,a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_b";
		cd.command = "/$U,b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up_c";
		cd.command = "/$U,c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "a";
		cd.command = "a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "b";
		cd.command = "b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "c";
		cd.command = "c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "x";
		cd.command = "x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "y";
		cd.command = "y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "z";
		cd.command = "z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "s";
		cd.command = "s";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "ougi8";
		cd.command = "D,D,B,y+x";
		cd.time = 30;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "fwd";
		cd.command = "$F";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "downfwd";
		cd.command = "$DF";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "down";
		cd.command = "$D";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "downback";
		cd.command = "$DB";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "back";
		cd.command = "$B";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "upback";
		cd.command = "$UB";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "up";
		cd.command = "$U";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "upfwd";
		cd.command = "$UF";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_x";
		cd.command = "/x";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_y";
		cd.command = "/y";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Back";
		cd.command = "D,F,B,U,B,U,a+b+c+x+y+z+b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_z";
		cd.command = "/z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_a";
		cd.command = "/a";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_b";
		cd.command = "/b";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_c";
		cd.command = "/c";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "hold_s";
		cd.command = "/s";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holdfwd";
		cd.command = "/$F";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holddownfwd";
		cd.command = "/$DF";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holddown";
		cd.command = "/$D";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holddownback";
		cd.command = "/$DB";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holdback";
		cd.command = "/$B";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "AI_ATK_Down";
		cd.command = "D,F,B,U,U,a+b+a+b+x+y+z";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holdupback";
		cd.command = "/$UB";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holdup";
		cd.command = "/$U";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		CommandDefinition cd;
		cd.name = "holdupfwd";
		cd.command = "/$UF";
		cd.time = 1;
		commands.push_back(cd);
	}

	{
		constants.data.life = 1000;
		constants.data.power = 3000;
		constants.data.attack = 80;
		constants.data.defence = 100;
		constants.data.fall_defence_up = 50;
		constants.data.liedown_time = 60;
		constants.data.airjuggle = 15;
		constants.data.sparkno = 2;
		constants.data.guard_sparkno = 40;
		constants.data.ko_echo = 0;
		constants.data.volume = 0;
		constants.data.intpersistindex = 57;
		constants.data.floatpersistindex = 40;
	}

	{
		constants.movement.airjump_num = 1;
		constants.movement.airjump_height = 35;
		constants.movement.yaccel = .44f;
		constants.movement.stand_friction = .85f;
		constants.movement.crouch_friction = .82f;
	}

	{
		constants.size.xscale = 1;
		constants.size.yscale = 1;
		constants.size.ground_back = 15;
		constants.size.ground_front = 16;
		constants.size.air_back = 12;
		constants.size.air_front = 12;
		constants.size.height = 60;
		constants.size.attack_dist = 160;
		constants.size.proj_attack_dist = 90;
		constants.size.proj_doscale = 0;
		constants.size.head_pos = {-5, -90};
		constants.size.mid_pos = {-5, -60};
		constants.size.shadowoffset = 0;
		constants.size.draw_offset = {0, 0};
	}

	{
		constants.velocity.walk_fwd = 1.6f;
		constants.velocity.walk_back = -1.0;
		constants.velocity.run_fwd = {3.2f, 0};
		constants.velocity.run_back = {-3.5, -3.2};
		constants.velocity.jump_neu = {0, -7.4};
		constants.velocity.jump_back = -2.55;
		constants.velocity.jump_fwd = 2.5f;
		constants.velocity.runjump_back = {-2.55, -7.1};
		constants.velocity.runjump_fwd = {4, -7.8};
		constants.velocity.airjump_neu = {0, -7.1};
		constants.velocity.airjump_back = -2.55;
		constants.velocity.airjump_fwd = 2.5f;
	}

}

bool Cloudi::RunState(int stateNum)
{
	switch(stateNum)
	{
		case -3:
			state_m3();
			break;
		case -2:
			state_m2();
			break;
		case -1:
			state_m1();
			break;
		case 0:
			state_0();
			break;
		case 10:
			state_10();
			break;
		case 11:
			state_11();
			break;
		case 12:
			state_12();
			break;
		case 20:
			state_20();
			break;
		case 40:
			state_40();
			break;
		case 45:
			state_45();
			break;
		case 50:
			state_50();
			break;
		case 51:
			state_51();
			break;
		case 52:
			state_52();
			break;
		case 100:
			state_100();
			break;
		case 101:
			state_101();
			break;
		case 105:
			state_105();
			break;
		case 106:
			state_106();
			break;
		case 120:
			state_120();
			break;
		case 130:
			state_130();
			break;
		case 131:
			state_131();
			break;
		case 132:
			state_132();
			break;
		case 140:
			state_140();
			break;
		case 150:
			state_150();
			break;
		case 151:
			state_151();
			break;
		case 152:
			state_152();
			break;
		case 153:
			state_153();
			break;
		case 154:
			state_154();
			break;
		case 155:
			state_155();
			break;
		case 170:
			state_170();
			break;
		case 175:
			state_175();
			break;
		case 180:
			state_180();
			break;
		case 181:
			state_181();
			break;
		case 190:
			state_190();
			break;
		case 191:
			state_191();
			break;
		case 195:
			state_195();
			break;
		case 200:
			state_200();
			break;
		case 201:
			state_201();
			break;
		case 202:
			state_202();
			break;
		case 203:
			state_203();
			break;
		case 204:
			state_204();
			break;
		case 206:
			state_206();
			break;
		case 300:
			state_300();
			break;
		case 301:
			state_301();
			break;
		case 302:
			state_302();
			break;
		case 305:
			state_305();
			break;
		case 306:
			state_306();
			break;
		case 307:
			state_307();
			break;
		case 400:
			state_400();
			break;
		case 410:
			state_410();
			break;
		case 411:
			state_411();
			break;
		case 412:
			state_412();
			break;
		case 420:
			state_420();
			break;
		case 421:
			state_421();
			break;
		case 422:
			state_422();
			break;
		case 500:
			state_500();
			break;
		case 510:
			state_510();
			break;
		case 600:
			state_600();
			break;
		case 601:
			state_601();
			break;
		case 602:
			state_602();
			break;
		case 603:
			state_603();
			break;
		case 622:
			state_622();
			break;
		case 888:
			state_888();
			break;
		case 1000:
			state_1000();
			break;
		case 1001:
			state_1001();
			break;
		case 1010:
			state_1010();
			break;
		case 1011:
			state_1011();
			break;
		case 1013:
			state_1013();
			break;
		case 2000:
			state_2000();
			break;
		case 2001:
			state_2001();
			break;
		case 2002:
			state_2002();
			break;
		case 5000:
			state_5000();
			break;
		case 5001:
			state_5001();
			break;
		case 5010:
			state_5010();
			break;
		case 5011:
			state_5011();
			break;
		case 5020:
			state_5020();
			break;
		case 5030:
			state_5030();
			break;
		case 5035:
			state_5035();
			break;
		case 5040:
			state_5040();
			break;
		case 5050:
			state_5050();
			break;
		case 5070:
			state_5070();
			break;
		case 5071:
			state_5071();
			break;
		case 5080:
			state_5080();
			break;
		case 5081:
			state_5081();
			break;
		case 5100:
			state_5100();
			break;
		case 5101:
			state_5101();
			break;
		case 5110:
			state_5110();
			break;
		case 5120:
			state_5120();
			break;
		case 5150:
			state_5150();
			break;
		case 5200:
			state_5200();
			break;
		case 5201:
			state_5201();
			break;
		case 5210:
			state_5210();
			break;
		case 5500:
			state_5500();
			break;
		case 5888:
			state_5888();
			break;
		case 5900:
			state_5900();
			break;
		case 9000:
			state_9000();
			break;
		case 9001:
			state_9001();
			break;
		case 9005:
			state_9005();
			break;
		case 50000:
			state_50000();
			break;
		case 90000:
			state_90000();
			break;
		default: 
			return false;
	}
	return true;
}


