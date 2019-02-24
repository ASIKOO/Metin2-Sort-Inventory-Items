//Find	
	LPITEM			AutoGiveItem(DWORD dwItemVnum, BYTE bCount=1, int iRarePct = -1, bool bMsg = true);
	void			AutoGiveItem(LPITEM item, bool longOwnerShip = false);
	
///Change
#ifdef ENABLE_SORT_INVEN
	LPITEM			AutoGiveItem(DWORD dwItemVnum, BYTE bCount=1, int iRarePct = -1, bool bMsg = true, bool highlight = true);
	void			AutoGiveItem(LPITEM item, bool longOwnerShip = false, bool highlight = true);
#else
	LPITEM			AutoGiveItem(DWORD dwItemVnum, BYTE bCount=1, int iRarePct = -1, bool bMsg = true);
	void			AutoGiveItem(LPITEM item, bool longOwnerShip = false);
#endif