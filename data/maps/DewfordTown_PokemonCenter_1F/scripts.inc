.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordCity_PokemonCenter_1F_EventScript_Expert::
	trainerbattle_single TRAINER_EXPERT_2, DewfordCity_PokemonCenter_1F_Text_ExpertIntro, DewfordCity_PokemonCenter_1F_Text_ExpertDefeat
	msgbox DewfordCity_PokemonCenter_F_Text_ExpertPostBattle, MSGBOX_AUTOCLOSE
	cleartrainerflag TRAINER_EXPERT_2
	end

DewfordCity_PokemonCenter_1F_Text_ExpertIntro:
	.string "The journey ahead\n"
	.string "much training.\p"
	.string "Are you ready?$"
	
DewfordCity_PokemonCenter_1F_Text_ExpertDefeat:
	.string "You aren't ready.$"
	
DewfordCity_PokemonCenter_F_Text_ExpertPostBattle:
	.string "Maybe you are\n"
	.string "ready...$"

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"

