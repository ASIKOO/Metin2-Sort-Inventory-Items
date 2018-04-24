//Find
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell)
	
///Change
#ifdef ENABLE_SORT_INVEN
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell, bool highlight)
#else
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell)
#endif

//Find
	bool bWereMine = this->GetLastOwnerPID() == ch->GetPlayerID();
	
//Change
#ifdef ENABLE_SORT_INVEN
	bool bWereMine = this->GetLastOwnerPID() == ch->GetPlayerID() && highlight;
#else
	bool bWereMine = this->GetLastOwnerPID() == ch->GetPlayerID();
#endif
	