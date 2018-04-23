///Add
static bool SortMyItems(const LPITEM & s1, const LPITEM & s2) 
{ 
	/// change what you want
	return s1->GetName() < s2->GetName();
	// return s1->GetVnum() < s2->GetVnum();
}
void CHARACTER::EditMyInven()
{
	if (IsDead())
		return;
	static std::vector<LPITEM> v;
    LPITEM myitems;
	
	///clear vector
	v.clear();
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	int size = Inventory_Size();
#else
	int size = INVENTORY_MAX_NUM;
#endif

	for (int i = 0; i < size; ++i)
	{
		if (!(myitems = GetInventoryItem(i))) 
			continue;
		
		///add all items inven to vector
		v.push_back(myitems);
		
		///delete items from inven
		myitems->RemoveFromCharacter();
	}
	///Sort items
	std::sort(v.begin(), v.end(), SortMyItems);
	
	///Send vector items to inven
	itertype(v) it = v.begin();
	while (it != v.end()) {	
		LPITEM item = *(it++);
		if (item) 
			AutoGiveItem(item);
	}
	
	///message
	ChatPacket(CHAT_TYPE_INFO, "Your items sorted.");
}