//Find
		bool		AddToCharacter(LPCHARACTER ch, TItemPos Cell);
		
///Change
	#ifdef ENABLE_SORT_INVEN
		bool		AddToCharacter(LPCHARACTER ch, TItemPos Cell, bool highlight = true);
	#else
		bool		AddToCharacter(LPCHARACTER ch, TItemPos Cell);
	#endif