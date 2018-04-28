// Find
void CHARACTER::AutoGiveItem(LPITEM item, bool longOwnerShip)
	
///Change
#ifdef ENABLE_SORT_INVEN
void CHARACTER::AutoGiveItem(LPITEM item, bool longOwnerShip, bool highlight)
#else
void CHARACTER::AutoGiveItem(LPITEM item, bool longOwnerShip)
#endif

//Find
		if (item->IsDragonSoul())
			item->AddToCharacter(this, TItemPos(DRAGON_SOUL_INVENTORY, cell));
		else
			item->AddToCharacter(this, TItemPos(INVENTORY, cell));
		
///Change
		if (item->IsDragonSoul())
			item->AddToCharacter(this, TItemPos(DRAGON_SOUL_INVENTORY, cell));
		else
		#ifdef ENABLE_SORT_INVEN
			item->AddToCharacter(this, TItemPos(INVENTORY, cell), highlight);
		#else
			item->AddToCharacter(this, TItemPos(INVENTORY, cell));
		#endif
		
//Find
	LPITEM CHARACTER::AutoGiveItem(DWORD dwItemVnum, BYTE bCount, int iRarePct, bool bMsg)
	
///Change
#ifdef ENABLE_SORT_INVEN
LPITEM CHARACTER::AutoGiveItem(DWORD dwItemVnum, BYTE bCount, int iRarePct, bool bMsg, bool highlight)
#else
LPITEM CHARACTER::AutoGiveItem(DWORD dwItemVnum, BYTE bCount, int iRarePct, bool bMsg)
#endif

//Find
		if (item->IsDragonSoul())
			item->AddToCharacter(this, TItemPos(DRAGON_SOUL_INVENTORY, iEmptyCell));
		else
			item->AddToCharacter(this, TItemPos(INVENTORY, iEmptyCell));
		
///Change
		if (item->IsDragonSoul())
			item->AddToCharacter(this, TItemPos(DRAGON_SOUL_INVENTORY, iEmptyCell));
		else
		#ifdef ENABLE_SORT_INVEN
			item->AddToCharacter(this, TItemPos(INVENTORY, iEmptyCell), highlight);
		#else
			item->AddToCharacter(this, TItemPos(INVENTORY, iEmptyCell));
		#endif
