ProfBirch_EventScript_UpdateLocation::
	compare VAR_PETALBURG_GYM_STATE, 0
	goto_if_eq Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 0
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 1
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 2
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	compare VAR_BIRCH_STATE, 3
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	compare VAR_BIRCH_STATE, 4
	call_if_eq ProfBirch_EventScript_MoveToRoute103
	compare VAR_BIRCH_STATE, 5
	call_if_eq ProfBirch_EventScript_MoveToRoute103
	compare VAR_BIRCH_STATE, 6
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 7
	call_if_eq ProfBirch_EventScript_MoveToLab
	return

ProfBirch_EventScript_MoveToLab::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute103::
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

ProfBirch_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

ProfBirch_EventScript_AskRatePokedex::
	goto_if_set FLAG_BADGE05_GET, LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_1
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_1::
	goto_if_unset FLAG_BIRCH_STONE_GET LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_2
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_2::
		msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Five_Badges, MSGBOX_DEFAULT
		switch VAR_STARTER_MON
		case 0, LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Sceptile
		case 1, LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Blaziken
		case 2, LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Swampert
		msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Power_Of_Mega_Stones, MSGBOX_DEFAULT
		setflag FLAG_BIRCH_STONE_GET
		end

LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Sceptile::
	giveitem ITEM_SCEPTILITE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Blaziken::
	giveitem ITEM_BLAZIKENITE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Give_Mega_Stone_Swampert::
	giveitem ITEM_SWAMPERTITE, 1
	return

ProfBirch_EventScript_DeclineRating::
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring 0, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring 1, VAR_0x8009  @ Num Hoenn caught
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfBirch_EventScript_ShowRatingMessage
	compare VAR_0x800A, 0
	goto_if_eq Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008  @ Num National seen
	buffernumberstring 1, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return
	
	
LittlerootTown_ProfessorBirchsLab_EventScript_Five_Badges:
	.string "Oh, you've beaten your\n"
	.string "father and gotten a mega ring?\n"
	.string "I have a gift for you to celebrate!\n"

LittlerootTown_ProfessorBirchsLab_EventScript_Power_Of_Mega_Stones:
	.string "If you give your\n"
	.string "starter this stone,\n"
	.string "it will unlock a great power\n"
	.string "in battle when you\n"
	.string "press start before\n"
	.string "selecting a move.$" 
