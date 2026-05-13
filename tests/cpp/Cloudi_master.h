/*
   Cloudi_master.h
   Master file for Cloudi
   Generated on 2026-05-13.

   by Sourcy Code Translator
   (c) 2017 - radexx

  Runtime version: 1.0

*/

#include "FightActor.h"

// Class definition
class Cloudi : public FightActor
{
	public:
		Cloudi();
		~Cloudi();
		
		void InitInfo(Constants& constants, ButtonRemaps& btnRemaps, Commands& commands, CommandDefaults& cmdDefaults);
		bool RunState(int stateNum);

		// Basic information
	protected:
		// State definitions
		void state_m3();
		void state_m2();
		void state_m1();
		void state_0();
		void state_10();
		void state_11();
		void state_12();
		void state_20();
		void state_40();
		void state_45();
		void state_50();
		void state_51();
		void state_52();
		void state_100();
		void state_101();
		void state_105();
		void state_106();
		void state_120();
		void state_130();
		void state_131();
		void state_132();
		void state_140();
		void state_150();
		void state_151();
		void state_152();
		void state_153();
		void state_154();
		void state_155();
		void state_170();
		void state_175();
		void state_180();
		void state_181();
		void state_190();
		void state_191();
		void state_195();
		void state_200();
		void state_201();
		void state_202();
		void state_203();
		void state_204();
		void state_206();
		void state_300();
		void state_301();
		void state_302();
		void state_305();
		void state_306();
		void state_307();
		void state_400();
		void state_410();
		void state_411();
		void state_412();
		void state_420();
		void state_421();
		void state_422();
		void state_500();
		void state_510();
		void state_600();
		void state_601();
		void state_602();
		void state_603();
		void state_622();
		void state_888();
		void state_1000();
		void state_1001();
		void state_1010();
		void state_1011();
		void state_1013();
		void state_2000();
		void state_2001();
		void state_2002();
		void state_5000();
		void state_5001();
		void state_5010();
		void state_5011();
		void state_5020();
		void state_5030();
		void state_5035();
		void state_5040();
		void state_5050();
		void state_5070();
		void state_5071();
		void state_5080();
		void state_5081();
		void state_5100();
		void state_5101();
		void state_5110();
		void state_5120();
		void state_5150();
		void state_5200();
		void state_5201();
		void state_5210();
		void state_5500();
		void state_5888();
		void state_5900();
		void state_9000();
		void state_9001();
		void state_9005();
		void state_50000();
		void state_90000();
};


