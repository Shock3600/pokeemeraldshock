Std_RegisteredInMatchCall:: @ 82742C9
    return

EventScript_TryGetTrainerScript::
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GotoTrainerScript
	releaseall
	end

EventScript_GotoTrainerScript::
	gotobeatenscript
	releaseall
	end
