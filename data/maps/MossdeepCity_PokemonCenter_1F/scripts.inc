.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Expert::
	trainerbattle_single TRAINER_EXPERT_7, MossdeepCity_PokemonCenter_1F_Text_ExpertIntro, MossdeepCity_PokemonCenter_1F_Text_ExpertDefeat
	msgbox MossdeepCity_PokemonCenter_F_Text_ExpertPostBattle, MSGBOX_AUTOCLOSE
	cleartrainerflag TRAINER_EXPERT_7
	end

MossdeepCity_PokemonCenter_1F_Text_ExpertIntro:
	.string "The journey ahead\n"
	.string "much training.\p"
	.string "Are you ready?$"
	
MossdeepCity_PokemonCenter_1F_Text_ExpertDefeat:
	.string "You aren't ready.$"
	
MossdeepCity_PokemonCenter_F_Text_ExpertPostBattle:
	.string "Maybe you are\n"
	.string "ready...$"

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"

